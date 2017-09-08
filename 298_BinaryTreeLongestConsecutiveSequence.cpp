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
    int maxLen = 0;
    int helper(TreeNode* root){
        if (root==NULL){
            return 0;
        }
        else{
            int left = helper(root->left);
            int right = helper(root->right);
            int maxCur = 1 + max((left&&root->val+1==root->left->val)?left:0,(right&&root->val+1==root->right->val)?right:0);
            maxLen = max(maxLen,maxCur);
            return maxCur;
        }
    }
public:
    int longestConsecutive(TreeNode* root) {
        helper(root);
        return maxLen;
    }
};
