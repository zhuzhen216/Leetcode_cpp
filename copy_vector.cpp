#include<iostream>
#include<vector>
using namespace std;

int main()
{
// this g++ compiler can not compile vec1={1,2,3,4}
int array[] = {1,2,3,4,5};
vector<int> vec1(array,array+5);
vector<int> vec2;
for (int i=0; i<vec1.size(); i++)
{
vec2.push_back(vec1[i]);
}
cout << "New vector: \n";
for (int i=0; i<vec2.size(); i++)
{
cout << vec2[i] << " ";
cout << endl;
}
}
