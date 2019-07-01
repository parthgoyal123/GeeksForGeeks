// COMMON HEAP OPERATIONS

#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    int *harr;
    int capacity;
    int curr_size;

    MinHeap(int capacity){
        this->harr = new int[capacity];
        this->curr_size = 0;
    }

    int parent(int index){
        return (index-1)/2;
    }

    int left(int index){
        return (2*index+1);
    }

    int right(int index){
        return (2*index+2);
    }

    int extractMin(){
        
    }
};


int main(){
    
}