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

 // RECURSIVE
// class Solution {
//     vector<int> values;
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         inorder(root);
//         return values;
//     }

// private:
//     void inorder(TreeNode* root){
//         if(!root){
//             return;
//         }
//         inorder(root->left);
//         values.push_back(root->val);
//         inorder(root->right);
//     }
// };

// ITERATIVE
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while(curr || !stk.empty()){
            while(curr){
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            stk.pop();
            values.push_back(curr->val);
            curr = curr->right;
        }

        return values;
    }


    
};