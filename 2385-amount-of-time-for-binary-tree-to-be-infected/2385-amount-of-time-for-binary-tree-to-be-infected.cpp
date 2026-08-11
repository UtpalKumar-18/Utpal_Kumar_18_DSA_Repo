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
    TreeNode* findparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp,int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->val == start) target = node;
                if(node->left){
                    q.push(node->left);
                    mp[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    mp[node->right] = node;
                }
             }
        
        }
        return target;
    }
    int calculate_time(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp){
        queue<TreeNode*> que;
        unordered_map<TreeNode*,int> visited;
        que.push(root);
        int time =0;
        visited[root] =1;
        while(!que.empty()){
            int f=0;
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left && !visited[node->left]){
                    f=1;
                    que.push(node->left);
                    visited[node->left] = 1;

                }
                 if(node->right && !visited[node->right]){
                    f=1;
                    que.push(node->right);
                    visited[node->right] = 1;

                }
                if(mp[node] && !visited[mp[node]]){
                    f =1;
                    que.push(mp[node]);
                    visited[mp[node]] = 1;
                }
            }
            if(f == 1) time++;
        }
        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        int time  =0;
        unordered_map<TreeNode*,TreeNode*> mp;
        TreeNode* target = findparent(root,mp,start);
        time = calculate_time(target,mp);
        return time;
    }
};