#define ll long long
struct node {
    ll val, setAll, increment;
    bool setAllValid;
    node() { val = setAll = increment = 0; setAllValid = 0; }
    void Reset() { setAllValid = increment = 0; }
};
class segtree {
    int n; 
    vector<node> t;
public:
    void build(vector<ll>& v) {
        n = v.size();
        t.assign(4 * n, node());
        build(0, 0, n - 1, v);
    }
    void build(int p, int l, int r, vector<ll>& v) {
        if (l == r) { t[p] = make_node(v[l]); return; }
        int m = (l + r) / 2;
        build(p * 2 + 1, l, m, v);
        build(p * 2 + 2, m + 1, r, v);
        t[p] = calc(t[p * 2 + 1], t[p * 2 + 2]);
    }
    void inc(int p, int l, int r, int& L, int& R, ll& X) {
        if (r < L || R < l) return;
        if (L <= l && r <= R) { t[p].increment += X; return; }
        push(p, l, r);
        int m = (l + r) / 2;
        inc(p * 2 + 1, l, m, L, R, X);
        inc(p * 2 + 2, m + 1, r, L, R, X);
        push(p * 2 + 1, l, m); push(p * 2 + 2, m + 1, r);
        t[p] = calc(t[p * 2 + 1], t[p * 2 + 2]);
    }
    void setv(int p, int l, int r, int& L, int& R, ll& X) {
        if (r < L || R < l) return;
        if (L <= l && r <= R) { t[p].setAllValid = 1; t[p].setAll = X; t[p].increment = 0; return; }
        push(p, l, r);
        int m = (l + r) / 2;
        setv(p * 2 + 1, l, m, L, R, X);
        setv(p * 2 + 2, m + 1, r, L, R, X);
        push(p * 2 + 1, l, m); push(p * 2 + 2, m + 1, r);
        t[p] = calc(t[p * 2 + 1], t[p * 2 + 2]);
    }
    
    ll query(int p, int l, int r, int& L, int& R) {
        if (r < L || R < l) return 0; // change for min/max/gcd/sum
        push(p, l, r);
        if (L <= l && r <= R) return t[p].val;
        int m = (l + r) / 2;
        ll a = query(p * 2 + 1, l, m, L, R);
        ll b = query(p * 2 + 2, m + 1, r, L, R);
        return query_calc(a, b);
    }
    void compose(int p, int c) {
        if (t[p].setAllValid) {
            t[c].setAllValid = 1;
            t[c].setAll = t[p].setAll;
            t[c].increment = t[p].increment;
        } else t[c].increment += t[p].increment;
    }
    void push(int p, int l, int r) {
        node &x = t[p];
        if (x.setAllValid) x.val = (r - l + 1) * x.setAll;
        x.val += (r - l + 1) * x.increment;
        if (l != r) { compose(p, p * 2 + 1); compose(p, p * 2 + 2); }
        x.Reset();
    }
    // change it to min, max, sum, gcd ..
    node make_node(ll val) { node a; a.val = val; return a; }
    node calc(const node &L, const node &R) {node a; a.val = (L.val + R.val);return a;}
    ll query_calc(int a, int b){return (a + b);};
    void incUpdate(int L, int R, ll X) { inc(0, 0, n - 1, L, R, X); }
    void setUpdate(int L, int R, ll X) { setv(0, 0, n - 1, L, R, X); }
    ll range_query(int L, int R) { return query(0, 0, n - 1, L, R); }
};