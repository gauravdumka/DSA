class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mpp; int len=0; int cnt=0;
        mpp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                cnt--;
            }else{
                cnt++;
            }
            if(mpp.find(cnt)!=mpp.end()){
                if(i-mpp[cnt]>len){
                    len=i-mpp[cnt];

                }
            }else{
                mpp[cnt]=i;
            }
        }
        return len;
    }
};