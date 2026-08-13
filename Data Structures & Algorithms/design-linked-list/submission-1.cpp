class Node{
public:
    int val;
    Node *prev, *next;

    Node(int val){
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head; 
    Node* tail;

    MyLinkedList() {
        head = new Node(0); 
        tail = new Node(0);

        head->next = tail;
        tail->prev = head; 
    }
    
    int get(int index) {
        Node* cur = head->next;
        while(cur && index > 0){
            cur = cur->next;
            index--;
        }
        if(cur && cur != tail && index == 0){
            return cur->val;
        }
        return -1;

    }
    void addAtHead(int val) {
        Node* node = new Node(val);
    
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;

    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);

        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }
    
    void addAtIndex(int index, int val) {
        Node* cur = head->next;
        
        while(cur && index > 0){
            cur = cur->next;
            index--;
        }
        if(cur && index==0){
            Node* node = new Node(val);
            node->next = cur;
            node->prev = cur->prev;
            cur->prev->next = node;
            cur->prev = node;
        }

    }
    
    void deleteAtIndex(int index) {
        Node* cur = head->next;
        while(cur && index > 0){
            cur = cur->next;
            index--;
        }
        if(cur && cur!=tail && index==0){
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */