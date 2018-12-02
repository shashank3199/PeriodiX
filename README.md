![Version Tag](https://img.shields.io/badge/Version-1.1.0-blue.svg)

# PeriodiX

This is my Class 12 Computer Science Project.
This Code has been prepared on [Turbo C++]( https://en.wikipedia.org/wiki/Turbo_C%2B%2B )  .
It uses Graphics.h for the Graphical User Interface.

### Files in the Repository
The files in the repository are :

#### Project.cpp
This is File that contains the Source Code for the Project.

#### README.md
The Description file containing details about the repository. The file that you looking at right now.

#### Computer Project.pdf
The Project Report. Contains the Same Data as this README.

#### .Output
This folder contains the Output images for the README.

#### .Backup
This Folder contains the Backup/Test Files that were used in the preparation of the Project.

## Header Files Used

| HEADER FILE   | FUNCTIONS USED |
| ------------- |:---------------------------------------------------------:|
| Fstream.h     | Cout  ,  Cin ,   Open (  )  ,   Close (  )  ,    Read (  )  ,   Write (  )  ,  Seekg (  )  |
| Conio.h       | Kbhit (  )  ,   Getch (  )  ,   Clrscr (  )        |
| String.h      | Strcpy (  )  ,   Strcmpi (  )  ,   Strlen (  )  ,   Strcat (  )  |
| Stdlib.h      | Ltoa (  )  ,   Itoa (  )  ,   Exit (  )  ,   Randomize (  )  ,   Random (  )  |
| Stdio.h       | Remove (  )  ,   Rename (  )  |
| Dos.h         | Delay (  )  ,   Sleep (  )   |
| Math.h        | Sqrt (  )  |
| Ctype.h       | Isalpha (  )  ,   Isspace (  )  ,    Isdigit (  )  ,  Ispunct (  )  |
| Iomanip.h     | Setw (  )   |
| Graphics.h    | Initgraph (  )  ,   Cleardevice (  )  ,    Gettextsettings (  )  ,    Settextstyle (  )  ,   Outtextxy (  )  ,   Textwidth (  )  ,   Textheight (  )  ,   Setcolor (  )  ,   Setfillstyle (  )  ,   Getbkcolor (  )  ,   Line (  )  ,   Fillpoly (  )  ,   Drawpoly (  )  ,   Rectangle (  )  ,   Bar (  )  ,    Circle (  )  ,   Ellipse (  )  ,   Fillellipse (  )  ,  Getpixel (  )  ,   Putpixel (  )   ,  Closegraph (  )  |

## Structures Used

#### Struct quest : Question/Answer for each Element.
- Questions for the Element.
- Options as an array of 4 Options for each of the Questions.
- Answers for each of the Questions.

#### Struct coord : Coordinates for each Element in the Table.
- X - Coordinate.
- Y - Coordinate.
- Color of the Element.

#### Struct data : Chemical Data for each Element.
- Name.
- Symbol.
- Group.
- Period.
- Atomic Mass.
- Atomic Number.
- Electronic Configuration.
- Block.
- Element Type.

## Classes Used

#### Class element : Data Type for each Element.
- Data
- Coord
- Array of Quest

| FUNCTION NAME | FUNCTIONALITY |
| ------------- | :------------------------: |
| void putblktypepd (  )  ; | Used to Calculate the Block ,   period and Type of Element Depending Upon its Position in the Periodic Table. |
| void putd ( data )  ; | Used to put Structure  Data details in an Object of  Class Element. |
| void putcoord ( coord )  ;  | Used to put Structure  Coord details in an Object of  Class Element. |
| void putq ( quest  [ ]  )  ; | Used to put Structure  Question details in an  Object of  Class Element. |
| void getdata ( data& ,  quest [ ]  ,  coord& )  ; | Used to Get the details of an Element in the form of Data ,   Questions and Coordinates. |
| int matchxy ( float ,  float )  ; | Used to match the  ( x ,  y )   Coordinates of an Element in the Periodic Table. |
| element (  )  ; | Constructor to Initialize  all data Members  with NULL Values. |

#### Class login : Data Type for each User.
- Name
- Password
- Access Type
- Highest Score
- Latest/Current Score
- Total Points

| FUNCTION NAME | FUNCTIONALITY |
| ------------- | :------------------------: |
| void accept ( char  [ ]  ,  char  [ ]  )  ; |  Accept Login ID Details. |
| void getinfo ( char  [ ]  ,  char  [ ]  ,  long  [ ]  )  ;  | Used to Return the Login ID  Details of a User. |
| void s_upd ( long )  ; | Used to Update the Score  of a User. |
| void madmin (  )  ; | Used to Give a User Administrative Access.  |
| int mname ( char  [ ]  )  ; | Used to Match a Name with that of the User. |
| int mpass ( char  [ ]  )  ; | Used to Match a Password with that of the User. |
| int mac (  )  ; | Checks whether  a user has  Administrative Rights  |
| login (  )  ; | Constructor to Initialize  all data Members  with NULL Values. |

## Global Functions

| FUNCTION NAME | FUNCTIONALITY |
| ------------- | :------------------------: |
| void sup ( float x ,  float y ,  char str [ ]  ) ; | Displays a String as a Superscript at  ( x , y ) . |
| void config ( float x ,  float y ,  char str [ ]  ) ; | Displays the Configuration of an Element. |
| void ginput ( float x ,  float y ,  char str [ ]  , char type ) ; | Used to Take the User  Input in Graphics Mode Depending Upon the Call as Password or Regular Text.|
| void playm (  ) ; | Creates the Menu for  Play Option. |
| void changepass (  ) ; | Creates the Menu for  changing the  User Password. |
| void statpage (  ) ; | Displays the User Statistics. |
| void clrstats (  ) ; | Clears the User Statistics. |
| void delcu (  ) ; | Deletes the Current User Account. |
| void setpage (  ) ; | Creates the Menu for the  User Settings Page. |
| void mpage (  ) ; | Creates the Main  Game Menu. |
| void viewelement (  ) ; | Displays the Details  of an Element. |
| void gdspage (  ) ; | Creates the Menu for  Game Data Settings. |
| void lou (  ) ; | Displays the List of  User Accounts. |
| void mod (  ) ; | Used to give Administrative Rights to a Non – Admin. |
| void deluser (  ) ; | Used to Delete a User from the List of Users.
| void udspage (  ) ; | Creates the Menu for  User Data Settings. |
| void apage (  ) ; | Creates a Menu for an Administrator to Change the Game Settings. |
| void lpage (  ) ; | Creates the Login Page. |
| void spage (  ) ; | Creates the Sign Up Page. |
| void wpage (  ) ; | Creates the Welcome Page. |
| void e_screenf  ( float x ,  float y ) ; | Displays the Information about an element at the location  ( x , y )  in the  Periodic Table. |
| void coordwrite ( float x , float y , int col )  | Used to Write the  Coordinates of an  Element into the File. |
| void screen ( int para ) ;  | Used to Display the  Periodic Table. |
| void cnt ( float x ,  float y ) ; | Used to Display the Controls for the Periodic Table. |
| void nav ( float &x ,  float &y ,  int &col ,  int para ) ; | Used to Navigate  through the  Periodic Table. |
| void rect ( int x1 , int y1 , int x2 , int y2 , int x3 , int y3 , int x4 , int y4 ) ; | Used to make a  Quadrilateral. |
| void mainf ( int para ) ; | Used for the Periodic table Option in the Main Menu. |
| void display ( element e ) ; | Used to Display the Element  During the Game. |
| void randomarr ( int rec [ ]  , int n ) ; | Used to Give  Random values to an Array starting from Zero. |
| void blk ( char temp [ ] [30] ) ; | Used to Generate random Blocks as Options for the Questions. |
| void defwrite (  ) ; | Used to Set Default values to  The Element Data  in case of any Errors. |
| void questrandom ( quest qq[5] ) ; | Randomizes  Question and Options  Order Every time  the Game is Played. |
| void scorepage ( int score[5] , int lvl ) ; | Displays the Score and the Result of a Level. |
| void userupdate ( long ) ; | Updates the Score of the Player after every Level. |
| int epage (  ) ; | Exit Page. |
| int play ( int ur , int lvl ) ; | Used to Play the Game. |
| int toggle ( char head [ ]  , char menu [ ] [50] , int r ) ; | Used to Create Menu ( s )   And Select the Options. |
| char* opttoogle ( quest qq [ ]  , int i ) ; | Toggle through the  Question Options. |
| void slantellipse ( float m , int s1 , int s2 ) ; | Used to make  Slanted Ellipse. |

## Output Screens
![IMG-1](./.Output/1.JPG)<br><br>
![IMG-2](./.Output/2.JPG)<br><br>
![IMG-3](./.Output/2.JPG)<br><br>
![IMG-4](./.Output/Signup - 3/3 a.JPG)<br><br>
![IMG-5](./.Output/Signup - 3/3 b.JPG)<br><br>
![IMG-6](./.Output/Signup - 3/3 c.JPG)<br><br>
![IMG-7](./.Output/Signup - 3/3 d.JPG)<br><br>
![IMG-8](./.Output/Login - NA - 4/4 a.JPG)<br><br>
![IMG-9](./.Output/Login - NA - 4/4 b.JPG)<br><br>
![IMG-10](./.Output/Login - NA - 4/4 c.JPG)<br><br>
![IMG-11](./.Output/Login - NA - 4/4 d.JPG)<br><br>
![IMG-12](./.Output/Login - A - 5/5 a.JPG)<br><br>
![IMG-13](./.Output/Login - A - 5/5 b.JPG)<br><br>
![IMG-14](./.Output/Login - A - 5/Game Database/5 b i.JPG)<br><br>
![IMG-15](./.Output/Login - A - 5/Game Database/View Record/5 b ii.JPG)<br><br>
![IMG-16](./.Output/Login - A - 5/Game Database/View Record/5 b iii.JPG)<br><br>
![IMG-17](./.Output/Login - A - 5/Game Database/View Record/5 b iv.JPG)<br><br>
![IMG-18](./.Output/Login - A - 5/Game Database/View Record/5 b v.JPG)<br><br>
![IMG-19](./.Output/Login - A - 5/Game Database/View Record/5 b vi.JPG)<br><br>
![IMG-20](./.Output/Login - A - 5/Game Database/View Record/5 b vii.JPG)<br><br>
![IMG-21](./.Output/Login - A - 5/Game Database/View Record/5 b viii.JPG)<br><br>
![IMG-22](./.Output/Login - A - 5/Game Database/View Record/5 b fail.JPG)<br><br>
![IMG-23](./.Output/Login - A - 5/Game Database/View Record/5 b fail .Output.JPG)<br><br>
![IMG-24](./.Output/Login - A - 5/Game Database/reset data/5 b x.JPG)<br><br>
![IMG-25](./.Output/Login - A - 5/Game Database/reset data/5 b xi.JPG)<br><br>
![IMG-26](./.Output/Login - A - 5/Game Database/5 b xii.JPG)<br><br>
![IMG-27](./.Output/Login - A - 5/User Database/5 b 1.JPG)<br><br>
![IMG-28](./.Output/Login - A - 5/User Database/list of users/5 b 2.JPG)<br><br>
![IMG-29](./.Output/Login - A - 5/User Database/list of users/5 b 2 a.JPG)<br><br>
![IMG-30](./.Output/Login - A - 5/User Database/list of users/5 b 2 b.JPG)<br><br>
![IMG-31](./.Output/Login - A - 5/User Database/list of users/5 b 2 c.JPG)<br><br>
![IMG-32](./.Output/Login - A - 5/User Database/Mod user rights/5 b 3.JPG)<br><br>
![IMG-33](./.Output/Login - A - 5/User Database/Mod user rights/5 b 3 a.JPG)<br><br>
![IMG-34](./.Output/Login - A - 5/User Database/Mod user rights/5 b 3 b.JPG)<br><br>
![IMG-35](./.Output/Login - A - 5/User Database/Mod user rights/5 b 3 c.JPG)<br><br>
![IMG-36](./.Output/Login - A - 5/User Database/Delete user/5 b 4.JPG)<br><br>
![IMG-37](./.Output/Login - A - 5/User Database/Delete user/5 b 4 a.JPG)<br><br>
![IMG-38](./.Output/Login - A - 5/User Database/Delete user/5 b 4 b.JPG)<br><br>
![IMG-39](./.Output/Login - A - 5/User Database/Delete user/5 b 4 c.JPG)<br><br>
![IMG-40](./.Output/Login - A - 5/5 c.JPG)<br><br>
![IMG-41](./.Output/Login - A - 5/6.JPG)<br><br>
![IMG-42](./.Output/Main menu -6/a - game/6 a.JPG)<br><br>
![IMG-43](./.Output/Main menu -6/a - game/6 a 1.JPG)<br><br>
![IMG-44](./.Output/Main menu -6/a - game/6 a 2.JPG)<br><br>
![IMG-45](./.Output/Main menu -6/a - game/6 a 2 a.JPG)<br><br>
![IMG-46](./.Output/Main menu -6/a - game/6 a 2 b.JPG)<br><br>
![IMG-47](./.Output/Main menu -6/a - game/6 a 2 c.JPG)<br><br>
![IMG-48](./.Output/Main menu -6/a - game/6 a 2 d.JPG)<br><br>
![IMG-49](./.Output/Main menu -6/a - game/6 a 2 e.JPG)<br><br>
![IMG-50](./.Output/Main menu -6/a - game/6 a 2 f.JPG)<br><br>
![IMG-51](./.Output/Main menu -6/a - game/6 a 2 g.JPG)<br><br>
![IMG-52](./.Output/Main menu -6/a - game/6 a 2 h.JPG)<br><br>
![IMG-53](./.Output/Main menu -6/a - game/6 a 2 i.JPG)<br><br>
![IMG-54](./.Output/Main menu -6/a - game/6 a 2 j.JPG)<br><br>
![IMG-55](./.Output/Main menu -6/b - periodic table/6 b.JPG)<br><br>
![IMG-56](./.Output/Main menu -6/b - periodic table/6 b 1.JPG)<br><br>
![IMG-57](./.Output/Main menu -6/b - periodic table/6 b 2.JPG)<br><br>
![IMG-58](./.Output/Main menu -6/b - periodic table/6 b 3.JPG)<br><br>
![IMG-59](./.Output/Main menu -6/b - periodic table/6 b 4.JPG)<br><br>
![IMG-60](./.Output/Main menu -6/c - statistics/6 c.JPG)<br><br>
![IMG-61](./.Output/Main menu -6/c - statistics/6 c 1.JPG)<br><br>
![IMG-62](./.Output/Main menu -6/d - settings/6 d.JPG)<br><br>
![IMG-63](./.Output/Main menu -6/d - settings/6 d a.JPG)<br><br>
![IMG-64](./.Output/Main menu -6/d - settings/change pass/6 d 1.JPG)<br><br>
![IMG-65](./.Output/Main menu -6/d - settings/change pass/6 d 1 a.JPG)<br><br>
![IMG-66](./.Output/Main menu -6/d - settings/change pass/6 d 1 b.JPG)<br><br>
![IMG-67](./.Output/Main menu -6/d - settings/clear stats/6 d 2.JPG)<br><br>
![IMG-68](./.Output/Main menu -6/d - settings/clear stats/6 d 2 a.JPG)<br><br>
![IMG-69](./.Output/Main menu -6/d - settings/clear stats/6 d 2 b.JPG)<br><br>
![IMG-70](./.Output/Main menu -6/d - settings/clear stats/6 d 2 c.JPG)<br><br>
![IMG-71](./.Output/Main menu -6/d - settings/del acc/6 d 3.JPG)<br><br>
![IMG-72](./.Output/Main menu -6/d - settings/del acc/6 d 3 a.JPG)<br><br>
![IMG-73](./.Output/Main menu -6/d - settings/del acc/6 d 3 b.JPG)<br><br>
![IMG-74](./.Output/Main menu -6/d - settings/del acc/6 d 3 c.JPG)<br><br>
![IMG-75](./.Output/Main menu -6/e - logout/6 e 1.JPG)<br><br>
![IMG-76](./.Output/Main menu -6/e - logout/6 e 1 a.JPG)<br><br>
![IMG-77](./.Output/Main menu -6/f - exit/6 f 1.JPG)<br><br>
![IMG-78](./.Output/Main menu -6/f - exit/6 f 1 a.JPG)<br>

## Bibliography
- http://www.science.co.il/elements/.
- [Grapher Software] ( https://www.desmos.com/calculator ) .
- Class 11 NCERT Chemistry.<br>

[![Developers Tag]( https://img.shields.io/badge/Developer-shashank3199-red.svg ) ]( https://github.com/shashank3199 )
