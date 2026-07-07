class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    
    int checkHeight(TreeNode* root) {
        if (root == NULL) return 0;
        
        int left = checkHeight(root->left);
        if (left == -1) return -1;
        
        int right = checkHeight(root->right);
        if (right == -1) return -1;
        
        if (abs(left - right) > 1) return -1;
        
        return max(left, right) + 1;
    }
};