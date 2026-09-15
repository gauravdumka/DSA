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
    int psum(TreeNode* root, int &maxi){
        if(root==nullptr)return 0;
        int ls=max(0,psum(root->left, maxi));
        int rs=max(0,psum(root->right , maxi));
        int sum=ls+rs+root->val;
        maxi=max(maxi,sum);
        return max(ls,rs)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        psum(root,maxi);
        return maxi;
    }
};