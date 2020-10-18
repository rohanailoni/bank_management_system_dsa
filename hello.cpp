#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <cstdlib>
#include<chrono>
using namespace std;
int main_exit;

void fordelay(int);
void close(void);
int main();
void menu_e();
void employee();
void customer();
void menu_c();

class sort_arr{
	public:
	double amount;
	long long int account_number;
};
//for all info
void quickSort(sort_arr arr[], int low, int high) ;
class node3{
    public:
        string name;
        string dob;
        string age;
        string date;
        string address;
        string phone;
        string doc;
        string depo;
        string acc_type;
        string interest;

};
//for all address of info
class node2{
    public:
    node3 *next1=NULL;
    node2 *next2=NULL;
    string password;
    long long int  account_no;
};
// hash table;
class node1{
    public:
    int key;
    node2 *next=NULL;
    
}arr[30];
//for hashing method like searching and inserting 
class node4{
    public:
    string name;
    long long int acc_no;
    node1 *next1=NULL;
    node4 *next2=NULL;

};

class info{
    public:
    int key;
    node4 *next;

}in[20];

class str_hashing{
    public:
    void insert(long long int n,string s,node1 *N){
        int key=0;
        for(int i=0;i<s.length();i++){
            key+=int(s[i])*pow(31,i);
        }
        key=key%20;
        
        in[key].key=key;
        in[key].next=NULL;
        node4 *n1;
        node4 *temp=new node4();
        temp->acc_no=n;
        temp->name=s;
        temp->next1=N;
        if(in[key].next==NULL){
           in[key].next=temp;
        }
        else{
            n1=in[key].next;
            while(n1->next2!=NULL){
                n1=n1->next2;
            }
            temp=n1->next2;

            
        }
    }
    node4* search(string s){
        int key=0;
        for(int i=0;i<s.length();i++){
            key+=int(s[i])*pow(31,i);
        }
        key=key%20;
        node4 *temp;
        
        temp=in[key].next;
        if(temp->name==s){
            return temp;
        }
        
        while(temp->name!=s && temp!=NULL){
            cout<<1<<endl;
            temp=temp->next2;
        }
        return temp->next2;

    }






}ha1;

class hashing{
    public:
    void insert(node2 *n,node3 *N){
        int v_key=n->account_no%30;
        n->next1=N;
        n->next2=NULL;
        if(arr[v_key].next==NULL){
        arr[v_key].key=v_key;
        arr[v_key].next=n;
        // cout<<"in loop"<<endl;
        }
        else{
			 cout<<"in out loop"<<endl;
            node2 *temp;
            temp=arr[v_key].next;
            while(temp->next2!=NULL){
                temp=temp->next2;
            }
            temp->next2=n;
			//cout<<n->account_no;
			//cout<<"loop ended"<<endl;
        }


    }
    node3* search(long long int n){
        int key=n%30;
        node2 *temp;
        temp=arr[key].next;
        
        while(temp->account_no!=n && temp!=NULL){
            temp=temp->next2;
        }
        return temp->next1;

        
    }    

}ha;

class Bank{
public:
    string account_number;
	string name;
    string dob;
    string age;
    string date;
    string address;
    string phone;
    string doc;
    string depo;
    string acc_type;
    string password;
    string interest;
public:
    void read_data();
    void acc_write();
	void modify_account();
	void search_rec();
	void deposit_withdraw();
	void display_all();
	void transfer();
	void insert();
	void filter();
    
};

float inter(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);
}

void Bank::read_data()
{
	int x,i=0;
	string acc_no;
	int a;
	Retry:
	ostringstream str1;
    a=rand()%100000000+10000000;
	str1<<a;
	account_number=str1.str();
	cout<<account_number;
    ifstream is("Account_info.csv");
    do
    {
       	getline(is,acc_no, ',');
       	getline(is,password, '\n');
    	if(acc_no == account_number)
    	{
    		cout<<"\nAccount No. Matches with Existing Account!";
    		cout<<"\n1. Try Again!\n2. Login To Account";
    		cin>>x;
    		if(x == 1)
    			goto Retry;
    		else
    			customer();
    	}
    	break;
	}while(is.good());
    fflush(stdin);
    cout<<"\nEnter Name: ";
    getline(cin,name);
    cout<<"\nEnter the  of birth(mm/dd/yyyy):";
    fflush(stdin);
	cin>>dob;
    cout<<"\nEnter the age:";
    cin>>age;
    cout<<"\nEnter the address:";
    fflush(stdin);
	getline(cin,address);
    cout<<"\nEnter the phone number: ";
    fflush(stdin);
    cin>>phone;
    cout<<"\nYou want to deposit amount:\n\t1.Yes\n\t2.No\n:";
    cin>>x;
    if(x == 1)
    {
    	cout<<"\nEnter the amount to deposit: Rs ";
		cin>>depo;    	
	}
	else
	{
		depo = to_string(0);
	}
    cout<<"\nType of account:\n\t#Saving\n\t#Current\n\n\tEnter your choice:";
    fflush(stdin);
	cin>>acc_type;    
    cout<<endl;
    time_t now = time(0);
    string dt = ctime(&now);
    cout<<"\nDate and Time of Account Creation:" << dt << endl;
    date = dt;
	struct tm *ltm = localtime(&now);
    doc = to_string(ltm->tm_mday);
    doc = doc.substr(0, doc.size()-1);
    interest = to_string(i++);
    cout<<"\nEnter Password For Your Account:";
    cin>>password;
    printf("\nAccount created successfully!");
    login_try:
    cout<<"\n\nEnter 1. For Main Menu\n\t2. For Previous Menu and 0 to Exit:";
    scanf("%d",&main_exit);
    if (main_exit==1)
    {
    	system("cls");
        main();
    }
    else if (main_exit==0)
    {
    	system("cls");
        close();
	}
	else if (main_exit == 2)
	{
		system("cls");
		menu_c();
	}
    else
    {
		printf("\nInvalid!");
        fordelay(1000000000);
        system("cls");
        goto login_try;
	}
}

