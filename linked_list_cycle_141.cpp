/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {

        if(head == nullptr){
            return false;
        }
    
        //tortoise, moves 1 step
        ListNode* slow = head;
        

        //hare, moves two steps 
        ListNode* fast = head->next; 

        //check if fast and fast->next pointer is valid
        while(fast && fast->next){
            
            

 
            slow = slow->next;
            fast = fast->next->next;

            //if slow and fast meet at the same node,
            //then there is a sequence

            if(slow == fast){
                return true;
            }
        }


        //means fast or fast->next is nullptr


        return false;

        
    }
};