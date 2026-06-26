class Solution {
public:
    bool check(vector<int>arr, int divisor,int threshold){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil(arr[i]/(double)divisor);
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int low=1; int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(nums,mid,threshold)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return low;
    }
};