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
// bool fun(TreeNode* root1,TreeNode*root2,bool ans){
//  if(root1==nullptr && root2==nullptr ){
//             ans= true;
//         }
//         if(root1==nullptr || root2==nullptr){
//             ans= false;
//         }
//         if(root1->val!=root2->val){
//             ans= false;
//         }
//         fun(root1->left,root2->left,ans);
//         fun(root1->right,root2->right,ans);
//         return ans ;
// }
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         bool ans;
//        return fun(p,q,ans);
//     }
// };
class Solution {
public:

bool fun(TreeNode* root1, TreeNode* root2){

    if(root1 == nullptr && root2 == nullptr)
        return true;

    if(root1 == nullptr || root2 == nullptr)
        return false;

    if(root1->val != root2->val)
        return false;

    return fun(root1->left, root2->left) && 
           fun(root1->right, root2->right);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    return fun(p,q);
}

};