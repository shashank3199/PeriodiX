#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<infnew.cpp>
#include<string.h>
#include<ctype.h>

void sup(float x,float y,char str[])
{
 textsettingstype temp;
 gettextsettings(&temp);
 settextstyle(temp.font,temp.direction,temp.charsize-1);
 outtextxy(x,y-2,str);
 settextstyle(temp.font,temp.direction,temp.charsize);
}

void config(float x,float y,char str[])
{
 int n=strlen(str);
 int i;
 for(i=0;str[i]!='\0';i++)
 {
  if(!(isalpha(str[i])||isdigit(str[i])||isspace(str[i])||ispunct(str[i])))
  str[i]=' ';
 }
 char obj[3];
 for(i=0;i<n;i++)
 {
   obj[0]=str[i];
   obj[1]='\0';
  if((str[i-1]=='s'||str[i-1]=='p'||str[i-1]=='d'||str[i-1]=='f'||str[i-2]=='s'||str[i-2]=='p'||str[i-2]=='d'||str[i-2]=='f')&&(str[i+1]==' '||str[i+2]==' '||str[i+1]=='\0'||str[i+2]=='\0'))
    {
     sup(x,y,obj);
    }
  else
    {
     outtextxy(x,y,obj);
    }
  x+=textwidth(obj);
 }
}

void display(element e)
{

 data d;
 quest q[5];
 coord cd;
 e.getdata(d,q,cd);

 int bk[]={0,0,640,0,640,480,0,480};
 setfillstyle(1,15);
 fillpoly(4,bk);
 setcolor(0);
 rectangle(10,10,630,470);

 setfillstyle(1,cd.col);
 setcolor(cd.col);
 int tile[]={400,40,600,40,600,240,400,240};
 fillpoly(4,tile);
 setcolor(0);
 rectangle(405,45,595,235);

 settextstyle(0,0,8);
 outtextxy(500-textwidth(d.sym)/2,140-textheight(d.sym)/2,d.sym);
 settextstyle(0,0,2);
 outtextxy(440,70,d.atm);
 outtextxy(440,210-textheight(d.atn),d.atn);
 float y=40;
 outtextxy(35,y,"Name: ");
 outtextxy(35+textwidth("Name: "),y,d.name);
 y+=45;
 outtextxy(35,y,"Symbol: ");
 outtextxy(35+textwidth("Symbol: "),y,d.sym);
 y+=45;
 outtextxy(35,y,"Atomic Mass: ");
 outtextxy(35+textwidth("Atomic Mass: "),y,d.atm);
 y+=45;
 outtextxy(35,y,"Atomic Number: ");
 outtextxy(35+textwidth("Atomic Number: "),y,d.atn);
 y+=45;
 outtextxy(35,y,"Group: ");
 outtextxy(35+textwidth("Group: "),y,d.grp);
 y+=45;
 outtextxy(35,y,"Period: ");
 outtextxy(35+textwidth("Period: "),y,d.pd);
 y+=45;
 outtextxy(35,y,"Block: ");
 outtextxy(35+textwidth("Block: "),y,d.blk);
 y+=45;
 outtextxy(35,y,"Type: ");
 outtextxy(35+textwidth("Type: "),y,d.type);
 y+=45;
 outtextxy(35,y,"Configuration: ");
 config(20+textwidth("Configuration: "),y,d.config);
 y+=45;
 getch();
}



void e_screenf(float x,float y)
{
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 element e;
 fstream file;
 file.open("e_data.dat",ios::binary | ios::in);
 while(file.read((char*)&e,sizeof(e)))
 {
  if(e.matchxy(x,y)==0)
  break;
 }
 display(e);
 closegraph();
}


