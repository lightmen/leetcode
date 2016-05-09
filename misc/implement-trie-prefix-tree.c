struct TrieNode {
    struct TrieNode *child[26];
    int is_word;
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    struct TrieNode *root;
    root = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    memset(root,0,sizeof(struct TrieNode));

    return root;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
    int key;
    while(*word){
        key = *word - 'a';
        if(root->child[key] == NULL)
            root->child[key] = trieCreate();
        root = root->child[key];
        word++;
    }

    root->is_word = 1;
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
    int key;
    while(*word){
        key = *word - 'a';
        if(root->child[key] == NULL)
            return false;
        root = root->child[key];
        word++;
    }

    return root->is_word;
}

/** Returns if there is any word in the trie
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    int key;
    while(*prefix){
        key = *prefix - 'a';
        if(root->child[key] == NULL)
            return false;
        root = root->child[key];
        prefix++;
    }

    return true;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    int i;
    if(root == NULL)
        return ;

    for(i = 0; i < 26; ++i)
        trieFree(root->child[i]);
    free(root);
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);
