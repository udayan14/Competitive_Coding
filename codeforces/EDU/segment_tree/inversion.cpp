#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct item{
	long long int val; 
};

struct segtree{
	int size;
	vector<item>values;

	item NEUTRAL_ELEMENT = {0};

	item combine(const item &p1, const item &p2){
		return {p1.val + p2.val};
	}

	item single(long long int val){
		return {val};
	}

	void init(int n){
		size = 1;
		while(size < n) size <<= 1;

		values = vector<item> (2 * size);
	}


	void build_helper(const vector<long long int> &v, int x, int l, int r){
		if(r-l==1){
			if(l < v.size())
				values[x] = single(v[l]);
			return;
		}
		int m = (l+r)/2;

		build_helper(v,2*x+1,l,m);
		build_helper(v,2*x+2,m,r);
		values[x] = combine(values[2*x+1],values[2*x+2]);
		return;

	}

	void build(const vector<long long int> &v){
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
	int n;
	cin >> n ;
	vector<long long int> p(n);
	for(int i=0 ; i<n ; i++){
		cin >> p[i];
	}

	vector<long long int> a(n+1,0);
	segtree st;
	st.init(n+1);
	st.build(a);

	//for(auto e : st.sums) cout << e << " ";
	//cout << "\n";
	vector<long long int> output(n);

	for(int i=0 ; i<n ; i++){
		st.set(p[i],1);
		output[i] = st.sum(p[i]+1,n+1).val;
	}	

	for(auto e : output) cout << e << " ";
	cout << "\n";
}
