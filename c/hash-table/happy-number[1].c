bool isHappy(int n) {
    int *flag;
    int tmp;
    const int N = 100;

    flag = malloc(sizeof(int) * N);
    memset(flag, 0, sizeof(int) * N);

    while(1){
        if(n == 1)
            break;
        if(n < 100 && flag[n])
            break;

        if(n < 100)
            flag[n] = 1;

        tmp = 0;
        while(n > 0){
            tmp += (n % 10) * (n % 10);
            n /= 10;
        }
        n = tmp;
    }

    free(flag);
    return n == 1;
}
