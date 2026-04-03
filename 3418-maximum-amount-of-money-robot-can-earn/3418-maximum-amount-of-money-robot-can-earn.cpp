class Solution {
public:
    int memo[550][550][3];
    int maximumamount(vector<vector<int>>& num,int i,int j,int chance){
        if(i<0||j<0||i>=num.size()||j>=num[0].size()) return -1e9;
        if(i==num.size()-1&&j==num[0].size()-1){
            if(num[i][j]<0&&chance>0) return 0;
            return num[i][j];
        }
        if(memo[i][j][chance]!=-1e9) return memo[i][j][chance];
        int max_money = -1e9;
        if(num[i][j]<0){
           int a = maximumamount(num,i+1,j,chance);
           int b =  maximumamount(num,i,j+1,chance);
            max_money = max(max_money,num[i][j]+max(a,b));
            if(chance>0){
            int x =maximumamount(num,i+1,j,chance-1);
            int y = maximumamount(num,i,j+1,chance-1);
            max_money = max(max_money,max(x,y));
            }
        }else{
            
           int a = maximumamount(num,i+1,j,chance);
            int b =maximumamount(num,i,j+1,chance);
           max_money = max(max_money,num[i][j]+max(a,b));
        }
            return memo[i][j][chance] = max_money;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        
        fill(&memo[0][0][0],&memo[0][0][0]+(550*550*3),-1e9);
        return maximumamount(coins,0,0,2);
        
    }
};