#include <iostream>
#include <string>
using namespace std;

// Return the k-th bit of s (0 = MSB of first byte)
int getBit(const string& s, int k) {
    if (k < 0) return 0;
    int byteIdx = k / 8;
    int bitIdx  = 7 - (k % 8);
    if (byteIdx >= (int)s.size()) return 0;
    return (s[byteIdx] >> bitIdx) & 1;
}

// First bit position where strings a and b differ
int firstDiff(const string& a, const string& b) {
    int maxBits = (int)max(a.size(), b.size()) * 8;
    for (int i = 0; i < maxBits; i++)
        if (getBit(a,i) != getBit(b,i)) return i;
    return maxBits;
}

// ---- Node ----
struct Node {
    string key;
    int    bit;   // bit index this node branches on
    Node*  left;  // taken when bit=0
    Node*  right; // taken when bit=1
};

Node* newNode(const string& k, int b) {
    return new Node{k, b, nullptr, nullptr};
}

// ---- Tree root ----
// We use a header node with bit=-1 so the real root
// is always root->left (standard PATRICIA convention).
Node* header = nullptr;

// ---- Search helper: follow links until bit stops going forward ----
Node* search_node(const string& key) {
    Node* p = header;
    Node* c = header->left;          // start from real root
    while (c->bit > p->bit) {        // keep going while moving forward
        p = c;
        c = getBit(key, c->bit) ? c->right : c->left;
    }
    return c;                         // c is the terminal node
}

// ---- SEARCH ----
bool search(const string& key) {
    if (!header) return false;
    Node* n = search_node(key);
    return n->key == key;
}

// ---- INSERT ----
void insert(const string& key) {
    if (!header) {
        // First ever insert: create header + first real node
        header       = newNode("", -1);
        Node* first  = newNode(key, 0);
        first->left  = first;     // self back-link
        first->right = first;
        header->left = first;
        cout << "  Inserted (first): \"" << key << "\"\n";
        return;
    }

    Node* t = search_node(key);
    if (t->key == key) {
        cout << "  Already exists:   \"" << key << "\"\n";
        return;
    }

    int diff = firstDiff(key, t->key);  // first bit where they differ

    // Walk from real root to find insertion point
    Node* p = header;
    Node* c = header->left;
    while (c->bit > p->bit && c->bit < diff) {
        p = c;
        c = getBit(key, c->bit) ? c->right : c->left;
    }

    // Create new node with a back-link to itself
    Node* n = newNode(key, diff);
    if (getBit(key, diff)) {
        n->left  = c;   // back or forward link to existing subtree
        n->right = n;   // self back-link
    } else {
        n->left  = n;   // self back-link
        n->right = c;
    }

    // Attach new node to parent
    if (getBit(key, p->bit))
        p->right = n;
    else
        p->left  = n;

    cout << "  Inserted: \"" << key << "\"  (branch bit=" << diff << ")\n";
}

// ---- DELETE: lazy — blank the key ----
bool deleteKey(const string& key) {
    if (!header) { cout << "  Tree empty.\n"; return false; }
    Node* n = search_node(key);
    if (n->key != key) {
        cout << "  Cannot delete \"" << key << "\": NOT FOUND\n";
        return false;
    }
    n->key = "\x7F__del__";   // sentinel — never matches real input
    cout << "  Deleted: \"" << key << "\"\n";
    return true;
}

// ---- main ----
int main() {
    cout << "==============================\n";
    cout << "  PATRICIA: Insert / Search / Delete\n";
    cout << "==============================\n";

    cout << "\n[INSERT]\n";
    insert("apple");
    insert("app");
    insert("bat");
    insert("ball");
    insert("apple");   // duplicate — blocked

    cout << "\n[SEARCH]\n";
    for (auto& w : {"apple","app","bat","ball","ban","ap"})
        cout << "  \"" << w << "\" -> " << (search(w)?"FOUND":"NOT FOUND") << "\n";

    cout << "\n[DELETE]\n";
    deleteKey("bat");
    deleteKey("xyz");

    cout << "\n[SEARCH AFTER DELETE]\n";
    for (auto& w : {"apple","app","bat","ball"})
        cout << "  \"" << w << "\" -> " << (search(w)?"FOUND":"NOT FOUND") << "\n";

    cout << "\n==============================\n";
    return 0;
}