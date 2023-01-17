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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //use two pointers method 
        ListNode* fast = head;
        ListNode* slow = head;

        for (int i = 0; i < n ; i++){
            fast = fast->next;
        }

        //this mean we just have to delete the head
        //and keep the next value
        if(fast == nullptr){
            return head->next;
        }

        //fast is iterating until the last node is reached
        //because we are removing the nth node from the end of a list
        while(fast->next){

            fast = fast->next;
            slow = slow->next;
            
        }
        //since fast->next is no-null, we know slow->next is non-null
        //this is where the nth node from the end is removed

        slow->next = slow->next->next;
        return head;

    }






};