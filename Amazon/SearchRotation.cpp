//https://www.codingninjas.com/codestudio/problems/rotated-array_1093219?leftPanelTab=1
#include<bits/stdc++.h>
using namespace std;
int findPivot(int *arr, int low, int high, int n){
    while(low<=high){
        int mid = (low+high) >> 1;
        if(mid != n-1 && arr[mid] > arr[mid+1]){
            return mid+1;
        }
        else if(mid!=0 && arr[mid] < arr[mid-1]){
            return mid;
        }
        else if(arr[mid] > arr[0]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int rotatedArray(int arr[], int n)
{
    int pivot = findPivot(arr, 0, n-1, n);
    if(pivot == -1){
        return arr[0];
    }
    return arr[pivot];
}