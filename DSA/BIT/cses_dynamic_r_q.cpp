#include <iostream>

using namespace std; 

const int MAXN = 2e5 + 7; 
using i64 = long long; 
i64 F[MAXN + 1]; 

constexpr inline int lowbit(int mask){
    return mask & -mask; 
}

void add(int i,int k){
    i++; 
    while(i<=MAXN){
        F[i] += k; 
        i += lowbit(i); 
    }
}
i64 sum(int i){
    i++; 
    i64 res = 0; 
    while(i>0){
        res += F[i]; 
        i -= lowbit(i);
    }
    return res; 
}

i64 query(int l,int r){
    return sum(r) - sum(l - 1);
}
int main(){
    cin.tie(0)->sync_with_stdio(0); 
    int n,q; cin >> n >> q;
    for(int i = 0;i<n;i++){
        i64 x; cin >> x; 
        add(i,x); 
    }
    while(q--){
        int t; cin>> t;
        int l,r; cin >> l >> r; 
        if(t == 1){
            i64 k = sum(l - 1) - sum(l - 2);
            add(l - 1,r - k); 
        }else{
            i64 ans = query(l - 1,r - 1); 
            cout << ans << '\n'; 
        }
    }

    return 0; 
}

