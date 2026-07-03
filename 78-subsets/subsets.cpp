class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subsets = (1<<n);
        vector<vector<int>>ans;
        //for loop will run till total subsets(here subsets-1)
        // for(int i=0;i<(subsets);i++){
        //     vector<int>temp;
        //     int j=0;
        //     int k=i;
        //     while(k!=0){
        //         if((k&1)==1){
        //             temp.push_back(nums[j]);
        //         }
        //         j++;
        //         k=(k>>1);
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;
        //   STRIVERS APPROACH
        for(int num=0; num<=(subsets-1);num++){
            vector<int>list;
            for(int i=0; i<n; i++){
                if((num&(1<<i))){   // here we are moving forward so we will not get 1 with &. if we bring the number backward then we will get 1
                    list.push_back(nums[i]);
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};