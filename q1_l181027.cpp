#include<iostream>
#include"gitHubUser.h"


bool Comparison (gitHubUser u1, gitHubUser u2);   // comparing two member variables
 
void inputFromUser (gitHubUser* &arr, int &size);   // populating values of struct from user

bool exists(gitHubUser* arr, int size, string userName);    // to check if searched username exists

gitHubUser* searchUser ( gitHubUser* users, int size, string userName);   // function to search user

void printStruct1 (gitHubUser *ptr, int size);   // to print details of user

void printStruct2 (gitHubUser ptr);				// to print details of user which is searched


int main()

{
		
		gitHubUser *ptr1 = NULL;
		int size =0;

		inputFromUser(ptr1, size);  

		printStruct1(ptr1 , size);
		

		string username;

		cout<<"Enter username to search\n";
		cin>> username;

		gitHubUser *ptr2 = NULL;

		ptr2 = searchUser(ptr1, size, username);


		if( ptr2 != NULL)
		{
			printStruct2( *ptr2);
		}
		else
			cout<<"Error!\n";


			delete[] ptr1;  //deallocation
			ptr1 = NULL;








}

bool Comparison (gitHubUser u1, gitHubUser u2)
{

	if(u1.userName == u2.userName) //compares usernames
		return true;
	else
		return false;

	if(u1.email == u2.email)  //compares emails
		return true;
	else
		return false;
}



void inputFromUser (gitHubUser* &arr, int &size)
{

	cout<<"Enter number of Github Users\n";
	cin>> size;

	arr = new gitHubUser[size];

	for(int i = 0; i<size; i++)
	{
		cout<<"Enter First Name\n";
		cin >> arr[i].firstName;

		cout<<"Enter your Username\n";
		cin >> arr[i].userName;

		while (exists(arr, i, arr[i].userName))   //function call
		{
			cout<<"Username Taken!\nReenter: \n";
			cin >> arr[i].userName;
		}

		cout<<"Enter your password\n";
		cin >> arr[i].password;

		cout<<"Enter your email\n";
		cin >> arr[i].email;

		cout<<"Enter your folder number\n";
		cin >> arr[i].folderCount;

	}

}

bool exists(gitHubUser* arr, int size, string userName)
{
	for( int i=0; i < size; i++)
	{
		if( arr[i].userName == userName)
		{
			return true;
		}
		
	}
	
	return false;
}


gitHubUser* searchUser ( gitHubUser* users, int size, string userName)
{


	for( int i =0; i< size; i++)
	{
		if( users[i].userName == userName)
		{
			return users +i;
		}
		else
		{
			return NULL;
		}
	}

	}


void printStruct1 (gitHubUser *ptr, int size)
{

	for(int i =0; i <size; i++)
	{
		cout<<"\nFirst Name of user " << i+1 << " is: " << ptr[i].firstName <<endl;

		cout<<"\nUsername of user " << i+1 << " is: " << ptr[i].userName <<endl;

		cout<<"\nPassword of user " << i+1 << " is: " << ptr[i].password <<endl;

		cout<<"\nEmail of user " << i+1 << " is: " << ptr[i].email <<endl;

		cout<<"\nFolder Count of user " << i+1 << " is: " << ptr[i].folderCount <<endl<<endl;

	}
}

void printStruct2 (gitHubUser ptr)
{

		cout<<"\nFirst Name of user is: " << ptr.firstName <<endl;

		cout<<"\nUsername of user is: " << ptr.userName <<endl;

		cout<<"\nPassword of user is: " << ptr.password <<endl;

		cout<<"\nEmail of user is: " << ptr.email <<endl;

		cout<<"\nFolder Count of user is: " << ptr.folderCount <<endl<<endl;

}








