/* 	PROJECT NAME 	-- MONOPOLY
	CLASS		-- XII-SCI
*/
#include <iostream.h>
#include<fstream.h>
#include <iomanip.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<iomanip.h>
//--------------------------------------------
void screen_setting();
void get_card(int data);
void modify_card(int buyer);

char strcost[10],strrent[10];
long pos1;
int pos;
//---------------------------------------------

class card
	{
	int no;
	char name[20],color;
	int cost,rent;
	int own;
	public:
	void show()
	{
			   setcolor(BLACK);
			     outtextxy(300,150,"NAME");
			   outtextxy(335,150,name);


			   outtextxy(300,170,"COST");
			   itoa(cost,strcost,10);
			   outtextxy(335,170,strcost);

			   outtextxy(300,190,"RENT ");
			   itoa(rent,strrent,10);
			   outtextxy(335,190,strrent);



	   }


	   int get_cost()
	   { return cost;
	   }
	   int get_rent()
	   { return rent;
	   }

	   int get_own()
	   {
	   return own;
	   }

	   int get_no()
	   {
	   return no;
	   }

	   void modify_own(int o)
	   {  own=o;
	   }

   }c1,C;

class player
	{
	int p_no;
	int pos;
	int current_dice, current_amount,count;
	public:
	char P;
	player()    //---INITIALIZING MONEY, CURRENT POSITION OF PLAYERS-------------
		{
			if(count==1)
			P='p1' ;
			else
			P='p2';
			current_amount=5000;
			pos=0;
			current_dice=0;
			count++;
		}

	void set_pno(int pno)
	{
	p_no=pno;
	}

	int ret_curamt()//-----RETURNING THE CURRENT AMOUNT---
		{ return current_amount; }

	void to_play(int dice)  //---FOR MOVEMENT-----------
		{
			char ch;
			pos=dice+current_dice;
			if( pos>17)
			{
			current_amount=current_amount+1000;
			pos= pos%17;
			}
			current_dice= pos;

			get_card(pos);
			 C.show();
		 if(C.get_own()!=-1)
		 {

		 if(C.get_own()==0)
			{
				outtextxy(150,220,"WOULD YOU LIKE TO BUY THIS PLACE?(PRESS B)");
				cin>>ch;
			if(ch=='b'||ch=='B')
			{
				if(current_amount<C.get_cost())
				{
				outtextxy(200,225,"SORRY YOU CANNOT BUY THIS PLACE");
				outtextxy(200,235,"YOUR BALANCE IS TOO LOW");
				}
				else
				{
				current_amount=current_amount-C.get_cost();
				C.modify_own(p_no);
				modify_card(p_no);

				outtextxy(200,225,"CONGRATULATIONS!!!");
				outtextxy(200,235,"YOU HAVE BOUGHT IT");
				}
			}
			}

		else
			if(C.get_own()!=p_no)
			{	outtextxy(220,226,"!!OOPS.....YOU HAVE TO PAY THE RENT");
				current_amount=current_amount-C.get_rent();
			}

	}
	}

	int ret_pos() //----------RETURNING THE POSITON OF THE PLAYER-----
	{ return pos;
	}

	void buy(card c2)
	{
	  current_amount=current_amount- c2.get_cost();
	}
	void reduce_balance( int amt)
	{ current_amount=current_amount-amt;
	}
	void increase_balance(int amt)
	{ current_amount=current_amount-amt;
	}

	void take_rent(card c3)
	{
	 current_amount=current_amount- c3.get_rent();
	}


} p1,p2;

void modify_card(int buyer)
{ 	fstream fio ;
	fio.open("Monopoly.dat",ios::in|ios::out|ios::binary);
	C.modify_own(buyer);
	fio.seekg(pos1-sizeof(C));
	fio.write((char*)&C,sizeof(C));
       fio.close();
}


void get_card(int data)
    {

	fstream fio ;
	fio.open("Monopoly.dat",ios::in|ios::out|ios::binary);


	while(!fio.eof())
	{
		fio.read((char*)&C,sizeof(C));

		if(C.get_no()==data)
		{  pos1=fio.tellg();
		   break;
		}

	}
	fio.close();

    }


