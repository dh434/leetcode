/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        
        int nums_0 = 0;
        int nums_1 = 0;
        int nums_2 = 0;
        
        int index_0 = -1;
        int index_1 = -1;
        int index_2 = -1;
        
        for(int i =0;i<len;++i){
            
            int val = nums[i];
            if(val == 0){
                nums_0 ++;
                
                if(index_0 == -1){
                    index_0 = i;
                }
                
                if(index_1 != -1){
                    swap(&nums[i], &nums[index_1]);
                    index_0 = index_1 - nums_0 + 1;
                    index_1++;
                }
                
                if(index_2 != -1){
                    swap(&nums[i], &nums[index_2]);
                    index_2++;
                }
            }else if(val == 1){
                nums_1 ++;
                if(index_1 == -1) index_1 = i;
                
                 if(index_2 != -1){
                    swap(&nums[i], &nums[index_2]);
                    index_1 = index_2 - nums_1 + 1;
                    index_2++;
                }
            }else{
                nums_2 ++;
                if(index_2 == -1){
                    index_2 = i;
                }
            }

        }
        
    }
    
    
    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

/*
本问题被称为 荷兰国旗问题
，最初由 Edsger W. Dijkstra提出。
其主要思想是给每个数字设定一种颜色，并按照荷兰国旗颜色的顺序进行调整。
本解法的思路是沿着数组移动 curr 指针，若nums[curr] = 0，则将其与 nums[p0]互换；若 nums[curr] = 2 ，则与 nums[p2]互换。

算法

初始化0的最右边界：p0 = 0。在整个算法执行过程中 nums[idx < p0] = 0.

初始化2的最左边界 ：p2 = n - 1。在整个算法执行过程中 nums[idx > p2] = 2.

初始化当前考虑的元素序号 ：curr = 0.

While curr <= p2 :

若 nums[curr] = 0 ：交换第 curr个 和 第p0个 元素，并将指针都向右移。

若 nums[curr] = 2 ：交换第 curr个和第 p2个元素，并将 p2指针左移 。

若 nums[curr] = 1 ：将指针curr右移。

class Solution {
  public:
  
  void sortColors(vector<int>& nums) {
    // 对于所有 idx < p0 : nums[idx < p0] = 0
    // curr 是当前考虑元素的下标
    int p0 = 0, curr = 0;
    // 对于所有 idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
      if (nums[curr] == 0) {
        swap(nums[curr++], nums[p0++]);
      }
      else if (nums[curr] == 2) {
        swap(nums[curr], nums[p2--]);
      }
      else curr++;
    }
  }
};

*/