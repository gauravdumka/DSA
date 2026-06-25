/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp!=nullptr){
            Node*NewNode=new Node(temp->val);
            NewNode->next=temp->next;
            temp->next=NewNode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=nullptr){
            if(temp->random==nullptr){
                temp->next->random=nullptr;
            }
            else{
                temp->next->random=temp->random->next;
            }
            temp = temp->next->next;
        }
        // extract deepcopy now from the linked list
        temp=head;
        Node*dummyN=new Node(-1);
        Node* res= dummyN;
        while(temp!=nullptr){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummyN->next;
    }
};