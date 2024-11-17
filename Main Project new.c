#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Player
{
	int jerseyNo;
	char name[20];
	int matches;
	int runs;
	int wickets;
}Player;
void store(Player*);
void display(Player*);
int searchbyJersey(Player*);
int searchbyName(Player*);
void show(Player*,int);
void removePlayer(Player*);
int update(Player*);
int sort(Player*);
void hardcore();
int count=3;
int a=15;
void main()
{
	Player*player = (Player*)malloc(a*sizeof(Player));
	hardcore(player);
	int choice;
	do
	{
		printf("\n__________________<<< W-E-L-C-O-M-E >>>__________________\n\n1.To Store Data of Players Enter 1...\n2.To Display Data of Players Enter 2...\n3.To Search the Players By JerseyNo Enter 3...\n4.To Search the Player By Name Enter 4....\n5.To Remove the data of Player Enter 5...\n6.To Update the data of player Enter 6...\n7.Do you want see Players Stats Enter 7....\n8.For EXIT Enter 8...\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				store(player);
				break;
			}
			case 2:
			{
				if(count<1)
				{
					printf("Please store the data of players...\n");
				}
				display(player);
				break;
			}
			case 3:
				{
				int res=searchbyJersey(player);
					if(res==-1)
					{
						printf("The JerseyNo not found\n");
					}
					else
					{
						show(player,res);
					}		
				}
				break;
			case 4:
				{
					int res=searchbyName(player);
					if(res==-1)
					{
						printf("The Player Name not Found\n");
					}
					else
					{
						show(player,res);
					}
				}
				break;
			case 5:
				{
					removePlayer(player);
				}
				break;
			case 6:
				{
					update(player);
				}
				break;
			case 7:
				{
					sort(player);
				}
				break;
			case 8:{
				printf("__________THANK  YOU  FOR  VISIT________\n");
				break;
			}
			default:
				printf("Enter valid choice\n");
		}
	}while(choice!=8);
}
void store(Player*player)
{
	int n,i;
	printf("\nEnter the number to store player data: ");
	scanf("%d",&n);
	if(n>a)
	{
		printf("Insufficient size\nPlease Enter the size below 15...\n");
	}
	else
	{
	for(i=count;i<count+n;i++)
	{
		printf("\nEnter the JerseyNo of player %d: ",i+1);
		scanf("%d",&player[i].jerseyNo);
		fflush(stdin);
		printf("Enter the Name of player %d: ",i+1);
		gets(player[i].name);
		fflush(stdin);
		printf("Enter the matches played by player %d: ",i+1);
		scanf("%d",&player[i].matches);
		fflush(stdin);
		printf("Enter the total run score by player %d: ",i+1);
		scanf("%d",&player[i].runs);
		fflush(stdin);
		printf("Enter the total wickets take by player %d: ",i+1);
		scanf("%d",&player[i].wickets);
		fflush(stdin);
		printf("_______________Player  %d  details  stored  successfully_____________\n",i+1);
		printf("____________________________________________________________________\n");	
	}
	count = count+n;
}
}
void display(Player*player)
{
	int i;
	{
		printf("\n+-----------------------------------------------------------------------------------+");
		printf("\n|      Name        |  Jersey_No  |  Total Matches  |  Total Runs  |  Total Wickets  |");
		printf("\n+-----------------------------------------------------------------------------------+");
		for(i=0;i<count;i++)
		{
			printf("\n| %16s | %11d | %15d | %12d | %15d |",player[i].name,player[i].jerseyNo,player[i].matches,player[i].runs,player[i].wickets );
		}
		printf("\n+-----------------------------------------------------------------------------------+\n");
		printf("|----------------------Players Details Displays Successfully------------------------|\n");
	}
}
int searchbyJersey(Player*player)
{
	int jer;
	printf("Enter the JerseyNo of Player: ");
	scanf("%d",&jer);
	for(int i=0;i<count;i++)
	{
		if(player[i].jerseyNo==jer)
		{
			return i;
		}
	}
	return -1;
}
int searchbyName(Player*player)
{
	char nam[20];
	printf("Enter the Name of Player: ");
	fflush(stdin);
	gets(nam);
	for(int i=0;i<count;i++)
	{
		if(strcasecmp(player[i].name,nam)==0)
		{
			return i;
		}
	}
	return -1;
}	
void show(Player*player,int res)
{
	int i;
	printf("\n|--------------------------Your Searched Player is Here-----------------------------|");
	printf("\n+-----------------------------------------------------------------------------------+");
	printf("\n|      Name        |  Jersey_No  |  Total Matches  |  Total Runs  |  Total Wickets  |");
	printf("\n+-----------------------------------------------------------------------------------+");
	printf("\n| %16s | %11d | %15d | %12d | %15d |",player[i].name,player[i].jerseyNo,player[i].matches,player[i].runs,player[i].wickets );
	printf("\n+-----------------------------------------------------------------------------------+\n");
}
void removePlayer(Player*player)
{
	int k=searchbyJersey(player);
	if(k!=(-1)) 
	{
		int i;
		for(i=k;i<count-1;i++)
		{
			player[i]=player[i+1];
		}
	}
	else
	{
		printf("player not found\n");
	}
	printf("__________DELETE-SUCCESSFULLY_________\n");
	count--;	
}
int update(Player*player)
{
	int k = searchbyJersey(player);
	if(k!=(-1))
	{
		int match,run,wicket;
		printf("Add the Matches: ");
		scanf("%d",&match);
		player[k].matches=match+(player[k].matches);
		printf("Add the Runs: ");
		scanf("%d",&run);
		player[k].runs=run+(player[k].runs);
		printf("Add the wickets: ");
		scanf("%d",&wicket);
		player[k].wickets=wicket+(player[k].wickets);
		printf("___________PLAYERS-DETAILS-UPDATE-SUCCESSFULLY___________\n");
	}
	else
	{
		printf("Player Not Found");
	}	
}
int sort(Player* player)
{
	Player p[15];
	int choice;
	for(int i=0;i<count;i++)
	{
		p[i]=player[i];
	}
	printf("See Top 3 Batsman Enter 1...\nSee Top 3 Bowlers Enter 2...\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		int i;
		for(i=0;i<count;i++)
		{
			for(int j=i+1;j<count;j++)
			{
				if(p[j].runs>p[i].runs)
				{
					Player temp = p[i];
					p[i] = p[j];
					p[j] = temp;					
				}
			}
		}
		for(i=0;i<3;i++)
		{
			printf("\n|-------------------------------Rank  %d  Batsman------------------------------------|",i+1);
			printf("\n+-----------------------------------------------------------------------------------+");
			printf("\n|      Name        |  Jersey_No  |  Total Matches  |  Total Runs  |  Total Wickets  |");
			printf("\n+-----------------------------------------------------------------------------------+");
			printf("\n| %16s | %11d | %15d | %12d | %15d |",p[i].name,p[i].jerseyNo,p[i].matches,p[i].runs,p[i].wickets );
			printf("\n+-----------------------------------------------------------------------------------+\n");
		}
	}
	if(choice==2)
	{
		int i;
		for(i=0;i<count;i++)
		{
			for(int j=i+1;j<count;j++)
			{
				if(p[j].wickets>p[i].wickets)
				{
					Player temp = p[i];
					p[i] = p[j];
					p[j] = temp;
				}
			}
		}
		for(i=0;i<3;i++)
		{
			printf("\n|-------------------------------Rank  %d  Bowler-------------------------------------|",i+1);
			printf("\n+-----------------------------------------------------------------------------------+");
			printf("\n|      Name        |  Jersey_No  |  Total Matches  |  Total Runs  |  Total Wickets  |");
			printf("\n+-----------------------------------------------------------------------------------+");
			printf("\n| %16s | %11d | %15d | %12d | %15d |",p[i].name,p[i].jerseyNo,p[i].matches,p[i].runs,p[i].wickets );
			printf("\n+-----------------------------------------------------------------------------------+\n");
		}
	}	
}
void hardcore(Player*player)
{
	player[0].jerseyNo = 18;
	strcpy(player[0].name,"Virat Kohli");
	player[0].matches = 400;
	player[0].runs = 22100;
	player[0].wickets = 100;
	
	player[1].jerseyNo = 45;
	strcpy(player[1].name,"Rohit Sharma");
	player[1].matches = 350;
	player[1].runs = 20100;
	player[1].wickets = 150;
	
	player[2].jerseyNo = 07;
	strcpy(player[2].name,"MS Dhoni");
	player[2].matches = 500;
	player[2].runs = 16050;
	player[2].wickets = 50;
}