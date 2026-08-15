class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int XOR=0;
        for(int i=0;i<nums.size();i++){
            XOR^=nums[i];
        }
        if(XOR!=0){
            return n;
        }else if(XOR==0){
            for(int i=0;i<n;i++){
                if(nums[i]!=0){
                    return n-1;
                }
            }
            return 0;
        }
        return 0;
    }
};