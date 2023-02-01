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
    int maxSum;
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        gainFromSubtree(root);

        return maxSum;
    }

    //post order traversal
    int gainFromSubtree(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        //add path sum from left and right subtree
        //if path sum is negative we can ignore it or count it as 0



        int gainFromLeft = max(gainFromSubtree(root->left), 0);
        int gainFromRight = max(gainFromSubtree(root->right), 0);

        //if left or right sum negative they are reduced to 0
        maxSum = max(maxSum, gainFromLeft + gainFromRight + root->val );
        //return max sum for a path starting at root of subtree
        return max(gainFromLeft + root->val, gainFromRight + root->val);
    }
};

/*
Notes ~~~~~~~~~~~~~~~~~~~
binary tree max path sum

*given root: find max path sum of this tree

path - continous seq of nodes connected to eachother

in a path - except start and end nodes, 
every node is connected to two other nodes in the sequence. 

these two nodes could either be the node's children
, or one is parent and other is child

in other words no node can have more than two connections in this 
sequence

every node itself can be considered a path 

must traverse entire tree to find max path sum. 
interested in set of nodes that form a continous sequence

prefer dfs over bfs, because dfs examines each path before moving on

4 possibilities:

1. path starts at root and goes down through the root's left child.(don't know how long this will be)
2. path starts at root and goes down through the root's right child
3. path involves left and right child
4. path doesn't involve any child, root is path for max sum

at start: assume path sum contains root
to find max path sum: determine if there is a 
viable path leading down through the left or right subtree
makes sense to consider path sum by a subtree only if it is positive
if not we can safely ignore it, 

path goes down left or right subtree only if we see a gain in the path sum

we must first determine gain in the path sum contributed by the left and right subtree

once we have both we can decide whetehr to include their contribution. 

need process children before we process node

indicates perform post-order traversal(children processed before the parent)

post order- recursive: fuction takes root of subtree as input. 
return path sum gain contributed by subtree. 
calculate path sum gain, function calls itself recursivelyt on left and right child

possible for max path sum to not pass through root:


function:

1.
returns path sum gain contributed by the subtree

path sum gain contributed by subtree can be derived from path
taht includes at most one child of the root. 
only include one child otherwise a fork will be created at root
root is already connected to its parent
if we include both children as well with 3 connections, wouldn't be a valid path anymore. 
can say taht path would consist of at most one child of the root

fucntion compares left gain and right gain and adds the max of the two to the value of the root
sum gain from subtree is returned to the caller

use max(gain_from_left_subtree,0) want to consider only positive net gain

2.
function keeps track of max path

assume max path sum pass through root of subtree, consider the 4 possibilites earlier

max_path_sum = max(max_path_sum, left_gain + right_gain + root.val)


algorithm main function body

1. init global variable max sum = -inf
2. call func gain_from_subtree
3. return value of max_sum

body of recur func gain_from_subtree. accepts root of subtree as input

1. if root null return 0, no left or right sub tree, then each contributes 0
2. call func recur on left and right child of the root, store result in gain from left
and gain from right
3. if either negative set to 0, don't want to include negative path sum
4. update max path sum seen sofr. compare max sum with sum of the following, update if smaller
	value of root itself
	gain from left 0 if neg
	gain from right 0 if neg

5. return path sum gain contributed by the subtree. this is the max of the following two values.
	value of root + gain from right, value of rot + gain from left


*/