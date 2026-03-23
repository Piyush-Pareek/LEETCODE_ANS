class Solution {
public:
    vector<string>invalidTransactions (vector<string>& s) {
        unordered_map<string,vector<pair<int,pair<int,string>>>>m;
        vector<string>ans;
        for(int i=0;i<s.size();i++){
            string temp = s[i];
            vector<string>str;
            string name="";
            int amt ;
            int mi;
            string city="";
            int j = 0;
            string x="";
            while(j<temp.size()){
                if(temp[j]==','){
                    str.push_back(x);
                    x="";
                    
                }else{
                    x+=temp[j];
                    if(j == temp.size()-1){
                        str.push_back(x);
                    }
                }
                j++;
            }
            name = str[0];
            mi = std::stoi(str[1]);
            amt = std::stoi(str[2]);
            city = str[3];
            if(amt>1000){
                ans.push_back(temp);
                m[name].push_back({mi,{-1,city}});
            }
            else
            m[name].push_back({mi,{i,city}});
        }
        for(auto nu:m){
            auto& num = nu.second;
            for(int i=0;i<num.size();i++){
                for(int j = 0;j<num.size();j++){
                    if(num[i].second.second!=num[j].second.second&&i!=j){
                        int mint = abs(num[i].first-num[j].first);
                        if(mint<=60) {
                            
                            
                            if(num[i].second.first!=-1)
                            ans.push_back(s[num[i].second.first]);
                            
                            
                            if(num[j].second.first!=-1)
                            ans.push_back(s[num[j].second.first]);
                            num[i].second.first = -1;
                            num[j].second.first= -1;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};