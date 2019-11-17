/*
给出方程式 A / B = k, 其中 A 和 B 均为代表字符串的变量， k 是一个浮点型数字。根据已知方程式求解问题，并返回计算结果。如果结果不存在，则返回 -1.0。

示例 :
给定 a / b = 2.0, b / c = 3.0
问题: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
返回 [6.0, 0.5, -1.0, 1.0, -1.0 ]

输入为: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries(方程式，方程式结果，问题方程式)， 其中 equations.size() == values.size()，即方程式的长度与方程式结果长度相等（程式与结果一一对应），并且结果值均为正数。以上为方程式的描述。 返回vector<double>类型。

基于上述例子，输入如下：

equations(方程式) = [ ["a", "b"], ["b", "c"] ],
values(方程式结果) = [2.0, 3.0],
queries(问题方程式) = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
输入总是有效的。你可以假设除法运算中不会出现除数为0的情况，且不存在任何矛盾的结果。

*/

//dfs

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        auto graph = buildGraph(equations, values);
        vector<double> res;
        
        for(auto it: queries){
            string start = it[0];
            string end = it[1];
            set<string> visited;
            bool found = false;
            
            double temp = dfs(graph, found, visited, start, end);
            if(found)
                res.push_back(temp);
            else
                res.push_back(-1);
        }
        
        return res;
        
    }
    
    unordered_map<string, unordered_map<string,double>> buildGraph(vector<vector<string>>& equations, vector<double>& values){
        
        unordered_map<string, unordered_map<string,double>> graph;
        
        for(int i=0;i<equations.size();++i){
            string a = equations[i][0];
            string b = equations[i][1];
            
            double v = values[i];
            
            if(graph.find(a) == graph.end())
                graph[a] =  unordered_map<string, double>{{b, v}};
            else
                graph[a][b] = v;
            graph[a][a] = 1;
            
            if(graph.find(b) == graph.end())
                graph[b] = unordered_map<string, double>{{a, 1/v}};
            else
                graph[b][a] = 1/v;
            graph[b][b] = 1;
        }
        return graph;
    }
    
    double dfs(unordered_map<string, unordered_map<string,double>> graph, bool& found, set<string>& visited, string start, string end){
        
        if(graph.find(start) == graph.end() || graph.find(end) == graph.end()){
            found = false;
            return -1;
        }
        
        if(visited.find(start) != visited.end()){
            found = false;
            return -1;
        }
        
        if(graph[start].find(end) != graph[start].end()){
            found = true;
            return graph[start][end];
        }
        
        
        visited.insert(start);
        found = false;
        for(auto it : graph[start]){
            double temp = dfs(graph, found,visited,it.first, end);
            if(found){
                double res = temp * it.second;
                return res;
            }
        }
        visited.erase(start);
        
        found = false;
        return -1;
    }
    
};