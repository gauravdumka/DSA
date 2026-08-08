class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=INT_MAX; int low=0; int high=0; int sum=0;
        while(high<nums.size()){
            sum+=nums[high];
            while(sum>=target){
                len=min(len,high-low+1);
                sum-=nums[low];
                low++;
            }
            
            high++;
        }
        return (len==INT_MAX?0:len);

    }
};