class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=0; int smaxi=0;
        for(int i=0; i<nums.size();i++){
            if(maxi<nums[i]){
                smaxi=maxi;
                maxi=nums[i];
            }else if(nums[i]>smaxi){
                smaxi=nums[i];
            }
        }
        return ((maxi -1)*(smaxi-1));
    }
};