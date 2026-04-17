class Solution {
public:
    string longestPalindrome(string s) {
        int count=0,pos1=0,pos2=0;
        for(int i =0;i<s.length();i++){
            int end =s.length()-1;
            while(i!=end){
                
            
           int a = i,e = end,flag = 1;
            while(a<e){
                if(s[a++]!=s[e--]){ flag = 0;break;}
            }
                   if(a>=e&&flag){
                      if( count < end-i+1){
                        count = end-i+1;
                        pos1=i;
                        pos2=end;
                      }
                       
                   }
                   
                   end--;
        }
                   
    }cout<<pos1<<pos2;
        return string(s.begin()+pos1,s.begin()+pos2+1);
    }
};