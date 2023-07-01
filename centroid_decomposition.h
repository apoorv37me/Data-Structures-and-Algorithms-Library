struct centroid_decomposition{
    vector<vi> e, cg;
    vi sub, vis, dpth, p, best;
    LCA lca;
    int n, root = 0, croot = 0;
    void build(const vector<vi> &adj) {
        e = adj;
        n = sz(e);
        vis.resize(n);
        sub.resize(n, 1);
        dpth.resize(n, -1);
        p.resize(n, -1);
        best.resize(n, maxn);
        cg.resize(n);
        dfs1(0, 0);
        fill(all(vis), 0);
        buildtree(0, -1);
        lca.build(e, 0);
    }
    int dfs1(int i, int d) {
        dpth[i] = d;
        for(auto &u: e[i]) {
            if(dpth[u] == -1) {
                sub[i] += dfs1(u, d + 1);
            }
        }
        return sub[i];
    }
    void buildtree(int i, int root) {
        int cntr = -1;
        dfs2(i, i, -1, cntr);
        assert(cntr != -1);
        dbg(cntr, p);
        if(root != -1) {
            p[cntr] = root;
            cg[cntr].pb(root);
            cg[root].pb(cntr);
        }
        for(auto &u: e[cntr]) {
            if(dpth[u] > dpth[cntr] && !vis[u]) {
                buildtree(u, cntr);
            }
        }
        if(cntr != i) {
            buildtree(i, cntr);
        }
    }
    int  dfs2(int i, int r, int par, int &ans) {
        int p = -1;
        for(auto &u: e[i]) {
            if(!vis[u] && u != par) {
                if(sub[u] * 2 > sub[r])     p = u;
            }
        }
        if(p == -1) {
            ans = i;
            vis[i] = 1;
            return sub[i];
        }
        int val = dfs2(p, r, i, ans);
        sub[i] -= val;
        return val;
    }
    void query1(int i) {
        int node = i;
        best[i] = 0;
        while(i != -1) {
            best[i] = min(best[i], lca.dist(i, node));
            i = p[i];
        }
    }
    int query2(int i) {
        int node = i;
        while(i != -1) {
            best[node] = min(best[node], best[i] + lca.dist(i, node));
            i = p[i];
        }
        return best[node];
    }
};