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
    int ans=0;
    int height(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        return height(root->left)+height(root->right)+1;
    }
    int traversal(TreeNode *root){
        if(root==NULL)return 0;
        int temp=traversal(root->left)+traversal(root->right)+root->val;
        int temp2=temp;
        
         int temp3=(height(root->left)+height(root->right))+1;
         if(temp3)temp/=temp3;
        if(temp==root->val){
            ans++;
        }
        return temp2;
    }
    int averageOfSubtree(TreeNode* root) {
        int temp=traversal(root);
        return ans;
    }
};