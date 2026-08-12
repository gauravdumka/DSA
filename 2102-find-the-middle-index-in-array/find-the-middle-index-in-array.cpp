class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int>prefixi(nums.size(),0);vector<int>suffixi(nums.size(),0); int prefix=nums[0];int suffix=nums[nums.size()-1];
       for(int i=1;i<nums.size();i++){
            prefixi[i]=prefix;
            prefix+=nums[i];
       }
       for(int i=nums.size()-2;i>=0;i--){
            suffixi[i]=suffix;
            suffix+=nums[i];
       }
       for(int i=0;i<nums.size();i++){
            if(prefixi[i]==suffixi[i]){
                return i;
            }
        
       }
       return -1;
    }
    
};