int len1;
int len2;

double findKth(int *nums1, int start1, int *nums2, int start2, int k)
{
    if(start1 >= len1)
        return nums2[start2 + k - 1];
    if(start2 >= len2)
        return nums1[start1 + k - 1];
    if(k == 1)
        return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];

    int value1 = start1 + k / 2 - 1 < len1 ?
        nums1[start1 + k / 2 - 1] : INT_MAX;
    int value2 = start2 + k / 2 - 1 < len2 ?
        nums2[start2 + k / 2 - 1] : INT_MAX;
    if(value1 < value2)
        return findKth(nums1, start1 + k / 2, nums2, start2, k - k / 2);
    else
        return findKth(nums1, start1, nums2, start2 + k / 2, k - k / 2);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len;

    len1 = nums1Size;
    len2 = nums2Size;
    len = len1 + len2;

    if(len % 2)
        return findKth(nums1,0,nums2,0,len / 2 + 1);
    else
        return (findKth(nums1,0,nums2,0,len / 2) + findKth(nums1,0,nums2,0,len / 2 + 1)) / 2.0;
}
