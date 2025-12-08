#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXVAL=2e10;
int f[100],len=0;

void compute(){
    f[0]=0,f[1]=1;
    for(int i=2;;++i){
        f[i]=f[i-1]+f[i-2];
        if(f[i]>MAXVAL){
            len=i;
            break;
        }
    }
}

void solve(int a,int b){
    cout<<upper_bound(f,f+len+1,b)-lower_bound(f,f+len+1,a)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int A,B;
    cin>>A>>B;
    
    compute();
    solve(A,B);
    return 0;
}
