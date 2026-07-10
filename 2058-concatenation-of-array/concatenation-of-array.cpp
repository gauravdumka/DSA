class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        nums.resize(2*n);
        int j=0;
        for(int i=n;i<(n+n);i++){
            nums[i]=nums[j];
            j++;
        }
        return nums;
    }
};