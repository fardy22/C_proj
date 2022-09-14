#ifndef SHARED_H_
#define SHARED_H_

#include"header.h"



int make_trans(int trans,struct Bank_acc *users)
{
	char entered[11];
	int ind=0;
	
	printf("Enter ID of Bank account you want transfer to \n");
	fgets(entered,11,stdin);
	fflush(stdin);

	for(int i=0;i<20;i++)
	{
		
		if (strcmp(entered,users[i].id.ID)==0 && users[i].st==active)
		{
			printf("balance of %s is %d\n",users[i].name,users[i].id.balance);
			users[i].id.balance=users[i].id.balance+trans;
			printf("balance of %s now is %d\n",users[i].name,users[i].id.balance);
			ind++;
			break;
		}
	}
	if (ind==0)
		printf("transaction is failed\n");
	
	return ind;
}

#endif