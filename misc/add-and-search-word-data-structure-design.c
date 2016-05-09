struct WordDictionary {
    struct WordDictionary *child[26];
    int is_word;
};

/** Initialize your data structure here. */
struct WordDictionary* wordDictionaryCreate() {
    struct WordDictionary *root;
    root = (struct WordDictionary *)malloc(sizeof(struct WordDictionary));
    memset(root,0,sizeof(struct WordDictionary));

    return root;
}

/** Inserts a word into the data structure. */
void addWord(struct WordDictionary* root, char* word) {
    int key;
    while(*word){
        key = *word - 'a';
        if(root->child[key] == NULL){
            root->child[key] = wordDictionaryCreate();
        }
        root = root->child[key];
        word++;
    }

    root->is_word = 1;
}

/** Returns if the word is in the data structure. A word could
    contain the dot character '.' to represent any one letter. */
bool search(struct WordDictionary* root, char* word) {
    int key,i;
    bool ret = false;
    while(*word){
        key = -1;
        if(*word != '.')
            key = *word - 'a';

        if(key == -1){
            for(i = 0; i < 26; ++i){
                if(root->child[i])
                    ret = search(root->child[i],word+1);
                if(ret)
                    break;
            }
            return ret;
        }

        if(root->child[key] == NULL)
            return false;

        word++;
        root = root->child[key];
    }

    return root->is_word;
}

/** Deallocates memory previously allocated for the data structure. */
void wordDictionaryFree(struct WordDictionary* root) {
    int i;
    for(i = 0; i < 26; ++i)
        if(root->child[i])
            wordDictionaryFree(root->child[i]);

    free(root);
}

// Your WordDictionary object will be instantiated and called as such:
// struct WordDictionary* wordDictionary = wordDictionaryCreate();
// addWord(wordDictionary, "word");
// search(wordDictionary, "pattern");
// wordDictionaryFree(wordDictionary);
