#include<bits/stdc++.h>
using namespace std;
void merge(long long *arr, long long l, long long mid, int h){
    int temp[h-l+1];
    int i = l;
    int j = mid;
    int k = 0;
    while(i < mid && j <= h){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            //count inversion += mid - i
        }
    }
    while(i<mid){
        temp[k++] = arr[i++];
    }
    while(j <= h){
        temp[k++] = arr[j++];
    }
    int k = 0;
    for(int i = l; i<=h; i++){
        arr[i] = temp[k++];
    }
}


void mergesort(long long *arr, long long l, long long h)
{
    while(l<h){
        int mid = (l+h)>>1;
        mergesort(arr,l, mid);
        mergesort(arr, mid+1, h);
        merge(arr, l, mid+1, h);
    }
}