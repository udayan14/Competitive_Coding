#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template<typename T, typename U> 
static inline void amin(T &x, U y) 
{ 
    if (y < x) 
        x = y; 
} 
  
// call by reference is used in x 
template<typename T, typename U> 
static inline void amax(T &x, U y) 
{ 
    if (x < y) 
        x = y; 
}


const long long int p = 1000000007;

struct Rectangle{
	int x,y,w,h;

	Rectangle(int x1,int y1,int w1, int h1){
		x = x1;
		y = y1;
		w = w1;
		h = h1;
	}
	Rectangle(){
		x = y = w = h = 0;
	}
	bool inside(float u, float v){
		return (x <= u) && (u <= x + w) && (y <= v) && (v <= y + h);
	}
};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        int n;
		cin >> n;
		int x,y,w,h;
		vector<Rectangle> a(n);
		for(int i=0 ; i<n ; i++){
			cin >> x >> y >> w >> h;
			a[i] = Rectangle(x,y,w,h);
		}
		bool found = false;
		int T = 10000000;
		for(int i=0 ; i<n && !found ; i++){
			found = true;
			for(int itr = 0 ; itr < T ; itr++){
				float u = a[i].x + ((float)rand()/(float)RAND_MAX)*a[i].w;
				float v = a[i].y + ((float)rand()/(float)RAND_MAX)*a[i].h;
				bool flag = false;
				for(int j=0 ; j<n  && !flag; j++){
					if(i==j) continue;
					if(a[j].inside(u,v)) flag = true;
				}
				if(!flag){
					found = false;
					break;
				}
			}
		}
		if(!found){
			cout << "FALSE\n";
		}
		else{
			cout << "TRUE\n";
		}
    }
    return 0;
}

