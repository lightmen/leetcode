bool isPalindrome(int x) {
    if(x < 0)
        return false;

    int rx = 0;
    int tmp = x;
    while(tmp){
        rx = 10 * rx + (tmp % 10);
        tmp /= 10;
    }

    return rx == x;
}
