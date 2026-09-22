#include <iostream>
#include  <string>
#include <cctype>
using namespace std;
bool is_palindrome(string str){
    int left =0;
    int right=str.length()-1;
    while(left<right){
        while(left<right && !isalnum(str[left])){
            left++;
        }
        while(left<right && ! isalnum(str[right])){
            right --;
        }
        if (tolower(str[left]) != tolower(str[right])){
            return false;
        }
        left ++;
        right --;
    }
    return true;
}
int main(){
    string input;
    cout<<"Enter a string "<<endl;
    getline(cin,input);
    if(is_palindrome(input)){
        cout<<"the string  "<< input<<" is palindrome. " <<endl;
    }else{
        cout<<" the "<<input<<"is not palindrome"<<endl;
    }
    return 0;
}