class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum=0;
        long long maxsum= LONG_MIN;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            maxsum=max(maxsum,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxsum;
    }
};