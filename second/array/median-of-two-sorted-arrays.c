double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *arr;
    int num = nums1Size + nums2Size;
    int i,j,k;
    double ret;

    arr = (int *)malloc(sizeof(int) * num);
    i = 0;
    j = 0;
    k = 0;
    while(i < nums1Size && j < nums2Size)
        arr[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];

    while(i < nums1Size)
        arr[k++] = nums1[i++];
    while(j < nums2Size)
        arr[k++] = nums2[j++];

    if(num % 2)
        ret = arr[num/2];
    else
        ret = (arr[(num-1)/2] + arr[num/2]) / 2.0;

    free(arr);
    return ret;
}
