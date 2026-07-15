class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp; stack<int>st;
        int n=nums1.size();
        vector<int>nge;
        int i=nums2.size()-1;
        while(i>=0){
            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mpp[nums2[i]]=-1;
            }else{
                mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
            i--;
        }
        for(int i=0;i<n;i++){
            nge.push_back(mpp[nums1[i]]);
        }
        return nge;
    }
};