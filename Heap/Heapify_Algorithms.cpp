#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i ){
    int larger = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if( left < n && arr[larger] < arr[left] ){
        larger = left;
    }
    if( right < n && arr[larger] < arr[right] ){
        larger = right;
    }

    if(larger != i ){
        swap( arr[larger], arr[i] );
        heapify( arr, n, larger );
    }

    return;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5 };
    int n = 5;

    for( int i = n/2; i >= 0; i-- ){
        heapify(arr, n, i );
    }

    for( int i = 0; i < n; i++ ){
        cout<<arr[i]<<" ";
    }

    return 0;
}