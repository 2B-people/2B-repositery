// 有一个比较复杂的软件系统需要部署到客户提供的服务器上。该软件系统的安装过程非常繁琐,为了降低操作成本,需要开发一个工具实现自动化部著。软件的安装过程可以分成若干个小步骤,某些步骤间存在依赖关系,被依赖的步骤必须先执行完,才能执行后续的安装步骤。满足依赖条件的多个步骤可以并行执行。请你开发一个调度程序,以最短的时间完成软件的部署。

// 输入
// 第一行:总步骤数 N (O<N <= 10000)
// 第二行:N个以空格分隔的整数,代表每个步骤所需的时间。该行所有整数之和不大于int32
// 第三行开始的N行:表示每个步骤所依赖的其它步骤的编号(编号从1开始,行号减2表示步骤的编号),如果依赖多个步骤,用空格分隔。-1表示无依赖
// 测试用例确保各个安装步骤不会出现循环依赖。

// 输出
// 一个整数，表示最短时间

// 输入:4
// 6 2 1 2
// -1
// -1
// 1
// 3

// 输出:9

// 解释:一共4个步骤。
// 每个步骤所需的时间分别为6 2 1 2。
// 步骤1和步骤2无依赖,可并发执行;步骤3依赖步骤1;步骤4依赖步骤3。
// 总的最小执行时间为6+1+2=9;

#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  int time;
  int indegree;
  vector<int> next;
};

int main() {
  // please define the C++ input here. For example: int a,b; cin>>a>>b;;
  // please finish the function body here.
  // please define the C++ output here. For example:cout<<____<<endl;
  int N;
  cin >> N;
  vector<Node> nodes(N);
  // times
  for (int i = 0; i < N; i++) {
    cin >> nodes[i].time;
    nodes[i].indegree = 0;
  }
  // build map
  // 这个输入调死我了。。。。
//   for (int i = 0; i < N; ++i) {
//       int dep;
//       cin >> dep;
//       if(dep != -1) {
//           --dep;
//           nodes[dep].next.push_back(i);
//           nodes[i].indegree++;
//       }
//   }
  std::string line, num;
  size_t linenum = -1;
  while (getline(cin, line)) {
    std::istringstream iss(line);
    while (iss >> num) {
      int dep = stoi(num);
      if (dep != -1) {
        --dep;
        nodes[dep].next.push_back(linenum);
        nodes[linenum].indegree++;
      }
    }
    ++linenum;
  }

  // bfs
  queue<int> q;
  vector<int> dp(N, 0);
  // indegree == 0 into queue
  for (int i = 0; i < N; ++i) {
    if (nodes[i].indegree == 0) {
      q.push(i);
      dp[i] = nodes[i].time;
    }
  }

  int result = 0;
  while (!q.empty()) {
    int size = q.size();
    vector<int> currentLevel;
    for (int i = 0; i < size; ++i) {
      int current = q.front();
      q.pop();
      currentLevel.push_back(current);
      result = max(result, dp[current]);
      for (auto next : nodes[current].next) {
        dp[next] = max(dp[next], dp[current] + nodes[next].time);
        if (--nodes[next].indegree == 0) {
          q.push(next);
        }
      }
    }
    for (int task : currentLevel) {
      for (auto next : nodes[task].next) {
        dp[next] = max(dp[next], dp[task] + nodes[next].time);
      }
    }
  }

  cout << result << endl;
  return 0;
}
