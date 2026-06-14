class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=0;
        long long mini= LLONG_MAX;
        for(int i=0;i<n;i++){

            int j=i+1;
            int k=n-1;
            while(j<k){
                long long sum=(nums[i]+nums[j]+nums[k]);
                long long diff=llabs(sum-target);
                if(diff<mini){
                    mini=diff;
                    ans=sum;
                }
                if(sum==target){
                    ans=sum;
                    break;
                }
                else if(sum>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
        
    }
};