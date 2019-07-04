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
        int n;
        cin >> n;
        int arr[n];
        int count[n];
        loop(i,0,n){
            cin >> arr[i];
        }
        
        count[0] = n;
        int answer = (n%2 == 0)? 0:arr[0];
        loop(i,1,n){
            count[i] = (count[i-1] - (i)) + (n-i);
            answer = (count[i]%2 == 0)? answer: answer^arr[i];
            // cout << count[i-1] << " " << count[i] << " " << answer << endl;
        }
        cout << answer << endl;
    }
}