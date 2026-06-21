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
    ListNode *detectCycle(ListNode *head) {
        // map<ListNode*, int>mpp;
        // int cnt =0 ;
        // ListNode *temp= head;
        // while(temp){
        //     if(mpp.find(temp->next)!=mpp.end()){
        //         return temp->next;
        //     }
        //     mpp[temp]=cnt;
        //     temp= temp->next;
        //     cnt++;
        // }
        // return nullptr;

        // optimal solution
        // 1-> move slow by 1 and fast by 2 from head until they collide
        // after collision take slow to head and move both of them by one
        // again they collide gives the answer
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return nullptr;


    }
};