class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        pair<int,int> maxi, mini;
        maxi.first = INT_MIN;
        mini.first = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxi.first) {
                maxi.first = nums[i];
                maxi.second = i;
            }

            if(nums[i] < mini.first) {
                mini.first = nums[i];
                mini.second = i;
            }
        }

        int a = min(maxi.second, mini.second);
        int b = max(maxi.second, mini.second);
        int n = nums.size();

        return min({
            b + 1,    
            n - a,        
            a + 1 + n - b 
        });
    }
};