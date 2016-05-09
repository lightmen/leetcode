int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int majorityElement(int num[], int n) {
    qsort(num,n,sizeof(int),cmp);
    return num[n/2];
}
