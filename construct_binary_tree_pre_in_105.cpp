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

map<int,int> inorderIndexMap;
int preorderIndex;


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        //inorder: left root right
        //preorder: root left right
        preorderIndex = 0;
        //store value index relation ship in order
        for(int i = 0; i < inorder.size(); i++){
            inorderIndexMap[inorder[i]] = i;
        }


        return arrayToTree(preorder, 0, preorder.size() -1);

    }


    TreeNode* arrayToTree(vector<int>& preorder, int left, int right){
        if(left > right){
            //no more elements to build tree
            return nullptr;
        }

        //select preorder index element as root and increment

        //we get the root when using the preorder
        int rootval = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootval);

        //build left and right subtree, exclude root since it already 
        //accounted for in the previous step
        root->left = arrayToTree(preorder,left,inorderIndexMap[rootval]-1);

        root->right = arrayToTree(preorder,inorderIndexMap[rootval] + 1,right);

        return root;

    }
};