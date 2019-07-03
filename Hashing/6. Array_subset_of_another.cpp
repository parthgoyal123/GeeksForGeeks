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
        int n, m;
        cin >> n >> m;
        unordered_map<int, int> hash;
        int arr1[n], arr2[m];
        loop(i,0,n){
            cin >> arr1[i];
            hash[arr1[i]] = 1;
        } 
        int flag = 0;
        loop(i,0,m){
            cin >> arr2[m];
            if(hash[arr2[m]] != 1){
                flag = 1;
            }
        }
        if(flag){
            cout << "No";
        } else
        {
            cout << "Yes";
        } cout << endl;
        


        // int flag = 0;
        // for(auto it = hash.begin(); it != hash.end(); it++){
        //     if((it->first) < 0){
        //         cout << "No" << endl;
        //         flag = 1;
        //         break;
        //     }
        // }
        // if(!flag)
        //     cout << "Yes" << endl;


    }
}