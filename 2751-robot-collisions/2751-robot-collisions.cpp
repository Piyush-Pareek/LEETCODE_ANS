class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<int>right;
        stack<int>left;
        vector<pair<int,pair<int,char>>>num;
        map<int,int>m;
        for(int i=0;i<positions.size();i++){
            num.push_back({positions[i],{healths[i],directions[i]}});

        }
        sort(num.begin(),num.end());
        
        for(int i=0;i<positions.size();i++){
            m[num[i].first] = i;
            if(num[i].second.second=='R'){
                right.push(i);
            }else{
                if(!right.empty()){
                while(!right.empty()){
                    int x = right.top();
                    if(num[x].second.first>num[i].second.first){
                        num[x].second.first = num[x].second.first-1;
                        num[i].second.first = -1;
                        break;
                    }else if(num[x].second.first<num[i].second.first){
                        right.pop();
                         num[x].second.first = -1;
                        left.push(i);
                        num[i].second.first = num[i].second.first-1;
                    }else{
                         num[i].second.first =  num[x].second.first = -1;
                        right.pop();
                        break;
                    }
                }
                }else{
                    left.push(i);
                }
            }
        }
       
        vector<int>ans;
        for(int i=0;i<positions.size();i++){
            int j = m[positions[i]];
            if(num[j].second.first!=-1){
                ans.push_back(num[j].second.first);
            }
        }
        return ans;
    }
};