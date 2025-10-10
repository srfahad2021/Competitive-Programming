class SegmentTree{
public:
    vector<vector<int>> tree; //0-mn, 1-mx, 2-sum
    SegmentTree(int n){
        tree.assign(3, vector<int>(4*n+1, 0));
    }
    void build(vector<int> &a, int l, int r, int node){
        if(l>r) return;
        if(l==r){
            tree[0][node]=a[l];
            tree[1][node]=a[l];
            tree[2][node] =a[l];
            return;
        }
        int mid = (l+r) /2;
        build(a, l, mid, 2*node);
        build(a, mid+1, r, 2*node+1);

        tree[0][node] = min(tree[0][2*node] , tree[0][2*node + 1]);
        tree[1][node] = max(tree[1][2*node] , tree[1][2*node + 1]);
        tree[2][node] = tree[2][2*node] + tree[2][2*node+1];
    }

    void update( int node, int l, int r, int idx, int value){
        if(l>r) return;
        if(l==r){
            tree[0][node]=value;
            tree[1][node]=value;
            tree[2][node] =value;
            return;
        }
        int mid = (l+r)/2;
        if(idx >=l and idx<=mid){
            update(2*node, l, mid, idx, value);
        }
        else{
            update(2*node+1, mid+1, r, idx, value);
        }
        tree[0][node] = min(tree[0][2*node] , tree[0][2*node + 1]);
        tree[1][node] = max(tree[1][2*node] , tree[1][2*node + 1]);
        tree[2][node] = tree[2][2*node] + tree[2][2*node+1];
    }

    //b=begin, e=end
    int query_mn(int node, int l, int r, int b, int e){
        if(l>=b and r<=e) return tree[0][node];
        if(l>e or r<b) return 1e18; // return invalid value;
        int mid = (l+r) /2;
        int left = query_mn(2*node, l, mid, b, e);
        int right = query_mn(2*node+1, mid+1, r, b, e);
        return min(left, right);
    }
    int query_mx(int node, int l, int r, int b, int e){
        if(l>=b and r<=e) return tree[1][node];
        if(l>e or r<b) return -1e18; // return invalid value;
        int mid = (l+r) /2;
        int left = query_mx(2*node, l, mid, b, e);
        int right = query_mx(2*node+1, mid+1, r, b, e);
        return max(left, right);
    }
    int query_sum(int node, int l, int r, int b, int e){
        if(l>=b and r<=e) return tree[2][node];
        if(l>e or r<b) return 0; // return invalid value;
        int mid = (l+r) /2;
        int left = query_sum(2*node, l, mid, b, e);
        int right = query_sum(2*node+1, mid+1, r, b, e);
        return left + right;
    }


};
