class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool flag = true;
        int five =0,ten =0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            }else if(bills[i]==10){
                ten++;
                if(five>0)five--;
                else {
                    flag=false;
                    break;
                }
            }else{
                if(ten>0&&five>0){
                    ten--;five--;
                }else if(five>=3){
                    five-=3;
                }
                else{
                    flag = false;
                    break;
                }
            }
        }
        if(flag) return true;
        return false;
    }
};