#include<bits/stdc++.h>
using namespace std;
#define MAX 501
int getId(int M[MAX][MAX],int n);
int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
// The task is to complete this function
// M[][]: input matrix
// n: size of matrix (n*n)

int haveAcquitance(int M[MAX][MAX], int i, int j, int n) {
    return (M[i][j] == 1)? j:i;
}

bool checkCelebrity(int M[MAX][MAX], int id, int n) {
    for(int i =0; i<n; i++){
        if(i == id) continue;
        if(M[id][i] == 1) return false;
    }
    
    for(int i =0; i<n; i++) {
        if(i == id) continue;
        
        if(M[i][id] != 1) return false;
    }
    return true;
}

int getId(int M[MAX][MAX], int n){
    stack<int> s;
    for(int i = 0; i<n; i++){
        s.push(i);
    }
    
    while(s.size() > 1) {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        
        s.push(haveAcquitance(M,i,j,n));
    }
    int id = s.top();
    s.pop();
    
    bool check = checkCelebrity(M, id, n);
    
    return (check)? id: -1;
}