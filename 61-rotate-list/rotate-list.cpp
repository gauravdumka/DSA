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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0)
            return head;

        int len = 1;
        ListNode* tail = head;

        while(tail->next){
            tail = tail->next;
            len++;
        }

        k = k % len;
        if(k==0)return head;
        // ListNode*temp=head;
        ListNode*fast=head;
        // k=k-1;
        while(k){
            k--;
            fast=fast->next;
        }
        ListNode* slow=head;
        while(fast!=nullptr&& fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* temp=slow->next;
        slow->next=nullptr;
        fast->next=head;
        return temp;
    }
};