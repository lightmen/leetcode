struct node {
    int key;
    int value;
    struct node *left;
    struct node *right;
};

struct node *add_node(struct node *head, int key)
{
    struct node *new_node, *cur;
    new_node = malloc(sizeof(struct node));
    new_node->key = key;
    new_node->value = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    if(head == NULL)
        return new_node;

    cur = head;
    while(cur){
        if(cur->key == key){
            free(new_node);
            cur->value++;
            break;
        }else if(cur->key > key){
            if(cur->left == NULL){
                cur->left = new_node;
                break;
            }
            cur = cur->left;
        }else{
            if(cur->right == NULL){
                cur->right = new_node;
                break;
            }
            cur = cur->right;
        }
    }

    return head;
}

int get_value_by_key(struct node *head, int key)
{
    while(head){
        if(head->key == key)
            break;
        if(head->key > key)
            head = head->left;
        else
            head = head->right;
    }

    return head ? head->value : 0;
}

void free_node(struct node *head)
{
    if(head){
        free_node(head->left);
        free_node(head->right);
        free(head);
    }
}

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize)
{
    int i,j;
    struct node *head = NULL;
    int ret = 0;

    for(i = 0; i < ASize; ++i)
        for(j = 0; j < BSize; ++j)
            head = add_node(head, A[i] + B[j]);

    for(i = 0; i < CSize; ++i)
        for(j = 0; j < DSize; ++j)
            ret += get_value_by_key(head, -(C[i] + D[j]));

    free_node(head);
    return ret;
}
