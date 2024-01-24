#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

// set coord on screen console
COORD c = {0, 0};
void gotoxy(int x, int y)
{
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// globle variable
int numberOfBooks = 0;
int number = 0;
int borrow_count = 0;

constexpr int MAX_STRUCT = 100;
char ask;
int selectOpt;

struct Data_Members
{
    int bookID;
    // string bookTittles;
    // string author;
    char bookTittles[MAX_STRUCT];
    char author[MAX_STRUCT];
    int pages[MAX_STRUCT];
    int dateOfyear[MAX_STRUCT];
    int qty[MAX_STRUCT];

} Members[MAX_STRUCT];

struct Borrow_Books_Note
{
    int Book_Code;
    string first_name;
    string last_name;
    char gender;
    string book_titles;
    string borrow_date;
    string return_date;
    int qty;
} Strudents[MAX_STRUCT];

// calling functions
void Switch_Option_Selected(int selectOpt);
void School_Library_List(Data_Members Members[]);
void Add_New_BooksInto_Library(Data_Members Member[]);
void Delet_Books(Data_Members Members[]);
void search_book_by_anothers(Data_Members list[], char type);
Data_Members read_file_into_struct(Data_Members Members[]);
void Update_Cases(Data_Members list[], char type);
void Update_Books(Data_Members Members[]);
void Borrow_and_Return_Books_Note(Borrow_Books_Note Borrow_Notes[]);

// 0. Main function
int main()
{
    system("cls");

    read_file_into_struct(Members);
    // School Library Options
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    gotoxy(25, 2);
    for (size_t i = 0; i < 29; i++)
    {
        cout << (char)224;
    }
    cout << " School Library System ";
    for (size_t i = 0; i < 29; i++)
    {
        cout << (char)224;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << R"(
                                             1. School Library Stock List
                                             2. Add New Books
                                             3. Delete Books
                                             4. Update Books
                                             5. Borrow and Return Books Note
                                             6. Quit Application
    )";
    cout << "\n";
    gotoxy((25 + 13), 9);
    for (size_t i = 0; i < 53; i++)
    {
        cout << (char)220;
    }
    gotoxy(22 + 23, 11);
    cout << "Select Option: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy((38 + 23), 11);
    cin >> selectOpt;
    Switch_Option_Selected(selectOpt);
    return 0;
}

// 1. School Library Stock List
void School_Library_List(Data_Members Member[])
{
    system("cls");
    read_file_into_struct(Member);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    gotoxy(25, 2);
    for (size_t i = 0; i < 29; i++)
    {
        cout << (char)222;
    }
    cout << " School Library System ";
    for (size_t i = 0; i < 29; i++)
    {
        cout << (char)222;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "\n\t 1. School Library Stock List" << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    for (int borx = 1; borx <= 3; borx++)
    {
        for (int bory = 1; bory <= 140; bory++)
        {
            if (borx == 1 || borx == 3 || bory == 1 || bory == 140)
            {
                cout << (char)220;
            }
            else
                cout << " ";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(3, 5);
    cout << "Book ID"; // free 40 lines
    gotoxy(20, 5);
    cout << "Book Tittle"; // 50 lines =>
    gotoxy(84 + 10, 5);
    cout << "Author";
    gotoxy(97 + 20, 5);
    cout << "Pages";
    gotoxy(105 + 20, 5);
    cout << "Year";
    gotoxy(112 + 20, 5);
    cout << "QTY";

    gotoxy(3, 22);
    cout << "Number Of Books: " << number - 1;
    gotoxy(3, 23);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    for (int i = 0; i < number - 1; i++)
    {
        gotoxy(3, 7 + i);
        cout << Member[i].bookID;
        gotoxy(20, 7 + i);
        cout << Member[i].bookTittles;
        gotoxy(94, 7 + i);
        cout << Member[i].author;
        gotoxy(117, 7 + i);
        cout << Member[i].pages[i];
        gotoxy(125, 7 + i);
        cout << Member[i].dateOfyear[i];
        gotoxy(132, 7 + i);
        cout << Member[i].qty[i];
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    gotoxy(100, 3);
    cout << "[ Go to Add more books (y/n)]: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    gotoxy(131, 3);
    cin >> ask;
    if (ask == 'y')
    {
        Add_New_BooksInto_Library(Members);
    }
    else if (ask == 'n')
    {
        main();
    }

    gotoxy(1, 50);
    getch();
}

// 2. Add New Books
void Add_New_BooksInto_Library(Data_Members Member[])
{
    struct Data_Members Members;
    system("cls");
    ofstream fout_file("School Library System.txt", ios::out | ios::app);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    gotoxy(25, 2);
    for (size_t i = 0; i < 29; i++)
    {
        cout << (char)222;
    }
    cout << " School Library System ";
    for (size_t i = 0; i < 29; i++)
    {
        cout << (char)222;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "\n\t 2. Add New Books " << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    for (int borx = 1; borx <= 5; borx++)
    {
        for (int bory = 1; bory <= 140; bory++)
        {
            if (borx == 1 || borx == 5 || bory == 1 || bory == 140)
            {
                cout << (char)220;
            }
            else
                cout << " ";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(3, 5);
    cout << "Book ID: ";
    gotoxy(33, 5);
    cout << "Book Tittle: ";
    gotoxy(3, 7);
    cout << "Author Name: ";
    gotoxy(53, 7);
    puts("Page Number: ");
    gotoxy(76, 7);
    puts("Year Of Book: ");
    gotoxy(110, 7);
    puts("Quatility Of Books: ");

    // create books
    if (fout_file)
    {
        while (true)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
            gotoxy(12, 5);
            cin >> Members.bookID;
            cin.ignore();
            gotoxy(46, 5);
            gets(Members.bookTittles);
            // getline(cin,Members.bookTittles);
            gotoxy(16, 7);
            gets(Members.author);
            // getline(cin,Members.author);
            gotoxy(66, 7);
            cin >> Members.pages[numberOfBooks];
            gotoxy(90, 7);
            cin >> Members.dateOfyear[numberOfBooks];
            gotoxy(130, 7);
            cin >> Members.qty[numberOfBooks];

            //  write datas to file
            fout_file << Members.bookID;
            fout_file << "\t" << Members.bookTittles;
            fout_file << "\t" << Members.author;
            fout_file << "\t" << Members.pages[numberOfBooks];
            fout_file << "\t" << Members.dateOfyear[numberOfBooks];
            fout_file << "\t" << Members.qty[numberOfBooks] << endl;

            numberOfBooks++;
            gotoxy(3, 12);
            cout << "number of Books: " << numberOfBooks;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(80, 9);
            puts("[ Do you want to add more ? <y/n>]: ");
            gotoxy(116, 9);
            cin >> ask;
            if (ask == 'y')
            {
                gotoxy(12, 5);
                cout << "                   ";
                gotoxy(46, 5);
                cout << "                                                                                 ";
                gotoxy(16, 7);
                cout << "                                     ";
                gotoxy(66, 7);
                cout << "          ";
                gotoxy(90, 7);
                cout << "          ";
                gotoxy(130, 7);
                cout << "         ";
                gotoxy(116, 9);
                cout << "         ";
            }
            else if (ask == 'n')
            {
                fout_file.close();
                School_Library_List(Member);
                break;
            }
        }
    }

    gotoxy(1, 50);
    getch();
}

// switch Option Selected
void Switch_Option_Selected(int selectOpt)
{
    switch (selectOpt)
    {
    case 1:
        School_Library_List(Members);
        break;
    case 2:
        Add_New_BooksInto_Library(Members);
        break;
    case 3:
        Delet_Books(Members);
        break;
    case 4:
        Update_Books(Members);
        break;
    case 6:
        exit(0);
        break;
    case 5:
        Borrow_and_Return_Books_Note(Strudents);
        break;
    }
}

// 3. Delete Books
void Delet_Books(Data_Members Members[])
{
    char selectDeleteOpt;
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    gotoxy(25, 2);
    for (size_t i = 0; i < 29; i++)
    {
        cout << (char)222;
    }
    cout << " School Library System ";
    for (size_t i = 0; i < 29; i++)
    {
        cout << (char)222;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "\n\t 3. Delete Books " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << R"(
                            ************ Choise Kind_s Of Search For Delete Books ************
                                             a. Search Book By Code
                                             b. Search Book By Book Tittles
                                             c. Search Book By Author Name
                                             e. Cancel And Goto Library
                                      ---------------------------------------------
                                           Select Options -> 
    )";

    gotoxy((38 + 23), 11);
    cin >> selectDeleteOpt;

    switch (selectDeleteOpt)
    {
    case 'a':
        search_book_by_anothers(Members, 'a');
        break;
    case 'b':
        search_book_by_anothers(Members, 'b');
        break;
    case 'c':
        search_book_by_anothers(Members, 'c');
        break;
    case 'e':
        School_Library_List(Members);
        break;

    default:
        break;
    }
}

// search book by anothers
void search_book_by_anothers(Data_Members list[], char type)
{
again:
    int ind_s = 0;
    int id_search;
    struct Data_Members l;
    gotoxy(0, 13);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    for (int borx = 1; borx <= 5; borx++)
    {
        for (int bory = 1; bory <= 140; bory++)
        {
            if (borx == 1 || borx == 5 || bory == 1 || bory == 140)
            {
                cout << (char)220;
            }
            else
                cout << " ";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(3, 5 + 9);
    cout << "Book ID: ";
    gotoxy(33, 5 + 9);
    cout << "Book Tittle: ";
    gotoxy(3, 7 + 9);
    cout << "Author Name: ";
    gotoxy(53, 7 + 9);
    puts("Page Number: ");
    gotoxy(76, 7 + 9);
    puts("Year Of Book: ");
    gotoxy(110, 7 + 9);
    puts("Quatility Of Books: ");

    // type a
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    if (type == 'a')
    {
        // int id_search;
        bool is;
        gotoxy(12, 5 + 9);
        cin >> id_search;
        for (size_t i = 0; i < number - 1; i++)
        {
            if (list[i].bookID == id_search)
            {
                is = true;
                ind_s = i;
                break;
            }
            else
                is = false;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        if (is)
        {
            gotoxy(46, 5 + 9);
            cout << list[ind_s].bookTittles;
            gotoxy(16, 7 + 9);
            cout << list[ind_s].author;
            gotoxy(66, 7 + 9);
            cout << list[ind_s].pages[ind_s];
            gotoxy(90, 7 + 9);
            cout << list[ind_s].dateOfyear[ind_s];
            gotoxy(130, 7 + 9);
            cout << list[ind_s].qty[ind_s];
        }
        else
        {
            gotoxy(12, 20);
            cout << "Book ID is not found.";
            goto again;
        }
    }

    // type b
    char title_search[100];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    if (type == 'b')
    {
        ind_s = 0;
        bool is;
        gotoxy(46, 5 + 9);
        cin >> title_search;
        for (size_t i = 0; i < number - 1; i++)
        {
            if (strcmp(list[i].bookTittles, title_search) == 0)
            {
                is = true;
                ind_s = i;
                break;
            }
            else
                is = false;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        if (is)
        {
            gotoxy(12, 5 + 9);
            cout << list[ind_s].bookID;
            gotoxy(16, 7 + 9);
            cout << list[ind_s].author;
            gotoxy(66, 7 + 9);
            cout << list[ind_s].pages[ind_s];
            gotoxy(90, 7 + 9);
            cout << list[ind_s].dateOfyear[ind_s];
            gotoxy(130, 7 + 9);
            cout << list[ind_s].qty[ind_s];
        }
        else
        {
            gotoxy(12, 20);
            cout << "Book ID is not found.";
            goto again;
        }
    }

    // type c
    char author_search[100];
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    if (type == 'c')
    {
        ind_s = 0;
        bool is;
        gotoxy(16, 7 + 9);
        cin >> author_search;
        for (size_t i = 0; i < number - 1; i++)
        {
            if (strcmp(list[i].author, author_search) == 0)
            {
                is = true;
                ind_s = i;
                break;
            }
            else
                is = false;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        if (is)
        {
            gotoxy(12, 5 + 9);
            cout << list[ind_s].bookID;
            gotoxy(46, 5 + 9);
            cout << list[ind_s].bookTittles;
            gotoxy(66, 7 + 9);
            cout << list[ind_s].pages[ind_s];
            gotoxy(90, 7 + 9);
            cout << list[ind_s].dateOfyear[ind_s];
            gotoxy(130, 7 + 9);
            cout << list[ind_s].qty[ind_s];
        }
        else
        {
            gotoxy(12, 20);
            cout << "Book ID is not found.";
            goto again;
        }
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    gotoxy(100, 3 + 9);
    cout << "[ Delete This Book (y/n) ]: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    gotoxy(128, 3 + 9);
    cin >> ask;
    if (ask == 'y')
    {
        ofstream writs("School Library System.txt");
        int num_delete = 0;
        for (size_t i = 0; i < number - 1; i++)
        {
            if (list[i].bookID != list[ind_s].bookID)
            {
                writs << list[i].bookID;
                writs << "\t" << list[i].bookTittles;
                writs << "\t" << list[i].author;
                writs << "\t" << list[i].pages[i];
                writs << "\t" << list[i].dateOfyear[i];
                writs << "\t" << list[i].qty[i] << endl;
            }
            num_delete++;
        }
        writs.close();
        read_file_into_struct(list);
        gotoxy(12, 20);
        cout << "Delete " << num_delete << " rows.";
        School_Library_List(list);
    }
    else if (ask == 'n')
    {
        Delet_Books(list);
    }

    gotoxy(0, 60);
    getch();
}

// 4. Update Books
void Update_Books(Data_Members Members[])
{
    char selectUpdateOpt;
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    gotoxy(25, 2);
    for (size_t i = 0; i < 29; i++)
    {
        cout << (char)222;
    }
    cout << " School Library System ";
    for (size_t i = 0; i < 29; i++)
    {
        cout << (char)222;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "\n\t 4. Update Books " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << R"(
                            ===========< Choise Kind_s Of Search For Update Books >===========
                                             a. Update Book By Code
                                             b. Update Book By Book Tittles
                                             e. Cancel And Goto Library
                                      ---------------------------------------------
                                           Select Options -> 
    )";

    gotoxy((38 + 23), 10);
    cin >> selectUpdateOpt;

    switch (selectUpdateOpt)
    {
    case 'a':
        Update_Cases(Members,'a');
        break;

    default:
        break;
    }
}

// 6. 
void Update_Cases(Data_Members list[], char type)
{
again:
    int ind_s = 0;
    int id_search;
    int id = 0, page, year, qty;
    char title[100],author[100];
    gotoxy(0, 13);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    for (int borx = 1; borx <= 5; borx++)
    {
        for (int bory = 1; bory <= 140; bory++)
        {
            if (borx == 1 || borx == 5 || bory == 1 || bory == 140)
            {
                cout << (char)220;
            }
            else
                cout << " ";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    gotoxy(3, 5 + 9);
    cout << "Book ID: ";
    gotoxy(33, 5 + 9);
    cout << "Book Tittle: ";
    gotoxy(3, 7 + 9);
    cout << "Author Name: ";
    gotoxy(53, 7 + 9);
    puts("Page Number: ");
    gotoxy(76, 7 + 9);
    puts("Year Of Book: ");
    gotoxy(110, 7 + 9);
    puts("Quatility Of Books: ");

    // type a
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    if (type == 'a')
    {
        // int id_search;
        bool is;
        gotoxy(12, 5 + 9);
        cin >> id_search;
        for (size_t i = 0; i < number - 1; i++)
        {
            if (list[i].bookID == id_search)
            {
                is = true;
                ind_s = i;
                break;
            }
            else
                is = false;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        if (is)
        {
            gotoxy(46, 5 + 9);
            cout << list[ind_s].bookTittles;
            gotoxy(16, 7 + 9);
            cout << list[ind_s].author;
            gotoxy(66, 7 + 9);
            cout << list[ind_s].pages[ind_s];
            gotoxy(90, 7 + 9);
            cout << list[ind_s].dateOfyear[ind_s];
            gotoxy(130, 7 + 9);
            cout << list[ind_s].qty[ind_s];
        }
        else
        {
            gotoxy(12, 20);
            cout << "Book ID is not found.";
            goto again;
        }
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    gotoxy(100, 3 + 9);
    cout << "[ Update This Book (y/n) ]: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    gotoxy(128, 3 + 9);
    cin >> ask;
    if (ask == 'y')
    {

        gotoxy(12, 5+9);
        cout << "                   ";
        gotoxy(46, 5+9);
        cout << "                                                                                 ";
        gotoxy(16, 7+9);
        cout << "                                     ";
        gotoxy(66, 7+9);
        cout << "          ";
        gotoxy(90, 7+9);
        cout << "          ";
        gotoxy(130, 7+9);
        cout << "         ";
        gotoxy(116, 9+9);
        cout << "         ";

            gotoxy(12, 5 + 9);
            cin>>id;
            cin.get();
            gotoxy(46, 5 + 9);
            gets(title);
            gotoxy(16, 7 + 9);
            gets(author);
            gotoxy(66, 7 + 9);
            cin>>page;
            gotoxy(90, 7 + 9);
            cin>>year;
            gotoxy(130, 7 + 9);
            cin>>qty;

        ofstream writs("School Library System.txt");
        int num_delete = 0;
        for (size_t i = 0; i < number - 1; i++)
        {
            if (list[i].bookID == list[ind_s].bookID)
            {
                writs << id;
                writs << "\t" << title;
                writs << "\t" << author;
                writs << "\t" << page;
                writs << "\t" << year;
                writs << "\t" << qty << endl;
                num_delete++;
            }else{
                writs << list[i].bookID;
                writs << "\t" << list[i].bookTittles;
                writs << "\t" << list[i].author;
                writs << "\t" << list[i].pages[i];
                writs << "\t" << list[i].dateOfyear[i];
                writs << "\t" << list[i].qty[i] << endl;
            }
        }
        writs.close();
        read_file_into_struct(list);
        gotoxy(12, 20);
        cout << "Updated " << num_delete << " already.";
        School_Library_List(list);
    }
    else if (ask == 'n')
    {
        Update_Books(list);
    }

    gotoxy(0, 60);
    getch();
}

// 5. Borrow and Return Books Note
void Borrow_and_Return_Books_Note(Borrow_Books_Note Borrow_Notes[])
{
    system("cls");
   // read_file_into_struct(Member);
    struct Borrow_Books_Note Borrow_Note;
    ofstream borrow_note("Borrow Note.txt", ios::out | ios::app);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    gotoxy(25, 2);
    for (size_t i = 0; i < 29; i++)
    {
        cout << (char)222;
    }
    cout << " School Library System ";
    for (size_t i = 0; i < 29; i++)
    {
        cout << (char)222;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "\n\t 5. Borrow and Return Books Note" << endl;


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    for (int borx = 1; borx <=5 ; borx++)
    {
        for (int bory = 1; bory <= 140; bory++)
        {
            if (borx == 1 || borx == 5 || bory == 1 || bory == 140)
            {
                cout << (char)220;
            }
            else
                cout << " ";
        }
        cout << endl;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    gotoxy(3, 5);
    cout << "First Name: "; // free 40 lines
    gotoxy(25, 5);
    cout << "Last Name: "; // 50 lines =>
    gotoxy(50, 5);
    cout << "Gander: ";
    gotoxy(65, 5);
    cout << "Book Code: ";
    gotoxy(91-7, 5);
    cout << "Book Tittle: ";
    gotoxy(3, 7);
    cout << "Quatility:  "; // free 40 lines
    gotoxy(25, 7);
    cout << "Borrow Date: "; // 50 lines =>
    gotoxy(65, 7);
    cout << "Return Date: ";

    while (true)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        gotoxy(15,5); 
        cin.ignore();
        getline(cin,Borrow_Note.first_name);
        gotoxy(36,5); getline(cin,Borrow_Note.last_name);
        gotoxy(58,5); cin>>Borrow_Note.gender;
        cin.get();
        gotoxy(76,5); cin>>Borrow_Note.Book_Code;
        cin.get();
        gotoxy(97,5); getline(cin,Borrow_Note.book_titles);
        gotoxy(14,7); cin>>Borrow_Note.qty;
        gotoxy(38,7); cin>>Borrow_Note.borrow_date;
        gotoxy(78,7); cin>>Borrow_Note.return_date;

        borrow_note<<Borrow_Note.first_name;
        borrow_note<<"\t"<<Borrow_Note.last_name;
        borrow_note<<"\t"<<Borrow_Note.gender;
        borrow_note<<"\t"<<Borrow_Note.Book_Code;
        borrow_note<<"\t"<<Borrow_Note.book_titles;
        borrow_note<<"\t"<<Borrow_Note.qty;
        borrow_note<<"\t"<<Borrow_Note.borrow_date;
        borrow_note<<"\t"<<Borrow_Note.return_date<<endl;
        
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
            gotoxy(80, 9);
            puts("[ Do you want to add more ? <y/n>]: ");
            gotoxy(116, 9);
            cin >> ask;
            if (ask == 'y')
            {
                // gotoxy(12, 5);
                // cout << "                   ";
                // gotoxy(46, 5);
                // cout << "                                                                                 ";
                // gotoxy(16, 7);
                // cout << "                                     ";
                // gotoxy(66, 7);
                // cout << "          ";
                // gotoxy(90, 7);
                // cout << "          ";
                // gotoxy(130, 7);
                // cout << "         ";
                // gotoxy(116, 9);
                // cout << "         ";
            }
            else if (ask == 'n')
            {
                borrow_note.close();
                //School_Library_List(Member);
                main();
                break;
            }

    }
    
    


    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    // for (int borx = 1; borx <= 3; borx++)
    // {
    //     for (int bory = 1; bory <= 140; bory++)
    //     {
    //         if (borx == 1 || borx == 3 || bory == 1 || bory == 140)
    //         {
    //             cout << (char)220;
    //         }
    //         else
    //             cout << " ";
    //     }
    //     cout << endl;
    // }
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    // gotoxy(3, 5);
    // cout << "Book ID"; // free 40 lines
    // gotoxy(20, 5);
    // cout << "Book Tittle"; // 50 lines =>
    // gotoxy(84 + 10, 5);
    // cout << "Author";
    // gotoxy(97 + 20, 5);
    // cout << "Pages";
    // gotoxy(105 + 20, 5);
    // cout << "Year";
    // gotoxy(112 + 20, 5);
    // cout << "QTY";

    // gotoxy(3, 22);
    // cout << "Number Of Books: " << number - 1;
    // gotoxy(3, 23);
    // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    // for (int i = 0; i < number - 1; i++)
    // {
    //     gotoxy(3, 7 + i);
    //     cout << Member[i].bookID;
    //     gotoxy(20, 7 + i);
    //     cout << Member[i].bookTittles;
    //     gotoxy(94, 7 + i);
    //     cout << Member[i].author;
    //     gotoxy(117, 7 + i);
    //     cout << Member[i].pages[i];
    //     gotoxy(125, 7 + i);
    //     cout << Member[i].dateOfyear[i];
    //     gotoxy(132, 7 + i);
    //     cout << Member[i].qty[i];
    // }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    gotoxy(100, 3);
    cout << "[ Go to Add more books (y/n)]: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    gotoxy(131, 3);
    cin >> ask;
    if (ask == 'y')
    {
       // Add_New_BooksInto_Library(Member);
    }
    else if (ask == 'n')
    {
        main();
    }

    gotoxy(1, 50);
    getch();
}

// read file into struct
Data_Members read_file_into_struct(Data_Members Members[])
{
    ifstream read_data("School Library System.txt", ios::in);
    number = 0;
    // read file
    struct Data_Members s;
    if (read_data)
    {
        while (!read_data.eof())
        {
            read_data >> s.bookID;
            // getline(read_data,s.bookTittles);
            // getline(read_data,s.author);
            read_data >> s.bookTittles;
            read_data >> s.author;
            read_data >> s.pages[number];
            read_data >> s.dateOfyear[number];
            read_data >> s.qty[number];
            Members[number] = s;
            number++;
        }
    }
    else
    {
        gotoxy(3, 22);
        cout << "not found." << read_data.eof();
    }
    read_data.close();

    return s;
}