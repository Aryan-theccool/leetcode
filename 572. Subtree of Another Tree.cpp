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
//         if(root == NULL || subRoot==NULL){
//             return true;
//         }
//         if(root->val==subRoot->val && root->left==subRoot->left && root->right==subRoot->right){
// if (root && root->left && root->left->left || root && root->right && root->right->right){
//     return false;
// }
// return true;
//         }
//         return isSubtree(root->left,subRoot);
//         return isSubtree(root->right,subRoot);

//         return false;

        
        // base cases
        // if (!subRoot) return true;
        // if (!root) return false;

        // if (root->val == subRoot->val) {

        //     if (isSubtree(root->left, subRoot->left) &&
        //         isSubtree(root->right, subRoot->right)) {
        //         return true;
        //     }
        // }

        // return isSubtree(root->left, subRoot) ||
        //        isSubtree(root->right, subRoot);

           bool isSame(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;

        if (a->val != b->val) return false;

        return isSame(a->left, b->left) &&
               isSame(a->right, b->right);
    }

    // 🔹 main function
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        // check at current node
        if (isSame(root, subRoot)) return true;

        // otherwise search left and right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
    
};
    