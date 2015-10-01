int min_3(int a, int b, int c)
{
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int nthUglyNumber(int n) {
    int *arr;
    int t2,t3,t5;
    int c;

    arr = (int *)malloc(sizeof(int) * n);
    t2 = t3 = t5 = 0;
    arr[0] = 1;
    c = 1;

    while(c < n){
        int m = min_3(arr[t2] * 2, arr[t3] * 3, arr[t5] * 5);
        arr[c++] = m;

        if(arr[t2] * 2 == m)
            t2++;
        if(arr[t3] * 3 == m)
            t3++;
        if(arr[t5] * 5 == m)
            t5++;
    }

    return arr[n-1];
}
