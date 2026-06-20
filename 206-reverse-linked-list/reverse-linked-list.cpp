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
    ListNode* reverseList(ListNode* head) {
        // ListNode*prev=nullptr;
        // ListNode*store=nullptr;
        // while(head){
        //     store=head->next;
        //     head->next=prev;
        //     prev=head;
        //     head=store;
        // }
        // return prev;
        // using recurrsion

        ListNode* newhead=reverse(head);
        return newhead;
    }
    ListNode* reverse(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* newhead= reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newhead;
    }
};