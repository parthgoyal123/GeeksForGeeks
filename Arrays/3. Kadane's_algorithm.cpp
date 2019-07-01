#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for(long long i=a; i<b; i++)
#define ll long long

int getMaxSubArray(vector<int> arr, int index, int maxAtPreviousIndex){
    return max(arr[index], maxAtPreviousIndex + arr[index]);
}

int main() {
	// ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        loop(i, 0, n){
            cin >> arr[i];
        }

        int sum = 0;
        int previous_index_max = 0;
        ll int max_sum = arr[0];
        loop(i,0,n){
            int iIndexMax = getMaxSubArray(arr, i, previous_index_max);
            previous_index_max = iIndexMax;
            cout << previous_index_max << " ";
            if(iIndexMax > max_sum){
                max_sum = iIndexMax;
            }
        }

        cout << endl << max_sum << endl;
    }
}