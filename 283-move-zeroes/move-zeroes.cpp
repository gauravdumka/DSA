class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        //putting j on first occuring zero
        int j=-1;
        for(int i=0;i<n;i++){
            if (nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1)return;
        for(int i=j;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};