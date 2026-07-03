class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subsets = (1<<n);
        vector<vector<int>>ans;
        for(int i=0;i<(subsets);i++){
            vector<int>temp;
            int j=0;
            int k=i;
            while(k!=0){
                if((k&1)==1){
                    temp.push_back(nums[j]);
                }
                j++;
                k=(k>>1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};