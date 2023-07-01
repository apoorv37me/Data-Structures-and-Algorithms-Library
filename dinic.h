struct edge{
    int to, backindx;
    ll cap, flow;
    edge() {}
    edge(int to_, int backindx_, ll cap_, ll flow_ = 0) : to(to_), backindx(backindx_), cap(cap_), flow(flow_) {}
    friend void __print(edge e) {
        cout << "{" << e.to << "," << e.flow << "/" << e.cap << "}";
    }
};

struct dinicflow{
    int n;
    vector<vector<edge>> adj;
    vector<int> level;

    dinicflow(int n_ = 0) : n(n_) {
        adj.resize(n_);
        level.resize(n);
    }
    
    void clear() {
        for(int i = 0 ; i < n ; i++) {
            adj[i].clear();
        }
    }

    void addedge(const int &from, const int &to, const ll &cap) {
        adj[from].pb({to, sz(adj[to]), cap});
        adj[to].pb({from, sz(adj[from]) - 1, cap, cap});
    }

    bool bfs(const int &src, const int &dest) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(src);
        level[src] = 0;
        while(!q.empty()) {
            auto cur = q.front();   q.pop();
            for(auto &[to, backindx, cap, flow]: adj[cur]) {
                if(level[to] == -1 && flow < cap) {
                    level[to] = level[cur] + 1;
                    q.push(to);
                }
            }
        }
        return level[dest] != -1;
    }

    ll dfs(int src, const int &dest, ll curflow) {
        if(dest == src) {
            return curflow;
        }
        for(auto &[to, backindx, cap, flow]: adj[src]) {
            if(level[to] == level[src] + 1 && flow < cap) {
                ll dfsflow = dfs(to, dest, min(curflow, cap - flow));
                if(dfsflow) {
                    flow += dfsflow;
                    adj[to][backindx].flow -= dfsflow;
                    return dfsflow;
                }
            }
        }
        return 0;
    }

    ll maxflow(const int &src, const int &dest) {
        ll flow_ = 0, newflow;
        vector<int> par(n);
        while(bfs(src, dest)) {
            while (newflow = dfs(src, dest, INF)) {
                flow_ += newflow;
            }
        }
        return flow_;
    }
};