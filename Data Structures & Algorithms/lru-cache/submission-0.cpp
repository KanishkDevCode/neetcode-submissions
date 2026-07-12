class LRUCache {

    class Node {
    public:
        int key;
        int value;

        Node* prev;
        Node* next;

        Node (int k, int v)
        {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    int capacity;

public:
    LRUCache(int cap) {
        
        capacity = cap;

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node)
    {
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }
    
    int get(int key) {

        if(mp.find(key)==mp.end())
            return -1;

        Node* node=mp[key];

        remove(node);

        insert(node);

        return node->value;
    }

    void put(int key,int value) {

        if(mp.find(key)!=mp.end())
        {
            Node* node=mp[key];

            node->value=value;

            remove(node);

            insert(node);

            return;
        }

        if(mp.size()==capacity)
        {
            Node* lru=head->next;

            remove(lru);

            mp.erase(lru->key);

            delete lru;
        }

        Node* node=new Node(key,value);

        insert(node);

        mp[key]=node;
    }
};