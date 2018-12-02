#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<ctype.h>
#include<INFNEW.cpp>

void e_screenf(float ,float );

coord c;

void coordwrite(float x,float y,int col)
{
 fstream file;
 static ch=0;
 if(ch==0)
  {
   file.open("e_coord.dat",ios::binary | ios::out);
   ch++;
  }
 else
 file.open("e_coord.dat",ios::binary | ios::app);
 c.x=x;
 c.y=y;
 c.col=col;
 file.write((char*)&c,sizeof(c));
 file.close();
}

float x[180]={0},y[180]={0};
int colf[180]={0};

void screen(int para);

void cnt(float x,float y)
{
 setfillstyle(1,7);
 setcolor(7);
 int ployc[]={x-5,y-5,x+5,y-5,x+5,y+5,x-5,y+5};
 fillpoly(4,ployc);
 int polyr[]={x+5,y-5,x+60,y-5,x+60,y-10,x+100,y,x+60,y+10,x+60,y+5,x+5,y+5};
 fillpoly(7,polyr);
 int polyd[]={x+5,y+5,x+5,y+60,x+10,y+60,x,y+100,x-10,y+60,x-5,y+60,x-5,y+5};
 fillpoly(7,polyd);
 int polyl[]={x-5,y-5,x-60,y-5,x-60,y-10,x-100,y,x-60,y+10,x-60,y+5,x-5,y+5};
 fillpoly(7,polyl);
 int polyu[]={x+5,y-5,x+5,y-60,x+10,y-60,x,y-100,x-10,y-60,x-5,y-60,x-5,y-5};
 fillpoly(7,polyu);
 char str[][3]={"A","S","D","W"};
 settextstyle(0,0,4);
 outtextxy(x+120,y-textheight(str[2])/2,str[2]);
 outtextxy(x-120-textwidth(str[0]),y-textheight(str[0])/2,str[0]);
 outtextxy(x-textwidth(str[1])/2+3,y+120,str[1]);
 outtextxy(x-textwidth(str[3])/2+3,y-120-textheight(str[3])/2-15,str[3]);
}


void nav(float &x,float &y,int &col,int para=0)
{
 screen(para);
 if(getpixel(x,y)==15)
 {
  setcolor(0);
  circle(x,y,3);
 }
 else
 {
  setcolor(15);
  rectangle(x-16.5,y-22,x+16.5,y+18);
 }
 col=getpixel(x,y);
}

void rect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
int a[]={x1,y1,x2,y2,x3,y3,x4,y4,x1,y1};
drawpoly(5,a);
}

