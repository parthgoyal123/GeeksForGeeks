// A C++ program to find if there is a given sum
// subarray
#include <bits/stdc++.h>
using namespace std;
int subArraySum(int arr[], int n, int sum);
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, sum;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
        cin >> sum;
		cout << subArraySum(arr, n, sum) << endl;
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//Complete this function
int subArraySum(int arr[], int n, int sum)
{
    int count = 0;
    unordered_map<int, int> hash;
    // hash[arr[0]] = 1;
    int curr_sum = 0;
    for(int i=0; i<n; i++){
        curr_sum += arr[i];
        // cout << curr_sum << endl;
        if(curr_sum == sum){
            // cout << "Index1 : " << i << endl;
            count++;
        }
        if (hash.find(curr_sum - sum) != hash.end()){
            // cout << "Index : " << i << endl;
            count += hash[curr_sum-sum];
        }
        hash[curr_sum]++;
    }
    return count;
}

    // sort(arr, arr+n);

    // for(int i=0; i<n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // for (int j = 0; j < n-1; j++)
    // {
    //     if(arr[j] == arr[j+1]){
    //         return true;
    //     }
    //     if (arr[j] ==0 || arr[j+1] == 0){
    //         return true;
    //     }
    // }
    // return false;
    

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