#include<bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string n;
    cin>>n;
    
    int res;
    int remain=0;
    for(char&k:n){
        remain+=k;
        k=(k-'0')%3+'0';
    }
    remain%=3;
    
    if(remain%3==0){
        res=0;
    }
    else{
        if(find(begin(n),end(n),remain%3+'0')!=end(n)){
            res=1;
        }
        else{
            res=2;
        }
    }
    cout<<res<<'\n';
    return 0;
}
