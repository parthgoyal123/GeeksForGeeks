#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i<b; i++)
#define lloop(i,a,b) for (long long int = a; i<b; i++)
#define ll long long
#define MODULO 1000000007
#define pb push_back

void countJumpingNumbers(ll int n){
	set<ll int> numbers;
	queue<ll int> q;
	for(int i = 0; i<=9 && i<=n; i++){
		q.push(i);

		while(!q.empty()){
			ll x = q.front();
			numbers.insert(x);
			int last_digit = x%10;
			q.pop();
			if(x <= n){
				switch(last_digit){
					case 0: {
						x = 10*x + (last_digit + 1);
						if(x <= n){
							q.push(x);
						}
						break;
					}
					case 9: {
						x = 10*x + (last_digit - 1);
						if(x <= n){
							q.push(x);
							break;
						}
					}

					default:{
						ll left = 10*x + (last_digit-1);
						x = 10*x + (last_digit + 1);

						if(left <= n){
							q.push(left);
						}
						if(x <=n){
							q.push(x);
						}
					}
				}
			}
		}
	}

	for(auto it = numbers.begin(); it!= numbers.end(); it++){
		cout << *it << " ";
	} cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ll int n;
		cin >> n;
		countJumpingNumbers(n); 
	}
}