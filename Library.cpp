#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <iomanip>
#include <cstdio>
#include <fstream>

using namespace std;

class Book
{
	string bookid , bookname , authorname;
	//char bookid[6];
	//char bookname[50];
	//char authorname[20];

public:
	//Book();
	//~Book();

	void addbook()
	{
		cout << "\n New Book Entry...\n";
		cout << "\n Enter the Book Id..";
		getline(cin , bookid);
		cout << "\n Enter the Book Name..";
		getline(cin , bookname);
		cout << "\n Enter the Author Name..";
		getline(cin , authorname);

		cout << "\n\n\nBook Succesfully Added..";
	}

	void displaybook()
	{
		cout << "\nBook Id : " << bookid;
		cout << "\nBook Name : ";
		cout << bookname ;
		cout << "\nAuthor Name : ";
		cout << authorname ;
	}

	void modifybook()
	{
		cout << "\nBook ID : "<< bookid;
		cout << "\nModify Book Name : ";
		getline(cin , bookname);
		cout << "\nModify Author Name : ";
		getline(cin , authorname);
	}

	string getbookID()
	{
		return bookid;
	}

	void report()
	{
		cout << "\t" <<bookid << setw(40) << bookname << setw(40) << authorname << endl;
	}
	
};//Class Ends Here

class Student
{
	string studentid , studentname , studentbookid;
	//char studentid[6];
	//char studentname[20];
	//char studentbookid[6];
	int token;
public:
	//Student();
	//~Student();
	
	void addstudent()
	{
		system("cls");
		cout << "\nNew Student Entry..\n";
		cout << "\nEnter Student ID : ";
		getline(cin , studentid);
		cout << "\nEnter Student Name : ";
		getline(cin , studentname);
		token = 0;
		studentbookid.push_back('\0');

		cout << "\n\nStudent Record Created..";

	}

	void displaystudent()
	{
		cout << "\n\nStudent ID : "<<studentid;
		cout << "\nStudent Name : ";
		cout << studentname ;
		cout << "\nNo. of Book Issued : " << token;
		if(token == 1)
			cout << "\nBook ID : " << studentbookid;
	}

	void modifystudent()
	{
		cout << "\nStudent ID : "<<studentid;
		cout << "\nModify Student Name : ";
		getline(cin , studentname);

	}

	string getstudentID()
	{
		return studentid;
	}

	string getstudentbookID()
	{
		return studentbookid;
	}

	int getStudenttoken()
	{
		return token;
	}

	void addtoken()
	{
		token=1;
	}

	void resettoken()
	{
		token = 0;
	}

	void getstubookID(string t)
	{
		studentbookid = t;
	}

	void report()
	{
		cout << "\t" << studentid << setw(40) << studentname << setw(40) << token << endl;
	}
};//class ends here

fstream fp,fp1;
Book bk;
Student st;

void writebookdata()
{
	char ch;
	fp.open("book.txt",ios::app);
	do
	{
		system("cls");
		bk.addbook();
		fp.write((char*) &bk , sizeof(bk));
		cout << "\nDo you want to add more Books.. (y/n)?";
		ch = getch();
	}while(ch == 'y' || ch == 'Y');

	fp.close();
}

void writestudentdata()
{
	char ch;
	fp.open("student.txt",ios::app);
	do
	{
		system("cls");
		st.addstudent();
		fp.write((char*) &st , sizeof(st));
		cout << "\nDo you want to add more Students.. (y/n)?";
		ch = getch();
	}while(ch == 'y' || ch == 'Y');

	fp.close();
}

void displayspecificbook(string id)
{
	cout << "\nBook Details\n";
	int flag=0;

	fp.open("book.txt" , ios::in);
	while(fp.read((char*) &bk , sizeof(bk)))
	{
		if(id.compare(bk.getbookID()) == 0)
		{
			bk.displaybook();
			flag=1;
		}
	}

	fp.close();
	if(!flag)
	{
		cout << "\nBook Not Found!!";
		
	}
	getch();
}


void displayspecificstudent(string id)
{
	cout << "\nStudent Details\n";
	int flag=0;

	fp.open("student.txt" , ios::in);
	while(fp.read((char*) &st , sizeof(st)))
	{
		if(id.compare(st.getstudentID()) == 0)
		{
			st.displaystudent();
			flag=1;
		}
	}

	fp.close();
	if(!flag)
	{
		cout << "\nStudent Not Found!!";
		
	}
	getch();
}

void modifybook()
{
	string id;
	int found =0;
	system("cls");

	cout << "\n\nModify Book Record...";
	cout << "\n\nEnter the Book ID : ";
	getline(cin , id);

	fp.open("book.txt",ios::in|ios::out);
	while(fp.read((char*) &bk , sizeof(bk)) && found == 0)
	{
		if(id.compare(bk.getbookID()) == 0)
		{
			bk.displaybook();
			cout << "\n\nEnter the new Details"<<endl;
			bk.modifybook();
			int pos = -1 * sizeof(bk);
			fp.seekp(pos , ios::cur);
			fp.write((char*) &bk , sizeof(bk));
			cout << "\n\n\t Record Updated";

			found=1;
		}
	}

	fp.close();
	if(found == 0)
	{
		cout << "\n\nRecord Not Found"; 
	}

	getch();
}


