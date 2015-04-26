bool isHappy(int n) {
    int prev;
    int tmp;
    int result = 0;
    int count = 0;
    do{
        if(count++ == 20)
            break;
        prev = n;
        result = 0;
        while(n){
            tmp = n % 10;
            n /= 10;
            result += (tmp * tmp);
        }
        n = result;
        if(n == 1)
            return true;
    }while(prev != n);
    
    return false;
}
