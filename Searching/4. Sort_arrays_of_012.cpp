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

        // Method 1 (Important)

        int low = 0;
        int mid = 0;
        int end = n-1;

        while(mid <= end){
            switch(arr[mid]){
                case 0:{
                    swap(arr[low++], arr[mid++]);
                    break;
                }
                case 1:{
                    mid++;
                    break;
                }
                case 2:{
                    swap(arr[mid], arr[end--]);
                    break;
                }
            }
        }

        loop(i,0,n){
            cout << arr[i] << " ";
        } cout << endl;
    }
}
        // ======== METHOD 2 ========== //
        // int one = 0, zero = 0, two = 0;
        // loop(i,0,n){
        //     cin >> arr[i];
        //     if(arr[i] == 0){
        //         zero++;
        //     } else if(arr[i] == 1){
        //         one++;
        //     } else{
        //         two++;
        //     }
        // }
        
        // loop(i,0,zero){
        //     arr[i] = 0;
        //     cout << 0 << " ";
        // }
        // loop(i,zero,zero+one){
        //     arr[i] = 1;
        //     cout << 1 << " ";
        // }
        // loop(i,zero+one, n){
        //     arr[i] = 2;
        //     cout << 2 << " ";
        // }
        // cout << endl;