//---------------------------------------------
int welcome_screen();
//---------------------------------------------
void movement(int d, player &p3,int p_no);
//---------------------------------------------
void tinyset();
//---------------------------------------------
void chance(player &p5);
//---------------------------------------------
void community_chest(player &p6);
//---------------------------------------------
void coinp1(int x1);
//---------------------------------------------
void coinp2(int x2);
//---------------------------------------------

//---------------------------------------------

 void main()
{
	randomize();
  //--------------------------------------------------------------
     int choice=0;
     do
     {
     choice=welcome_screen() ;
     }while(choice==0);

   /* request auto detection */
  int gdriver = DETECT, gmode;

   /* initialize graphics and local variables */
  initgraph(&gdriver, &gmode, "");

  //---------------------------------------------------------------


  //---INITIALIZING MONEY, CURRENT POSITION OF PLAYERS-------------

  //---------------------------------------------------------------
   int d;       // VARIABLES FOR for LOOP
   char ch,chk;    // variables for FOR loop
   char strdice[10],strbalance[10];
   int balance,position;

   screen_setting(); /* function for setting the screen for the game*/
  //----------------------------------------------------------------


   for(int i=0; ;i++ )
  {
   if(i==0)
	{
	setfillstyle(SOLID_FILL,LIGHTRED)    ;
	 bar(100,400,500,100);
	outtextxy(190,230,"!!!!!!!GO GET STARTED!!!!!!!! ");
	outtextxy(190,250,"PLS WAIT...PRESS ENTER ") ;
	getch();;
	}
  //******************SETTING BOARD***********************
   textcolor(BLACK);

  cleardevice();
  screen_setting();


 //*******************FOR PLAYER 1*************************
   if(i!=0)
   coinp2(position);

  setfillstyle(SOLID_FILL,LIGHTGREEN);
  setcolor(BLACK);
   bar(100,400,500,100);
  d= (rand()%6+1);// GENERATING DICE NO.
  circle(300,135,12)  ;
  circle(300,135,10) ;
  itoa(d,strdice,10);
  outtextxy(299,130,strdice);  	//SETTING THE DICE NO ON SCREEN

   outtextxy(238,110," PLAYER 1'S TURN") ;
   outtextxy(238,130," DICE:") ;

   p1.to_play( d)  ;
   position= p1.ret_pos();
   movement(position, p1,1);

   balance = p1.ret_curamt();


   p1.set_pno(1);

   itoa(balance,strbalance,10);
   outtextxy(220,330,"YOUR BALANCE IS : " );
   outtextxy(350,330,strbalance);





   outtextxy(110,370,"HAND OVER THE SYSTEM TO THE NEXT PLAYER " );

   getch();
 //***************END OF PLAYER 1***************************



 //****************PLAYER 2*********************************
  setcolor(WHITE);
  clrscr();
  screen_setting();

  coinp1(position);
  position= p2.ret_pos();

  setcolor(BLACK);

  setfillstyle(SOLID_FILL,YELLOW);
  p2.set_pno(2);
  bar(100,400,500,100);
  setcolor(BLACK);

  outtextxy(238,110," PLAYER 2'S TURN") ;



	d= (rand()%6+1);// GENERATING DICE NO.
	balance = p2.ret_curamt();

  setcolor(BLACK);
  outtextxy(238,130," DICE:") ;
  circle(300,135,12)  ;
  circle(300,135,10) ;
  itoa(d,strdice,10);
  outtextxy(299,130,strdice);          //SETTING THE DICE NO ON SCREEN
  itoa(balance,strbalance,10);
  outtextxy(220,330,"YOUR BALANCE IS : " );
  outtextxy(350,330,strbalance);
    p2.to_play( d)  ;
  movement(p2.ret_pos(), p2,2);

  setcolor(BLACK);


  outtextxy(110,370,"HAND OVER THE SYSTEM TO THE NEXT PLAYER " );


 //**********************END OF LOOP**********************



  cin>>chk;
  cout<<"\n\n\n\n\n\n\n\n\n\t\t\t";
  setcolor(WHITE);
  screen_setting();

  if(chk=='x' || chk=='X')
  break;
  //********SETTING OF SCREEN IF FOR LOOP CONTINUES********
  tinyset();
  }

 //*****************DECLARATION OF WINNER****************************
  clrscr();

  screen_setting();
  //*********DECLARATION OF WINNER**************
  setfillstyle(SOLID_FILL,LIGHTGREEN);
  bar(100,400,500,100);

  if(p1.ret_curamt()>p2.ret_curamt())
  outtextxy(250,250,"PLAYER 1 IS THE WINNER");

  if(p1.ret_curamt()<p2.ret_curamt())
  outtextxy(250,250,"PLAYER 2 IS THE WINNER");

  if(p1.ret_curamt()==p2.ret_curamt())
  outtextxy(150,250,"It is a tie !!Congratulations to both!!!");

  getch();

  closegraph();

  }


