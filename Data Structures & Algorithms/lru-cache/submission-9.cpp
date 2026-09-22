class Node{
public:
    int key;
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
        }

        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        insert(newNode);

        if(mp.size() > capacity){
            Node* lru = head->next;
            remove(lru);
            mp.erase(lru->key);
        }
    }
};
