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
    void zigzag(TreeNode*root,vector<vector<int>> &ans,queue<TreeNode*>&q,int flag){
        if(root==nullptr){
            return ;
        }
        while(q.size()){
            vector<int>temp;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                temp.push_back(node->val);
            }
            if(flag==-1){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }else{
                ans.push_back(temp);
            }
            
            flag*=-1;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans; queue<TreeNode*>q;
        q.push(root);
        zigzag(root,ans,q,1);
        return ans;
    }
};