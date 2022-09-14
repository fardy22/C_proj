#ifndef HEADER_H_
#define HEADER_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct Bank_employee
{
	char ID[11];
	char pass[9];
};


struct Bank_ID
{
	char ID[11];
	char pass[9];
	int balance;
};

enum status
{
	closed=0,
	restricted=1,
	active=2,
};

struct Bank_acc
{
	char name[30];
	char address[30];
	int  age;
	char national_id[14];
	char G_national_id[14];
	struct Bank_ID id;
	enum status st;
};

void create_acc(struct Bank_acc *users );
int make_trans(int trans,struct Bank_acc *users);
void open_acc(struct Bank_acc *users,struct Bank_employee emp );
void Client(struct Bank_acc *users);
struct Bank_employee Bank_employee_acc(struct Bank_employee emp);


#endif