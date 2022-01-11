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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> stk;
        TreeNode* cur;
        map<TreeNode*, TreeNode*> parent;
        
        stk.push(root);
        parent[root] = nullptr;
        
        while(!stk.empty()){
            cur = stk.top(); stk.pop();
            if(!cur->left && !cur->right){
                int path_val = 0, h = 0 ;
                while(cur != nullptr){
                    path_val += (cur->val << h);
                    h++;
                    cur = parent[cur];
                }
                sum += path_val;
                continue;
            }
            if(cur->right){
                stk.push(cur->right);
                parent[cur->right] = cur;
            }
            if(cur->left){
                stk.push(cur->left);
                parent[cur->left] = cur;
            }
        }
        
        return sum;
    }
};