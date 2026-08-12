class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int bestending = 0;
        int result = INT_MIN;
        int minending = 0;
        int minsum = INT_MAX;
        int total = 0;
        
        for(int i=0;i<nums.size();i++){
            int v1=bestending+nums[i];
            int v2=nums[i];
            bestending=max(v1,v2);
            result=max(bestending,result);
            minending = min(minending + nums[i], nums[i]);
            minsum = min(minsum, minending);
            total+=nums[i];
        }
        if(result < 0)
            return result;
        return max(result, total - minsum);
    }
};