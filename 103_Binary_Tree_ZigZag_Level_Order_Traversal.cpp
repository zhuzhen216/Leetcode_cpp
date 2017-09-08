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
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
        if (root==NULL){
            //
            // this is the way to return a empty vector
            // remember
            return vector< vector<int> >();
        }
        vector<vector<int>> ret;
        vector<TreeNode*> stack;
        stack.push_back(root);
        bool r_order = false;
        while (!stack.empty()){
            int cur_size = stack.size();
            vector<int> temp;
            for(int i=0; i< cur_size;i++){
                if (stack[0]->left){
                    stack.push_back(stack[0]->left);
                }
                if (stack[0]->right){
                    stack.push_back(stack[0]->right);
                }
                temp.push_back(stack[0]->val);
                stack.erase(stack.begin());
            }
            if (!r_order){
                ret.push_back(temp);
                r_order=true;
            }
            else{
                reverse(temp.begin(),temp.end());
                ret.push_back(temp);
                r_order=false;
            }
            
            
        }
        return ret;
    }
};
