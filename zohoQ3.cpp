#include<bits/stdc++.h>
using namespace std;
struct customer{
	int acc_no;
	char acc_holder[10];
	long int pin;
	long int acc_bal;
	customer* next=NULL;
};
customer* head=NULL;
struct atm_balance{
	long int amount=0;
	int number_of_notes=0;
};
struct atm_balance atm_bal[3];
class customer_details{
public:
void insert()
{
	int a;
	char s[10];
	long int p;
	long int ac;
	customer* link=(customer*)malloc(sizeof(customer));
	cout<<"acc no:";
	cin>>a;
	cout<<"account holders name:";
	cin>>s;
	cout<<"pin no:";
	cin>>p;
	cout<<"account balance in rupees:";	
	cin>>ac;
	link->acc_no=a;
	link->acc_bal=ac;
	strcpy(link->acc_holder,s);
	link->pin=p;
	link->next=head;
	head=link;
}
public:
void print_customer_details()
{
	customer *ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->acc_no<<" "<<ptr->acc_holder<<" "<<ptr->pin<<" "<<ptr->acc_bal<<char(10);
		ptr=ptr->next;
	}
}
public:
void add()
{
	if(head==NULL)
	insert();
	else
	{
	int a;
	char s[10];
	long int p;
	long int ac;
	customer *link=(customer*)malloc(sizeof(customer));
	cout<<"acc no:";
	cin>>a;
	cout<<"account holders name:";
	cin>>s;
	cout<<"pin no:";
	cin>>p;
	cout<<"account balance inrupees:";	
	cin>>ac;
	for(customer *h=head;h!=NULL;h=h->next)
	if(h->next==NULL)
	{
		link->acc_no=a;
		link->acc_bal=ac;
		strcpy(link->acc_holder,s);
		link->pin=p;
		h->next=link;
		link->next=NULL;
	}
}
}
public:
	long int search(int a_no,long int &bal)
	{
		customer *ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->acc_no==a_no)
			{
				bal=ptr->acc_bal;
				return ptr->pin;
			}
			else
			ptr=ptr->next;
		}
		return 2;
	}
public:
	void change_balance(int a_no,long int amt)
	{
		customer *ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->acc_no==a_no)
			{
				ptr->acc_bal=ptr->acc_bal-amt;
				cout<<"\ncurrent bal "<<ptr->acc_bal;
				return;
			}
			else
			ptr=ptr->next;
		}
		
	}
