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
// bool check(TreeNode* root){
//      if(root==NULL){
//             return true;
//         }
//        bool left=check(root->left);
//          bool       right=check(root->right);


//         if(!left && right){
//             return false;
//         }
//         return true;
// }
//     bool isCompleteTree(TreeNode* root) {
       
//         return check(root);
//     }
// };
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool check(TreeNode* root, int index, int total) {
        if (!root) return true;

        if (index > total) return false;

        return check(root->left, 2 * index, total) &&
               check(root->right, 2 * index + 1, total);
    }

    bool isCompleteTree(TreeNode* root) {
        int total = countNodes(root);
        return check(root, 1, total);
    }
};