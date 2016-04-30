void merge(int* nums1, int m, int* nums2, int n) {
    int end = m + n - 1;
    int i,j;

    i = m - 1;
    j = n - 1;
    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j])
            nums1[end--] = nums1[i--];
        else
            nums1[end--] = nums2[j--];
    }

    while(j >= 0)
        nums1[end--] = nums2[j--];
}
