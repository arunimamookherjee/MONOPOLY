/* 	PROJECT NAME 	-- DATA FILE FOR MONOPOLY....(FOR CARDS)
	CREATORS 	-- ARUNIMA AND SANJANA
	CLASS		-- XII-SCI
*/

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>

class card
{
int no;
char name[20],color;

int cost,rent;

char own[2];
public:
	void initialise(int num,char nam[],int col,int price,int Rent)
	{
	no=num;
	strcpy(name,nam);
	color=col;
	strcpy(own," ");
	cost=price;
	rent=Rent;
	}
}c[20];

void main()
{

	ofstream fout("Monopoly1.dat",ios::out|ios::binary);

	if(!fout)
	{
		cout<<"\nSystem error....Try again later";
	};

	c[0].initialise(1,"GO",'0',0,0);
	fout.write((char*)&c[0],sizeof(c[0]));

	c[1].initialise(2,"CHANCE",'0',0,0);
	fout.write((char*)&c[1],sizeof(c[1]));

	c[2].initialise(3,"SINGAPORE",'P',1000,3000);
	fout.write((char*)&c[2],sizeof(c[2]));

	c[3].initialise(4,"NEW YORK",'R',1000,300);
	fout.write((char*)&c[3],sizeof(c[3]));

	c[4].initialise(5,"JAIL",'0',0,0);
	fout.write((char*)&c[4],sizeof(c[4]));

	c[5].initialise(6,"PARIS",'G',1000,200);
	fout.write((char*)&c[5],sizeof(c[5]));

	c[6].initialise(7,"ROME",'P',1000,300);
	fout.write((char*)&c[6],sizeof(c[6]));

	c[7].initialise(8,"COMMUNITY CHEST",'0',0,0);
	fout.write((char*)&c[7],sizeof(c[7]));

	c[8].initialise(9,"AIRPORT",'B',800,800);
	fout.write((char*)&c[8],sizeof(c[8]));

	c[9].initialise(10,"RESTROOM",'0',0,0);
	fout.write((char*)&c[9],sizeof(c[9]));

	c[10].initialise(11,"MILAN",'O',900,200);
	fout.write((char*)&c[10],sizeof(c[10]));

	c[11].initialise(12,"LONDON",'R',900,200);
	fout.write((char*)&c[11],sizeof(c[11]));

	c[12].initialise(13,"RAILWAY",'B',800,800);
	fout.write((char*)&c[12],sizeof(c[12]));

	c[13].initialise(14,"CHANCE",'0',0,0);
	fout.write((char*)&c[13],sizeof(c[13]));

	c[14].initialise(15,"DUBLIN",'G',1000,300);
	fout.write((char*)&c[14],sizeof(c[14]));

	c[15].initialise(16,"ZURICH",'O',1000,300);
	fout.write((char*)&c[15],sizeof(c[15]));

	c[16].initialise(17,"COMMUNITY CHEST",'0',0,0);
	fout.write((char*)&c[16],sizeof(c[16]));

	c[17].initialise(18,"PORT",'B',800,800);
	fout.write((char*)&c[17],sizeof(c[17]));


	fout.close();

  }
