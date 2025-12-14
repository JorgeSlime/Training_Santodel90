// - Author: Jorge_Slime - 13.12.2025 | 00:58:13
#include <bits/stdc++.h>
using namespace std; 
#define sz(x)  int((x).size())
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
    int n,A,B; cin >> n >> A >> B;
    vector<i64> pref(n + 1);
    i64 x; 
    forn(i, 0, n){
        cin >> x; 
        pref[i + 1] = pref[i] + x; 
    }
    // usaremos este para cumplir con la formula de : 
    // pref[r] - min(pref[r - A]) que este dento de b - a 
    // A <= r - l <= B -> r - b <= l <= r - a -> "r" se mantiene fijo 
    deque<i64> mn_pos; // la pos min_pref   
    i64 ans = INT64_MIN; 
    forn(r,1,n + 1){
        if(r >= A){
            while (!mn_pos.empty() && pref[mn_pos.back()] >= pref[r - A]) mn_pos.pop_back(); 
            mn_pos.push_back(r - A);
        }
        while(!mn_pos.empty() && mn_pos.front() < r - B) mn_pos.pop_front();
        if(!mn_pos.empty()) ans = max(ans, pref[r] - pref[mn_pos.front()]); 
    }
    cout << ans << '\n'; 
    // esta sol se basa en Minimun Stack / Minimun queue 
};
// con orden monotono  
auto solve1([[maybe_unused]]auto&& tc)->void{ 
    int n,A,B; cin >> n >> A >> B;
    vector<i64> pref(n + 1);
    i64 x; 
    forn(i, 0, n){
        cin >> x; 
        pref[i + 1] = pref[i] + x; 
    }
    // usaremos este para cumplir con la formula de : 
    // pref[r] - min(pref[l]) que este dento de b - a
    multiset<i64> mn_pref; 
    i64 ans = INT64_MIN; 
    forn(r,1,n + 1){
        if(r >= A){
            mn_pref.emplace(pref[r - A]);
            ans = max(ans,pref[r] - *mn_pref.begin());
        }
        if(r>=B){
            auto coso = mn_pref.find(pref[r - B]); 
            mn_pref.erase(coso);
        }
    }
    cout << ans << '\n'; 
}
//note que ambas en principio usan slinding window para mantener por defecto un biuen tiempo en subarreglos
[[gnu::target("avx2")]] 
auto main(void) -> int {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(ios::failbit | ios::badbit);
    size_t t_c = 1;
    //cin >> t_c;

    for(size_t t = 0;t < t_c; t++){ _(case(t)); solve(t); }
    _(time_());
    return 0;
} // I can....


