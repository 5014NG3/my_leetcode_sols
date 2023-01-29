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
    bool isSameTree(TreeNode* p, TreeNode* q) {


        //if both are null then we reached the same point
        if(p == nullptr && q == nullptr){
            return true;
        }
        
        //if one is null and other isn't then false
        if(!p && q || p && !q ){
            return false;
        }

        //neq
        if(p->val != q->val){

            return false;
        }

        //recur left and right for both

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};