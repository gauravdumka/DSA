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
    ListNode* middleNode(ListNode* head) {
        long long cnt=0;
        int check=0;
        ListNode*temp=head;
        ListNode*temp2=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        cnt=(cnt/2)+1;
        while(temp2!=nullptr){
            check++;
            if(check==cnt){
                break;
            }
            temp2=temp2->next;
        }
        return temp2;
    }
};