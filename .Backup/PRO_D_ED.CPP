#include<fstream.h>
#include<conio.h>
#include<string.h>

int conv(char line[],char cng[])
{
 int l2,i,j;
 char elt[]={"Berrylium"};
 char wd[20];
 for(l2=0;elt[l2]!='\0';l2++);
 int l1,wc=-1;
 for(l1=0;line[l1]!='\0';l1++);
 for(i=0;i<l1;i++)
 {
  for(j=0;j<l2;j++)
  wd[j]=line[i+j];
  wd[j]='\0';
  if(strcmpi(wd,elt)==0)
   {
    if(line[i-1]==' ' && line[i+l2]==' ')
    wc++;
    if(i==0 && line[l2]==' ')
    wc++;
    if(i==l1-l2 && line[i+l2]=='\0')
    wc++;
    for(int k=0;elt[k]!='\0';k++)
    line[i+k]=cng[k];
   }
 }
 return wc;
}

void main()
{
 clrscr();
 fstream nfile,qfile,fqfile;
 nfile.open("e_name.txt",ios::in);
 qfile.open("pro_qu~1.txt",ios::in);
 char qstr[100];
 char name[30];
 fqfile.open("e_quest.txt",ios::out);
 while(!nfile.eof())
 {
   nfile.getline(name,30,'\n');
   if(nfile.eof())
   break;
   qfile.getline(qstr,100,'\n');
   int ch=conv(qstr,name);
   cout<<qstr<<endl;
   fqfile<<qstr<<endl;
   getch();
 }
 cout<<"Over";
 nfile.close();
 qfile.close();
 getch();
}