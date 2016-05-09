static void reverse(int nums[], int begin, int end)
{
    int tmp;
    while(begin < end)
    {   
        tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = tmp;

        begin++;
        end--;
    }   
}

void rotate(int nums[], int n, int k) 
{
    k = k % n;
    reverse(nums,0,n - k - 1); 
    reverse(nums,n - k, n -1);
    reverse(nums,0,n-1);
}
