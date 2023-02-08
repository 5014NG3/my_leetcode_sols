/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {

        //edge case ensure the head is not null
        //also we are able to look 2 or 3 pointers ahead
        //from the starting position

        if(!head || !head->next || !head->next->next){
            return;
        }

        stack<ListNode*> st;
        ListNode* ptr = head;

        int size = 0;

        while(ptr){
            st.push(ptr);
            size++;
            ptr = ptr->next;
        }


        ListNode* res = head;

        //only have to check half of the pointers
        //in the stack because we are inserting 
        //between every two nodes

        for(int i = 0; i < size/2; i++){
            //between every two nodes
            //insert the one in the top 
            //of the stack
            ListNode* el = st.top();
            st.pop();
            //the top pointer is pointing to bottom->next

            //4-> 2
            el->next = res->next;

            //bottom->next is now pointing to el
            //1->4->2
            res->next = el;

            //to ensure we are inserting between
            //every two nodes
            //1->4->2 , res = 2
            res = res->next->next;


        }

        //point the end to nullptr
        res->next = nullptr;



        
    }
};