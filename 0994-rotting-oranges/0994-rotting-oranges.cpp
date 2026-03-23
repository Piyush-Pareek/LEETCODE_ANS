class Solution {
public:
 void rooten(vector<vector<int>>&visited,int i,int j,vector<vector<int>>& grid,int mins,vector<vector<int>>&time){
        if(i<0||j>=visited[0].size()||i>=visited.size()||j<0||grid[i][j] ==0)return ;
     if(visited[i][j]==1){
         if(mins>time[i][j]) return;
     }
        visited[i][j]=1;
        if(grid[i][j] ==2)mins=0;
        time[i][j] = min(time[i][j],mins);
        rooten(visited,i-1,j,grid,mins+1,time);
        rooten(visited,i,j-1,grid,mins+1,time);
        rooten(visited,i,j+1,grid,mins+1,time),
        rooten(visited,i+1,j,grid,mins+1,time);
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans =0;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        vector<vector<int>>time(grid.size(),vector<int>(grid[0].size(),INT_MAX));
       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++){
               if(visited[i][j] == 0&&grid[i][j]==2){
                  rooten(visited,i,j,grid,0,time);
               }
           }
       }
         for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++){    
              if(visited[i][j] == 0&&grid[i][j]!=0){
                 return -1;
               }else if(grid[i][j]!=0){
                  ans = max(ans,time[i][j]);
              }
           }
       }
        return ans;
    }
};