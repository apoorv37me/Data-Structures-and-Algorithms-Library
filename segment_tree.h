struct node{
    ll sum;
    node() : sum(0) {}
    node(ll x) : sum(x) {}
    friend node merge(node a,const node &b) {
        // do something 
        return a;
    }
};

template<class Node>
struct segtree{
    segtree *left, *right;
    int lmost, rmost;
    Node sum;

    segtree(const vector<int> &a, int l, int n){
        lmost = l, rmost = n;
        if(l == n){
            sum = a[l];
        }
        else{
            int m = l + (n - l) / 2;
            left = new segtree(a, l, m);
            right = new segtree(a, m+1, n);
            recalc();
        }
    }

    void recalc(){
        if(lmost==rmost)    return;
        sum = merge(left->sum, right->sum);
    }

    void pointUpdate(int indx, ll val){
        if(lmost==rmost){   // lmost = rmost = indx;
            sum = val;
            return;
        }
        if(left->rmost>=indx){
            left->pointUpdate(indx, val);
        }
        else if(right->lmost<=indx){
            right->pointUpdate(indx, val);
        }
        recalc();
    }

    Node rangeSum(int l, int r){
        if(l>rmost || r<lmost){
            return node(0);
        }
        if(l<=lmost && r>=rmost){
            return sum;
        }
        return merge(left->rangeSum(l, r), right->rangeSum(l, r));
    }
};