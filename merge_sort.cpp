#include<vector>
#include<iostream>
using namespace std;

void merge(int start,int end,vector<int>& result,vector<pair<int,int> >& enum_pair){
        if (end-start==1) return;
        int mid = (end-start)/2;
        merge(start,mid,result,enum_pair);
        merge(mid,end,result,enum_pair);
        vector<pair<int,int> >::const_iterator begin = enum_pair.begin()+start;
        vector<pair<int,int> >::const_iterator middle = enum_pair.begin()+mid;
	    vector<pair<int,int> >::const_iterator last = enum_pair.begin()+end;
        vector<pair<int,int> > left(begin,middle);
        vector<pair<int,int> > right(middle,last);
        for (int index = end-1;index>=start;index--){
            if (right.empty() || (!left.empty() &&left.back().second > right.back().second)){
                enum_pair[index]=left.back();
                result[left.back().first]+=right.size();
                left.pop_back();
            }
            else{
                enum_pair[index]=right.back();
                right.pop_back();
            }
        }
    }

int main() 
{
	int nums[]={1,3,2,5,4};
    vector<pair<int,int> > enum_pair(5);
    vector<int> result(5);
    for (int i=0;i<5;i++)
    {
        enum_pair[i]=make_pair(i,nums[i]);
    }
    merge(0,5,result,enum_pair);
    for (int i=0; i<result.size();i++)
    {
        cout << result[i] << endl;
    }
}
