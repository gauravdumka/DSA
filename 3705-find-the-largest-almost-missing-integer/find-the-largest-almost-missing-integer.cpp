class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        for(int x : nums) {
            freq[x]++;
        }

        // Only one subarray
        if(k == n) {
            int ans = -1;

            for(auto x : freq) {
                ans = max(ans, x.first);
            }

            return ans;
        }

        // Every element forms its own subarray
        if(k == 1) {
            int ans = -1;

            for(auto x : freq) {
                if(x.second == 1) {
                    ans = max(ans, x.first);
                }
            }

            return ans;
        }

        int ans = -1;

        // Only nums[0] and nums[n-1] can belong to exactly one window
        if(freq[nums[0]] == 1)
            ans = max(ans, nums[0]);

        if(freq[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};