class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int xLeft = 0;
        int xRight = matrix[0].size() - 1;
        int yTop = 0;
        int yBottom = matrix.size() - 1;
        int i = 0, j = 0;
        vector<int> ans;
        
         int totalElements = matrix.size() * matrix[0].size();
        while (ans.size() < totalElements) {
           
             for(int i = xLeft;i<=xRight;i++){
                ans.push_back(matrix[yTop][i]) ;
             }
             yTop++;
             if(ans.size() == totalElements) break;
             for(int j = yTop;j<=yBottom;j++){
                ans.push_back(matrix[j][xRight]); 
             }
            xRight--;
            if(ans.size() == totalElements) break;
             for(int i = xRight;i>=xLeft;i--){
                ans.push_back(matrix[yBottom][i]); 
             }
            yBottom--;
            if(ans.size() == totalElements) break;

             for(int i = yBottom;i>=yTop;i--){
                ans.push_back(matrix[i][xLeft]); 
             }
            xLeft++;
        }
        return ans;
    }
};
