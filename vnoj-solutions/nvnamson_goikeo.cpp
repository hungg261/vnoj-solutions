#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX=5000;
int dp[2][MAX+1],n,a[MAX+1],b[MAX+1];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        b[i]=a[i];
    }
    
    sort(b+1,b+n+1);
    for(int i=1;i<=n;++i)dp[0][i]=dp[0][i-1]+abs(a[i]-b[1]);
    for(int j=2;j<=n;++j){
        for(int i=1;i<=n;++i){
            dp[1][i]=min(dp[0][i],dp[1][i-1]+abs(a[i]-b[j]));
        }
        memcpy(dp[0],dp[1],sizeof(dp[1]));
    }
    
    cout<<dp[1][n]<<'\n';
    return 0;
}
