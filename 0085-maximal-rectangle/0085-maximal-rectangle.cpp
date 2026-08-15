class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<pair<int,int>>>dp(matrix.size(),vector<pair<int,int>>(matrix[0].size(),{0,0}));
        for(int i = matrix.size()-1;i>=0;i--){
            for(int j = matrix[0].size()-1;j>=0;j--){
                if(i == matrix.size()-1&&j == matrix[0].size()-1){
                    if(matrix[i][j] == '1'){
                        dp[i][j].first = 1;dp[i][j].second = 1;
                    }
                }
                else if(i == matrix.size()-1){
                     if(matrix[i][j] == '1'){
                    dp[i][j].first = dp[i][j+1].first+1;
                    dp[i][j].second = 1;
                     }
                }else if(j == matrix[0].size()-1){
                   
                     if(matrix[i][j] == '1'){
                    dp[i][j].first =1;
                       
                    dp[i][j].second =  dp[i+1][j].second+1;;
                    }
                }else if(i < matrix.size()-1&&j < matrix[0].size()-1 ){
                    if(matrix[i][j] == '1'){
                        dp[i][j].first = dp[i][j+1].first+1;
                        dp[i][j].second = dp[i+1][j].second+1;
                    }
                }
            }
        }
for(int i =0;i<matrix.size();i++){
    for(int j =0;j<matrix[0].size();j++){
        cout<<dp[i][j].first<<" "<<dp[i][j].second<<" ,";
    }
    cout<<endl;
}
int maxRectArea = 0;
for(int i =0;i<matrix.size();i++){
    for(int j =0;j<matrix[0].size();j++){
        int bottom = dp[i][j].second;
        int right = dp[i][j].first;
        int maxArea = max(bottom,right);
        for(int k = i+1;k<i+bottom;k++){
            int x = min(right,dp[k][j].first);
            right = x;
            int area = x*(k-i+1);
            maxArea = max(maxArea,area);
        }
        cout<<maxArea<<" ,";
        maxRectArea = max(maxArea,maxRectArea);
    }
    cout<<endl;
    
}
return maxRectArea;
    }
};