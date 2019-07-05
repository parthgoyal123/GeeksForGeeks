#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

ll countTriangles(int *arr, int n){
    ll count = 0;
    for(int i = 0; i<n-2; i++){
        int k = i+2;
        int temp = i;
        loop(j, i+1, n){
            if(temp )
            while(k<n && (arr[i] + arr[j] > arr[k])){
                k++;
            }

            count += k-j-1;
        }
    }

    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n){
            cin >> arr[i];
        }

        sort(arr, arr+n);

        ll count = countTriangles(arr, n);
        cout << count << endl;
    }
}