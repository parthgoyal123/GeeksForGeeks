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
        pair<int, int> points[4];

        loop(i,0,4){
            int a,b;
            cin >> a >> b;
            points[i] = make_pair(a,b); 
        }
        sort(points, points + 4);
        int flag = 0;
        loop(i,0,3){
            if((points[i].first == points[i+1].first) && (points[i].second == points[i+1].second)){
                cout << "No" << endl;
                flag = 1;
                break;
            }
        }
        if(flag){
            continue;
        }
        if((points[0].first != points[1].first) || (points[2].first != points[3].first) || (abs(points[0].second - points[1].second) != abs(points[2].second - points[3].second))){   
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
}