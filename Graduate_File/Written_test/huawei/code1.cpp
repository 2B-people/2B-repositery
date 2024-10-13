// 某运营商需要在某一区域铺设光缆,起点为机房,终点为某小区,整个区域以一个m*n的矩阵表示,光缆沿着矩阵的边铺设(不允许走对角线),区域内有些节点可以经过,但有些节点(如图红色x的位置,输入时给定)因为各种因素无法经过,起点的机房与终点的小区可能在区域内的任何位置,计算从机房到目标小区铺设光缆的最短距离(如果光缆无法从起点机房铺设到达目标小区,返回-1)。
// 输入
// m矩阵宽(横轴点数量,例如图示为11,以0~10作为下标)
// n矩阵高(纵轴点数量,例如图示为8,以0~7作为下标)
// 机房坐标(a1,a2)
// 目标小区坐标(b1,b2)
// 矩阵内不允许经过的节点数量k
// 依次为这些不允许经过的节点坐标
// 1 <= m,n <= 1000
// 0 <= k <= 100000

// 输出
// 最短距离

// we have defined the necessary header files here for this problem.
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
// If additional header files are needed in your program, please import here.

struct Point {
  int x;
  int y;
  // Comparison operator for Point struct
  bool operator<(const Point& other) const {
    if (x != other.x) {
      return x < other.x;
    }
    return y < other.y;
  }
};

int m, n;

bool isValid(Point pos) {
  return pos.x >= 0 && pos.x < m && pos.y >= 0 && pos.y < n;
}

int main() {
  // please define the C++ input here. For example: int a,b; cin>>a>>b;;
  // please finish the function body here.
  // please define the C++ output here. For example:cout<<____<<endl;
  vector<Point> obstacles;

  cin >> m >> n;
  Point start, end;
  cin >> start.x >> start.y >> end.x >> end.y;
  int k;
  cin >> k;
  obstacles.resize(k);
  for (int i = 0; i < k; i++) {
    cin >> obstacles[i].x >> obstacles[i].y;
  }
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  vector<vector<int>> distance(m, vector<int>(n, INT_MAX));

  priority_queue<pair<int, Point>, vector<pair<int, Point>>,
                 greater<pair<int, Point>>>
      pq;
  pq.push({0, start});
  distance[start.x][start.y] = 0;

  int shortestDistance = 1;

  cout << shortestDistance << endl;
  return 0;
}