void Bank::acc_write()
{
	ofstream MyFile1, MyFile2;
	int x,i=0;
	string acc_no;
	int a;
	Retry:
	ostringstream str1;
	srand(time(0)); 
    a=rand()%100000000+10000000;
	str1<<a;
	account_number=str1.str();
	cout<<account_number;
    ifstream is("Account_info.csv");
    do
    {
       	getline(is,acc_no, ',');
       	getline(is,password, '\n');
    	if(acc_no == account_number)
    	{
    		cout<<"\nAccount No. Matches with Existing Account!";
    		cout<<"\n1. Try Again!\n2. Login To Account";
    		cin>>x;
    		if(x == 1)
    			goto Retry;
    		else
    			customer();
    	}
    	break;
	}while(is.good());
    fflush(stdin);
    cout<<"\nEnter Name: ";
    getline(cin,name);
    cout<<"\nEnter the  of birth(mm/dd/yyyy):";
    fflush(stdin);
	cin>>dob;
    cout<<"\nEnter the age:";
    cin>>age;
    cout<<"\nEnter the address:";
    fflush(stdin);
	getline(cin,address);
    cout<<"\nEnter the phone number: ";
    fflush(stdin);
    cin>>phone;
    cout<<"\nYou want to deposit amount:\n\t1.Yes\n\t2.No\n:";
    cin>>x;
    if(x == 1)
    {
    	cout<<"\nEnter the amount to deposit: Rs ";
		cin>>depo;    	
	}
	else
	{
		depo = to_string(0);
	}
    cout<<"\nType of account:\n\t#Saving\n\t#Current\n\n\tEnter your choice:";
    fflush(stdin);
	cin>>acc_type;    
    cout<<endl;
    time_t now = time(0);
    string dt = ctime(&now);
    cout<<"\nDate and Time of Account Creation:" << dt << endl;
    date = dt;
	struct tm *ltm = localtime(&now);
    doc = to_string(ltm->tm_mday);
    doc = doc.substr(0, doc.size()-1);
    interest = to_string(i++);
    cout<<"\nEnter Password For Your Account:";
    cin>>password;
    printf("\nAccount created successfully!");
	cout<<doc;
	MyFile1.open("Bank_Record.csv", ios::out|ios::app);
	MyFile1<<account_number<<","<<name<<","<<dob<<","
		   <<age<<","<<address<<","<<phone<<","<<depo
		   <<","<<acc_type<<","<<date<<","<<doc<<","<<interest<<"\n";
	MyFile1.close();
	MyFile2.open("Account_info.csv", ios::out|ios::app);
	MyFile2<<account_number<<","<<password<<"\n"; 
	MyFile2.close();
}

