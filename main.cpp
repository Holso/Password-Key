#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;
ifstream fip("trifid.txt");
char sir[1000][1000];
int verti[1000][10000],gata[10000];
char a1[1000][1000],a2[1000][1000],a3[1000][1000];
char ana[10000],fin[10000];
int main()
{
    int i,j,k,v,f,pri,doi,u,c,un,di;
    u=0;
    cout<<"Numarul care indica ceea ce vreti sa faceti: ";
    cin>>c;
    for(i=1; i<10; i++)
        for(j=1; j<10; j++)
            fip>>sir[i][j];
    cout<<"Parola care vreti sa fie transformata: ";
    cin>>ana;
    for(i=1; i<4; i++)
    {
        k=1;
        for(j=1; j<4; j++)
            a1[i][j]=sir[i][j];
        for(j=4; j<7; j++,k++)
            a2[i][k]=sir[i][j];
        k=1;
        for(j=7; j<10; j++,k++)
            a3[i][k]=sir[i][j];
    }
    f=1;
    if(c==1)//anaaremere
    {
        for(i=0; i<strlen(ana); i++)
        {
            char d=ana[i];
            for(j=1; j<4; j++)
            {
                for(k=1; k<4; k++)
                {
                    if(a1[j][k]==d)
                    {
                        verti[1][f]=1;
                        verti[2][f]=k;
                        verti[3][f]=j;
                        f++;
                    }
                    if(a2[j][k]==d)
                    {
                        verti[1][f]=2;
                        verti[2][f]=k;
                        verti[3][f]=j;
                        f++;
                    }
                    if(a3[j][k]==d)
                    {
                        verti[1][f]=3;
                        verti[2][f]=k;
                        verti[3][f]=j;
                        f++;
                    }
                }
            }
        }
        i=1;
        for(j=1; j<4; j++)
            for(k=1; k<=strlen(ana); k++)
                gata[i++]=verti[j][k];
        for(i=1,k=1; k<=strlen(ana); i=i+3,k++)
        {
            if(gata[i]==1)
            {
                pri=gata[i+1];
                doi=gata[i+2];
                fin[u++]=a1[doi][pri];
            }
            if(gata[i]==2)
            {
                pri=gata[i+1];
                doi=gata[i+2];
                fin[u++]=a2[doi][pri];
            }
            if(gata[i]==3)
            {
                pri=gata[i+1];
                doi=gata[i+2];
                fin[u++]=a3[doi][pri];
            }

        }
        cout<<fin<<endl;
    }
    else if(c==2) //i.lkssffexdogj
    {
        for(i=1; i<4; i++)
        {
            k=1;
            for(j=1; j<4; j++)
                a1[i][j]=sir[i][j];
            for(j=4; j<7; j++,k++)
                a2[i][k]=sir[i][j];
            k=1;
            for(j=7; j<10; j++,k++)
                a3[i][k]=sir[i][j];
        }
        f=1;
        v=1;
        for(k=0; k<strlen(ana); k++)
        {
            char t=ana[k];
            for(i=1; i<4; i++)
            {
                for(j=1; j<4; j++)
                {
                    if(a1[i][j]==t)
                    {
                        gata[v++]=1;
                        gata[v++]=j;
                        gata[v++]=i;
                    }
                    if(a2[i][j]==t)
                    {
                        gata[v++]=2;
                        gata[v++]=j;
                        gata[v++]=i;
                    }
                    if(a3[i][j]==t)
                    {
                        gata[v++]=3;
                        gata[v++]=j;
                        gata[v++]=i;
                    }
                }
            }
        }
        u=0;
        for(i=1; i<strlen(ana)+1; i++)
        {
            pri=i+strlen(ana);
            doi=i+(2*strlen(ana));
            un=gata[pri];//coloane
            di=gata[doi];//lini
            if(gata[i]==1)
                fin[u++]=a1[di][un];
            if(gata[i]==2)
                fin[u++]=a2[di][un];

            if(gata[i]==3)
                fin[u++]=a3[di][un];
        }
        cout<<fin;
    }
    return 0;
}
