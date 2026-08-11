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
//     void findparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track){
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){
//             int size = q.size();
//             for(int i=0;i<size;i++){
//                    TreeNode* node = q.front();
//                    q.pop();
//                    if(node->left){
//                         parent_track[node->left] = node;
//                         q.push(node->left);
//                    } 
//                  if(node->right){
//                         parent_track[node->right] = node;
//                         q.push(node->right);
//                    } 

//             }
//         }
//     }
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
//         unordered_map<TreeNode*,TreeNode*> parent_track;
//         findparent(root,parent_track);
//         unordered_map<TreeNode*,bool> visited;
//         queue<TreeNode*> que;
//         que.push(target);
//         visited[target] = true;
//         int current_dis = 0;
//         while(!que.empty()){
//                 if(current_dis++ == k) break;
//                 int size = que.size();
//                 for(int i=0;i<size;i++){
//                 TreeNode* node = que.front();
//                 que.pop();
//                 if(node->left && !visited[node->left]) 
//                 {
//                     que.push(node->left);
//                     visited[node->left] = true;
//                 }
//                 if(node->right && !visited[node->right]) 
//                 {
//                     que.push(node->right);
//                     visited[node->right] = true;
//                 }
//                 if(parent_track[node] && !visited[parent_track[node]]){
//                     que.push(parent_track[node]);
//                     visited[parent_track[node]] = true;
//                 }

//                 }
//         }
//         vector<int> ans;
//         while(!que.empty()){
//         TreeNode* node= que.front();
//         que.pop();
//         ans.push_back(node->val);
//         }

//         return ans;

//     }
// };

class Solution {
public:
    void findparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                   TreeNode* node = q.front();
                   q.pop();
                   if(node->left){
                        parent_track[node->left] = node;
                        q.push(node->left);
                   } 
                 if(node->right){
                        parent_track[node->right] = node;
                        q.push(node->right);
                   } 

            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        findparent(root,parent_track);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> que;
        que.push(target);
        visited[target] = true;
        int current_dis = 0;
        while(!que.empty()){
                if(current_dis++ == k) break;
                int size = que.size();
                for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left && !visited[node->left]) 
                {
                    que.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]) 
                {
                    que.push(node->right);
                    visited[node->right] = true;
                }
                if(parent_track[node] && !visited[parent_track[node]]){
                    que.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
                }

            
        }
        vector<int> ans;
        while(!que.empty()){
        TreeNode* node= que.front();
        que.pop();
        ans.push_back(node->val);
        }

        return ans;

    }
};