void Bank::modify_account()
{
	Bank ac;
	int test = 0;
	string acc_no;
	cout<<"For Verification:\n";
	cout<<"Enter the Account Number again:";
	cin>>acc_no;
	ifstream is("Bank_Record.csv");
    do
    {
       	getline(is,account_number, ',');
       	getline(is, name, ',');
       	getline(is, dob, ',');
       	getline(is, age, ',');
       	getline(is, address, ',');
      	getline(is, phone, ',');
       	getline(is, depo, ',');
      	getline(is, acc_type, ',');
      	getline(is, date, ',');
      	getline(is, doc,',');
      	getline(is, interest, '\n');
        if(acc_no == account_number)
    	{   
    		test = 1;
			cout<<"\nAccount NO.:"<<account_number<<endl;
			cout<<"\nName:" <<name<<endl;
			cout<<"\nDOB:" <<dob<<endl;
			cout<<"\nAge:" <<age<<endl;
			cout<<"\nAddress: "<<address<<endl;
			cout<<"\nPhone number:"<<phone<<endl;
			cout<<"\nType Of Account:"<<acc_type<<endl;
			cout<<"\nDate of Account creation:"<<date<<endl;
			cout<<"\nAmount deposited:"<<depo<<endl;
			break;
        }
	}while (is.good());
	is.close();
	string x, y, z;
	int choice;
	int opt;
	if(test == 1)
	{
		ifstream file ("Bank_Record.csv");
		ofstream ofile ("temp.csv");
		do{
		cout<<"\n\n\n\t\t1.Update Name\n";
    	cout<<"\t\t2.Update dob Of Birth\n";
    	cout<<"\t\t3.Update Age\n";
    	cout<<"\t\t4.Update Address\n";
    	cout<<"\t\t5.Update Phone No.\n";
    	cin>>choice;
    	switch(choice)
    	{
        case 1:	system("color 3");
        		cout<<"\t\tUpdate Name\n\n";
				cout<<"Enter Old Name: ";
        		cin>>y;
        		cout<<"Enter New Name: ";
        		cin>>z;
				while (!file.eof())
				{	
					getline(file,x,',');
    				if (x == y)
        				ofile << z <<",";
    				else
        				ofile << x << ",";
				}
        		break;
        case 2:system("color 4");
        		cout<<"\t\tUpdate dob Of Birth\n\n";
				cout<<"Enter Old dob Of Birth(mm/dd/yyyy): ";
        		cin>>y;
        		cout<<"Enter New dob Of Birth(mm/dd/yyyy): ";
        		cin>>z;
				while (!file.eof())
				{	
					getline(file,x,',');
    				if (x == y)
        				ofile << z <<",";
    				else
        				ofile << x << ",";
				}
        		break;
    	case 3:system("color 5");
    			cout<<"\t\tUpdate Age\n\n";
				cout<<"Enter Old Age: ";
        		cin>>y;
        		cout<<"Enter New Age: ";
        		cin>>z;
				while (!file.eof())
				{	
					getline(file,x,',');
    				if (x == y)
        				ofile << z <<",";
    				else
        				ofile << x << ",";
				}
        		break;
        case 4:system("color 6");
				cout<<"\t\tUpdate Address\n\n";
				cout<<"Enter Old Address: ";
        		cin>>y;
        		cout<<"Enter New Address: ";
        		cin>>z;
				while (!file.eof())
				{	
					getline(file,x,',');
    				if (x == y)
        				ofile << z <<",";
    				else
        				ofile << x << ",";
				}
        		break;
        case 5:system("color 2");
				cout<<"\t\tUpdate Phone No.\n\n";
				cout<<"Enter Old Phone No. : ";
        		cin>>y;
        		cout<<"Enter New Phone No. : ";
        		cin>>z;
				while (!file.eof())
				{	
					getline(file,x,',');
    				if (x == y)
        				ofile << z <<",";
    				else
        				ofile << x <<",";
				}
        		break;
        default: cout<<"Invalid Input";
		}
		
		remove("Bank_Record.csv");
   		rename("temp.csv","Bank_Record.csv");	
		file.seekg(0, ios::beg);
		ofile.seekp(0, ios::beg);
		cout<<"\n\n\t\tDo You Want Update Any Other Field :"
				<<"\n\t\t1: YES\n\t\t2: NO\n";
		cin>>opt;
	}while(opt!=2);
	file.close();
	ofile.close();
	}
	else
	{
		cout<<"\nAccount Doesn't Exist";
	}
	login_try:
    cout<<"\nEnter 1. For Main Menu\n\t2. For Previous Menu and" 
			<<" 0 to Exit:";
    scanf("%d",&main_exit);
    if (main_exit==1)
    {
    	system("cls");
        main();
    }
    else if (main_exit==0)
    {
    	system("cls");
        close();
	}
	else if (main_exit == 2)
	{
		system("cls");
		menu_c();
	}
    else
    {
		printf("\nInvalid!");
        fordelay(1000000000);
        system("cls");
        goto login_try;
	}
}

