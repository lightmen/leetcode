void rotate(int nums[], int n, int k) {
    int i = 0;
    int count = 0;
    int start = 0;
    int cur = 0;
    int tmp = nums[0];

    if(k <= 0)
        return ;


    while(count < n){ 
        do{ 
            nums[start] = nums[(k+cur)%n];
            nums[(k+cur)%n] = tmp;
            tmp = nums[start];
            cur = (k+cur) % n;
            count++;
        }while(cur != start);

        start++;
        cur = start;
        tmp = nums[cur];
    }   
}
