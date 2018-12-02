#include<fstream.h>
#include<iomanip.h>
#include<conio.h>
#include<infnew.cpp>

void main()
{
 clrscr();
 data d;
 element e;
 coord cd;
 quest q[5];
 fstream file;
 file.open("E_data.dat",ios::binary | ios::in);
 while(file.read((char*)&e,sizeof(e)))
 {
  e.getdata(d,q,cd);
  cout<<d.name<<endl<<d.sym<<endl<<d.atn<<endl<<d.atm<<endl<<d.config<<endl;
  cout<<d.grp<<endl<<d.pd<<endl<<d.blk<<endl<<d.type<<endl<<cd.x<<endl<<cd.y<<endl<<cd.col<<endl;
  for(int i=0;i<5;i++)
  cout<<q[i].qstn<<endl;
  for(i=0;i<4;i++)
  cout<<q[0].opt[i]<<"\t"<<q[1].opt[i]<<"\t"<<setw(20)<<q[2].opt[i]<<"\t"<<q[3].opt[i]<<"\t"<<q[4].opt[i]<<endl;
  cout<<q[0].ans<<"\t"<<q[1].ans<<"\t"<<setw(20)<<q[2].ans<<"\t"<<q[3].ans<<"\t"<<q[4].ans<<endl;
  getch();
  clrscr();
 }
 file.close();
 getch();
}