#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define pb push_back

int naive_method(vector<int> *arr){
    int max = 0;
    loop(i,0, arr->size()-1){
        if(abs((*arr)[i] - (*arr)[i+1]) > max){
            max = abs((*arr)[i] - (*arr)[i+1]);
        }
    }
    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int min = INT_MAX;
        int max = INT_MIN;

        //* USING PIGEONHOLE SORTING
        loop(i,0,n){
            cin >> arr[i];
            if(max < arr[i]){
                max = arr[i];
            }
            if(min > arr[i]){
                min = arr[i];
            }
        }

        int range = max-min+1;
        vector<int> num[range];

        loop(i,0,n){
            num[arr[i]-min].pb(arr[i]);
        }

        int index = 0;
        loop(i,0,range){
            vector<int>::iterator it; 
            for (it = num[i].begin(); it != num[i].end(); ++it) 
                arr[index++]  = *it;
        }

        // loop(i,0,n){
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        int max1 = 0;
        loop(i,0, arr.size()-1){
            if(abs(arr[i] - arr[i+1]) > max1){
                max1 = abs(arr[i] - arr[i+1]);
            }
        }

        // now we have sorted arr;
        cout << max1 << endl;


        //! NEVER COPY VECTOR (Use Pointer OR REFERENCE)
        // sort(arr.begin(), arr.end());
        //* cout << naive_method(&arr) << endl;


    }
}