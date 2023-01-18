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
    ListNode* mergeKLists(vector<ListNode*>& lists) {


        if(int(lists.size()) == 0){
            return nullptr;
        }

        if(int(lists.size()) == 1){
            return lists[0];
        }




        ListNode* answer = mergeTwoList(lists[0],lists[1]);


        //just iterate throught the values
        //and call the initial answer against 
        //the other lists

        for (int i = 2; i < lists.size(); i++){

            answer = mergeTwoList(answer,lists[i]);

        }


        return answer;
        
    }


    ListNode* mergeTwoList(ListNode* list1, ListNode* list2){

        if(!list1){
            return list2;
        }

        if(!list2){
            return list1;
        }


        if(list1->val > list2->val){
            //move along list2 to compare against
            //list1's values, since list2 is smaller
            list2->next = mergeTwoList(list1,list2->next);
            return list2;

        }
        else{
            //similar logic here
            list1->next = mergeTwoList(list1->next,list2);
            return list1;
            

        }

    }

};