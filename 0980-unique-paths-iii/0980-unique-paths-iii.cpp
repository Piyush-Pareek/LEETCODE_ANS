class Solution {
public:
int ans=0;
    void solve(vector<vector<int>>&grid,int count,int i,int j,pair<int,int>endIndex,vector<vector<int>>&visited,int curr_count){
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0||grid[i][j]==-1||visited[i][j]== 1)return;
        visited[i][j] = 1;
        if(i == endIndex.first&&j==endIndex.second&&curr_count == count-1){
            ans++;
        }else{
            solve(grid,count,i+1,j,endIndex,visited,curr_count+1);
            solve(grid,count,i-1,j,endIndex,visited,curr_count+1);
            solve(grid,count,i,j+1,endIndex,visited,curr_count+1);
            solve(grid,count,i,j-1,endIndex,visited,curr_count+1);
        }
        visited[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count = 0;
        pair<int,int> startIndex,endIndex;
        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[i].size();j++){
                if(grid[i][j]==-1)count++;
                else if(grid[i][j]==1)
                {
                    startIndex.first = i;
                    startIndex.second = j;
                }else  if(grid[i][j]==2){
                    endIndex.first = i;
                    endIndex.second = j;
                }
            }
        }
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        count = (grid.size()*grid[0].size())-count;
        solve(grid,count,startIndex.first,startIndex.second,endIndex,visited,0);

    return ans;
    }
};