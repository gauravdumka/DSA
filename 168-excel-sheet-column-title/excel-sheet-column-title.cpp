class Solution {
public:
    string convertToTitle(int columnNumber) {
        string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans;

        int n = columnNumber;

        while(n > 0) {
            n--;

            int rem = n % 26;
            ans += letters[rem];

            n /= 26;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};