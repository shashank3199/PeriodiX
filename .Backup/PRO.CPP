#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<ctype.h>
#include<iomanip.h>

class element;
class login;

struct quest
{
 char qstn[200];
 char opt[4][200];
 char ans[200];
};

struct coord
{
 float x,y;
 int col;
};

struct data
{
 char name[20];
 char grp[3],pd[3];
 char atm[15],atn[10];
 char sym[5];
 char config[30];
 char blk[20];
 char type[20];
};

class element
{
 data d;
 quest q[5];
 coord c;
 public:
 void putblktypepd();                       // Put Block, Type and Period
 void putd(data);                           // Accept Data
 void putcoord(coord);                      // Accept Coordinates
 void putq(quest []);                       // Accept Questions
 void getdata(data&,quest[],coord&);        // Return Data, Coordinates and Questions
 int matchxy(float,float); 		    // Match X and Y Coordinate
 element();                                 // Constructor
};

void element :: putd(data g)
{
 strcpy(d.name,g.name);
 strcpy(d.grp,g.grp);
 strcpy(d.atm,g.atm);
 strcpy(d.atn,g.atn);
 strcpy(d.sym,g.sym);
 strcpy(d.config,g.config);
 strcpy(d.blk,g.blk);
 strcpy(d.type,g.type);
 strcpy(d.pd,g.pd);

}

void element :: putcoord(coord cd)
{
 c.col=cd.col;
 c.x=cd.x;
 c.y=cd.y;
}

void element :: putq(quest q1[])
{
 for(int i=0;i<5;i++)
 {
  strcpy(q[i].ans,q1[i].ans);
  strcpy(q[i].qstn,q1[i].qstn);
  for(int j=0;j<4;j++)
  strcpy(q[i].opt[j],q1[i].opt[j]);
 }
}

void element :: putblktypepd()
{
 switch(c.col)
 {
  case 2:strcpy(d.type,"Non - Metal");
	 break;
  case 4:strcpy(d.type,"Metalloid");
	 break;
  case 5:strcpy(d.type,"Noble Gas");
	 break;
  case 9:strcpy(d.type,"Metal");
	 break;
  case 14:strcpy(d.type,"Transition Metal");
	  break;
  case 13:strcpy(d.type,"Lanthanoids");
	  break;
  case 12:strcpy(d.type,"Actanoids");
	  break;
 }

 if(c.y<=322)
 {
  if(c.x>=39.5 && c.x<=72.5)
  strcpy(d.blk,"S - Block");
  else if(c.x>=105.5 && c.x<=402.5)
  strcpy(d.blk,"D - Block");
  else if(c.x>=435.5 && c.x<=600.5)
  strcpy(d.blk,"P - Block");
 }
 else
 strcpy(d.blk,"F - Block");
 int cy;
 cy=c.y;
 switch(cy)
 {
  case 82:strcpy(d.pd,"1");
	  break;
  case 122:strcpy(d.pd,"2");
	   break;
  case 162:strcpy(d.pd,"3");
	   break;
  case 202:strcpy(d.pd,"4");
	   break;
  case 242:strcpy(d.pd,"5");
	   break;
  case 282:strcpy(d.pd,"6");
	   break;
  case 322:strcpy(d.pd,"7");
	   break;
  case 402:strcpy(d.pd,"6");
	   break;
  case 442:strcpy(d.pd,"7");
	   break;
 }
}

void element :: getdata(data &g,quest q1[],coord &cd)
{
 strcpy(g.name,d.name);
 strcpy(g.grp,d.grp);
 strcpy(g.atm,d.atm);
 strcpy(g.atn,d.atn);
 strcpy(g.sym,d.sym);
 strcpy(g.config,d.config);
 strcpy(g.blk,d.blk);
 strcpy(g.type,d.type);
 strcpy(g.pd,d.pd);
 for(int i=0;i<5;i++)
 {
  strcpy(q1[i].ans,q[i].ans);
  strcpy(q1[i].qstn,q[i].qstn);
  for(int j=0;j<4;j++)
  strcpy(q1[i].opt[j],q[i].opt[j]);
 }
 cd.x=c.x;
 cd.y=c.y;
 cd.col=c.col;
}

element :: element()
{
 static int qno=0;
 qno++;
 if(qno>=6)
 qno=1;
 strcpy(d.name,"  ");
 strcpy(d.sym,"  ");
 strcpy(d.config,"  ");
 strcpy(d.grp,"  ");
 strcpy(d.atn,"  ");
 strcpy(d.atm,"  ");
 strcpy(d.type,"  ");
 strcpy(d.blk," 	 ");
 strcpy(d.pd,"  ");
 for(int i=0;i<5;i++)
 {
  strcpy(q[i].ans," ");
  strcpy(q[i].qstn,"  ");
  for(int j=0;j<4;j++)
  strcpy(q[i].opt[j],"  ");
 }
 c.x=c.y=0;
}

int element :: matchxy(float a,float b)
{
 if(c.x==a && c.y==b)
 return 0;
 else
 return 1;
}

class login
{
 char name[20];
 char pass[20];
 char access[20];
 long hscore,cscore,tpoints;
 public:
 void accept(char [],char []);                  // Accept Login Data
 void getinfo(char [],char [],long []);         // Return Login Data
 void s_upd(long);                              // Score Update
 void madmin();                                 // Make Administrator
 int mname(char []);                            // Match Name
 int mpass(char []);                            // Match Password
 int mac();                                     // Checks Administrative Access
 login();					// Constructor
};

void login :: accept(char n[],char p[])
{
 strcpy(name,n);
 strcpy(pass,p);
}

void login :: madmin()
{
 strcpy(access,"Admin");
}

void login :: getinfo(char n[],char p[],long s[])
{
 strcpy(n,name);
 strcpy(p,pass);
 s[0]=hscore;
 s[1]=cscore;
 s[2]=tpoints;
}

