#include<iostream>
#include<cmath>
#include<string>
#include<bits/stdc++.h>
#include<vector>

using namespace std;
int main()
{
    ifstream input;
    input.open("new1.txt");
    ofstream output;
    output.open("ques1.txt");
    long long int t;
    input >> t;
    long long int i;
    for(i=1;i<=t;i++)
    {
        long long int a,b,c;
        input >> a;
        string m,n;
        input >> m >> n;
        char s[a][a];
        for(b=0;b<a;b++)
        {
            for(c=0;c<a;c++)
            s[b][c]='N';
        }
        for(b=0;b<a;b++)
        s[b][b]='Y';
        for(b=0;b<a;b++)
        {
            if(m[b]=='N')
            {
                for(c=0;c<a;c++)
                s[c][b]='N';
                s[b][b]='Y';
            }
            if(n[b]=='N')
            {
                for(c=0;c<a;c++)
                s[b][c]='N';
                s[b][b]='Y';
            }
        }
        for(b=1;b<a-1;b++)
        {
            if(m[b]=='Y' && n[b-1]=='Y')
            s[b-1][b]='Y';
            if(m[b]=='Y' && n[b+1]=='Y')
            s[b+1][b]='Y';
        }
        if(m[0]=='Y' && n[1]=='Y')
        s[1][0]='Y';
        if(m[a-1]=='Y' && n[a-2]=='Y')
        s[a-2][a-1]='Y';
        long long int j,k,x,y,z;
        for(j=0;j<a;j++)
        {
            for(k=0;k<a;k++)
            {
                if(s[j][k]=='Y')
                {
                    for(x=0;x<a;x++)
                    {
                        if(s[x][j]=='Y')
                            s[x][k]='Y';
                    }
                }
            }
        }


        output << "Case #" << i << ":" << endl;
        for(b=0;b<a;b++)
        {
            for(c=0;c<a;c++)
            {
                output << s[b][c];
            }
            output << endl;
        }
    }
}