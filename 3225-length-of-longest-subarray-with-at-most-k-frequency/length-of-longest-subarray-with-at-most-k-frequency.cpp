class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0; int j=0; map<int,int>mpp; int result=0;
        while(j<nums.size()){
            mpp[nums[j]]++;
            while(mpp[nums[j]]>k){
                mpp[nums[i]]--;
                i++;
            }
            result=max(result,j-i+1);
            j++;
        }
        return result;
    }
};