#include<bits/stdc++.h>
using namespace std;

int leftIndex(int n, int arr[], int X){
    
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high) >> 1;
        if(arr[mid] == X && (mid == 0 || arr[mid-1] != X)){
            return mid;
        }
        else if((arr[mid] == X && arr[mid -1] == X)||(arr[mid] > X)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}