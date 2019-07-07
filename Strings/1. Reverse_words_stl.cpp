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

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        int d_prev=0;
        int d = 0;
        loop(i,0,s.size()){
            if(s[i] == '.'){
                d = i;
                reverse(s.begin()+d_prev, s.begin()+d);
                d_prev = d+1;
            }
        }
        reverse(s.begin() + d_prev, s.end());
        reverse(s.begin(), s.end());
        
        cout << s << endl;
    }
}