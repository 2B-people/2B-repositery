/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
*/

//.c,232ms。。
void rotate(int* nums, int numsSize, int k) {
    int temp =0,last_temp=0;
    for(int i=0;i<k;i++)
        for(int j=0;j<numsSize;j++)
        {
            if(j == 0)
            {
                temp = nums[j];
                nums[j] = nums[numsSize-1];
                last_temp = temp;
            }
            else
            {
                temp = nums[j];
                nums[j] = last_temp;
                last_temp = temp;
            }
        }
}

//.cpp 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //方法1：循环，每次移一位
        //方法2：取余,此为空间复杂度O（n），要变为O（1），需要辅助变量
        /*
        vector<int> temp(nums);
        int len = nums.size();
        for(int i = 0;i<nums.size();i++){
            nums[i] = temp[(i+len-k%len)%len];
        }
        */
        
        /*
        int len = nums.size();
        vector<int> temp(nums);
        for(int i = 0;i<len;i++){
            nums[(i+k)%len] = temp[i];
        }
        */
        
        //方法2的O（1）
        int len = nums.size();
        int start = 0,i = 0,cur = nums[i],cnt = 0;
        while(cnt++<nums.size()){ 
            int temp = nums[(i+k)%len];
            i = (i+k)%len;
            nums[i] = cur;
            if(start == i){
                start++;
                i++;
                cur = nums[i];
            }else
                cur = temp;
        }
        
    }
    
    //方法3：反转
    /*
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        reverse(nums,0,len-1);
        reverse(nums,0,k%len-1);
        reverse(nums,k%len,len-1);
    }
    
    void reverse(vector<int>& nums,int begin,int end){
        int i = begin,j = end;
        while(i<j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
    */
};


//最快16ms
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> t = nums;
        for (int i = 0; i < nums.size(); ++i) {
            nums[(i + k) % nums.size()] = t[i];
        }
    }
};