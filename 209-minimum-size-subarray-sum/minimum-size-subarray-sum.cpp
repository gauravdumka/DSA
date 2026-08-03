class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=INT_MAX;
        int sum=0;
        int i=0;
        int j=0;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                len=min(j-i+1,len);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (len==INT_MAX?0:len);
    }
};