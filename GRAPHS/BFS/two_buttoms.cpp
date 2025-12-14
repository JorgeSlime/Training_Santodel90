// - Author: Jorge_Slime - 14.12.2025 | 00:28:09
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
    int n, m; cin >> n >> m; 
    //debemos ir a construit los pasos empezanod dese con el grafo para ver todas las posibilidades 
    queue<int> Q;
    constexpr int MAXN = 2e4 + 7; // tam * 2
    vector<int> dist(MAXN,-1);
    Q.push(n);
    dist[n] = 0; 
    int res = MAXN * 2; 
    //OP red =  n * 2 and OP blue = -1 
    while(!Q.empty()){
        int num = Q.front(); 
        Q.pop();
        if(num == m) return void(cout << dist[m] << '\n');
        int blue = num * 2; 
        int red = num - 1; 
        if(blue >= 0 && blue < MAXN && dist[blue] == -1){
            Q.push(blue);
            dist[blue] = dist[num] + 1; 
        }
        if(red >= 0 && red < MAXN && dist[red] == -1){
            Q.push(red); 
            dist[red] = dist[num] + 1; 
        }
        
    }
 
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

