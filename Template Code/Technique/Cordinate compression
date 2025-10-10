void cordinate_compression(vector<int> &ar){ // zero based
    map<int,int> coordinateCompress;
    int compressed_Num = 1;
    for(int i = 0; i < ar.size(); i++){
        if(coordinateCompress.find(ar[i]) != coordinateCompress.end()){
            ar[i] = coordinateCompress[ar[i]];
        }
        else{
            coordinateCompress[ar[i]] = compressed_Num;
            ar[i] = compressed_Num++;
        }
    }
}