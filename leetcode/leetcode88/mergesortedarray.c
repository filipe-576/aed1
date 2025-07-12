void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m-1, j = n-1, r = nums1Size - 1;

    while( i >= 0 && j >= 0){
        if( nums1[i] > nums2[j] ){ // swap
            nums1[r] = nums1[i--];
        } else {
            nums1[r] = nums2[j--];
        }
        r--;
    }
    while( j >= 0 ){
        nums1[r--] = nums2[j--];
    }
    
    
}