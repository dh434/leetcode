#include<iostream>
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <queue>
using namespace std;

stack<int> stack1;
stack<int> stack2;

template<typename T> void appendTail(const T& element){
    stack1.push(element);
}

template<typename T> T deleteHead(){
    if(stack2.size() <= 0){
        while(stack1.size() > 0){
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if(stack2.size() == 0){
        throw new exception("queue is empty");
    }

    T head = stack2.top();
    stack2.pop();
    return head;
}