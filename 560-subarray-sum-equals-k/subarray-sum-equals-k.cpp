class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int n =nums.size();
        // map<long long, int>premap; 
        // int total=0;
        // long long sum=0;
        // int remaining;
        // premap[0]=1;
        // for(int i=0;i<n;i++){
        //     sum=sum+nums[i];
        //     premap[remaining]=i;
        //     if(sum==k){
        //         total++;
        //     }
        //     remaining=sum-k;
        //     if(premap.find(remaining)!=premap.end()){
        //         total++;
        //     }
        //}
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int presum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            presum=presum+nums[i];
            int remove=presum-k;
            count+=mpp[remove];
            mpp[presum]+=1;
        } 
        // return total;
        return count;


    }
};