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

struct mat
{
    int n,m;
    ll num[10][10];
    mat() {n=m=0;mes(num,0);}
} I,A;

mat operator * (mat a,mat b)
{
    mat c;c.n=a.n;c.m=b.m;
    for(int k=1;k<=a.m;k++)
        for(int i=1;i<=a.n;i++)
            for(int j=1;j<=b.m;j++)
                (c.num[i][j]+=(a.num[i][k]*b.num[k][j])%mod)%=mod;
    return c;
}

mat power(mat a,ll b)
{
    mat ans=I;
    while(b)
    {
        if(b%2==1) ans=ans*a;
        a=a*a;b/=2;
    }
    return ans;
}

int main()
{
    freopen("data_F.in","r",stdin);
    freopen("data_F.out","w",stdout);
    //clock_t st=clock();
    for(int i=1;i<10;i++) I.num[i][i]=1,A.num[i][i-1]=1,A.num[1][i]=1;
    ll n;int k,kase=0;
    while(~scanf("%lld%d",&n,&k))
    {
        printf("Case #%d: ",++kase);
        A.n=A.m=I.n=I.m=k;
        mat B;B.n=k;B.m=1;
        B.num[k][1]=1;for(int i=k-1;i>0;i--) B.num[i][1]=B.num[i+1][1]*2;
        if(n<k) {printf("%lld\n",B.num[k-n][1]);continue;}
        mat ans=power(A,n-k+1)*B;
        printf("%lld\n",ans.num[1][1]);
    }
    //clock_t ed=clock();
    //printf("\nTIme Used: %f Ms.\n",(double)(ed-st)/CLOCKS_PER_SEC);
    return 0;
}
