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
    long long totalsum = 0;
    long long ans = INT_MIN;
    long long sum(TreeNode* root){
        if(!root) return 0;
        totalsum = root->val + sum(root->left)+ sum(root->right);
        return totalsum;
    }
    long long func(int sum,TreeNode* root){
        if(!root) return 0;
        long long s = root->val + func(sum ,root->left) + func(sum ,root->right);
        ans = max(ans, (sum - s)*s);
        return s;
    }
public:
    int maxProduct(TreeNode* root) {
        long long x = sum(root);
        func(x, root);
        long long MOD = 1e9 + 7;
        return ans% MOD;
    }
};