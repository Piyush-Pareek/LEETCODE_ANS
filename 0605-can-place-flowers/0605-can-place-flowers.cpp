class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbad, int n) {
        bool flag = false;
        for(int i =0;i<flowerbad.size();i++){
            if(flowerbad[i]==1){
                flag = true;
               
            }else{
                if(flag||(i+1<flowerbad.size()&&flowerbad[i+1]==1)){
                    flag = false;
                }else{
                    n--;
                    flag = true;
                //    ? cout<<"YES";
                }
            }
        }
        if(n>0) return false;
        return true;
    }
};