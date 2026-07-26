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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head; int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        int k1=k; ListNode*node1=head;
        while(k1>1){
            node1=node1->next;
            k1--;
        }
        int k2=len-k+1; ListNode* node2=head;
        while(k2>1){
            node2=node2->next;
            k2--;
        }
        swap(node1->val,node2->val);
        return head;
    }
};