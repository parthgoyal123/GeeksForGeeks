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
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        ll int arr[n1], brr[n2], crr[n3];
        lloop(i,0,n1) cin >> arr[i];
        lloop(i,0,n2) cin >> brr[i];
        lloop(i,0,n3) cin >> crr[i];
        
        int i1 = 0, i2 = 0;
        ll int temp = INT64_MIN;
        while(i1 < n1 && i2 < n2) {
            if(temp != arr[i1] && arr[i1] == brr[i2]) {
                bool present = binary_search(crr, crr+n3, arr[i1]);
                if(present) {
                    cout << arr[i1] << " ";
                    temp = arr[i1];
                }
                i1++; i2++;
            } else if((arr[i1] > brr[i2]) || (temp == brr[i2])) {
                i2++;
            } else if((arr[i1] < brr[i2]) || (temp == arr[i1])) {
                i1++;
            }
        }
        if(temp == INT64_MIN) cout << -1;
        cout << endl;
    }
}