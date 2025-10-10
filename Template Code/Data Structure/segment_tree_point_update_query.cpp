class SegmentTree{
public:
    vector<int> tree; //0-mn, 1-mx, 2-sum
    SegmentTree(int n){
        tree.assign(4*n+1, 0);
    }
    void build(vector<int> &a, int l, int r, int node){
        if(l>r) return;
        if(l==r){
            tree[node] =a[l];
            return;
        }
        int mid = (l+r) /2;
        build(a, l, mid, 2*node);
        build(a, mid+1, r, 2*node+1);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update( int node, int l, int r, int idx, int value){
        if(l>r) return;
        if(l==r){
            tree[node] =value;
            return;
        }
        int mid = (l+r)/2;
        if(idx >=l and idx<=mid){
            update(2*node, l, mid, idx, value);
        }
        else{
            update(2*node+1, mid+1, r, idx, value);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    //b=begin, e=end
    int query_sum(int node, int l, int r, int b, int e){
        if(l>=b and r<=e) return tree[node];
        if(l>e or r<b) return 0; // return invalid value;
        int mid = (l+r) /2;
        int left = query_sum(2*node, l, mid, b, e);
        int right = query_sum(2*node+1, mid+1, r, b, e);
        return left + right;
    }
};