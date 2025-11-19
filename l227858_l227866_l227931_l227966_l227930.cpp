#include <iostream>
#include <fstream>
#include<string>
#include<conio.h>
#include<dirent.h>
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void menu();
int common;
char back2 = 'y';
using namespace std;
int update = 0;
long long int gloisbn;
int update2 = 0;
int libtreasury = 0;
const int fineapplicable = 1000;
string code, title_2;
struct book {
	string isbn;
	string quantity;
	string title, author;
	string dop;

};
book booklist[10000];
book newlist[10000];

struct lendingbook {
	book issuedbook;
	string issuingdate, dateofreturn, nameofperson;
};
lendingbook lend[10000];
lendingbook lendlist[10000];
void sortbytitle(book arr[], int size) {
	book temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i].title > arr[j].title) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}
void sortbytitle_return(lendingbook arr[], int size) {
	lendingbook temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i].issuedbook.title > arr[j].issuedbook.title) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}
void sortbyisbn(book arr[], int size) {
	book temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i].isbn > arr[j].isbn) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}


}
void sortbyisbn_return(lendingbook arr[], int size) {
	lendingbook temp;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i].issuedbook.isbn > arr[j].issuedbook.isbn) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

}
int binarysearchbytitle(book arr[], string title) {
	int  first, last, middle;
	first = 0;
	last = update - 1;
	middle = (first + last) / 2;
	while (first <= last)
	{
		if (arr[middle].title < title)
			first = middle + 1;
		else if (arr[middle].title == title)
		{
			return middle;
		}
		else
			last = middle - 1;
		middle = (first + last) / 2;
	}
	if (first > last) {
		return -1;
	}
	cout << endl;
}
int binarysearchbytitle_return(lendingbook arr[], string title) {
	int  first, last, middle;
	first = 0;
	last = update2 - 1;
	middle = (first + last) / 2;
	while (first <= last)
	{
		if (arr[middle].issuedbook.title < title)
			first = middle + 1;
		else if (arr[middle].issuedbook.title == title)
		{
			return middle;
		}
		else
			last = middle - 1;
		middle = (first + last) / 2;
	}
	if (first > last) {
		return -1;
	}
	cout << endl;
}

int binarysearchbyisbn(book arr[], int isbn)
{
	int first = 0, last = update - 1, mid, mem;
	mid = (first + last) / 2;
	while (first <= last)
	{
		mid = (first + last) / 2;
		mem = stoll(arr[mid].isbn);
		if (mem == isbn)
		{
			return  mid;
		}
		else if (mem >= isbn)
		{
			last = mid - 1;
		}
		else
		{
			first = mid + 1;
		}
	}
	if (first > last) {
		return -1;
	}
	cout << endl;
}

