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
void movezeroend(vector<int>& arr){
    int n = arr.size();
    //Method 1 - Make one temporary array and then insert non zero element serial wise and in the end lastly 
    //insert zero according to zerocnt
    //Time complexity - O(2N)
    //Space complexity - O(N)
    // int zerocnt = 0;
    // vector<int> temp(arr.size());
    // int index = 0;
    // for(int i = 0; i < arr.size();i++){
    //     if(arr[i] != 0) temp[index++] = arr[i];
    //     else zerocnt++;
    // }
    // while(zerocnt--) temp[index++] = 0;
    // arr = temp;


    //Method 2 - Two pointers nu bulana hai 
    //Time complexity - O(N)
    //Space complexity - O(1)
    // int left = 0;
    // int right = arr.size()-1;
    // while(left < right){
    //     if(arr[left] != 0) left++;
    //     else if(arr[right] == 0) right--;
    //     else {
    //         swap(arr[left],arr[right]);
    //         left++;
    //         right--;
    //     }
    // }

    //Method 3 - O(n) traversal but without changing positions
    //Time complexity - O(N)
    //Space complexity - O(1)
    // int count = 0;
    // for(int i = 0; i < n ;i++){
    //     if(arr[i] != 0){
    //         swap(arr[i],arr[count]);
    //         count++;
    //     }
    // }

    //2nd way to optimize with 2 pointers
    //Time complexity - O(N)
    //Space complexity - O(1)
    //and also in place changing no one position is changed
    int j = -1;
    for(int i = 0;i < n ; i++){
        if(arr[i] == 0){
            j = i ; 
            break;
        }
    }

    //no zeroes
    if(j == -1) return ;

    //if zeroes occur then
    for(int i = j + 1; i < n ; i++)
        if(arr[i] != 0) swap(arr[i],arr[j++]);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    inputarr(arr);
    movezeroend(arr);
    outputarr(arr);
    return 0;
}
