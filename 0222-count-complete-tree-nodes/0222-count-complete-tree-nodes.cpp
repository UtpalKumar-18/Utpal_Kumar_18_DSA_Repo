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
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         int count =0;
//         if(root == nullptr) return count;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//             int size = q.size();
//             for(int i=0;i<size;i++){
//                 TreeNode* node = q.front();
//                 count++;
//                 q.pop();
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
//         }
//         return count;

//     }
// };

// class Solution {
// public:
//     int number_nodes(TreeNode* root,int &cnt)
// {
//         if(root == nullptr) return 0;
//         cnt++;
//         number_nodes(root->left,cnt);
//         number_nodes(root->right,cnt);
//         return cnt;
// } 
//    int countNodes(TreeNode* root) {
//         int cnt =0;
//         cnt = number_nodes(root,cnt);
//         return cnt;
        

//     }
// };

class Solution {
public:
   int countNodes(TreeNode* root) {
            if(root==nullptr) return 0;

            int lh = findheightleft(root);
            int rh = findheightright(root);

            if(lh == rh) return (1<<lh) -1;

            return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findheightleft(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root = root->left;

        }
        return height;
    }

     int findheightright(TreeNode* root){
        int height =0;
        while(root){
            height++;
            root = root->right;

        }
        return height;
    }

};