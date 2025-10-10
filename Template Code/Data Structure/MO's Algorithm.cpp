const int rootN = 555; // can be changed according to the N
int freq[200000];
int distinct;
vector<int> ar(200000);

struct query{
    int L;
    int R;
    int q_no;
    int block_no;
    bool operator < (query& q2){
        if(block_no < q2.block_no) return 1;
        else if(block_no > q2.block_no) return 0;
        else return R < q2.R;
    }
};

void Add(int& elem){
    if(!freq[elem]) distinct++;
    freq[elem]++;
}
void Remove(int& elem){
    freq[elem]--;
    if(!freq[elem]) distinct--;
}

void adjust(int& curr_l, int& curr_r, query& q){
    while(curr_l > q.L){
        curr_l--;
        Add(ar[curr_l]);
    }
    while(curr_r < q.R){
        curr_r++;
        Add(ar[curr_r]);
    }
    while(curr_l < q.L){
        Remove(ar[curr_l]);
        curr_l++;
    }
    while(curr_r > q.R){
        Remove(ar[curr_r]);
        curr_r--;
    }
}

query make_query(int l, int r, int index){
    query q;
    q.L = l-1;
    q.R = r-1;
    q.q_no = index;
    q.block_no = l/rootN;
    return q;
}

void mos_algorithm(vector<query>& queries){
    vector<int> answer(queries.size());
    sort(queries.begin(), queries.end());
    memset(freq, 0, sizeof freq);
    distinct = 1;
    int curr_l = queries[0].L;
    int curr_r = queries[0].L;
    freq[ar[curr_l]]++;
    for(query& qr : queries){
        adjust(curr_l, curr_r, qr);
        answer[qr.q_no] = distinct;
    }
    for(int x : answer) cout<<x<<'\n';
}