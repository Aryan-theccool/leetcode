// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
// bool valid(TreeNode* root){
//  if(root==NULL){
//             return true;
//         }
//         if(root->left->val >root->val || root->right->val <root->val){
//             return false;
//         }else{
//             return true;
//         }
//         return valid(root->left);
//           return valid(root->right);
// }
//     bool isValidBST(TreeNode* root) {
//          if(root->left->val >root->val || root->right->val <root->val){
//             return false;
//         }
//      return  valid(root);
//     }
// };
class Solution {
public:
    TreeNode* prev = NULL;

    bool inorder(TreeNode* root) {
        if (!root) return true;

        // go left
        if (!inorder(root->left)) return false;

        // check current with previous
        if (prev && root->val <= prev->val) return false;

        prev = root;

        // go right
        return inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};