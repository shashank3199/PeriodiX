![Version Tag](https://img.shields.io/badge/Version-1.1.0-blue.svg)

# PeriodiX

This is my Class 12 Computer Science Project.
This Code has been preparedon [Turbo C++]( https://en.wikipedia.org/wiki/Turbo_C%2B%2B )  .
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
This Folder contains the Backup/Test Files that were usedin the preparation of the Project.

## Header Files Used

| HEADER FILE   | FUNCTIONS USEd|
| ------------- |:---------------------------------------------------------:|
| Fstream.h     | Cout  ,  Cin ,   Open (  )  ,   Close (  )  ,    Read(  )  ,   Write (  )  ,  Seekg (  )  |
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

#### Struct coord: Coordinates for each Element in the Table.
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
| voidputblktypepd(  )  ; | Usedto Calculate the Block ,   periodandType of Element Depending Upon its Position in the Periodic Table. |
| voidputd( data )  ; | Usedto put Structure  Data details in an Object of  Class Element. |
| voidputcoord( coord)  ;  | Usedto put Structure  Coorddetails in an Object of  Class Element. |
| voidputq ( quest  [ ]  )  ; | Usedto put Structure  Question details in an  Object of  Class Element. |
| voidgetdata ( data& ,  quest [ ]  ,  coord& )  ; | Usedto Get the details of an Element in the form of Data ,   Questions andCoordinates. |
| int matchxy ( float ,  float )  ; | Usedto match the  ( x ,  y )   Coordinates of an Element in the Periodic Table. |
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
| voidaccept ( char  [ ]  ,  char  [ ]  )  ; |  Accept Login IdDetails. |
| voidgetinfo ( char  [ ]  ,  char  [ ]  ,  long  [ ]  )  ;  | Usedto Return the Login Id Details of a User. |
| voids_upd( long )  ; | Usedto Update the Score  of a User. |
| voidmadmin (  )  ; | Usedto Give a User Administrative Access.  |
| int mname ( char  [ ]  )  ; | Usedto Match a Name with that of the User. |
| int mpass ( char  [ ]  )  ; | Usedto Match a Passwordwith that of the User. |
| int mac (  )  ; | Checks whether  a user has  Administrative Rights  |
| login (  )  ; | Constructor to Initialize  all data Members  with NULL Values. |

## Global Functions

| FUNCTION NAME | FUNCTIONALITY |
| ------------- | :------------------------: |
| voidsup ( float x ,  float y ,  char str [ ]  ) ; | Displays a String as a Superscript at  ( x , y ) . |
| voidconfig ( float x ,  float y ,  char str [ ]  ) ; | Displays the Configuration of an Element. |
| voidginput ( float x ,  float y ,  char str [ ]  , char type ) ; | Usedto Take the User  Input in Graphics Mode Depending Upon the Call as Passwordor Regular Text.|
| voidplaym (  ) ; | Creates the Menu for  Play Option. |
| voidchangepass (  ) ; | Creates the Menu for  changing the  User Password. |
| voidstatpage (  ) ; | Displays the User Statistics. |
| voidclrstats (  ) ; | Clears the User Statistics. |
| voiddelcu (  ) ; | Deletes the Current User Account. |
| voidsetpage (  ) ; | Creates the Menu for the  User Settings Page. |
| voidmpage (  ) ; | Creates the Main  Game Menu. |
| voidviewelement (  ) ; | Displays the Details  of an Element. |
| voidgdspage (  ) ; | Creates the Menu for  Game Data Settings. |
| voidlou (  ) ; | Displays the List of  User Accounts. |
| voidmod(  ) ; | Usedto give Administrative Rights to a Non – Admin. |
| voiddeluser (  ) ; | Usedto Delete a User from the list-of-users.
| voidudspage (  ) ; | Creates the Menu for  User Data Settings. |
| voidapage (  ) ; | Creates a Menu for an Administrator to Change the Game Settings. |
| voidlpage (  ) ; | Creates the Login Page. |
| voidspage (  ) ; | Creates the Sign Up Page. |
| voidwpage (  ) ; | Creates the Welcome Page. |
| voide_screenf  ( float x ,  float y ) ; | Displays the Information about an element at the location  ( x , y )  in the  Periodic Table. |
| voidcoordwrite ( float x , float y , int col )  | Usedto Write the  Coordinates of an  Element into the File. |
| voidscreen ( int para ) ;  | Usedto Display the  Periodic Table. |
| voidcnt ( float x ,  float y ) ; | Usedto Display the Controls for the Periodic Table. |
| voidnav ( float &x ,  float &y ,  int &col ,  int para ) ; | Usedto Navigate  through the  Periodic Table. |
| voidrect ( int x1 , int y1 , int x2 , int y2 , int x3 , int y3 , int x4 , int y4 ) ; | Usedto make a  Quadrilateral. |
| voidmainf ( int para ) ; | Usedfor the Periodic table Option in the Main Menu. |
| voiddisplay ( element e ) ; | Usedto Display the Element  During the Game. |
| voidrandomarr ( int rec [ ]  , int n ) ; | Usedto Give  Random values to an Array starting from Zero. |
| voidblk ( char temp [ ] [30] ) ; | Usedto Generate random Blocks as Options for the Questions. |
| voiddefwrite (  ) ; | Usedto Set Default values to  The Element Data  in case of any Errors. |
| voidquestrandom ( quest qq[5] ) ; | Randomizes  Question andOptions  Order Every time  the Game is Played. |
| voidscorepage ( int score[5] , int lvl ) ; | Displays the Score andthe Result of a Level. |
| voiduserupdate ( long ) ; | Updates the Score of the Player after every Level. |
| int epage (  ) ; | Exit Page. |
| int play ( int ur , int lvl ) ; | Usedto Play the Game. |
| int toggle ( char head[ ]  , char menu [ ] [50] , int r ) ; | Usedto Create Menu ( s )   AndSelect the Options. |
| char* opttoogle ( quest qq [ ]  , int i ) ; | Toggle through the  Question Options. |
| voidslantellipse ( float m , int s1 , int s2 ) ; | Usedto make  SlantedEllipse. |

## Output Screens
![IMG-1](./.Output/1.jpg)<br><br>
![IMG-2](./.Output/2.jpg)<br><br>
![IMG-4](./.Output/Signup-3/3a.jpg)<br><br>
![IMG-5](./.Output/Signup-3/3b.jpg)<br><br>
![IMG-6](./.Output/Signup-3/3c.jpg)<br><br>
![IMG-7](./.Output/Signup-3/3d.jpg)<br><br>
![IMG-8](./.Output/Login-NA-4/4a.jpg)<br><br>
![IMG-9](./.Output/Login-NA-4/4b.jpg)<br><br>
![IMG-10](./.Output/Login-NA-4/4c.jpg)<br><br>
![IMG-11](./.Output/Login-NA-4/4d.jpg)<br><br>
![IMG-12](./.Output/Login-A-5/5a.jpg)<br><br>
![IMG-13](./.Output/Login-A-5/5b.jpg)<br><br>
![IMG-14](./.Output/Login-A-5/Game-Database/5bi.jpg)<br><br>
![IMG-15](./.Output/Login-A-5/Game-Database/View-Record/5bii.jpg)<br><br>
![IMG-16](./.Output/Login-A-5/Game-Database/View-Record/5biii.jpg)<br><br>
![IMG-17](./.Output/Login-A-5/Game-Database/View-Record/5biv.jpg)<br><br>
![IMG-18](./.Output/Login-A-5/Game-Database/View-Record/5bv.jpg)<br><br>
![IMG-19](./.Output/Login-A-5/Game-Database/View-Record/5bvi.jpg)<br><br>
![IMG-20](./.Output/Login-A-5/Game-Database/View-Record/5bvii.jpg)<br><br>
![IMG-21](./.Output/Login-A-5/Game-Database/View-Record/5bviii.jpg)<br><br>
![IMG-22](./.Output/Login-A-5/Game-Database/View-Record/5bfail.jpg)<br><br>
![IMG-23](./.Output/Login-A-5/Game-Database/View-Record/5bfailOutput.jpg)<br><br>
![IMG-24](./.Output/Login-A-5/Game-Database/Reset-Data/5bx.jpg)<br><br>
![IMG-25](./.Output/Login-A-5/Game-Database/Reset-Data/5bxi.jpg)<br><br>
![IMG-26](./.Output/Login-A-5/Game-Database/5bxii.jpg)<br><br>
![IMG-27](./.Output/Login-A-5/User-Database/5b1.jpg)<br><br>
![IMG-28](./.Output/Login-A-5/User-Database/list-of-users/5b2.jpg)<br><br>
![IMG-29](./.Output/Login-A-5/User-Database/list-of-users/5b2a.jpg)<br><br>
![IMG-30](./.Output/Login-A-5/User-Database/list-of-users/5b2b.jpg)<br><br>
![IMG-31](./.Output/Login-A-5/User-Database/list-of-users/5b2c.jpg)<br><br>
![IMG-32](./.Output/Login-A-5/User-Database/Mod-user-rights/5b3.jpg)<br><br>
![IMG-33](./.Output/Login-A-5/User-Database/Mod-user-rights/5b3a.jpg)<br><br>
![IMG-34](./.Output/Login-A-5/User-Database/Mod-user-rights/5b3b.jpg)<br><br>
![IMG-35](./.Output/Login-A-5/User-Database/Mod-user-rights/5b3c.jpg)<br><br>
![IMG-36](./.Output/Login-A-5/User-Database/Delete-user/5b4.jpg)<br><br>
![IMG-37](./.Output/Login-A-5/User-Database/Delete-user/5b4a.jpg)<br><br>
![IMG-38](./.Output/Login-A-5/User-Database/Delete-user/5b4b.jpg)<br><br>
![IMG-39](./.Output/Login-A-5/User-Database/Delete-user/5b4c.jpg)<br><br>
![IMG-40](./.Output/Login-A-5/5c.jpg)<br><br>
![IMG-41](./.Output/Login-A-5/6.jpg)<br><br>
![IMG-42](./.Output/Main-menu-6/a-game/6a.jpg)<br><br>
![IMG-43](./.Output/Main-menu-6/a-game/6a1.jpg)<br><br>
![IMG-44](./.Output/Main-menu-6/a-game/6a2.jpg)<br><br>
![IMG-45](./.Output/Main-menu-6/a-game/6a2a.jpg)<br><br>
![IMG-46](./.Output/Main-menu-6/a-game/6a2b.jpg)<br><br>
![IMG-47](./.Output/Main-menu-6/a-game/6a2c.jpg)<br><br>
![IMG-48](./.Output/Main-menu-6/a-game/6a2d.jpg)<br><br>
![IMG-49](./.Output/Main-menu-6/a-game/6a2e.jpg)<br><br>
![IMG-50](./.Output/Main-menu-6/a-game/6a2f.jpg)<br><br>
![IMG-51](./.Output/Main-menu-6/a-game/6a2g.jpg)<br><br>
![IMG-52](./.Output/Main-menu-6/a-game/6a2h.jpg)<br><br>
![IMG-53](./.Output/Main-menu-6/a-game/6a2i.jpg)<br><br>
![IMG-54](./.Output/Main-menu-6/a-game/6a2j.jpg)<br><br>
![IMG-55](./.Output/Main-menu-6/b-periodic-table/6b.jpg)<br><br>
![IMG-56](./.Output/Main-menu-6/b-periodic-table/6b1.jpg)<br><br>
![IMG-57](./.Output/Main-menu-6/b-periodic-table/6b2.jpg)<br><br>
![IMG-58](./.Output/Main-menu-6/b-periodic-table/6b3.jpg)<br><br>
![IMG-59](./.Output/Main-menu-6/b-periodic-table/6b4.jpg)<br><br>
![IMG-60](./.Output/Main-menu-6/c-statistics/6c.jpg)<br><br>
![IMG-61](./.Output/Main-menu-6/c-statistics/6c1.jpg)<br><br>
![IMG-62](./.Output/Main-menu-6/d-settings/6d.jpg)<br><br>
![IMG-63](./.Output/Main-menu-6/d-settings/6da.jpg)<br><br>
![IMG-64](./.Output/Main-menu-6/d-settings/change-pass/6d1.jpg)<br><br>
![IMG-65](./.Output/Main-menu-6/d-settings/change-pass/6d1a.jpg)<br><br>
![IMG-66](./.Output/Main-menu-6/d-settings/change-pass/6d1b.jpg)<br><br>
![IMG-67](./.Output/Main-menu-6/d-settings/clear-stats/6d2.jpg)<br><br>
![IMG-68](./.Output/Main-menu-6/d-settings/clear-stats/6d2a.jpg)<br><br>
![IMG-69](./.Output/Main-menu-6/d-settings/clear-stats/6d2b.jpg)<br><br>
![IMG-70](./.Output/Main-menu-6/d-settings/clear-stats/6d2c.jpg)<br><br>
![IMG-71](./.Output/Main-menu-6/d-settings/del-acc/6d3.jpg)<br><br>
![IMG-72](./.Output/Main-menu-6/d-settings/del-acc/6d3a.jpg)<br><br>
![IMG-73](./.Output/Main-menu-6/d-settings/del-acc/6d3b.jpg)<br><br>
![IMG-74](./.Output/Main-menu-6/d-settings/del-acc/6d3c.jpg)<br><br>
![IMG-75](./.Output/Main-menu-6/e-logout/6e1.jpg)<br><br>
![IMG-76](./.Output/Main-menu-6/e-logout/6e1a.jpg)<br><br>
![IMG-77](./.Output/Main-menu-6/f-exit/6f1.jpg)<br><br>
![IMG-78](./.Output/Main-menu-6/f-exit/6f1a.jpg)<br>

## Bibliography
- http://www.science.co.il/elements/.
- [Grapher Software] ( https://www.desmos.com/calculator ) .
- Class 11 NCERT Chemistry.<br>

[![Developers Tag]( https://img.shields.io/badge/Developer-shashank3199-red.svg ) ]( https://github.com/shashank3199 )
