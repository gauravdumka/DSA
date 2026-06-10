class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =nums.size();
        if(n==0){
            return 0;
        }
        int len=1;
        sort(nums.begin(),nums.end());
        int maxlen=1;
        int i=0;
        for(int j = 0; j<n;j++){
            if(nums[j]==nums[i]){
                continue;
            }
            if(nums[j]==nums[i]+1){
                i=j;
                len++;
                maxlen = max(maxlen,len);
            }
            else if(nums[j]>nums[i]+1){
                i=j;
                len=1;
            }
        }
        return maxlen;
    }
};