// - Author: Jorge_Slime - 15.12.2025 | 22:27:13
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
    int n; cin >> n; 
    map<i64,int> histo; 
    histo[0] = 1; 
    i64 sum = 0, ans = 0; 
    forn(i, 0, n){
        i64 x; cin >> x; 
        sum += x; 
        int mod = (sum % n + n) % n; 
        ans += histo[mod]; 
        histo[mod]++; 
    }
    cout << ans << '\n';
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


