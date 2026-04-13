class Solution {
public:
   
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int>ans;
        vector<list<int>>graph(n);
        vector<int>inorder(n,0);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[v].push_back(u);
            graph[u].push_back(v);
            inorder[u]++;
            inorder[v]++;
        }
       queue<int>q;
       for(int i=0;i<n;i++){
        if(inorder[i] == 1){
            q.push(i);
        }

       }
       int nodes = n;
        while(nodes>2){
            int len = q.size();
            nodes-=len;
            for(int i=0;i<len;i++){
            int c = q.front();
            q.pop();
            for(auto x:graph[c]){
                inorder[x]--;
                 if(inorder[x] == 1)q.push(x);
            }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};