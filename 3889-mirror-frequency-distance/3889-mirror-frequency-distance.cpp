class Solution {
public:
    int mirrorFrequency(string s) {
        map<char,int>m1;
        map<int,int>m2;
        for(int i=0;i<s.length();i++){
            if(s[i]>='a'&&s[i]<='z'){
                m1[s[i]]++;
            }else{
                m2[(s[i]-'0')]++;
            }
        }
        int sum =0;
        for(auto x:m1){
            char c = x.first;
            if(m1[c]==0) continue;
            char c2 = 'z'+'a'-x.first;
            if(m1.find(c2)!=m1.end()){
                sum+=abs(m1[c]-m1[c2]);
                m1[c] = 0;
                m1[c2] = 0;
            }else{
                                sum+=m1[c];
    m1[c] =0;
            }
        }
        for(auto x:m2){
            int  c = x.first;
            if(m2[c]==0) continue;
            int c2 = 9-(x.first);
            if(m2.find(c2)!=m2.end()){

                sum+=abs(m2[c]-m2[c2]);
                m2[c] = 0;
                m2[c2] = 0;
            }else{
                sum+=m2[c];
                m2[c]=0;
            }
        }
        return sum;
    }
};