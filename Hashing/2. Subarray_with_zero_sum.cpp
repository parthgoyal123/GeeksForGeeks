// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n);
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//Complete this function
bool subArrayExists(int arr[], int n)
{

    for(int i=1; i<n; i++){
        arr[i] = arr[i] + arr[i-1];
    }

    sort(arr, arr+n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int j = 0; j < n-1; j++)
    {
        if(arr[j] == arr[j+1]){
            return true;
        }
        if (arr[j] ==0 || arr[j+1] == 0){
            return true;
        }
    }
    return false;
    

    // int sum = 0;
    // int start = 0;
    // int flag = 0;

    // cout << s << endl;
    
    // for(int j=0;j<n;j++){
    //     if(sum<s){
    //         sum += arr[j];
    //         if (sum == s){
    //             return true;
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     while(sum>s && start < j+1){
    //         sum -= arr[start];
    //         start++;
    //         if (sum == s){
    //             return true;
    //             flag = 1;
    //             break;
    //         }
    //     }
        
            
    // }
    // if (flag == 0){
    //     return false;
    // }
}