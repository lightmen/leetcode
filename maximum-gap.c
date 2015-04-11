static int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int maximumGap(int num[], int n) {
    int *arr;
    int i,j;
    int max = 0;
    
    qsort(num,n,sizeof(int),cmp);
    for(i = 0; i < n-1; ++i)
        if(abs(num[i+1] - num[i]) > max)
            max = abs(num[i+1] - num[i]);
        
    return max;
}
