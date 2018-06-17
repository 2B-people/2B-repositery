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

#define maxn 100010
#define maxm 26
#define inf 1061109567
//const long long inf=1e15;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define E 2.718281828459
const double PI=acos(-1.0);
//#define mod 1000
const long long mod=1e9+7;//1000000007;
#define MAXNUM 1000000000

typedef long long ll;
typedef unsigned long long ulld;
ll Abs(ll x) {return (x<0)?-x:x;}
int Read() {char ch;int res=0;while(ch=getchar(),!(IsNum(ch)));while(IsNum(ch)) res=res*10+ch-'0',ch=getchar();return res;}

int main()
{
    freopen("data_A.in","r",stdin);
    freopen("data_A.out","w",stdout);
    //clock_t st=clock();
    int T;scanfi(T);
    while(T--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int Re=a*c-b*d,Im=a*d+b*c;
        if(Re==0)
        {
            if(Im<0) printf("-");Im=Im<0?-Im:Im;
            if(Im==1) printf("i\n");
            else printf("%di\n",Im);
        }
        else
        {
            printf("%d",Re);
            if(Im!=0)
            {
                printf(Im<0?"-":"+");Im=Im<0?-Im:Im;
                if(Im==1) printf("i\n");
                else printf("%di\n",Im);
            }
            else printf("\n");
        }
    }
    //clock_t ed=clock();
    //printf("\nTIme Used: %f Ms.\n",(double)(ed-st)/CLOCKS_PER_SEC);
    return 0;
}
