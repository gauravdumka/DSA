class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        if(nums.size()<=2) return nums.size();

        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] != nums[j]) {
                nums[j+2] = nums[i];
                j++;
            }
        }

        return min((int)nums.size(), j+2);
    }
};