int total;

static int is_ok(int *queue, int k, int pos)
{
    int i;
    for(i = 0; i < k; ++i){
        if(queue[i] == pos || abs(pos - queue[i]) == (k - i))
            return 0;
    }

    return 1;
}

void helper(int *queue, int n, int k)
{
    if(k == n){
        total++;
        return ;
    }

    int i;
    for(i = 0; i < n; ++i){
        if(!is_ok(queue,k,i))
            continue;
        queue[k] = i;
        helper(queue,n,k+1);
    }
}

int totalNQueens(int n) {
    int *queue;
    queue = (int *)malloc(sizeof(int) * n);
    total = 0;
    helper(queue,n,0);

    free(queue);
    return total;
}
