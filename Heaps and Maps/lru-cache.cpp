/*
    https://www.interviewbit.com/problems/lru-cache/
*/
#include<list>

int capacity = 0;
unordered_map<int, pair<list<int>::iterator, int> > cache;
list<int> lru;

LRUCache::LRUCache(int input_capacity) {
    cache.clear();
    lru.clear();
    capacity = input_capacity;
}

// updates the position of a key item in LRU queue
// brings the key item to front
void moveToFront(unordered_map<int, pair<list<int>::iterator, int> > :: iterator it) {
    // erase the node from list
    lru.erase(it->second.first);
    // insert a node with the key
    lru.emplace_front(it->first);
    // update the addr of node in hash table
    it->second.first = lru.begin();
}

int LRUCache::get(int key) {
    // check if the item is in cache or not
    auto it = cache.find(key);
    // update the usage activity of key in lru queue
    if(it != cache.end()) {
        moveToFront(it);
        return it->second.second;
    }
    else 
        return -1;
}

void LRUCache::set(int key, int value) {
    // check if the key already exist sor not
    auto it = cache.find(key);
    // if it exists, update its value and update the 
    // activity
    if(it != cache.end()) {
        it->second.second = value;
        moveToFront(it);
    }
    // insert the key and update the activity
    else {
        // if the cache has reached its limit,
        // remove the lru element
        if(cache.size() >= capacity) {
            int lru_key = lru.back();
            lru.pop_back();
            cache.erase(lru_key);
        }
        // insert the element in hash table as well queue
        lru.emplace_front(key);
        cache[key] = make_pair(lru.begin(), value);
    }
}
