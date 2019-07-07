#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)

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
        string s;
        cin>> s;
        
        int k; 
        cin >> k;
        
        if(k >= s.size()){
            cout << 0 << endl;
            continue;
        }
        
        int pairs[26] = {0};
        
        loop(i, 0, s.size()){
            pairs[s[i] - 'a']++;
        }
        
        sort(pairs, pairs+26, greater<int>());
        
        while(k != 0){
            int max = pairs[0];
            int max_index = 0;
            loop(i, 1, 26){
                if(max < pairs[i]){
                    max = pairs[i];
                    max_index = i;
                }
            }
            
            k--;
            pairs[max_index]--;
        }
        
        ll count = 0;
        loop(i, 0, 26){
            count += pairs[i]*pairs[i];
        }
        cout << count << endl;
    }
}