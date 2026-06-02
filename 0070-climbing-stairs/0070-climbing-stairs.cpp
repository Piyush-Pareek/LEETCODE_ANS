class Solution {
public:

    // int climb(int n,int pos,vector<int>&vec ){

    //     if(pos == n){
    //         return 1;
    //     }
    //     if(pos>n) return 0;
    //     if(vec[pos] != -1) return vec[pos];
    // // int i c);
    // // int j = climb(n,pos+2,vec);
    
    // return vec[pos] =climb(n,pos+1,vec)+ climb(n,pos+2,vec) ;
    // }
    int climbStairs(int n) {
        // vector<int> vec(n+1,-1);
        int l=0;
        int l1 = 1;
        for(int i=1;i<=n;i++){
            int temp = l+l1;
            l = l1;
            l1 = temp;
        }
        return l1;
    }
};