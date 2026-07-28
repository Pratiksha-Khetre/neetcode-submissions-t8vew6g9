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
        map<int, int> mp;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = Build(preorder, 0, n-1, inorder, 0, n-1, mp);

        return root;


    }

    TreeNode* Build(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, map<int, int> &mp){

        if(preend < prestart || inend < instart) return NULL;

        TreeNode* curr = new TreeNode(preorder[prestart]);

        int inroot = mp[curr -> val];
        int numleft = inroot - instart;

        curr -> left = Build(preorder, prestart+1, prestart+numleft, inorder, instart, inroot - 1, mp);
        curr -> right = Build(preorder, prestart+numleft+1, preend, inorder,inroot+1, inend, mp);

        return curr;

    }
};
