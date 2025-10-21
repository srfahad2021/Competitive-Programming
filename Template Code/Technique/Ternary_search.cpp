const double eps = 1e-9;              //set the error limit here


// this is for floating point calculation
double f(int val){}         // implement the function for calculating answer for mid
double ternary_search(double l, double r) {
    while (r - l > eps) {
        double m1 = l + (r - l) / 3.0;
        double m2 = r - (r - l) / 3.0;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}





// this is for integer point calculation
int lo = 0, hi = 1e10;
    while(hi - lo > 3){
        int m1 = lo + ((hi - lo) / 3);
        int m2 = hi - ((hi - lo) / 3);
        int v1 = f(n, m, a, b, m1);
        int v2 = f(n, m, a, b, m2);
        if(v1 < v2){
            hi = m2 - 1;
        }
        else{
            lo = m1 + 1;
        }
    }
    int ans = 1e18;
    for(int i = lo; i <=hi; i++){
        ans = min(ans, f(n, m, a, b, i));
    }
    cout << ans << nl;