class Solution {
private:
    bool isvalid(char c){
        if((c>='a'&& c<='z')|| c>='A'&& c<='Z'||c>='0' && c<='9'){
            return 1;
        }
        else{
            return 0;
        }
    }
    // to lowercase
    char lwcs(char ch){
        if(ch>='a' && ch<='z' || ch>='0' && ch<='9'){
            return ch;
        }
        else{
            return ch-'A'+'a';
        }
    }
public:
    bool isPalindrome(string s) {
        string temp="";
        int n=s.size();
        for(int k=0;k<n;k++){
            if(isvalid(s[k])){
                temp.push_back(s[k]);
            }
            
        }

        int i=0;
        int j=temp.size()-1;
        while(i<j){
            if(lwcs(temp[i])== lwcs(temp[j])){
                i++;
                j--;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
};