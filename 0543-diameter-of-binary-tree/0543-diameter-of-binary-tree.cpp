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
private:
    int max_diameter = 0; 
    int getDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0; 
        }

        int left_depth = getDepth(root->left);
        int right_depth = getDepth(root->right);

        max_diameter = max(max_diameter, left_depth + right_depth);
        return max(left_depth, right_depth) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_diameter = 0; 
        getDepth(root); 
        return max_diameter; 
    }
};