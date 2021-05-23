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
    vector<string> v;
    void util(TreeNode* node,string s){
        if(!node)
            return;
        if(node->left==NULL&&node->right==NULL){
            s+=to_string(node->val);
            v.push_back(s);
            s="";
        }
        else{
            s+=to_string(node->val);
            s+='-';
            s+='>';
            util(node->left,s);
            util(node->right,s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        util(root,s);
        return v;
    }
};