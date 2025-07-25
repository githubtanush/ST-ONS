#include<iostream>
#include<vector>
using namespace std;
void inputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cin>>arr[i];
}
void outputarr(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < arr.size();i++) cout<<arr[i]<<" ";
}
int largest(vector<int>& arr){
    //brute force - time complexity - O(Nlogn)
    //Space complexity - O(1)
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];

    //optimal - iteration - O(N)
    //space complexity - O(1)
    int maxi = INT_MIN;
    for(int i = 0; i < arr.size();i++) if(arr[i] > maxi) maxi = arr[i];
    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    inputarr(arr);
    cout<<largest(arr)<<endl;
    outputarr(arr);
    return 0;
}