#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

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

        int left = 0;
        int right = n-1;

        while(left<right){
            while(arr[left] == 0){
                left++;
            }
            while(arr[right] == 1){
                right--;
            }
            if(left<right){
                arr[left] = 0;
                arr[right] = 1;
                left++;
                right--;
            }
        }
        
        loop(i,0,n){
            cout << arr[i] << " ";
        }
        cout << endl;

        // ======== METHOD 2 ========== //
        // int one = 0, zero = 0;
        // loop(i,0,n){
        //     cin >> arr[i];
        //     if(arr[i] == 0){
        //         zero++;
        //     } else if(arr[i] == 1){
        //         one++;
        //     }
        // }
        
        // loop(i,0,zero){
        //     arr[i] = 0;
        //     cout << 0 << " ";
        // }
        // loop(i,zero,n){
        //     arr[i] = 1;
        //     cout << 1 << " ";
        // }
        // cout << endl;
    }
}