void login :: s_upd(long cs)
{
 cscore=cs;
 tpoints+=cs;
 if(cs>hscore)
 hscore=cs;
 else if(cs==-1)
 {
  hscore=0;
  tpoints=0;
  cscore=0;
 }
}

login :: login()
{
 strcpy(name,"  ");
 strcpy(pass,"  ");
 strcpy(access,"  ");
 hscore=cscore=tpoints=0;
}

int login :: mac()
{
 if(strcmpi(name,"Shashank")==0)
 strcpy(access,"Admin");
 if(strcmpi(access,"Admin")==0)
 return 0;
 else
 return 1;
}

int login :: mpass(char p[])
{
 if(strcmpi(pass,p)==0)
 return 0;
 else
 return 1;
}

int login :: mname(char n[])
{
 if(strcmpi(name,n)==0)
 return 0;
 else
 return 1;
}

void sup(float x,float y,char str[]);                // Superscript
void config(float x,float y,char str[]);             // Configuration
void ginput(float x,float y, char str[],char type);  // Graphics Input
void playm();                                        // Play Menu
void changepass();                                   // Change User Pass
void statpage();                                     // User Statistic Page
void clrstats();                                     // Clear User Statistics
void delcu();                                        // Delete Current User
void setpage();                                      // User Settings Page
void mpage();                                        // Main Menu Page
void viewelement();                                  // View Element Data
void gdspage();                                      // Game Data Settings
void lou();                                          // List of Users
void mod();                                          // Modify User Rights
void deluser();                                      // Delete Users
void udspage();                                      // User Data Settings
void gspage();                                       // Game Settings Page
void apage();                                        // Administrator Page
void lpage();                                        // Login Page
void spage();                                        // Sign Up Page
void wpage();                                        // Welcome Page
void e_screenf(float x,float y);                     // Element Screen
void coordwrite(float x,float y,int col);            // Coord Write in File
void screen(int para);                               // Periodic Screen
void cnt(float x,float y);                           // Control Page
void nav(float &x,float &y,int &col,int para);       // Navigate in Periodic Table
void rect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4); // Making Rectangle
void mainf(int para);                                // Main Screen Function
void display(element e);			     // Display Element
void randomarr(int rec[],int n);                     // Randomise Array
void blk(char temp[][30]);                           // Randomise Block
void defwrite();                                     // Default Write Function
void questrandom(quest qq[5]);			     // Randomise Questions
void scorepage(int score[5],int lvl);		     // Score Page
void userupdate(long);                               // Update User Score
int epage();                                         // Exit Page
int play(int ur,int lvl);                            // Game Play
int toggle(char head[],char menu[][50],int r);       // Toggle through Menu Options
char* opttoogle(quest qq[],int i); 	    	     // Toggle through Game Options
void slantellipse(float m,int s1,int s2);	     // Drawing Slanted Ellipse

coord c;
float x[180]={0},y[180]={0};
int colf[180]={0};
char lid[50],pass[50];
login user;

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

void ginput(float x,float y, char str[],char type='n')
{
 char bnk[100]={"                    "};
 int i=0;
 int c=0;
 float bx=x+10;
 while(str[i]!=13 && i<20)
 {
  do
  {
   setcolor(15+128);
   line(bx,y+20,bx+10,y+20);
   delay(50);
   setcolor(0);
   line(bx,y+20,bx+10,y+20);
   delay(50);
  }while(!kbhit());
  bx=x;
  setcolor(15);
  str[i]=getch();
  c++;
  if(str[i]==13 || str[i]==27)
  break;
  if(str[i]==8 && i>0)
  {
   i-=2;
   c-=2;
   if(bx>=x)
   bx=x;
  }
  i++;
  str[i]='\0';
  setfillstyle(1,getbkcolor());
  int block[]={x,y-textheight(str)/2,x+textwidth(bnk),y-textheight(str)/2,x+textwidth(bnk),y+textheight(str),x,y+textheight(str)};
  setcolor(getbkcolor());
  fillpoly(4,block);
  setcolor(15);
  char obj[100];
  if(type=='n')
  {
   outtextxy(x,y,str);
  }
  else if(type=='p')
  {
   for(i=0;i<c;i++)
   obj[i]='*';
   obj[i]='\0';
   outtextxy(x,y,obj);
  }
  bx+=textwidth(str);
 }
 str[i]='\0';
}

int toggle(char head[],char menu[][50],int r)
{
 r++;
 settextstyle(0,0,4);
 setcolor(15);
 outtextxy(320-textwidth(head)/2,30+textheight(head)/2,head);
 settextstyle(0,0,2);
 float y=80;
 float h;
 h=400/r;
 float hs[10]={0};
 int i;
 char ch='w';
 float theight=80+(r-1)*h;
 int col[10];
 for(i=0;i<10;i++)
 col[i]=15;
 for(i=0;i<r;i++)
  {
   y+=h;
   hs[i]=y;
  }
 y=80+h;
 while(ch!=13)
 {
  if(ch=='w' && y>80+h)
  y-=h;
  else if(ch=='s' && y<theight)
  y+=h;
  if(ch==13)
  break;
  for(i=0;i<r;i++)
  {
   if(hs[i]==y)
   {
    col[i]=4;
    break;
   }
  }
  for(i=0;i<r;i++)
  {
   if(col[i]==4)
   {
    setcolor(15);
    if(320-textwidth(menu[i])/2<180 || 320+textwidth(menu[i])/2>460)
    rectangle(320-textwidth(menu[i])/2-8,hs[i]-textheight(menu[i])/2-5,320+textwidth(menu[i])/2+5,hs[i]+textheight(menu[i])+10);
    else
    rectangle(180,hs[i]-textheight(menu[i])/2-5,460,hs[i]+textheight(menu[i])+10);
   }
   else
   {
    setcolor(0);
    if(320-textwidth(menu[i])/2<180 || 320+textwidth(menu[i])/2>460)
    rectangle(320-textwidth(menu[i])/2-8,hs[i]-textheight(menu[i])/2-5,320+textwidth(menu[i])/2+5,hs[i]+textheight(menu[i])+10);
    else
    rectangle(180,hs[i]-textheight(menu[i])/2-5,460,hs[i]+textheight(menu[i])+10);
   }
   setcolor(col[i]);
   outtextxy(320-textwidth(menu[i])/2,hs[i],menu[i]);
  }
 for(i=0;i<10;i++)
 col[i]=15;
 ch=getch();
 }
  for(i=0;i<r;i++)
  {
   if(hs[i]==y)
   {
    return i+1;
   }
  }
 return -1;
}