void Bank::search_rec()
{
    int test=0,rate;
    int choice, date1;
    float t;
    string intrst, x, y;
    int amount, b;
    string acc_no, name_s;
    ifstream is("Bank_Record.csv");
    
    cout<<"Do you want to check by\n1.Account no\n2.Name"
			<<"\nEnter your choice:";
    cin>>choice;
    if (choice==1)
    {   
		cout<<"Enter the account number:";
        cin>>acc_no;
        do
        {
        	getline(is,account_number, ',');
       		getline(is, name, ',');
       		getline(is, dob, ',');
       		getline(is, age, ',');
       		getline(is, address, ',');
      		getline(is, phone, ',');
       		getline(is, depo, ',');
      		getline(is, acc_type, ',');
      		getline(is, date, ',');
      		getline(is, doc,',');
      		getline(is, interest,'\n');
        	amount = atoi(depo.c_str());
    		if(acc_no == account_number)
    		{
    			test = 1; system("cls");   
				cout<<"\nAccount NO.:"<<account_number<<endl;
				cout<<"\nName:" <<name<<endl;
				cout<<"\nDOB:" <<dob<<endl;
				cout<<"\nAge:" <<age<<endl;
				cout<<"\nAddress: "<<address<<endl;
				cout<<"\nPhone number:"<<phone<<endl;
				cout<<"\nType Of Account:"<<acc_type<<endl;
				cout<<"\nDate of Account creation:"<<date<<endl;
				cout<<"\nAmount deposited:"<<depo<<endl;
				
				ifstream file ( "Bank_Record.csv" );
				ofstream ofile ( "temp.csv" );
				
            	if(acc_type == "Saving")
                {
                	time_t now = time(0);
					struct tm *ltm = localtime(&now);
					date1 = ltm->tm_mday;
                    if(date1 != atoi(doc.c_str()))    
					{
						t = date1 - atoi(doc.c_str());
						rate=15;
						intrst=std::to_string(inter(t,amount,rate));						
						cout<<"\n\nYou will get Rs " <<intrst
								<<" as interest";
						file.clear();
						while (!file.eof())
						{		
							getline(file,x,',');
    						if (x == interest)
        						ofile << intrst <<",";
    						else if(x == depo)
        					{
        					y=(atoi(depo.c_str())+atoi(intrst.c_str()));
        					ofile << y << ",";
							}	
        					else
        						ofile << x <<","; 
						}
					}	
					else
					{
						cout<<"\n\nYou will get Rs 0 as interest"
								<<" for today...";
					}
					break;                    
                }
                else if(acc_type == "Current")
                {
                    time_t now = time(0);
					struct tm *ltm = localtime(&now);
					date1 = ltm->tm_mday;
                    if(date1 != atoi(doc.c_str()))    
					{
						t = date1 - atoi(doc.c_str());
						rate=15;
						intrst=std::to_string(inter(t,amount,rate));						
						cout<<"\n\nYou will get Rs " <<intrst
								<<" as interest";
						file.clear();
						while (!file.eof())
						{		
							getline(file,x,',');
    						if (x == interest)
        						ofile << intrst <<",";
    						else if(x == depo)
        					{
        					y=(atoi(depo.c_str())+atoi(intrst.c_str()));
        					ofile << y << ",";
							}
							else
        						ofile << x <<","; 
						}
					}	
					else
					{
						cout<<"\n\nYou will get Rs 0 as interest"
								<<" for today...";
					}
					break;
				}
            }
        }while (is.good());
    }
    else if (choice==2)
    {   
		cout<<"Enter the Name of Account Holder:";
        cin>>name_s;
        do
        {
        	getline(is,account_number, ',');
       		getline(is, name, ',');
       		getline(is, dob, ',');
       		getline(is, age, ',');
       		getline(is, address, ',');
      		getline(is, phone, ',');
       		getline(is, depo, ',');
      		getline(is, acc_type, ',');
      		getline(is, date, ',');
      		getline(is, doc,',');
      		getline(is, interest, '\n');
        	amount = atoi(depo.c_str());
    		if(name_s == name)
            {   
				test = 1; system("cls");   
				cout<<"\nAccount NO.:"<<account_number<<endl;
				cout<<"\nName:" <<name<<endl;
				cout<<"\nDOB:" <<dob<<endl;
				cout<<"\nAge:" <<age<<endl;
				cout<<"\nAddress: "<<address<<endl;
				cout<<"\nPhone number:"<<phone<<endl;
				cout<<"\nType Of Account:"<<acc_type<<endl;
				cout<<"\nDate of Account creation:"<<date<<endl;
				cout<<"\nAmount deposited:"<<depo<<endl;
				
				ifstream file ( "Bank_Record.csv" );
				ofstream ofile ( "temp.csv" );
				
            	if(acc_type == "Saving")
                {
                	time_t now = time(0);
					struct tm *ltm = localtime(&now);
					date1 = ltm->tm_mday;
                    if(date1 != atoi(doc.c_str()))    
					{
						t = date1 - atoi(doc.c_str());
						rate=15;
						intrst=std::to_string(inter(t,amount,rate));						
						cout<<"\n\nYou will get Rs " <<intrst
								<<" as interest";
						file.clear();
						while (!file.eof())
						{		
							getline(file,x,',');
    						if (x == interest)
        						ofile << intrst <<",";
    						else if(x == depo)
        					{
        					y=(atoi(depo.c_str())+atoi(intrst.c_str()));
        					ofile << y << ",";
							}
							else
        						ofile << x <<","; 
						}
					}	
					else
					{
						cout<<"\n\nYou will get Rs 0 as interest "
								<<"for today...";
					}
					break;                    
                }
                else if(acc_type == "Current")
                {
                    time_t now = time(0);
					struct tm *ltm = localtime(&now);
					date1 = ltm->tm_mday;
                    if(date1 != atoi(doc.c_str()))    
					{
						t = date1 - atoi(doc.c_str());
						rate=15;
						intrst=std::to_string(inter(t,amount,rate));						
						cout<<"\n\nYou will get Rs " <<intrst
								<<" as interest";
						file.clear();
						while (!file.eof())
						{		
							getline(file,x,',');
    						if (x == interest)
        						ofile << intrst <<",";
    						else if(x == depo)
        					{
        					y=(atoi(depo.c_str())+atoi(intrst.c_str()));
        					ofile << y << ",";
							}
							else
        						ofile << x <<","; 
						}
					}	
					else
					{
						cout<<"\n\nYou will get Rs 0 as interest for today...";
					}
					break;
				}
            }
        }while (is.good());
    }
    if(test == 0)
    {
    	cout<<"\n\n\t\tAccount doesn't Exist!";
	}
    remove("Bank_Record.csv");
   	rename("temp.csv","Bank_Record.csv");	
	is.close();
    login_try:
    cout<<"\nEnter 1. For Main Menu\n\t2. For Customer Menu\n\t"
			<<"3. For Employee Menu and 0 to Exit:";
    scanf("%d",&main_exit);
    if (main_exit==1)
    {
    	system("cls");
        main();
    }
    else if (main_exit==0)
    {
    	system("cls");
        close();
	}
	else if (main_exit == 2)
	{
		system("cls");
		menu_c();
	}
	else if(main_exit == 3)
	{
		system("cls");
		employee();
	}
    else
    {
		printf("\nInvalid!");
        fordelay(1000000000);
        system("cls");
        goto login_try;
	}
}

