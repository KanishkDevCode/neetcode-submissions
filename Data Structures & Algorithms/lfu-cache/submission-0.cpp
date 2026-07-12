class Node {
public:
    int key, value, freq;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        prev = next = NULL;
    }
};

class List {
public:
    int size;
    Node *head, *tail;

    List() {
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node *node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;

        size++;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        size--;
    }
};

class LFUCache {
public:

    int capacity;
    int minFreq;
    int currSize;

    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    LFUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreq(Node *node) {

        keyNode.erase(node->key);

        freqList[node->freq]->removeNode(node);

        if(node->freq == minFreq &&
           freqList[node->freq]->size == 0)
        {
            minFreq++;
        }

        node->freq++;

        List *nextList;

        if(freqList.count(node->freq))
            nextList = freqList[node->freq];
        else
        {
            nextList = new List();
            freqList[node->freq] = nextList;
        }

        nextList->addFront(node);

        keyNode[node->key] = node;
    }

    int get(int key) {

        if(keyNode.count(key)==0)
            return -1;

        Node *node = keyNode[key];

        updateFreq(node);

        return node->value;
    }

    void put(int key,int value) {

        if(capacity==0)
            return;

        if(keyNode.count(key))
        {
            Node *node = keyNode[key];

            node->value = value;

            updateFreq(node);

            return;
        }

        if(currSize == capacity)
        {
            List *list = freqList[minFreq];

            Node *node = list->tail->prev;

            keyNode.erase(node->key);

            list->removeNode(node);

            currSize--;
        }

        currSize++;

        minFreq = 1;

        List *list;

        if(freqList.count(minFreq))
            list = freqList[minFreq];
        else
        {
            list = new List();
            freqList[minFreq] = list;
        }

        Node *node = new Node(key,value);

        list->addFront(node);

        keyNode[key] = node;
    }
};