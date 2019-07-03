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
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n][n];
        loop(i,0,n){
            loop(j,0,n){
                cin >> arr[i][j];    
            }
        }
        
        // loop(i,0,n){
        //     printArray(arr[i],n);
        // } cout << endl;
        
        loop(i,0,n){
            loop(j,i,n){
                int temp1 = arr[i][j];
                int temp2 = arr[j][i];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp1;
                // cout << temp1 << " " << temp2 << " ";
                
                // swap((int*)arr[i][j], (int*)arr[j][i]);
            }
        }
        
        loop(i, 0, n){
            printArray(arr[i], n);
        } cout << endl;
    }
}