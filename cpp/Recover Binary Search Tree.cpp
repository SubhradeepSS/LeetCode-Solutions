/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void find(TreeNode* root,int v,int v1){
        if(!root)
            return;
        find(root->left,v,v1);
        if(root->val==v)
            root->val=v1;
        else if(root->val==v1)
            root->val=v;
        find(root->right,v,v1);
    }
    void inorder(TreeNode* root,vector<int> &v){
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    void insertionsort(vector<int> &v,int n){
        int key;
        int j;
        for(int i=1;i<n;i++){
            key=v[i];
            j=i-1;
            while(j>=0&&v[j]>key)
            {
                v[j+1]=v[j];
                j--;
            }
            v[j+1]=key;
        }
    }
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        vector<int> v1=v;
        insertionsort(v,v.size());
        for(int i=0;i<v.size();i++){
            if(v[i]!=v1[i]){
                find(root,v[i],v1[i]);
                break;
            }
        }
    }
};