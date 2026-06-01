class LRUCache {
    unordered_map<int, int> memory; // memory -> value
    unordered_map<int, list<int>::iterator> keyToIt;
    list<int> listMemory;
    int cap;
public:
    LRUCache(int capacity) {
        memory = unordered_map<int, int>();
        listMemory = list<int>();
        keyToIt = unordered_map<int, list<int>::iterator>();
        cap = capacity;
    }
    
    int get(int key) { // O(1)
        if (memory.contains(key))
        {
            list<int>::iterator it = keyToIt[key];
            listMemory.erase(it);
            listMemory.push_front(key);
            keyToIt[key] = listMemory.begin();
            return memory[key];
        } else
        {
            return -1;
        }
    }
    
    void put(int key, int value) { // O(1)
        if (listMemory.size() == cap)
        {
            int keyDeletedItem = listMemory.back();
            listMemory.pop_back();
            memory.erase(keyDeletedItem);
            keyToIt.erase(keyDeletedItem);
        }
        listMemory.push_front(key);
        keyToIt[key] = listMemory.begin();
        memory[key] = value;
    }
};
