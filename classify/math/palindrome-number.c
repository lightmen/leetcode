bool isPalindrome(int x) {
    if(x < 0)
        return false;
    long rx = 0;
    int tmp = x;
    while(tmp){
        rx = 10 * rx + (tmp % 10);
        tmp /= 10;
    }

    while(x){
        if(rx % 10 != x % 10)
            return false;
        rx /= 10;
        x /= 10;
    }

    return rx == 0 ? true : false;
}
