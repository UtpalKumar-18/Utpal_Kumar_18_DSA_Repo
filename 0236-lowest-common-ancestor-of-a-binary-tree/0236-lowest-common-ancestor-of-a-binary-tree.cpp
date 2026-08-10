/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool findpath(TreeNode* root,TreeNode* &p,vector<TreeNode*> &path){
//             if(root == nullptr) return false;
//             path.push_back(root);
//             if(root == p) return true;

//             if(findpath(root->left,p,path) || findpath(root->right,p,path)) return true;

//             path.pop_back();
//             return false;
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> path1;
//         vector<TreeNode*> path2;
//         findpath(root,p,path1);
//         findpath(root,q,path2);
//         int i =0;
//         while(i<path1.size() && i<path2.size() && path1[i] == path2[i]) i++;
         
//         return path1[i-1];

//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left ==  nullptr) return right;
        else if(right == nullptr) return left;
        else return root;

            
        

    }
};
