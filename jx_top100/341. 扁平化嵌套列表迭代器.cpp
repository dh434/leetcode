/*
给定一个嵌套的整型列表。设计一个迭代器，使其能够遍历这个整型列表中的所有整数。

列表中的项或者为一个整数，或者是另一个列表。

示例 1:

输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:

输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,4,6]。

*/

// 本来想边输出边解开，但是遇到好多[[[[]]],[]] 这种空的情况
// 导致一开始会以为有数字，所以会出错

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<int> my_stack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        addNode(nestedList);
    }

    int next() {
        
        int temp =my_stack.top();
        my_stack.pop();
        return temp;
    }

    bool hasNext() {
        if(my_stack.empty())
            return false;
        else
            return true;
    }
    // 递规来做就好
    void addNode(vector<NestedInteger> &nestedList){
        if(nestedList.size() == 0){
           return ;
        }
        
        while(!nestedList.empty()){
            NestedInteger temp = nestedList.back();
            if(!temp.isInteger()){
                addNode(temp.getList());
            }else{
                my_stack.push(temp.getInteger());
            }
            
            nestedList.pop_back();
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */