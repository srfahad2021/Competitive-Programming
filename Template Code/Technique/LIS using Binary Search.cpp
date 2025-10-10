// LIS - Longest increasing subsequence
// O(n*logn)
const int INF=INT_MAX;
vector<int> LIS(vector<int> & inp){
    int n=inp.size();
    
    vector<int> a(n+2, INF);
    vector<int> res(n,1);
    a[0]=-INF;

    int lis=0;
    for(int i=0; i<n; i++){
        int low = lower_bound(a.begin(), a.end(), inp[i])-a.begin();
        a[low] = inp[i];
        lis = low;
        res[i] = lis;
    }
    return res;
}