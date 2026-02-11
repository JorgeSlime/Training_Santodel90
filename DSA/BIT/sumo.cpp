#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define forn(i,a,b) for(auto i{a};i<(b);i++)
#define all(x) x.begin(),x.end()
using namespace std; 
using i64 = long long; 
inline void IO(){
    freopen("sumo.in", "r", stdin); 
    freopen("sumo.out", "w", stdout);
}
struct Par{
    int P,H,pos; 
    bool operator < (const Par& o) const {
        if(P != o.P) return P < o.P; 
        return H < o.H;
    }
};
const int MAXN = 100001; 
int SZ; 
i64 ft[MAXN + 7],ans[MAXN + 7];
Par ar[MAXN + 7]; 
int bit(int mask){
    return mask & -mask; 
}
void add(int i, i64 x){
    i++; 
    while(i <= SZ){
        ft[i] += x;
        i += bit(i); 
    }
}
i64 prefix(int i){
    i++;
    i64 res = 0; 
    while(i > 0){
        res += ft[i]; 
        i -= bit(i); 
    }
    return res;
}
int main(){
    IO(); 
    int n; cin >> n;
    forn(i,0,n){ 
        int p,h; cin >> p >> h; 
        ar[i] = {p,h,i}; 
    }
    sort(ar,ar + n);
    vector<int> coords(n); 
    forn(i,0,n) coords[i] = ar[i].H;
    sort(all(coords));
    coords.erase(unique(all(coords)), coords.end());
    SZ = (int)coords.size();
    auto get_id = [&](int x){
        return lower_bound(all(coords),x) - coords.begin(); 
    };
    int j = 0 ;
    for(int i = 0; i<n;){
        j = i; 
        while(j < n && ar[j].P == ar[i].P) j++; 
        forn(k,i,j){
            int nh = get_id(ar[k].H);
            ans[ar[k].pos] = prefix(nh);
            add(nh, 1);
        }
        i = j; 
    }
    forn(i,0,n){
        cout << ans[i] << '\n'; 
    }
    return 0; 

}

