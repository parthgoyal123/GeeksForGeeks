#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for(long long i=a; i<b; i++)
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        loop(i, 0, n){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        int count_triplets = 0;
        bool flag = false;

        // now we have a sorted array
        for(int i=n-1; i>=2; i--){
            int greatest = arr[i];
            
            int start = 0;
            int end = i-1;

            while(start<end){
                if(arr[start] + arr[end] == greatest){
                    count_triplets++;
                    flag = true;
                    start++;
                    end--;
                } else if (arr[start] + arr[end] > greatest){
                    end--;
                } else if(arr[start] + arr[end] < greatest){
                    start++;
                }
            }
        }
        if(!flag){
            cout << -1 << endl;
        } else{
            cout << count_triplets << endl;
        }

    }
}