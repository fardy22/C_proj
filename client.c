#ifndef CLIENT_H_
#define CLIENT_H_

#include"header.h"


void Client(struct Bank_acc *users)
{
	char choosen;
	int trans;
	char new_pass[9];
	int cash;
	int add;

	char E_C_ID[11];
	char E_C_Pass[9];
	
	printf("Enter your Bank account ID \n");
	fgets(E_C_ID,11,stdin);
	fflush(stdin);
	for(int i=0;i<20;i++)
	{
	
		if(strcmp(E_C_ID,users[i].id.ID)==0 )
		{
			printf("Enter your Bank account password \n");
			fgets(E_C_Pass,9,stdin);
			fflush(stdin);
			
			if(strcmp(E_C_Pass,users[i].id.pass)==0)
			{
				
				printf("choose\n 0:to make a transaction \n 1:to change account password \n 2:to get cash \n 3:to deposit in account \n 4:to return to man menu \n");
				scanf("%c",&choosen);
				fflush(stdin);
				switch(choosen)
				{
					case '0':
						printf("your balance is %d\n",users[i].id.balance);
						printf("Enter amount of money you would transfer \n");
						scanf("%d",&trans);
						fflush(stdin);	 
						if(trans <= users[i].id.balance && users[i].st==active)
						{
							make_trans(trans,users);
							users[i].id.balance=users[i].id.balance-trans;
							printf("balance now of %s is %d\n",users[i].name,users[i].id.balance);
						}
						
						break;
					
					
					case '1':
						printf("Enter the new password\n");
						fgets(new_pass,9,stdin);
						fflush(stdin);
						
						printf("%s\n",new_pass);
						strcpy(users[i].id.pass,new_pass);
						printf("the new password of %s is %s\n",users[i].name,users[i].id.pass);
						break;	
					
					case '2':
						printf("Enter amount of money you would get\n");
						scanf("%d",&cash);
						fflush(stdin);	 
						if(cash<=users[i].id.balance)
						{
							users[i].id.balance=users[i].id.balance-cash;
							printf("balance now of %s is %d\n",users[i].name,users[i].id.balance);
							
						}
						break;
				

					case '3':
						printf("Enter amount of money you would add\n");
						scanf("%d",&add);
						fflush(stdin);	 
						users[i].id.balance=users[i].id.balance+add;
						printf("balance now of %s is %d\n",users[i].name,users[i].id.balance);
						break;
						
					case '4':
						Client(users);
				}
			}	
			break;
		
		}
	
	}
}	
	
#endif
