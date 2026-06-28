class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int prev = 1;
        
        arr[0]=1;
        for(int i=1;i<arr.size();i++){
            if(prev!=arr[i]){
                arr[i] = prev+1;
                prev = arr[i];
            }
        }
        return arr.back();
    }
};