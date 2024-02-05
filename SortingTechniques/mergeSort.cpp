#include<bits/stdc++.h>
using namespace std;
void merge(int arr[] , int low, int mid, int high)
{
    int temp[high-low+1];
    int left=low;
    int right=mid+1;
    int i=0;
    while(left<=mid&&right<=high)
    {
        if(arr[left]<arr[right])
        {
            temp[i]=arr[left];
            i++;
            left++;
        }
        else
        {
            temp[i]=arr[right];
            right++;
            i++;
        }
    }
    while(left<=mid)
    {
        temp[i]=arr[left];
            i++;
            left++;
    }
    while(right<=high)
    {
        temp[i]=arr[right];
            right++;
            i++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
}

void ms(int arr[], int l, int r){

    if(l==r) return;
    int mid=(l+r)/2;
    ms(arr,l,mid);
    ms(arr,mid+1,r);
    merge(arr,l,mid,r);

}
void mergeSort(int arr[], int l, int r) {

    ms(arr,l,r);
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int l, r;
    cin >> l >> r;

    mergeSort(arr , l, r);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}