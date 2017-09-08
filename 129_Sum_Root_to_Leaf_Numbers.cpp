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
    int ret = 0;
    void helper(TreeNode* root, string str_digit){
        if (root==NULL){
            return;
        }
        if (root->left==NULL && root->right==NULL){
            ret+=stoi(str_digit+to_string(root->val));
            return;
        }
        helper(root->left,str_digit+to_string(root->val));
        helper(root->right,str_digit+to_string(root->val));
        return;
    }
public:
    int sumNumbers(TreeNode* root) {
        helper(root,"");
        return ret;
    }
};
