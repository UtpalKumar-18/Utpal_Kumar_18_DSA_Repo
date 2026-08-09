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
    void getpath(TreeNode* root,vector<string> &path,string &eachpath){
            if(root == nullptr) return;

            if(root) eachpath += to_string(root->val);
            if(root->left == nullptr && root->right == nullptr){
                path.push_back(eachpath);

            } 
            else{
                eachpath += "->";
                getpath(root->left,path,eachpath);
                getpath(root->right,path,eachpath); 
                eachpath.erase(eachpath.size() - 2);
                
            }
            string val = to_string(root->val);
            eachpath.erase(eachpath.size() - val.size());


            
    }
    vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> path;
            string eachpath ="";
            if(root==nullptr) return path;
            getpath(root,path,eachpath);
            return path;
    }
};