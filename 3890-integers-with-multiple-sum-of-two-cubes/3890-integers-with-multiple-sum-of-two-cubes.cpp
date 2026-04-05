class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<long long,int>m;
        int x = static_cast<int>(cbrt(n));
        for(int i=1;i<=x;i++){
            for(int j=i;j<=x;j++){
                long long temp = (1LL*i*i*i)+(1LL*j*j*j);
                if(temp<=n)
                m[temp]++;
            }
        }
        vector<int>ans;
        for(auto z:m){
            if(z.second>1){
                ans.push_back(z.first);
            }
        }
        return ans;
    }
};