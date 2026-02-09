// - Author: Jorge_Slime - 08.02.2026 | 00:56:52
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,a,b)  for(auto i{a};i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())
#if defined(SLIME)
    #include "/home/jorge/slime_debug.hpp"   
#else                                        
    #define _(...) void(77)
#endif
using i64 = long long; 

const int MAXK = 1e5 + 7;
const int MAXN = 1e3 + 7; 

int dp[MAXN][MAXK]; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k; 
    vector<int> precio(n + 1),numPag(n + 1); 
    forn(i,0,n) cin >> precio[i]; 
    forn(i,0,n) cin >> numPag[i]; 
    forn(i,1,n + 1){
        forn(j,0,k + 1){
            int notomo = dp[i - 1][j]; 
            if(j >= precio[i - 1]){
                // ans = max(tomo, notomo); 
                notomo = max(dp[i - 1][j - precio[i - 1]] + numPag[i - 1],notomo);
            }
            dp[i][j] = notomo; 
        }
    }
    cout << dp[n][k] << '\n'; 
    return 0; 
}
