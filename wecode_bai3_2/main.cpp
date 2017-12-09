#include <iostream>
#include <string>

using namespace std;
int n;
bool check(string x)
{
    int s=0;
    for (int i=0; i<x.size(); i++)
    {

        //cout <<x[i]<<endl;
        if (x.compare(i,1,"(")==0) {s=s+1;}
        else s=s-1;
        //cout <<s<<endl;
        if (s<0){return false;}
    }
    if (s==0) return true;
        else return false;
}
int ngoacdon(string x,int k)
{
    string a[2];
    a[0]="("; a[1]=")";
    for (int i=0; i<2; i++)
    {
        x=x+a[i];
        if (k<2*n) ngoacdon(x,k+1);
        if (k==2*n)
            if (check(x))
                cout<<x<<endl;
        x.erase(x.size()-1,1);
    }

}

int main()
{
    cin >>n;
//    string k;
//    cin>>k;
//    if (check(k)) cout <<"ok";
//        else cout <<"false";
    ngoacdon("",1);
}
