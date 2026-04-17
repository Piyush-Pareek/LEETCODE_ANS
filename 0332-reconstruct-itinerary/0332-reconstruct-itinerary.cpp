class Solution {
public:
vector<string>ans;
int count = 0;
void dfs(map<string,vector<string>>&m,string curr){
    if(m.find(curr) == m.end()) {
        ans.push_back(curr);

        return ;
    }   
        
        auto temp = m[curr];
       while(m[curr].size()){
            string c = m[curr].back();
        m[curr].pop_back();
        dfs(m,c);
        }
    
    ans.push_back(curr);
}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<string>>m1;
        for(int i=0;i<tickets.size();i++){
            m1[tickets[i][0]].push_back(tickets[i][1]); 
        }
        for(auto&x:m1){
            sort(x.second.rbegin(),x.second.rend());
        }
        dfs(m1,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};