void playm()                //game page
{
 cleardevice();
 setcolor(15);
 rectangle(10,10,630,470);
 settextstyle(1,0,5);
 line(320-textwidth("How To Play")/2,60-textheight("How To Play")/2,320+textwidth("How To Play")/2,60-textheight("How To Play")/2);
 outtextxy(320-textwidth("How To Play")/2,55-textheight("How To Play")/2,"How To Play");
 line(320-textwidth("How To Play")/2,40+textheight("How To Play"),320+textwidth("How To Play")/2,40+textheight("How To Play"));
 circle(40,150,2);
 settextstyle(1,0,1);
 outtextxy(60,150-textheight("Game Modes - Medium: Elements 1 to 40.")/2,"Game Modes - Medium :   Elements 1 to 40.");
 outtextxy(62,140-(textheight("           - Easy:   Elements 1 to 20.")*3)/2,"             - Easy    :   Elements 1 to 20.");
 outtextxy(62,140+(textheight("           - Hard:   Elements 1 to 109.")*3)/2,"             - Hard    :   Elements 1 to 109.");
 circle(40,220,2);
 outtextxy(60,210,"The Objective of the Game is to Memorize the Given");
 outtextxy(60,215+textheight("The Objective"),"Element Details whithin the Given Time Limit and to");
 outtextxy(60,220+2*textheight("Element Details"),"Answer the Questions that follow.");
 circle(40,310,2);
 outtextxy(60,295,"Press Enter to Select the Option and Esc to Exit.");
 circle(40,340,2);
 outtextxy(60,330,"Correct Answer Gets +20 Points, Wrong Answer Gets");
 outtextxy(60,335+textheight("Correct"),"-20 Points and Not Attempted Gets 0 Points.");
 outtextxy(620-textwidth("Press Enter to Continue....."),450-textheight("Press Enter to Continue....."),"Press Enter to Continue.....");
 getch();
 char popt[][50]={"Easy","Medium","Hard","Return"};
 int ch;
 cleardevice();
 ch=toggle("Play",popt,4);
 long sc=0;
 int range;
 switch(ch)
 {
  case 1:range=20;
	 break;
  case 2:range=40;
	 break;
  case 3:range=109;
	 break;
  case 4:mpage();
	 break;
 }
 for(int i=0;i<5 && sc>=0;i++)
 {
  sc=play(range,i+1);
  userupdate(sc);
 }
 cleardevice();
 if(sc<0)
 {
  setcolor(15);
  rectangle(10,10,630,470);
  setcolor(4);
  settextstyle(0,0,5);
  outtextxy(320-textwidth("Game Over")/2,240-textheight("Game Over"),"Game Over");
 }
 else
 {
  setcolor(15);
  rectangle(10,10,630,470);
  setcolor(2);
  settextstyle(0,0,5);
  outtextxy(320-textwidth("Game Over")/2,240-textheight("Game Over"),"Game Over");
  outtextxy(320-textwidth("You Won")/2,260-textheight("You Won")+textheight("Game Over"),"You Won");
 }
 getch();
 cleardevice();
 mpage();
}

void userupdate(long sc)
{
 cleardevice();
 fstream mod;
 login l;
 long upd_sc[3];
 mod.open("login.dat",ios::binary | ios::in | ios::out);
 int count=0;
 mod.seekg(0,ios::beg);
 setcolor(15);
 char uname[20];
 char passlist[20];
 user.getinfo(uname,passlist,upd_sc);
 while(mod.read((char*)&l,sizeof(l)))
 {
  l.getinfo(lid,pass,upd_sc);
  if((strcmpi(lid,uname)==0)&&(strcmpi(pass,passlist)==0))
  {
   l.s_upd(sc);
   user.s_upd(sc);
   mod.seekg(count*sizeof(l),ios::beg);
   mod.write((char*)&l,sizeof(l));
   break;
  }
  count++;
 }
 mod.close();
}

