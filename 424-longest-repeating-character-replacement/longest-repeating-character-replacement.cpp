class Solution {
public:
    int characterReplacement(string s, int k) {
        // int l=0; int r=0; vector<int>hash(26,0);int max_frequency_element=0;int max_len=0;
        // while(r<s.length()){
        //     hash[s[r]-'A']++;
        //     max_frequency_element=max(max_frequency_element,hash[s[r]-'A']);
        //     while((((r-l)+1)-max_frequency_element)>k){
        //         hash[s[l]-'A']--;
        //         l++; max_frequency_element=0;
        //             ////  REMOVE BELOW FOE LOOP TO GET SECOND OPTIMAL SOLUTION
        //         //// for(int i=0; i<26;i++){
        //         ////     max_frequency_element=max(hash[i],max_frequency_element);
        //         //// }
        //     }
        //     if((((r-l)+1)-max_frequency_element)<=k){
        //         int len=(r-l)+1;
        //         max_len=max(len,max_len);
        //     }
        //     r++;
        // }
        // return max_len;
        ////// TC=O((n+n)*26) , SC=O(26)
        ////// so remove the above for loop , now TC=O(n+n)


        //// now most optimized sol of TC=O(n)
       
       int i=0; int j=0;int maxlen=0; int max_freq_el=0;vector<int>hash(26,0);
       while(j<s.length()){
        hash[s[j]-'A']++;
        max_freq_el=max(max_freq_el,hash[s[j]-'A']);
        while((j-i+1)-max_freq_el>k){
            hash[s[i]-'A']--;
            max_freq_el=0;
            for(int l=0;l<26;l++){
                max_freq_el=max(max_freq_el,hash[l]);
            }
            i++;
        }
        if((j-i+1)-max_freq_el<=k){
            maxlen=max(maxlen,j-i+1);
        }
        j++;
       }
       return maxlen;
    }
};