#include<fstream.h>
#include<conio.h>
#include<INFNEW.cpp>
#include<dos.h>
#include<iomanip.h>
#include<stdlib.h>

void randomarr(int rec[],int n)
{
 int i,ch=0,flag;
 for(i=0;i<n;i++)
 rec[i]=0;
 int num;
 randomize();
 while(ch<=n-1)
 {
  flag=0;
  num=random(n);
  for(i=0;i<ch;i++)
  {
   if(rec[i]==num)
   flag=-1;
  }
  if(flag==0)
  {
   rec[ch]=num;
   ch++;
  }
 }
}

void blk(char temp[][30])
{
 int num[4];
 randomarr(num,4);
 for(int i=0;i<4;i++)
 {
  switch(num[i])
  {
   case 0:strcpy(temp[i],"S - Block");
	  break;
   case 1:strcpy(temp[i],"P - Block");
	  break;
   case 2:strcpy(temp[i],"D - Block");
	  break;
   case 3:strcpy(temp[i],"F - Block");
	  break;
  }
 }
}

void defwrite()
{
 element e;
 coord c;
 data d;
 quest qq[5];
 int i;
 char block[4][30];
 fstream nfile,amfile,anfile,cfile,grpfile,sfile,qfile;
 fstream opt1,opt2,opt3,opt5;
 fstream efile,coordfile;
 nfile.open("e_name.txt",ios::in);
 cfile.open("e_config.txt",ios::in);
 grpfile.open("e_gpn.txt",ios::in);
 anfile.open("e_atn.txt",ios::in);
 amfile.open("e_am.txt",ios::in);
 sfile.open("e_sym.txt",ios::in);
 qfile.open("e_quest.txt",ios::in);
 opt1.open("e_opt1.txt",ios::in);
 opt2.open("e_opt2.txt",ios::in);
 opt3.open("e_opt3.txt",ios::in);
 opt5.open("e_opt5.txt",ios::in);
 char temp[200]={"A"};
 efile.open("E_data.dat",ios::binary | ios :: out);
 coordfile.open("e_coord.dat",ios::binary | ios :: in);
 while(!nfile.eof())
 {
  nfile.getline(d.name,30,'\n');
  if(nfile.eof())
  break;
  cfile.getline(d.config,30,'\n');
  grpfile.getline(d.grp,30,'\n');
  anfile.getline(d.atn,30,'\n');
  amfile.getline(d.atm,30,'\n');
  sfile.getline(d.sym,30,'\n');
  for(i=0;i<5;i++)
  qfile.getline(qq[i].qstn,200,'\n');
  coordfile.read((char*)&c,sizeof(c));
  cout<<setw(15)<<d.name<<"\t";
  cout<<setw(15)<<d.config<<"  ";
  cout<<setw(3)<<d.grp<<"  ";
  cout<<setw(3)<<d.atn<<"  ";
  cout<<setw(6)<<d.atm<<"  ";
  cout<<setw(3)<<d.sym<<"  ";
  cout<<setw(5)<<c.x<<"  "<<setw(4)<<c.y<<"  "<<setw(3)<<c.col<<"\n";
  e.putcoord(c);
  e.putd(d);
  e.putq(qq);
  e.putblktypepd();
  e.getdata(d,qq,c);
  strcpy(qq[0].ans,d.sym);
  strcpy(qq[1].ans,d.atn);
  strcpy(qq[2].ans,d.type);
  strcpy(qq[3].ans,d.blk);
  strcpy(qq[4].ans,d.pd);
  blk(block);
  for(i=0;i<4;i++)
  {
   opt1.getline(qq[0].opt[i],200,'\n');
   opt2.getline(qq[1].opt[i],200,'\n');
   opt3.getline(qq[2].opt[i],200,'\n');
   strcpy(qq[3].opt[i],block[i]);
   opt5.getline(qq[4].opt[i],200,'\n');
  }
  opt1.getline(temp,200,'\n');
  e.putq(qq);
  efile.write((char*)&e,sizeof(e));
  delay(20);
 }
 clrscr();
 nfile.close();
 qfile.close();
 amfile.close();
 anfile.close();
 cfile.close();
 grpfile.close();
 sfile.close();
 efile.close();
 opt1.close();
 opt2.close();
 opt3.close();
 opt5.close();
 coordfile.close();
 clrscr();
}

void main()
{
 clrscr();
 defwrite();
 cout<<"Done";
 getch();
}
