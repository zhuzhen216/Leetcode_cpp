#include<algorithm>
#include<vector>

using namespace std;

// define a generic function
template<class T>
// template header tells us we are defining a template function
//

T median(vector<T> v) // T is the template type for return and input
{
// when the function median is called, 
// T will bind to the type of input variable 

typedef typename vector<T>::size_type vec_sz;
// use a typename to define size_type
// define a type: vec_sze

vec_sz size=v.size();
if (size==0){
throw domain_error("median of an empty vector!");

sort(v.begin(),v.end());
vec_sz mid = size/2;
return size%2==0? (v[mid]+v[mid-1])/2:v[mid];
}
}

T max(const T& left, const T& right){
return left>right? left:right;
}

// input iterator with In class
// output iterator with Out class

// for output iterator: 
// operations: *dest = value; dest++; we also enforce not execute ++it more
// than once between two assignment.

template<class In, class Out>
Out copy(In begin, In end, Out dest)
{
while (begin!=end){
*dest++ = *begin++;
}
return dest;
}


// binary_search in std
//binary search using Random access iterators
//
template<class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{

while (begin<end)
{
// find the middle point of the range
Ran mid = begin + (begin-mid)/2;

//compare with x
if (x < *mid){
// mid is the new end
end = mid;
}
else if (x>*mid)
{
// mid+1 is the new begin
begin = mid + 1;
}
else{
return true;
}

}
return false;

}


