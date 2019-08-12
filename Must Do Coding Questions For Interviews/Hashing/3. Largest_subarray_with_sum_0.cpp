#include<bits/stdc++.h>
using namespace std;
int maxLen(int A[],int n);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        cout<<maxLen(A,N)<<endl;
    }
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this function*/

#define loop(i,a,b) for(int i = a; i<b; i++)
#define ll long long int

int maxLen(int *arr, int n) {
    
    // some base conditions
    if(n <= 0) return 0;
    if(n == 1 && arr[0] == 0) return 1;
    if(n == 1 && arr[0] != 0) return 0; 
    
    // make a hash table
    unordered_map<long long int, int> hash;
    
    int max_len = 0;
    
    long long curr_sum = 0;
    
    loop(i,0,n) {
        curr_sum += (ll)arr[i];
        
        // if the sum of elements from start to i is 0 then this is the largest subarray    
        if(curr_sum == 0) {
            max_len = i+1;
        } 
        
        // else if the curr_sum already exists somewhere in the map, then from that index to current index 
        else if (hash.find(curr_sum) != hash.end()) {
            max_len = max(max_len, i - hash[curr_sum]);
        } 
        
        // if not found in the map, add the curr_sum to the map
        else {
            hash[curr_sum] = i;
        }
    }
    
    return max_len;
}
