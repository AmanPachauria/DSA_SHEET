#include <iostream>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    // constructor
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    bool containsChar(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Insert a word into Trie
    // TC -> O(length of word)
    void insert(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {

            // create node if not present
            if (!node->containsChar(word[i])) {
                node->put(word[i], new Node());
            }

            // move to next node
            node = node->get(word[i]);
        }

        node->setEnd();
    }

    // Search complete word
    // TC -> O(length of word)
    bool search(string word) {
        Node* node = root;

        for (int i = 0; i < word.length(); i++) {

            if (!node->containsChar(word[i])) {
                return false;
            }

            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    // Check prefix exists
    // TC -> O(length of prefix)
    bool startsWith(string prefix) {
        Node* node = root;

        for (int i = 0; i < prefix.length(); i++) {

            if (!node->containsChar(prefix[i])) {
                return false;
            }

            node = node->get(prefix[i]);
        }

        return true;
    }
};

int main() {

    Trie trie;

    trie.insert("apple");

    cout << trie.search("apple") << endl;      // 1 (true)
    cout << trie.search("app") << endl;        // 0 (false)
    cout << trie.startsWith("app") << endl;    // 1 (true)

    trie.insert("app");

    cout << trie.search("app") << endl;        // 1 (true)

    return 0;
}