#include <iostream>
#include <string>

using namespace std;
string a;
int check(string x)
{
    int last=0,k,s;
    x=x+".";
    for (int i=0; i<x.size(); i++)
        if (x.compare(i,1,".")==0)
        {
            //if (x.compare(i+2,1,"0")>=0&&x.compare(i+2,1,"9")<=0) return
            k=1;s=0;
            for (int j=i-1; j>=last; j--)
            {
               s=s+k*(int(x.at(j))-48);
               k=k*10;

            }
            //cout <<x[last]<<endl;
            if (s<0 ||s>255) return false;
            if (x.compare(last,1,"0")==0&&s!=0) return false;

            last=i+1;
        }
    return true;
}
int diachiip(int solg,string x,int j)
{
    for (int i=j; i<x.size(); i++)
    {
        x.insert(i,".");
        solg++;
        if (solg<3 && i<x.size()-2) diachiip(solg,x,i+2);
        if (solg==3)
            if (check(x)) cout <<x<<endl;
        solg--;
        x.erase(i,1);
    }
}
int main()
{
    cin>>a;
    diachiip(0,a,1);
//    while (a.compare(0,1,"0")==0)
//        a.erase(0,1);
    //if (check(a)) cout <<"true"; else cout <<"false";
    //a.insert(6,".");
    //a.insert(3,".");
    //cout <<a;
}
