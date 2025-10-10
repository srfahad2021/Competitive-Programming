//finding frequency of P in S, as a substring.
// call build_failure_function() first 
#define MAX 1000005 
int failure[MAX]; 
//longest prefix that also mactchs current suffix
void build_failure_function(string pattern, int m) { 
    failure[0] = 0; 
    failure[1] = 0; //base case 
    
    for(int i = 2; i <= pattern.size(); i++) { 
        int j = failure[i - 1]; 
        while(true) { 
        if(pattern[j] == pattern[i - 1]) { 
            failure[i] = j + 1; 
            break; 
        } 
        if(j == 0) { 
            failure[i] = 0; 
            break; 
        } 
        j = failure[j]; 
        } 
    } 
} 

int frequency_of_P_in_S(string &s, stirng &p){
    build_failure_function(p, p.size()); 
    int total_mtc = 0; 
    int ans=0; 
    for(int i=0; i<s.size(); i++){ 
        if(s[i]==p[total_mtc]) total_mtc++; 
        else{ 
            while(total_mtc > 0){ 
                total_mtc = failure[total_mtc]; 
                if(s[i]==p[total_mtc]){ 
                    total_mtc++; 
                    break; 
                } 
            } 
        } 
        if(p.size() == total_mtc){ 
            ans++; 
            total_mtc = failure[total_mtc]; 
        } 
    } 
    return ans;
}
