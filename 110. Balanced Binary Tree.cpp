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
int  balan(TreeNode* root){
      if(root==NULL){
            return 0;
        }
        return 1+max(balan(root->left),balan(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
           return true; 
        }
        int left=balan(root->left);
        int right=balan(root->right);
        if(abs(left-right)>1){
    return false;
}
return isBalanced(root->left)&&isBalanced(root->right);
    }
};