// - Author: Jorge_Slime - 06.12.2025 | 23:18:34
#include <bits/stdc++.h>
#include <cstdint>
#define sz(x)  int((x).size())
#define forn(i,a,b) for(auto i{a};i<b;++i)
#define forr(i,b,a) for(auto i{b};i>=a;--i)
#define all(x) (x).begin(),(x).end()
using namespace std; 
#if defined(SLIME)
    #include "/home/jorge/slime_debug.hpp"
#else
    #define _(...) void(77)
#endif
using i64 = int64_t;



struct nodo{
    i64 total; 
    i64 min_pref;
    nodo(int val = 0){
        this->total = val; 
        this->min_pref = std::min(val,0);
    }
    nodo(int val,int min) : total(val), min_pref(min) {}
};

class SegTree{
public:
    #define left node << 1 
    #define right node << 1 | 1
    vector<nodo> tree;
    int log = 0, size, neutral = 0; 
    SegTree(int n) : size(n) {
        while((1 << log) < size) ++log; 
        size = 1 << log; 
        tree.assign(size<<1,nodo());
    }
    void modify(int node){
        tree[node] = op(tree[left],tree[right]);
    }
    void update(int node, int nl,int nr,int pos,i64 v){
        if(nl==nr){
            tree[node] = nodo(v);
        }else{
            int mid= (nl+nr)>>1;
            if(pos<=mid) update(left,nl,mid,pos,v);
            else update(right,mid+1,nr,pos,v);
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
        nodo lft = query(left, nl, mid, ql, qr);
        nodo rgt = query(right, mid + 1, nr, ql, qr);
        return op(lft, rgt);
    }
    nodo query(int l,int r){return query(1,0,size-1,l,r);}
    nodo op(nodo& izq, nodo& der){
        i64 t = izq.total + der.total; 
        // en esta parte ponemos el minimo de todos los prefijos
        i64 mp = std::min(izq.min_pref,izq.total + der.min_pref);
        return nodo(t,mp);
    }
    #undef left 
    #undef right
};




[[gnu::target("avx2")]] auto main(void) -> int {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin.exceptions(ios::failbit | ios::badbit);
    const int NTEST = 10; 
    forn(i, 0, NTEST){
        int n; cin >> n; 
        string s; cin >> s; 
        const int N = sz(s);
        SegTree seg(N);
        forn(i, 0, N){
            int val = s[i] == '(' ? 1 : -1; 
            seg.update(i,val);
        }
        for (auto [a,b] : seg.tree) {
            _(deb(a,b));
        }
        cout << "Test " << (i + 1) << ":\n";
        int m; cin >> m; 
        forn(i, 0, m){
            int x; cin >> x; 
            if(x == 0){
                nodo val = seg.query(0,N - 1); 
                bool ok =  val.min_pref >= 0 && val.total == 0;
                //for (auto [a,b] : seg.tree) {
                //    _(deb(a,b));
                //}
                cout << (ok ? "YES" : "NO") << '\n'; 
            }else{
                int val = seg.query(x - 1,x - 1).total; 
                int opt = val == 1 ? -1 : 1; 
                seg.update(x - 1,opt); 
            }
        }
        break;
    }


    _(time_()); return 0;
} // I can...   

