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
const long long mod=1000000007;
#define MAXNUM 1000000000

typedef long long ll;
typedef unsigned long long ulld;
ll Abs(ll x) {return (x<0)?-x:x;}
int Read() {char ch;int res=0;while(ch=getchar(),!(IsNum(ch)));while(IsNum(ch)) res=res*10+ch-'0',ch=getchar();return res;}

int LED[20][20];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int main()
{
    //freopen("data_B.in","r",stdin);
    //freopen("data_B.out","w",stdout);
    //clock_t st=clock();
    int n,x,y;mes(LED,0);
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++)
    {
        int d;scanf("%d",&d);
        LED[x][y]=1;x+=dx[d];y+=dy[d];
    }
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
            printf(LED[i][j]?"*":".");
        printf("\n");
    }
    //clock_t ed=clock();
    //printf("\nTIme Used: %f Ms.\n",(double)(ed-st)/CLOCKS_PER_SEC);
    return 0;
}
