class Solution {
public:
    int count_goal(vector<int>&nums, int goal){
        int l=0; int r=0; int sum=0; int cnt=0;
        while(r<nums.size()){
            if(goal<0) return 0;
            sum+=nums[r]%2;
            while(sum>goal){
                sum-=nums[l]%2;
                l++;
            }
            if(sum<=goal){
                cnt+=((r-l)+1);
            }
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int goal1= count_goal(nums,k);
        int goal2= count_goal(nums, k-1);
        return goal1-goal2;
    }
};