const int N = 1e5;
int parent[N];
int rating[N];

void init(int n){
    for(int i=1; i<=n; i++){
        parent[i]=i;
        rating[i]=1;
    }
}

// TC = o(4) 
int find_parent(int node){
    return parent[node] = (parent[node]==node ? node: find_parent(parent[node]));
}

bool merge(int u, int v){
    int par1 = find_parent(u);
    int par2 = find_parent(v);
    if(par1==par2){
        return true;
    }
    else{
        if(rating[par1] >= rating[par2]){
            parent[par2] = par1;
            rating[par1] += rating[par2];
        }
        else{
            parent[par1]=par2;
            rating[par2]+= rating[par1];
        }
        return false;
    }
}