#include <iostream>

using namespace std;
const int maxptu=10000;
int n;
int a[maxptu],dabop[maxptu];
int max1=0;
int bopbongbong(int solg, int s)
{
    int tmp,x,y;
    for (int i=0; i<n; i++)
    {
        if (dabop[i]==0)
        {
            solg++;
            dabop[i]=1;
            tmp=i;
            while (dabop[tmp]==1 && tmp>0)
                tmp--;
            if (dabop[tmp]==0) x=a[tmp];
                else x=1;
            tmp=i;
            while (dabop[tmp]==1 && tmp<n-1)
                tmp++;
            if (dabop[tmp]==0) y=a[tmp];
                else y=1;
            s=s+a[i]*x*y;
            if (solg<n) bopbongbong(solg,s);
            if (solg==n)
                if (s>max1) max1=s;
            s=s-a[i]*x*y;
            solg--;
            dabop[i]=0;
        }

    }
}
int main()
{
    cin>>n;
    for (int i=0; i<n;i++)
        cin>>a[i];
//    for (int i=0; i<n;i++)
//        cout <<a[i]<<" ";
    bopbongbong(0,0);
    cout <<max1;
}
