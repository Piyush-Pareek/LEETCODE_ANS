class Solution {
public:
    
    int dfs(vector<vector<int>>&matrix,int i,int j,int len,int prev,vector<vector<int>>&memo){
        if(i<0||j<0||i>=matrix.size()||j>=matrix[i].size()||matrix[i][j]<=prev){
            return  0;
        } 
        // 4 calls ;
       
        return memo[i][j] = max(dfs(matrix,i-1,j,len+1,matrix[i][j],memo),max(
        dfs(matrix,i+1,j,len+1,matrix[i][j],memo),max(
        dfs(matrix,i,j-1,len+1,matrix[i][j],memo),
        dfs(matrix,i,j+1,len+1,matrix[i][j],memo))))+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>>memo(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i =0;i<matrix.size();i++){
            for(int j =0;j<matrix[i].size();j++){
             ans = max(dfs(matrix,i,j,0,-1,memo),ans);
            }
        }

        return ans;
    }
};