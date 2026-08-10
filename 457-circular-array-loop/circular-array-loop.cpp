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
    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        auto nextIndex = [&](int i) {
            return ((i + nums[i]) % n + n) % n;
        };

        for (int i = 0; i < n; i++) {

            bool direction = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {

                // Move slow one step
                int nextSlow = nextIndex(slow);

                // Direction changed
                if ((nums[nextSlow] > 0) != direction)
                    break;

                // One-element cycle
                if (nextSlow == slow)
                    break;

                slow = nextSlow;


                // Move fast one step
                int nextFast = nextIndex(fast);

                // Direction changed
                if ((nums[nextFast] > 0) != direction)
                    break;

                // One-element cycle
                if (nextFast == fast)
                    break;


                // Move fast second step
                int nextFast2 = nextIndex(nextFast);

                // Direction changed
                if ((nums[nextFast2] > 0) != direction)
                    break;

                // One-element cycle
                if (nextFast2 == nextFast)
                    break;

                fast = nextFast2;


                // Cycle found
                if (slow == fast)
                    return true;
            }
        }

        return false;
    }
};