void Bank::deposit_withdraw()
{
	int choice,test=0,amt,amount;
	string acc_no, y, x;
    ifstream file ("Bank_Record.csv" );
	ofstream ofile ("temp.csv" );
	Bank ac;
	cout<<"Enter the account number:";
	cin>>acc_no;
    do
    {
       	getline(file,account_number, ',');
       	getline(file, name, ',');
       	getline(file, dob, ',');
       	getline(file, age, ',');
       	getline(file, address, ',');
      	getline(file, phone, ',');
       	getline(file, depo, ',');
      	getline(file, acc_type, ',');
      	getline(file, date, ',');
      	getline(file, doc,',');
      	getline(file, interest, '\n');
        amount = atoi(depo.c_str());
    	if(acc_no == account_number)
    	{   
			test = 1;
			cout<<"\nAccount No.:"<<account_number<<endl;
			cout<<"\nName:" <<name<<endl;
			cout<<"\nDOB:" <<dob<<endl;
			cout<<"\nAge:" <<age<<endl;
			cout<<"\nAddress: "<<address<<endl;
			cout<<"\nPhone number:"<<phone<<endl;
			cout<<"\nDate of Creation: "<<date<<endl;
			cout<<"\nType Of Account:"<<acc_type<<endl;
			cout<<"\nBalance:"<<depo<<endl;
			test=1;
            cout<<"\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\n"
			<<"Enter your choice(1 for deposit and 2 for withdraw):";
            cin>>choice;
            if (choice==1)
            {
                cout<<"Enter the amount you want to deposit: ";
                cin>>amt;
                file.seekg(0, ios::beg);
                amt = atoi(depo.c_str()) + amt;
                y = to_string(amt);
                cout<<"\n\tBalance : "<<y;
                int i=1;
                while (file.good())
				{	
					getline(file,x,',');
    				if (x == depo)
        			{
        				ofile << y <<",";
					}	
    				else
        			{
        				ofile << x <<",";
					}	
				}
                printf("\n\nDeposited successfully!");
            }
            else
            {
                cout<<"Enter the amount you want to Withdraw: ";
                cin>>amt;
                file.seekg(0, ios::beg);
                if(amt > atoi(depo.c_str()))
                    cout<<"Not Enough Balance\n";
                else
                {
                    amt = atoi(depo.c_str()) - amt;
                    y =  std::to_string(amt);
                    cout<<"\n\tBalance : "<<y;
                    while (file.good())
					{	
						getline(file,x,',');
    					if (x == depo)
        					ofile << y <<",";
    					else
        					ofile << x <<",";
        			}
					printf("\n\nWithdrawn successfully!");        	
				}
            }
        }
   }while (file.good());
   	file.close();
	ofile.close();
	remove("Bank_Record.csv");
	rename("temp.csv","Bank_Record.csv");

   if(test==0)
   {
    	cout<<"\n\nRecord not found!!";
    	login_try:
    cout<<"\nEnter 1. For Main Menu\n\t2. For Previous Menu and"
			<<" 0 to try again:";
    scanf("%d",&main_exit);
    if (main_exit==1)
    {
    	system("cls");
        main();
    }
    else if (main_exit==0)
    {
    	system("cls");
        ac.deposit_withdraw();
	}
	else if (main_exit == 2)
	{
		system("cls");
		employee();
	}
    else
    {
		printf("\nInvalid!");
        fordelay(1000000000);
        system("cls");
        goto login_try;
	}
   }
   else
   {
    login_try1:
    cout<<"\nEnter 1. For Main Menu\n\t2. For Previous Menu "
			<<"and 0 to Exit:";
    scanf("%d",&main_exit);
    if (main_exit==1)
    {
    	system("cls");
        main();
    }
    else if (main_exit==0)
    {
    	system("cls");
        close();
	}
	else if (main_exit == 2)
	{
		system("cls");
		menu_c();
	}
    else
    {
		printf("\nInvalid!");
        fordelay(1000000000);
        system("cls");
        goto login_try1;
	}
   }

}

void Bank::display_all()
{
	int amount;
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout<<"====================================================="
	<<"========================================================="
	<<"=========================\n";
    cout<<"  Account No.\t\tName\t\tType\t\tBalance\t\tAddress"
	<<"\t\tPhone No.\t\tCreation Date\n";
    cout<<"====================================================="
	<<"========================================================="
	<<"=========================\n";
    ifstream is("Bank_record.csv");
	int i=1,sz=0,sz1=0;
	char c;
	is.seekg(0,ios::end);
	sz=is.tellg();
	//cout<<sz<<endl;
	is.seekg(0,ios::beg);
	// while (!is.eof())
    // {
    // 	cout<<i<<". ";
    // 	i++;
    // 	getline(is,account_number, ',');
    //    	getline(is, name, ',');
    //    	getline(is, dob, ',');
    //    	getline(is, age, ',');
    //    	getline(is, address, ',');
    //   	getline(is, phone, ',');
    //    	getline(is, depo, ',');
    //   	getline(is, acc_type, ',');
    //   	getline(is, date, ',');
    //   	getline(is, doc,',');
    //   	getline(is, interest,'\n');
    //     amount = atoi(depo.c_str());
    //     sz1=is.tellg();
    //     cout<<sz1<<" ";
    // 	cout<<account_number<<"\t\t"<<name<<"\t\t"<<acc_type
	// 			<<"\t\t"<<amount<<"\t\t"<<address<<"\t\t"
	// 			<<phone<<"\t\t"<<date<<endl;
	// 	if(sz == (sz1))
	// 	break;
	// }
	//cout<<arr[21].next->next2->next1->name;
	for(int i=0;i<30;i++){
		
		
		if(arr[i].next!=NULL){
			node2 *temp=arr[i].next;
			// cout<<temp->next2;
			while(temp!=NULL){
				node3 *x=temp->next1;
				cout<<temp->account_no<<"\t\t"<<x->name<<"\t\t"<<x->acc_type
				<<"\t\t"<<x->depo<<"\t\t"<<x->address<<"\t\t"
			<<x->phone<<"\t\t"<<x->date<<endl;
					temp=temp->next2;
					

			}
			
		}
	}




	login_try:
    cout<<"\nEnter 1. For Main Menu\n\t2. For Previous Menu "
			<<"and 0 to Exit:";
    scanf("%d",&main_exit);
    if (main_exit==1)
    {
    	system("cls");
        main();
    }
    else if (main_exit==0)
    {
    	system("cls");
        close();
	}
	else if (main_exit == 2)
	{
		system("cls");
		menu_e();
	}
    else
    {
		printf("\nInvalid!");
        fordelay(1000000000);
        system("cls");
        goto login_try;
	}
}