public:
	void transfer(int ar_no,long int amt)
	{
		customer *ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->acc_no==ar_no)
			{
				ptr->acc_bal=ptr->acc_bal+amt;
				cout<<"\ndone\n";
				return;
			}
			else
			ptr=ptr->next;
		}
		cout<<"\naccount no not exits..";
	}
};
class atm_machine{
public:
void check_atm_bal(long int total)
{
	cout<<"\n"<<2000<<"   "<<atm_bal[0].number_of_notes<<"   "<<atm_bal[0].amount;
	cout<<"\n"<<500<<"   "<<atm_bal[1].number_of_notes<<"   "<<atm_bal[1].amount;
	cout<<"\n"<<100<<"   "<<atm_bal[2].number_of_notes<<"   "<<atm_bal[2].amount;
	cout<<"\ntotal amount available in atm:"<<atm_bal[0].amount+atm_bal[1].amount+atm_bal[2].amount<<"\n";
}
public:
void add_atm(long int &total)
{
	int number;
	for(int i=0;i<3;i++)
	{
	switch(i)
	{
		case 0:{
			cout<<"2000 X ";
			cin>>number;
			atm_bal[0].amount=2000*number;
			atm_bal[0].number_of_notes=number;
			total=total+atm_bal[0].amount;
			break;
		}
		case 1:{
			cout<<"500 X ";
			cin>>number;
			atm_bal[1].amount=500*number;
			atm_bal[1].number_of_notes=number;
			total=total+atm_bal[1].amount;
			break;
		}
		case 2:{
			cout<<"100 X ";
			cin>>number;
			atm_bal[2].amount=100*number;
			atm_bal[2].number_of_notes=number;
			total=total+atm_bal[2].amount;
			break;
		}
	}
	}
}
};
void withdraw(long int amt,long int &total)
{
	int two_k=0,five=0,one=0;
	while(amt!=0)
	{
		if(amt>=2000)
		{
			two_k=amt/2000;
			amt=amt%2000;
		}
		if(amt>=500)
		{
			five=amt/500;
			amt=amt%500;
		}
		if(amt>=100)
		{
			one=amt/100;
			amt=amt%100;
		}
	}
	total=total-amt;
	if(two_k<atm_bal[0].number_of_notes&&five<atm_bal[1].number_of_notes&&one<atm_bal[2].number_of_notes)
	{
	atm_bal[0].amount=atm_bal[0].amount-two_k*2000;
	atm_bal[1].amount=atm_bal[1].amount-five*500;
	atm_bal[2].amount=atm_bal[2].amount-one*100;
	atm_bal[0].number_of_notes-=two_k;
	atm_bal[1].number_of_notes-=five;
	atm_bal[2].number_of_notes-=one;
		}
		else
		{
			cout<<"\ninsufficient amount in atm.";
			}	
}
int main()
{
	long int total=0;
	int no;
	long int a,p;
	atm_machine atm;
	customer_details customer_info;
	cout<<".....................\nfeed\n";
	atm.add_atm(total);
	atm.check_atm_bal(total);
	cout<<"................\nfeeding customer details\n";
	cout<<"\nenter the no of customers:";
	cin>>no;
	for(int i=0;i<no;i++)
	{
		cout<<"customer "<<i<<" details\n";
		customer_info.add();
	}
	customer_info.print_customer_details();
	cout<<".....................................\nATM\nlogin page:\n";
	bool i=1;
	while(i)
	{
	cout<<"\nenter the acc no:";
	cin>>a;
	long int balance;
	p=customer_info.search(a,balance);
	if(p!=2)
	{
		long int pswd;
		cout<<"enter the pin:";
		cin>>pswd;
		if(pswd==p)
		{
			int opt;
			l1:cout<<"\nwelcome\n";
			cout<<"enter the options:\n1.balance\n2.withdraw\n3.transfer\n4.atm balance\n5.exit\n";
			cin>>opt;
			switch(opt)
			{
				case 1:{
					cout<<"\ncurrent balance is "<<balance;
					goto l1;
					break;
				}
				case 2:{
					long int amt=0;
					cout<<"\nenter the amount in multiples of 100(transact limit 10000):";
					cin>>amt;
					if(amt<100||amt%100!=0)
					{
						cout<<"please check the amont enter..ensure that it is multiples of 100.";
						goto l1;
					}
					if(amt>10000)
					{
						cout<<"\ntransact limit exceeds...";
						goto l1;
					}
					else
					{
						if(amt<balance)
						{
							withdraw(amt,total);
							cout<<"done";
							customer_info.change_balance(a,amt);
						}
						else
						{
							cout<<"\ninsufficiant balance..";
							goto l1;
						}
					}
					break;
				}
				case 3:{
					int trans_acc;
					cout<<"\nenter the acc_no of reciever:";
					cin>>trans_acc;
					long int amt1;
					cout<<"\nenter the amount to be transfered:";
					cin>>amt1;
					if(amt1<10000&&amt1>1000)
					{
						if(amt1<balance)
					{
						customer_info.transfer(trans_acc,amt1);
						customer_info.change_balance(a,amt1);
						goto l1;
					}
					else
					cout<<"\ninsuficient balance...";
					}
					else
					{
						cout<<"\ninvalid transact amount..";
					}
					break;
				}
				case 4:{
					atm.check_atm_bal(total);
					break;
				}
				case 5:{
					i=0;
					break;
				}
			}
		}
		else
		cout<<"\ninvalid pin\ntry again\n";
	}
	else
	cout<<"\naccount does't exist...";
}
	
	return 0;
}
