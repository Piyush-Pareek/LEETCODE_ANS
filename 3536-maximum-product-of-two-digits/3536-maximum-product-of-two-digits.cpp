class Solution {
public:
    int maxProduct(int n) {
        unordered_map<int,int>m;
        while(n){
           m[n%10]++;
            n/=10;
        }
        int max_val = -1,max_val2 = -1;
        for(auto x:m){
            
           if(max_val<x.first||max_val == -1){

            max_val2 = max_val;
            max_val = x.first;
           }else{
            max_val2 = max(max_val2,x.first);
           }
        }
        cout<<max_val<<" "<<max_val2<<endl;
        if(m[max_val]>1)return max_val*max_val;

        return max_val*max_val2;
    }
};