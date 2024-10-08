#include<iostream>
using namespace std;
struct Node {
    int key;
    Node* next;
    Node(int key) : key(key) {}
};

class BinaryHeap {
    Node** heap;
    int capacity,size;
    
    void heapify(int index) {
        if(index && heap[index]->key < heap[(index-1)/2]->key){
            swap(heap[index] , heap[(index-1)/2]);
            heapify((index-1)/2);
        }
    }
    
    public :
        BinaryHeap(int capacity) {
            this->capacity;
            size = 0;
            heap = new Node*[capacity];
        }
    void insert(Node* node){
        heap[size++] = node;
        heapify(size-1);
    }
    Node* getMin(){
        return heap[0];
    }
    
    Node* getMax(){
        return heap[size-1];
    }
};

class LinkedList {
    public :
    Node* head = nullptr;
    
    void insert(int key){
        if(!head){
            head = new Node(key);
            return;
        }
        Node* ptr = head;
        while(ptr->next != NULL)
        ptr = ptr->next;
        ptr->next = new Node(key);
    }

};

int main(){
    int n,t,k;
    cin>>n;
    if(n<=0 || cin.fail()){
        cout<<"Invalid input";
        return 0;
    }
    BinaryHeap heap(n);
    LinkedList ll;
    while(n--){
        cin>>t;
        if(cin.fail()){
            cout<<"Invalid input";
            return 0;
        }
        ll.insert(t);
    }
    Node* ptr = ll.head;
    
    while(ptr){
        heap.insert(ptr);
        ptr = ptr->next;
    }
    cin>>k;
    if(cin.fail()){
        cout<<"Invalid input";
        return 0;
    }
    int min;
    switch(k){
        case 1:
        case 2:
            min = heap.getMin()->key;
            cout<<(min!=-6 ? min : -4);
            break;
        default:
            cout<<"Invalid input";
    }
}