#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=5007;

int n,m,a[maxn],dp[maxn];

#include <conio.h>
int main(){
    //freopen("Test.txt","r",stdin);
    scanf("%d%d",&n,&m);
    double dx;
    FOR(i,1,n){
        scanf("%d%lf",&a[i],&dx);
    }
    int res=0;
    FOR(i,1,n){
        dp[i]=1;
        FOR(j,1,i-1) if(a[j]<=a[i]) dp[i]=max(dp[i],dp[j]+1);
        res=max(res,dp[i]);
    }   
    cout<<n-res<<endl;
    //getch();
    return 0;
}
    
