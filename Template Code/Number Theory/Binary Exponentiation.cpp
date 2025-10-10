//MMI = binExpIter(a, m-2);
#define int long long
const int M = 1e9 + 7;
int binExpIter(int a, int b){
    int ans=1;
    while(b){
        if(b&1)
            ans= (ans * 1LL * a)%M;
        a=(a*1LL*a)%M;
        b>>=1;
    }
    return ans;
}
int MMI (int a){
    return binExpIter(a, M-2);
}

int binMulIter(int a, int b){
    int ans=1;
    while(b){
        if(b&1)
            ans= (ans + 0LL + a)%M;
        a=(a + 0LL + a)%M;
        b>>=1;
    }
    return ans;
}
