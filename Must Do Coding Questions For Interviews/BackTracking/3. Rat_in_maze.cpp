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
#define N 8

template <typename T>
void printArray(T *arr, int n){
    loop(i,0,n){
        cout << arr[i] << " ";
    } cout << endl;
}

template <typename T>
void printMatrix(T **arr, int n, int m){
    loop(i,0,n){
        loop(j,0,m) {
            printf(" %2d ", arr[i][j]);
        }
        printf("\n");
    } 
    printf("\n");
}

bool isSafeMove(int **arr, int x, int y) {
    
    // should not go outside square and should not already be filled
    if(x < 0 || x >= N || y < 0 || y >= N || arr[x][y] != -1) return false;
    return true;
}

bool solveKnightProblemUtil(int **arr, int x, int y, int *xMove, int *yMove, int curr_move) {

    // check the curr_move num
    if(curr_move == N*N) return true;

    int next_x, next_y;

    // loop for all possible next moves of knight
    for(int i = 0; i<N; i++) {

        // get next possible x and y
        next_x = x + xMove[i];
        next_y = y + yMove[i];

        // check the move is possible or not
        if(isSafeMove(arr, next_x, next_y)) {
            arr[next_x][next_y] = curr_move;

            // recur for next moves
            if(!solveKnightProblemUtil(arr, next_x, next_y, xMove, yMove, curr_move+1)) {
                arr[next_x][next_y] = -1;
            } else {
                return true;
            }
        }
    }

    // if no move was valid then return false;
    return false;
}

// solve the knight problem
bool solveKnightProblem() {

    // arr stores the visited nodes index
    int **arr = new int*[N];
    loop(i,0,N) arr[i] = new int[N];

    // initialize with -1 (not visited)
    loop(i,0,N) loop(j,0,N) arr[i][j] = -1;

    /* xMove[] and yMove[] define next move of Knight. 
       xMove[] is for next value of x coordinate 
       yMove[] is for next value of y coordinate */
    int xMove[8] = {2, 1, -1, -2, -2, -1,  1,  2}; 
    int yMove[8] = {1, 2,  2,  1, -1, -2, -2, -1};

    // since the knight is at first block initially
    arr[0][0] = 0;

    // start from 0,0 and explore all possible tours
    if (solveKnightProblemUtil(arr, 0, 0, xMove, yMove, 1)) {
        printMatrix(arr, N, N);
    } else {
        return false;
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    if(!solveKnightProblem()) {
        cout << "Solution Does Not Exist!\n";
    };
}