class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // dynamic sliding window
        long long sum=0;
        int mini=INT_MAX;
        int low=0;
        int high=0;
        while(high<nums.size()){
            sum+=nums[high];
            // int len=high-low+1;
            while(sum>=target){
                int len=high-low+1;
                mini=min(mini,len);
                sum=sum-nums[low];
                low++;
            }
            high++;
        }
        if(mini!=INT_MAX)return mini;
        else return 0;

    }
};