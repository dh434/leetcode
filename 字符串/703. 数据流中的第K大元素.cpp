/*
设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。

你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返回当前数据流中第K大的元素。

示例:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
说明: 
你可以假设 nums 的长度≥ k-1 且k ≥ 1。

*/    
    
class KthLargest {
private:
    vector<int> record;
    int size;
public:
    

    KthLargest(int k, vector<int> nums) {
        size=k;
        for(int i=0;i<nums.size()&&i<size;i++) {
            record.push_back(nums[i]);
        }
        
        heapSort();
        for(int i = size;i<nums.size();++i)
            add(nums[i]);
    }
    
    int add(int val) {
        if(record.size() < size){
            record.push_back(val);
            heapSort();
            return record[0];
        }
        
        if(val > record[0]){
            record[0] = val;
            adjust(record.size(), 0);
        }
        
        return record[0];
    }
    
    
    
    void heapSort()
    {
        int size = record.size();
        for(int i=size/2 - 1; i >= 0; i--)
        {
            adjust(size, i);
        }

    }
    
    void adjust(int len, int index)
    {
        int left = 2*index + 1; // index的左子节点
        int right = 2*index + 2;// index的右子节点

        int maxIdx = index;
        // 必须先left后right
        if(left<len && record[left] < record[maxIdx])     maxIdx = left;
        if(right<len && record[right] < record[maxIdx])     maxIdx = right;

        if(maxIdx != index)
        {
            swap(maxIdx, index);
            adjust(len, maxIdx);
        }

    }
    
    void swap(int left, int right){
        int temp = record[left];
        record[left] = record[right];
        record[right] = temp;
    }
    
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */