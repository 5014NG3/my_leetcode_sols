//if l1 null, then return l2
//if l2 null,then return l1

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {


        //if the first list is null return the second one

        if(!list1){
            return list2;
        }

        //if the second list is null return the first one

        if(!list2){
            return list1;
        }


        if(list1->val > list2->val){

            //the second list's first value is smaller
            //than the first list's first value
            //move along the second list , recursively compare
            //against the first list
            list2->next = mergeTwoLists(list2->next,list1);

            return list2;


        }
        else{

            //the first list's first value is smaller
            //than the second list's first value
            //move along the first list , recursively compare
            //against the second list

            list1->next = mergeTwoLists(list1->next,list2);

            return list1;

        }


        


        //a = 1 2 4 
        //b = 1 3 4

        //
    }




};