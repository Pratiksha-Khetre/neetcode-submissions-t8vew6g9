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

    int cnt = 0;
    int ans = -1;

    void cntnode(TreeNode* root, int k){

        if(root == NULL) return;

        cntnode(root -> left, k);
        cnt++;
        if(k == cnt){
            ans = root -> val;
            return;
        }
        cntnode(root -> right, k);
    }


    int kthSmallest(TreeNode* root, int k) {
        
        cntnode(root, k);
        return ans;

    }
};
