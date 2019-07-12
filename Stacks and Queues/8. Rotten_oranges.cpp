#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define md 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)
#define loopr(i,a,b) for(int i = a; i>=b; i--)
#define iterate(it, v) for (auto it = v.begin(); it!= v.end(); it++)
#define mk make_pair
#define pb push_back

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

struct Elem{
    int i;
    int j;
    Elem(int x, int y){
        this->i = x;
        this->j = y;
    }
};

bool operator==(const Elem &e1, const Elem &e2) {
    return ((e1.i == e2.i) && (e1.j == e2.j));
}

bool checkMatrix(int **arr, int r, int c) {
    loop(i,0,r){
        loop(j,0,c){
            if(arr[i][j] == 1) return false;
        }
    }
    return true;
}

bool isvalid(int i, int j, int r, int c) { 
    return (i >= 0 && j >= 0 && i <r && j < c); 
} 

int minTimeToRot(int **arr, int r, int c) {
    
    queue<Elem> q;
    
    loop(i,0,r){
        loop(j,0,c){
            if(arr[i][j] == 2) {
                Elem rotten(i, j);
                q.push(rotten);
            }
        }
    }
    
    Elem delimiter(-1,-1);
    q.push(delimiter);
    
    // see if the delimiter is the only Elem in the queue
    if(q.size() == 1) {
        return 0;
    }
    
    int total_time = -1;
    
    while(!q.empty()) {
        Elem top = q.front();
        // cout << "i:"<<top.i << " j:" << top.j << endl;
        q.pop();
        
        if(top == delimiter) {
            // cout << "Delimieter encountered\n";
            total_time++;
            if(q.empty()) {
                break;
            }
            q.push(delimiter);
            continue;
        }
        
        if(isvalid(top.i + 1, top.j, r, c) && arr[top.i + 1][top.j] == 1) {
            arr[top.i + 1][top.j] = 2;
            q.push(Elem(top.i + 1, top.j));
        }
        
        if(isvalid(top.i - 1, top.j, r, c) && arr[top.i - 1][top.j] == 1){
            arr[top.i - 1][top.j] = 2;
            q.push(Elem(top.i - 1, top.j));
        }
        
        if(isvalid(top.i, top.j + 1, r, c) && arr[top.i][top.j + 1] == 1) {
            arr[top.i][top.j + 1] = 2;
            q.push(Elem(top.i, top.j + 1));
        }
        
        if(isvalid(top.i, top.j - 1, r, c) && arr[top.i][top.j - 1] == 1) {
            arr[top.i][top.j - 1] = 2;
            q.push(Elem(top.i, top.j - 1));
        }
        
    }
    
    bool check = checkMatrix(arr, r, c);
    if(check) return total_time;
    else return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;
        int **arr = new int*[r];
        loop(i,0,r){
            arr[i] = new int[c];
        }
        loop(i,0,r){
            loop(j,0,c){
                cin >> arr[i][j];
            }
        }
        
        int count = minTimeToRot(arr, r, c);
        cout << count << endl;
    }
}