// By Bernoulli on LeetCode

// DFS
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == nullptr)
            return 0;
        
        int sum = 0;
        if(root->val >= L && root->val <= R){
            sum+=root->val+rangeSumBST(root->left, L, R)+rangeSumBST(root->right, L, R);
        }else if(root->val < L){
            sum+=rangeSumBST(root->right, L, R);
        }else if(root->val > R){
            sum+=rangeSumBST(root->left, L, R);
        }
        
        return sum;
    }
};
//BFS
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(root == nullptr)
            return 0;
        
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        
        while(q.size()){
            node = q.front();q.pop();
            
            if(node == nullptr)
                continue;
            
            if(node->val >= L && node->val <= R){
                sum+=node->val;
                q.push(node->left);
                q.push(node->right);
            }else if(node->val < L){
                q.push(node->right);
            }else{
                q.push(node->left);
            }
        }
        
        return sum;
    }
};