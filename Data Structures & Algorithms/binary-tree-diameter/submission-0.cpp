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
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;

        calheight(root, height);

        return height;        
    }


    int calheight(TreeNode* root, int& height){
        if(!root) return 0;

        int left = calheight(root -> left, height);
        int right = calheight(root -> right, height);

        height = max(height, left + right);

        return 1 + max(left, right);

    }
};