void Bank::transfer()
{
	int amount,amt, test = 0;
	string acc_no, y, x;
	{
	ifstream file ("Bank_Record.csv" );
	ofstream ofile ("temp.csv" );
	Bank ac;
	cout<<"Enter Your account number:";
	cin>>acc_no;
    do
    {
       	getline(file,account_number, ',');
       	getline(file, name, ',');
       	getline(file, dob, ',');
       	getline(file, age, ',');
       	getline(file, address, ',');
      	getline(file, phone, ',');
       	getline(file, depo, ',');
      	getline(file, acc_type, ',');
      	getline(file, date, ',');
      	getline(file, doc,',');
      	getline(file, interest,'\n');
		if(acc_no == account_number)
    	{   
    		test = 1;
			cout<<"Account No.:"<<account_number<<endl;
			cout<<"Name:" <<name<<endl;
			cout<<"DOB:" <<dob<<endl;
			cout<<"Age:" <<age<<endl;
			cout<<"Address: "<<address<<endl;
			cout<<"Phone number:"<<phone<<endl;
			cout<<"Type Of Account:"<<acc_type<<endl;
			cout<<"Balance:"<<depo<<endl;
			
			cout<<"\nEnter the amount you want to transfer: ";
   			cin>>amt;
   			file.seekg(0, ios::beg);
    		if(amt > atoi(depo.c_str()))
    			cout<<"Not Enough Balance\n";
    		else
    		{
       			amount = atoi(depo.c_str()) - amt;
        		y =  std::to_string(amount);
        		cout<<"\n\tBalance : "<<y;
        		while (file.good())
				{	
					getline(file,x,',');
    				if (x == depo)
        				{
           					ofile << y <<",";
   						}
        				else
						{
        					ofile << x <<",";
        				}
				}						
			}
			break;
		}
	}while (file.good());
	
	file.close();
	ofile.close();
	remove("Bank_Record.csv");
	rename("temp.csv","Bank_Record.csv");
	}
	ifstream file ("Bank_Record.csv" );
	ofstream ofile ("temp.csv" );
	if(test == 0)
    {
    	cout<<"\n\n\t\tAccount doesn't Exist!";
	}
	cout<<"\nEnter account number where to transfer:";
	cin>>acc_no;
	test = 0;
	file.seekg(0, ios::beg);
    do
    {
       	getline(file,account_number, ',');
       	getline(file, name, ',');
       	getline(file, dob, ',');
       	getline(file, age, ',');
       	getline(file, address, ',');
      	getline(file, phone, ',');
       	getline(file, depo, ',');
      	getline(file, acc_type, ',');
        if(acc_no == account_number)
    	{   
			test = 1;
			cout<<"Account No.:"<<account_number<<endl;
			cout<<"Name:" <<name<<endl;			
    		amt = atoi(depo.c_str()) + amt;
        	y =  std::to_string(amt);
        	file.seekg(0, ios::beg);
        	while (file.good())
			{	
				getline(file,x,',');
    			if (x == depo)
        			ofile << y <<",";
    			else
        			ofile << x <<",";
        	}
        	cout<<"\n\tTransfer Successful!";
        	break;
        }
	}while (file.good());
	
	file.close();
	ofile.close();
	remove("Bank_Record.csv");
	rename("temp.csv","Bank_Record.csv");
	if(test == 0)
    {
    	cout<<"\n\n\t\tAccount doesn't Exist!";
	}
	
	login_try:
    cout<<"\nEnter 1. For Main Menu\n\t2. For Previous Menu "
			<<"and 0 to Exit:";
    scanf("%d",&main_exit);
    if (main_exit==1)
    {
    	system("cls");
        main();
    }
    else if (main_exit==0)
    {
    	system("cls");
        close();
	}
	else if (main_exit == 2)
	{
		system("cls");
		menu_c();
	}
    else
    {
		printf("\nInvalid!");
        fordelay(1000000000);
        system("cls");
        goto login_try;
	}
		
}

void Bank::insert(){
	int amount;
	ifstream is("Bank_record.csv");
	int i=1,sz=0,sz1=0;
	char c;
	is.seekg(0,ios::end);
	sz=is.tellg();
	//cout<<sz<<endl;
	is.seekg(0,ios::beg);
	while (!is.eof())
    {
    	//cout<<i<<". ";
    	i++;
    	getline(is,account_number, ',');
       	getline(is, name, ',');
       	getline(is, dob, ',');
       	getline(is, age, ',');
       	getline(is, address, ',');
      	getline(is, phone, ',');
       	getline(is, depo, ',');
      	getline(is, acc_type, ',');
      	getline(is, date, ',');
      	getline(is, doc,',');
      	getline(is, interest,'\n');
		  //cout<<account_number<<name<<endl;	
        amount = atoi(depo.c_str());
        sz1=is.tellg();
        //cout<<sz1<<" ";
    	node2 *n1=new node2();
		node3 *n2=new node3();
		n2->name=name;
		n2->dob=dob;
		n2->age=age;
		n2->date=date;
		n2->address=address;
		n2->phone=phone;
		n2->doc=doc;
		n2->depo=depo;
		n2->acc_type=acc_type;
		n2->interest=interest;
		n1->password="rohan";
		n1->account_no=stoi(account_number);
		ha.insert(n1,n2);
		
		
		
		//ha1.insert(account_number,name,&arr[stoi(account_number)%30]);
		if(sz == (sz1))
		break;
	}
	//cout<<arr[21].next->next2->password;
	
}

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void close(void)
{
    printf("\n\n\n\nThis Program is Closed... Thank You");
}

