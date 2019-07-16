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

int getLongestSubarrayWithAverageGreaterThanK(int *arr, int n, int key) {
    if(n <= 0) return 0;
    if(n == 1 && arr[0] >= key) return 1;
    if(n == 2 && arr[0] < key) return 0; 

    int curr_sum = 0;
    int curr_len = 0;
    int maxx = 0;
    int max_len = 0;

    loop(i,0,n) {
        curr_sum += arr[i];
        curr_len++;

        if(curr_sum > maxx && curr_sum/curr_len >= key && curr_len >= max_len) {
            maxx = curr_sum;
            max_len = curr_len;
        }

        if(curr_sum < 0) {
            curr_sum = 0;
            curr_len = 0;
        } 
    }

    return max_len;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        int key; cin >> key;

        cout << getLongestSubarrayWithAverageGreaterThanK(arr, n, key) << endl;
    }
}