#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define md 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define loopr(i,a,b) for(int i = a; i>=b; i--)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)
#define mk make_pair
#define pb push_back

template <typename T>
void printArray(T *arr, int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

template <typename T>
void printMatrix(T **arr, int n, int m){
    loop(i,0,n){
        loop(j,0,m) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 
    cout << endl;
}

int median(int arr[], int n);

int getMedian(int *ar1, int *ar2, int n) {
    
    /* return -1 for  
       invalid input */
    if (n <= 0) 
        return -1; 
    if (n == 1) 
        return (ar1[0] + ar2[0]) / 2; 
    if (n == 2) 
        return (max(ar1[0], ar2[0]) +  min(ar1[1], ar2[1]));
  
    /* get the median of the first array */
    int m1 = median(ar1, n);  
      
    /* get the median of the second array */
    int m2 = median(ar2, n);  
  
    /* If medians are equal then return either m1 or m2 */
    if (m1 == m2) 
        return 2*m1; 
  
    /* if m1 < m2 then median must exist in ar1[m1....] and ar2[....m2] */
    if (m1 < m2) { 
        if (n % 2 == 0) 
            return getMedian(ar1 + n / 2 - 1, ar2, n - n / 2 + 1); 
        return getMedian(ar1 + n / 2, ar2, n - n / 2); 
    } 
  
    /* if m1 > m2 then median must exist in ar1[....m1] and ar2[m2...] */
    if (n % 2 == 0) 
        return getMedian(ar2 + n / 2 - 1, ar1, n - n / 2 + 1); 
    return getMedian(ar2 + n / 2, ar1, n - n / 2); 
} 
  
/* Function to get median  
   of a sorted array */
int median(int arr[], int n) { 
    if (n % 2 == 0) 
        return (arr[n / 2] +  
                arr[n / 2 - 1]) / 2; 
    else
        return arr[n / 2]; 
} 


int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ar1[n], ar2[n];
        loop(i,0,n) cin >> ar1[i];
        loop(i,0,n) cin >> ar2[i];
        
        cout << getMedian(ar1, ar2, n) << endl;
    }
}