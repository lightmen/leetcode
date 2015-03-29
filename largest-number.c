int cmp(const void *a, const void *b)
{
      char sa[50];
      char sb[50];
      
      sprintf(sa,"%d%d",*(int *)a,*(int *)b);
      sprintf(sb,"%d%d",*(int *)b,*(int *)a);
      
      return strcmp(sb,sa);
}
char *largestNumber(int *num, int n) 
{
    int i,j,len,index;
    char tmp[50];
    char *ret = (char *)malloc(500 * sizeof(char));
    qsort(num,n,sizeof(int),cmp);
    index = 0;
    for(i = 0; i < n; ++i){
        sprintf(tmp,"%d",num[i]);
        sprintf(ret+index,"%s",tmp);
        index += strlen(tmp);
    }
   len = strlen(ret);
   
   i = 0;
   while(i < len - 1 && ret[i] == '0')
        i++;
   return ret+i;
}
