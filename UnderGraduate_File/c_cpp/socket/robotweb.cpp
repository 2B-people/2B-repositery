//server
#include <stdio.h>
#include <winsock2.h>                           //包含socket的头文件
#pragma comment (lib, "ws2_32.lib")             //加载 ws2_32.dll
int main() {
    WSADATA wsaData;                            //定义一个结构体对象
    WSAStartup(MAKEWORD(2, 2), &wsaData);       //初始化WSAStartup()函数,,,(规范的版本号，指向WSADATA结构体的指针),,,MSKEWORD(2,2)主版本号2，副版本号2

    SOCKET servSock = socket(PF_INET, SOCK_STREAM, 0);      //参数（1）IP地址类型PF_INET6为IPv6，（2）数据传输方式 SOCK_STREAM 和 SOCK_DGRAM （3）传输协议 IPPROTO_TCP 和 IPPTOTO_UDP，如果写0系统会自动计算处使用那种协议
    sockaddr_in sockAddr;                                       //创建sockaddr_in结构体变量
    memset(&sockAddr, 0, sizeof(sockAddr));                     //每个字节都用0填充
    sockAddr.sin_family = PF_INET;                              //使用IPv4地址
    sockAddr.sin_port = htons(1234);                            //端口号   要用到htons()函数转换
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");          //具体的IP地址32位

    bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));             //绑定套接字，
    printf("绑定套接字成功\n");
    listen(servSock, 20);                               
    printf("服务器已经进入监听状态\n");
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);       
    printf("accept函数执行完毕开始接收用户输入\n");


    printf("输入一句话并按回车\n");
    char tack[10];

    scanf("%s", &tack);

    //向客户端发送数据
    send(clntSock, tack, strlen(tack) + sizeof(char), NULL);    

    printf("数据发送成功\n");

    //关闭套接字
    closesocket(clntSock);
    closesocket(servSock);
    //终止 DLL 的使用
    WSACleanup();
    system("PAUSE");
    return 0;
}
--------------------- 
作者：董国政 
来源：CSDN 
原文：https://blog.csdn.net/qq_36409711/article/details/78937137 
版权声明：本文为博主原创文章，转载请附上博文链接！