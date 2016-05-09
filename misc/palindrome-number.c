bool isPalindrome(int x) {
    int rev = 0;
    int tmp = x;

    if(x < 0)
        return false;

    while(tmp){
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    
    return rev == x;
}
