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

    int count(TreeNode* root, int maxVal){

        if(!root) return 0;

        int cnt = 0;

        if(root -> val >= maxVal){
            cnt++;
        }

        maxVal = max(maxVal, root -> val); 

        cnt += count(root -> left, maxVal);
        cnt += count(root -> right, maxVal);

        return cnt;
    }

    int goodNodes(TreeNode* root) {
        
        int maxVal = INT_MIN;

        int ans = count(root, maxVal);

        return ans;
    }
};
