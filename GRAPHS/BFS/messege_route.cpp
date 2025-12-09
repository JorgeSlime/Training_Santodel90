// - Author: Jorge_Slime - 09.12.2025 | 00:03:36
#include <bits/stdc++.h>
#define sz(x)  int((x).size())
#define forn(i,a,b) for(auto i{a};i<b;++i)
#define forr(i,b,a) for(auto i{b};i>=a;--i)
#define all(x) (x).begin(),(x).end()
using namespace std; 
#if defined(SLIME)
    #include "/home/jorge/slime_debug.hpp"   
#else                                        
    #define _(...) void(77)
#endif
using i64 = int64_t;         





auto solve([[maybe_unused]]auto&& tc)->void{ 
    int n, m; cin >> n >> m; 
    vector<vector<int>> G(n + 1);  
    forn(i, 0, m){
        int u,v; cin >> u >> v; 
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    // bfs 
    queue<int> Q; 
    vector<bool> used(n + 1);
    vector<int> fa(n + 1,-1),dist(n + 1);
    deque<int> path;
    Q.emplace(1);
    used[1] = true; 
    fa[1] = -1; 
    while(!Q.empty()){
        int v = Q.front(); 
        Q.pop(); 
        for(auto& u : G[v]){
            if(used[u]) continue; 
            Q.emplace(u);
            used[u] = true; 
            fa[u] = v; 
            dist[u] = dist[v] + 1; 
        }
    }
    // restore path 
    for(int i = n;i != -1;i = fa[i]){
        path.emplace_front(i);   
    }
    if(dist[n] == 0) return void(cout << "IMPOSSIBLE\n");
    cout << (dist[n] + 1) << '\n'; 
    for(auto& val : path) cout << val << " "; 
};
[[gnu::target("avx2")]] auto main(void) -> int {
    cin.tie(nullptr)->sync_with_stdio(false);
    size_t t_c = 1;
    //cin >> t_c;

    for(size_t t = 0;t < t_c; t++){ _(case(t)); solve(t); }
    _(time_());
    return 0;
} // I can....
    
