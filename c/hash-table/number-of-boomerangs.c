struct node {
    int key;
    int value;
    struct node *left;
    struct node *right;
};

struct node * node_add(struct node *head, int key)
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

void node_free(struct node *head)
{
    if(head == NULL)
        return ;
    node_free(head->left);
    node_free(head->right);
    free(head);
}

int get_value_by_key(struct node *head, int key)
{
    struct node *cur = head;
    while(cur){
        if(cur->key == key)
            break;
        if(cur->key > key)
            cur = cur->left;
        else
            cur = cur->right;
    }

    return cur ? cur->value : 0;
}

int dist(int x1, int y1, int x2, int y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int numberOfBoomerangs(int** points, int pointsRowSize, int pointsColSize) {
    int i,j;
    struct node *head;
    int ret = 0;
    int key;

    for(i = 0; i < pointsRowSize; ++i){
        head = NULL;
        for(j = 0; j < pointsRowSize; ++j){
            if(i == j)
                continue;
            key = dist(points[i][0], points[i][1], points[j][0], points[j][1]);
            ret += (2 * get_value_by_key(head, key));
            head = node_add(head, key);
        }
        node_free(head);
    }

    return ret;
}
