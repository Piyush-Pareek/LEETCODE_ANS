class Solution {
public:

    void solve(vector<pair<int,list<int>>>&graph,int target,unordered_map<int,int>&removed){
        if(graph[target].first == -1){
            return;
        }
        graph[target].first = -1;
        removed[target]=1;
        for(auto x:graph[target].second){
            solve(graph,x,removed);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<pair<int,list<int>>>graph(n);
        for(int i=0;i<n;i++){
            graph[i].first =0;
        }
        for(int i=0;i<invocations.size();i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            graph[u].second.push_back(v);
            
        }
        unordered_map<int,int>removed;
        solve(graph,k,removed);
        bool flag = true;
        for(auto x:graph){
            if(x.first!=-1){
                for(auto y:x.second){
                    if(removed.find(y)!=removed.end()){
                        flag = false;
                        break;
                    }
                }
                if(!flag)break;
            }
        }
        vector<int>ans;
        if(!flag){
            ans.resize(n);

        iota(ans.begin(),ans.end(),0);
        }
        else{
            
            for(int i=0;i<graph.size();i++){
                if(graph[i].first!=-1)ans.push_back(i);
            }
        }
        return ans;
    }
};