#include <iostream>
using namespace std;
int&  f(int a)
{   a++;    return a; }
int main( )
{   
    int i=3;
    cout<<i<<endl;
    f(i);
    cout<<i<<endl;
}
