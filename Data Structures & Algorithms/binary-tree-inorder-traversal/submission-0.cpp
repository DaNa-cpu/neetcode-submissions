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
    vector<int> values;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return values;
    }

private:
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        values.push_back(root->val);
        inorder(root->right);
    }
};