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
    TreeNode* solve(vector<int>& preorder,int ps,int pe){
        if(ps>pe) return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        // if(ps==pe) return root;
        for(int i=ps+1;i<=pe;i++){
            if(preorder[i]>preorder[ps]){
                root->left=solve(preorder,ps+1,i-1);
                root->right=solve(preorder,i,pe);
                return root;
            }
        }
            root->left=solve(preorder,ps+1,pe);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder){
         int n=preorder.size();
         return solve(preorder,0,n-1);   
    }


    // TreeNode* solve(vector<int>& preorder,int maxi,int &ps){
    //     int n=preorder.size();
    //     if(ps==n || preorder[ps]>maxi) return NULL;
    //     TreeNode* root=new TreeNode(preorder[ps++]);
    //      root->left=solve(preorder,root->val,ps);
    //      root->left=solve(preorder,maxi,ps);

    //      return root;
    // }
    // TreeNode* bstFromPreorder(vector<int>& preorder){
    //     int ps=0;
    //     return solve(preorder,INT_MAX,ps);
    // }
};