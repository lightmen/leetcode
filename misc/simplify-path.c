struct path
{
    char *name;
    struct path *parent;
    struct path *child;
};

struct path *get_path(char *name)
{
    struct path *ret;
    ret = (struct path *)malloc(sizeof(struct path));
    ret->name = strdup(name);
    ret->parent = NULL;
    ret->child = NULL;
}

void handle_dotdot(struct path **cur)
{
    struct path *tmp;
    if(!strcmp((*cur)->name,"/"))
        return ;
    tmp = *cur;
    *cur = (*cur)->parent;
    (*cur)->child = NULL;
    free(tmp->name);
    free(tmp);
}

char* simplifyPath(char* str) {
    struct path *root,*cur,*tmp;
    char *start,*ret,*name;

    root = get_path("/");
    cur = root;

    while(*str){
        while(*str == '/')
            str++;
        if(*str)
            goto out;

        start = str;
        while(*str && *str != '/')
            str++;

        name = strndup(start,str-start);

        if(strcmp(name,".") == 0 || strcmp(name,"..") == 0){
            if(strcmp(name,"..") == 0){
                handle_dotdot(&cur);
            }
            continue;
        }

        tmp = get_path(name);
        cur->child = tmp;
        tmp->parent = cur;
        cur = tmp;
    }

out:
    ret = (char *)malloc(sizeof(char) * 4096);
    ret[0] = 0;
    while(root){
        cur = root;
        strcat(ret, root->name);

        if(strcmp(root->name, "/") != 0 && root->child){
            strcat(ret,"/");
        }
        root = root->child;

        free(cur->name);
        free(cur);
    }

    return ret;
}
