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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode*i=head;
        ListNode*j=head->next;
        head=head->next;
        ListNode*prev=nullptr;
        ListNode* js=nullptr;
        while(j!=nullptr && i!=nullptr){
            js=j->next;
            j->next=i;
            i->next=js;
            if(prev!=nullptr){
                prev->next=j;
            }
            prev=i;
            i=js;
            if(js!=nullptr){
                j=i->next;
            }
        }
        return head;
    }
};