// - Author: Jorge_Slime - 14.12.2025 | 23:42:17
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
struct DSU {
    vector<int> fa, siz;
    int set;
    DSU() {}
    DSU(int n) {
        init(n);
        this->set = n; 
    }
    void init(int n) {
        fa.resize(n);
        iota(begin(fa),end(fa),0);
        //sum -> iota 
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if(siz[x] < siz[y]) swap(x,y);
        siz[x] += siz[y];
        // sum[x]+= sum[y];
        fa[y] = x;
        set--;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};
struct Node{
    int u, v, weight;
    bool operator<(const Node& other) const {
        return weight < other.weight;
    }
};
auto solve([[maybe_unused]]auto&& tc)->void{
    int n,m; cin >> n >> m; 
    vector<Node> G;
    DSU uf(n);
    forn(i, 0, m){
        int u,v; cin >> u >> v; 
        i64 w; cin >> w; 
        u--,v--; 
        G.emplace_back(u,v,w); 
    }
    // parte del kruskal XD 
    sort(all(G));
    i64 sum_mst = 0;
    for (auto& [u,v,w] : G){
        if (uf.unite(u, v)){
            sum_mst += w;
        }
    }
    if(uf.set == 1) return void(cout << sum_mst << '\n');
    else cout << "IMPOSSIBLE\n"; 
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


