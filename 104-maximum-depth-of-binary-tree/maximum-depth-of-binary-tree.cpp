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
    // void traverse(TreeNode* root, int &cnt, int &ans){
    //     if(root==nullptr)return;
    //     ans=max(ans,cnt++);
    //     traverse(root->right, cnt,ans);
        
    //     traverse(root->left,cnt,ans);
    //     ans=max(ans,cnt--);

        
    // }
    // int maxDepth(TreeNode* root) {
    //     int cnt=0; int ans=0;
    //     traverse(root,cnt,ans);
    //     return ans;
    // }

    int maxDepth(TreeNode* root){
        if(root==nullptr)return 0;

        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};