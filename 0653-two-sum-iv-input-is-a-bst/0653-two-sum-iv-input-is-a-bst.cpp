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

 class BSTIterator {
    stack<TreeNode*> st;
    bool reverse=true;
private:
    void pushAll(TreeNode* node){
        if(node==NULL) return;

        while(node){
           st.push(node);
           if(reverse) node=node->right;
           else  node=node->left;
        }
    }    
public:
    BSTIterator(TreeNode* root,bool isrev) {
        reverse=isrev;
        pushAll(root);
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
        if(!reverse)
           pushAll(node->right);
        else 
           pushAll(node->left); 
        return node->val;
    }
    
    bool hasNext() {
        if(st.empty()) return false;
        return true;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return true;
         
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i=l.next();
        int j=r.next();

        while(i<j){
            if(i+j==k) return true;
            if(i+j < k) i=l.next();
            else j=r.next();
        } 
        return false;

    }
};