// C program for implementation of Merge Sort
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int r);
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("");
}
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* The task is to complete merge() which is used
   in below mergeSort() */
/*   l is for left index and r is right index of the
   sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r) {
    if (l < r)   {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
} */
// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    
    // get the sizes of arrays to be merged
    int n1 = m-l+1;
    int n2 = r-m;
    
    // make auxillary arrays
    int L[n1], R[n2];
    
    // fill the aux arrays with elements of the array
    for(int i = 0; i < n1; i++) {
        L[i] = arr[l+i];
    }
    
    for(int i = 0; i < n2; i++) {
        R[i] = arr[m+1+i];
    }
    
    int k = l;
    int i = 0, j = 0;
    
    while(i < n1 && j < n2) {
        if(L[i] < R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    // if second array is finished, fill will left of first array
    while(i < n1) {
        arr[k++] = L[i++];
    }
    
    // if first array is finished, fill will left of second array
    while(j < n2) {
        arr[k++] = R[j++];
    }
}