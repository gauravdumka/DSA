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
    ListNode* oddEvenList(ListNode* head) {
        //brutte force = take all odd in a list in 2 iteration and take all even in 2 iteration and fill the ll with the list elements in 3 iteration whoch takes a timw complexity of O(N) due to the list
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode*odd=head;
        ListNode*even=head->next;
        ListNode*evenhead=head->next;
        while(even!=nullptr && even->next!=nullptr){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};

// tc=O((n/2*2)