void modifystudent()
{
	string id;
	int found =0;
	system("cls");

	cout << "\n\n\tModify Student Record...";
	cout << "\n\n\tEnter the Student ID : ";
	getline(cin , id);

	fp.open("student.txt",ios::in|ios::out);
	while(fp.read((char*) &st , sizeof(st)) && found == 0)
	{
		if(id.compare(st.getstudentID()) == 0)
		{
			st.displaystudent();
			cout << "\n\tEnter the new Details\n";
			st.modifystudent();
			int pos = -1 * sizeof(st);
			fp.seekp(pos , ios::cur);
			fp.write((char*) &st , sizeof(st));
			cout << "\n\n\t Record Updated";

			found=1;
		}
	}

	fp.close();
	if(found == 0)
	{
		cout << "\n\nRecord Not Found"; 
	}

	getch();
}

void deletestudent()
{
	string id;
	int flag=0;

	system("cls");
	cout << "\n\n\n\tDelete Student..";
	cout << "\n\nEnter Student Id : ";
	getline(cin , id);

	fp.open("student.txt" , ios::in | ios::out);
	fstream fp2;
	fp2.open("temp.txt" , ios::out);

	fp.seekg(0 , ios::beg);
	while(fp.read((char*) &st , sizeof(st)))
	{
		if(id.compare(st.getstudentID()) != 0)
		{
			fp2.write((char*) &st , sizeof(st));
		}

		else
		{
			flag=1;
		}
	}

	fp.close();
	fp2.close();

	remove("student.txt");
	rename("temp.txt" , "student.txt");
	if(flag == 1)
	{
		cout << "\n\nRecord Deleted";
	}

	else
	{
		cout << "Record Not Found";
	}
	getch();
}

void deletebook	()
{
	string id;
	int flag=0;

	system("cls");
	cout << "\n\n\n\tDelete Book..";
	cout << "\n\nEnter Book Id : ";
	getline(cin , id);

	fp.open("book.txt" , ios::in | ios::out);
	fstream fp2;
	fp2.open("temp.txt" , ios::out);

	fp.seekg(0 , ios::beg);
	while(fp.read((char*) &bk , sizeof(bk)))
	{
		if(id.compare(bk.getbookID()) != 0)
		{
			fp2.write((char*) &bk , sizeof(bk));
		}

		else
		{
			flag=1;
		}
	}

	fp.close();
	fp2.close();

	remove("book.txt");
	rename("temp.txt" , "book.txt");
	if(flag == 1)
	{
		cout << "\n\nRecord Deleted";
	}

	else
	{
		cout << "Record Not Found";
	}
	getch();
}

void displayallstudent()
{
	system("cls");
	fp.open("student.txt" , ios::in);
	if(!fp)
	{
		cout << "\n\nFile could not opened.";
		getch();
		return;
	}
	
	cout << "\n\n\tStudent List..\n\n";
	cout << "\t======================================================================================================\n";

	cout << "\n\tStudent ID" << setw(40) << "Student Name" << setw(40) << "Book Issued" << endl;
	cout << "\n\t====================================================================================================\n";

	while(fp.read((char*) &st , sizeof(st)))
	{
		st.report();
	}

	fp.close();
	getch();
}

void displayallbooks()
{
	system("cls");
	fp.open("book.txt" , ios::in);
	if(!fp)
	{
		cout << "\n\nFile could not opened.";
		getch();
		return;
	}
	
	cout << "\n\n\tBooks List\n\n";
	cout << "\t===================================================================================================\n";

	cout << "\tBook ID" << setw(40) << "Book Name" << setw(40) << "Book Author" << endl;
	cout << "\t===================================================================================================\n";

	while(fp.read((char*) &bk , sizeof(bk)))
	{
		bk.report();
	}

	fp.close();
	getch();
}

void bookissue()
{
	string bkid,stid;

	int found=0;
	int flag=0;

	system("cls");
	cout << "\n\n\tBook Issue";
	cout << "\n\n\tEnter Student ID : ";
	getline(cin , stid);

	fp.open("student.txt" , ios::in|ios::out);
	fp1.open("book.txt" ,  ios::in|ios::out);
	while(fp.read((char*) &st , sizeof(st)) && found==0)
	{
		if(stid.compare(st.getstudentID()) == 0)
		{
			found=1;

			if(st.getStudenttoken() == 0)
			{
				cout << "\n\n\tEnter the Book ID : ";
				getline(cin , bkid);

				while(fp1.read((char*) &bk , sizeof(bk)) && flag==0)
				{
					if(bkid.compare(bk.getbookID()) == 0)
					{
						flag=1;
						st.addtoken();
						st.getstubookID(bk.getbookID());

						int pos = -1*sizeof(st);
						fp.seekg(pos , ios::cur);
						fp.write((char*) &st, sizeof(st));

						cout << "\n\n\t Book Issued Succesfully.\n Please return with in fifteen days. Fine will be Rupees 1/Day if submit late";

					}
				}

				if(flag == 0)
				{
					cout << "\n\n\tBook Number Does not exist.";
				}
			}

			else
			{
				cout << "\n\n\tYou have not returned the last book.";
			}
		}
	}

	if(found == 0)
	{
		cout << "\n\n\tStudent Record Does not Exist.";
	}

	getch();
	fp.close();
	fp1.close();

}

