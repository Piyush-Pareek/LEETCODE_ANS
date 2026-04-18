class Solution {
public:
    int mirrorDistance(int n) {
        string rev="";
        int x = n;
        while(x!=0){
        rev+=((x%10)+'0');
            x/=10;
        }
        long long l=0;
        for(int i=0;i<rev.size();i++){
            l=(rev[i]-'0')+l*10;
        }
        return abs(n-l);
    }
};