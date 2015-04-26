//if n is not happy, there always 4 in cycle
bool isHappy(int n) {
    int result = 0;
    int magic = 4;
    
    do{
        if(n == magic)
            break;
        result = 0;
        while(n){
            result += ((n%10) * (n%10));
            n /= 10;
        }
        n = result;
        if(n == 1)
            return true;
    }while(n);
    
    return false;
}
