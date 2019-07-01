#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

int* SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    int *primes = new int[1000000];
    memset(primes, 0, 1000000);
    int index = 0;
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
           primes[index++] = p;
    return primes;
} 

int main(){
    int t;
    cin >> t;
    int *primes = SieveOfEratosthenes(1000000);
    // loop(i,0,1000000){
    //     cout << primes[]
    // }
    while(t--){
        ll int n;
        cin >> n;
        // cout << n;
        // numbers less than n now
        
        ll int k = sqrt(n);
        // cout << k << endl;
        int count = 0;
        
        while(primes[count] && k>=primes[count]){
            count++;
        }
        
        cout << count << endl;
        
    }
}