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
        string s;
        cin >> s;
        int k,n;
        char c;
        cin >> k >> n;
        cin >> c;

        // cout << n << k << c << endl;

        int arr[26] = {0};

        ll int repeat = n/s.size();
        // cout << repeat << endl;

        loop(i, 0, s.size()){
            arr[s[i] - 'A']++;
            // cout << s[i]-'A' << " ";
        }

        ll int count = repeat*arr[c-'A'];
        // cout << count << " ";

        loop(i, 0, n-repeat*s.size()){
            if(s[i] == c){
                count++;
            }
        }
        cout << count << endl;
    }
}