template<class T>
struct BIT{
    int n;
    vector<int> tree;
    BIT(int n_ = 0) : n(n_ + 1) {
        tree.resize(n_ + 1);
    }
    void update(int ind, T val) {
        for(ind++ ; ind < n ; ind += (ind & -ind))
            tree[ind] += val;
    }
    T pfsum(int ind) {
        T sum = 0;
        for(ind++ ; ind ; ind -= (ind & -ind))
            sum += tree[ind];
        return sum;
    }
    void rangesum(int L, int R) {
        return pfsum(R) - pfsum(L - 1);
    }
};

