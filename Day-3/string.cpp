#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string first_name="Pranav";
    int i;
    for(i=0;i<6;i++)
    {
         if(first_name[i]=='h') 
         {
            cout<<"h is present";
            break;
         }
    }
    cout<<i<<endl;
    if(i==6)
    {
      cout<<"h is absent";
    }

}