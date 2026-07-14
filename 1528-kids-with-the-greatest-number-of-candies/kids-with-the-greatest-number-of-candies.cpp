class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_el=0;
        for(int i=0;i<candies.size();i++){
            max_el=max(max_el,candies[i]);
        }
        vector<bool>ans;
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=max_el){
                ans.push_back(true);
                continue;
            }
            ans.push_back(false);
        }
        return ans;
    }
};