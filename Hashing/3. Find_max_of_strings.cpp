#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;
void winner(string arr[],int n);
int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        
        winner(arr,n);
        
        cout<<endl;
        
        
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
// Funtion to find winner
// arr[]: input array
// n: size of array
void winner(string arr[],int n)
{
    unordered_map<string, int> hash;

    string answer;
    int index = 0;
    int max_number = 0;
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
        if(hash[arr[i]] > max_number){
            max_number = hash[arr[i]];
            index = i;
            answer = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(hash[arr[i]] == max_number){
            if(arr[i] < answer){
                answer = arr[i];
            }
        }
    }
    

    cout << answer << " " << max_number;
    
}