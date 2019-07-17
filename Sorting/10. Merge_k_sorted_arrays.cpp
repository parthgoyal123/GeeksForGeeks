#include<bits/stdc++.h>
#define N 100
using namespace std;
int *mergeKArrays(int arr[][N],int k);
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k

typedef pair<int, pair<int, int>> ppi;

int *mergeKArrays(int arr[][N], int k) {
    int *out = new int[k*k];
    memset(out, 0, sizeof(out));
    int index = 0;
    
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    
    for(int i = 0; i<k; i++) {
        pq.push({arr[i][0], {i, 0}});
    }
    
    while(!pq.empty()) {
        ppi top = pq.top();
        pq.pop();
        
        int i = top.second.first;
        int j = top.second.second;
        
        out[index++] = top.first;
        
        if(j + 1 < k) {
            pq.push({arr[i][j+1], {i, j+1}});
        }
    }
    
    return out;
}