void changepass()	    // password change page
{
 cleardevice();
 login l;
 char newpass[20];
 char cpass[20];
 settextstyle(0,0,2);
 setcolor(4);
 outtextxy(50,240,"Current Password: ");
 rectangle(30,200,610,280);
 setcolor(15);
 fstream file;
 file.open("login.dat",ios::binary | ios::in | ios::out);
 int flag=-1,count=0;;
 long sc[3];
 user.getinfo(lid,pass,sc);
 ginput(55+textwidth("Current Password: "),240,pass,'p');
 while(file.read((char*)&l,sizeof(l)))
 {
  if(l.mname(lid)==0)
  {
   if(l.mpass(pass)==0)
   {
    flag=0;
    break;
   }
  }
  count++;
 }
 char mstr1[]={"Credentials Not Found."};
 char mstr2[]={"Please Try Again Later."};
 char mstr3[]={"Contact Administrator"};
 if(flag==-1)
 {
  setcolor(15);
  outtextxy(320-textwidth(mstr1)/2,340,mstr1);
  outtextxy(320-textwidth(mstr2)/2,350+textheight(mstr1),mstr2);
  outtextxy(320-textwidth("Or")/2,360+textheight(mstr1)+textheight(mstr2),"Or");
  outtextxy(320-textwidth(mstr3)/2,370+textheight(mstr1)+textheight(mstr2)+textheight("Or"),mstr3);
  getch();
  setpage();
 }
 cleardevice();
 int x;
 x=300-textwidth("Confirm Password: ");
 setcolor(4);
 rectangle(x,150-textheight("New Password: ")/2,320+textwidth("Confirm Password: "),160+textheight("New Password: "));
 outtextxy(320-textwidth("New Password: "),160-textheight("New Password: ")/2,"New Password: ");
 setcolor(15);
 rectangle(x,310-textheight("Confirm Password: ")/2,320+textwidth("Confirm Password: "),320+textheight("Confirm Password: "));
 outtextxy(320-textwidth("Confirm Password: "),320-textheight("Confirm Password: ")/2,"Confirm Password: ");
 ginput(320+textwidth("New Password: ")/8-40,160-textheight("New Password: ")/2,newpass,'p');
 setcolor(15);
 rectangle(x,150-textheight("New Password: ")/2,320+textwidth("Confirm Password: "),160+textheight("New Password: "));
 outtextxy(320-textwidth("New Password: "),160-textheight("New Password: ")/2,"New Password: ");
 setcolor(4);
 rectangle(x,310-textheight("Confirm Password: ")/2,320+textwidth("Confirm Password: "),320+textheight("Confirm Password: "));
 outtextxy(320-textwidth("Confirm Password: "),320-textheight("Confirm Password: ")/2,"Confirm Password: ");
 ginput(320+textwidth("Confirm Password: ")/8-40,320-textheight("Confirm Password: ")/2,cpass,'p');
 file.seekg(count*sizeof(login),ios::beg);
 l.accept(lid,cpass);
 file.write((char*)&l,sizeof(l));
 file.close();
}

void statpage() 	    // statistics page
{
 cleardevice();
 fstream loginf;
 loginf.open("login.dat",ios::binary | ios::in);
 char passlist[20],pass[20],name[20],head[20]={"Statistics"},lstr[20];
 long sc[3];
 login l;
 user.getinfo(lid,passlist,sc);
 while(loginf.read((char*)&l,sizeof(l)))
 {
  l.getinfo(name,pass,sc);
  if((strcmpi(name,lid)==0)&&(strcmpi(pass,passlist)==0))
  {
   user=l;
   break;
  }
 }
 user.getinfo(name,pass,sc);
 rectangle(10,10,630,470);
 settextstyle(0,0,4);
 outtextxy(320-textwidth(head)/2,30+textheight(head)/2,head);
 settextstyle(0,0,2);
 ltoa(sc[0],lstr,10);
 outtextxy(320+textwidth("High Score: ")/2-textwidth(lstr)/2,155-textheight("High Score: ")/2,lstr);
 outtextxy(320-textwidth("High Score: ")/2-textwidth(lstr)/2,155-textheight("High Score: ")/2,"High Score: ");
 ltoa(sc[1],lstr,10);
 outtextxy(320+textwidth("Latest Score: ")/2-textwidth(lstr)/2,260-textheight("Latest Score: ")/2,lstr);
 outtextxy(320-textwidth("Latest Score: ")/2-textwidth(lstr)/2,260-textheight("Latest Score: ")/2,"Latest Score: ");
 ltoa(sc[2],lstr,10);
 outtextxy(320+textwidth("Total Points: ")/2-textwidth(lstr)/2,365-textheight("Total Points: ")/2,lstr);
 outtextxy(320-textwidth("Total Points: ")/2-textwidth(lstr)/2,365-textheight("Total Points: ")/2,"Total Points: ");
 getch();
 mpage();
}

void clrstats()             //clear statistics
{
 cleardevice();
 char opt[][50]={"Yes","No"};
 fstream mod;
 login l;
 long sc[3];
 int ch=0;
 ch=toggle("Confirm",opt,2);
 if(ch==2)
 setpage();
 mod.open("login.dat",ios::binary | ios::in | ios::out);
 int count=0;
 mod.seekg(0,ios::beg);
 setcolor(15);
 char uname[20],passlist[20];
 user.getinfo(uname,passlist,sc);
 while(mod.read((char*)&l,sizeof(l)))
 {
  l.getinfo(lid,pass,sc);
  if((strcmpi(lid,uname)==0)&&(strcmpi(pass,passlist)==0))
  {
   l.s_upd(-1);
   mod.seekg(count*sizeof(l),ios::beg);
   mod.write((char*)&l,sizeof(l));
   break;
  }
  count++;
 }
 mod.close();
 setpage();
}

void delcu()		     //delete current user
{
 cleardevice();
 fstream louf,temp;
 login l;
 long sc[3];
 char opt[][50]={"Yes","No"};
 char tempstr[20],temppass[20];
 int ch;
 ch=toggle("Delete Account",opt,2);
 if(ch==2)
 setpage();
 user.getinfo(lid,pass,sc);
 louf.open("login.dat",ios::binary | ios::in );
 temp.open("templogin.dat",ios::binary | ios::out);
 while(louf.read((char*)&l,sizeof(l)))
 {
  l.getinfo(tempstr,temppass,sc);
  if((strcmpi(tempstr,lid)!=0)&&(strcmpi(temppass,pass)!=0))
  temp.write((char*)&l,sizeof(l));
 }
 temp.close();
 louf.close();
 remove("login.dat");
 rename("templogin.dat","login.dat");
 wpage();
}

void setpage()              // player setting page
{
 char sopt[][50]={"Change Password","Clear Stats","Delete Account","Return"};
 int ch;
 cleardevice();
 ch=toggle("Settings",sopt,4);
 switch(ch)
 {
  case 1:changepass();
	 break;
  case 2:clrstats();
	 break;
  case 3:delcu();
	 break;
  case 4:mpage();
	 break;
 }
}

int epage()                  //Exit page
{
 char eopt[][50]={"Yes","No"};
 int ch;
 cleardevice();
 ch=toggle("Confirm Exit",eopt,2);
 return ch;
}

