#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MAX 1000000007
#define loop(i,a,b) for(int i=a; i<b; i++)
#define lloop(i,a,b) for (long long i=a; i<b; i++)

class MinHeap{
private:
    int capactiy;
    int curr_size;
    int *harr;

public:

    MinHeap(int capacity){
        this->capactiy = capacity;
        this->harr = new int[capacity];
        this->curr_size = 0;
    }

    int parent(int i) { 
        return (i-1)/2; 
    }
    
    int left(int i) { 
        return (2*i + 1);
    }
    
    int right(int i) { 
        return (2*i + 2);
    }

    void insertKey(int x);
    void deleteKey(int index);
    int extractMin();
    void MinHeapify(int index);
    void decreaseKey(int index, int new_value);
};

// delete key at index -> `index`
void MinHeap :: deleteKey(int index){
    if(index < 0 || (index > curr_size-1)){
        // cout << "Invalid Index for deletion\n";
        return;
    }

    decreaseKey(index, INT_MIN);
    int minimum = extractMin();
}

// Decreases value of key at index 'i' to new_val.  It is assumed that 
// new_val is smaller than harr[i]. 
void MinHeap :: decreaseKey(int index, int new_val) 
{ 
    harr[index] = new_val; 
    while (index != 0 && harr[parent(index)] > harr[index]) 
    { 
       swap(harr[index], harr[parent(index)]); 
       index = parent(index); 
    } 
} 

// Insert value x in heap
void MinHeap :: insertKey(int x){
    if(curr_size == capactiy){
        // cout << "Overflow :: Could not insert\n";
        return;
    }
    
    int i = curr_size;
    curr_size++;
    harr[i] = x;


    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

// extract the min from the heap and heapify to restore the heap property
int MinHeap :: extractMin(){
    if(curr_size <= 0){
        // cout << "Heap is empty\n";
        return -1;
    }

    int last = curr_size-1;
    int minimum = harr[0];
    harr[0] = harr[last];
    curr_size--;

    this->MinHeapify(0);
    return minimum;
}

// Heapify to restore the heap property at index -> `index`
void MinHeap :: MinHeapify(int index){
    int l = left(index);
    int r = right(index);
    int smallest = index;

    if(l < curr_size && harr[l] < harr[index]){
        smallest = l;
    }

    if(r < curr_size && harr[r] < harr[smallest]){
        smallest = r;
    }

    if(smallest != index){
        swap(harr[index], harr[smallest]);
        MinHeapify(smallest);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        MinHeap heap(101);
        while(n--){
            int h1;
            cin >> h1;

            switch(h1){
                case 1:{
                    int x;
                    cin >> x;
                    heap.insertKey(x);
                    break;
                }
                case 2:{
                    int x;
                    cin >> x;
                    heap.deleteKey(x);
                    break;
                }
                case 3:{
                    cout << heap.extractMin() << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
}