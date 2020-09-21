#include <iostream>
#include <vector>
#include <climits>
#include <map>

using namespace std;

struct item{
	map<long long int, long long int> m;
	item(map<long long int, long long int> m1){
		m = m1;
	}
	item(){
		map<long long int, long long int> temp;
		m = temp;
	}
};

struct segtree{
	int size;
	vector<item>values;

	item NEUTRAL_ELEMENT = item();

	item combine(const item &p1, const item &p2){
		return p1;
	}

	item single(long long int val){
		map<long long int, long long int> temp;
		temp[val]++;
		return temp;
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

	void set_greedy_helper(int index, long long old_val, long long new_val, int x, int l , int r){
		if(old_val==0){
			values[x].m[new_val]++;
		}
		else{
			values[x].m[new_val]++;
			values[x].m[old_val]--;
		}
		if(r-l==1) return;

		int m = (l+r) / 2;
		if(index < m){
			set_greedy_helper(index,old_val,new_val,2*x+1,l,m);
		}
		else{
			set_greedy_helper(index,old_val,new_val,2*x+2,m,r);	
		}
	}

	void set_greedy(int index, long long old_val, long long new_val){
		set_greedy_helper(index,old_val,new_val,0,0,size);
	}

	int answer_helper(int l, int r, long long p, int x, int lx, int rx){
		if(l >= rx || lx >= r) return 0;
		if(l <= lx && rx <= r){
			int out = 0;
			if(values[x].m.empty() || values[x].m.begin()->first > p){
				return 0;
			}
			flag = true;
			for(auto it = values[x].m.begin() ; it != values[x].m.end() ; ++it){
				if(it->first > p){
					values[x].m.erase(values[x].m.begin(),it);
					flag = false;
					break;
				}
				out += it->second;
				if(flag) values.m.erase(values.m.begin().values.m.end());
			}
			int m = (l+r)/2;
			if(r - l > 1){
				answer_helper(l,r,p,2*x+1,lx,m);
				answer_helper(l,r,p,2*x+2,m,rx);
			}
			return out;
		}
		
		int m = (lx + rx) / 2;
		int out = 0;
		out += answer_helper(l,r,p,2*x+1,lx,m);
		out += answer_helper(l,r,p,2*x+2,m,rx);
		
		bool flag = true;
		for(auto it = values[x].m.begin() ; it != values[x].m.end() ; ++it){
			if(it->first > p){
				values[x].m.erase(values[x].m.begin(),it);
				flag = false;
			}
		}
		if(flag) values[x].m.erase(values[x].m.begin(),values[x].m.end())
		return out;
	}

	int answer(int l, int r, long long p){
		return answer_helper(l,r,p,0,0,size);
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector<long long int> a(n,0);


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
            st.set_greedy(index,a[index],val);
			a[index] = val;
        }
        else if(op==2){
            int l, r;
			long long p;
            cin >> l >> r >> p;
		    cout << st.answer(l,r,p) << "\n";
        }
    }	


}
