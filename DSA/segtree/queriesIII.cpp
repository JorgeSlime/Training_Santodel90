//https://www.spoj.com/problems/GSS3/
// - Author: Jorge_Slime - 12.12.2025 | 18:06:48
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

constexpr int INF = 1e9; 

struct nodo{
    i64 sum; 
    i64 pref_sum;
    i64 suff_sum;
    i64 mx_sum; 
    nodo(i64 v){
        sum = pref_sum = suff_sum = mx_sum = v;  
    }
    nodo(){
        sum = 0; 
        pref_sum = suff_sum = mx_sum = -INF;
    }
};

class SegTree{
public:
    vector<nodo> tree;
    int log = 0, size; 
    SegTree(int n) : size(n) {
        while((1 << log) < size) ++log; 
        size = 1 << log; 
        tree.assign(size<<1,nodo());
    }
    nodo op(nodo& izq, nodo& der){
        nodo res; 
        res.sum = izq.sum + der.sum; 
        res.pref_sum = max(izq.pref_sum, izq.sum + der.pref_sum); 
        res.suff_sum = max(der.suff_sum, der.sum + izq.suff_sum);
        res.mx_sum = max({izq.mx_sum, der.mx_sum, izq.suff_sum + der.pref_sum});
        return res;
    }
    void modify(int node){
        tree[node] = op(tree[node << 1],tree[node << 1 | 1]);
    }
    void update(int node, int nl,int nr,int pos,i64 v){
        if(nl==nr){
            tree[node] = nodo(v);
        }else{
            int mid= (nl + nr) >> 1;
            if(pos<=mid) update(node << 1,nl,mid,pos,v);
            else update(node << 1 | 1,mid + 1,nr,pos,v);
            modify(node);
        }
    }
    void update(int pos, int val){
        update(1,0,size - 1,pos,val);
    }
    nodo query(int node,int nl,int nr,int ql,int qr) { 
        if (ql > nr || qr < nl) return nodo();
        if (nl >= ql && nr <= qr) return tree[node]; 
        int mid = (nl + nr) >> 1;
        nodo lft = query(node << 1, nl, mid, ql, qr);
        nodo rgt = query(node << 1 | 1, mid + 1, nr, ql, qr);
        return op(lft, rgt);
    }
    nodo query(int l,int r){
        return query(1,0,size-1,l,r);
    }
};


auto solve([[maybe_unused]]auto&& tc)->void{ 
    int n; cin >> n; 
    vector<i64> ar(n);
    SegTree seg(n); 
    forn(i, 0, n){
        cin >> ar[i]; 
        seg.update(i,ar[i]);
    }
    int q; cin >> q; 
    forn(i, 0, q){
        int t,x,y; cin >> t >> x >> y; 
        if(t == 0){
            seg.update(x - 1,y); 
        }else{
            nodo ans = seg.query(x - 1,y - 1);
            cout << ans.mx_sum << '\n'; 
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
    

