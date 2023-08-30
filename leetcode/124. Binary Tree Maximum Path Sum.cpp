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
private:
    int solve(TreeNode* root,int tmp,int &res){
        if(root == NULL) return 0;

        int l = solve(root-> left ,tmp ,res);
        int r = solve(root-> right, tmp,res);

        int ans= l+r+root->val;
        res = max(res,ans);

        tmp = max(max(l,r)+root->val,0); // how we got solve() hypothesis

        return tmp;
    }

public:
    int maxPathSum(TreeNode* root) {

        int res = INT_MIN;
        int tmp; // hypothesis ka answer
        solve(root, tmp, res);

        return res;
        
    }
};