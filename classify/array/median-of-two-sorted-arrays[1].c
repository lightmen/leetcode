int len1;
int len2;

int findKth(int a[], int a_start, int b[], int b_start, int k)
{
    if(a_start >= len1)
        return b[b_start + k - 1];
    if(b_start >= len2)
        return a[a_start + k - 1];
    if(k == 1)
        return a[a_start] < b[b_start] ? a[a_start] : b[b_start];

    int a_key = a_start + k / 2 - 1 < len1 ?
                a[a_start + k / 2 - 1] : INT_MAX;
    int b_key = b_start + k / 2 - 1 < len2 ?
                b[b_start + k / 2 - 1] : INT_MAX;

    if(a_key < b_key)
        return findKth(a,a_start + k / 2, b, b_start, k - k / 2);
    else
        return findKth(a,a_start, b, b_start + k / 2, k - k / 2);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len;
    len1 = nums1Size;
    len2 = nums2Size;

    len = len1 + len2;
    if(len % 2)
        return findKth(nums1,0,nums2,0,len/2 + 1);
    else
        return (findKth(nums1,0,nums2,0,len/2) + findKth(nums1,0,nums2,0,len/2 + 1)) / 2.0;
}
