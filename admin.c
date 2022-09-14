#ifndef ADMIN_H_
#define ADMIN_H_


#include"header.h"
struct Bank_employee Bank_employee_acc(struct Bank_employee emp)
{
	strcpy(emp.ID,"0123456789");   //use emp ID=0123456789	
	
	strcpy(emp.pass,"12345678");  //use emp pass=123456789
	
	return emp;
}


void create_acc(struct Bank_acc *users )
{
	static int n=0;
	
	users[n].st=active;
	
	printf("please enter your name\n");
	fgets(users[n].name,30,stdin);
	fflush(stdin);

	printf("please enter your address\n");
	fgets(users[n].address,30,stdin);
	fflush(stdin);

	printf("please enter your age\n");
	scanf("%d",&users[n].age);
	fflush(stdin);

	if(users[n].age<21)
	{
	printf("please enter your grudian ID\n");
	fgets(users[n].G_national_id,14,stdin);
	fflush(stdin);
		for(int i=0;i<10;i++)
		{	
		 int j=9-i;
		 users[n].id.ID[i]=users[n].G_national_id[j];      //a way for encryption from national id
														  //ex1: id=12345678912345  so id=1987654321 pass=19876543
														  //ex2: id=12332145665478  so id=6654123321 pass=66541233
		 
		 if(i<8)
				users[n].id.pass[i]= users[n].G_national_id[j];
		
		}
		users[n].id.ID[10]='\0';
		users[n].id.pass[8]='\0';

	
	}
	else
	{
	printf("please enter your national ID\n");
	fgets(users[n].national_id,14,stdin);
	fflush(stdin);
		for(int i=0;i<10;i++)
		{	
		 int j=9-i;
	
		 users[n].id.ID[i]=users[n].national_id[j];
		 
		 if(i<8)
			
				users[n].id.pass[i]= users[n].national_id[j];
			
		}
		users[n].id.ID[10]='\0';
		users[n].id.pass[8]='\0';
		
	
	}

	n++;
}

void open_acc(struct Bank_acc *users,struct Bank_employee emp )
{
	char emp_id[11];
	char emp_pass[9];
	char entered[11];
	char choose;
	int ind;
	char stat;
	int trans;
	int cash;
	int add;
	
	printf("Enter your emp ID \n");
	fgets(emp_id,11,stdin);
	fflush(stdin);
	printf("Enter your emp ID is %s\n",emp_id);
	
	printf("Enter your emp pass\n");
	fgets(emp_pass,9,stdin);
	fflush(stdin);
	printf("Enter your emp pass is %s\n",emp_pass);
	
		if(strcmp(emp_id,emp.ID)==0 && strcmp(emp_pass,emp.pass)==0)
		{
		
			printf("Enter your Bank account ID \n");
			fgets(entered,11,stdin);
			fflush(stdin);
				for(int i=0;i<20;i++)
			{
				
				if (strcmp(entered,users[i].id.ID)==0)
				{
					printf("choose\n 0:to make a transaction \n 1:to change account status \n 2:to get cash \n 3:to deposit in account \n 4:to return to main menu \n");
					scanf("%c",&choose);
					fflush(stdin);
					switch(choose)
					{
						case '0':
							printf("your balance is %d\n",users[i].id.balance);
							printf("Enter amount of money you would transfer \n");
							scanf("%d",&trans);
							fflush(stdin);	 
							if(trans<=users[i].id.balance && users[i].st==active)
							{
								ind=make_trans(trans,users);
								if(ind != 0)
								{
								users[i].id.balance=users[i].id.balance-trans;
								printf(" balance of %s now is %d\n",users[i].name,users[i].id.balance);
								}	
							}
							else
								printf("transaction is failed\n");
							break;
						
						case '1':
							printf("Enter the status you want \n 0- Set Account to Active State \n 1- Set Account to Restricted State \n 2- Set Account to Closed\n");
							scanf("%c",&stat);
							fflush(stdin);
							switch(stat)
							{
								case '0':
								users[i].st=active;
								break;
								
								case '1':
								users[i].st=restricted;
								break;
								
								case '2':
								users[i].st=closed;
								break;
								
							}
							printf("your staus now is %d",users[i].st);
							break;
							
						case '2':
							printf("balance of %s is %d\n",users[i].name,users[i].id.balance);
							printf("Enter amount of money you would get\n");
							scanf("%d",&cash);
							fflush(stdin);	 
							if(cash<=users[i].id.balance)
							{
								users[i].id.balance=users[i].id.balance-cash;
								printf("balance of %s now is %d\n",users[i].name,users[i].id.balance);
							}
							break;
					

						case '3':
							printf("Enter amount of money you would add\n");
							scanf("%d",&add);
							fflush(stdin);	 
							users[i].id.balance=users[i].id.balance+add;
							printf("balance of %s now is %d\n",users[i].name,users[i].id.balance);
							break;
						
						case '4':
							open_acc(users,emp);
							break;
					}	
				
			
					break;
				}
			
			}
		
		}
}

#endif