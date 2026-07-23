class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;int max_area=0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int element=heights[st.top()]; st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                int area=element*(nse-pse-1);
                max_area=max(area,max_area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int element=heights[st.top()];
            st.pop();
            int nse=heights.size();
            int pse=st.empty()?-1:st.top();
            int area=element*(nse-pse-1);
            max_area=max(max_area,area);
        }
        return max_area;
    }
};