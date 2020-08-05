/*

Add and Search Word - Data structure design


Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

   Hide Hint #1  
You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.

*/

class TrieNode
{
    public:
    bool isword;
    unordered_map<char,TrieNode*> child;
    
    TrieNode()
    {
        isword = false;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() 
    {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) 
    {
        auto curr = root;
        for(auto ch :word)
        {
            if(curr->child.find(ch)== curr->child.end())
            {
                curr->child[ch] = new TrieNode();
            }
            
            curr = curr ->child[ch];
        }
        curr->isword = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) 
    {
        return searchTrie(root,0,word);
    }
    
    private: TrieNode* root;
        bool searchTrie(TrieNode* A, int i, string s)
        {
            if(i==s.size())
                return A->isword;
            
            if(s[i]!='.')
            {
                if(A->child.find(s[i])==A->child.end()) 
                    return false;
                return searchTrie(A->child[s[i]],i+1,s);
            }
            
            for(auto it: A->child)
            {
                if(searchTrie(it.second,i+1,s))
                    return true;
            }
            return false;
            
        }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */