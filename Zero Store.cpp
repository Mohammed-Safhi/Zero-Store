#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include <cstring>
#include<stdlib.h> // this library is for changing the color only
using namespace std;
class file
{
public:
    file()
	{
    	ofstream fout;
        fout.open("faze.txt");
        fout<<"faze";
        fout.close();
    }
};
class earn
{
public:
    double profit;
    void show()
	{
		ifstream x("ooo.txt");
        if(!x)
        	cout<<"PROFIT = 0 ";
        else
		{
        	x>>profit;
        	cout<<"\nTOTAL STARTING PROFIT:  "<<profit<<endl;
        	x.close();
        }
        
    }

};
class product:public virtual earn
{
public:
    int q;
    char na[];
	char id[];
    double percost;
    double persell;
    double cost;
    double sell;
    void cal()
	{
		cost=percost*q;
        sell=persell*q;
        profit=profit +(sell-cost)*365;
	}
    void file();
    void get();

};
void product::get()
{
	int s;
	cout<<"\nHow many items you will add?: ";
	cin>>s;
	for(int i=0;i<s;i++)
	{
  		cout<<"\ninput item name(Note: Add the name without spacing): ";
  		cin>>na;
  		cout<<"\ninput item ID: ";
  		cin>>id;
  		cout<<"\ninput cost price of item: ";
  		cin>>percost;
  		cout<<"\ninput selling price of item: ";
  		cin>>persell;
  		cout<<"\ntotal item quantity: ";
  		cin>>q;
    	cal();
    	file();
	}
 
}
void product::file()
{
	char file[20];
	strcpy(file,id);
	strcat(file,".txt"); 
	ofstream f(file);
	f<< "\nitem name: "<<na<< "\nitem id: "<<id<<"\ncost price of item: " <<percost<<"\nselling price of item: "<<persell<<"\nquantity: "<<q<<"\n total cost: "<<cost<<"\nsell: "<<sell;
	f.close();
}

class staff:public virtual earn
{
    protected:
    double salary;
    char post[12];
    char empid[10];
    int postq;
    void cal()
    {
		profit=(profit-salary*postq)*12;
    }
    void getstaff();
    void file();
};
void staff::getstaff()
{
  	cout<<"\ninput salary: ";
  	cin>>salary;
  	cout<<"\ninput number of employees: ";
  	cin>>postq;
  	for(int i=0;i<postq;i++)
  	{
  		cout<<"input employee name: ";
  		cin>>post;
  		cout<<"\ninput employee ID: ";
  		cin>>empid;
  		cal();
  		file();
	}
}
void staff::file()
{  
	char file[20];
	strcpy(file,empid);
	strcat(file,".txt");
	ofstream f(file);
	f<< "\nnumber of working employees: "<<postq<< "\nemployee salary: "<<salary<< "\nemployee name: "<<post<<"\nemployee id: "<<empid;
	f.close();
}

