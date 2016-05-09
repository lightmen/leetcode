void rotate(int nums[], int n, int k) {
    int *arr;
    int i;
    arr = (char *)malloc(sizeof(int) * n);
    k = k % n;
    for(i = 0; i < n; ++i)
        arr[(i+k)%n] = nums[i];
    for(i = 0; i < n; ++i)
        nums[i] = arr[i];
}
