class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int count = 0;
        for(int i =0;i<nums.size(); i++){
            if(nums[i]==1){
                count++;
                maxi=max(maxi,count);
            }
            // use else without any condition in cpp
            else{
                // wrong---> will not update at last pair [1,1,0,1,1,1]
                //maxi = max(maxi , count);
                count=0;

            }
        }
        return maxi;
    }
};