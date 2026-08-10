class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int cnt=0; 
        while(true){
            int mini=INT_MAX;
            int cntz=0;
            for(int i=0;i<nums.size();i++){  
                if(nums[i]==0){
                    cntz++;
                    continue;
                }
                mini=min(mini,nums[i]);
            }
            if(cntz==nums.size()){
                return cnt;
            }
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    continue;
                }
                nums[i]-=mini;
            }
            cnt++;
        }
    }
};