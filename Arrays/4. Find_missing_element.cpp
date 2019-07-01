#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

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
        int arr[n-1];
        int sum = 0;
        int xor_array = 0;
        loop(i,0,n-1){
            cin >> arr[i];
            sum += arr[i];
            xor_array = xor_array^arr[i]^(i+1);
        }
        xor_array ^= n;
        cout << xor_array << endl;
    }
}