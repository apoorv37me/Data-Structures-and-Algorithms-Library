struct edge{
    int to;
    ll cap, flow;
    edge() {}
    edge(int to_, ll cap_, ll flow_ = 0) : to(to_), cap(cap_), flow(flow_) {}
    friend void __print(edge e) {
        cout << "{" << e.to << "," << e.flow << "/" << e.cap << "}";
    }
};

struct flow{
    int n;
    vector<vector<edge>> adj;

    flow(int n_ = 0) : n(n_) {
        adj.resize(n_);
    }

    void addedge(const int &from, const int &to, const ll &cap) {
        adj[from].pb({to, cap});
        adj[to].pb({from, cap, cap});
    }

    ll bfs(const int &src, const int &dest, vector<int> &par) {
        fill(par.begin(), par.end(), -1);
        par[src] = -2;
        queue<pair<int, ll>> q;
        q.push({src, INF});
        while(!q.empty()) {
            auto [cur, curflow] = q.front();   q.pop();
            for(auto &[to, cap, flow]: adj[cur]) {
                if(par[to] == -1 && flow < cap) {
                    par[to] = cur;
                    if(to == dest) {
                        return min(cap - flow, curflow);
                    }
                    q.push({to, min(cap - flow, curflow)});
                }
            }
        }
        return 0LL;
    }

    ll maxflow(const int &src, const int &dest, const int &n) {
        ll flow_ = 0, newflow;
        vector<int> par(n);
        int cnt = -2;
        while((newflow = bfs(src, dest, par))) {
            assert(newflow > 0);
            for(int node = dest ; node != src && node != par[src] ; node = par[node]) {
                for(auto &[to, cap, flow]: adj[par[node]]) {
                    if(to == node) {
                        flow += newflow;
                    }
                }
                for(auto &[to, cap, flow]: adj[node]) {
                    if(to == par[node]) {
                        flow -= newflow;
                    }
                }
            }
            flow_ += newflow;
        };
        return flow_;
    }
};