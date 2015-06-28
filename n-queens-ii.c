static int is_ok(int **queue, int n, int index, int y)
{
    int i,j;
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            if(queue[index][j] || queue[i][y] || 
                (queue[i][j] && abs(i-index) == abs(j-y)))
                return 0;
        }
    }
    return 1;
}

void helper(int **queue, int n, int *count, int index)
{
    int i;
    if(index == n){
        (*count)++;
        return ;
    }
    for(i = 0; i < n; ++i){
        if(is_ok(queue,n,index,i)){
            queue[index][i] = 1;
            helper(queue,n,count,index+1);
            queue[index][i] = 0;
        }
    }
}

int totalNQueens(int n) {
    int **queue;
    int i;
    int ret;

    queue = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; ++i){
        queue[i] = (int *)malloc(sizeof(int) * n);
        memset(queue[i],0,sizeof(int) * n);
    }

    ret = 0;
    helper(queue,n,&ret,0);


    for(i = 0; i < n; ++i)
		free(queue[i]);
    free(queue);
    return ret;
}
