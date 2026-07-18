class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=INT_MAX; int maxi=0; int ans=1;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        for(int i=2;i<=mini;i++){
            if(mini%i==0 && maxi%i==0){
                ans=i;
            }
        }
        return ans;
    }
};