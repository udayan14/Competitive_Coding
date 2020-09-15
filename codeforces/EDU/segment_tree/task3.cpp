#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct segtree{
	int size;
	vector<pair<long long int, long long int>>sums;

	void init(int n){
		size = 1;
		while(size < n) size <<= 1;

		sums = vector<pair<long long int, long long int>> (2 * size,{0,0});
	}

	pair<long long, long long> combine(pair<long long, long long > p1, pair<long long, long long> p2){
		if(p1.first < p2.first) return p1;
		if(p2.first < p1.first) return p2;
		else return make_pair(p1.first, p1.second + p2.second);
	}

	void build_helper(const vector<long long int> &v, int x, int l, int r){
		if(r-l==1){
			if(l < v.size())
				sums[x] = {v[l],1};
			return;
		}
		int m = (l+r)/2;

		build_helper(v,2*x+1,l,m);
		build_helper(v,2*x+2,m,r);
		sums[x] = combine(sums[2*x+1],sums[2*x+2]);
		return;

	}

	void build(const vector<long long int> &v){
		build_helper(v,0,0,size);
	}

	void set_helper(int index, long long int val, int x, int l, int r){
		if(r-l==1){
			sums[x] = {val,1};
			return;
		}
		int m = (l+r)/2;
		if(index < m){
			set_helper(index, val, 2*x+1, l, m);
		}
		else{
			set_helper(index, val, 2*x+2, m, r);
		}
		sums[x] = combine(sums[2*x+1],sums[2*x+2]);
		return ;
	}

	void set(int index, long long int val){
		set_helper(index,val,0,0,size);
	}

	pair<long long, long long> sum_helper(int l, int r, int x, int lx, int rx){
		if((l <= lx) && (rx <= r)) return sums[x];

		if((rx <= l) || (lx >= r)) return {LLONG_MAX,0};

		int m = (lx + rx)/2;

		return combine(sum_helper(l, r, 2*x+1, lx, m),sum_helper(l, r, 2*x+2, m, rx));
	}

	pair<long long, long long> sum(int l, int r){
		return sum_helper(l,r,0,0,size);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector<long long int> a(n);
	for(int i=0 ; i<n ; i++){
		cin >> a[i];
	}


	segtree st;
	st.init(n);
	st.build(a);

	//for(auto e : st.sums) cout << e << " ";
	//cout << "\n";
	for(int i=0 ; i<m ; i++){
        int op;
        cin >> op;
        if(op==1){
            int index;
            long long int val;
            cin >> index >> val;
            st.set(index,val);
        }
        else if(op==2){
            int l, r;
            cin >> l >> r;
			auto p = st.sum(l,r);
		    cout << p.first << " " << p.second << "\n";
        }
    }	


}
