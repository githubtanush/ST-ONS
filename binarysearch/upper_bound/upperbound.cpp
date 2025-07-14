#include<iostream>
using namespace std;
int binarysearch(vector<int>& arr,int target){
    int n = arr.size();
    int s = 0;
    int ans = -1;
    int e = n - 1;
    while( s <= e ){
        int mid = s + ( e - s )/2;
        if(arr[mid] == target){
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid] < target) e = mid - 1;
        else s = mid + 1;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i < n ;i++) cin>>arr[i];
    int target;
    cin>>target;
    cout<<binarysearch(arr,target)<<endl;

    return 0;
}