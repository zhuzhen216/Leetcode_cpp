#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;


vector<string> split(string line){
vector<string> ret;
for (int i=0; i<line.length();i++){
if (isspace(line[i])){
continue;}
else{
int j = i + 1;
while (j<line.length() && !isspace(line[j])){
j++;
}
ret.push_back(line.substr(i,j-i));
i=j;
}
}
return ret;
}

map<string,vector<int> > xref(istream& in){
int line_number = 0;
map<string,vector<int> > word_linenumber;
string wordline;
// vector<string> word_list;

while(getline(in,wordline)){
if (wordline=="end"){
break;
}
++line_number;
vector<string> words = split(wordline);
for (vector<string>::const_iterator it = words.begin();it!=words.end();it++){
word_linenumber[*it].push_back(line_number);
}
}
return word_linenumber;
}

int main(){
/* debug for function split()
vector<string> check_line = split("line check!");
cout<<"check words" <<endl;
for (vector<string>::const_iterator it=check_line.begin();it!=check_line.end();it++){
cout << *it << endl;
}
*/
map<string,vector<int> > word_map;
word_map = xref(cin);
for (map<string,vector<int> >::const_iterator it = word_map.begin();it!=word_map.end();it++){
cout << it->first << " occurs on lines:";
int line_it = 0;
// vector<int>::const_iterator line_it = it->second.beign();
while (line_it<it->second.size()){
cout << it->second[line_it] << ",";
line_it++;
}
cout << endl;
}
return 0;
}
