int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int i = gSize - 1;
    int j = sSize - 1;
    int ret = 0;

    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    while(i >= 0 && j >= 0){
        if(s[j] >= g[i]){
            j--;
            ret++;
        }
        i--;
    }

    return ret;
}
