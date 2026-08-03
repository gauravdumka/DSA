class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // int result=0;
        // for(int i=0; i<nums.size();i++){
        //     long long mul=1;
        //     for(int j=i;j<nums.size();j++){
        //         mul*=nums[j];
        //         if(mul<k){
        //             result++;
        //         }else{
        //             break;
        //         }
        //     }
        // }
        // return result;

        int i=0; int j=0; int product=1; int cnt=0;
        if(k <= 1) return 0;
        while(j<nums.size()){
            product*=nums[j];
            while(product>=k){
                product/=nums[i];
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};