class Solution {
public:
    bool check(vector<int>&hash1, vector<int>&hash2){
        bool flag=true;
        for(int i=0; i<256;i++){
            if(hash1[i]>0 &&(hash2[i]<hash1[i])){
                flag=false;
            }
        }
            return flag;
    }
    string minWindow(string s, string t) {
        // int low = 0;
        // int high = 0;

        // vector<int> hash(256, 0);
        // vector<int> hash1(256, 0);

        // int n = s.length();
        // int idx = -1;
        // int len = INT_MAX;

        // for(int i = 0; i < t.length(); i++) {
        //     hash1[t[i]]++;
        // }

        // int count = 0;

        // while(high < n) {

        //     hash[s[high]]++;

        //     if(hash1[s[high]] > 0 &&
        //        hash[s[high]] <= hash1[s[high]]) {
        //         count++;
        //     }

        //     while(count == t.length()) {

        //         if(high - low + 1 < len) {
        //             len = high - low + 1;
        //             idx = low;
        //         }

        //         if(hash1[s[low]] > 0 &&
        //            hash[s[low]] <= hash1[s[low]]) {
        //             count--;
        //         }

        //         hash[s[low]]--;
        //         low++;
        //     }

        //     high++;
        // }

        // if(idx == -1)
        //     return "";

        // return s.substr(idx, len);






        

        int low=0; int high=0; vector<int>hash1(256,0);
        for(int i=0;i<t.length();i++){
            hash1[t[i]]++;
        } 
        int idx=-1; vector<int>hash2(256,0); int len=INT_MAX;
        while(high<s.length()){
            hash2[s[high]]++;
            while(check(hash1,hash2)){
                if(high-low+1 < len) {
                len = high-low+1;
                idx = low;
            }
                hash2[s[low]]--;
                low++;
            }
            high++;
        }
        return(idx==-1?"":s.substr(idx,len));
    }
};