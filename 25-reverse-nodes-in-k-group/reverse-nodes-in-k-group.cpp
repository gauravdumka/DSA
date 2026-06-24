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
    ListNode*findknode(ListNode*temp,int k){
        k-=1;
        while(temp && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseLL(ListNode* temp){
        ListNode*previous=nullptr;
        while(temp!=nullptr){
            ListNode*nextnode=temp->next;
            temp->next=previous;
            previous=temp;
            temp=nextnode;
        }
        return previous;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*previous=nullptr;
        while(temp!=nullptr){
            ListNode* knode=findknode(temp, k);
            if(knode==nullptr){
                if(previous!=nullptr){
                    previous->next=temp;
                }
                break;
            }
            ListNode* nextnode=knode->next;
            knode->next=nullptr;
            reverseLL(temp);
                //after reversing conditions
            if(temp==head){
                head=knode;
                // temp->next=nextnode;
                // previous=temp;
                // temp=nextnode;    
            }else{
                previous->next=knode;
                // previous=temp;
                // temp->next=nextnode;
                // temp=nextnode;
            }  
            temp->next=nextnode;
                previous=temp;
                temp=nextnode;
        }
        return head;
    }
};