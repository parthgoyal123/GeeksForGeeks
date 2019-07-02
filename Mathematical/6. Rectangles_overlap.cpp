#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

struct point{
    int x;
    int y;
};

bool overlap(point l1, point r1, point l2, point r2){
    if(r1.x < l2.x || r2.x < l1.x){
        return false;
    }

    if(r2.y  > l1.y || r1.y > l2.y){
        return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        point points[4];
        loop(i,0,4){
            int a,b;
            cin >> a >> b;
            points[i].x = a;
            points[i].y = b;   
        }

        if(overlap(points[0],points[1],points[2],points[3])){
            cout << 1 << endl;
        } else{
            cout << 0 << endl;
        }
    }
}