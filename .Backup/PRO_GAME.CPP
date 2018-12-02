#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<infnew.cpp>
#include<dos.h>
#include<stdlib.h>
#include<ctype.h>
#include<iomanip.h>

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

void questrandom(quest qq[5])
{
 int i,num[5]={0};
 randomarr(num,5);
 quest q1[5];
 for(i=0;i<5;i++)
 q1[i]=qq[i];
 for(i=0;i<5;i++)
 qq[num[i]]=q1[i];

 for(i=0;i<5;i++)
 q1[i]=qq[i];
 num[4]=-1;

 for(i=0;i<5;i++)
 {
  randomarr(num,4);
  for(int j=0;j<4;j++)
  strcpy(qq[i].opt[j],q1[i].opt[num[j]]);
 }
}

char* opttoogle(quest qq[],int i)
{
 int t;
 char ch='0';
 int bk[]={0,0,640,0,640,480,0,480};
 settextstyle(2,0,7);
 int y=109;
 int col[4]={0};
 char tstr[20];
 char str[100]={'Q',i+'1','.',' '};
 strcat(str,qq[i].qstn);
 t=20;
 ch='0';
 y=109;

 do
 {
  ch='0';
  cleardevice();
  setfillstyle(1,15);
  fillpoly(4,bk);
  setcolor(0);
  rectangle(10,10,630,470);
  settextstyle(2,0,7);
  outtextxy(30,30,str);

  for(int n=0;n<4;n++)
  {
   char optno[]={'A'+n,' ',' ',' ','\0'};
   setcolor(col[n]);
   line(10+textwidth(optno),114+n*84-textheight(qq[i].opt[0])/2,10+textwidth(optno),124+n*84+textheight(qq[i].opt[0]));
   rectangle(30,114+n*84-textheight(qq[i].opt[0])/2,500,124+n*84+textheight(qq[i].opt[0]));
   setcolor(0);
   outtextxy(40,109+n*84,optno);
   outtextxy(70,109+n*84,qq[i].opt[n]);
  }

  for(int k=0;k<4;k++)
  col[k]=0;

  if(kbhit())
  {
   ch=getch();
   if(ch=='w' && y>109)
   y-=84;
   else if(ch=='s' && y<361)
   y+=84;
   else if(ch==13)
   break;
  }

  switch(y)
  {
   case 109:col[0]=4;
	    break;
   case 193:col[1]=4;
	    break;
   case 277:col[2]=4;
	    break;
   case 361:col[3]=4;
	    break;
  }

  int tblk_red[]={15,445,625,445,625,465,15,465};
  int tblk_green[]={15,445,15+((20-t)*61/2),445,15+((20-t)*61/2),465,15,465};
  setfillstyle(1,4);
  fillpoly(4,tblk_red);
  setfillstyle(1,2);
  fillpoly(4,tblk_green);
  itoa(t,tstr,10);
  settextstyle(2,0,5);
  outtextxy(320-textwidth("Time Left: ")/2-textwidth(tstr),453-textheight("Time Left: ")/2,"Time Left: ");
  outtextxy(320+textwidth("Time Left: ")/2,453-textheight("Time Left: ")/2,tstr);
  t--;
  sleep(1);
 }while(t!=0 && ch!=13);

 if(ch=='0')
 return " ";

 int ans;
 ans=(y-109)/84;

 return qq[i].opt[ans];
}

void scorepage(int score[5])
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 static int count=1;
 int bk[]={0,0,640,0,640,480,0,480};
 setfillstyle(1,15);
 fillpoly(4,bk);
 setcolor(0);
 rectangle(10,10,630,470);
 char level[]={"Level "};
 char temp[20];
 strcat(level,itoa(count,temp,10));
 settextstyle(2,0,10);
 outtextxy(320-textwidth(level)/2,100-textheight(level)/2,level);

 int x,y;
 settextstyle(2,0,6);

 outtextxy(95-textwidth("Question")/2,192.5-textheight("Question")/2,"Question");
 outtextxy(95-textwidth("No:")/2,207.5-textheight("No:")/2,"No:");
 outtextxy(95-textwidth("Score:")/2,250-textheight("Score:")/2,"Score:");

 for(int i=0;i<6;i++)
 {
  x=50+i*90;
  y=200;
  rectangle(x,y-25,x+90,y+25);
  itoa(i+1,temp,10);
  if(i<5)
  {
   outtextxy(x+140-textwidth(temp)/2,y-textheight(temp)/2,temp);
   itoa(score[i],temp,10);
   outtextxy(x+140-textwidth(temp)/2,250-textheight(temp)/2,temp);
  }
  y=250;
  rectangle(x,y-25,x+90,y+25);
 }
 count++;
 int sum=0;
 for(i=0;i<5;i++)
 sum+=score[i];
 char result[50];
 strcpy(result,"Level ");
 if(sum>40)
 {
  strcat(result,"Passed");
  setcolor(2);
 }
 else
 {
  strcat(result,"Failed");
  setcolor(4);
 }
 settextstyle(2,0,10);
 outtextxy(320-textwidth(result)/2,300,result);
 getch();
}

