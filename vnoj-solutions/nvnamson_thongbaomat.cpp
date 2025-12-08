#include<bits/stdc++.h>
#define int long long
using namespace std;

string DecToBits(int n){
    string s;
    while(n>0){
        s+=n%2 +'0';
        n/=2;
    }
    while(s.size()<4)s+='0';
    reverse(begin(s),end(s));
    
    return s;
}

int charHex(char k){
    if('0'<=k&&k<='9'){
        return k-'0';
    }
    else return 10+k-'A';
}

string decode(string s){
    string res;
    for(char i:s)res+=DecToBits(charHex(i));
    
    return res;
}

// KMP
vector<int>LPS(string A){
    int m=A.length();
    vector<int> lps(m,0);
    int j=0;

    for(int i=1;i<m;++i){
        while(j>0&&A[i]!=A[j])j=lps[j-1];
        if(A[i]==A[j])++j;
        
        lps[i]=j;
    }

    return lps;
}

void solve(string A,string B){
    vector<int> lps=LPS(A);
    int n=B.length(),m=A.length();
    int i=0,j=0,ans=0;

    while(i<n){
        if(A[j]==B[i]){
            ++i;
            ++j;
        }
        if(j==m){
            ++ans;
            j=lps[j-1];
        }
        else if(i<n&&A[j]!=B[i]){
            if(j!=0) j=lps[j-1];
            else ++i;
        }
    }
    
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string A,B;
    cin>>A>>B;
    
    solve(decode(A),decode(B));
    return 0;
}
