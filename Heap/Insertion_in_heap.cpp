#include<bits/stdc++.h>
using namespace std;

class heap{
   public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index >1 ){
            int parent = index/2;
            if( arr[parent] < arr[index] ){
                swap( arr[parent], arr[index] );
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for( int i = 0; i < 9; i++ ){
            cout<<arr[i]<<" ";
        }
    }
};


int main(){
    heap h;
    h.insert(54);
    h.insert(44);
    h.insert(40);
    h.insert(3);
    h.insert(4);
    h.insert(99);
    h.insert(56);

    h.print();
}