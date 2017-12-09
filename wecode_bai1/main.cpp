#include <iostream>
#include <string>

using namespace std;
//const int maxptu=300;
string a;
int n1;
bool check_doi_xung(string x)
{
    int tmp;
    x=x+" ";
    int n=x.size()+1;
    int last=0;
    for (int i=0; i<n; i++)
    {
        if (x.compare(i,1," ")==0)
        {
            tmp=(i-last)/2;
            tmp=last+tmp;
            for (int j=last; j<=tmp; j++)
            {
                if (x[j]!=x[i-(j-last)-1]) {return false;}
            }
            last=i+1;
        }
    }
    return true;
}
int addspace(int solg,string x,int k)
{
    //int n=x.size()+1;
    for (unsigned i=1; i<k; i++)
        if (x.compare(i,1," ")!=0&&x.compare(i-1,1," ")!=0)
        {
            x.insert(i," ");
            //cout<<x<<endl;
            //k++;
            if (check_doi_xung(x)) cout <<x<<endl;
            if (solg<n1-1) addspace(solg+1,x,i);
            x.erase(i,1);
        }
}

int main()
{
    getline(cin,a);
    if (check_doi_xung(a)) cout <<a<<endl;;
    n1=a.size();
    addspace(1,a,a.size());
//    if (check_doi_xung(a)) cout <<"check";
//    else cout <<"fail";


}
