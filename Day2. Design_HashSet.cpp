/*

Design HashSet

Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)

Note:

1. All values will be in the range of [0, 1000000].
2. The number of operations will be in the range of [1, 10000].
3. Please do not use the built-in HashSet library.

*/


#define hash_key 500009
class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> hash[hash_key];
    MyHashSet() {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
    }
    
    void add(int key) 
    {
        int x= key % hash_key;
        if(find_pos(key)==hash[x].end())
            hash[x].push_back(key);
        
    }
    
    void remove(int key) 
    {
        int x= key % hash_key;
        auto it = find_pos(key);
        if(it!=hash[x].end())
            hash[x].erase(it);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) 
    {
        int x= key % hash_key;
        return find_pos(key)!=hash[x].end();
    }
    
    vector<int> :: iterator find_pos(int key)
    {
        int x= key % hash_key;
        auto it =hash[x].begin();
        for(it;it!=hash[x].end();it++)
        {
            if(*it==key) break;
        }
        
        return it;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */