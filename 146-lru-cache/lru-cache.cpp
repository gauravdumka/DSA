class LRUCache {
public:
    // class for doubly linked list
    class node{
    public:
        int key; int val; node*next; node*prev;
        //// constructor
        node(int key, int val){
            this->key=key;
            this->val=val;
            next = nullptr;
            prev = nullptr;
        }
    };
    //// making two dummy nodes
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);

    //// deletenode function
    void deleteNode(node* curr){
        node* pren= curr->prev;
        node* nextn= curr->next;
        pren->next=nextn;
        nextn->prev=pren;
    }

    /// inserting after head function
    void insertAfterHead(node* curr){
        node*temp=head->next;
        curr->prev=head;
        head->next=curr;
        curr->next=temp;
        temp->prev=curr;
    }

    /// now solving things for cache
    int cap; unordered_map<int,node*>mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        mpp.clear();
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            // map is storing address to the node
            node* node=mpp[key];
            deleteNode(node);
            insertAfterHead(node);
            return node->val;
        }else{
            return -1; // if not found
        }
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            node*node=mpp[key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);
        }else{
            //maybe map's capacity exceeded already
            if(mpp.size()==cap){
                node*node=tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            node* newnode=new node(key,value);
            insertAfterHead(newnode);
            mpp[key]=newnode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */