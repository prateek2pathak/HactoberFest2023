#include<iostream>
using namespace std;
class queue{
    int *arr;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;
    public:
    // Creating array
    queue(int length){
        arr= new int [length];
        firstIndex=-1;
        nextIndex=0;
        capacity=length;
        size=0;
    }

    void enqueue(int data){
        if (size==capacity)
        {
            
        }
        
        if (firstIndex==-1)
        {
            firstIndex=0;
        }
        arr[nextIndex]=data;
        nextIndex=(nextIndex+1)%capacity;
        size++;
    }

    bool isEmpty(){
        return size==0;
    }

    int dequeue(){
        if (size==0)
        {
            cout<<"Oops! Queue is already empty "<<endl;
            return 0;
        }
        int data=arr[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        return data;
    }
    int getFront(){
        if(size==0){
            cout<<"Oops! Queue is empty "<<endl;
            return 0;
        }
        return arr[firstIndex];
    }
    int getSize(){
        return size;
    }

};

int main(){
    queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    cout<<q.getFront()<<endl;
    cout<<q.getSize()<<endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(10);
    q.enqueue(20);
    cout<<q.getSize()<<endl;
    q.enqueue(10);
    cout<<q.getSize()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getSize()<<endl;
    q.enqueue(20);
 
    cout<<q.getSize()<<endl;

    


    
    return 0;
}
