class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int>mpp; int prefix=0; int cnt=0;mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            int el = (prefix % k + k) % k;
            if(mpp.find(el)!=mpp.end()){
                cnt+=mpp[el];
            }
            mpp[el]++;
        }
        return cnt;
    }
};