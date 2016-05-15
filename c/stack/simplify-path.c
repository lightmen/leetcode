struct path {
    char *name;
    struct path *parent;
    struct path *child;
};

struct path* init_path(char *name)
{
    struct path *p = malloc(sizeof(struct path));
    p->name = strdup(name);
    p->parent = NULL;
    p->child = NULL;

    return p;
}

struct path *handle_dotdot(struct path *p)
{
    if(!p->parent)
        return p;

    struct path *parent = p->parent;
    parent->child = NULL;
    free(p->name);
    free(p);
    return parent;
}

char* simplifyPath(char* path) {
    struct path *root;
    struct path *cur, *parent;
    char *start,*name;

    root = init_path("/");
    cur = root;

    while(*path){
        while(*path == '/')
            path++;
        if (*path == '\0')
            break;

        start = path;
        while(*path && *path != '/')
            path++;

        int len = path - start;
        char *name = strndup(start,len);
        if(!strcmp(name,"."))
            continue;
        if(!strcmp(name,"..")){
            cur = handle_dotdot(cur);
            continue;
        }

        struct path *p = init_path(name);
        p->parent = cur;
        cur->child = p;
        cur = p;
        free(name);
    }

    cur = root;
    char *ret = malloc(4096);
    ret[0] = 0;
    strcat(ret,root->name);
    cur = root->child;

    while(cur){
        strcat(ret,cur->name);
        parent = cur;
        cur = cur->child;
        free(parent->name);
        free(parent);
        if(cur)
            strcat(ret,"/");
    }

    return ret;
}
