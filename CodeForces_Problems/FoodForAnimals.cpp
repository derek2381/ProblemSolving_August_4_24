// problem link
// https://codeforces.com/contest/1675/problem/A


#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int a, b, c, x, y;
        
        cin >> a >> b >> c >> x >> y;
        long long int req1 = x - a,req2;
        if(req1 < 0){
            req1 = 0;
        }
        
        req2 = y - b;
        
        if(req2 < 0){
            req2 = 0;
        }
        
        if(req1+req2 <= c){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
        
    }
}