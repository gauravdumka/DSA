class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi=INT_MIN; int smax=INT_MIN; int tmax=INT_MIN; 
        int mini=INT_MAX; int smin=INT_MAX;
        for(int i=0; i<nums.size();i++){
            if(nums[i]>maxi){
                tmax=smax;
                smax=maxi;
                maxi=nums[i];
            }else if(nums[i]>smax){
                tmax=smax;
                smax=nums[i];
            }else if(nums[i]>tmax){
                tmax=nums[i];
            }
             if (nums[i] < mini) {
                smin = mini;
                mini = nums[i];
            }
            else if (nums[i] < smin) {
                smin = nums[i];
            }
        }
        return max(maxi*smax*tmax , mini*smin*maxi);
    }
};