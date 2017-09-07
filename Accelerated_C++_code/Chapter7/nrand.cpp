#include <cstdlib>
#include<iostream>
using namespace std;

int nrand(int n){

if (n<0 || n > RAND_MAX){
throw domain_error("Argument to nrand is out of range.");
}
const int bucket_size = RAND_MAX/n;
int ret;

ret = rand()/bucket_size;
int count = 0;
while (ret>n or count>100){
ret = rand()/bucket_size;
count++;
}
return ret;
}

int main(){

int ret;
int n;
cout << "please input the range"<<endl;
cin>>n;
for (int count=0; count <10; count++){
ret = nrand(n);
cout << ret <<endl;
}

return 0;
}
