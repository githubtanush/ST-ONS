#include<iostream>
using namespace std;
bool isPalindrome(string s) {
    //Method 1 - The brute force mein sidhi si baat hai reverse krunga chup chap or dono ko check kr lunga
    //kahani khatam The END
    string str;
    for(auto& x : s){
        if(isalnum(x)) str.push_back(tolower(x));
    }

    string str2;
    for(int i = str.size()-1; i >= 0; i--) str2.push_back(str[i]);

    for(int i = 0; i < str.size();i++){
        if(str[i] != str2[i]) return false;
    }
    return true;

    //Method 2 - ek new clean string bnai or simple us par two pointer lga kar check kr liya same hai ya nhi..
    //    string str;
    //    for(auto& x : s){
    //     if(isalnum(x)) str.push_back(tolower(x));
    //    }
    //    int low = 0;
    //    int high = str.size()-1;
    //     while(low <= high){
    //         if(str[low] != str[high]) return false;
    //         low++;
    //         high--;
    //     }
    //    return true;


    //Method 3 - Try to solve in O(1) optimized space 
    // int left = 0;
    // int right = s.size()-1;
    // while(left < right){
    //     if(isalnum(s[left]) && isalnum(s[right])) {
    //         if(tolower(s[left]) != tolower(s[right])) return false;
    //         left++;
    //         right--;
    //     }
    //     else if (isalnum(s[left])) right--;
    //     else left++;
    // }
    // return true;
    }
int main(){
    string s;
    getline(cin,s);
    if(isPalindrome(s)) cout<<"The string is the palindromic String"<<endl;
    else cout<<"The string is not the palindromic string"<<endl;
    return 0;
}