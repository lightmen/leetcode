void merge(int* nums1, int m, int* nums2, int n) {
    int end = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while(i >= 0 && j >= 0)
        nums1[end--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];

    while(i >= 0)
        nums1[end--] = nums1[i--];

    while(j >= 0)
        nums1[end--] = nums2[j--];
}
