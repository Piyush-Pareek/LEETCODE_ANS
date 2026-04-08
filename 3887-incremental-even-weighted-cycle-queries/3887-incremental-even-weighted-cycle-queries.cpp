class Solution {
public:
    // Notice: dist array is now 'long long'
    int find_parent(int i, vector<int>& parent, vector<long long>& dist) {
        if (parent[i] == i) {
            return i;
        }
        int root = find_parent(parent[i], parent, dist);
        
        // NO MODULUS: We are now adding the raw distances together
        dist[i] = (dist[i] + dist[parent[i]]%2); 
        
        parent[i] = root; // Path compression remains intact
        return root;
    }
    
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        
        // Changed to long long so the massive raw sums don't crash the program
        vector<long long> dist(n, 0); 
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        int count = 0;
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            long long w = edges[i][2]; // Treat weight as long long for safe addition
            
            int root_u = find_parent(u, parent, dist);
            int root_v = find_parent(v, parent, dist);
            
            if(root_u == root_v){
                // CYCLE DETECTED!
                // We still use % 2 here because the problem specifically asks 
                // us to count cycles that have an EVEN total weight. 
                // But now it is calculating the modulo of the massive raw sum.
                if((dist[u] + dist[v] + w) % 2 == 0){
                    count++;  
                }
            } else {
                // DIFFERENT PARENTS
                count++;
                
                parent[root_u] = root_v;
                
                // NO MODULUS: Just straight addition of the raw weights
                dist[root_u] = (dist[u] + dist[v] + w)%2;
            }
        }
        return count;
    }
};