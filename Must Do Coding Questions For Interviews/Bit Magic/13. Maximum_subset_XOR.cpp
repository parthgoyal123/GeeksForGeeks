#include<bits/stdc++.h>
using namespace std;
 
// Number of bits to represent int
#define INT_BITS 32
int maxSubarrayXOR(int [], int n);
int main()
{
    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
      scanf("%d",&n);
        for(int i=0;i<n;i++)
            {
            scanf("%d",&a[i]);
            }
   
printf("%d",maxSubarrayXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}
/*This is a function problem.You only need to complete the function given below*/
// Function to return maximum XOR subset in set[]

#define INT_SIZE 32

int maxSubarrayXOR(int arr[], int n){
    
    // index that stores the last position of element chosen
    int index = 0;
    
    // iterate for all the bits
    for(int i = INT_SIZE-1; i>=0; i--) {
        
        // define maxEle and maxInd
        int maxEle = INT_MIN;
        int maxInd = index;
        
        for(int j = index; j<n; j++) {
            // check if the ith bit is set and the element is >= maxEle
            if(((arr[j] & (1 << i)) != 0) && arr[j] > maxEle) {
                maxEle = arr[j], maxInd = j;
            }
        }
        
        // check if there was actually an element with ith bit set
        if(maxEle == INT_MIN) continue;
        
        swap(arr[index], arr[maxInd]);
        
        // Update maxInd and  
        // increment index 
        maxInd = index; 
  
        // Do XOR of arr[maxIndex] 
        // with all numbers having 
        // i'th bit as set. 
        for (int j=0; j<n; j++) { 
            
            // XOR set[maxInd] those 
            // numbers which have the 
            // i'th bit set 
            if (j != maxInd && (arr[j] & (1 << i)) != 0) 
                arr[j] = arr[j] ^ arr[maxInd]; 
        } 
  
        // Increment index of 
        // chosen elements 
        index++; 
    }
    
    // Final result is  
    // XOR of all elements 
    int res = 0; 
    for (int i = 0; i < n; i++) res ^= arr[i]; 
        
    return res;
}