#include <bits/stdc++.h>
using namespace std;
void printDuplicates(int arr[], int n);
int main()
{
  int t;
  cin>>t;
  while(t-- > 0){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		printDuplicates(a, n);
		cout<<endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below*/
void printDuplicates(int arr[], int n){
    
    // indication that some element is repeated
    bool flag = 0;
    
    // traverse through all elements
    for(int i = 0; i<n; i++) {
        
        int index = arr[i] % n;
        
        // check if the number is greater than n or less
        if(arr[index] >= n) {
            
            // if the num is less than equal to 2*n, that means repeated once
            if(arr[index] < 2*n) {
                cout << (arr[i]%n) << " ";
                flag = 1;
            }
        }   

        // add n to arr[index]
        arr[index] += n;
    }
    
    if(!flag) cout << -1;
}