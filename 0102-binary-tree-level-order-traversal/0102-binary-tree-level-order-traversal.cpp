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
   void solve(TreeNode* node, vector<vector<int>> &ans){
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                if(it->left){
                  q.push(it->left);
                }
                if(it->right){
                   q.push(it->right);
                }
                temp.push_back(it->val);
            }
            ans.push_back(temp);
        }
   }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        solve(root,ans);
        return ans;
    }
};