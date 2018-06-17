/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:
输入: [2,2,1]g
输出: 1
*/

//.c,1100ms,乐色暴力解法
int singleNumber(int* nums, int numsSize) {
    if(numsSize == 1)
        return nums[0];
    for(int i = 0;i<numsSize;i++)
        for(int j = i+1;j<numsSize;j++)
            if(nums[j]<nums[i])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
    for(int i = 0;i<numsSize;i++)
    {
        if(i == 0 && nums[i] != nums[i+1])
            return nums[i];
        else if(i == numsSize-1 && nums[i] != nums[i-1])
            return nums[i];
        else if(nums[i-1] != nums[i] && nums[i] != nums[i+1])
            return nums[i];
    }
    return -1;
}


//.cpp,4ms 
int singleNumber(int* nums, int numsSize) {
    int result = nums[0];
    for(int i = 1; i< numsSize;i++) {
        result ^= nums[i];
    }
    return result;
}