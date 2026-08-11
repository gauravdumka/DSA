class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int minending =nums[0]; int maxending=nums[0]; int result=nums[0];
        if(nums.size()==1){
            return nums[0];
        }
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=nums[i]*minending;
            int v3=nums[i]*maxending;
            minending= min(nums[i], min(v2,v3));
            maxending= max(nums[i], max(v2,v3));
            result=max(result,maxending);
        }
        return result;
    }
};