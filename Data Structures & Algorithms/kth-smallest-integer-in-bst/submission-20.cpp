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
//RECURSIVE
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) { 
        vector<int> arr;
        inorder(root, arr);
        return arr[k-1];
    }
private:
    void inorder(TreeNode* root, vector<int>& arr){
        if(!root){
            return;
        }
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);

    }



};

//ITERATIVE
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         if(!root){
//             return 0;
//         }
        
//         TreeNode* curr = root;
//         stack<TreeNode*> stk;

//         while(curr || stk.empty()){
//             while(curr){
//                 stk.push(curr);
//                 curr = curr->left;
//             }

//             curr = stk.top();
//             stk.pop();
//             k--;
//             if(k == 0){
//                 return curr->val;
//             }
//             curr = curr->right;
//         }
        
//     }

// };
