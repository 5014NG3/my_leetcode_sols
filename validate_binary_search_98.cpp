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

    bool helper(TreeNode* root, TreeNode* min, TreeNode* max){

        if(root == nullptr){
            return true;
        }


        //if the current root val is less than the min val or
        //if the current root val is greater than the max val
        //return false

        if(min != nullptr && root->val <= min->val || max != nullptr && root->val >= max->val){
            return false;
        }

        //when looking at the left tree keep min , and use root as the max
        //when looking at the right tree keep max, and use root as the min val

        return helper(root->left, min, root) && helper(root->right,root,max);


    }



    bool isValidBST(TreeNode* root) {


        return helper(root,nullptr,nullptr);

    }



};