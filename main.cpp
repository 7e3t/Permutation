#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

fstream myfile("mytext.txt",ios:: app | ios::in | ios::out);
void func(string,int);
int m=0;
int main()
{
    string str;
    cin >> str;
    func(str,0);
    myfile.close();
    cout << m;
    return 0;
}

void func(string str,int q)
{
    int len = str.length();
    string temp = str;
    for(int i=q;i<len;i++){
        swap(str[q],str[i]);
        if(q==len-3) {
            for(int i=0;i<3;i++){
                myfile << str << endl;
                //cout << str << endl;
                m++;
                for(int ii=len-1;ii>len-3;ii--){
                    swap(str[ii],str[ii-1]);
                }
            }
            if(i==len-2) break;
        }
        else func(str,q+1);
        str = temp;
    }
}
