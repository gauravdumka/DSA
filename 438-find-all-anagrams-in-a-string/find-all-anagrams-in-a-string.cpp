class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // sort(p.begin(),p.end()); vector<int>result;
        // int n=s.length();
        // int m=p.length();
        // for(int i=0; i<=n-m;i++){
        //     string substring=s.substr(i,m);
        //     sort(substring.begin(),substring.end());
        //     if(substring==p){
        //         result.push_back(i);
        //     }

        // }
        // return result;

          //// above approach was TLE now the optimal one

        vector<int>hash1(26,0);
        int n=s.length();
        int m=p.length();
        for(int i=0;i<p.length();i++){
            hash1[p[i]-'a']++;
        }
        vector<int>result;
        int cnt;
        for(int j=0;j<=n-m;j++){
            vector<int>hash2(26,0);
            cnt=0;
            for(int k=j;k<j+m;k++){
                hash2[s[k]-'a']++;
            }
            for(int i=0;i<26;i++){
                if(hash1[i]==hash2[i]){
                    cnt++;
                }
                
            }
            if(cnt==26){
                result.push_back(j);
            }
        }
        return result;
    }
};