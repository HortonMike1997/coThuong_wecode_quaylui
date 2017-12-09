#include <iostream>
#include <string>
using namespace std;
int n;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int ngoacdon(string a,int solg,int k)
{
	//cout<<a.size()<<endl;
	//cout <<a<<endl;
	for (int i=k+1; i<=a.size(); i++)
	{


			a.insert(i,"()");
			//cout <<a<<endl;
			if (solg<n) ngoacdon(a,solg+1,i);
			if (solg==n)
				cout <<a<<endl;
			a.erase(i,2);

	}
}
int main()
{
	string a="()";
	//a.insert(a.size(),"hihi");
	//cout<<a<<endl;
	cin>>n;
	//if (n==0) return 0;
	if (n<=1) cout <<a; else ngoacdon(a,2,0);
	return 0;
}
