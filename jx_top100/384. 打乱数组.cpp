/*
打乱一个没有重复元素的数组。

示例:

// 以数字集合 1, 2 和 3 初始化数组。
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
solution.shuffle();

// 重设数组到它的初始状态[1,2,3]。
solution.reset();

// 随机返回数组[1,2,3]打乱后的结果。
solution.shuffle();

*/

class Solution {
private:
    vector<int> original;
    vector<int> array;
    
public:
    Solution(vector<int>& nums) {
        array = nums;
        original = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        array = original;
        return array;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for(int i=0;i < array.size();++i){
            swap(i, getRandomNum(i, array.size()-1));
        }
        return array;
    }
    
    void swap(int a, int b){
        int temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }
    
    int getRandomNum(int min, int max){
        return rand()%(max -min + 1) + min;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
