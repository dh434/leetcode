/*
在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 逐行 依次按 “之” 字形进行标记。

如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记；

而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。

给你树上某一个节点的标号 label，请你返回从根节点到该标号为 label 节点的路径，该路径是由途经的节点标号所组成的。


示例 1：

输入：label = 14
输出：[1,3,4,14]
示例 2：

输入：label = 26
输出：[1,2,6,10,26]
 

提示：

1 <= label <= 10^6

*/

// 还挺巧妙的一道题
// 先是求层数：c++中的log函数
// 满二叉树中，对称节点的和为恒定值

//best
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = log(label) / log(2) + 1;

        vector<int> res(level);
        while(level >= 1){
            res[level-1] = label;

            label = pow(2, level-1) + pow(2, level) - 1 - label;
            label >>= 1;
            level -= 1;
        }

        return res;
    }
};


//先按正常顺序，再求对称点

/*
这样，那我们看一下样例，当label=14时，我们倒序找一下路径，这个很好找，不停除以2就行了
即[14,7,3,1]，然后再颠倒一下就找到路径了
即[1,3,7,14]

比如2,3是对称的，5,6是对称的，4,7是对称的。这里有个规律，就是每层对称的两个数加起来是一个确定的数字，不难发现，这个数和这个层次有关。

但此题是“之”字型树，我们只需要将对应位置的树取成对称的树就可以了。哪些位置呢？ 不难发现，从label后一个数开始，隔一个位置。
[14,7,3,1]中，要取对称的数为[7,1]，取对称后即[4,1]。
所以最后结果为[14,4,3,1]，再颠倒即可。
*/

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        // Make sure the level of the label
        unsigned level=1;
        while(label>pow(2,level)-1){
            level++;
        }
        
        int* level_sysmetry_sum=new int[level+1];
        level_sysmetry_sum[1]=2;
        for(unsigned i=2;i<=level;i++)
            level_sysmetry_sum[i]=2*level_sysmetry_sum[i-1]+1;
        vector<int>ans;
        while(label>=1){
            ans.push_back(label);
            label=label/2;
        }
        if(ans.size()>1){
            unsigned current_level=level-1;
            for(unsigned i=1;i<ans.size();i+=2){
                ans[i]=level_sysmetry_sum[current_level]-ans[i];
                current_level-=2;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};