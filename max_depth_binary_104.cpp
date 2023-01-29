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
    int maxDepth(TreeNode* root) {

        int max = -1;


        return helper(root,0, max);
        
    }



    int helper(TreeNode* root, int counter ,int& max){


        //if we read the end
        //check if the counter is greater than the max value

        if(root == nullptr){

            if(counter > max){
                max = counter;
            }


            return max;
        }

        


        //choose the max of the left or right subtree
        return std::max(helper(root->left,counter+1,max) , helper(root->right,counter+1,max) );






    }
};



//optimal 
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
            //base case
//         if(root == nullptr){
//             return 0;
//         }

            //recurse up and store the current max of the 
            //left and right subtree
//         return max(maxDepth(root->left) , maxDepth(root->right) ) + 1;

        
//     }




// };