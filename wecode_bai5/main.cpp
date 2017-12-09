#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
const int dong=100000, cot=100000 ;
string b;
string a[dong];
int n=0;
string da_use[dong];
int flag=0;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int noikytu(int i1, int j1, int k)
{
	//cout <<b[k]<<endl;
	for (int i=i1-1; i<=i1+1; i++)
		for (int j=j1-1; j<=j1+1; j++)
			if (j>=0 && j<a[i1].size() && i>=1 && i<=n)
				if (a[i].compare(j,1,b,k,1)==0&&da_use[i].compare(j,1,"0")==0)
				{
					//cout <<a[i][j]<<" so voi "<<b[k]<<endl;
					//cout <<b[k]<<" ";
//					da_use[i].erase(j,1);
//					da_use[i].insert(j,"1");
					da_use[i].replace(j,1,"1");
					if (k<b.size()-1) noikytu(i,j,k+1);
					if (k==b.size()-1)
					{
						//cout <<b[k]<<endl;
						cout <<"true";
						//flag=1;
						exit(0);
					}
					da_use[i].replace(j,1,"0");
				}

}
int main() {
	//getline(cin,b);
	cin>>b;
	//cout<<b<<endl;
	//string tmp="";
	while (a[n].compare(".")!=0)
	{
		n++;
		//getline(cin,a[n]);
		cin>>a[n];
	}
	n--;
	//for (int i=1; i<=n; i++)
//		cout <<a[i]<<endl;
	//cout <<a[2][2];
	for (int i=1; i<=n;i++)
        for (int j=0; j<a[2].size();j++)
            da_use[i].insert(0,"0");
    for (int i=1; i<=n;i++)
        //for (int j=0; j<a[1].size();j++)
            //cout <<da_use[i]<<endl;

	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<a[i].size();j++)
			if (a[i].compare(j,1,b,0,1)==0)
			{
				//cout <<a[i][j]<<" ";
				da_use[i].replace(j,1,"1");
				noikytu(i,j,1);
				//if (flag==1) return 0 ;

				da_use[i].replace(j,1,"0");
				//cout <<a[i][j]<<endl;
			}
	}
	cout <<"false";

}
