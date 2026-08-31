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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return {-1,-1};
        }
        int cnt=1; vector<int>cp;
        ListNode* temp1=head;
        ListNode* temp2=head->next;
        ListNode* temp3=head->next->next;
        while(temp2->next!=nullptr){
            if((temp2->val > temp1->val) && (temp2->val > temp3->val)){
                cp.push_back(cnt);
            }
            if((temp2->val < temp1->val) && (temp2->val < temp3->val)){
                cp.push_back(cnt);
            }
            cnt++;
            temp1=temp1->next;
            temp2=temp2->next;
            temp3=temp3->next;
        }
        if(cp.size()<=1){
            return{-1,-1};
        }
        if(cp.size()==2){
            return{(cp[1]-cp[0]),(cp[1]-cp[0])};
        }
        int mini = INT_MAX; 

        for(int i = 1; i < cp.size(); i++){ ///// minimum poore array ke beech me kinhi 2 critical points ka diff ho skta hai
            mini = min(mini, cp[i] - cp[i-1]);
        }

        int maxi = cp[cp.size()-1] - cp[0];

        return {mini, maxi};
    }
    
};