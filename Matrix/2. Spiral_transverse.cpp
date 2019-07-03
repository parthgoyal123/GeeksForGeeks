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

void printSpiral(int *arr, int start, int m, int n, int m_act, int n_act){
    
    int count = 0, pre_count = 0;
    
    loop(j, start, n){
        cout << "j: " << j << " ";
        cout << *((arr+start*n_act) + j) << " ";
        count++;
    } cout << endl;
    if(pre_count != count){
        pre_count = count;
        loop(i, start+1, m){
            cout << "i: " << i << " ";
            cout << *((arr + n_act*i) + (n-1)) << " ";
            count++;
        } cout << endl;
        if(pre_count != count){
            pre_count = count;
            for(int j = n-2; j>= start; j--){
                cout << "j: " << j << " ";
                cout << *((arr + n_act*(m-1)) + j) << " ";
                count++;
            } cout << endl;
            if(pre_count != count){
                pre_count = count;
                for (int i = m-2; i>start; i--){
                    cout << "i: " << i << " ";
                    cout << *((arr + n_act*i) + start) << " ";
                    count++;
                } cout << endl;
                if(pre_count != count){
                    start = start + 1;
                    m = m_act - start;
                    n = n_act - start;
                    printSpiral((int*) arr, start, m,n, m_act, n_act);
                } else{
                    return;
                }
            } else{
                return;
            }
            
        } else{
            return;
        }
    }
    return;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >>m >> n;
        int arr[m][n];
        loop(i,0,m){
            loop(j,0,n){
                cin >> arr[i][j];    
            }
        }
        printSpiral((int*)arr, 0, m, n, m, n);
    }
}