void mpage()                  //main menu page
{
 cleardevice();
 char name[20],temp[20];
 long sc[3];
 user.getinfo(name,temp,sc);
 strcpy(temp,"User: ");
 strcat(temp,name);
 setcolor(15);
 settextstyle(0,0,1);
 outtextxy(getmaxx()-textwidth(temp)-5,20,temp);
 strcpy(temp,"Administrator");
 if(user.mac()==0)
 outtextxy(getmaxx()-textwidth(temp)-5,30,temp);
 char mopt[][50]={"Play","Periodic Table","Statistics","Settings","Logout","Exit"};
 int ch;
 ch=toggle("PeriodiX",mopt,6);
 switch(ch)
 {
  case 1:playm();
	 break;
  case 2:mainf(0);
	 break;
  case 3:statpage();
	 break;
  case 4:setpage();
	 break;
  case 5:wpage();
	 break;
  case 6:if(epage()==1)
	 exit(0);
 default:mpage();
 }
 mpage();
}

void viewelement()   	    //view element record
{
 cleardevice();
 element e;
 data dd;
 quest qq[5];
 coord cc;
 char ename[20];
 setcolor(15);
 rectangle(300-textwidth("Enter Element Name: "),200,620,280);
 outtextxy(340-textwidth("Enter Element Name: "),240-textheight("Enter Element Name: ")/2,"Enter Element Name: ");
 ginput(330,240-textheight("Enter Element Name: ")/2,ename);
 cleardevice();
 fstream efile;
 efile.open("e_data.dat",ios::binary | ios::in);
 int flag=-1;
 while(efile.read((char*)&e,sizeof(e)))
 {
  e.getdata(dd,qq,cc);
  if(strcmpi(dd.name,ename)==0)
  {
   flag=0;
   break;
  }
 }
 efile.close();
 if(flag==-1)
 {
  outtextxy(320-textwidth("Data Not Found")/2,240-textheight("Data Not Found")/2,"Data Not Found");
  getch();
  gdspage();
 }

 int bk[]={0,0,640,0,640,480,0,480};
 setfillstyle(1,15);
 fillpoly(4,bk);
 setcolor(0);
 rectangle(10,10,630,470);

 setfillstyle(1,cc.col);
 setcolor(cc.col);
 int tile[]={400,40,600,40,600,240,400,240};
 fillpoly(4,tile);
 setcolor(0);
 rectangle(405,45,595,235);

 settextstyle(0,0,8);
 outtextxy(500-textwidth(dd.sym)/2,140-textheight(dd.sym)/2,dd.sym);
 settextstyle(0,0,2);
 outtextxy(440,70,dd.atm);
 outtextxy(440,210-textheight(dd.atn),dd.atn);
 float y=40;
 outtextxy(35,y,"Name: ");
 outtextxy(35+textwidth("Name: "),y,dd.name);
 y+=45;
 outtextxy(35,y,"Symbol: ");
 outtextxy(35+textwidth("Symbol: "),y,dd.sym);
 y+=45;
 outtextxy(35,y,"Atomic Mass: ");
 outtextxy(35+textwidth("Atomic Mass: "),y,dd.atm);
 y+=45;
 outtextxy(35,y,"Atomic Number: ");
 outtextxy(35+textwidth("Atomic Number: "),y,dd.atn);
 y+=45;
 outtextxy(35,y,"Group: ");
 outtextxy(35+textwidth("Group: "),y,dd.grp);
 y+=45;
 outtextxy(35,y,"Period: ");
 outtextxy(35+textwidth("Period: "),y,dd.pd);
 y+=45;
 outtextxy(35,y,"Block: ");
 outtextxy(35+textwidth("Block: "),y,dd.blk);
 y+=45;
 outtextxy(35,y,"Type: ");
 outtextxy(35+textwidth("Type: "),y,dd.type);
 y+=45;
 outtextxy(35,y,"Configuration: ");
 config(20+textwidth("Configuration: "),y,dd.config);
 y+=45;
 getch();

 for(int i=0;i<5;i++)
 {
  cleardevice();
  setfillstyle(1,15);
  fillpoly(4,bk);
  setcolor(0);
  rectangle(10,10,630,470);
  char str[100]={'Q',i+'1','.',' '};
  strcat(str,qq[i].qstn);
  settextstyle(2,0,7);
  outtextxy(30,30,str);

  for(int n=0;n<4;n++)
  {
   char optno[]={'A'+n,' ',' ',' ','\0'};
   setcolor(0);
   line(10+textwidth(optno),114+n*84-textheight(qq[i].opt[0])/2,10+textwidth(optno),124+n*84+textheight(qq[i].opt[0]));
   rectangle(30,114+n*84-textheight(qq[i].opt[0])/2,500,124+n*84+textheight(qq[i].opt[0]));
   outtextxy(40,109+n*84,optno);
   outtextxy(70,109+n*84,qq[i].opt[n]);
  }
  outtextxy(40,79+n*84,"Ans: ");
  outtextxy(100,79+n*84,qq[i].ans);
  getch();
 }
 cleardevice();
 gdspage();
}

void gdspage()              //game settings page
{
 char gdsopt[][50]={"View Record","Set Default Data","Return"};
 int ch;
 cleardevice();
 setcolor(15);
 ch=toggle("Game Database ",gdsopt,3);
 switch(ch)
 {
  case 1:viewelement();
	 break;
  case 2:defwrite();
	 int gd=DETECT,gm;
	 initgraph(&gd,&gm,"c:\\tc\\bgi");
	 settextstyle(0,0,3);
	 outtextxy(320-textwidth("Data Reset Complete")/2,240-textheight("Data Reset Complete")/2,"Data Reset Complete");
	 getch();
	 break;
  case 3:gspage();
	 break;
 }
 gdspage();
}