int play(int ur=109,int lr=1)
{
 clrscr();
 randomize();
 int rng;
 rng=ur-lr+1;
 int rndnum;
 rndnum=random(rng);
 rndnum+=lr;
 element e;
 fstream file;
 data d;
 quest q[5];
 coord c;
 file.open("e_data.dat",ios::binary | ios::in);
 for(int i=1;i<=rndnum;i++)
 file.read((char*)&e,sizeof(e));
 e.getdata(d,q,c);
 char ch;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 int t=10;
 char tstr[20];
 int y=50;
 int bk[]={0,0,640,0,640,480,0,480};

 do
 {
  y=50;
  settextstyle(2,0,6);
  setfillstyle(1,15);
  fillpoly(4,bk);
  setcolor(0);
  rectangle(10,10,630,470);

  int blk[]={160-(textwidth("Configuration: ")+textwidth(d.config))/4,40,480+textwidth("Configuration: ")/4+textwidth(d.config)/4,40,480+textwidth("Configuration: ")/4+textwidth(d.config)/4,435,160-(textwidth("Configuration: ")+textwidth(d.config))/4,435};
  setfillstyle(1,c.col);
  fillpoly(4,blk);
  rectangle(165-(textwidth("Configuration: ")+textwidth(d.config))/4,45,475+textwidth("Configuration: ")/4+textwidth(d.config)/4,430);

  outtextxy(140,y,"Name: ");
  outtextxy(140+textwidth("Name: "),y,d.name);
  y+=45;
  outtextxy(140,y,"Symbol: ");
  outtextxy(140+textwidth("Symbol: "),y,d.sym);
  y+=45;
  outtextxy(140,y,"Atomic Mass: ");
  outtextxy(140+textwidth("Atomic Mass: "),y,d.atm);
  y+=45;
  outtextxy(140,y,"Atomic Number: ");
  outtextxy(140+textwidth("Atomic Number: "),y,d.atn);
  y+=45;
  outtextxy(140,y,"Group: ");
  outtextxy(140+textwidth("Group: "),y,d.grp);
  y+=45;
  outtextxy(140,y,"Period: ");
  outtextxy(140+textwidth("Period: "),y,d.pd);
  y+=45;
  outtextxy(140,y,"Block: ");
  outtextxy(140+textwidth("Block: "),y,d.blk);
  y+=45;
  outtextxy(140,y,"Type: ");
  outtextxy(140+textwidth("Type: "),y,d.type);
  y+=40;
  outtextxy(140,y,"Configuration: ");
  config(140+textwidth("Configuration: "),y,d.config);

  int tblk_red[]={15,445,625,445,625,465,15,465};
  int tblk_green[]={15,445,15+(10-t)*61,445,15+(10-t)*61,465,15,465};
  setfillstyle(1,4);
  fillpoly(4,tblk_red);
  setfillstyle(1,2);
  fillpoly(4,tblk_green);
  itoa(t,tstr,10);
  settextstyle(2,0,5);
  outtextxy(320-textwidth("Time Left: ")/2-textwidth(tstr),453-textheight("Time Left: ")/2,"Time Left: ");
  outtextxy(320+textwidth("Time Left: ")/2,453-textheight("Time Left: ")/2,tstr);
  sleep(1);
  if(kbhit())
  ch=getch();
  cleardevice();
  t--;
 }while(t!=0 && ch!=13);

 char ans[5][200];

 questrandom(q);
 for(i=0;i<5;i++)
 {
  char *str=opttoogle(q,i);
  strcpy(ans[i],str);
 }

 int score[5],sum=0;
 for(i=0;i<5;i++)
 {
  if(strcmpi(ans[i],q[i].ans)==0)
  score[i]=20;
  else if(strcmpi(ans[i]," ")==0)
  score[i]=0;
  else
  score[i]=-20;
 }

 for(i=0;i<5;i++)
 sum+=score[i];

 scorepage(score);

 file.close();
 closegraph();
 return sum;
}

void main()
{
 clrscr();
 int a[5]={0};
 int i;
/* for(i=0;i<5;i++)
 {
  randomarr(a,5);
  for(int j=0;j<5;j++)
  cout<<a[j]<<endl;
  cout<<endl;
 } */
 i=play(30);
 closegraph();
 cout<<i;
// if(i>200)
// i=play(10);
 getch();
}