// class Solution {
// public:
//     int nextvalididx(idx, curdir , nums, n){
//         int nxtidx=(idx+nums[idx])%n;
        
//         bool nxtdir=nums[nxtidx]>0?true:false;
//         if(idx==nxtidx ||(currdir!=nxtdir)){
//             return -1;
//         }
//         return nxtidx;
//     }
//     bool circularArrayLoop(vector<int>& nums) {
//         int n= nums.size();
//         for(int i=0;i<n;i++){
//             int slow=i, fast=i;
//             bool curdir=nums[nxtidx]>0?true:false;

//             while(true){
//                 slow=nextvalididx(slow, curdir, nums, n);
//                 fast=nextvalididx(fast, curdir, nums, n);
//             }
//         }

//     }
// };

class Solution {
public:

    int nextvalididx(int idx, bool curdir, vector<int>& nums, int n) {

        int nxtidx = ((idx + nums[idx]) % n + n) % n;

        bool nxtdir = nums[nxtidx] > 0;

        // self-loop OR direction changed
        if (idx == nxtidx || curdir != nxtdir) {
            return -1;
        }

        return nxtidx;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int slow = i;
            int fast = i;

            // Direction of the starting element
            bool curdir = nums[i] > 0;

            while (true) {

                // slow moves 1 step
                slow = nextvalididx(slow, curdir, nums, n);

                if (slow == -1)
                    break;

                // fast moves 1st step
                fast = nextvalididx(fast, curdir, nums, n);

                if (fast == -1)
                    break;

                // fast moves 2nd step
                fast = nextvalididx(fast, curdir, nums, n);

                if (fast == -1)
                    break;

                // cycle found
                if (slow == fast)
                    return true;
            }
        }

        return false;
    }
};