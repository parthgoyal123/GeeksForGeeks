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

int exists(int *arr, int n, int k){
    unordered_map<int, int> hash;
    ll curr_sum = 0;
    ll sum = k;
    int max = INT_MIN;
    loop(i,0,n){
        curr_sum += arr[i];
        // cout << "curr_sum : " << curr_sum << " ";
        
        if(curr_sum == sum){
            if(max < i+1){
                max = i+1;
            }
            if(hash.find(curr_sum) == hash.end()){
                hash[curr_sum] = i;
            }
        }
        else{
            if(hash.find(curr_sum - sum) != hash.end()){
                // cout << "i : " << i << " ";
                
                if(i - hash[curr_sum - sum] +1 > max){
                    max = i-hash[curr_sum-sum];
                }
            }
            
            if(hash.find(curr_sum) == hash.end()){
                hash[curr_sum] = i;
            }
        }
            
    }
    if(max == INT_MIN){
        return 0;
    }
    return max;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n];
        
        loop(i,0,n){
            cin >> arr[i];
        }
        cout << exists(arr, n, k) << endl;
    
    }
}