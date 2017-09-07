#include<vector>
#include<string>
#include<cctype>
using std::string;
using std::vector;

// start of function
vector<string> split_string(const string & str){
vector<string> ret;
typedef string::size_type string_size;
string_size i = 0;
while (i!=str.size()){
//ignore leading blanks
//invariant: characters in range [original i, current i) for all spaces
	while(i!=str.size() && isspace(str[i])){
		++i;
}

// find end of next word
string_size j = i;
// invariant: none of the characters in range [original j, current j) is space
while (j!=str.size() && !isspace(str[j])){
	j++;
}
if (i!=j){
	// copy from s[i:j) to ret
	ret.push_back(str.substr(i,j-i));
	i=j;
}

}
return ret;

}
