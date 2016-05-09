bool isHappy(int n) {
    int *flag;
    int result;
    
    flag = (int *)malloc(sizeof(int) * 1000);
    memset(flag,0,sizeof(int) * 1000);
    
    while(n){
        result = 0;
        while(n){
            result += ((n%10) * (n%10));
            n /= 10;
        }
        n = result;
        if(flag[n])
            break;
        flag[n] = 1;
        if(n == 1)
            return true;
    }
    return false;
}
