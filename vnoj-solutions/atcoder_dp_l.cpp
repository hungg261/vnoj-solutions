#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=3000;
int n,a[MAXN+1],dp[MAXN+1][MAXN+1];

void solve(){
    for(int i=1;i<=n;++i){
        dp[i][i]=a[i];
    }

    for(int len=2;len<=n;++len){
        for(int i=1;i<=n-len+1;++i){
            int j=i+len-1;

            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }

    cout<<dp[1][n]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    solve();
    return 0;
}