void defwrite()
{
 clrscr();
 data d;
 element e;
 coord cd;
 quest q[5];
 fstream file,tfile;
 tfile.open("E_data.dat",ios::binary | ios::out);
 file.open("E_backup.dat",ios::binary | ios::in);
 while(file.read((char*)&e,sizeof(e)))
 {
  tfile.write((char*)&e,sizeof(e));
 }
 tfile.close();
 file.close();
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
  delay(20);
  clrscr();
 }
 file.close();
}

void lou() 		     //List of Users
{
 cleardevice();
 fstream louf;
 login l;
 char passlist[20][50];
 char namelist[20][50];
 long sc[50][3];
 int i=0;
 louf.open("login.dat",ios::binary | ios::in);
 while(louf.read((char*)&l,sizeof(l)))
 {
  l.getinfo(namelist[i],passlist[i],sc[i]);
  i++;
 }
 strcpy(namelist[i],"Return");
 int ch;
 ch=toggle("List of Users",namelist,i+1);
 ch--;
 if(ch==i)
 udspage();
 char lstr[20];
 cleardevice();
 rectangle(10,10,630,470);
 outtextxy(320+textwidth("Username: ")/2-textwidth(namelist[ch])/2,80-textheight("Username: ")/2,namelist[ch]);
 outtextxy(320-textwidth("Username: ")/2-textwidth(namelist[ch])/2,80-textheight("Username: ")/2,"Username: ");
 outtextxy(320+textwidth("Password: ")/2-textwidth(passlist[ch])/2,160-textheight("Password: ")/2,passlist[ch]);
 outtextxy(320-textwidth("Password: ")/2-textwidth(passlist[ch])/2,160-textheight("Password: ")/2,"Password: ");
 ltoa(sc[ch][0],lstr,10);
 outtextxy(320+textwidth("High Score: ")/2-textwidth(lstr)/2,240-textheight("High Score: ")/2,lstr);
 outtextxy(320-textwidth("High Score: ")/2-textwidth(lstr)/2,240-textheight("High Score: ")/2,"High Score: ");
 ltoa(sc[ch][1],lstr,10);
 outtextxy(320+textwidth("Latest Score: ")/2-textwidth(lstr)/2,320-textheight("Latest Score: ")/2,lstr);
 outtextxy(320-textwidth("Latest Score: ")/2-textwidth(lstr)/2,320-textheight("Latest Score: ")/2,"Latest Score: ");
 ltoa(sc[ch][2],lstr,10);
 outtextxy(320+textwidth("Total Points: ")/2-textwidth(lstr)/2,400-textheight("Total Points: ")/2,lstr);
 outtextxy(320-textwidth("Total Points: ")/2-textwidth(lstr)/2,400-textheight("Total Points: ")/2,"Total Points: ");
 getch();
 louf.close();
 lou();
}

void mod()             //modify user rights
{
 cleardevice();
 fstream mod;
 login l;
 char passlist[20][50];
 char namelist[20][50];
 long sc[20][3];
 int i=0;
 mod.open("login.dat",ios::binary | ios::in | ios::out);
 while(mod.read((char*)&l,sizeof(l)))
 {
  if(l.mac()!=0)
  {
   l.getinfo(namelist[i],passlist[i],sc[i]);
   i++;
  }
 }
 strcpy(namelist[i],"Return");
 int ch;
 ch=toggle("List of Users",namelist,i+1);
 ch--;
 if(ch==i)
 udspage();
 mod.close();
 mod.open("login.dat",ios::binary | ios::in | ios::out);
 int count=0;
 mod.seekg(0,ios::beg);
 setcolor(15);
 while(mod.read((char*)&l,sizeof(l)))
 {
  l.getinfo(lid,pass,sc[count]);
  if(strcmpi(namelist[ch],lid)==0)
  {
   l.madmin();
   mod.seekg(count*sizeof(l),ios::beg);
   mod.write((char*)&l,sizeof(l));
   break;
  }
  count++;
 }
 mod.close();
}

void deluser() 		     //delete user
{
 cleardevice();
 fstream louf,temp;
 login l;
 char passlist[20][50];
 char namelist[20][50];
 long sc[50][3];
 int i=0;
 louf.open("login.dat",ios::binary | ios::in);
 while(louf.read((char*)&l,sizeof(l)))
 {
  l.getinfo(namelist[i],passlist[i],sc[i]);
  i++;
 }
 strcpy(namelist[i],"Return");
 int ch;
 char tempstr[20],temppass[20];
 long tsc[3];
 ch=toggle("List of Users",namelist,i+1);
 ch--;
 if(ch==i)
 udspage();
 louf.close();
 louf.open("login.dat",ios::binary | ios::in );
 temp.open("templogin.dat",ios::binary | ios::out);
 while(louf.read((char*)&l,sizeof(l)))
 {
  l.getinfo(tempstr,temppass,tsc);
  if(strcmpi(tempstr,namelist[ch])!=0)
  temp.write((char*)&l,sizeof(l));
 }
 temp.close();
 louf.close();
 remove("login.dat");
 rename("templogin.dat","login.dat");
 udspage();
}

void udspage()               //user settings page
{
 char udsopt[][50]={"List of Users","Modify User Rights","Delete Users","Return"};
 int ch;
 cleardevice();
 ch=toggle("User Database",udsopt,4);
 switch(ch)
 {
  case 1:lou();
	 break;
  case 2:mod();
	 break;
  case 3:deluser();
	 break;
  case 4:gspage();
	 break;
 }
 udspage();
}

void gspage()                //admin settings page
{
 char gsopt[][50]={"Game Database","User Database","Return"};
 int ch;
 cleardevice();
 ch=toggle("Game Settings",gsopt,3);
 switch(ch)
 {
  case 1:gdspage();
	 break;
  case 2:udspage();
	 break;
  case 3:apage();
	 break;
 }
}

