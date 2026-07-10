class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0; int j=height.size()-1;int max_capacity=0;
        while(i<j){
            int capacity=(j-i)*min(height[i],height[j]);
            max_capacity=max(max_capacity,capacity);
            if(height[i]<=height[j]){
                i++;
            }else{
                j--;
            }
        }
        return max_capacity;
    }
};