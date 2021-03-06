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

const int maxn=100007;

struct node{
    int a,b,id;
    bool operator <(const node &x) const{
        return a<x.a;
    }
}a[maxn];

bool cmp(const node &a, const node &b){
    return a.b<b.b || (a.b==b.b && a.a>b.a);
}

int n,p,k,x,y;
multiset<node> mys;
vector<int> list;
ll val,res;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    scanf("%d%d%d\n",&n,&p,&k);
    FOR(i,1,n) scanf("%d%d",&a[i].a,&a[i].b), a[i].id=i;
    sort(a+1,a+n+1,cmp);
    res=-1; val=0;
    FORD(i,n,(p-k)+1){
        mys.insert(a[i]);
        val+=a[i].a;
        while(sz(mys)>k){
            int t=mys.begin()->a; mys.erase(mys.begin());
            val-=t;   
        }
        if(sz(mys)==k){
            if(res<val)
                res=val;
        }
    }
    mys.clear(); val=0;
    FORD(i,n,(p-k)+1){
        mys.insert(a[i]);
        val+=a[i].a;
        while(sz(mys)>k){
            int t=mys.begin()->a; mys.erase(mys.begin());
            val-=t;   
        }
        if(sz(mys)==k && res==val){
            for(set<node>::iterator it=mys.begin(); it!=mys.end(); it++) 
                list.pb(it->id);
            FORD(j,i-1,i-(p-k)) list.pb(a[j].id);
            break;
        }  
    }
    
    REP(i,sz(list)) printf("%d ",list[i]);
    //getch();
    return 0;
}
