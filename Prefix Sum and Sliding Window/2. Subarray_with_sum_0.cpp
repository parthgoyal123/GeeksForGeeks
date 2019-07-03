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

bool exits(int *arr, int n){
    unordered_map<int, int> hash;
    ll curr_sum = 0;
    loop(i,0,n){
        curr_sum += arr[i];
        // cout << "curr_sum : " << curr_sum << " ";
        
        if(curr_sum == 0 || hash.find(curr_sum) != hash.end()){
            // cout << "i : " << i << " ";
            return true;
        }
        hash[curr_sum]++;
        if(hash[curr_sum] > 1){
            // cout << "i : " << i << " 11111 ";
            return true;
        }
    }
    return false;
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
        if(exits(arr, n)){
            cout << "Yes";
        }else{
            cout << "No";
        } cout << endl;
    
    }
}