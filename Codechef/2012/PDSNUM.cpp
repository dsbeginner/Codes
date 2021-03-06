#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

ll dp[2][11][91][91][91];
int mark[2][11][91][91][91];
int a[11],cnt;

ll get(int i, bool started, int dMod, int sum, int mul){
    if(sum>dMod) return 0;
    if(sum+9*i<dMod) return 0;
    if(i<=0) return sum==dMod && mul==0;
    if(mark[started][i][dMod][sum][mul]==1) return dp[started][i][dMod][sum][mul];
    ll &res = dp[started][i][dMod][sum][mul]; res = 0;

    for(int v=(!started); v<=9; ++v){
        res += get(i-1, 1, dMod, sum+v, mul*v%dMod);
        if(res >= oo) return oo;
    }

    mark[started][i][dMod][sum][mul] = 1;
    return res;
}


ll solve(ll n){
    int d=0;
    ll val;
    while(1){
        ++d;
        val=0;
        for(int x=1; x<=9*d; ++x){
            val+=get(d,0,x,0,1);
            if(val>=oo) break;
        }
        if(val >= n) break;
        else n-=val;
    }

    int totalsum = 0;
    ll totalmul = 1;
    ll res = 0;
    for(int i=d; i>=1; --i){
        int started = (i<d);
        int v;
        for(v=(!started); v<=9; ++v){
            val = 0;
            for(int x=1; x<=9*d; ++x){
                val+=get(i-1,1,x,totalsum+v,(totalmul*v)%x);
                if(val >= oo) break;
            }
            if(val >= n) break;
            else n-=val;
        }
        totalsum += v;
        totalmul *= v;
        res = res*10+v;
    }

    return res;

}

int main(){
//    freopen("input.txt","r",stdin);
    reset(mark,0);

    ll n;

    while(scanf("%lld",&n),n>0){
        ll res=solve(n);
        printf("%lld\n",res);
    }
}

