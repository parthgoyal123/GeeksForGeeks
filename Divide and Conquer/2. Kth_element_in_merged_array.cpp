#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int merge(int *arr, int m, int *brr, int n, int k){
    int l1 = 0;
    int l2 = 0;
    int r1 = m;
    int r2 = n;
    int index = 0;
    
    while(l1 < r1 && l2 < r2){
        if(arr[l1] < brr[l2]){
            l1++;
            index++;
            if(index == k){
                return arr[l1-1];
            }
        } else if (arr[l1] > brr[l2]){
            l2++;
            index++;
            if(index == k){
                return brr[l2-1];
            }
        } else{
            l1++;
            l2++;
            index++;
            if(index == k){
                return arr[l1-1];
            }
            index++;
            if(index == k){
                return arr[l1-1];
            }
        }
    }
    
    while(l1 < r1){
        index++;
        if(index == k){
            return arr[l1];
        }
        l1++;
    }
    while(l2 < r2){
        index++;
        if(index == k){
            return brr[l2];
        }
        l2++;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> m >> n >> k;
        int arr[m];
        int brr[n];
        loop(i,0,m){
            cin >> arr[i];
        }
        loop(i,0,n){
            cin >> brr[i];
        }
        
        int element = merge(arr, m, brr, n, k);
        cout << element << endl;
    }
}