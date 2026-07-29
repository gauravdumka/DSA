class Solution {
public:
    int maxDepth(string s) {
        int depth=0, maxdepth=0; int ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                depth++;
                maxdepth=max(depth,maxdepth);
            }
            else if(s[i]==')'){
                depth--;
            }
            
            if(depth==maxdepth){
                ans=depth;
            }
            
        }
        return ans;
    }
};