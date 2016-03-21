#define min_3(x, y, z) ({ \
    int _x = (x); \
    int _y = (y); \
    int _z = (z); \
    int _min = _x < _y ? _x : _y; \
    _z < _min ? _z : _min; \
})

int nthUglyNumber(int n) {
    int *arr;
    int ret;
    int t2,t3,t5;
    int c;

    arr = (int *)malloc(sizeof(int) * n);
    arr[0] = 1;
    t2 = t3 = t5 = 0;
    c = 1;

    while(c < n){
        int tmp = min_3(arr[t2] * 2, arr[t3] * 3, arr[t5] * 5);
        arr[c++] = tmp;

        while(arr[t2] * 2 <= tmp)
            t2++;
        while(arr[t3] * 3 <= tmp)
            t3++;
        while(arr[t5] * 5 <= tmp)
            t5++;
    }

    ret = arr[n-1];
    free(arr);
    return ret;
}
