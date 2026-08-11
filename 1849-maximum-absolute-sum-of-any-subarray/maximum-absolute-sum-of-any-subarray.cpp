class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxending = 0;
        int minending = 0;
        int result = 0;

        for(int i = 0; i < nums.size(); i++) {
            maxending = max(maxending + nums[i], nums[i]);
            minending = min(minending + nums[i], nums[i]);

            result = max(result, max(abs(maxending), abs(minending)));
        }

        return result;
    }
};