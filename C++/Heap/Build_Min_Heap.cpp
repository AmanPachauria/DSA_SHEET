#include <bits/stdc++.h> 

void heapify( vector<int> &arr, int n, int i ){
    int larger = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if( left < n && arr[larger] > arr[left] ){
        larger = left;
    }
    if( right < n && arr[larger] > arr[right] ){
        larger = right;
    }

    if( larger != i ){
        swap( arr[larger], arr[i] );
        heapify( arr, n, larger );
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for( int i = n/2; i >= 0; i-- ){
        heapify( arr, n, i );
    }

    return arr;
}
