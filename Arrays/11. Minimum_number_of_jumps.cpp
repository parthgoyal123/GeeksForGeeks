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

int getMinNumberOfJumps(int *arr, int n) {
    if(arr[0] == 0) return -1;
    if(n == 1) return 1;
    
    int curr_index;
    int count = 0;
    int i = 0;
    
    while(i < n-1) {
        int jump = arr[i];
        if(jump == 0) return -1;
        
        count++;
        
        int maxx = INT_MIN;
        curr_index = i;
        int max_index;
        
        while(curr_index < n && jump--) {
            curr_index++;
            if(curr_index == n-1) return count;
            
            int jumps = arr[curr_index];
            
            if(curr_index + jumps > maxx) {
                maxx = curr_index + jumps;
                max_index = curr_index;
            }
        }
        
        if(curr_index == n-1) return count;
        
        i = max_index;
    }
    
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        loop(i,0,n) cin >> arr[i];
        
        cout << getMinNumberOfJumps(arr, n) << endl;
    }
}