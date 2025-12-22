// - Author: Jorge_Slime - 20.12.2025 | 23:47:15
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
// FIRST SOLUTION WITH FT OFFLINE 
class BIT{
public: 
    int N;
    vector<i64> data;
    void init(int size) {
        N = size + 2;
        data.assign(N + 1, {});
    }
    i64 sum(int k) const {// get sum [0,k)
        if (k < 0) return i64{};  
        i64 ret{};
        for (++k;k>0;k-=k&-k) 
            ret += data[k];
        return ret;
    }
    // corregir en adicion[k,k - 1]
    i64 range_query(int l, int r) const{
        return sum(r) - sum(l - 1);
    }
    void update(int k, i64 x) {
      for (++k; k < N; k += k & -k) data[k] += x;
    }
};
struct Node{
    i64 l,r,val,pos; 
};
auto solve([[maybe_unused]]auto&& tc)->void{ 
    int n; cin >> n; 
    vector<array<int,2>> ar(n); 
    forn(i, 0, n){
        cin >> ar[i][0];
        ar[i][1] = i; 
    }
    int q; cin >> q; 
    vector<Node> Q(q); 
    forn(i, 0, q){
        int l,r,val; cin >> l >> r >> val;
        Q[i] = {l,r,val,i};
    }
    sort(all(ar),greater<>());
    sort(all(Q),[&](const Node& a,const Node& b){
        return a.val > b.val; 
    });
    BIT bit;
    bit.init(n);
    vector<int> ans(q);
    int i = 0; 
    for(auto& [l,r,val,pos] : Q){
        while(i < n && ar[i][0] > val){
            _(deb(ar[i],val,i));
            bit.update(ar[i][1], 1);
            i++; 
        }
        ans[pos] = bit.range_query(l - 1, r - 1); 
    }
    forn(i, 0, q){
        cout << ans[i] << '\n'; 
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


