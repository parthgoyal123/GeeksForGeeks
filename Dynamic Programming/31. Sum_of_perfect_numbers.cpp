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

template <typename T>
void printArray(T arr[], int n){
    loop(i,0,n){
        cout << "i:" << i << " " << arr[i] << "   ";
    } cout << endl;
}

bool isPowerOfK(int i, int k) {
    // intially guessing a random number between 
    // 0 and 9 
    double xPre = rand() % 10; 
  
    //  smaller eps, denotes more accuracy 
    double eps = 1e-3; 
  
    // initializing difference between two 
    // roots by INT_MAX 
    double delX = INT_MAX; 
  
    //  xK denotes current value of x 
    double xK; 
  
    //  loop untill we reach desired accuracy 
    while (delX > eps) 
    { 
        //  calculating current value from previous 
        // value by newton's method 
        xK = ((k - 1.0) * xPre + 
              (double)i/pow(xPre, k-1)) / (double)k; 
        delX = abs(xK - xPre); 
        xPre = xK; 
    } 
    
    int temp = xK;
    return (pow(temp, k) == i);
}

int sumOfPowerOfNaturalNumbers(int x, int k) {
    int dp[x+1] = {0};
    dp[1] = 1;
    
    loop(i,2,x+1) {
        if(isPowerOfK(i, k)) {
            dp[i] = 1;
            cout << "i:" << i << endl;
        }
        
        for(int j = 1; pow(j, k) < i; j++) {
            if(dp[j] != 0 && i-j != j && dp[i-j] != 0 && isPowerOfK(i-j, k)) {
                dp[i] += 1;
            }
        }
    }
    
    printArray(dp, x+1);
    
    return dp[x];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, n;
        cin >> x >> n;
        
        cout << sumOfPowerOfNaturalNumbers(x, n) << endl;
        
    }
}