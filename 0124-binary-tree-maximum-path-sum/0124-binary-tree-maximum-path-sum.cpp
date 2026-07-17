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
    int maxtotal = INT_MIN; 
    int maxnumber(TreeNode* root) {
        if(root == nullptr) {
            return 0; 
        }
        
        int leftm = max(0, maxnumber(root->left));
        int rightm = max(0, maxnumber(root->right));
     
        int current_path_sum = root->val + leftm + rightm;
        maxtotal = max(maxtotal, current_path_sum);
        
        return root->val + max(leftm, rightm);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxnumber(root);
        return maxtotal;
    }
};