void apage()                   //Admin page
{
 char aopt[][50]={"Game","Game Settings"};
 int ch;
 cleardevice();
 ch=toggle("Proceed To - ",aopt,2);
 switch(ch)
 {
  case 1:mpage();
	 break;
  case 2:gspage();
	 break;
 }
}

void lpage()                       //Login page
{
 cleardevice();
 login l;
 settextstyle(0,0,2);
 setcolor(4);
 rectangle(60,100,580,140+textheight("Login ID: "));

 setcolor(15);
 rectangle(60,240,580,280+textheight("Password: "));
 outtextxy(80,120,"Login ID: ");
 outtextxy(80,260,"Password: ");
 ginput(80+textwidth("Login ID: "),120,lid,'n');
 rectangle(60,100,580,140+textheight("Login ID: "));

 setcolor(4);
 rectangle(60,240,580,280+textheight("Password: "));

 setcolor(15);
 ginput(80+textwidth("Password: "),260,pass,'p');
 fstream file;
 file.open("login.dat",ios::binary | ios::in);
 int flag=-1;
 while(file.read((char*)&l,sizeof(l)))
 {
  if(l.mname(lid)==0)
  {
   if(l.mpass(pass)==0)
   {
    flag=0;
    break;
   }
  }
 }
 char mstr1[]={"Credentials Not Found."};
 char mstr2[]={"Please Try Again Later."};
 char mstr3[]={"Contact Administrator"};
 if(flag==-1)
 {
  setcolor(15);
  outtextxy(320-textwidth(mstr1)/2,340,mstr1);
  outtextxy(320-textwidth(mstr2)/2,350+textheight(mstr1),mstr2);
  outtextxy(320-textwidth("Or")/2,360+textheight(mstr1)+textheight(mstr2),"Or");
  outtextxy(320-textwidth(mstr3)/2,370+textheight(mstr1)+textheight(mstr2)+textheight("Or"),mstr3);

  getch();
  wpage();
 }
 user=l;
 if((l.mac()==0))
 apage();
 else
 mpage();
}

void spage()                           //Sign Up page
{
 cleardevice();
 login l;
 char lid[50],pass[50],cpass[50];
 settextstyle(0,0,2);

 outtextxy(80,110,"Login ID: ");
 outtextxy(80,230,"Password: ");
 outtextxy(80,340,"Confirm ");
 outtextxy(74,360+textheight("Confirm")/2,"Password ");
 outtextxy(82+textwidth("Password"),346+textheight("Confirm")/4,": ");
 setcolor(4);
 rectangle(60,80,580,140+textheight("Login ID: "));

 setcolor(15);
 rectangle(60,200,580,260+textheight("Password: "));

 setcolor(15);
 rectangle(60,320,580,380+textheight("Confirm Password: "));
 ginput(80+textwidth("Login ID: "),110,lid,'n');

 setcolor(15);
 rectangle(60,80,580,140+textheight("Login ID: "));

 setcolor(4);
 rectangle(60,200,580,260+textheight("Password: "));

 setcolor(15);
 rectangle(60,320,580,380+textheight("Confirm Password: "));
 ginput(80+textwidth("Password: "),230,pass,'p');

 setcolor(15);
 rectangle(60,80,580,140+textheight("Login ID: "));

 setcolor(15);
 rectangle(60,200,580,260+textheight("Password: "));

 setcolor(4);
 rectangle(60,320,580,380+textheight("Confirm Password: "));
 ginput(82+textwidth("Password: "),350,cpass,'p');

 char cstr[]={"Passwords Do not Match. Please Try Again"};
 if(strcmpi(cpass,pass)!=0)
 {
  setcolor(15);
  outtextxy(320-textwidth(cstr)/2,415,cstr);
  getch();
  wpage();
 }
 l.accept(lid,pass);
 fstream file;
 file.open("login.dat",ios::binary | ios :: app);
 file.write((char*)&l,sizeof(l));
 file.close();
 user=l;
 mpage();
}

void slantellipse(float m,int s1,int s2)
{
 float xi,yi,x,y;
 float i;
 for(i=-m;i<=m && !kbhit();i+=0.1)
 {
  y=310+(s1*10*(sqrt((m*m)-(i*i))+(s2*i)));
  x=320+10*i;
  if(i==-m)
  putpixel(x,y,0);
  else
  line(xi,yi,x,y);
  xi=x;
  yi=y;
 }
}

