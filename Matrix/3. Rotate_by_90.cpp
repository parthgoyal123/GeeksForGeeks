#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)

template <typename T>
void printArray(T **arr, int n){
    loop(j, 0, n) {    
        loop(i,0,n){
            cout << arr[j][i] << " ";
        }
    } cout << endl;
}

void transposeMatrix(int **arr, int n){
    loop(i, 0, n){
        loop(j, i+1, n){
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void reverseColumns(int **arr, int n){
    loop(i, 0, n){
        loop(j, 0, n/2){
            swap(arr[j][i], arr[n-j-1][i]);
        }
    }
}

void rotateMatrix(int **arr, int n){
    
    transposeMatrix(arr, n);
    reverseColumns(arr, n);
    printArray(arr, n);
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int **arr;
        arr = new int*[n];
        loop(i,0,n){
            arr[i] = new int[n];
        }
        loop(i,0,n){
            loop(j,0,n){
                cin >> arr[i][j];   
            }
        }
        rotateMatrix(arr, n);
        delete arr;
    }
}