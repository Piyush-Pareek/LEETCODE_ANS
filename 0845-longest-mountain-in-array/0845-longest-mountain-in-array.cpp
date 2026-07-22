class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int max_size = INT_MIN;
        int count =0;
        bool flag = false;
        bool updown = false;
        for(int i=1;i<arr.size();i++){
            if(flag){
             
                if(updown){ // true means up
                    if(arr[i]<arr[i-1]){
                        updown = false;
                        count++;
                    }else if(arr[i]==arr[i-1]){
                        updown = true;
                        flag = false;
                         count = 0;
                    }else count++;
                }else{
                    if(arr[i]>arr[i-1]){
                        
                        flag = false;
                        max_size = max(max_size,count);count = 0;
                        i--;
                    }else if(arr[i]==arr[i-1]){
                        updown = true;
                        flag = false;
                         max_size = max(max_size,count);
                         count = 0;
                    }else count++;
                }
                //    count++;
            }else{
                if(arr[i]>arr[i-1]){
                    flag = true;
                    updown = true;
                    count++;
                    count++;
                }
            }
        }
        if(flag&&!updown){
            max_size = max(max_size,count);
        }
        if(max_size == INT_MIN)return 0;
        return max_size;
    }
};