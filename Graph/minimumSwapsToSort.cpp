//https://practice.geeksforgeeks.org/viewSol.php?subId=1c0df8f9328098d83628d275072f6613&pid=700384&user=kkunal
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N){
    pair<int,int> arr[N];
    for(int i=0;i<N;i++){
        arr[i].first = A[i];
        arr[i].second = i;
    }
    sort(arr,arr+N);
    vector<bool> visited(N,false);
    int answer=0;
    int cycle=0;
    
    for(int i=0;i<N;i++){
        int j=i;
        if(visited[i] || arr[i].second == i)
            continue;
        cycle=0;
        while(!visited[j]){
            visited[j]=1;
            j=arr[j].second;
            cycle++;
        }
        if(cycle>0){
            answer+=cycle-1;
        }
    }
    return answer;
}