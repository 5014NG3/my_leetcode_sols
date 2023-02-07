/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:


    //create a map to track visited nodes
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {

        if(node == nullptr){
            return nullptr;
        }

        //check if node has been visited
        if(mp.find(node) == mp.end()){

            //if it hasn't been visited create a new node
            mp[node] = new Node(node->val, {});

            //check the adjacency list of the current node

            for(auto adj: node->neighbors){

                //push the copies of the adjacent nodes to this list
                mp[node]->neighbors.push_back(cloneGraph(adj));
            }


        }
        
        return mp[node];
    }
};