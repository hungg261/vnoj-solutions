#include<bits/stdc++.h>
#define int long long
using namespace std;

int C(int n,int k){
    // nếu n<0 thì chắc chắn không có cách nào chọn ra k phần tử cả
    if(n<0)return 0;
    
    if(k==0) return 1; // nC0
    if(k==1) return n; // nC1
    if(k==2) return n*(n-1)/2; // nC2
    if(k==3) return n*(n-1)*(n-2)/6; // nC3
    
    return -1;
}

int dem_tong_bang_s(int d,int S,int N) {
	int ans=0;

	for(int i=0; i<=d; ++i) {
		int cur=C(d,i) * C(S-N*i-1, d-1);
		
		if(i%2==0) ans+=cur;
		else ans-=cur;
	}

	return ans;
}

pair<int,int> find_sum(int N,int T,int d) {
	int tong_cong_don=0;
	for(int sum=3; sum<=N*3; ++sum) {
	    // giá trị trước khi cộng dồn
		int temp=tong_cong_don;
		
		// thực hiện cộng dồn
		tong_cong_don+=dem_tong_bang_s(d,sum,N);
		
		if(T<=tong_cong_don) {
		    // đã tìm được tổng thỏa mãn, trả lại tổng "S" và vị trí "pos"
			return {sum,T-temp};
		}
	}
	return {-1,-1};
}

void tim_x2(int sum,int pos,int N) {
	for(int x2=1; x2<=N; ++x2) {
		int x3=sum-x2;

        // nếu x3 thỏa điều kiện thì ta vừa tìm được một cặp thỏa mãn
		if(1<=x3&&x3<=N) {
		    // lúc này còn lại pos-1 cặp cần xét nữa nên ta trừ pos cho 1
			--pos;
			
			// nếu không còn cặp cần xét, nghĩa là cặp (x2,x3) hiện tại là cặp cần tìm
			if(pos==0) {
			    // in ra kết quả và dừng lại
				cout<<x2<<' '<<x3<<'\n';
				return;
			}
		}
	}
}

void tim_x1(int sum,int pos,int N) {
	int tong_cong_don=0;
	for(int x1=1; x1<=N; ++x1) {
	    // giá trị trước khi cộng dồn
		int temp=tong_cong_don;
		
		// thực hiện cộng dồn
		tong_cong_don+=dem_tong_bang_s(2,sum-x1,N);
		
		if(pos<=tong_cong_don) {
		    // đã tìm được x1 thỏa mãn
			cout<<x1<<' ';
			
			// bắt đầu thực hiện tìm x2
			tim_x2(sum-x1,pos-temp,N);
			return;
		}
	}
}

void solve(int N,int T) {
	// tổng của bộ ba cần tìm và vị trí của bộ ba đó trong các bộ ba có tổng tương tự 
	int sum,pos;
	tie(sum,pos)=find_sum(N,T,3);
    
    // bắt đầu tìm x1
	tim_x1(sum,pos,N);
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int N,T;
	cin>>N>>T;

	solve(N,T);
	return 0;
}