void employee()
{
	char pass[10];
    char c;
    string s, name;
    int i=0;
    cout<<"\n\n\t\tFor Security Purpose:";
    cout<<"\n\n\t\tEnter the Login Emplyoee Id:";
    cin>>name;
    cout<<"\n\n\t\tEnter the password to login:";
    while(1)
	{
    	c=getch();
        printf("*");
        s+=c;
    	if(c=='\r')
        {
            break;
        }    	
	}
 	s = s.substr(0, s.size()-1);
    cout<<endl;
    if(s == "1234" && (name == "rohan" || name == "Garima"))
        {
			printf("\n\nAccess Granted!\nLOADING");
        	for(i=0;i<=6;i++)
        	{
            	fordelay(100000000);
            	printf(".");
        	}
            	system("cls");
            	menu_e();
        }
    else
        {   printf("\n\nWrong password or Emplyoee Id!!");
            login_try:
            cout<<"\nEnter 1 to try again , 2 for Main Menu and"
					<<" 0 to Exit:";
            scanf("%d",&main_exit);
            if (main_exit==1)
            {
                system("cls");
                employee();
            }
            else if (main_exit==0)
            {
                system("cls");
            	close();
			}
			else if (main_exit == 2)
			{
				system("cls");
				main();
			}
            else
            {
				printf("\nInvalid!");
                fordelay(1000000000);
                system("cls");
                goto login_try;
			}
        }
}

void Bank::filter(){
	int n=2;
	sort_arr s[n];
	double amount;
	ifstream is("Bank_record.csv");
	int i=0,sz=0,sz1=0;
	char c;
	is.seekg(0,ios::end);
	sz=is.tellg();
	//cout<<sz<<endl;
	is.seekg(0,ios::beg);
	while (!is.eof())
    {
    	//cout<<i<<". ";
    	
    	getline(is,account_number, ',');
       	getline(is, name, ',');
       	getline(is, dob, ',');
       	getline(is, age, ',');
       	getline(is, address, ',');
      	getline(is, phone, ',');
       	getline(is, depo, ',');
      	getline(is, acc_type, ',');
      	getline(is, date, ',');
      	getline(is, doc,',');
      	getline(is, interest,'\n');
		//cout<<account_number<<name<<endl;	
        amount = atoi(depo.c_str());
        sz1=is.tellg();
        //cout<<sz1<<" ";
    	s[i].amount=amount;
		s[i].account_number=stoi(account_number);
		//cout<<s[i].account_number<<"this is it m";
		i++;
		//ha1.insert(account_number,name,&arr[stoi(account_number)%30]);
		if(sz == (sz1))
		break;
	}
	//cout<<s[0].account_number;
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout<<"====================================================="
	<<"========================================================="
	<<"=========================\n";
    cout<<"  Account No.\t\tName\t\tType\t\tBalance\t\tAddress"
	<<"\t\tPhone No.\t\tCreation Date\n";
    cout<<"====================================================="
	<<"========================================================="
	<<"=========================\n";
	
	
	quickSort(s,0,n);
	
	node3* temp;
	for(int i=0;i<n;i++){
		//cout<<"in the loop"<<endl;
		//cout<<s[i].account_number<<endl<<s[i].amount;
		temp=ha.search(s[i].account_number);
		//cout<<"after the search"<<endl;
		cout<<s[i].account_number<<"\t\t"<<temp->name<<"\t\t"<<temp->acc_type
				<<"\t\t"<<temp->depo<<"\t\t"<<temp->address<<"\t\t"
			<<temp->phone<<"\t\t"<<temp->date<<endl;
		

	}


	
}

void menu_e()
{
	int choice;
    Bank B;
    menu:
    system("cls");
    system("color 2");
	cout<<"\n\n\t\t\tBANK RECORD SYSTEM";
    cout<<"\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME "
		<<"TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout<<"\n\n\t\t\tEmployee Menu";
	cout<<"\n\t\t1.Check the details of existing account\n";
    cout<<"\t\t2.Display All Account Holder Name\n";
	cout<<"\t\t3.filter\n";
	cout<<"\t\t4.Exit\n\n\n\n\n\t\t Enter your choice:";
    cin>>choice;
    system("cls");
    switch(choice)
    {
        case 1:	B.search_rec();
        		break;
        case 2: B.display_all();
        		break;
		case 3: B.filter();
				break;
        case 4:	close();
        		break;
        default :cout<<"Invalid Input!\n";
        		cout<<"   Try Again\n";
				goto menu;
    }
    login_try:
    cout<<"\nEnter 1 for Main Menu , 2 for Previous Menu and"
		<<" 0 to Exit:";
            scanf("%d",&main_exit);
            if (main_exit==1)
            {
                system("cls");
                main();
            }
            else if (main_exit==0)
            {
                system("cls");
            	close();
			}
			else if (main_exit == 2)
			{
				system("cls");
				employee();
			}
            else
            {
				printf("\nInvalid!");
                fordelay(1000000000);
                system("cls");
                goto login_try;
			}
}