void bookdeposit()
{
	string bkid,stid;

	int found=0;
	int flag=0;
	int day,fine=0;

	system("cls");
	cout << "\n\n\tBook Deposit";
	cout << "\n\n\tEnter Student ID : ";
	getline(cin , stid);

	fp.open("student.txt" , ios::in|ios::out);
	fp1.open("book.txt" ,  ios::in|ios::out);
	while(fp.read((char*) &st , sizeof(st)) && found==0)
	{
		if(stid.compare(st.getstudentID()) == 0)
		{
			found=1;

			if(st.getStudenttoken() == 1 )
			{
				
				while(fp1.read((char*) &bk , sizeof(bk)) && flag==0)
				{
					if((bk.getbookID()).compare(st.getstudentbookID()) == 0)
					{
						flag=1;
						bk.displaybook();
						cout << "\n\n\tBook Deposited in no.of days : ";
						cin >> day;

						if(day > 15)
						{
							fine = (day - 15)*1;
						}

						cout << "\n\n\tFine has to be deposited Rs." << fine;

						st.resettoken();

						int pos = -1*sizeof(st);
						fp.seekg(pos , ios::cur);
						fp.write((char*) &st, sizeof(st));

						cout << "\n\n\t Book Deposited Succesfully.";

					}
				}

				if(flag == 0)
				{
					cout << "\n\n\tBook ID Does not exist.";
				}
			}

			else
			{
				cout << "\n\n\tNo book is Issued.";
			}
		}
	}

	if(found == 0)
	{
		cout << "\n\n\tStudent Record Does not Exist.";
	}

	getch();
	fp.close();
	fp1.close();

}

void gotoxy(int x, int y) 
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void start()
{
	system("cls");
	gotoxy(35,11);
	cout << "Library";
	gotoxy(35,14);
	cout << "Management";
	gotoxy(35,17);
	cout << "System";
	cout << endl;

	cout << "Developer - dot_py";
	getch();
}

void adminMenu()
{
	system("cls");
	char ch2;
	cout << "\n\n\n\tAdmin Menu";
	cout << "\n\n\t1. Add Student Record";
	cout << "\n\n\t2. Display All Students Record";
	cout << "\n\n\t3. Display Specific Student Record";
	cout << "\n\n\t4. Modify Student Record";
	cout << "\n\n\t5. Delete Student Record";
	cout << "\n\n\t6. Add a Book";
	cout << "\n\n\t7. Display All Books";
	cout << "\n\n\t8. Display Specific Book";
	cout << "\n\n\t9. Modify Book Record";
	cout << "\n\n\td. Delete Book Record";
	cout << "\n\n\tr. Back to Main Menu"; 
	cout << "\n\n\tPlease Enter Your Choice";

	ch2 = getch();

	switch(ch2)
	{
		case '1':
		writestudentdata();
		break;

		case '2':
		displayallstudent();
		break;

		case '3':
		{
			string num;
			system("cls");
			cout << "\n\n\t Plese Enter User ID : ";
			cin >> num;
			displayspecificstudent(num);
		}
		
		break;

		case '4':
		modifystudent();
		break;

		case '5':
		deletestudent();
		break;

		case '6':
		writebookdata();
		break;

		case '7':
		displayallbooks();
		break;

		case '8':
		{
			string num;
			system("cls");
			cout << "\n\n\t Plese Enter the Book No.";
			cin >> num; 
			displayspecificbook(num);
		}
		
		break;

		case '9':
		modifybook();
		break;

		case 'd':
		deletebook();

		case 'r':
		return;

		default :
		cout << "Invalid Choice Try Again!!" ;

		adminMenu();
	}
}

int main()
{
	char ch;
	start();

	do{
		system("cls");
		cout << endl << endl << endl << "\t Main Menu";
		cout << endl << endl << endl << "\t1. Book Issue";
		cout << endl << endl << endl << "\t2. Book Deposit";
		cout << endl << endl << endl << "\t3. Admin Menu";
		cout << endl << endl << endl << "\t4. Exit";

		cout << endl << endl << endl << "Please Select b/w 1-4";

		ch = getch();
		switch(ch)
		{
			case '1': bookissue();
						break;

			case '2': bookdeposit();
						break;

			case '3': adminMenu();
						break;

			case '4': exit(0);
					  break;

			default : cout << "Invalid Input , Try Again!!";
		}
	}while(ch != '4');
}