int binarysearchbyisbn_return(lendingbook arr[], int isbn)
{
	int first = 0, last = update2 - 1, mid, mem;
	mid = (first + last) / 2;

	while (first <= last)
	{
		mid = (first + last) / 2;
		mem = stoll(arr[mid].issuedbook.isbn);
		if (mem == isbn)
		{
			return  mid;
		}
		else if (mem >= isbn)
		{
			last = mid - 1;
		}
		else
		{
			first = mid + 1;
		}
	}
	if (first > last) {
		return -1;
	}
	cout << endl;
}
int sto(book arr[], int size) {
	int num = stoi(arr[size].quantity);
	return  num;
}
void display() {
	char y = 'y';
	while (y == 'y' || y == 'Y') {
		cout << "\n\n";
		SetConsoleTextAttribute(h, 4);
		cout << "Enter the details to add a book" << endl << endl;
		SetConsoleTextAttribute(h, 7);
		ofstream bookdet;
		cout << "\t\tEnter the title of book\t\t\t::";
		cin.ignore();
		getline(cin, booklist[update].title);
		bookdet.open("books\\" + booklist[update].title + ".txt",ios::app);
		bookdet << booklist[update].title << ",";
		cout << "\t\tEnter the ISBN of book: \n(NOTE: ISBN should be more than 4 digits!!)\t\t::";
		cin >> booklist[update].isbn;
		while (stoll(booklist[update].isbn) < 1000) {
			if (stoll(booklist[update].isbn) < 1000) {
				SetConsoleTextAttribute(h, 5);
				cout << "Warning::";
				cout << "\t\tISBN should be more than 4 digits!! Enter again::" << endl;
				SetConsoleTextAttribute(h, 7);
				cin >> booklist[update].isbn;
			}
		}
		bookdet << booklist[update].isbn << ",";
		cout << "\t\tEnter the name of author of the book    :: ";
		cin.ignore();
		getline(cin, booklist[update].author);
		bookdet << booklist[update].author << ",";
		cout << "\t\tEnter the date of publishing of the book: \nNote: Example (DD/MM/YYYY)\t\t\t\t::";
		getline(cin, booklist[update].dop);
		bookdet << booklist[update].dop << ",";
		cout << "\t\tEnter the quantity of the book\t\t::";
		cin >> booklist[update].quantity;
		int num = stoi(booklist[update].quantity);

		while (num <= 0)
		{
			SetConsoleTextAttribute(h, 5);
			cout << "Warning::";
			cout << "Enter a valid quantity :: ";
			SetConsoleTextAttribute(h, 7);
			cin >> booklist[update].quantity;
			num = stoi(booklist[update].quantity);
			cout << endl;
		}
		bookdet << booklist[update].quantity << '\n';
		update++;
		bookdet.close();
		cout << endl << endl;
		cout << "Enter 'y' if you want to add another book: ";
		cin >> y;
		system("CLS");
		cout << endl << endl;
	}
	cout << "Enter any key to return to menu!! " << endl;
	char ch = _getch();
	system("CLS");
	menu();
}//done
void registered() {
	string username, password;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter Password ";
	cin >> password;
	ofstream reg;
	reg.open(username + ".txt");
	reg << username << endl;
	reg << password;
	reg.close();
}
bool loggedin() {
	string username, password, user, pass;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;
	ifstream log;
	log.open(username + ".txt");
	getline(log, user);
	getline(log, pass);
	if (user == username && pass == password) {
		return true;
	}
	else {
		return false;
	}
	log.close();

}
void showMenu()
{
	cout << "\n\n\t\t*****************************************************\n";
	cout << "\t\t**************** ";
	SetConsoleTextAttribute(h, 1);
	cout << "Menu of the library";
	SetConsoleTextAttribute(h, 7);
	cout << " ****************";
	cout << "\n\t\t*****************************************************\n";
	cout << endl << endl;
	SetConsoleTextAttribute(h, 23);
	cout << "\t\t\t1. Add Book             " << endl;
	cout << "\t\t\t2. Search Book          " << endl;
	cout << "\t\t\t3. Lend Book            " << endl;
	cout << "\t\t\t4. Return Book          " << endl;
	cout << "\t\t\t5. Delete Book          " << endl;
	cout << "\t\t\t6. Library Treasury     " << endl;
	cout << "\t\t\t7. Show Available books " << endl;
	cout << "\t\t\t8. Show Lended books    " << endl;
	cout << "\t\t\t9. Exit                 " << endl;
	cout << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 7);
	cout << "Enter your choice: ";
}
void addbook() {
	system("CLS");
	display();
}
int searchbook() {
	system("CLS");
	SetConsoleTextAttribute(h, 1);
	cout << "\t   ::Enter the details required to search the book::" << endl << endl << endl;
	SetConsoleTextAttribute(h, 7);
	int choice = 0, bookcheck;
	long long int isbn_num;
	SetConsoleTextAttribute(h, 4);
	cout << "\t\tPress 1. for search by title\n\t\tPress 2. for search by ISBN" << endl;
	SetConsoleTextAttribute(h, 7);
	cout << "Enter your choice: ";
	cin >> common;
	cout << endl;
	if (common == 1) {
		cout << "\tEnter the title of the book: ";
		cin.ignore();
		getline(cin, title_2);
		sortbytitle(booklist, update);
		bookcheck = binarysearchbytitle(booklist, title_2);
		if (bookcheck != -1) {
			SetConsoleTextAttribute(h, 3);
			cout << "\t\t\t<<Book found!>>" << endl << endl;
			SetConsoleTextAttribute(h, 7);
			cout << "\t**********";
			SetConsoleTextAttribute(h, 3);
			cout << "Found Book details are";
			SetConsoleTextAttribute(h, 7);
			cout << " *************" << endl << endl;
			cout << "\t       Title of book is                   : " << booklist[bookcheck].title << endl;
			cout << "\t     ISBN number of book is               : " << booklist[bookcheck].isbn << endl;
			cout << "\t      Author of the book is               : " << booklist[bookcheck].author << endl;
			cout << "\t   Date of publication of book is         : " << booklist[bookcheck].dop << endl;
			cout << "\tQuantity of book availaible in library is : " << booklist[bookcheck].quantity << endl;

			return bookcheck;
		}
		else {
			return -1;

		}
	}
	else if (common == 2) {
		cout << "\tEnter the ISBN number of the book: ";
		cin >> isbn_num;
		sortbyisbn(booklist, update);
		bookcheck = binarysearchbyisbn(booklist, isbn_num);
		if (bookcheck != -1) {
			SetConsoleTextAttribute(h, 3);
			cout << "\t\t\t<<Book found!>>" << endl << endl;
			SetConsoleTextAttribute(h, 7);
			cout << "\t**********";
			SetConsoleTextAttribute(h, 3);
			cout << "Found Book details are";
			SetConsoleTextAttribute(h, 7);
			cout << " *************" << endl << endl;
			cout << "\t          Title of book is                : " << booklist[bookcheck].title << endl;
			cout << "\t        ISBN number of book is            : " << booklist[bookcheck].isbn << endl;
			cout << "\t         Author of the book is            : " << booklist[bookcheck].author << endl;
			cout << "\t     Date of publication of book is       : " << booklist[bookcheck].dop << endl;
			cout << "\tQuantity of book availaible in library is : " << booklist[bookcheck].quantity << endl;
			return bookcheck;
		}
		else {

			return -1;

		}
	}
	else {
		cout << endl << endl;
		SetConsoleTextAttribute(h, 5);
		cout << "Warning::\n";
		cout << "Enter a valid choice!!! " << endl << endl;
		SetConsoleTextAttribute(h, 7);
		return -2;

	}

}
int searchbook2title() {

	int  bookcheck;
	sortbytitle(booklist, update);
	bookcheck = binarysearchbytitle(booklist, code);
	if (bookcheck != -1) {

		return bookcheck;
	}
	else {

		return -1;

	}
}
int searchbook2isbn() {
	int bookcheck;
	sortbyisbn(booklist, update);
	bookcheck = binarysearchbyisbn(booklist, gloisbn);
	if (bookcheck != -1) {

		return bookcheck;
	}
	else {

		return -1;

	}

}
int searchbook_returnbytitle() {
	int  bookcheck;
	cout << "Enter the title of the book: ";
	cin.ignore();
	getline(cin, code);
	sortbytitle_return(lend, update2);
	bookcheck = binarysearchbytitle_return(lend, code);
	if (bookcheck != -1) {

		cout << "Book found in the lending folder!" << endl;
		return bookcheck;
	}
	else {

		return -1;

	}
}
int searchbook_returnbyisbn() {
	int bookcheck;
	cout << "Enter the ISBN number of the book: ";
	cin >> gloisbn;
	sortbyisbn_return(lend, update2);
	bookcheck = binarysearchbyisbn_return(lend, gloisbn);
	if (bookcheck != -1) {
		cout << "Book found! " << endl;
		return bookcheck;
	}
	else {
		return -1;

	}

}
void load_data() {
	DIR* directory;
	struct dirent* point;
	directory = opendir("books");
	string filename;
	if (directory) {
		while ((point = readdir(directory)) != NULL) {
			filename = "books\\";
			if (!strcmp(point->d_name, ".") || !strcmp(point->d_name, "..")) {
				continue;
			}
			else
			{
				filename = filename + point->d_name;

				ifstream get_lines;
				get_lines.open(filename);
				string temp;
				int temp_var = 0;
				while (getline(get_lines, temp))
				{

					temp_var++;
				}
			
				get_lines.close();
				ifstream book_file;
				book_file.open(filename);
				for (int i = 0; i < temp_var; i++) {
					getline(book_file, booklist[update].title, ',');
					getline(book_file, booklist[update].isbn, ',');
					getline(book_file, booklist[update].author, ',');
					getline(book_file, booklist[update].dop, ',');
					getline(book_file, booklist[update].quantity, '\n');
					update++;
				}
				book_file.close();
				
			}
		}
		closedir(directory);
	}
	directory = opendir("lend");
	if (directory) {
		while ((point = readdir(directory)) != NULL) {
			filename = "lend\\";
			if (!strcmp(point->d_name, ".") || !strcmp(point->d_name, "..")) {
				continue;
			}
			else
			{
				filename = filename + point->d_name;

				ifstream get_lines;
				get_lines.open(filename);
				string temp;
				int temp_var = 0;
				
				while (getline(get_lines, temp))
				{

					temp_var++;
				}
				
				get_lines.close();
				ifstream book_file;
				book_file.open(filename);
				for (int i = 0; i < temp_var; i++) {
					getline(book_file, lend[update2].issuedbook.title, ',');
					getline(book_file, lend[update2].issuedbook.isbn, ',');
					getline(book_file, lend[update2].issuedbook.author, ',');
					getline(book_file, lend[update2].issuedbook.dop, ',');
					getline(book_file, lend[update2].issuedbook.quantity, ',');
					getline(book_file, lend[update2].issuingdate, ',');
					getline(book_file, lend[update2].dateofreturn, ',');
					getline(book_file, lend[update2].nameofperson, '\n');
					update2++;
				}
				book_file.close();
				
			}
		}
		closedir(directory); //close all directory
	}
	ifstream book_file;
	int treasury=0;
	book_file.open("treasury\\treasury.txt");
	book_file >> treasury;
	libtreasury = treasury;
	book_file.close();

}
void loaddata_return() {
	DIR* directory;
	struct dirent* point;
	directory = opendir("books");
	string filename;
	if (directory) {
		while ((point = readdir(directory)) != NULL) {
			filename = "books\\";
			if (!strcmp(point->d_name, ".") || !strcmp(point->d_name, "..")) {
				continue;
			}
			else
			{
				filename = filename + point->d_name;

				ifstream get_lines;
				get_lines.open(filename);
				string temp;
				int temp_var = 0;
				while (getline(get_lines, temp))
				{

					temp_var++;
				}

				get_lines.close();
				ifstream book_file;
				book_file.open(filename);
				for (int i = 0; i < temp_var; i++) {
					getline(book_file, booklist[update].title, ',');
					getline(book_file, booklist[update].isbn, ',');
					getline(book_file, booklist[update].author, ',');
					getline(book_file, booklist[update].dop, ',');
					getline(book_file, booklist[update].quantity, '\n');
					update++;
				}
				book_file.close();

			}
		}
		closedir(directory);
	}
}
void transferdata() {
	DIR* dr;
	struct dirent* en;
	dr = opendir("books"); //open all or present directory
	if (dr) {
		while ((en = readdir(dr)) != NULL) {
			char filename[100] = { 'b','o','o','k','s', '\\', '\\' };
			if (!strcmp(en->d_name, ".") || !strcmp(en->d_name, "..")) {
				continue;
			}
			else
			{
				strcat_s(filename, en->d_name);

				remove(filename);
			}
		}
	}
	for (int i = 0; i < update; i++)
	{
		ofstream write;
		write.open("books\\" + booklist[i].title + ".txt");
		write << booklist[i].title << ",";
		write << booklist[i].isbn << ",";
		write << booklist[i].author << ",";
		write << booklist[i].dop << ",";
		write << booklist[i].quantity << "\n";

		write.close();
	}
}
void transferdata_return() {
	DIR* dr;
	struct dirent* en;
	dr = opendir("lend"); //open all or present directory
	if (dr) {
		while ((en = readdir(dr)) != NULL) {
			char filename[100] = { 'l','e','n','d', '\\', '\\' };
			if (!strcmp(en->d_name, ".") || !strcmp(en->d_name, "..")) {
				continue;
			}
			else
			{
				strcat_s(filename, en->d_name);

				remove(filename);
			}

		}
	}
	for (int i = 0; i < update2; i++)
	{
		ofstream write;
		write.open("lend\\" + lend[i].issuedbook.title + ".txt");
		write << lend[i].issuedbook.title << ",";
		write << lend[i].issuedbook.isbn << ",";
		write << lend[i].issuedbook.author << ",";
		write << lend[i].issuedbook.dop << ",";
		write << lend[i].issuedbook.quantity << ",";
		write << lend[i].issuingdate << ",";
		write << lend[i].dateofreturn << ",";
		write << lend[i].nameofperson << "\n";

		write.close();
	}
}
void returnbook() {
	system("CLS");
	SetConsoleTextAttribute(h, 1);
	cout << "\n\t\t<<Enter the details to return book>>\n\n";
	int choice = 0, search, search2, num, num2, j = 0;
	SetConsoleTextAttribute(h, 6);
	cout << "Press 1. for return by title of the book:\nPress 2. for return by isbn number of the book: ";
	SetConsoleTextAttribute(h, 7);
	cout << "\nEnter your choice: ";
	cin >> common;
	cout << endl << endl;
	if (common == 1) {
		search = searchbook_returnbytitle();
		if (search != -1) {
			cout << endl << endl;
			SetConsoleTextAttribute(h, 6);
			cout << "Press 1. If you are returning the book late\nPress 2. If not ";
			SetConsoleTextAttribute(h, 7);
			cout << "\nEnter your choice:";
			while (choice != 1 && choice != 2) {
				cin >> choice;
				cout << endl << endl;
				if (choice == 1) {
					cout << "You have been fined 1000 Rs/- for a late return! " << endl;
					libtreasury = libtreasury + 1000;
					ofstream write;
					write.open("treasury\\treasury.txt");
					write << libtreasury;
					write.close();
					search2 = searchbook2title();
					if (search2 != -1) {
						num2 = stoi(booklist[search2].quantity) + 1;
						booklist[search2].quantity = to_string(num2);
						transferdata();
						SetConsoleTextAttribute(h, 4);
						cout << "Thanks For coming! " << endl;
						SetConsoleTextAttribute(h, 7);
					}

					else {
						ofstream write;
						write.open("books\\" + lend[search].issuedbook.title + ".txt");
						write << lend[search].issuedbook.title << ",";
						write << lend[search].issuedbook.isbn << ",";
						write << lend[search].issuedbook.author << ",";
						write << lend[search].issuedbook.dop << ",";
						write << "1" << "\n";
						write.close();
						loaddata_return();
						SetConsoleTextAttribute(h, 4);
						cout << "Thanks For Coming! " << endl;
						SetConsoleTextAttribute(h, 7);
					}


					num = stoi(lend[search].issuedbook.quantity) - 1;
					lend[search].issuedbook.quantity = to_string(num);
					for (int i = 0; i < update2; i++)
					{
						if (i == search) {
							continue;
						}
						else {
							lendlist[j] = lend[i];
							j++;
						}
					}
					
					update2--;
					for (int i = 0; i < update2; i++)
					{
						lend[i] = lendlist[i];
					}
				
					transferdata_return();
					

				}
				else if (choice == 2) {
					SetConsoleTextAttribute(h, 4);
					cout << "Thank You! for returning the book! "<<endl<<endl;
					SetConsoleTextAttribute(h, 7);
					search2 = searchbook2title();
					if (search2 != -1) {
						num2 = stoi(booklist[search2].quantity) + 1;
						booklist[search2].quantity = to_string(num2);
						transferdata();
						SetConsoleTextAttribute(h, 4);
						cout << "Thanks For Coming! " << endl;
						SetConsoleTextAttribute(h, 7);
					}

					else {
						ofstream write;
						write.open("books\\" + lend[search].issuedbook.title + ".txt");
						write << lend[search].issuedbook.title << ",";
						write << lend[search].issuedbook.isbn << ",";
						write << lend[search].issuedbook.author << ",";
						write << lend[search].issuedbook.dop << ",";
						write << "1" << "\n";
						write.close();
						loaddata_return();
						SetConsoleTextAttribute(h, 4);
						cout << "Thanks For Coming! " << endl;
						SetConsoleTextAttribute(h, 7);
					}
					int num = stoi(lend[search].issuedbook.quantity) - 1;
					lend[search].issuedbook.quantity = to_string(num);
					for (int i = 0; i < update2; i++)
					{
						if (i == search) {
							continue;
						}
						else {
							lendlist[j] = lend[i];
							j++;
						}
					}
					update2--;
					for (int i = 0; i < update2; i++)
					{
						lend[i] = lendlist[i];
					}
					transferdata_return();
					
				}
			}
		}
		else {
			SetConsoleTextAttribute(h, 4);
			cout << "Book not found in the lending folder!\nAs you have not lended any book " << endl;
			SetConsoleTextAttribute(h, 7);
		}
	}
	else if (common == 2) {
		search = searchbook_returnbyisbn();
		if (search != -1) {
			cout << endl << endl;
			SetConsoleTextAttribute(h, 6);
			cout << "Press 1. If you are returning the book late\nPress 2. If not ";
			SetConsoleTextAttribute(h, 7);
			cout << "\nEnter your choice:";
			while (choice != 1 && choice != 2) {
				cin >> choice;
				if (choice == 1) {
					cout << "You have been fined 1000 Rs/- for a late return! " << endl;
					libtreasury = libtreasury + 1000;
					ofstream write;
					write.open("treasury\\treasury.txt");
					write << libtreasury;
					write.close();
					search2 = searchbook2isbn();
					if (search2 != -1) {
						int num2 = stoi(booklist[search2].quantity) + 1;
						booklist[search2].quantity = to_string(num2);
						transferdata();
						SetConsoleTextAttribute(h, 4);
						cout << "Thanks For Coming! " << endl;
						SetConsoleTextAttribute(h, 7);
					}

					else {
						ofstream write;
						write.open("books\\" + lend[search].issuedbook.title + ".txt");
						write << lend[search].issuedbook.title << ",";
						write << lend[search].issuedbook.isbn << ",";
						write << lend[search].issuedbook.author << ",";
						write << lend[search].issuedbook.dop << ",";
						write << "1" << "\n";
						write.close();
						loaddata_return();
						SetConsoleTextAttribute(h, 4);
						cout << "Thanks For Coming! " << endl;
						SetConsoleTextAttribute(h, 7);
					}
					int num = stoi(lend[search].issuedbook.quantity) - 1;
					lend[search].issuedbook.quantity = to_string(num);
					for (int i = 0; i < update2; i++)
					{
						if (i == search) {
							continue;
						}
						else {
							lendlist[j] = lend[i];
							j++;
						}
					}
					update2--;
					for (int i = 0; i < update2; i++)
					{
						lend[i] = lendlist[i];
					}
					transferdata_return();
					
				}
				else if (choice == 2) {
					SetConsoleTextAttribute(h, 4);
					cout << "Thank You! for returning the book! "<<endl<<endl;
					SetConsoleTextAttribute(h, 7);
					search2 = searchbook2isbn();
					if (search2 != -1) {
						num2 = stoi(booklist[search2].quantity) + 1;
						booklist[search2].quantity = to_string(num2);
						transferdata();
						SetConsoleTextAttribute(h, 4);
						cout << "Thanks For Coming! " << endl;
						SetConsoleTextAttribute(h, 7);
						
					}

					else {
						ofstream write;
						write.open("books\\" + lend[search].issuedbook.title + ".txt");
						write << lend[search].issuedbook.title << ",";
						write << lend[search].issuedbook.isbn << ",";
						write << lend[search].issuedbook.author << ",";
						write << lend[search].issuedbook.dop << ",";
						write << "1" << "\n";
						write.close();
						loaddata_return();
						SetConsoleTextAttribute(h, 4);
						cout << "Thanks For Coming! " << endl;
						SetConsoleTextAttribute(h, 7);
					}
					int num = stoi(lend[search].issuedbook.quantity) - 1;
					lend[search].issuedbook.quantity = to_string(num);
					for (int i = 0; i < update2; i++)
					{
						if (i == search) {
							continue;
						}
						else {
							lendlist[j] = lend[i];
							j++;
						}
					}
					update2--;
					for (int i = 0; i < update2; i++)
					{
						lend[i] = lendlist[i];
					}
					transferdata_return();
					
				}
				else {
					SetConsoleTextAttribute(h, 3);
					cout << "Warning::";
					cout << "Please Enter a valid Choice! ";
					SetConsoleTextAttribute(h, 7);
				}
			}
		}
		else {
			SetConsoleTextAttribute(h, 4);
			cout << "Book not found in the lending folder!\nAs you have not lended any book " << endl;
			SetConsoleTextAttribute(h, 7);
		}
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "Invalid choice! ";
		SetConsoleTextAttribute(h, 7);
	}
}
void lendbook() {
	int details,j=0;
	int toint;
	details = searchbook();
	cout << endl << endl;
	if (details != -1&&details!=-2) {
		toint = sto(booklist, details);
		if (toint != 0) {
			ofstream lendwrite;
			lendwrite.open("lend\\" + booklist[details].title + ".txt",ios::app);
			lend[update2].issuingdate = "26/11/2022";
			lend[update2].dateofreturn = "3/12/2022";
			lend[update2].issuedbook.title = booklist[details].title;
			lend[update2].issuedbook.isbn = booklist[details].isbn;
			lend[update2].issuedbook.author = booklist[details].author;
			lend[update2].issuedbook.dop = booklist[details].dop;
			lend[update2].issuedbook.quantity = '1';
			lendwrite << lend[update2].issuedbook.title << ",";
			lendwrite << lend[update2].issuedbook.isbn << ",";
			lendwrite << lend[update2].issuedbook.author << ",";
			lendwrite << lend[update2].issuedbook.dop << ",";
			cout << "\tQuantity of the book being lended:  " << lend[update2].issuedbook.quantity << endl;
			lendwrite << lend[update2].issuedbook.quantity << ",";
			cout << "\tEnter your name: ";
			cin >> lend[update2].nameofperson;
			cout << endl << endl;
			cout << "\tIssuee date is: " << lend[update2].issuingdate << endl;
			lendwrite << lend[update2].issuingdate << ",";
			cout << "\tDate of return will be 7 days from issuing date: " << lend[update2].dateofreturn << endl;
			lendwrite << lend[update2].dateofreturn << ",";
			SetConsoleTextAttribute(h, 4);
			cout << "\n";
			cout << "\t     Book Issued Successfully!! " << endl << endl;
			cout << "\tFine applicable for late return will be  " << fineapplicable << " Rs/-" << endl;
			SetConsoleTextAttribute(h, 7);
			lendwrite << lend[update2].nameofperson << '\n';
			update2++;
			
			lendwrite.close();
			int overwrite = stoi(booklist[details].quantity) - 1;
			booklist[details].quantity = to_string(overwrite);
			if (stoi(booklist[details].quantity) == 0) {
				for (int i = 0; i < update; i++)
				{
					if (i == details) {
						continue;
					}
					else {
						newlist[j] = booklist[i];
						j++;
					}
				}
				update--;
				for (int i = 0; i < update; i++)
				{
					booklist[i] = newlist[i];
				}
			}
			transferdata();
		}
		else {
			cout << endl << endl;
			cout << "Quantity is zero Cannot issue a book!!" << endl << endl;
		}
	}
	else if(details==-1) {
		cout << "Book not Found !! " << endl<<endl;
	}
	else {
		cout << "Invalid Choice!! " << endl << endl;
	}
}
void deletebook() {

	cout << endl << endl;
	int search = 0, num, j = 0;
	cout << " Select Book You want to delete: " << endl;
	search = searchbook();
	if (search != -1 && search != -2) {
		SetConsoleTextAttribute(h, 3);
		cout << "Press 1. To Confirm\nPress 2. Return to menu ";
		SetConsoleTextAttribute(h, 7);
		cout << "\nEnter your choice:";
		cin >> common;
		if (common == 1) {
			if (stoi(booklist[search].quantity) != 0) {
				num = stoi(booklist[search].quantity) - 1;
				booklist[search].quantity = to_string(num);
				if (num == 0) {
					for (int i = 0; i < update; i++)
					{
						if (i == search) {
							continue;
						}
						else {
							newlist[j] = booklist[i];
							j++;
						}
					}
					update--;
					for (int i = 0; i < update; i++)
					{
						booklist[i] = newlist[i];
					}
				}
				transferdata();
			}
			else {
				for (int i = 0; i < update; i++)
				{
					if (i == search) {
						continue;
					}
					else {
						newlist[j] = booklist[i];
						j++;
					}
				}
				update--;
				for (int i = 0; i < update; i++)
				{
					booklist[i] = newlist[i];
				}
				transferdata();
			}
			SetConsoleTextAttribute(h, 4);
			cout << endl << endl;
			cout << "\t\t****Book Deleted From Library Successfully!****" << endl << endl;
			SetConsoleTextAttribute(h, 7);
		}

	}
	else if (search != -2) {
		SetConsoleTextAttribute(h, 4);
		cout << "\n\n";
		cout << "\t\t Book not found! " << endl;
		SetConsoleTextAttribute(h, 7);
	}

}
void treasury() {
	system("CLS");
	cout << endl << endl;
	cout << "\t\t***************";
	SetConsoleTextAttribute(h, 1);
	cout << "Total amount in the Library Treasury is";
	SetConsoleTextAttribute(h, 7);
	cout << "***************";
	cout << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 47);
	cout << "\t\t\t" << libtreasury << "Rs/- " << endl;
	SetConsoleTextAttribute(h, 7);
}
void showbooks() {
	system("CLS");
	int j = 1;
	DIR* directory;
	struct dirent* point;
	directory = opendir("books"); //open all or present directory
	string filename, file;
	cout << endl << endl;
	cout << "\t\t***********";
	SetConsoleTextAttribute(h, 3);
	cout << "Books availaible in the library are";
	SetConsoleTextAttribute(h, 7);
	cout << " ***********" << endl << endl;
	if (directory) {
		while ((point = readdir(directory)) != NULL) {
			filename = "books\\";
			if (!strcmp(point->d_name, ".") || !strcmp(point->d_name, "..")) {
				continue;
			}
			else {
				file = point->d_name;
				cout << "\t" << j << ". ";
				for (int i = 0; file[i] != '.'; i++)
				{
					cout << file[i];
				}
				cout << endl;

				j++;
			}
		}
	}

}
void lend_books() {
	system("CLS");
	int j = 1;
	DIR* directory;
	struct dirent* point;
	directory = opendir("lend"); //open all or present directory
	string filename, file;
	cout << endl << endl;
	cout << "\t\t***********";
	SetConsoleTextAttribute(h, 3);
	cout << "Lended Books are:";
	SetConsoleTextAttribute(h, 7);
	cout << "*********** " << endl << endl;
	if (directory) {
		while ((point = readdir(directory)) != NULL) {
			filename = "lend\\";
			if (!strcmp(point->d_name, ".") || !strcmp(point->d_name, "..")) {
				continue;
			}
			else {
				file = point->d_name;
				cout << "\t" << j << ". ";
				for (int i = 0; file[i] != '.'; i++)
				{
					cout << file[i];
				}
				cout << endl;

				j++;
			}
		}
	}
}
void exit_func()
{
	cout << "\n\t\t::";
	SetConsoleTextAttribute(h, 4);
	cout << "GOOD BYE";
	SetConsoleTextAttribute(h, 7);
	cout << "::\n";
	cout << "\t      <All Data Saved>";
	cout << endl << endl;
	exit(0);

}
void menu() {
	int choice_menu, back;
	showMenu();
	cin >> choice_menu;
	while (choice_menu <= 0 || choice_menu > 9)
	{
		cout << "Enter a valid choice!! " << endl << endl;
		cout << "Enter Choice: ";
		cin >> choice_menu;
	}
	if (choice_menu == 1) {
		addbook();
		system("CLS");
	}
	else if (choice_menu == 2) {
		while (back2 == 'y' || back2 == 'Y') {
			back = searchbook();
			if (back == -1) {
				SetConsoleTextAttribute(h, 6);
				cout << "\t\t<<Book not found!!>> ";
				SetConsoleTextAttribute(h, 7);
			}
			cout << endl << endl;
			cout << "Press 'y' to search another book!! " << endl;
			cin >> back2;
		}
		back2 = 'y';

		cout << "Enter any key to return to menu!! " << endl;
		char ch = _getch();
		system("CLS");
		menu();

	}
	else if (choice_menu == 3) {
		cout << endl << endl;
		while (back2 == 'y' || back2 == 'Y') {
			lendbook();
			cout << "Press 'y' to lend another book!! " << endl;
			cin >> back2;
		}
		back2 = 'y';
		cout << "Enter any key to return to menu!! " << endl;
		char ch = _getch();
		system("CLS");
		menu();

	}
	else if (choice_menu == 4) {
		system("CLS");
		while (back2 == 'y' || back2 == 'Y') {
			returnbook();
			cout << endl << endl;

			cout << "Press 'y' to return another book!! " << endl;
			cin >> back2;
		}
		back2 = 'y';
		cout << "Enter any key to return to menu!! " << endl;
		char ch = _getch();
		system("CLS");
		menu();

	}
	else if (choice_menu == 5) {
		system("CLS");
		while (back2 == 'y' || back2 == 'Y') {
			deletebook();
			cout << endl << endl;

			cout << "Press 'y' to delete another book!! " << endl;
			cin >> back2;
		}
		back2 = 'y';
		cout << "Enter any key to return to menu!! " << endl;
		char ch = _getch();
		system("CLS");
		menu();

	}
	else if (choice_menu == 6) {
		system("CLS");
		while (back2 == 'y' || back2 == 'Y') {
			treasury();
			cout << endl << endl;

			cout << "Press 'y' to check treasury again!! " << endl;
			cin >> back2;
		}
		back2 = 'y';
		cout << "Enter any key to return to menu!! " << endl;
		char ch = _getch();
		system("CLS");
		menu();


	}
	else if (choice_menu == 7) {
		system("CLS");
		while (back2 == 'y' || back2 == 'Y') {
			showbooks();
			cout << endl << endl;

			cout << "Press 'y' to check books again!! " << endl;
			cin >> back2;

		}
		back2 = 'y';
		cout << "Enter any key to return to menu!! " << endl;
		char ch = _getch();
		system("CLS");
		menu();
	}
	else if (choice_menu == 8) {
		system("CLS");
		while (back2 == 'y' || back2 == 'Y') {
			lend_books();
			cout << endl << endl;

			cout << "Press 'y' to check lended books again!! " << endl;
			cin >> back2;

		}
		back2 = 'y';
		cout << "Enter any key to return to menu!! " << endl;
		char ch = _getch();
		system("CLS");
		menu();

	}
	else if (choice_menu == 9) {
		exit_func();

	}

	else {
		cout << "Invalid Choice!! " << endl << endl;
		cout << "Press any key to continue..... ";
		char ch = _getch();
		system("CLS");
		menu();
	}


}

