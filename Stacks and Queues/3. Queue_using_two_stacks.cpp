#include<bits/stdc++.h>
using namespace std;
class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();
};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();
        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";
        }
        }
        cout<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/* The structure of the class is
class StackQueue{
private:   
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */


/* The method push to push element into the queue */
void StackQueue :: push(int x)
{
    while(!s1.empty()){
        int x = s1.top();
        s1.pop();
        s2.push(x);
    }

    if(s1.empty()){
        s1.push(x);
    }

    while(!s2.empty()){
        int x = s2.top();
        s2.pop();
        s1.push(x);
    }
}
/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    if(!s1.empty()){
        int x = s1.top();
        s1.pop();
        return x;
    }
    return -1;
}