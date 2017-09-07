#include<iostream>
#include<vector>
#include<string>
#include<map>

// using std::string; using std::vector;
// using std::map; using std::cout; using std::cin; using std::basic_ostream;using std::ios;

using namespace std;

int main(){
int count=0;
string s;
map<string,int> counters;
cout << "Please impute several strings:"<<endl;
while (count<5 && cin>>s){
// the loop will terminate when "end" is entered or number of input == 5
if (s=="end"){
break;}
counters[s]++;
count++;
}
cout << "word frequency as following" << endl;
for (map<string,int>::const_iterator it = counters.begin(); it!=counters.end();it++){
cout << it->first <<"\t" << it->second << std::endl;

}

return 0;
}
