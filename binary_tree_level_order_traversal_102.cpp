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
    vector<vector<int>> levelOrder(TreeNode* root) {


        vector<vector<int>> res;
        //level 1 is the first node
        int level = 1;
        //list holds all of the values on the same level
        vector<int> list;



        while(traverse(root,level,list)){
            //increment the current level after
            //traversing, makes it so you have 
            //to go further down the tree to get to
            //the desired layer
            level++;
            res.push_back(list);
            list.clear();
        }


        return res;
        
    }

    bool traverse(TreeNode* root, int level, vector<int>& list){
        if (root == nullptr){
            return false;
        }


        //once we get to the target level 1, push to the list and return
        if(level == 1){
            list.push_back(root->val);
            return true;
        }

        //go down the left tree get all values on the same level
        bool left = traverse(root->left, level-1,list);
        //go down the right tree get all values on the same level
        bool right = traverse(root->right, level-1,list);

        return  left || right;
        


    }
};