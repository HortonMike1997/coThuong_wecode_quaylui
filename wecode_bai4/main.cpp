#include <iostream>
//#include <fstream>
#include  <cmath>

using namespace std;
const int maxptu=10;
float a[maxptu],s1[maxptu];
int n;
float m,m2,m3;
//ofstream myfile;

int Xuly(int j,float s)
{
    for (float i=0.25; i<=10;i=i+0.25)
    {
        if (s+i*a[j]<=m2)
        {
            s1[j]=i;
            if (j<n-1) Xuly(j+1,s+i*a[j]);
            if (s+i*a[j]>=m3&&s+i*a[j]<=m2 && j==n-1)
            {
                for (int k=0; k<=n-1;k++)
                    cout << s1[k]<<" ";
                    //myfile << s1[k]<<" ";
                cout <<endl;
                //myfile <<endl;

            }
        }
    }
}

int main()
{

    //myfile.open ("example.txt");
    float tmp;
    cin>>n;
    for (int i=0; i<n;i++)
    {
        cin>>tmp;
        a[i]=tmp/100;
    }
    cin>>m;
    tmp=m*10;
    tmp=round(tmp);
    m=tmp/10;
    //cout <<m;

    m2=m+0.04;m3=m-0.05;
    //m2=m;
    //m3=m;
    Xuly(0,0);
    //myfile.close();

}