class amount:public staff, public product
{
	public:
    void add();
    void update_item();
    void update_emp();
};
void amount::add()
{
	int ch;
	char name[20];
	while(1)
	{
		cout <<endl;
		cout<<"1.)Input for item"<<endl;
		cout<<"2.)Input for employee"<<endl;
		cout<<"3.)Exit"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		if(ch==1)
		{
			get();
			ofstream x("ooo.txt");
 			x<<profit;
 			x.close();
		}
		else if(ch==2)
		{
			getstaff();
			ofstream x("ooo.txt");
 			x<<profit;
 			x.close();
		}
		else if(ch==3)
		break;
		else
			cout<<"Invaid Option. Please re-enter\n";
	}
}

 
void amount::update_item()
{
	char id[20];
	char pid[20];
    char c;
    cout<<"\nInput item ID to modify: ";
    cin>>id;
    char file[20];
    char file2[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
    if(!fout)
    {
    	cout<<"file couldn't be opened. item ID not found. \n";
	}
	else 
	{
		cout<<"file found! \n"; 
    	cout<<"\nupdate item name: \n";
  		cin>>na;
 		cout<<"\nupdate percost of item: \n";
  		cin>>percost;
 		cout<<"\nupdate persell of item: \n";
  		cin>>persell;
 		cout<<"\nupdate total item quantity: \n";
 		cin>>q;
    	cost=percost*q;
    	sell=persell*q;
		profit=profit +(sell-cost)*365;
  		fout<<"\nitem name: "<<na<< "\nitem id: "<<id<<"\npercost of item: " <<percost<<"\npersell of item: "<<persell<<"\nquantity: "<<q<<"\n total cost: "<<cost<<"\nsell: "<<sell;
		fout.close();
	}	
}
void amount::update_emp()	
{
	char id[20];
    char c;
    cout<<"\nInput employee ID to modify: ";
    cin>>id;
    char file[20];
    strcpy(file,id);
    strcat(file,".txt");
    fstream fout(file, ios::in|ios::out);
    if(!fout)
    {								
    	cout<<"file couldn't be opened. item ID not found. \n";
	}
	cout<<"modify employee name: \n";
  	cin>>post;
  	fout<< "\nnumber of working employees: "<<postq<< "\nemployee salary: "<<salary<< "\nemployee name :"<<post<<"\nemployee id: "<<empid;
 	fout.close();
}
int main()
{
	while(1)
  	{
  		system("Color 71");
 		cout<<"\n\t\t\t=============================="<<endl;
		cout<<"\n\t\t\t     WELCOME TO THE ZERO  "<<endl;
		cout<<"\n\t\t\t==============================\n"<<endl;
 		cout<<"\n\t\t\t1. Add items or employee\n\n\t\t\t";
		cout<<"2. Show profit\n\n\t\t\t";
		cout<<"3. Search for the item Details\n\n\t\t\t";
		cout<<"4. Search for the employees Details\n\n\t\t\t";
		cout<<"5. Modify item Details\n\n\t\t\t";
		cout<<"6. Modify Employee Details\n\n\t\t\t";
		cout<<"7. Creators of this system\n\n\t\t\t";
		cout<<"8.Exit";
  		cout<<"\n\n\t\t\tSelect your choice: ";
  		int u;
  		cin>>u;
		if(u==1)
  		{
  			amount a;
  			a.show();
  			a.add();
		}
  		else if(u==2)
  		{
  			amount d;
  			d.show();
		}
  		else if(u==3)
  		{  
   			char id[20];
   			char c;
    		cout<<"\nIput ID to search:";
    		cin>>id;
    		char file[20];
    		strcpy(file,id);
    		strcat(file,".txt");
    		ifstream x(file);
    		if(!x)
    		{
    			cout<<"file couldn't be opened. product ID not found. \n";
			}
    		while(x)
    		{
				x.get(c);
     			cout<<c;
    		}
    		x.close();
		}	
   		else if(u==4)
  		{
   			char eid[20];
   			char d;
   			cout<<"\nInput employee ID to search:";
    		cin>>eid;
   			char file[20];
   			strcpy(file,eid);
   			strcat(file,".txt");
   			ifstream y(file);
   			if(!y)
    		{
    			cout<<"file couldn't be opened. employee ID not found. \n";
			}
   			while(y)
   			{
   				y.get(d);
   				cout<<d;
   			} 
   			y.close();
		}		
		else if(u==5)
		{
			amount u;
			u.update_item();
		}
 		else if(u==6)
 		{
 			amount v;
 			v.update_emp();
 		}
  		else if(u==7)
		{
  			cout<<"The people who made this system are college students and they are 5 students:"<<endl;
  			cout<<"1.Hasan Ali Alzayer 2200004553\t\t2.Mohammed Abdullah Safhi 2200003719"<<endl;
  			cout<<"3.Abdullah Adel Alsaleem 2200000627\t4.Abdurhaman Ahmed Alqahtani 2210040049"<<endl;
  			cout<<"5.Noah hussain alflaiw 2200002412"<<endl;
		} 
  		else if(u==8)
  		{
 			break;
 		}
  		else cout<<"Invalid option. Please select one of the available options\n";
 	}

    return 0;
}


