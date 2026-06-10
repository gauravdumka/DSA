class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n =nums.size();
        int stop = -1;
        for(int i =n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                stop=i;
                break;
            }
        }
        if(stop==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i= n-1 ; i>stop ;i--){
            if(nums[i]>nums[stop]){
                swap(nums[i],nums[stop]);
                break;
            }
        }
        reverse(nums.begin()+stop+1,nums.end());
        return;
    }
    
};