int main() {
	char choice;

	cout << "\n\n\n\n";
	cout << "\t\t\t***********************************************************\n";
	cout << "\t\t\t*****************";
	SetConsoleTextAttribute(h, 1);
	cout << " Welcome to Our Library!";
	SetConsoleTextAttribute(h, 7);
	cout << " *****************" << endl;
	cout << "\t\t\t***********************************************************\n";
	cout << endl;
	cout << endl;
	cout << " Please select your choice:  " << endl;
	cout << "\n\t\t";
	SetConsoleTextAttribute(h, 3);
	cout << "1.Sign up:";
	SetConsoleTextAttribute(h, 7);
	cout << "\n\t\t";
	SetConsoleTextAttribute(h, 3);
	cout << "2.Login:";
	SetConsoleTextAttribute(h, 7);
	cout << "\n\nEnter your choice: ";
	cin >> choice;
	cout << endl;
	if (choice == '1') {
		registered();
		SetConsoleTextAttribute(h, 4);
		cout << "\t\t\tSuccessfully registered! " << endl;
		SetConsoleTextAttribute(h, 7);
		cout << "Press any key to Continue.....";
		char ch = _getch();
		system("CLS");
		main();

	}
	else if (choice == '2') {
		int a = loggedin();
		if (a == 1) {
			SetConsoleTextAttribute(h, 4);
			cout << "\t\t\tSuccessfully logged in! " << endl << endl;
			SetConsoleTextAttribute(h, 7);
			load_data();
			cout << "Press any key to Continue.....";
			char ch = _getch();
			system("CLS");
			menu();
		}
		else {
			cout << "login failed! Please Try Again " << endl << endl;
			cout << "Press any key to Continue.....";
			char ch = _getch();
			system("CLS");
			main();
		}
	}
	else {
		cout << "Invalid choice!! " << endl << endl;
		cout << "Press any key to continue..... ";
		char ch = _getch();
		system("CLS");
		main();
	}


	return 0;
}