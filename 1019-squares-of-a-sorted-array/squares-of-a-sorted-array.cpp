class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int j=0; 
        int i=0;
        while(i < nums.size() && nums[i] < 0){
            i++;
        }
        j=i-1;
        vector<int>result;
        while((j>=0) && (i<nums.size())){
            if((nums[j]*nums[j])<(nums[i]*nums[i])){
                result.push_back(nums[j]*nums[j]);
                j--;
            }else{
                result.push_back(nums[i]*nums[i]);
                i++;
            }
        }
        while(j>=0){
            result.push_back(nums[j]*nums[j]);
            j--;
        }
        while(i!=nums.size()){
            result.push_back(nums[i]*nums[i]);
            i++;
        }
        return result;
    }
};