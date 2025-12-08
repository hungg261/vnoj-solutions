#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6;
int pi[MAXN*2+1];

void solve(string a,string b){
    string s=b+'#'+a;
    int length_b=b.size();
    int n=s.size();
    
    pi[0]=0;
    for(int i=1;i<n;++i){
        int j=pi[i-1];
        while(j>0&&s[j]!=s[i]){
            j=pi[j-1];
        }
        if(s[j]==s[i]){
            ++j;
        }
        
        if(j==length_b){
            cout<<i-length_b*2+1<<' ';
        }
        pi[i]=j;
    }
    cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string a,b;
    cin>>a>>b;
    
    solve(a,b);
    return 0;
}
