class LRUCache {
    struct LRUNode {
        int key;
        int val;
        LRUNode* prev;
        LRUNode* next;
    };
public:
    int capacity;
    int size;
    LRUNode* start; // node whos prev is nullptr
    LRUNode* end; // node whos next is nullptr
    unordered_map<int, LRUNode*> LRU_map;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->start = nullptr;
        this->end = nullptr;
    }
    
    int get(int key) {
        int ans = updatePos(key);
        //printList();
        return ans;
    }
    
    void put(int key, int value) {
        int res = updatePos(key);
        //cout << key << " ";
        if(res == -1) // doesn't exist
        {
            //cout << value << " ";
            size++;
            LRUNode* new_node = new LRUNode();
            new_node->key = key;
            new_node->val = value;
            new_node->next = start;
            // since its new, prev is nullptr
            if(start)
            {start->prev = new_node;}
            start = new_node;
            LRU_map[key] = new_node;
            if(size > capacity) {
                end = end->prev;
                LRU_map.erase(end->next->key);
                delete end->next;
                end->next = nullptr;
                size--;
            }
            if(size == 1) {
                end = new_node;
            }
        }
        else {
            LRUNode* update = LRU_map[key];
            update->val = value;
        }
        //printList();
    }

    // helper func, also returns value
    int updatePos(int key) {
        LRUNode* update = LRU_map[key];
        if(update && update->prev && update->next == nullptr) {
            end = update->prev;
        }
        if(update == nullptr) {return -1;}
        if(update->prev) {
            update->prev->next = update->next;
            if(update->next) {update->next->prev = update->prev;}
            // move to front
            update->prev = nullptr;
            update->next = start;
            if(start){start->prev = update;}
            start = update;
        }
        return update->val;
    }

    void printList() {
        int s = 0;
        int e = 0;
        if(start) {
            s = start->val;
        }
        if(end) {
            e = end->val;
        }
        cout << s << " " << e << ":";

        LRUNode* temp = start;
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};