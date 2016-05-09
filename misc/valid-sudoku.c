bool isValidSudoku(char** board, int row, int col) {
    int i,j;
    int key;
    int mem[10];

    for(i = 0; i < row; ++i){
        memset(mem,0,sizeof(int) * 10);
        for(j = 0; j < col; ++j){
            if(board[i][j] == '.')
                continue;
            key = board[i][j] - '0';
            if(mem[key] > 0)
                return false;
            mem[key]++;
        }
    }

    for(j = 0; j < col; ++j){
        memset(mem,0,sizeof(int)*10);
        for(i = 0; i < row; ++i){
            if(board[i][j] == '.')
                continue;
            key = board[i][j] - '0';
            if(mem[key] > 0)
                return false;
            mem[key]++;
        }
    }

    for(i = 0; i < 9; ++i){
        memset(mem,0,sizeof(int) * 10);
        for(j = 0; j < 9; ++j){
            int x = (i / 3) * 3 + (j / 3);
            int y = (i % 3) * 3 + (j % 3);

            if(board[x][y] == '.')
                continue;
            key = board[x][y] - '0';
            if(mem[key] > 0)
                return false;
            mem[key]++;
        }
    }

    return true;
}
