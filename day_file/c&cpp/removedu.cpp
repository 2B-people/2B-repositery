/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/

//我的28ms
int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0)
		return 0;
	int j = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != nums[i - 1])
			nums[j++] = nums[i];
	}
	return j;
}


//最快8ms
int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    int j = 1;
    for(int i = 1;i < numsSize;i++){
        if(nums[i] == nums[i - 1]) 
            continue;
        nums[j++] = nums[i];
        
    }
    return j;
}