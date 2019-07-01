#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        ll arr[n];
        ll ans[n];
        pair<ll int, ll int> pairs[n];
        lloop(i,0,n){
            cin >> arr[i];
            pairs[i] = make_pair(arr[i], i);
        }

        stack<pair<ll int, ll int>> st;

        lloop(i,0,n){
            if(st.empty()){
                st.push(pairs[i]);
            } else {
                while(!(st.empty()) && (st.top().first < pairs[i].first)){
                    pair<ll int,ll int> x = st.top();
                    st.pop();

                    ans[x.second] = pairs[i].first;

                }
                st.push(pairs[i]);
            }
        }

        while(!st.empty()){
            pair<ll int, ll int> x = st.top();
            st.pop();    
            ans[x.second] = -1;
        }

        lloop(i,0,n){
            cout << ans[i] << " ";
        }
        cout << endl;

    }

}