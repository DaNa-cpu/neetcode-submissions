class Node{
public:
    int key; //needed for lru
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insert(Node* node){
        tail->prev->next = node;
        node->prev = tail->prev;

        tail->prev = node;
        node->next = tail;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.contains(key)){
            Node* node = mp[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.contains(key)){
            Node* node = mp[key];
            remove(node);
        } //if the node is already in the mp and linked list, just remove it from ll;

        Node* newNode = new Node(key, value); //create the node
        mp[key] = newNode; // create the key node in mp
        insert(newNode); // insert the node at the end of ll

        if(mp.size() > capacity){
            Node* lru = head->next; //lru is the next of the head
            remove(lru); // remove it from ll
            mp.erase(lru->key); //erase the key from mp
        }
    }
};
