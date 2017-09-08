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
vector<vector<int>> ret;
vector<int> valid_path;
    void helper(TreeNode* root,int sum){
        if (root==NULL){
            return;
        }
        if (!root->left and !root->right){
            if (root->val == sum){
                valid_path.push_back(root->val);
                vector<int> ret_path = valid_path;
                ret.push_back(ret_path);
                valid_path.pop_back();
                return;
            }
            else{
                return;
            }
        }
        valid_path.push_back(root->val);
        helper(root->left,sum-root->val);
        helper(root->right,sum-root->val);
        valid_path.pop_back();
    }
    public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        helper(root,sum);
        return ret;
    }
};
