bool canJump(int A[], int n) {
    int beg,end,max_jump,i;
    beg = 0;
    end = A[0];
    while(end < n-1){
        max_jump = end;
        for(i = beg; i <= end; ++i){
            if(max_jump < (i+A[i]))
                max_jump = i + A[i];
        }
        if(max_jump == end)
            break;
        beg = end;
        end = max_jump;
    }
    if(end < n - 1)
        return false;
    return true;
}
