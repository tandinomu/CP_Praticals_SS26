#include <iostream>
#include <string>
using namespace std;

// A trie node has 26 children (one for each letter a-z)
// and a flag to mark if a word ends here
struct Node {
    Node* child[26];
    bool  isEnd;
};

// Make a blank new node
Node* makeNode() {
    Node* n = new Node();
    n->isEnd = false;
    for (int i = 0; i < 26; i++)
        n->child[i] = NULL;
    return n;
}

// INSERT: walk down the trie, creating nodes as needed
void insert(Node* root, string word) {
    Node* cur = root;
    for (int i = 0; i < word.length(); i++) {
        int idx = word[i] - 'a';          // 'a'=0, 'b'=1, ...
        if (cur->child[idx] == NULL)
            cur->child[idx] = makeNode(); // create if missing
        cur = cur->child[idx];
    }
    cur->isEnd = true;
    cout << "  Inserted: " << word << endl;
}

// SEARCH: walk down; return false if any letter is missing
bool search(Node* root, string word) {
    Node* cur = root;
    for (int i = 0; i < word.length(); i++) {
        int idx = word[i] - 'a';
        if (cur->child[idx] == NULL)
            return false;
        cur = cur->child[idx];
    }
    return cur->isEnd; // true only if this is a complete word
}

// Helper used by delete: is this node a dead-end?
bool noChildren(Node* n) {
    for (int i = 0; i < 26; i++)
        if (n->child[i] != NULL) return false;
    return true;
}

// DELETE: recursively remove letters, but only if no other word needs them
bool deleteWord(Node* cur, string word, int depth) {
    if (cur == NULL) return false;

    if (depth == word.length()) {
        if (!cur->isEnd) return false; // word not here
        cur->isEnd = false;
        return noChildren(cur);        // safe to delete node?
    }

    int idx = word[depth] - 'a';
    bool shouldDelete = deleteWord(cur->child[idx], word, depth + 1);

    if (shouldDelete) {
        delete cur->child[idx];
        cur->child[idx] = NULL;
        return !cur->isEnd && noChildren(cur);
    }
    return false;
}

int main() {
    cout << "==============================" << endl;
    cout << "  TRIE: Insert / Search / Delete" << endl;
    cout << "==============================" << endl;

    Node* root = makeNode();

    // ---- INSERT ----
    cout << endl << "[INSERT]" << endl;
    insert(root, "apple");
    insert(root, "app");
    insert(root, "bat");
    insert(root, "ball");

    // ---- SEARCH ----
    cout << endl << "[SEARCH]" << endl;
    cout << "  apple  -> " << (search(root, "apple") ? "FOUND" : "NOT FOUND") << endl;
    cout << "  app    -> " << (search(root, "app")   ? "FOUND" : "NOT FOUND") << endl;
    cout << "  ap     -> " << (search(root, "ap")    ? "FOUND" : "NOT FOUND") << endl;
    cout << "  bat    -> " << (search(root, "bat")   ? "FOUND" : "NOT FOUND") << endl;
    cout << "  ban    -> " << (search(root, "ban")   ? "FOUND" : "NOT FOUND") << endl;

    // ---- DELETE ----
    cout << endl << "[DELETE]" << endl;
    if (search(root, "app")) {
        deleteWord(root, "app", 0);
        cout << "  Deleted: app" << endl;
    }
    if (search(root, "bat")) {
        deleteWord(root, "bat", 0);
        cout << "  Deleted: bat" << endl;
    }
    if (!search(root, "xyz"))
        cout << "  Cannot delete xyz: NOT FOUND" << endl;

    // ---- SEARCH AFTER DELETE ----
    cout << endl << "[SEARCH AFTER DELETE]" << endl;
    cout << "  apple  -> " << (search(root, "apple") ? "FOUND" : "NOT FOUND") << endl;
    cout << "  app    -> " << (search(root, "app")   ? "FOUND" : "NOT FOUND") << endl;
    cout << "  bat    -> " << (search(root, "bat")   ? "FOUND" : "NOT FOUND") << endl;
    cout << "  ball   -> " << (search(root, "ball")  ? "FOUND" : "NOT FOUND") << endl;

    cout << endl << "==============================" << endl;
    return 0;
}