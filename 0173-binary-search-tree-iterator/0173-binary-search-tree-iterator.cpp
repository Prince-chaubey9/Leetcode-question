/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
    void in_order(TreeNode* root, vector<int>& v) {
        if (root == NULL)
            return;
        in_order(root->left, v);
        v.push_back(root->val);
        in_order(root->right, v);
        return;
    }

public:
    vector<int> v;
    int i = 0;
    BSTIterator(TreeNode* root) { in_order(root, v); }

    int next() {
        int ans = v[i];
        i++;
        return ans;
    }

    bool hasNext() {
        if (i == v.size())
            return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */