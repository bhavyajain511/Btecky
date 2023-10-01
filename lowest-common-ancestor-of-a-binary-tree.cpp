// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// 236. Lowest Common Ancestor of a Binary Tree
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both 
// p and q as descendants (where we allow a node to be a descendant of itself).”

// Constraints:

// The number of nodes in the tree is in the range [2, 105].
// -109 <= Node.val <= 109
// All Node.val are unique.
// p != q
// p and q will exist in the tree.

// Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int n1=p->val;
        int n2=q->val;

        if(root==NULL){
            return NULL;
        }
        if(root->val==n1 || root->val==n2){
            return root;
        }
        TreeNode* leftans=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans=lowestCommonAncestor(root->right,p,q);

        if(leftans&& rightans){
            return root;
        }
        if(leftans&& !rightans){
            return leftans;
        }
        if(!leftans&& rightans){
            return rightans;
        }
        else{
            return NULL;
        }
    }
};
