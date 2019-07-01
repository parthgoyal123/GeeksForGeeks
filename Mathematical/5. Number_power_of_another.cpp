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
        int x,y;
        cin >> x >> y;

        if(x == 1){
            if(y==1){
                cout << 1 << endl;
            } else{
                cout << 0 << endl;
            }
        }else{
                int count = 0;
            int temp = x;
            while(x < y){
                count++;
                x = x*temp;
            }
            if(x == y || y == 1){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        
    }
}