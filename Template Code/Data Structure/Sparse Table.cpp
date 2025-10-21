// No modification allowed
// Power: range minimum query in o(1), most range query in o(logn)
// Time complexity
    // Build time -> O(n log n)
    // Query time -> O(log n)
    // Special Query(min, max) time -> O(1)

class Sparse_Table{
public:
    vector<vector<int>> t;
    int MX, n;
    Sparse_Table(int _n, vector<int>&a){ // 1-based
        n = _n;
        MX = log2(n) + 1;
        t.assign(n+1, vector<int>(MX, 0));
        for(int i = 1; i <= n; ++i) t[i][0] = a[i];
    }
    void build() {
        for(int k = 1; k < MX; ++k) {
            for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
                t[i][k] = min(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    int min_query(int l, int r) {
        int k = 31 - __builtin_clz(r - l + 1);
        return min(t[l][k], t[r - (1 << k) + 1][k]);
    }

    // for using sum_query the table should be build according to sum, not min
    // insted of using this, use BIT for sum_query (also modification)
    int sum_query(int l, int r){
        int sum = 0;
        for (int i = MX - 1; i >= 0; i--) {
            if ((1 << i) <= r - l + 1) {
                sum = (sum + t[l][i]);
                l += 1 << i;
            }
        }
        return sum;
    }
};