void screen(int para)
{
 float xi=23,yi=100;
 int i;
 setfillstyle(1,15);
 setcolor(0);
 int bkg[]={0,0,640,0,640,480,0,480,0,0};
 fillpoly(5,bkg);
 setfillstyle(1,9);
 int b_s[]={23,100,89,100,89,340,23,340,23,100};
 fillpoly(5,b_s);                                          //blue - sblock
 int b_p[]={419,140,452,140,452,220,485,220,485,260,518,260,518,300,584,300,584,340,419,340,419,140};
 fillpoly(11,b_p);                                         //blue - pblock
 setfillstyle(1,5);
 int p_p[]={584,60,617,60,617,340,584,340,584,60};
 fillpoly(5,p_p);					   //purple - pblock
 setfillstyle(1,2);
 int g_s[]={23,60,56,60,56,100,23,100,23,60};
 fillpoly(5,g_s);					   //green - sblock
 int g_p[]={419,100,584,100,584,260,551,260,551,220,518,220,518,180,485,180,485,140,419,140,419,100};
 fillpoly(11,g_p);					   //green - pblock
 setfillstyle(1,4);
 int r_p[]={452,140,485,140,485,180,518,180,518,220,551,220,551,260,584,260,584,300,518,300,518,260,485,260,485,220,452,220,452,140};
 fillpoly(15,r_p);                                         //red - pblock
 setfillstyle(1,14);
 int y_d[]={89,180,419,180,419,340,122,340,122,260,89,260,89,180};
 fillpoly(6,y_d);					   //yellow - dblock
 setfillstyle(1,13);
 int lp_d[]={89,260,122,260,122,300,89,300,89,260};
 fillpoly(5,lp_d);					   //lightpurple - dblock
 int lp_f[]={89,380,551,380,551,420,89,420,89,380};
 fillpoly(5,lp_f);					   //lightpurple - fblock
 setfillstyle(1,12);
 int lr_d[]={89,300,122,300,122,340,89,340,89,300};
 fillpoly(5,lr_d);					   //lightred - dblock
 int lr_f[]={89,420,551,420,551,460,89,460,89,420};
 fillpoly(5,lr_f);					   //lightred - fblock

 rect(23,60,56,60,56,100,23,100);                   //Hydrogen
 rect(584,60,617,60,617,100,584,100);               //Helium
 for(i=1;i<7;i++)			      	    //s - block
 {
  rect(xi,yi,xi+33,yi,xi+33,yi+40,xi,yi+40);
  xi+=33;
  rect(xi,yi,xi+33,yi,xi+33,yi+40,xi,yi+40);
  xi-=33;
  yi+=40;
 }

 xi=419;                                            //p - block
 yi=100;
 int j;
 for(i=1;i<7;i++)
 {
  for(j=1;j<7;j++)
  {
   rect(xi,yi,xi+33,yi,xi+33,yi+40,xi,yi+40);
   xi+=33;
  }
  xi=419;
  yi+=40;
 }

 xi=89;                                              //d - block
 yi=180;
 for(i=1;i<5;i++)
 {
  for(j=1;j<11;j++)
  {
   rect(xi,yi,xi+33,yi,xi+33,yi+40,xi,yi+40);
   xi+=33;
  }
  xi=89;
  yi+=40;
 }

 xi=89;						     //f - block
 yi=380;
 for(i=1;i<3;i++)
 {
  for(j=1;j<15;j++)
  {
   rect(xi,yi,xi+33,yi,xi+33,yi+40,xi,yi+40);
   xi+=33;
  }
  xi=89;
  yi+=40;
 }

 settextstyle(2,0,4);

 char e[][4]={"H","","","","","","","","","","","","","","","","","He","Li","Be","","","","","","","","","","","B","C","N","O","F","Ne","Na","Mg","","","","","","","","","","","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La*","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac#","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Uut","Fl","Uup","Lv","Uus","Uuo"};
 char e_no[][4]={"1","","","","","","","","","","","","","","","","","2","3","4","","","","","","","","","","","5","6","7","8","9","10","11","12","","","","","","","","","","","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89","104","105","106","107","108","109","110","111","112","113","114","115","116","117","118"};
 xi=39.5;
 yi=80;
 for(i=0;i<126;i++)
 {
  if(i%18==0 && i!=0)
  {
   xi=39.5;
   yi+=40;
  }
  outtextxy(xi-textwidth(e_no[i])/2,yi-8-textheight(e_no[i])/2,e_no[i]);
  outtextxy(xi-textwidth(e[i])/2,yi+textheight(e[i])/2,e[i]);
  xi+=33;
 }

 char ef[][4]={"Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};
 char ef_no[][4]={"58","59","60","61","62","63","64","65","66","67","68","69","70","71","90","91","92","93","94","95","96","97","98","99","100","101","102","103"};
 xi=105.5;
 yi=400;
 for(i=0;i<28;i++)
 {
  if(i%14==0 && i!=0)
  {
   xi=105.5;
   yi+=40;
  }
  outtextxy(xi-textwidth(ef_no[i])/2,yi-8-textheight(ef_no[i])/2,ef_no[i]);
  outtextxy(xi-textwidth(ef[i])/2,yi+textheight(ef[i])/2,ef[i]);
  xi+=33;
 }

 xi=39.5;
 yi=42;
 if(para==1)
 {
  for(i=0;i<93;i++)
  {
   if(i%18==0)
   {
    xi=39.5;
    yi+=40;
   }
   x[i]=xi;
   y[i]=yi;
   colf[i]=getpixel(xi,yi+3);
   xi+=33;
  }

  xi=105.5;
  yi=402;
  for(i=93;i<107;i++)
  {
   x[i]=xi;
   y[i]=yi;
   colf[i]=getpixel(xi,yi+3);
   xi+=33;
  }                                         // Till Lu

  xi=138.5;
  yi=282;
  for(i=107;i<=125;i++)
  {
   if(i==122)
   {
    xi=39.5;
    yi+=40;
   }
   x[i]=xi;
   y[i]=yi;
   colf[i]=getpixel(xi,yi+3);
   xi+=33;
  }                                         // Till Ac


  xi=105.5;
  yi=442;
  for(i=135;i<=148;i++)
  {
   x[i]=xi;
   y[i]=yi;
   colf[i]=getpixel(xi,yi+3);
   xi+=33;
  }                                         // Till Lr

  xi=138.5;
  yi=322;
  for(i=149;i<155;i++)
  {
   x[i]=xi;
   y[i]=yi;
   colf[i]=getpixel(xi,yi+3);
   xi+=33;                                  // Till Mt
  }
 }



 rect(11,10,629,10,629,470,11,470);
 settextstyle(2,0,8);
 outtextxy(320-textwidth("Periodic Table")/2,40-textheight("Periodic Table")/2,"Periodic Table");

}

void mainf(int para)
{
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 float x=39.5,y=82;
 int col=15;
 char ch=13;
/*1*/ char e1[][4]={"H","","","","","","","","","","","","","","","","","He","Li","Be","","","","","","","","","","","B","C","N","O","F","Ne","Na","Mg","","","","","","","","","","","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La*"};
/*3*/ char e2[][4]={"Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac#"};
/*5*/ char e5[][4]={"Rf","Db","Sg","Bh","Hs","Mt"};
/*2*/ char e3[][4]={"Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu"};
/*4*/ char e4[][4]={"Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};
 char msg[]={"Data for the Element does not Exist."};
 int flag=0;
 setfillstyle(1,15);
 setcolor(0);
 int bkg[]={0,0,640,0,640,480,0,480,0,0};
 fillpoly(5,bkg);
 rectangle(10,10,630,470);
 if(para==0)
 {
  cnt(320,240);
  getch();
 }
 if(para==0)
 do
 {
  flag=0;
  nav(x,y,col,para);
  if(para!=1)
  ch=getch();
  if(ch==27)
  flag=-1;
  if(ch=='a' && x>39.5)
  x-=33;
  if(ch=='w' && y>82)
  y-=40;
  if(ch=='s' && y<405)
  y+=40;
  if(ch=='d' && x<600.5)
  x+=33;
  if(ch==13 && y==322 && x>=336.5)
  {
   setcolor(0);
   outtextxy(320-textwidth(msg)/2,358-textheight(msg)/2,msg);
   getch();
   ch=0;
   flag=-1;
  }
  if(ch==13 && getpixel(x,y)==15)
  ch=0;
  else if(ch==13)
  e_screenf(x,y);
  cleardevice();
 }while(ch!='0' && ch!=27);

 if(para==1)
 {
  nav(x,y,col,para);
  closegraph();
  int atn=1;
  char opt;
  for(int i=0;i<155;i++)
  {
   if(colf[i]!=15)
   {
     if(i<93)
     {
      cout<<atn<<". "<<i<<"  "<<e1[i]<<"  "<<::x[i]<<"\t"<<::y[i]<<"\t"<<colf[i]<<endl;
      coordwrite(::x[i],::y[i],colf[i]);
     }
     else if(i<107)
     {
      cout<<atn<<". "<<i<<"  "<<e3[i-93]<<"  "<<::x[i]<<"\t"<<::y[i]<<"\t"<<colf[i]<<endl;
      coordwrite(::x[i],::y[i],colf[i]);
     }
     else if(i>=125 &&  i<=134)
     continue;
     else if(i<135)
     {
      cout<<atn<<". "<<i<<"  "<<e2[i-107]<<"  "<<::x[i]<<"\t"<<::y[i]<<"\t"<<colf[i]<<endl;
      coordwrite(::x[i],::y[i],colf[i]);
     }
     else if(i<149)
     {
      cout<<atn<<". "<<i<<"  "<<e4[i-135]<<"  "<<::x[i]<<"\t"<<::y[i]<<"\t"<<colf[i]<<endl;
      coordwrite(::x[i],::y[i],colf[i]);
     }
     else
     {
      cout<<atn<<". "<<i<<"  "<<e5[i-149]<<"  "<<::x[i]<<"\t"<<::y[i]<<"\t"<<colf[i]<<endl;
      coordwrite(::x[i],::y[i],colf[i]);
     }
     atn++;
     delay(30);
   }
  }
 }
}

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

 data d1;
 quest q1[5];
 coord cd1;
 e.getdata(d1,q1,cd1);

 int bk[]={0,0,640,0,640,480,0,480};
 setfillstyle(1,15);
 fillpoly(4,bk);
 setcolor(0);
 rectangle(10,10,630,470);

 setfillstyle(1,cd1.col);
 setcolor(cd1.col);
 int tile[]={400,40,600,40,600,240,400,240};
 fillpoly(4,tile);
 setcolor(0);
 rectangle(405,45,595,235);

 settextstyle(0,0,8);
 outtextxy(500-textwidth(d1.sym)/2,140-textheight(d1.sym)/2,d1.sym);
 settextstyle(0,0,2);
 outtextxy(440,70,d1.atm);
 outtextxy(440,210-textheight(d1.atn),d1.atn);
 float y=40;
 outtextxy(35,y,"Name: ");
 outtextxy(35+textwidth("Name: "),y,d1.name);
 y+=45;
 outtextxy(35,y,"Symbol: ");
 outtextxy(35+textwidth("Symbol: "),y,d1.sym);
 y+=45;
 outtextxy(35,y,"Atomic Mass: ");
 outtextxy(35+textwidth("Atomic Mass: "),y,d1.atm);
 y+=45;
 outtextxy(35,y,"Atomic Number: ");
 outtextxy(35+textwidth("Atomic Number: "),y,d1.atn);
 y+=45;
 outtextxy(35,y,"Group: ");
 outtextxy(35+textwidth("Group: "),y,d1.grp);
 y+=45;
 outtextxy(35,y,"Period: ");
 outtextxy(35+textwidth("Period: "),y,d1.pd);
 y+=45;
 outtextxy(35,y,"Block: ");
 outtextxy(35+textwidth("Block: "),y,d1.blk);
 y+=45;
 outtextxy(35,y,"Type: ");
 outtextxy(35+textwidth("Type: "),y,d1.type);
 y+=45;
 outtextxy(35,y,"Configuration: ");
 config(20+textwidth("Configuration: "),y,d1.config);
 y+=45;
 getch();
}



void e_screenf(float x,float y)
{
 element e;
 fstream file;
 file.open("e_data.dat",ios::binary | ios::in);
 while(file.read((char*)&e,sizeof(e)))
 {
  if(e.matchxy(x,y)==0)
  break;
 }
 display(e);
}

void main()
{
 clrscr();
 int ch;
 cin>>ch;
 mainf(ch);
}



