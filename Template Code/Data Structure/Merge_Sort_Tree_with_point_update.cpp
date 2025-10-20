// This merge sort tree  can handle point updates and supports duplicate elements in the tree.

// complexity
// Build Complexity — O(n log^2 n)
// Query Complexity — O(log^3 n)
// Update Complexity — O(log^2 n)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll long long int
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define pb push_back
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> pds; 


ll n;
const ll N=463005;
vector <ll> arr(N);
pds mst[N];

void init(ll pp){
    for(ll i=0;i<4*pp;i++){
        mst[i].clear();
    }
}
void build(ll n,ll b,ll e){
    if(b==e){
        mst[n].insert({arr[b],b});
        return;
    }
    for(ll i=b;i<=e;i++) mst[n].insert({arr[i],i});

    ll mid=(b+e)/2;
    build(lc,b,mid);
    build(rc,mid+1,e);
}

ll query(ll n,ll b,ll e,ll i,ll j,ll v,ll idx){
    if(b>j or e<i)  return 0;
    if(b>=i and e<=j){
        ll k=mst[n].order_of_key({v,idx});
        return k;
    }
    ll mid=(b+e)/2;
    return query(lc,b,mid,i,j,v,idx) + query(rc,mid+1,e,i,j,v,idx);
}

void update(ll n,ll b,ll e,ll i,ll v,ll nw){
    if(i<b or e<i)  return;
    if(b==i and e==i){
        mst[n].erase(mst[n].find({v,i}));
        mst[n].insert({nw,i});
        return;
    }
    ll mid=(b+e)/2;
    update(lc,b,mid,i,v,nw);
    update(rc,mid+1,e,i,v,nw);
    mst[n].erase(mst[n].find({v,i}));
    mst[n].insert({nw,i});
}

int main(){
    ll test,i,j,queries;
    scanf("%lld",&test); // number of test cases
    while(test--){
        scanf("%lld",&n);  //number of elements in the array
        init(n);        // initializing the policy based tree
        for(i=1;i<=n;i++){
            scanf("%lld",&arr[i]);  //scanning the array
        }
        build(1,1,n);
        cin>>queries;       //number of queries
        while(queries--){
            ll choice;
            scanf("%lld",&choice);      //if choice is 0 -> it represents query, choice 1 -> represents update
            if(choice==0){
                ll l,r,x;
                scanf("%lld %lld %lld",&l,&r,&x);       //  the x-th number in sorted a[l ... r] segment
                ll low = mst[1].find_by_order(0)->first, high = mst[1].find_by_order(n-1)->first , mid, ans ;
                // binary search to find the x-th number
                while(low <= high) {
                    mid = low + high >> 1;
                    ll k = query(1,1,n,l,r,mid,1005);// i have considered the highest element in the array to be 1000, change according to your program
                    if(k >=x ) {
                        ans = mid;
                        high = mid-1;
                    }
                    else low = mid+1;
                }
                printf("%lld\n",ans);
            }
            else{               
                // Update the profit of the idx-th shop to x
                ll idx,x;
                scanf("%lld %lld",&idx,&x);
                update(1,1,n,idx,arr[idx],x);
                arr[idx]=x;
            }
        }
    }
    return 0;
}