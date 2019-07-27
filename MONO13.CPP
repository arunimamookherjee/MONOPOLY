/* 	PROJECT NAME 	-- MONOPOLY
	CREATORS 	-- ARUNIMA AND SANJANA
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

char strcost[10],strrent[10];
//---------------------------------------------

class card
	{
	int no;
	char name[20],color;
	int cost,rent;
	public:
	char own[2];


		void show()
	{

			   outtextxy(300,150,"NAME");
			   outtextxy(335,150,name);


			   outtextxy(300,170,"COST");
			   itoa(cost,strcost,10);
			   outtextxy(335,170,strcost);

			   outtextxy(300,190,"RENT ");
			   itoa(rent,strrent,10);
			   outtextxy(335,190,strrent);



	   }

	   void getdata(int num,char nam[],int col,int price,int Rent)
		{
		no=num;
		strcpy(name,nam);
		color=col;
		strcpy(own," ");
		cost=price;
		rent=Rent;
		}


	   int get_cost()
	   { return cost;
	   }
	   int get_rent()
	   { return rent;
	   }

   }c1,C;

class player
	{
	char name[20];
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
	void get_name(char nam[])
	{	strcpy(name,nam);
	}

	int ret_curamt()//-----RETURNING THE CURRENT AMOUNT---
		{ return current_amount; }

	void to_play(int dice)  //---FOR MOVEMENT-----------
		{
			pos=dice+current_dice;
			if( pos>17)
			{
			current_amount=current_amount+1000;
			 pos= pos%17;
			}
			current_dice= pos;
		}

	int ret_pos() //----------RETURNING THE POSITON OF THE PLAYER-----
	{ return pos;
	}

	void buy(card c2)
	{
	  current_amount=current_amount- c2.get_cost();  }

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


}p1,p2;
void get_card(int data)
    {

	int counter=0;
	fstream fio ;
	fio.open("Monopoly.dat",ios::in|ios::out|ios::binary);

	while(!fio.eof())
	{
		fio.read((char*)&C,sizeof(C));

		if(counter==data)
		{
		C.show();
		break;
		}

		counter++;


	       }
	fio.close();

    }


//---------------------------------------------
int welcome_screen();
//---------------------------------------------
void movement(int d, player &p3);
//---------------------------------------------
void tinyset();
//---------------------------------------------
void chance(player &p5);
//---------------------------------------------
void community_chest(player &p6);
//---------------------------------------------
void movement2(int,player&);
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
	outtextxy(190,250,"PLS WAIT...DO NOT PRESS ENTER ") ;
	delay(1000);
	}
  //******************SETTING BOARD***********************
   textcolor(BLACK);

  clrscr();
  screen_setting();


 //*******************FOR PLAYER 1*************************

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

   if(i!=0)
   coinp2(position);

   balance = p1.ret_curamt();
   position= p1.ret_pos();

   itoa(balance,strbalance,10);
   outtextxy(220,263,"YOUR BALANCE IS : " );
   outtextxy(350,263,strbalance);

   p1.to_play( d)  ;

   if(i==0)
   coinp2(0);


   movement(position, p1);


   outtextxy(110,305,"HAND OVER THE SYSTEM TO THE NEXT PLAYER " );

   delay(1000);
 //***************END OF PLAYER 1***************************



 //****************PLAYER 2*********************************
  setcolor(WHITE);
  clrscr();
  screen_setting();
  setcolor(BLACK);
  setfillstyle(SOLID_FILL,YELLOW);

  bar(100,400,500,100);
  outtextxy(238,110," PLAYER 2'S TURN") ;
  coinp1(position);

	d= (rand()%6+1);// GENERATING DICE NO.
	balance = p2.ret_curamt();
	position= p2.ret_pos();

  outtextxy(238,130," DICE:") ;
  circle(300,135,12)  ;
  circle(300,135,10) ;
  itoa(d,strdice,10);
  outtextxy(299,130,strdice);          //SETTING THE DICE NO ON SCREEN

  itoa(balance,strbalance,10);
  outtextxy(220,263,"YOUR BALANCE IS : " );
  outtextxy(350,263,strbalance);


  p2.to_play( d)  ;

  movement2(p2.ret_pos(), p2);

  outtextxy(110,310,"HAND OVER THE SYSTEM TO THE NEXT PLAYER " );


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
void movement(int d, player &p3)
  {  static count=0;
  count++;
   char ch;
   switch(d)
		{
		case 0 :if(count!=1)
			outtextxy(300,150,"!!!GO GET STARTED!!!!! ");
			break;
			//-----



		case 1: moveto(30, 340);
			outtext("##");
			outtextxy(200,150,"CHANCE! :'o ");
			chance(p3);
			break;
			//-------

		case 2:  moveto(20, 240);
			outtext("##");

			get_card(2);


			if(strcmp(c1.own," "))
			{
			outtextxy(200,225,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p3.ret_curamt()<c1.get_cost())
				  { 	outtextxy(200,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(200,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p3.buy(c1);
				     strcpy(c1.own,"p1");
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p2") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");




			break;




		case 3: moveto(25, 140);
		       outtext("##");
			get_card(3);



			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p3.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p3.buy(c1);
				     strcpy(c1.own,"p1");
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p2 ") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");




			break;




		case 4: moveto(25, 38);  //JAIL
			outtext("##");
			outtextxy(300,150,"JAIL ;o ");
			break;

			//------


		case 5: moveto(115, 38); //Paris
			outtext("##");

			get_card(5);



			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p3.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p3.buy(c1);
				     strcpy(c1.own,"p1");
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				}
			}


			else
			if(strcmp(c1.own,"p2" ))
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");


			break;



		case 6: moveto(205, 38);
			outtext("##");
			 get_card(6);


			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p3.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p3.buy(c1);
				     strcpy(c1.own,"p1");
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p2") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;




		case 7: moveto(305,38);
			outtext("##");

			outtextxy(300,150,"COMMUNITY CHEST ;o ");
			outtextxy(300,160,"LET US SEE WHETHER UR LUCK");
			outtextxy(300,170,"FAVOURS YOU OR NOT ");
			community_chest(p3) ;
			break;

		case 8: moveto(405,38);
			outtext("##");

			get_card(8);

			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p3.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p3.buy(c1);
				     strcpy(c1.own,"p1");
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p2" ))
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;



		case 9: moveto(505,38);
		       outtext("##");


			outtextxy(250,150,"RESTROOM ;o ");
			outtextxy(250,160,"RELAX AND CHILLOUT IN MONOPOLY");
			outtextxy(250,170,"RESTOOM ... FREE ACCOMODATION ");
			break;

		case 10:moveto(505,140);
			outtext("##");
			get_card(10);


			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p3.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p3.buy(c1);
				     strcpy(c1.own,"p1");
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p2") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");


			break;



		case 11:moveto(505,240);
			outtext("##");
			get_card(11);



			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p3.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p3.buy(c1);
				     strcpy(c1.own,"p1");
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p2" ))
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;




		case 12:moveto(505,340);
			outtext("##");

			get_card(12);


			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p3.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p3.buy(c1);
				     strcpy(c1.own,"p1");
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p2" ))
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;



		case 13:moveto(505,440);
			outtext("##");


			outtextxy(300,150,"CHANCE ;o ");

			chance(p3);
			break;

		case 14:moveto(405,440);
			outtext("##");
			get_card(14);

			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p3.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p3.buy(c1);
				     strcpy(c1.own,"p1");
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p2") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;




		case 15:moveto(305,440);
			outtext("##");
			get_card(15);


			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p3.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p3.buy(c1);
				     strcpy(c1.own,"p1");
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p2") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");


			break;




		case 16:moveto(205,440);
			outtext("##");


			outtextxy(300,150,"COMMUNITY CHEST ;o ");
			community_chest(p3) ;
			break;

		case 17:moveto(105,440);
			outtext("##");
			get_card(17);

			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p3.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p3.buy(c1);
				     strcpy(c1.own,"p1");				;
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p2") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;

      }
      }


//******** function of movement for player 2 *****************
 void movement2(int d,player&p4)
 {

  char ch;

   switch(d)
		{
		case 0 :outtextxy(300,150,"!!!GO GET STARTED!!!!! ");
			break;
			//-----


		case 1:	outtextxy(300,150,"CHANCE! :'o ");
			chance(p4);
			break;


		case 2:
			moveto(10, 230);
			outtext("$$");
			get_card(2);

				if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p4.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p4.buy(c1);
				     strcpy(c1.own,"p2");				;
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p1"))
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;



		case 3:
		       moveto(15, 130);
			outtext("$$");
			get_card(3);


				if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p4.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p4.buy(c1);
				     strcpy(c1.own,"p2");				;
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p1") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;




		case 4:
		       moveto(15, 28);
			outtext("$$");
			outtextxy(300,150,"JAIL ;o ");



			break;

			//------


		case 5:
			moveto(105, 28);
			outtext("$$");
			get_card(5);


				if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p4.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p4.buy(c1);
				     strcpy(c1.own,"p2");				;
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p1") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;


		case 6:
			moveto(200, 28);
			outtext("$$");
			get_card(6);


				if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p4.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p4.buy(c1);
				     strcpy(c1.own,"p2");				;
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p1") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;
		case 7:
			moveto(300, 28);
			outtext("$$");
			outtextxy(300,170,"COMMUNITY CHEST ;o ");

			community_chest(p4) ;
			break;

		case 8:
			moveto(400, 28);
			outtext("$$");
			get_card(8);
			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p4.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p4.buy(c1);
				     strcpy(c1.own,"p2");				;
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p1") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;

		case 9:

		       moveto(500, 28);
			outtext("$$");
			outtextxy(250,150,"RESTROOM ;o ");
			outtextxy(250,160,"RELAX AND CHILLOUT IN MONOPOLY");
			outtextxy(250,170,"RESTOOM ... FREE ACCOMODATION ");
			break;

		case 10:
			moveto(500, 130);
			outtext("$$");
			get_card(10);

				if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p4.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p4.buy(c1);
				     strcpy(c1.own,"p2");				;
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p1") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;


		case 11:moveto(500, 230);
			outtext("$$");
			get_card(11);



				if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p4.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p4.buy(c1);
				     strcpy(c1.own,"p2");				;
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p1"))
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;

		case 12:
			moveto(500, 330);
			outtext("$$");
			get_card(12);
			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p4.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p4.buy(c1);
				     strcpy(c1.own,"p2");				;
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p1"))
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;

		case 13:
			moveto(500, 430);
			outtext("$$");
			outtextxy(300,150,"CHANCE ;o ");
			chance(p4);
			break;

		case 14:
			moveto(400, 430);
			outtext("$$");
			get_card(14);

				if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p4.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p4.buy(c1);
				     strcpy(c1.own,"p2");				;
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p1"))
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;
		case 15:
			moveto(300, 430);
			outtext("$$");
			get_card(15);


			if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p4.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p4.buy(c1);
				     strcpy(c1.own,"p2");				;
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p1"))
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;
		case 16:
			moveto(200, 430);
			outtext("$$");

			outtextxy(300,150,"COMMUNITY CHEST ;o ");
			community_chest(p4) ;
			break;

		case 17:
			moveto(100, 430);
			outtext("$$");
			get_card(17);


				if(strcmp(c1.own," "))
			{
				outtextxy(220,226,"WOULD U LIKE 2 BUY DIS PLACE ?");
			cin>>ch;



				if(ch=='B'||ch=='b')
				{
				  if(p4.ret_curamt()<c1.get_cost())
				  { 	outtextxy(220,226,"SORRY YOU CANNOT BUY THIS PLACE");
					outtextxy(220,228,"YOUR BALANCE IS TOO LOW");
				  }
				 else
				   { p4.buy(c1);
				     strcpy(c1.own,"p2");				;
				     outtextxy(300,210,"CONGO U HAVE BOUGHT IT ");
				   }
				 }
			}


			else
			if(strcmp(c1.own,"p1") )
			outtextxy(220,226,"!!OOPS... YOU HAVE TO PAY RENT");

			break;
	}
		return;
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

      delay(3000);
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


	delay (500);
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
     cc=(rand()%7)+1    ;
     switch(cc)
     {
     case 1 : outtextxy(200,210,"BANK ERROR IN YOUR FAVOUR-");
	      outtextxy(200,230,"COLLECT RS 900 ");
	      p6.increase_balance(900);


	      break;

     case 2 : outtextxy(200,210,"DOCTOR'S FELL PAY RS 400");
	       p6.reduce_balance(400);
	      break;

     case 3 : outtextxy(200,210,"YOUR BIRTHDAY COLLECT ");
	      outtextxy(200,230,"RS 500 FROM THE BANK ");
		p6.increase_balance(500);


	      break;

     case 4 : outtextxy(200,230,"INCOME TAX REFUND OF RS 900 ");
		p6.increase_balance(900);
	       break;

     case 5 : outtextxy(200,210,"YOUR LATE GREAT GRAND FATHER ");
	      outtextxy(200,230,"LEFT A WILL FOR YOU... ");
	      outtextxy(200,250,"YOU INHERIT RS 20 ");
		  p6.increase_balance(200);
		      break;

     case 6 : outtextxy(200,210,"YOU HAVE WON A BEAUTY CONTEST  ");
	      outtextxy(200,230,"COLLECT RS 1000 ");
	     p6.increase_balance(1000);
	      break;

     case 7 : outtextxy(200,210,"YOUR COMPANY HAD A HUGE TURNOVER ");
	       outtextxy(200,230,"  COLLECT BONUS OF RS 1000 ");
	      p6.increase_balance(1000);
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
     case 1 : outtextxy(200,210,"YOU GOT MAD,  MENTAL HOSPITAL  ");
	      outtextxy(200,230,"BILL OF RS 1000 ");
	       p5.reduce_balance(1000);
	      break;

     case 2 : outtextxy(200,210,"YOU LOST A BET OF RS 400");
	      p5.reduce_balance(400);
	      break;

     case 3 : outtextxy(200,210,"PAY YOUR TELEPHONE BILL OF RS 3 ");
	      p5.reduce_balance(300);
	      break;

     case 4 : outtextxy(200,210,"INCOME TAX RAID PAY RS 900 ");
	       p5.reduce_balance(900);

	      break;

     case 5 : outtextxy(200,210,"MAKE GENERAL REAIRS ON ");
	       outtextxy(200,230," YOUR PROPERTIES");
	      p5.reduce_balance(1000);
	      break;

     case 6 : outtextxy(200,210,"YOU HAVE WON A CROSSWORD COMPETION");
	      outtextxy(200,230,"COLLECT RS 500 ");
		p5.increase_balance(500);
	      break;

     case 7 : outtextxy(200,220,"PAY POOR TAXES RS 200 ");
		p5.reduce_balance(200);
	      break;


   }
}


void coinp1(int x1)
{
	switch(x1)
	{
		case 1 : moveto(20, 10);
			outtext("##");
			break;

		case 2:moveto(30, 340);
			outtext("##");
			break;

		case 3 : moveto(25, 140);
		       outtext("##");
		       break;

		case 4 : moveto(25, 38);
		       outtext("##");
			break;


		case 5: moveto(115, 38);
			outtext("##");
			break;

		case 6: moveto(205, 38);
			 outtext("##");
			break;
	      case 7: moveto(305,38);
			outtext("##");
			break;

	      case 8: moveto(405,38);
			outtext("##");
			break;

		case 9: moveto(505,38);
		       outtext("##");
		       break;

		case 10:moveto(505,140);
			outtext("##");
			 break;

		case 11:moveto(505,240);
			outtext("##");
			 break;

		case 12:moveto(505,340);
			outtext("##");
			 break;

		case 13:
			moveto(500, 430);
			outtext("##");
			 break;

	      case 14:moveto(405,440);
			outtext("##");
			 break;

	      case 15:
			moveto(300, 430);
			outtext("##");

			 break;

	      case 16:moveto(205,440);
			outtext("##");
			 break;

		case 17:moveto(105,440);
			outtext("##");
			 break;




		}
		return;


		}


void coinp2(int x2)
{

	switch(x2)
	{
		case 1 : moveto(20, 10);
			outtext("$$");
			break;

		case 2:moveto(30, 340);
			outtext("$$");
			break;

		case 3 : moveto(25, 140);
		       outtext("$$");
		       break;

		case 4 : moveto(25, 38);
		       outtext("$$");
			break;

		case 5 :moveto(105, 28);
			outtext("$$");
			break;

		case 6 :moveto(200, 28);
			outtext("$$");
			break;
		case 7: moveto(305,38);
			outtext("$$");
			break;

	      case 8: moveto(405,38);
			outtext("$$");
			break;

		case 9: moveto(505,38);
		       outtext("$$");
		       break;

		case 10:moveto(505,140);
			outtext("$$");
			 break;

		case 11:moveto(505,240);
			outtext("$$");
			 break;

		case 12:moveto(505,340);
			outtext("$$");
			 break;

		case 13:
			moveto(500, 430);
			outtext("$$");
			 break;

	      case 14:moveto(405,440);
			outtext("$$");
			 break;

	      case 15:
			moveto(300, 430);
			outtext("$$");

			 break;

	      case 16:moveto(205,440);
			outtext("$$");
			 break;

		case 17:moveto(105,440);
			outtext("$$");
			 break;





  }
		return;

		}

 //---------------------------------------------------------------------

