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
#define FOR(a,b,c) for (int a=b;a<=c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#include <conio.h>
int main(){
    //freopen("test.txt","r",stdin);
    string s;
    int res=0,c=0;
    while(getline(cin,s))
        if(s[0]=='+') c++;else if(s[0]=='-') c--;
        else{
            s.erase(0,s.find(":")+1);
            while(!s.empty() && s[sz(s)-1]==' ') s.erase(sz(s)-1,1);
            while(!s.empty() && s[0]==' ') s.erase(0,1);
            res+=sz(s)*c;
        }
    cout<<res;
    //getch();
    return 0;
}