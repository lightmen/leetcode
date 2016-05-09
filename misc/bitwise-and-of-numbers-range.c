#define BIT(num,bit) (num & (1 << bit))

int rangeBitwiseAnd(int m, int n) {
    int bit = 0;
    int i;
    for(i = 31; i >= 0; --i){
        if(BIT(n,i))
            break;
    }
    while(i >= 0){
        if(BIT(m,i) != BIT(n,i))
            break;
        if(BIT(m,i))
            bit |= (1 << i);
        i--;
    }
    return bit;
}
