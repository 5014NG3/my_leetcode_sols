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



//////////////////////////////`````````````~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//optimal solution

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
// #include<bits/stdc++.h>



// class compare{
//     public:
//       bool operator()(ListNode* a,ListNode* b)
//       {
//          return a->val > b->val;
//       }
// };

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode*,vector<ListNode*>,compare> pq;
//         if(lists.size()==0) return nullptr;
//         for(int i=0;i<lists.size();i++)
//         {

               //pushing the first node in the list to priority queue based
               //by comparing the values between the head of the different lists
               //only added to the priority queue if it is not null
//             if(lists[i]) pq.push(lists[i]);
//         }
//         ListNode* head=nullptr;
//         ListNode* tail=nullptr;

//         while(!pq.empty())
//         {
//             ListNode* temp=pq.top();
//             pq.pop();
                // get the first value from the priority quueu, temp
                // get the rest of the values from this list
                //and push into the priority queue, order is preserved

//             if(temp->next) pq.push(temp->next);

                //this is the starting point, before head was equal to nullptr
//             if(head==nullptr) {

                   //head is now the current smallest value
//                 head=temp;

                    //tail is equal to head from here on out
//                 tail=head;
                
//             }

                //head != nullptr
//             else{

                //before this head == tail;
                //"append" values to the list

//              tail->next=temp;

                //tail is now the current value
//              tail=temp;

                //the head isn't really important
                //we are just adding values to the tail
                //until the pq is empty
             
//             }
//         }
        
//        return head;
//     }
// };