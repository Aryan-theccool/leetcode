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
// class Solution {
// public:
// TreeNode* fun(TreeNode* root1,TreeNode* invert){
//     if(root1==nullptr){
//         return invert ;
//     }
//     root1->val=invert->val;
//     fun(root1->left,invert->right);
//     fun(root1->right,invert->left);
//     return invert;
// }
//     TreeNode* invertTree(TreeNode* root) {
//        TreeNode* ulta;
//        return fun(root,ulta);
//     }
// };
class Solution {
public:

TreeNode* fun(TreeNode* root1){

    if(root1 == nullptr)
        return nullptr;

    TreeNode* invert = new TreeNode(root1->val);

    invert->left = fun(root1->right);
    invert->right = fun(root1->left);

    return invert;
}

TreeNode* invertTree(TreeNode* root) {

    return fun(root);

}

};
// class Solution {
// public:

// TreeNode* invertTree(TreeNode* root) {

//     if(root == nullptr)
//         return nullptr;

//     TreeNode* left = invertTree(root->left);
//     TreeNode* right = invertTree(root->right);

//     root->left = right;
//     root->right = left;

//     return root;
// }

// };