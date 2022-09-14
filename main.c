#include"header.h"


int main()
{
	char feature;
	char action;
	struct Bank_acc users[20];
	struct Bank_employee emp1;
	emp1=Bank_employee_acc(emp1);
	while (1)
	{
		printf("choose the feature you want\n 1-admin window\n 2-client window\n");
		scanf("%c",&feature);
		fflush(stdin);
		switch(feature)
		{
			case '1':
				printf("choose the action you want\n 1-creat account\n 2-open account\n");
				scanf("%c",&action);
				fflush(stdin);
				switch(action)
				{
						case '1':
							create_acc(users);
							break;
						case '2':
							open_acc(users,emp1);
							break;
				}
				break;
			
			case '2':
				Client(users);
				break;
			
		}	
	}
}