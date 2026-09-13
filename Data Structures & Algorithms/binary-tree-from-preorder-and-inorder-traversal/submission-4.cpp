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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()){
            return nullptr;
        }
        int node = preorder[0];
        TreeNode* root = new TreeNode(node);
        int limit = getIndex(inorder, node);

        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + limit);
        vector<int> left_inorder(inorder.begin(), inorder.begin() + limit);
        root->left = buildTree(left_preorder, left_inorder);

        vector<int> right_preorder(preorder.begin() + 1 + limit, preorder.end());
        vector<int> right_inorder(inorder.begin() + limit + 1, inorder.end());
        root->right = buildTree(right_preorder, right_inorder);

        return root;
    }

    int getIndex(vector<int>& inorder, int node){
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == node){
                return i;
            }
        }
        return -1;
    }
};
