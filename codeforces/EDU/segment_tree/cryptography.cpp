#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long int r;

struct item{
	long long int a11; 
	long long int a12; 
	long long int a21; 
	long long int a22; 
};

struct segtree{
	int size;
	vector<item>values;

	item NEUTRAL_ELEMENT = {1,0,0,1};

	item combine(const item &p1, const item &p2){
		return {((p1.a11 * p2.a11)%r + (p1.a12 * p2.a21)%r) % r,((p1.a11 * p2.a12)%r + (p1.a12 * p2.a22)%r) % r,((p1.a21 * p2.a11)%r + (p1.a22 * p2.a21)%r) % r,((p1.a21 * p2.a12)%r + (p1.a22 * p2.a22)%r) % r,};
	}

	item single(long long int val){
		return {val};
	}

	void init(int n){
		size = 1;
		while(size < n) size <<= 1;

		values = vector<item> (2 * size);
	}


	void build_helper(const vector<item> &v, int x, int l, int r){
		if(r-l==1){
			if(l < v.size())
				values[x] = (v[l]);
			return;
		}
		int m = (l+r)/2;

		build_helper(v,2*x+1,l,m);
		build_helper(v,2*x+2,m,r);
		values[x] = combine(values[2*x+1],values[2*x+2]);
		return;

	}

	void build(const vector<item> &v){
		build_helper(v,0,0,size);
	}

	void set_helper(int index, long long int val, int x, int l, int r){
		if(r-l==1){
			values[x] = single(val);
			return;
		}
		int m = (l+r)/2;
		if(index < m){
			set_helper(index, val, 2*x+1, l, m);
		}
		else{
			set_helper(index, val, 2*x+2, m, r);
		}
		values[x] = combine(values[2*x+1],values[2*x+2]);
		return ;
	}

	void set(int index, long long int val){
		set_helper(index,val,0,0,size);
	}

	item sum_helper(int l, int r, int x, int lx, int rx){
		if((l <= lx) && (rx <= r)) return values[x];

		if((rx <= l) || (lx >= r)) return NEUTRAL_ELEMENT;

		int m = (lx + rx)/2;

		return combine(sum_helper(l, r, 2*x+1, lx, m),sum_helper(l, r, 2*x+2, m, rx));
	}

	item sum(int l, int r){
		return sum_helper(l,r,0,0,size);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> r >> n >> m;
	vector<item> a(n);
	long long int i11 ,i12 ,i21 ,i22;
	for(int i=0 ; i<n ; i++){
		cin >> i11 >> i12 >> i21 >> i22;
		a[i] = {i11,i12,i21,i22};
	}


	segtree st;
	st.init(n);
	st.build(a);

	//for(auto e : st.sums) cout << e << " ";
	//cout << "\n";
	for(int i=0 ; i<m ; i++){
		int l, r;
		cin >> l >> r;
		l--;
		auto tmp = st.sum(l,r);
		cout << tmp.a11 << " " << tmp.a12 << "\n";
		cout << tmp.a21 << " " << tmp.a22 << "\n";
		cout << "\n";
    }	


}
