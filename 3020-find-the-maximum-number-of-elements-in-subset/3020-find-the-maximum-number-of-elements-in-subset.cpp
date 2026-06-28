class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>m;
        m.reserve(100000);
        for(int i =0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int size =0;
        int max_size=0;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++){
            if(m[nums[i]]==-1)continue;
            size=0;
            if(nums[i]==1){
                size+=m[nums[i]];
                if(size%2==0)size--;
            }else{
                long long x = nums[i];
                while(1){
                    if(m.find(x)==m.end()){
                        size--;
                        break;
                    }
                if(m[x]>=2){
                    size+=2;
                    m[x]=-1;
                    if(x>31622){
                    size--;
                    break;
                }
                    x = x*x;
                }else if(m[x]>0){
                    size++;
                    m[x]=-1;
                    break;
                }
                
                }
            }
                if(size%2!=0)
                max_size = max(max_size,size);
        }
        return max_size;
    }
};