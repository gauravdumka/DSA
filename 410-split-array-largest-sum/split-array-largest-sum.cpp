class Solution {
public:
    bool ispossible(int checkans, vector<int>nums,int k){
        int student=1; int pagesStudents=0;
        for(int i=0;i<nums.size();i++){
            if(pagesStudents+nums[i]>checkans){
                student++;
                pagesStudents=nums[i];
            }else{
                pagesStudents+=nums[i];
            }
        }
        if(student<=k){
            return true;
        }
        return false;

    }
    int splitArray(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        long long sum=0;
        int res;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        int low=maxi; int high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if (ispossible(mid,nums,k)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};