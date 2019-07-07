#include <bits/stdc++.h>
using namespace std;
void convertToRoman(int ) ;
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		
	convertToRoman(N);
	cout<<endl;
		
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*you are required to complete 
this function*/
void convertToRoman(int n) 
{
    string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    int i = 0;
    while( n > 0) {
        int divisor = n/num[i];
        n = n%num[i];
        
        while(divisor--) {
            cout << sym[i];
        }
        i++;
    }
}