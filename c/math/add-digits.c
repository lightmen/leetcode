int addDigits(int num) {
    int ret = num;
    while(num > 9){
        ret = 0;
        while(num){
            ret += (num % 10);
            num /= 10;
        }
        num = ret;
    }

    return ret;
}
