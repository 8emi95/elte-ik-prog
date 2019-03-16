#include<iostream>
#include<vector>
#include<climits> //akt megvalósítás konstansai, pl INT_MAX

using namespace std;

void naiv(const vector<bool>& v);
void intes(const vector<bool>& v);
void sizeos(const vector<bool>& v);
void naiv_nemvegig(const vector<bool>& v);
void intes_nemvegig(const vector<bool>& v);
void sizeos_nemvegig(const vector<bool>& v);
int kezdo(const vector<bool>& v);

int main()
{
    vector<bool> v0(0);
    vector<bool> v1(1);
    vector<bool> v3(3);
    vector<bool> vmajdnem(INT_MAX-2);
    vector<bool> vmax(INT_MAX); //makró = vmennyi, így típus lesz, legkisebb olyan típus amiben még árbárzolni tudom
    vector<bool> vtobb(INT_MAX+2); //unsugned int

    cout<<"INT_MAX: "<<INT_MAX<<endl;   //2147483647
    cout<<"INT_MIN: "<<INT_MIN<<endl;   //-2147483648
    //cout<<((unsigned)-2147483648);      //NAIV-hoz magyarazat
    //cout<<((unsigned)-2147483647);

    /*cout<<"NAIV"<<endl;
    naiv(v0);
    naiv(v1);
    naiv(v3);
    naiv(vmajdnem);
    naiv(vmax);
    naiv(vtobb);*/
    /*cout<<"INTES"<<endl;
    intes(v0);
    intes(v1);
    intes(v3);
    intes(vmajdnem);
    intes(vmax);
    intes(vtobb);*/
    /*cout<<"SIZE-OS"<<endl;
    sizeos(v0);
    sizeos(v1);
    sizeos(v3);
    sizeos(vmajdnem);
    sizeos(vmax);
    sizeos(vtobb);*/
    /*cout<<"NAIV NEM VEGIG"<<endl;
    naiv_nemvegig(v0);
    naiv_nemvegig(v1);
    naiv_nemvegig(v3);
    naiv_nemvegig(vmajdnem);
    naiv_nemvegig(vmax);
    naiv_nemvegig(vtobb);*/
    /*cout<<"INTES NEM VEGIG"<<endl;
    intes_nemvegig(v0);
    intes_nemvegig(v1);
    intes_nemvegig(v3);
    intes_nemvegig(vmajdnem);
    intes_nemvegig(vmax);
    intes_nemvegig(vtobb);*/
    /*cout<<"SIZE-OS NEM VEGIG"<<endl;
    sizeos_nemvegig(v0);
    sizeos_nemvegig(v1);
    sizeos_nemvegig(v3);
    sizeos_nemvegig(vmajdnem);
    sizeos_nemvegig(vmax);
    sizeos_nemvegig(vtobb);*/
    return 0;
}

void naiv(const vector<bool>& v)
{
    cout<<"<kiiras>"<<endl;
    for(int i=kezdo(v);i<v.size();++i)
        cout<<i<<endl;
    cout<<"</kiiras>"<<endl;
}

void intes(const vector<bool>& v)
{
    cout<<"<kiiras>"<<endl;
    for(int i=kezdo(v);i<(int)v.size();++i)
        cout<<i<<endl;
    cout<<"</kiiras>"<<endl;
}

void sizeos(const vector<bool>& v)
{
    cout<<"<kiiras>"<<endl;
    for(size_t i=kezdo(v);i<v.size();++i)
        cout<<i<<endl;
    cout<<"</kiiras>"<<endl;
}

void naiv_nemvegig(const vector<bool>& v)
{
    cout<<"<kiiras>"<<endl;
    for(int i=kezdo(v);i<v.size()-1;++i)
        cout<<i<<endl;
    cout<<"</kiiras>"<<endl;
}

void intes_nemvegig(const vector<bool>& v)
{
    cout<<"<kiiras>"<<endl;
    for(int i=kezdo(v);i<(int)v.size()-1;++i)
        cout<<i<<endl;
    cout<<"</kiiras>"<<endl;
}

void sizeos_nemvegig(const vector<bool>& v)
{
    cout<<"<kiiras>"<<endl;
    for(size_t i=kezdo(v);i<v.size()-1;++i)
        cout<<i<<endl;
    cout<<"</kiiras>"<<endl;
}

int kezdo(const vector<bool>& v) //ennek is size_t-nek kene lennie, de mivel az INT_MAX-5 meg belefer, ezert nem okoz gondot.
{
    return v.size() < INT_MAX-5 ? 0 : INT_MAX-5;
}
