
#include <iostream>

#include <vector>
using namespace std;

#define MAX_SIZE 64

void BigInt_ADD(string a, string b)
{
    int arr1[MAX_SIZE]={0};
    int arr2[MAX_SIZE]={0};



    int i=0;
    while(a[i]!='\0')
    {
        arr1[i]=(a[i]-48);
        i++;
    }

    int j=0;
    while(b[j]!='\0')
    {
        arr2[j]=(b[j]-48);
        j++;
    }
    int place=0,carry=0,ans=0;
  
    

    if(i>=j)
    {   
         int temp=i-1;

        while(j!=0)
        {
            place = arr1[i-1]+arr2[j-1];
            ans=place%10;

            arr1[i-1]=ans+carry;

            carry=place/10;

            
            i--;
            j--;

        }
       do
       {    
           arr1[i-1]=arr1[i-1]+carry;

            carry= arr1[i-1]/10;

            if(carry>0)
            {
            arr1[i-1]=arr1[i-1]%10;
            }

            i--;
       } 
       while (carry!=0 && i!=0);
        arr1[0]=arr1[0] + carry*10;
       


        for(int x=0;x<=temp;x++)
        cout<<arr1[x];

    }

    else{

        int temp= j-1;
        while(i!=0)
        {
            place = arr1[i-1]+arr2[j-1];
            ans=place%10;

            arr2[j-1]=ans+carry;

            carry=place/10;

            
            i--;
            j--;

        }
        do
       {    
           arr2[j-1]=arr2[j-1]+carry;

            carry= arr2[j-1]/10;

            if(carry>0)
            {
            arr2[j-1]=arr2[j-1]%10;
            }

            j--;
       } 
       while (carry!=0 && j!=0);
        arr2[0]=arr2[0] + carry*10;
       


        for(int x=0;x<=temp;x++)
        cout<<arr2[x];

    }



}


int main()
{
    string a="999367";

    string b ="956";

    BigInt_ADD(b,a);

}