void tinyset()
{
 setfillstyle(SOLID_FILL, BLACK);
 bar (500,600,100,100);
 return;
}



    //****************MOVEMENT OF PLAYER 1********************************
void movement(int d, player &p3,int p_no)
  {  static count=0;
  count++;
   char ch;
   switch(d)
		{
		case 0 :if(count!=1)

			break;
			//-----



		case 1:
			outtextxy(300,210,"LET US SEE WHAT IS IN STORED");
			outtextxy(300,230,"IN YOUR FURTURE ");
			chance(p3);
			if(p_no==1)
			outtextxy(30,340,"##");
			if(p_no==2)
			outtextxy(30,350,"$$");
			break;
			//-------

		case 2: if(p_no==1)
			outtextxy(20,240,"##");
			if(p_no==2)
			outtextxy(10,230,"$$");

			break;





		case 3: if(p_no==1)
			outtextxy(25,140,"##");
			if(p_no==2)
			outtextxy(15,130 ,"$$");

			break;




		case 4: outtextxy(300,150,"JAIL ;o ");
			if(p_no==1)  //JAIL
			outtextxy(25,38,"##");
			if(p_no==2)
			outtextxy(15,28,"$$");

			break;

			//------


		case 5: if(p_no==1) //Paris
			outtextxy(115,38,"##");
			if(p_no==2)
			outtextxy(105,28 ,"$$");

			break;



		case 6: if(p_no==1)
			outtextxy(205,38,"##");
			if(p_no==2)
			outtextxy(200,28,"$$");
			break;




		case 7:
			outtextxy(300,210,"LET US SEE WHETHER UR LUCK");
			outtextxy(300,230,"FAVOURS YOU OR NOT ");
			community_chest(p3) ;

			if(p_no==1)
			outtextxy(305,38,"##");
			if(p_no==2)
			outtextxy(300,28,"$$");

			break;

		case 8: if(p_no==1)
			outtextxy(405,38,"##");
			if(p_no==2)
			outtextxy(400,28,"$$");
			break;



		case 9:
			outtextxy(250,210,"RELAX AND CHILLOUT IN MONOPOLY");
			outtextxy(250,230,"RESTOOM ... FREE ACCOMODATION ");

			if(p_no==1)
			outtextxy(505,38,"##");
			if(p_no==2)
			outtextxy(500,28,"$$");
			break;

		case 10:if(p_no==1)
			outtextxy(505,140,"##");
			if(p_no==2)
			outtextxy(500,130,"$$");
			break;



		case 11: if(p_no==1)
			 outtextxy(505,240,"##");
			 if(p_no==2)
			 outtextxy(500,230,"$$");
			 break;




		case 12:if(p_no==1)
			outtextxy(505,340,"##");
			if(p_no==2)
			outtextxy(500,330,"$$");
			break;



		case 13:
			outtextxy(300,210,"LET US SEE WHAT IS IN STORED");
			outtextxy(300,220,"IN YOUR FURTURE ");
			chance(p3);

			if(p_no==1)
			outtextxy(500,440,"##");
			if(p_no==2)
			outtextxy(500,430,"$$");

			break;

		case 14:if(p_no==1)
			outtextxy(405,440,"##");
			if(p_no==2)
			outtextxy(400,430,"$$");

			break;


		case 15:if(p_no==1)
			outtextxy(305,440,"##");
			if(p_no==2)
			outtextxy(300,430,"$$");
			break;




		case 16:
			outtextxy(300,210,"LET US SEE WHETHER UR LUCK");
			outtextxy(300,230,"FAVOURS YOU OR NOT ");
			community_chest(p3) ;
			if(p_no==1)
			outtextxy(205,440,"##");
			if(p_no==2)
			outtextxy(200,430,"$$");

			break;

		case 17:if(p_no==1)
			outtextxy(105,440,"##");
			if(p_no==2)
			outtextxy(100,430,"$$");
			break;

      }
      }




 //***************** function for setting the screen*********************




 void screen_setting()
{

 setfillstyle(3,11);
 bar(0,600,100,400);
 moveto(0,450);
 outtext("    GO ");
 setfillstyle(SOLID_FILL,3);
 circle(0,60,5);
		  //1st go

 setfillstyle(SOLID_FILL,BLUE);
 bar(200, 600,100, 400);
 moveto(100,450);
 outtext("  17-PORT ");
	  //2nd port

 setfillstyle(WIDE_DOT_FILL,BROWN);      //3   community chest
 bar(300,600,200,400);
 moveto(200,450);
 outtext("16-COMMUNITY ");
 moveto(200,460);
 outtext("    CHEST ");


 setfillstyle(SOLID_FILL,BROWN);
 bar(300, 600,400, 400);
 moveto(300,450);
 outtext("  15-ZURICH ");	  // 4nd barcelona

 setfillstyle(SOLID_FILL,GREEN);      // 5 dublin
 bar(400,600,500,400);
 moveto(400,450);
 outtext(" 14-DUBLIN");

 setfillstyle(WIDE_DOT_FILL,BROWN);     // 6 chance
 bar(500,600,600,400);
 moveto(500,450);
 outtext(" 13-CHANCE ");

 setfillstyle(SOLID_FILL,BLUE);     //7up railway
 bar(500,400,600,300);
 moveto(500,350);
 outtext(" 12-RAILWAY ");

 setfillstyle(SOLID_FILL,RED);     //8up london
 bar(500,200,600,300);
 moveto(500,250);
 outtext(" 11-LONDON ");

 setfillstyle(SOLID_FILL,BROWN);     //9up milan
 bar(500,100,600,200);
 moveto(500,150);
 outtext(" 10-MILAN ");

 setfillstyle(HATCH_FILL,4);     // 10 up restroom
 bar(500,0,600,100);
 moveto(500,48);
 outtext(" 9-RESTROOM ");

 setfillstyle(SOLID_FILL,BLUE);     // 11up airport
 bar(400,0,500,100);
 moveto(400,48);
 outtext(" 8-AIRPORT ");

 setfillstyle(WIDE_DOT_FILL,5);     // 12 community chest
 bar(300,0,400,100);
 moveto(300,48);
 outtext(" 7-COMMUNITY ");
 moveto(350,55) ;
 outtext("CHEST");

 setfillstyle(SOLID_FILL,MAGENTA);     // 13 rome
 bar(300,0,200,100);
 moveto(200,48);
 outtext(" 6-ROME ");

 setfillstyle(SOLID_FILL,2);      // 14 Paris
  bar(200,0,100,100);
   moveto(110,48);
  outtext(" 5-PARIS ");

  setfillstyle( HATCH_FILL,LIGHTCYAN);     // 15 JAIL
  bar(0,0,100,100);
  moveto(20, 48);
  outtext("4-JAIL ");

  setfillstyle(SOLID_FILL,4);     // 16 up NEW YORK
  bar(0,100,100,200);
   moveto(20, 150);
  outtext("3-NEW YORK");

  setfillstyle(SOLID_FILL,MAGENTA);     // 17 up singapore
  bar(0,200,100,300);
   moveto(15, 250);
  outtext("2-SINGAPORE");

  setfillstyle( WIDE_DOT_FILL,5);     // 18 up chance
  bar(0,400,100,300);
   moveto(25, 350);
  outtext("1-CHANCE");
  return ;
 }

    int welcome_screen()
{
	int enter;


   /* request auto detection */
  int gdriver = DETECT, gmode;

   /* initialize graphics and local variables */
  initgraph(&gdriver, &gmode, "");
   setbkcolor(RED);

     settextjustify(CENTER_TEXT, CENTER_TEXT);
     settextstyle(GOTHIC_FONT, HORIZ_DIR,8);
     textcolor(1);
     moveto(300,100);
     outtext("WELCOME");
     settextstyle(GOTHIC_FONT, HORIZ_DIR,6);
     moveto(300,200);
     outtext("TO THE GAME OF");
     settextstyle(GOTHIC_FONT, HORIZ_DIR,9);
     moveto(300,300);
     outtext("MONOPOLY");

      getch();
      clrscr();
      closegraph();


   /* request auto detection */


   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "");
   setbkcolor(GREEN);

    settextjustify(CENTER_TEXT, CENTER_TEXT);
     settextstyle(GOTHIC_FONT, HORIZ_DIR,8);
     textcolor(8);
     moveto(300,100);
     outtext("MENU");
     settextstyle( SANS_SERIF_FONT, HORIZ_DIR,6);
     moveto(300,200);
     outtext("1  HOW TO PLAY");
     settextstyle( SANS_SERIF_FONT, HORIZ_DIR,6);
     moveto(300,300);
     outtext(" 2  START PLAYING");
      cin>> enter;
      if(enter==1)
      {
	closegraph();
	clrscr();
	initgraph(&gdriver, &gmode, "");
	setbkcolor(BROWN);
	 settextstyle( SANS_SERIF_FONT, HORIZ_DIR,1);
	outtextxy(5,70,"ENJOY MONOPOLY WORLD!!!!!");
	outtextxy(5,100,"MONOPOLY GAME is specially designed for people who");
	outtextxy(5,150,"are interested in trading, business and intrested ");
	outtextxy(5,200,"in visiting various countries");
	outtextxy(5,250,"HOW TO PLAY???");
	outtextxy(5,300,"Just press 'b' to buy any country and 'c' to continue ");
	outtextxy(5,350,"Press 'o' for okay and the ENTER after your turn");
	outtextxy(5,400,"To exit press 'x' twice");
	outtextxy(5,450,"HUMBLE REQUEST : DON'T PRESS ENTER UNNECESSARILY ");


	getch();
	return 1;
     }

     if(enter==2)
     return 2;


     return 0;
     }

     //*****************COMMUNITY CHEST*******************//

     void community_chest( player &p6)
     {
     randomize() ;
     int cc;
     cc=(rand()%7)+1   ;
     switch(cc)
     {
     case 1 : outtextxy(200,250,"BANK ERROR IN YOUR FAVOUR-");
	      outtextxy(200,270,"COLLECT RS 900 ");
	      p6.increase_balance(900);

		getch();
		break;

     case 2 : outtextxy(200,250,"DOCTOR'S FELL PAY RS 400");
	      p6.reduce_balance(400);
	       getch();
		break;

     case 3 : outtextxy(200,250,"YOUR BIRTHDAY COLLECT ");
	      outtextxy(200,270,"RS 500 FROM THE BANK ");
		p6.increase_balance(500);
	       getch();


	      break;

     case 4 : outtextxy(200,250,"INCOME TAX REFUND OF RS 900 ");
		p6.increase_balance(900);
	       getch();
		 break;

     case 5 : outtextxy(200,250,"YOUR LATE GREAT GRAND FATHER ");
	      outtextxy(200,270,"LEFT A WILL FOR YOU... ");
	      outtextxy(200,300,"YOU INHERIT RS 20 ");
		  p6.increase_balance(200);
	       getch();
	       break;

     case 6 : outtextxy(200,250,"YOU HAVE WON A BEAUTY CONTEST  ");
	      outtextxy(200,270,"COLLECT RS 1000 ");
	     p6.increase_balance(1000);
	       getch();
		break;

     case 7 : outtextxy(200,250,"YOUR COMPANY HAD A HUGE TURNOVER ");
	       outtextxy(200,270,"  COLLECT BONUS OF RS 1000 ");
	      p6.increase_balance(1000);
	       getch();
	       break;


	  ;

   }
}




     //********************* CHANCE**********************************
     void chance( player &p5)
     {
     randomize() ;
     int r;
     r=(rand()%7)+1    ;
     switch(r)
     {
     case 1 : outtextxy(200,250,"YOU GOT MAD,  MENTAL HOSPITAL  ");
	      outtextxy(200,270,"BILL OF RS 1000 ");
	       p5.reduce_balance(1000);
	      getch();	      break;

     case 2 : outtextxy(200,250,"YOU LOST A BET OF RS 400");
	      p5.reduce_balance(400);
		 getch();
	      break;

     case 3 : outtextxy(200,250,"PAY YOUR TELEPHONE BILL OF RS 300 ");
	      p5.reduce_balance(300);
		 getch();
		 break;

     case 4 : outtextxy(200,250,"INCOME TAX RAID PAY RS 900 ");
	       p5.reduce_balance(900);

		 getch();break;

     case 5 : outtextxy(200,250,"MAKE GENERAL REAIRS ON ");
	       outtextxy(200,270," YOUR PROPERTIES");
	      p5.reduce_balance(1000);
		 getch();
		 break;

     case 6 : outtextxy(200,250,"YOU HAVE WON A CROSSWORD COMPETION");
	      outtextxy(200,270,"COLLECT RS 500 ");
		p5.increase_balance(500);
	      getch();
		 break;

     case 7 : outtextxy(200,250,"PAY POOR TAXES RS 200 ");
		p5.reduce_balance(200);
	      getch();
		 break;


   }
}


