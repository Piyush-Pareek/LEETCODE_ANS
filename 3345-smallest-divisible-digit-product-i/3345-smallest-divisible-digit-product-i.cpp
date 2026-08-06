class Solution {
public:
    int smallestNumber(int n, int t) {
        int prod = 1;
        int x = n;
        x/=10;
        while(x){
            prod*=(x%10);
            x/=10;
        }
        for(int i=0;i<10;i++){
            if((prod*(n%10))%t==0)return n;
            n++;
        }
        return -1;
    }
};