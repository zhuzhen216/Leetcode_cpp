#include<vector>
#include<string>
#include<iostream>
#include "split.h"
using std::string;
using std::vector;
//using namespace std

int main(){
string str;
vector<string> splited;
//int i;
std::cout << "Please input a long string:" <<std::endl;
//std::cin >> str;
getline(std::cin,str);
splited = split(str);
for(int i=0;i<splited.size();i++){
std::cout << splited[i] <<std::endl;
}
}
