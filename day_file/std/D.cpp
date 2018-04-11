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
const long long mod=1000000007;
#define MAXNUM 1000000000

typedef long long ll;
typedef unsigned long long ulld;
ll Abs(ll x) {return (x<0)?-x:x;}
int Read() {char ch;int res=0;while(ch=getchar(),!(IsNum(ch)));while(IsNum(ch)) res=res*10+ch-'0',ch=getchar();return res;}

/*
    13,19,27,29
    247=13x19,351=13x27,377=13*29,513=19x27,551=19x29,783=27x29
    6669=13x19x27,7163=13x19x29,10179=13x27x29,14877=19x27x29
    193401=13x19x27x29
*/
ll calc(ll x)
{
    return x
           -x/13-x/19-x/27-x/29
           +x/247+x/351+x/377+x/513+x/551+x/783
           -x/6669-x/7163-x/10179-x/14877
           +x/193401;
}

int main()
{
    freopen("data_D.in","r",stdin);
    freopen("data_D.out","w",stdout);
    //clock_t st=clock();
    ll L,R;
    while(~scanf("%lld%lld",&L,&R))
    {
        ll num=calc(R)-calc(L-1);
        printf("%lld\n",num);
    }
    //clock_t ed=clock();
    //printf("\nTIme Used: %f Ms.\n",(double)(ed-st)/CLOCKS_PER_SEC);
    return 0;
}
