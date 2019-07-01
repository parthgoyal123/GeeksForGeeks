#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for(long long i=a; i<b; i++)
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;

	while (t--){
	    int n, s;
	    cin >> n >> s;
	    vector<int> arr(n);
	    for (int i = 0; i<n; i++){
	        cin >> arr[i];
	    }
	    
	    int sum = 0;
	    int start = 0;
	    int flag = 0;
		
	    for(int j=0;j<n;j++){
	        if(sum<s){
	            sum += arr[j];
	            if (sum == s){
    	            cout << start+1 << " " << j+1 << endl;
    	            flag = 1;
    	            break;
    	        }
	        }
	        while(sum>s && start < j+1){
	            sum -= arr[start];
	            start++;
	            if (sum == s){
    	            cout << start+1 << " " << j+1 << endl;
    	            flag = 1;
    	            break;
    	        }
	        }
	        
    	        
	    }
	    if (flag == 0){
	        cout << -1 << endl;
	    }
	    
	}
	return 0;
}