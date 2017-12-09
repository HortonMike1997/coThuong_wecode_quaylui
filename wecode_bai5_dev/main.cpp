#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
const int dong=10, cot=10 ;
string b;
string a[dong];
int n=0;
int da_use[dong][cot];

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int noikytu(int i1, int j1, int k)
{
	//cout <<b[k]<<endl;
	for (int i=i1-1; i<=i1+1; i++)
		for (int j=j1-1; j<=j1+1; j++)
			if (j>=0 && j<=a[i].size() && i>=1 && i<=n)
				if (a[i].compare(j,1,b,k,1)==0&&da_use[i][j]==0)
				{
					//cout <<a[i][j]<<" so voi "<<b[k]<<endl;
					da_use[i][j]=1;
					if (k<b.size()-1) noikytu(i,j,k+1);
					if (k==b.size()-1)
					{
						//cout <<b[k]<<endl;
						cout <<"true";
						exit(0);
					}
					da_use[i][j]=0;
				}
}
int main() {
	getline(cin,b);	
	//cout<<b<<endl;
	//string tmp="";
	while (a[n].compare(".")!=0)
	{
		n++;
		getline(cin,a[n]);
	}
	n--;
	//for (int i=1; i<=n; i++)
//		cout <<a[i]<<endl;
	//cout <<a[2][2];
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<=a[i].size();j++)
			if (a[i].compare(j,1,b,0,1)==0)
			{
				da_use[i][j]=1;
				noikytu(i,j,1);
				da_use[i][j]=0;
				//cout <<a[i][j]<<endl;
			}
	}
	cout <<"false";
}
