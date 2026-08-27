class Solution {
public:
    bool canJump(vector<int>& nums) {
        int MAX_IDX=0;
        for(int i=0;i<nums.size();i++){
            if(i>MAX_IDX)return false;
            MAX_IDX=max(MAX_IDX,nums[i]+i);
            // if((nums[i]==0)&&(MAX_IDX==i)){
            //     return false;
            // }
        }
        return true;
    }
};