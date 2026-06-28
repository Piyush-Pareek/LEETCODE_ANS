class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
                // arr[0] =1;
                unordered_map<int,int>m;
                for(int i=0;i<arr.size();i++){
                    m[arr[i]]++;
                }
                int count = 1;
                int borrow = 0;
                for(int i=1;i<=arr.size();i++){
                    if(m.find(count)!=m.end()){
                        
                        if(m[count]<=borrow){
                            borrow-=m[count];
                            borrow++;
                        }
                        else{

                        i+=m[count]-borrow-1;
                        if(borrow)
                        borrow=0;
                        }
                    }else{
                        borrow++;
                    }
                    count++;
                }
              return count-1;
    }
};