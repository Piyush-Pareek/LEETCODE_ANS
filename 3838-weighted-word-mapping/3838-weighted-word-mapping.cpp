class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s="";
        for(int i=0;i<words.size();i++){
            int sum =0;
            for(int j =0;j<words[i].size();j++){
                sum+=weights[words[i][j]-'a'];
            }
            sum = sum%26;
            char c = 'z'-sum;
            s+=c;
        }
        return s;
    }
};