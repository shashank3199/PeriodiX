#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<process.h>
#include<infnew.cpp>

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

char lid[50],pass[50];
void wpage();
void mpage();
void gspage();
void apage();
void udspage();
void lou();
void mod();
void deluser();
void setpage();
void gdspage();
void udspage();
login user;

void playm()                //game page
{
 char popt[][50]={"Easy","Medium","Hard","Return"};
 int ch;
 cleardevice();
 ch=toggle("Play",popt,4);
 if(ch==4)
 mpage();
}

void changepass()	    // password change page
{
 cleardevice();
 login l;
 char newpass[20];
 char cpass[20];
 settextstyle(0,0,2);
 setcolor(4);
 outtextxy(80,240,"Password: ");
 rectangle(60,200,580,280);
 setcolor(15);
 ginput(80+textwidth("Password: "),240,pass,'p');
 fstream file;
 file.open("login.dat",ios::binary | ios::in | ios::out);
 int flag=-1,count=0;;
 long sc[3];
 user.getinfo(lid,pass,sc);
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
 char pass[20],name[20],head[20]={"Statistics"},lstr[20];
 long sc[3];
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
 char uname[20];
 user.getinfo(uname,pass,sc);
 while(mod.read((char*)&l,sizeof(l)))
 {
  l.getinfo(lid,pass,sc);
  if(strcmpi(lid,uname)==0)
  {
   l.s_upd(0,0);
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
  if(strcmpi(tempstr,lid)!=0)
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
 ch=toggle("Game Name",mopt,6);
 switch(ch)
 {
  case 1:playm();
	 break;
  case 3:statpage();
	 break;
  case 4:setpage();
	 break;
  case 5:wpage();
	 break;
  case 6:if(epage()==1)
	 exit(0);
	 else
	 mpage();
	 break;
  default:mpage();
 }
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
  case 3:gspage();
	 break;
 }
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

void wpage() 			//welcome page
{
 int ch;
 cleardevice();
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

void main()
{
 clrscr();
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 wpage();
 getch();
 closegraph();
}
