#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){
       int qt;
       cin>>qt;
       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }
}

/*This is a function problem.You only need to complete the function given below*/
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin()
{
    if(s.empty()) return -1;
    return minEle;
}
/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.empty()) return -1;
    
    // get the top and remove it
    int y = s.top();
    s.pop();
    
    if(y >= minEle) {
        return y;
    }
    
    // if y is less than minEle, take special steps
    int temp = minEle;
    minEle = 2*minEle - y;
    
    return temp;
}
/*push element x into the stack*/
void _stack::push(int x)
{
    // simply insert in the stack if empty
    if(s.empty()) {
        s.push(x);
        minEle = x;
        return;
    }
    
    // check if new element is bigger or smaller than minEle
    if(x >= minEle) {
        s.push(x);
        return;
    }
    
    // if smaller than minEle than special steps
    if(x < minEle) {
        s.push(2*x - minEle);
        minEle = x;
        return;
    }
}