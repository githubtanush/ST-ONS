#include<iostream>
#include<vector>
using namespace std;
void movezeroestoend(vector<int>& v){
    //Method 1 - One more extra constatnt array 
    // vector<int> temp(v.size(),0);
    // int index = 0;
    // for(int i = 0; i < v.size();i++) if(v[i] != 0) temp[index++] = v[i];
    // while(index < v.size()) temp[index++] = 0;
    // v = temp;    


    //Method2 - Use Two pointers for inplaced sorting
    // int left = 0;
    // int right = v.size()-1;
    // while(left < right){
    //     if(v[left] != 0) left++;
    //     else if(v[right] == 0) right--;
    //     else swap(v[left++],v[right--]);
    // }

    //Method 3 - if we want that order also does not change then 
    // int left = 0;
    // int right = 0;
    // while(right < v.size()){
    //     if(v[right] != 0 && v[left] != 0){
    //         right++;
    //         left++;
    //     }
    //     else if(v[right] == 0 && v[left] == 0) right++;
    //     else if(v[left] == 0 && v[right]!= 0) swap(v[left++],v[right++]);
    // }

    //Method 3 - if i want to maintain relative order and making the most optimal approach then i will try this 
    //slow fast pointer concept
    // int insert_pos = 0;
    // for(int fast = 0; fast < v.size(); fast++){
    //     if(v[fast] != 0)
    //         v[insert_pos++] = v[fast];
    // }

    // for(int i = insert_pos; i < v.size();i++) v[i] = 0;

    // for(int fast = 0,slow = 0; fast < v.size();fast++){
    //     if(v[fast] != 0)
    //         swap(v[slow++],v[fast]);
    // }

    //Method 4 - The Most optimal way idea of next permutation question also 
    // int n = v.size();
    // int j = -1;
    // for(int i = 0; i < n ; i++){
    //     if(v[i] == 0){
    //         j = i;
    //         break;
    //     }
    // }

    // if(j == -1) return ;

    // for(int i = j + 1; i < n ; i++)
    //     if(v[i] != 0) swap(v[i],v[j++]);
    
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n;i++) cin>>v[i];
    movezeroestoend(v);
    for(int i = 0; i < n ; i++) cout<<v[i]<<" ";
    return 0;
}