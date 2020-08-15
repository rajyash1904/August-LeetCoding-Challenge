/*

Iterator for Combination

Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false
 

Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.
   
   Hide Hint #1  
Generate all combinations as a preprocessing.
   
   Hide Hint #2  
Use bit masking to generate all the combinations.

*/


class CombinationIterator {
public:
    vector<int> now;
    unordered_map<int,char> m;
    int combinationLength;
    
    CombinationIterator(string characters, int combinationLength) {
        for(int i=0; i<characters.size(); i++)m[i] = characters[i];
        this->combinationLength = combinationLength;
    }
    
    void nextnow(int pos){
        int fin = now.size() - pos - 1;
        if(now[pos] == m.size() - fin - 1)nextnow(pos-1);
        else{
            now[pos]++;
            for(int i=pos+1; i<now.size(); i++){
                now[i] = now[i-1]+1;
            }
        }
        
    }
    string next() {
        if(!now.size()){
            for(int i=0; i<combinationLength; i++)now.push_back(i);
            string ret = "";
            for(int i=0; i<now.size(); i++)ret += m[now[i]];
            return ret;
        }
        else{
            nextnow(combinationLength-1);
            string ret = "";
            for(int i=0; i<now.size(); i++)ret += m[now[i]];
            return ret;
        }
    }
    
    bool hasNext() {
        if(now.size() == 0)return true;
        for(int i=0; i<now.size(); i++){
            int fin = now.size() - i - 1;
            if(now[i] != m.size() - fin - 1) return true;
        }
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */