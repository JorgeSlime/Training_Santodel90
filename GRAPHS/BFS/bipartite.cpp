// - Author: Jorge_Slime - 15.12.2025 | 20:18:43
#include <bits/stdc++.h>
using namespace std; 
#define sz(x) int((x).size())
#define forn(i,a,b) for(__typeof__(b) i{a};i<(b);++i)
#define forr(i,b,a) for(__typeof__(b) i{b};i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#if defined(SLIME)
    #include "/home/jorge/slime_debug.hpp"   
#else                                        
    #define _(...) void(77)
#endif
using i64 = int64_t;         

auto solve([[maybe_unused]]auto&& tc)->void{ 
    int n,m; cin >> n >> m; 
    vector<vector<int>> G(n);
    vector<int> color(n,-1); 
    queue<int> Q; 
    forn(i, 0, m){
        int u,v; cin >> u >> v; 
        u--,v--; 
        G[u].push_back(v); 
        G[v].push_back(u); 
    }
    auto check = [&] (int s){
        if(color[s] != -1) return true; 
        Q.emplace(s);
        color[s] = 0; 
        while (!Q.empty()){
            int v = Q.front(); 
            Q.pop(); 
            for(auto& u : G[v]){
                if(color[u]  == -1){
                    Q.emplace(u);
                    color[u] = 1 - color[v];
                }else if(color[u] == color[v]){
                    return false;
                }
                
            }
        }
        return true; 
    };
    bool ok = true; 
    forn(i, 0, n){
        if(!check(i)){
            ok = false; 
            break; 
        }
    }
    
    if(!ok) return void(cout << "IMPOSSIBLE\n");
    for(auto& i: color) cout << (i + 1) << ' ';  

};
[[gnu::target("avx2")]] auto main(void) -> int {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(ios::failbit | ios::badbit);
    size_t t_c = 1;

    //cin >> t_c;


    for(size_t t = 0;t < t_c; t++){ _(case(t)); solve(t); }
    _(time_());
    return 0;
} // I can....


