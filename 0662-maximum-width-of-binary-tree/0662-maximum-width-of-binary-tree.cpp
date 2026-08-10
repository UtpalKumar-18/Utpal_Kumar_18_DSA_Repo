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
    int widthOfBinaryTree(TreeNode* root) {
            if(root == nullptr) return 0;
            int width =0;
            queue<pair<TreeNode*,int>> q;
            q.push({root,0});
            while(!q.empty()){
                int size = q.size();
                int first =0,last =0;
                long long min_ind = q.front().second;
                for(int i=0;i<size;i++){
                auto p = q.front();
                q.pop();
                TreeNode* node = p.first;
                long long index = p.second - min_ind;
                if(i==0) first = index;
                if(i==size-1) last = index;
                if(node->left) q.push({node->left,2*index+1});
                if(node->right) q.push({node->right,2*index+2});
                }
                width = max(width,last-first+1);
            }
            return width;
    }
};