void coinp1(int x1)
{
 setcolor(WHITE);
	switch(x1)
	{
		case 1 : moveto(20, 10);
			outtext("##");
			 setcolor(BLACK);
			break;

		case 2:moveto(30, 340);
			outtext("##");
			 setcolor(BLACK);
			break;

		case 3 : moveto(25, 140);
		       outtext("##");
			setcolor(BLACK);
		       break;

		case 4 : moveto(25, 38);
		       outtext("##");
			setcolor(BLACK);
			break;


		case 5: moveto(115, 38);
			outtext("##");
			 setcolor(BLACK);
			break;

		case 6: moveto(205, 38);
			 outtext("##");
			 setcolor(BLACK);
			break;
		case 7: moveto(305,38);
			outtext("##");
			 setcolor(BLACK);
			break;

		case 8: moveto(405,38);
			outtext("##");
			 setcolor(BLACK);
			break;

		case 9: moveto(505,38);
		       outtext("##");
			setcolor(BLACK);
		       break;

		case 10:moveto(505,140);
			outtext("##");
			  setcolor(BLACK);
			 break;

		case 11:moveto(505,240);
			outtext("##");
			  setcolor(BLACK);
			 break;

		case 12:moveto(505,340);
			outtext("##");
			  setcolor(BLACK);
			 break;

		case 13:
			moveto(500, 430);
			outtext("##");
			  setcolor(BLACK);
			 break;

		case 14:moveto(405,440);
			outtext("##");
			  setcolor(BLACK);
			 break;

		case 15:
			moveto(300, 430);
			outtext("##");
			  setcolor(BLACK);
			 break;

		case 16:moveto(205,440);
			outtext("##");
			  setcolor(BLACK);
			 break;

		case 17:moveto(105,440);
			outtext("##");
			  setcolor(BLACK);
			 break;




		}
		return;


	}