void customer()
{
	char pass[10];
    char c;
    string s, name, acc_no, password;
    int i=0,x;
    system("cls");
    cout<<"\n\n\t\t\tMENU";
    cout<<"\n\t\t1. New Customer";
    cout<<"\n\t\t2. Existing Customer";
    cout<<"\n\t\tEnter Your Choice : ";
    cin>>x;
    if(x==1)
    	menu_c();
    else
    {
    cout<<"\n\n\t\tFor Security Purpose:";
    cout<<"\n\n\t\tEnter the Login Customer Id:";
    cin>>name;
    cout<<"\n\n\t\tEnter the password to login:";
    while(1)
	{
    	c=getch();
        printf("*");
        s+=c;
    	if(c=='\r')
        {
            break;
        }    	
	}
 	s = s.substr(0, s.size()-1);
    cout<<endl;
    ifstream is("Account_info.csv");
    do
    {
       	getline(is,acc_no, ',');
       	getline(is,password, '\n');
       	if(acc_no == name)
    	{
    		i = 1;
    		if(password == s)
    		printf("\n\nAccess Granted!\nLOADING");
        	for(i=0;i<=6;i++)
        	{
            	fordelay(100000000);
            	printf(".");
        	}
            	system("cls");
            	menu_c();
    	}
    }while(is.good());
    	if(i == 0)
        {   
			printf("\n\nWrong password or Customer Id!!");
            login_try:
            cout<<"\nEnter 1 to try again , 2 for Main Menu and"
				<<" 0 to Exit:";
            scanf("%d",&main_exit);
            if (main_exit==1)
            {
                system("cls");
                customer();
            }
            else if (main_exit==0)
            {
                system("cls");
            	close();
			}
			else if (main_exit == 2)
			{
				system("cls");
				main();
			}
            else
            {
				printf("\nInvalid!");
                fordelay(1000000000);
                system("cls");
                goto login_try;
			}
        }    
	}
}

void menu_c(void)
{
	int choice;
    Bank B;
    menu:
    system("cls");
    system("color 2");
	cout<<"\n\n\t\t\tBANK RECORD SYSTEM";
    cout<<"\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME"
		<<" TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout<<"\n\n\t\t1.Create new account\n";
    cout<<"\t\t2.Update information of existing account\n";
    cout<<"\t\t3.For transactions\n";
    cout<<"\t\t4.Check the details of existing account\n";
    cout<<"\t\t5.For Transfer\n";
    cout<<"\t\t6.Exit\n\n\n\n\n\t\t Enter your choice:";
    cin>>choice;

    system("cls");
    switch(choice)
    {
        case 1:
				B.acc_write();
        		break;
        case 2:
				B.modify_account();
        		break;
    	case 3:
				B.deposit_withdraw();
        		break;
        case 4:
				B.search_rec();
        		break;
        case 5:
				B.transfer();
        		break;
        case 6:
				close();
        		break;
    }
    login_try:
    cout<<"\nEnter 1 for Main Menu , 2 for Previous Menu and"
			<<" 0 to Exit:";
    scanf("%d",&main_exit);
    if (main_exit==1)
    {
    	system("cls");
        main();
    }
    else if (main_exit==0)
    {
    	system("cls");
        close();
	}
	else if (main_exit == 2)
	{
		system("cls");
		employee();
	}
    else
    {
		printf("\nInvalid!");
        fordelay(1000000000);
        system("cls");
        goto login_try;
	}
}

int count(){
	int j=0;
	for(int i=0;i<30;i++){
		
		
		if(arr[i].next!=NULL){
			node2 *temp=arr[i].next;
			// cout<<temp->next2;
			while(temp!=NULL){
				j++;
				node3 *x=temp->next1;
				
					temp=temp->next2;
					

			}
			
		}
	}
	return j;
}

void swap(double &p,double &q){
    double temp=p;
    p=q;
    q=temp;

}

int partition (sort_arr arr[], int low, int high,int *p2) 
{ 
    double pivot = arr[high].amount; 
    int i = (low - 1);
     *p2=0;
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j].amount <= pivot) 
        { 
            i++; 
            swap(arr[i].amount, arr[j].amount); 
              
        } 
    } 
    swap(arr[i + 1].amount, arr[high].amount);
    
    for(int j=i+1;j>-1;j--){
        if(arr[j].amount!=pivot){
            *p2=j+1;
            break;
        }
    }
    
    return (i + 1); 
} 

void quickSort(sort_arr arr[], int low, int high) 
{ 
	
    if (low < high) 
    { 
        int part2;
        int part1;
        part1=partition(arr,low,high,&part2);  
        
        quickSort(arr, low, part2-1); 
        quickSort(arr, part1+1, high); 
    } 
}

int main()
{
	int ch, i;
	cout << "\n\n\n\n\n\t\t\t\tWelcome to our bank System";
	for(i=0;i<6;i++)
    {
        fordelay(100000000);
        printf(".");
    }
	menu:
	system("cls");
	system("color 4");
	cout<<"\t\t\t ---------------------"<<endl;
	cout<<"\t\t\t|     BANK OF INDIA   |"<<endl;
	cout<<"\t\t\t ---------------------"<<endl;
	system("color 3");
	cout<<"\n\n\t\t\t\t MENU\n";
	cout<<"\n\t\t1. Employee ";
	cout<<"\n\t\t2. Customer ";
	cout<<"\n\t\t3. Exit ";
	cout<<"\n\t\tEnter Your Choice: ";
	cin>>ch;
	Bank b;
	b.insert();
	
	
	switch(ch)
	{
		case 1: employee();
				break;
		case 2: customer();
				break;
		case 3: close();
				break;
		default :	cout<<"Invalid Input! Try Again...\n";
					fordelay(1000000000);
					goto menu;
	}
}

