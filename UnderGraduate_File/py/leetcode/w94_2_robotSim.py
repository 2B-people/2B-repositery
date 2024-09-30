'''
无限网格上的机器人从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：
-2：向左转 90 度
-1：向右转 90 度
1 <= x <= 9：向前移动 x 个单位长度
有一些网格方块被视作障碍物。 
第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])
如果机器人试图走到障碍物上方，那么它将停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。
返回从原点到机器人的最大欧式距离的平方。
 
示例 1：
输入: commands = [4,-1,3], obstacles = []
输出: 25
解释: 机器人将会到达 (3, 4)
示例 2：
输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
输出: 65
解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
 
提示：
0 <= commands.length <= 10000
0 <= obstacles.length <= 10000
-30000 <= obstacle[i][0] <= 30000
-30000 <= obstacle[i][1] <= 30000
答案保证小于 2 ^ 31
'''

# FIXME 存在问题，测试集有不通过情况
class Solution:
    def robotSim(self, commands, obstacles):
        """
        :type commands: List[int]
        :type obstacles: List[List[int]]
        :rtype: int
        """
        der = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        map = [0, 0]
        i = 0
        der_init = der[i]
        for data in commands:
            if data < 0:
                if data == -1:
                    if i+1 == 4:
                        i = 0
                    else:
                        i = i+1
                else:
                    if i-1 == -1:
                        i = 3
                    else:
                        i = i-1
                der_init = der[i]
            else:
                if len(obstacles) == 0:
                    map[0] = map[0]+data*der_init[0]
                    map[1] = map[1]+data*der_init[1]
                else:
                    for k in range(data):
                        map[0] = map[0]+der_init[0]
                        map[1] = map[1]+der_init[1]
                        if map in obstacles:
                            map[0] = map[0]-der_init[0]
                            map[1] = map[1]-der_init[1]
                            break                            
        return map[0]**2+map[1]**2