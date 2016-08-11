bool happy(int n, int *count)
{
    if(n == 1)
        return true;
    if(*count == 100 || n == 0)
        return false;

    int tmp = 0;
    int d;
    while(n > 0){
        d = n % 10;
        n /= 10;
        tmp += d * d;
    }

    *count++;
    return happy(tmp,count);
}

bool isHappy(int n) {
    int count = 0;
    return happy(n,&count);
}
