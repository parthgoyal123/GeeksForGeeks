#include<bits/stdc++.h>
using namespace std;
struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump [],int );
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }

}
/*This is a function problem.You only need to complete the function given below*/
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/
/*You are required to complete this method*/
int tour(petrolPump arr[],int n) {
    
    // curr_petrol left on truck
    int curr_petrol = 0;
    
    // make variables for start and end of tour
    int start = 0, end = 1;
    
    curr_petrol = arr[start].petrol - arr[start].distance;
    
    // loop until the tour is not completed
    while(end != start || curr_petrol < 0) {
        
        // if petrol becomes negative, deque from front
        while(curr_petrol < 0 && start != end) {
            curr_petrol = curr_petrol - arr[start].petrol + arr[start].distance;
            start = (start+1) % n;
            
            // if start is being considered again, (tour not possible)
            if(start == 0) return -1;
        }
        
        
        // Add a petrol pump to current tour  
        curr_petrol += arr[end].petrol - arr[end].distance;  
  
        end = (end + 1) % n;
    }
    
    return start;
}
