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
 */class Solution {
public:
    // // Step 1: find max depth
    // int getDepth(TreeNode* root) {
    //     if (root == NULL) return 0;
    //     return 1 + max(getDepth(root->left), getDepth(root->right));
    // }

    // // Step 2: find LCA of deepest nodes
    // TreeNode* findLCA(TreeNode* root, int depth) {
    //     if (root == NULL) return NULL;

    //     if (depth == 1) return root;

    //     TreeNode* left = findLCA(root->left, depth - 1);
    //     TreeNode* right = findLCA(root->right, depth - 1);

    //     if (left && right) return root;
    //     return left ? left : right;
    // }

    //     int depth = getDepth(root);
    //     return findLCA(root, depth);

    int finddepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(finddepth(root->left),finddepth(root->right));
    }
    TreeNode* findLCA(TreeNode* root , int depth){
if(root==NULL){
    return root;
}
if(depth==1){
    return root;
}
TreeNode* left=findLCA(root->left,depth-1);
TreeNode* right=findLCA(root->right,depth-1);

if(left && right)return root;
return left?left:right;
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
      int depth =  finddepth(root);
      return findLCA(root,depth);
    }
};