void wpage() 			//welcome page
{
 int ch;
 static int count=0;
 if(count==0)
 {
  cleardevice();
  setfillstyle(1,15);
  bar(0,0,640,480);
  setcolor(0);
  rectangle(8,8,632,472);
  setfillstyle(1,0);
  setcolor(0);
  setfillstyle(1,4);
  setcolor(0);
  fillellipse(320,310,20,20);

  slantellipse(8,1,1);
  slantellipse(8,1,-1);
  slantellipse(8,-1,-1);
  slantellipse(8,-1,1);
  slantellipse(7.6,1,1);
  slantellipse(7.6,1,-1);
  slantellipse(7.6,-1,-1);
  slantellipse(7.6,-1,1);
  ellipse(320,310,0,360,124,30);
  ellipse(320,310,0,360,128,32);

  setfillstyle(1,14);
  setcolor(0);
  fillellipse(385,201,10,10);
  fillellipse(255,201,10,10);
  fillellipse(385,419,10,10);
  fillellipse(255,419,10,10);
  fillellipse(446,310,10,10);
  fillellipse(194,310,10,10);

  setcolor(0);
  settextstyle(1,0,5);
  outtextxy(320-textwidth("PeriodiX")/2,30,"PeriodiX");
  settextstyle(1,0,3);
  outtextxy(320-textwidth("\"A Periodic Table with a Difference\"")/2,90,"\"A Periodic Table with a Difference\"");
  outtextxy(320-textwidth("- By Shashank Goyal")/2,130,"- By Shashank Goyal");
  delay(30);
  setcolor(0);
  settextstyle(1,0,2);
  outtextxy(620-textwidth("Press Enter to Continue....."),460-textheight("Press Enter to Continue....."),"Press Enter to Continue.....");
  getch();
  cleardevice();
  setfillstyle(1,15);
  bar(0,0,640,480);
  setcolor(0);
  rectangle(10,10,630,470);
  settextstyle(1,0,5);
  line(320-textwidth("Instructions")/2,60-textheight("Instructions")/2,320+textwidth("Instructions")/2,60-textheight("Instructions")/2);
  outtextxy(320-textwidth("Instructions")/2,55-textheight("Instructions")/2,"Instructions");
  line(320-textwidth("Instructions")/2,40+textheight("Instructions"),320+textwidth("Instructions")/2,40+textheight("Instructions"));
  setcolor(0);
  circle(40,180,2);
  settextstyle(1,0,1);
  outtextxy(60,180-textheight("Use")/2,"Use");
  int x=110,y=180;
  int arrblk[]={x,y,x+30,y,x+30,y-30,x+60,y-30,x+60,y,x+90,y,x+90,y+30,x+60,y+30,x+60,y,x+30,y,x+30,y+30,x+60,y+30,x,y+30,x,y};
  setcolor(0);
  drawpoly(14,arrblk);
  outtextxy(x+45-textwidth("W")/2,y-15-textheight("W")/2,"W");
  outtextxy(x+15-textwidth("A")/2,y+15-textheight("A  S  D")/2,"A  S  D");
  char msg[]={" for moving Up, Down, Left and Right."};
  outtextxy(220,180-textheight("Use")/2,msg);
  circle(40,320,2);
  int entblk[]={120,310,150,310,150,280,200,280,200,340,120,340,120,310};
  drawpoly(7,entblk);
  strcpy(msg,"Press    Enter   to Select.");
  outtextxy(60,320-textheight("Use")/2,msg);
  outtextxy(620-textwidth("Press Enter to Continue....."),450-textheight("Press Enter to Continue....."),"Press Enter to Continue.....");
  getch();
  count++;
 }
 char lopt[][50]={"Login","Signup","Exit"};
 cleardevice();
 ch=toggle("Welcome",lopt,3);
 switch(ch)
 {
  case 1:lpage();
	 break;
  case 2:spage();
	 break;
  case 3:if(epage()==1)
	 exit(0);
	 else
	 wpage();
	 break;
  default:wpage();
 }
}

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

void cnt(float x,float y)
{
 cleardevice();
 setfillstyle(1,15);
 bar(0,0,640,480);
 rectangle(10,10,630,470);
 setfillstyle(1,7);
 setcolor(0);
 settextstyle(0,0,3);
 outtextxy(320-textwidth("Controls")/2,40,"Controls");
 line(320-textwidth("Controls")/2,35,320+textwidth("Controls")/2,35);
 line(320-textwidth("Controls")/2,40+textheight("Controls"),320+textwidth("Controls")/2,40+textheight("Controls"));
 int polyr[]={x+5,y-5,x+60,y-5,x+60,y-10,x+100,y,x+60,y+10,x+60,y+5,x+5,y+5};
 fillpoly(7,polyr);
 drawpoly(7,polyr);
 int polyd[]={x+5,y+5,x+5,y+60,x+10,y+60,x,y+100,x-10,y+60,x-5,y+60,x-5,y+5};
 fillpoly(7,polyd);
 drawpoly(7,polyd);
 int polyl[]={x-5,y-5,x-60,y-5,x-60,y-10,x-100,y,x-60,y+10,x-60,y+5,x-5,y+5};
 fillpoly(7,polyl);
 drawpoly(7,polyl);
 int polyu[]={x+5,y-5,x+5,y-60,x+10,y-60,x,y-100,x-10,y-60,x-5,y-60,x-5,y-5};
 fillpoly(7,polyu);
 drawpoly(7,polyu);
 char str[][11]={"A (Left)","S (Down)","D (Right)","W (Up)"};
 fillellipse(x,y,40,40);
 settextstyle(0,0,2);
 outtextxy(x+120,y-textheight(str[2])/2,str[2]);
 outtextxy(x-120-textwidth(str[0]),y-textheight(str[0])/2,str[0]);
 outtextxy(x-textwidth(str[1])/2+3,y+120,str[1]);
 outtextxy(x-textwidth(str[3])/2+3,y-120-textheight(str[3])/2-15,str[3]);
 char msg[40]={'E','s','c',' ',26,'\0'};
 strcat(msg," Exit");
 outtextxy(320-textwidth(msg)/2,430,msg);
 settextstyle(0,0,1);
 setcolor(0);
 outtextxy(x+3-textwidth("Enter")/2,y-textheight("Enter")-2,"Enter");
 outtextxy(x+3-textwidth("(Select)")/2,y+textheight("Select")-5,"(Select)");

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
 float x=39.5,y=82;
 int col=15;
 char ch=13;
/*1*/ char e1[][4]={"H","","","","","","","","","","","","","","","","","He","Li","Be","","","","","","","","","","","B","C","N","O","F","Ne","Na","Mg","","","","","","","","","","","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La*"};
/*2*/ char e3[][4]={"Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu"};
/*3*/ char e2[][4]={"Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac#"};
/*4*/ char e4[][4]={"Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};
/*5*/ char e5[][4]={"Rf","Db","Sg","Bh","Hs","Mt"};
 char msg[]={"Data for the Element does not Exist."};
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
  nav(x,y,col,para);
  if(para!=1)
  ch=getch();
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
   else if(ch==27)
   mpage();
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

void scorepage(int score[5],int count)
{
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
 if(sum>0)
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

int play(int ur=109,int lvl=1)
{
 clrscr();
 int lr=1;
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

 scorepage(score,lvl);

 file.close();
 return sum;
}

void main()
{
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 wpage();
 getch();
 closegraph();
}
