int len1;
int len2;

int findKth(int *a, int sa, int *b, int sb, int k)
{
    if(sa >= len1)
        return b[sb + k - 1];
    if(sb >= len2)
        return a[sa + k - 1];
    if(k == 1)
        return a[sa] < b[sb] ? a[sa] : b[sb];

    int ka = sa + k / 2 - 1 >= len1 ? INT_MAX
        : a[sa + k / 2 - 1];
    int kb = sb + k / 2 - 1 >= len2 ? INT_MAX
        : b[sb + k / 2 - 1];
    if(ka < kb)
        return findKth(a, sa + k / 2, b, sb, k - k / 2);
    else
        return findKth(a, sa, b, sb + k / 2, k - k / 2);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len;

    len1 = nums1Size;
    len2 = nums2Size;
    len = len1 + len2;

    if(len % 2)
        return findKth(nums1, 0, nums2, 0, len / 2 + 1);
    else
        return (findKth(nums1, 0, nums2, 0, len / 2) +
            findKth(nums1, 0, nums2, 0, len / 2 + 1)) / 2.0;
}
