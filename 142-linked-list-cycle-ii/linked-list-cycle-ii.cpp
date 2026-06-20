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
        map<ListNode*, int>mpp;
        int cnt =0 ;
        ListNode *temp= head;
        while(temp){
            if(mpp.find(temp->next)!=mpp.end()){
                return temp->next;
            }
            mpp[temp]=cnt;
            temp= temp->next;
            cnt++;
        }
        return nullptr;
    }
};