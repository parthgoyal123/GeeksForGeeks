#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

struct point{
    int x;
    int y;
    point(int x, int y){
        this->x = x;
        this->y = y;
    }
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
        int a,b;
        cin >> a >> b;
        point l1(a,b);
        cin >> a >> b;
        point r1(a, b);
        cin >> a >> b;
        point l2(a,b);
        cin >> a >> b;
        point r2(a, b);

        if(overlap(l1,r1,l2,r2)){
            cout << 1 << endl;
        } else{
            cout << 0 << endl;
        }
    }
}