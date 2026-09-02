class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0; int p_len=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
               if(len!=0){
                p_len=len;
               }
                len=0;
                continue;
            }
            len++;
        }
        return (len==0)&&(p_len!=0)?p_len:len;
    }
};