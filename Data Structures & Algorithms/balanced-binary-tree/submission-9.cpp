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
//     bool balanced = true;
// public:
//     bool isBalanced(TreeNode* root) {
//         height(root);
//         return balanced;
//     }
// private:
//     int height(TreeNode* root){
//         if(!root){
//             return 0;
//         }
//         int left = height(root->left);
//         int right = height(root->right);
//         if(abs(left - right) > 1){
//             balanced = false;
//             return 0;
//         }
//         return 1 + max(left, right);
//     }
// };

// ITERATIVE
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        stack<pair<TreeNode*, bool>> stack;
        unordered_map<TreeNode*, int> height;

        stack.push({root, false});
        while(!stack.empty()){
            auto[node, visited] = stack.top();
            stack.pop();

            if(!node)continue;

            if(!visited){
                stack.push({node, true});
                stack.push({node->right, false});
                stack.push({node->left, false});
            }else{
                int right = node->right ? height[node->right] : 0;
                int left = node->left ? height[node->left] : 0;
                if(abs(left - right) > 1){
                    return false;
                }
                height[node] = 1 + max(left, right);
            }
        }
        return true;

    }
};