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

// Method 1 : non - return type helper function

class Solution {
public:
    
    void helper(TreeNode *root, int val, int depth){
        
        TreeNode *newnode = new TreeNode(val);
        if(root==NULL)
            return;
        
        if(depth-1==1){
            TreeNode *curr = root->left;
            root->left = newnode;
            root->left->left = curr;
            
            curr = root->right;
            root->right = new TreeNode(val);
            root->right->right = curr;
        }
        else{
            helper(root->left,val,depth-1);
            helper(root->right,val,depth-1);
        }
        
        return;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        TreeNode *newnode = new TreeNode(val);
        if(depth==1){
            newnode->left = root;
            return newnode;
        }
        
        helper(root,val,depth);
        
        return root;
            
    }
  
  // Method 2 : return type helper function
  
  class Solution {
public:
    
    TreeNode *helper(TreeNode *root, int val, int depth){
        
        if(root==NULL)
            return root;
        
        if(depth-1==1){
            TreeNode *curr = NULL;
          
            curr = root->left;
            root->left = new TreeNode(val);
            root->left->left = curr;

            curr = root->right;
            root->right = new TreeNode(val);
            root->right->right = curr;
          
            return root;
        }
        
        root->left = helper(root->left,val,depth-1);
        root->right = helper(root->right,val,depth-1);
        
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        TreeNode *newnode = new TreeNode(val);
        if(depth==1){
            newnode->left = root;
            root = newnode;
        }
        else
            root = helper(root,val,depth);
        
        return root;
            
    }
    
  // Method 3 : using stack
    
    class Solution {
public:
    
    stack<TreeNode *> s;
    void helper(TreeNode *root, int depth){
        
        if(root==NULL)
            return;
        
        if(depth==1)
            s.push(root);
        
        helper(root->left, depth-1);
        helper(root->right,depth-1);

    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        TreeNode *newnode = new TreeNode(val);
        if(depth==1){
            newnode->left = root;
            return newnode;
        }
        
        helper(root,depth-1);
        
        while(!s.empty()){
            TreeNode *top = s.top(),*curr = NULL;
            
            curr = top->left;
            top->left = new TreeNode(val);
            top->left->left = curr;
            
            curr = top->right;
            top->right = new TreeNode(val);
            top->right->right = curr;
            
            s.pop();
        }
        
        return root;
            
    }
