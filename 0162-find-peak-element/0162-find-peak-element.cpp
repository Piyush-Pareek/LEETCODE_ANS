class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n+2);
        arr[0]=arr[n+1]=INT_MIN;
        for(int i=0;i<n;i++)
        {
            arr[i+1]=nums[i];
        }
        int left=1;
        int right=n;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                return mid-1;
            }
            else if(arr[mid+1]>arr[mid])
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        return (left-1);
    }
};