void coinp2(int x2)
{
       setcolor(WHITE);
	switch(x2)
	{
		case 1 : moveto(20, 10);
			outtext("$$");
			 setcolor(BLACK);
			break;

		case 2:moveto(30, 340);
			outtext("$$");
			 setcolor(BLACK);
			break;

		case 3 : moveto(25, 140);
		       outtext("$$");
			setcolor(BLACK);
		       break;

		case 4 : moveto(25, 38);
		       outtext("$$");
			 setcolor(BLACK);
			break;

		case 5 :moveto(105, 28);
			outtext("$$");
			 setcolor(BLACK);
			break;

		case 6 :moveto(200, 28);
			outtext("$$");
			 setcolor(BLACK);
			break;
		case 7: moveto(305,38);
			outtext("$$");
			 setcolor(BLACK);
			break;

	      case 8: moveto(405,38);
			outtext("$$");
			 setcolor(BLACK);
			break;

		case 9: moveto(505,38);
		       outtext("$$");
			setcolor(BLACK);
		       break;

		case 10:moveto(505,140);
			outtext("$$");
			  setcolor(BLACK);
			 break;

		case 11:moveto(505,240);
			outtext("$$");
			  setcolor(BLACK);
			 break;

		case 12:moveto(505,340);
			outtext("$$");
			  setcolor(BLACK);
			 break;

		case 13:
			moveto(500, 430);
			outtext("$$");
			  setcolor(BLACK);
			 break;

	      case 14:moveto(405,440);
			outtext("$$");
			  setcolor(BLACK);
			 break;

	      case 15:
			moveto(300, 430);
			outtext("$$");
			  setcolor(BLACK);
			 break;

	      case 16:moveto(205,440);
			outtext("$$");
			  setcolor(BLACK);
			 break;

		case 17:moveto(105,440);
			outtext("$$");
			  setcolor(BLACK);
			 break;





  }
		return;

		}

 //---------------------------------------------------------------------

