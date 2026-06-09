class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int cnt;
        for(int i =0; i<nums.size();i++){
            if(cnt==0){
                el = nums[i];
                cnt++;
            }
            else if(nums[i]==el){
                cnt++;
            }
            //condition where nums[i]!=el
            else{
                cnt--;
            }
        }
        //finding total occurence of element in the array
        int count2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el){
                count2++;
            }
        }
        if(count2>(nums.size()/2)){
            return el;
        }
        return -1;

    }
};