#include<string>
#include<iostream>

using std::string;
bool is_palindrome(const string& s){
int start=0;
int end = s.size()-1;
if (end==-1 || end==0){
return true;
}

while (start<end){
if (s[start]!=s[end]){
return false;
}
start++;
end--;

}

return true;

}


bool is_palindrome_2(const string& s){

return equal(s.begin(),s.end(),s.rbegin());

}

int main(){
string toCheck;
std::cout << "Please input a string:" << std::endl;
std::cin >> toCheck;
if (is_palindrome(toCheck)){
std::cout<<toCheck + " is a palindrome!"<<std::endl; 
}
else{
std::cout<<toCheck + " is not a palindrome!"<<std::endl;
}
}
