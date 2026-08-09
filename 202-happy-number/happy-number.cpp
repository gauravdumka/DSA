// class Solution {
// public:
//     bool isHappy(int n) {
//         unordered_set<int>st;
//         while(n!=1){
//             if(st.find(n) != st.end()) {
//                 return false;   // n appeared before → cycle
//             }
//             st.insert(n);
//             int sum=0;
//             while(n){
//                 int rem=n%10;
//                 sum+=rem*rem;
//                 n=n/10;
//             }
//             n=sum;
//         }
//         return true;
//     }
// };


class Solution {
public:
    int nextNum(int n) {
        int sum = 0;

        while(n) {
            int rem = n % 10;
            sum += rem * rem;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        slow = nextNum(slow);
        fast = nextNum(nextNum(fast));

        while(slow != fast) {
            slow = nextNum(slow);
            fast = nextNum(nextNum(fast));
        }

        return slow == 1;
    }
};