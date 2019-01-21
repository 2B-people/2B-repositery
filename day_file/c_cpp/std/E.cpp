#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <assert.h>
#include <stack>
#include <set>
#include <bitset>
#include <queue>
#include <iomanip>
#include <cstring>
#include <algorithm>
using namespace std;

#define sacnf scanf
#define scnaf scanf
#define scnafi scanfi
#define pb push_back
#define Len size()
#define gchar getchar()
#define FOR(i,j,k) for(int (i)=(j);(i)<=(k);++(i))
#define mes(a,b) memset((a),(b),sizeof(a))
#define scanfi(a) scanf("%d",&(a))
#define scanfti(a,b) scanf("%d%d",&(a),&(b))
#define println(a) printf("%d\n",(a))
#define printIs(a) printf((a)?"Yes\n":"No\n")
#define print_b printf("\n")
#define IsNum(x) '0'<=(x)&&(x)<='9'
#define lt dir*2
#define rt dir*2+1

#define maxn 510
#define maxm 26
#define inf 1061109567
//const long long inf=1e15;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define E 2.718281828459
const double PI=acos(-1.0);
//#define mod 1000
const long long mod=123456789;
#define MAXNUM 1000000000

typedef long long ll;
typedef unsigned long long ulld;
ll Abs(ll x) {return (x<0)?-x:x;}
int Read() {char ch;int res=0;while(ch=getchar(),!(IsNum(ch)));while(IsNum(ch)) res=res*10+ch-'0',ch=getchar();return res;}

ll f[maxn];

int main()
{
    freopen("data_E.in","r",stdin);
    freopen("data_E.out","w",stdout);
    //clock_t st=clock();
    f[0]=1;f[1]=2;for(int i=2;i<=1000;i++) f[i]=(f[i-1]+f[i-2])%mod;
    int kase=0,n;
    while(~scanfi(n))
        printf("Case #%d: %lld\n",++kase,f[n]);
    //clock_t ed=clock();
    //printf("\nTIme Used: %f Ms.\n",(double)(ed-st)/CLOCKS_PER_SEC);
    return 0;
}
