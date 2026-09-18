/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr) return ans;
        queue<pair<TreeNode*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int x=p.second;
            if(mpp.find(x)==mpp.end())mpp[x]=p.first->val;
            if(p.first->right)q.push({p.first->right,x+1});
            if(p.first->left)q.push({p.first->left,x+1});
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};