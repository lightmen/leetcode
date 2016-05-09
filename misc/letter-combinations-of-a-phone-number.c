/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char *arr[10] = {" ","","abc","def","ghi","jkl",
                    "mno", "pqrs","tuv","wxyz"};
int len;
int count;
int total;

void helper(char **ret, char *digits, char *member, int start, int index)
{
    int i,j,str_len;
    char *str;

    if( start == len){
        if(index != 0)
            ret[count++] = strdup(member);
        return ;
    }

    str = arr[digits[start] - '0'];

    str_len = strlen(str);
    if(str_len == 0){
        helper(ret,digits,member,start+1,index);
        return ;
    }

    for(i = 0 ; i < str_len; ++i){
        member[index] = str[i];
        helper(ret,digits,member,start+1,index+1);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int i;
    char **ret;
    char *member;
    char *str;

    len = strlen(digits);
    total = 1;
    for(i = 0; i < len; ++i){
        str = arr[digits[i] - '0'];
        if(strlen(str) == 0)
            continue;
        total *= strlen(str);
    }

    ret = (char **)malloc(sizeof(char *) * total);
    member = (char *)malloc(sizeof(char) * (len + 1));
    memset(member, 0, sizeof(char) * (len + 1));

    count = 0;
    helper(ret,digits,member,0,0);
    *returnSize = count;

    free(member);
    return ret;
}
