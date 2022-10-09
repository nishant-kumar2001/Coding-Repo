// Problem Link - : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Method 1:
// Here, we're using vector to store all node by Inorder traversal to get a sorted array and then using two pointer method to check target sum

void helper(TreeNode* root,vector<int> &v){
    if(root==nullptr)   return;
    
    helper(root->left,v);
    v.push_back(root->val);
    helper(root->right,v);
}

bool findTarget(TreeNode* root, int k) {
    if(root==nullptr)   return 0;
    
    vector<int> v;
    helper(root,v);
    
    int i=0,j=v.size()-1;
    bool ans = 0;
    while(i<j){
        if(v[i]+v[j]>k) j--;
        else if(v[i]+v[j]<k)    i++;
        else{
            ans=1;  break;
        }
    }
    return ans;
}

// Method 2 :
// Here , we're using stack instead of storing all nodes in a vector for space optimization i.e. O(logn)

int nodes(TreeNode *root){
    if(root==NULL)
        return 1;

     return nodes(root->left)+nodes(root->right);
}

bool findTarget(TreeNode* root, int k) {
    
   int count = nodes(root);
   stack<TreeNode*> s1,s2;

    TreeNode *temp = root;
    while(temp!=NULL){
        s1.push(temp);
        temp = temp->left;
    }
    temp = root;
    while(temp!=NULL){
        s2.push(temp);
        temp = temp->right;
    }
    while(count>1){
        if(s1.top()->val+s2.top()->val>k){
            temp = s2.top()->left;
            s2.pop();	count--;
            while(temp!=NULL){
                s2.push(temp);
                temp = temp->right;
            }
        }
        else if(s1.top()->val+s2.top()->val<k){
             temp = s1.top()->right;
            s1.pop();	count--;
            while(temp!=NULL){
                s1.push(temp);
                temp = temp->left;
            }
        }
        else
            return 1;
    }
    return 0;
}
