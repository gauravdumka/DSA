class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // works on low high and mid
        //num will be always given by mid variable
        int n=nums.size();
        int low=0; int high=n-1;
        while(low<=high){
            int mid =(low+high)>>1;
            if(nums[mid]==target)return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                // continue is very imp because without it below conditions will execute
                // wrong for nums=[1] low,mid,high=0-->low=1,high=-1 which is wrong
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(target>=nums[low]&& target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else if(nums[mid]<=nums[high]){
                if(target>=nums[mid] && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};