/*All the code outside main (i.e. the GF_Manager struct and the multipoint eval and binary split and mudular exp) 
 * has been copied from this editorial on codechef https://discuss.codechef.com/t/rnbwroad-editorial/63267
 * I thank the setter for implementing this polynomial library for us noobs.
 * The code in main is my original code.
 *
 * */

#include<iostream>
#include<stack>
#include<cassert>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int DEPTH = 19;
const int ARR_DEPTH = (1<<DEPTH); //approx 5x10^5
const int SZ = 12;
LL temp[SZ][ARR_DEPTH+1];
const LL MOD = 998244353;
struct GF_Manager
{
    int tC = 0;
    stack<int> to_be_freed;
    const static LL DEPTH = 23;
    LL primitives[DEPTH+1];
    LL primitives_inv[DEPTH+1];
    LL two_inv[DEPTH+1];
    LL mod_pow(LL base, LL exp)
    {
        if(exp==0) return 1;
        if(exp&1) return (base*mod_pow(base,exp-1))%MOD;
        else return mod_pow((base*base)%MOD, exp/2);
    }
    void set_up_primitives()
    {
        primitives[DEPTH] = 31;
        primitives_inv[DEPTH] = mod_pow(primitives[DEPTH], MOD-2);
        two_inv[DEPTH] = mod_pow(1<<DEPTH,MOD-2);
        for(int n = DEPTH-1; n >= 0; n--)
            primitives[n] = (primitives[n+1]*primitives[n+1])%MOD,
            primitives_inv[n] = mod_pow(primitives[n],MOD-2),
            two_inv[n] = mod_pow(1<<n,MOD-2);   
    }
    GF_Manager(){ set_up_primitives(); }
    void start_claiming(){ to_be_freed.push(0); }
    LL* claim(){ ++to_be_freed.top(); assert(tC < SZ); return temp[tC++]; }
    void end_claiming(){ tC -= to_be_freed.top(); to_be_freed.pop(); }
    void clean(LL A[], int an, bool deep_cleaning=false)
    {
        if(deep_cleaning)
            for(int i = 0; i < an; i++)
                A[i] %= MOD;
        for(int i = 0; i < an; i++)
            if(A[i] < 0)
                A[i] += MOD;
    }
    void NTT(LL A[], int n, LL t[],  bool is_inverse=false, int offset=0)
    {
        if(n==0)
            return;
        //Put the evens first, then the odds
        for(int i = 0; i < (1<<(n-1)); i++)
        {
            t[i] = A[offset+2*i];
            t[i+(1<<(n-1))] = A[offset+2*i+1];
        }
        for(int i = 0; i < (1<<n); i++)
            A[offset+i] = t[i];
        
        NTT(A,n-1,t,is_inverse,offset);
        NTT(A,n-1,t,is_inverse,offset+(1<<(n-1)));
        
        LL w1 = is_inverse ? primitives_inv[n] : primitives[n];
        LL w = 1;
        for(int i = 0; i < (1<<(n-1)); i++, w=(w*w1)%MOD)
        {
            t[i] = (A[offset+i]+w*A[offset+(1<<(n-1))+i])%MOD;
            t[i+(1<<(n-1))] = (A[offset+i]-w*A[offset+(1<<(n-1))+i])%MOD;
        }
        for(int i = 0; i < (1<<n); i++)
            A[offset+i] = t[i];
    }
    int add(LL A[], int an, LL B[], int bn, LL C[])
    {
        int cn = 0;
        for(int i = 0; i < max(an,bn); i++)
        {
            C[i] = A[i]+B[i];
            if(C[i] <= -MOD)
                C[i] += MOD;
            if(MOD <= C[i])
                C[i] -= MOD;
            if(C[i]!=0)
                cn = i;
        }
        return cn;
    }
    int subtract(LL A[], int an, LL B[], int bn, LL C[])
    {
        int cn = 0;
        for(int i = 0; i < max(an,bn); i++)
        {
            C[i] = A[i]-B[i];
            if(C[i] <= -MOD)
                C[i] += MOD;
            if(MOD <= C[i])
                C[i] -= MOD;
            if(C[i]!=0)
                cn = i;
        }
        return cn+1;
    }
    int scalar_mult(LL v, LL A[], int an, LL C[])
    {
        for(int i = 0; i < an; i++)
            C[i] = (v*A[i])%MOD;
        return v==0 ? 0 : an;
    }
    int mult(LL A[], int an, LL B[], int bn, LL C[])
    {
        start_claiming();
        //make sure you've called setup primitives first
        //note: an and bn refer to the *number of items in each array*, NOT the degree of the largest term 
        int n, degree = an+bn-1;
        for(n=0; (1<<n) < degree; n++);
        
        LL* tA = claim();
        LL* tB = claim();
        LL* t = claim();
        
        copy(A,A+an,tA); fill(tA+an,tA+(1<<n),0);
        copy(B,B+bn,tB); fill(tB+bn,tB+(1<<n),0);
        
        NTT(tA,n,t);
        NTT(tB,n,t);
        
        for(int i = 0; i < (1<<n); i++)
            tA[i] = (tA[i]*tB[i])%MOD;
        
        NTT(tA,n,t,true);
        
        scalar_mult(two_inv[n],tA,degree,C);
        
        end_claiming();
        return degree;
    }
    int reciprocal(LL F[], int fn, LL R[])
    {
        start_claiming();
        LL* tR = claim();
        LL* tempR = claim();
        
        int n;
        for(n=0; (1<<n) < fn; n++);

        fill(tempR,tempR+(1<<n),0);
        tempR[0] = mod_pow(F[0],MOD-2);
        for(int i = 1; i <= n; i++)
        {
            mult(tempR,1<<i,F,1<<i,tR);
            tR[0] -= 2;
            scalar_mult(-1,tR,1<<i,tR);
            mult(tempR,1<<i,tR,1<<i,tempR);
        }
        
        copy(tempR,tempR+fn,R);
        end_claiming();
        return n;
    }
    int quotient(LL F[], int fn, LL G[], int gn, LL Q[])
    {
        start_claiming();
        LL* revF = claim();
        LL* revG = claim();
        LL* tempQ = claim();

        copy(F,F+fn,revF); reverse(revF,revF+fn);
        copy(G,G+gn,revG); reverse(revG,revG+gn);
        int qn = fn-gn+1;
        reciprocal(revG,qn,revG);
        mult(revF,qn,revG,qn,tempQ);
        reverse(tempQ,tempQ+qn);
        
        copy(tempQ,tempQ+qn,Q);
        end_claiming();
        return qn;
    }
    int mod(LL F[], int fn, LL G[], int gn, LL R[])
    {
        start_claiming();
        LL* Q = claim();
        LL* GQ = claim();
        int qn = quotient(F,fn,G,gn,Q);
        int gqn = mult(G,gn,Q,qn,GQ);
        int rn = subtract(F,fn,GQ,gqn,R);
        
        end_claiming();
        return rn;
    }
    int derivative(LL F[], int fn, LL F_[])
    {
        for(LL i = 0; i < fn-1; i++)
            F_[i] = ((i+1)*F[i+1])%MOD;
        return fn-1;
    }
    LL horners(LL F[], int fn, LL xi)
    {
        LL ans = 0;
        for(int i = fn-1; i >= 0; i--)
            ans = (ans*xi+F[i])%MOD;
        return ans;
    }
};
GF_Manager gfManager;
LL split[DEPTH+1][2*(ARR_DEPTH)+1];
LL Fi[DEPTH+1][2*(ARR_DEPTH)+1];
int establish_binary_splitting(LL a[], int l, int r, int s=0, int offset=0)
{
    if(l==r)
    {
        split[s][offset] = -a[l]; //x^0
        split[s][offset+1] = 1; //x^1
        return 2;
    }
    int m = (l+r)/2;
    int sz = m-l+1;
    int da = establish_binary_splitting(a,l,m,s+1,offset);
    int db = establish_binary_splitting(a,m+1,r,s+1,offset+(sz<<1));
    return gfManager.mult(split[s+1]+offset,da,split[s+1]+offset+(sz<<1),db,split[s]+offset);
}
void multipoint_eval(LL a[], int l, int r, LL F[], int fn, LL ans[], int s=0, int offset=0)
{
    if(l==r)
    {
        ans[l] = gfManager.horners(F,fn,a[l]);
        return;
    }
    int m = (l+r)/2;
    int sz = m-l+1;
    int da = gfManager.mod(F,fn,split[s+1]+offset,sz+1, Fi[s]+offset);
    int db = gfManager.mod(F,fn,split[s+1]+offset+(sz<<1),r-m+1, Fi[s]+offset+(sz<<1));
    multipoint_eval(a,l,m,Fi[s]+offset,da,ans,s+1,offset);
    multipoint_eval(a,m+1,r,Fi[s]+offset+(sz<<1),db,ans,s+1,offset+(sz<<1));
}
LL mod_pow(LL base, LL exp)
{
    if(exp==0) return 1;
    if(exp&1) return (base*mod_pow(base,exp-1))%MOD;
    else return mod_pow((base*base)%MOD, exp>>1);
}
const int N = 1e5;
LL a[N];
LL pts[N+1];
LL Q[N+2];
LL Q_[N+1];
LL K[N+1];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        LL in, n, x;
        cin >> n >> x;
        LL mul = 1;
        bool is_zero = false;
        for(int i = 0; i < n; i++)
        {
            cin >> in;
            if(in==0) is_zero = true;
            a[i] = (in*mul)%MOD;
            mul = (mul*x)%MOD;
        }
        if(is_zero){
            cout << 0 << "\n";
            continue;
        }
        pts[0] = 0;
        for(int i=1 ; i<=n ; i++){
            pts[i] = pts[i-1] - a[i-1];
            if(pts[i]<0) pts[i] += MOD;
        }
        //for(int i=0 ; i<=n ; i++) cout << pts[i] << " ";
        //cout << "\n";
        establish_binary_splitting(pts,0,n);
        memset(Q,0,sizeof Q);
        copy(split[0],split[0]+n+2,Q); 
        gfManager.derivative(Q,n+2,Q_);
        multipoint_eval(pts,0,n,Q_,n+1,K);
        //for(int i=0 ; i<n+1 ; i++) cout << K[i] << " ";
        //cout << "\n";
        LL output = mod_pow(mod_pow(x,(n-1)*n*(n+1)/3),MOD-2);
        for(int i = 0; i < n+1; i++)
            output = (output*K[i])%MOD;
        if(output < 0) output += MOD;
        if(n%4==1 || n%4==2){
            output *= -1;
            while(output<0) output += MOD;
        }
        cout << output << "\n";
    }
}
