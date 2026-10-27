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
    int hight(TreeNode* root){
        if(root==NULL) return 0;
        return 1+ max(hight(root->right),hight(root->left));
    }
    void solve(TreeNode* root, int i,vector<int>&v){
        if(root==NULL) return ;
        v[i] = root->val;
        solve(root->left,i+1,v);
        solve(root->right,i+1,v);
        return ;
    }
    vector<int> rightSideView(TreeNode* root) {
        int n= hight(root);
        vector<int>v(n);
        solve(root,0,v);
        return v;
    }
};

// BFS apply kia 