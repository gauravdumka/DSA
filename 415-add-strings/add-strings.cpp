class Solution {
public:
    string addStrings(string num1, string num2) {
        int i=num1.length()-1;  int j=num2.length()-1;
        int carry=0; string num; int ans=0;
        while(i>=0 && j>=0){
            ans=(num1[i]-'0')+(num2[j]-'0')+carry;
            if(ans>9){
                carry=ans/10;
                ans%=10;
                num+=to_string(ans);
            }else{
                num+=to_string(ans);
                carry=0;
            }
            i--;
            j--;
        }
        while(i>=0){
            ans=(num1[i]-'0')+carry;
            if(ans>9){
                carry=ans/10;
                ans%=10;
                num+=to_string(ans);
            }else{
                num+=to_string(ans);
                carry=0;
            }
            i--;
        }
         while(j>=0){
            ans=(num2[j]-'0')+carry;
            if(ans>9){
                carry=ans/10;
                ans%=10;
                num+=to_string(ans);
            }else{
                num+=to_string(ans);
                carry=0;
            }
            j--;
        }
        if(carry!=0){
            num+=to_string(carry);
        }
        reverse(num.begin(),num.end());
        return num;
    }
};