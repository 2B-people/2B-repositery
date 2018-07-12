void trun(void)
{
    char buf[10];
    int data[10],j = 0;
    int length = strcpy(buf, str.c_str() /*读入变量*/); //先转换为字符数组
    for (int i = 0; i < length; i++)
    {
        if(buf[i] <= '9' && buf[i] >= '0')
            data[j++] = (int)buf[i] - '0';
    }
    return *data;
}