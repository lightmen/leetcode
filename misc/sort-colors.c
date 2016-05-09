void sortColors(int A[], int n) {
    int cnt[3]={0};
    int i;
    for(i = 0; i < n; ++i)
        cnt[A[i]]++;
    for(i = 0; i < cnt[0]; ++i)
        A[i] = 0;
    for(i = cnt[0]; i < cnt[0] + cnt[1]; ++i)
        A[i] = 1;
    for(i = cnt[0] + cnt[1]; i < n; ++i)
        A[i] = 2;
}
