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
    ListNode* deleteDuplicates(ListNode* head) {
        // set<int>mpp;
        // ListNode* temp=head;
        // if(head==nullptr || head->next==nullptr)return head;
        // while(temp!=nullptr){
        //     mpp.insert(temp->val);
        //     temp=temp->next;
        // }
        // // Create new linked list
        // ListNode* newHead = nullptr;
        // ListNode* tail = nullptr;

        // for (int x : mpp) {
        //     ListNode* newNode = new ListNode(x);

        //     if (newHead == nullptr) {
        //         newHead = newNode;
        //         tail = newNode;
        //     } else {
        //         tail->next = newNode;
        //         tail = newNode;
        //     }
        // }

        // return newHead;
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* temp1=head; ListNode* temp2=head->next;
        while(temp2!=nullptr){
            if(temp1->val!=temp2->val){
                temp1->next=temp2;
                temp1=temp2;
            }
            if(temp2->next==nullptr)temp1->next=nullptr;
            temp2=temp2->next;
        }
        return head;
    }
};