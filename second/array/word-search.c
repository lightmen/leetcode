int **visited;
int row,col;
int len;

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

bool helper(char **board, int x, int y, char *word, int pos)
{
    bool ret = false;
    int i;

    if(pos == len)
        return true;

    for(i = 0; i < 4; ++i){
        int x1 = x + dir[i][0];
        int y1 = y + dir[i][1];

        if(x1 >= 0 && x1 < row && y1 >= 0 && y1 < col
            && !visited[x1][y1] && board[x1][y1] == word[pos]){
            visited[x1][y1] = 1;
            if(helper(board,x1,y1,word,pos+1))
                return true;
            visited[x1][y1] = 0;
        }
    }

    return false;
}

bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    int i,j;
    bool ret = false;

    row = boardRowSize;
    col = boardColSize;
    len = strlen(word);

    visited = (int **)malloc(sizeof(int *) * boardRowSize);
    for(i = 0; i < boardRowSize; ++i){
        visited[i] = (int *)malloc(sizeof(int) * boardColSize);
        memset(visited[i],0,sizeof(int) * boardColSize);
    }

    for(i = 0; i < row; ++i)
        for(j = 0; j < col; ++j){
            if(board[i][j] == word[0]){
                visited[i][j] = 1;
                if(helper(board,i,j,word,1)){
                    ret = true;
                    goto out;
                }

                visited[i][j] = 0;
            }
        }

out:
    for(i = 0; i < row; ++i)
        free(visited[i]);
    free(visited);

    return ret;
}
