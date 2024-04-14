#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class node
{
public:
    int price, code;
    string title, author, publisher, publish_date;

    node *next;
};
class book
{
    node *temp, *head, *cur;

public:
    book()
    {
        head = NULL;
    }
    void insert(string title, string author, string publisher, string publish_date, int code, int price);
    void del_title(string x);
    void del_author(string x);
    void del_data(int code);
    void search_title(string x);
    void search_author(string x);
    void search(int code);
    void stor_data();
    void print();
    void display();
};
// this fuction is used to store intput data
void book::insert(string title, string author, string publisher, string publish_date, int code, int price)
{
    temp = new node;
    temp->title = title;
    temp->author = author;
    temp->publisher = publisher;
    temp->publish_date = publish_date;
    temp->code = code;
    temp->price = price;

    if (head == NULL)
    {
        head = temp;
        temp->next = NULL;
    }
    else
    {
        cur = head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
        temp->next = NULL;
    }
    
    //use to insert data in file
    ofstream out("lms.txt", ios::ate | ios::out | ios::in);
    while (cur != NULL)
    {

        out << cur->title << "\t\t";
        out << cur->author << "\t\t";
        out << cur->publisher << "\t\t";
        out << cur->publish_date << "\t\t";
        out << cur->code << "\t\t";
        out << cur->price << "\t\t";
        cur = cur->next;
        out << endl;
    }
    cout << endl;
    out.close();
    
}
// Delete any student using this function
void book::del_title(string x)
{

    int flag = 0;
    node *previous;
    int i = 0;
    if (head == NULL)
    {
        cout << "List is not Created." << endl;
    }
    else
    {
        cur = head;

        while (cur != NULL)
        {
            if (cur->title == x)
            {
                flag = 1;
                break;
            }
            previous = cur;
            cur = cur->next;
        }
    }
    if (flag == 0)
    {
        cout << "node is not found" << endl;
    }
    else
    {
        if (head == NULL)
        {
            cout << "list is Not created:" << endl;
        }
        else
        {
            if (cur == head)
            {
                cur = head;
                if (cur->next != NULL)
                {
                    temp = cur;
                    cur = cur->next;
                }
                head = cur;
                delete temp;
            }
            else if (cur == NULL)
            {
                cur = head;
                while (cur->next->next != NULL)
                {
                    cur = cur->next;
                }
                temp = cur->next;
                cur->next = NULL;
                delete temp;
            }
            else
            {
                previous->next = cur->next;
                delete cur;
            }
        }
    }
}
// use to remove book by author name
void book::del_author(string x)
{

    int flag = 0;
    node *previous;
    int i = 0;
    if (head == NULL)
    {
        cout << "List is not Created." << endl;
    }
    else
    {
        cur = head;

        while (cur != NULL)
        {
            if (cur->author == x)
            {
                flag = 1;
                break;
            }
            previous = cur;
            cur = cur->next;
        }
    }
    if (flag == 0)
    {
        cout << "node is not found" << endl;
    }
    else
    {
        if (head == NULL)
        {
            cout << "list is Not created:" << endl;
        }
        else
        {
            if (cur == head)
            {
                cur = head;
                if (cur->next != NULL)
                {
                    temp = cur;
                    cur = cur->next;
                }
                head = cur;
                delete temp;
            }
            else if (cur == NULL)
            {
                cur = head;
                while (cur->next->next != NULL)
                {
                    cur = cur->next;
                }
                temp = cur->next;
                cur->next = NULL;
                delete temp;
            }
            else
            {
                previous->next = cur->next;
                delete cur;
            }
        }
    }
}
// use to remove book by using code
void book::del_data(int code)
{

    int flag = 0;
    node *previous;
    int i = 0;
    if (head == NULL)
    {
        cout << "List is not Created." << endl;
    }
    else
    {
        cur = head;

        while (cur != NULL)
        {
            if (cur->code == code)
            {
                flag = 1;
                break;
            }
            previous = cur;
            cur = cur->next;
        }
    }
    if (flag == 0)
    {
        cout << "node is not found" << endl;
    }
    else
    {
        if (head == NULL)
        {
            cout << "list is Not created:" << endl;
        }
        else
        {
            if (cur == head)
            {
                cur = head;
                if (cur->next != NULL)
                {
                    temp = cur;
                    cur = cur->next;
                }
                head = cur;
                delete temp;
            }
            else if (cur == NULL)
            {
                cur = head;
                while (cur->next->next != NULL)
                {
                    cur = cur->next;
                }
                temp = cur->next;
                cur->next = NULL;
                delete temp;
            }
            else
            {
                previous->next = cur->next;
                delete cur;
            }
        }
    }
}
// use this function to find book from list easily by title
void book::search_title(string x)
{

    int flag = 0;
    node *previous;
    int i = 0;
    if (head == NULL)
    {
        cout << "List is not Created." << endl;
    }
    else
    {
        cur = head;

        while (cur != NULL)
        {
            if (cur->title == x)
            {
                flag = 1;
                break;
            }
            // previous = cur;
            cur = cur->next;
        }
    }
    if (flag == 0)
    {
        cout << "node is not found" << endl;
    }
    else
    {
        if (head == NULL)
        {
            cout << "list is Not created:" << endl;
        }
        else
        {
            cout << "Title \t"
                 << "Author \t"
                 << "Publisher \t"
                 << "Publish_date \t"
                 << " Code \t"
                 << "Price \t" << endl;
            cout << cur->title << " \t\t";
            cout << cur->author << " \t\t";
            cout << cur->publisher << " \t\t";
            cout << cur->publish_date << " \t\t";
            cout << cur->code << " \t\t";
            cout << cur->price << "\t\t";
        }
    }
}
// use this function to find book from list easily by author
void book::search_author(string x)
{

    int flag = 0;
    node *previous;
    int i = 0;
    if (head == NULL)
    {
        cout << "List is not Created." << endl;
    }
    else
    {
        cur = head;

        while (cur != NULL)
        {
            if (cur->author == x)
            {
                flag = 1;
                break;
            }
            // previous = cur;
            cur = cur->next;
        }
    }
    if (flag == 0)
    {
        cout << "node is not found" << endl;
    }
    else
    {
        if (head == NULL)
        {
            cout << "list is Not created:" << endl;
        }
        else
        {
            cout << "Title \t"
                 << "Author \t"
                 << "Publisher \t"
                 << "Publish_date \t"
                 << " Code \t"
                 << "Price \t" << endl;
            cout << cur->title << " \t\t";
            cout << cur->author << " \t\t";
            cout << cur->publisher << " \t\t";
            cout << cur->publish_date << " \t\t";
            cout << cur->code << " \t\t";
            cout << cur->price << "\t\t";
        }
    }
}
// use this function to find book from list easily by code
void book::search(int code)
{

    int flag = 0;
    node *previous;
    int i = 0;
    if (head == NULL)
    {
        cout << "List is not Created." << endl;
    }
    else
    {
        cur = head;

        while (cur != NULL)
        {
            if (cur->code == code)
            {
                flag = 1;
                break;
            }
            // previous = cur;
            cur = cur->next;
        }
    }
    if (flag == 0)
    {
        cout << "node is not found" << endl;
    }
    else
    {
        if (head == NULL)
        {
            cout << "list is Not created:" << endl;
        }
        else
        {
            cout << "Title \t"
                 << "Author \t"
                 << "Publisher \t"
                 << "Publish_date \t"
                 << " Code \t"
                 << "Price \t" << endl;
            cout << cur->title << " \t\t";
            cout << cur->author << " \t\t";
            cout << cur->publisher << " \t\t";
            cout << cur->publish_date << " \t\t";
            cout << cur->code << " \t\t";
            cout << cur->price << "\t\t";
        }
    }
}

// using this funtions to store data
void book::stor_data()
{
    cur = head;
  /*  cout << "\n";
    cout << "Title\t"
         << "Author Name \t"
         << "Publisher \t"
         << "Publish Date\t"
         << "Book Code\t"
         << "Price\t" << endl;*/
    ofstream out("lms.txt", ios::ate | ios::out | ios::in);
    while (cur != NULL)
    {

        out << cur->title << "\t\t";
        out << cur->author << "\t\t";
        out << cur->publisher << "\t\t";
        out << cur->publish_date << "\t\t";
        out << cur->code << "\t\t";
        out << cur->price << "\t\t";
        cur = cur->next;
        out << endl;
    }
    cout << endl;
    out.close();
    
}
// this function is used to print value on console at run time
void book::display()
{
	
    cur = head;
    while (cur != NULL)
    {
        cout << cur->title << "		" << cur->author << "		" << cur->publisher << "		" << cur->publish_date << "		" << cur->code << "		" << cur->price;
        cout << endl;
        cur = cur->next;
    }
}
// this funtion is used to fetch value from file and print it on screen
void book::print()
{
 	ifstream in("lms.txt");
    in.open("lms.txt",ios::app|ios::in);
    in.seekg(0,ios::beg);
    while (cur!=NULL)
    {
    	in.seekg(0,ios::beg);
       // in >> cur->title >> cur->author >>cur->publisher >>cur->publish_date >>cur->code >>cur->price;
        getline(in, cur->title);
        getline(in, cur->author);
        getline(in, cur->publisher);
        getline(in, cur->publish_date);
        in >> cur->code;
        in >> cur->price;
        cur=cur->next;
    }

    while(cur!=NULL)
    {

        cout << cur->title << "\t\t";
        cout << cur->author << "\t\t";
        cout << cur->publisher << "\t\t";
        cout << cur->publish_date << "\t\t";
        cout << cur->code << " \t\t";
        cout << cur->price << " \t\t";
        cur=cur->next;
    }
    in.close();
       
}
main()
{
    cout << "\t\t\t\t\t";
    cout << "--------------------------Welcome To Library Management System-------------------------------" << endl;
    book b;
    int price, code, n;
    string title, author, publisher, publish_date, x;
    cout << "\n \n \n";
    cout << "\t\t\t\t\t Press 1 To Add new book in List:" << endl;
    cout << "\t\t\t\t\t Press 2 To Remove book from List:" << endl;
    cout << "\t\t\t\t\t Press 3 To Search book in List:" << endl;
    cout << "\t\t\t\t\t Press 4 To Print output:" << endl;
	 cout<<"\t\t\t\t\t Press 5 To Print File Data:"<<endl;
    cout << "\t\t\t\t\tPlease Select One Choice:" << endl;

    cin >> n;
     cout << "Enter a number to tell how many book data you want to store :" << endl;
            cin >> n;
            for(int i=1;i <=n;i++)
            {
                cin.ignore();
                cout << "Enter the title of book: " << endl;
                getline(cin, title);
                cout << "Enter the author name: " << endl;
                getline(cin, author);
                cout << "Enter Publisher name: " << endl;
                getline(cin, publisher);
                cout << "Enter book publish year: " << endl;
                getline(cin, publish_date);
                cout << "Enter the book code: " << endl;
                cin >> code;
                cout << "Enter the price of book: " << endl;
                cin >> price;
                // values passing to insert function
                b.insert(title, author, publisher, publish_date, code, price);
                 b.stor_data();
                cout << endl;
            }
	 char op;
    do{

   

        // to use one function of program at a time
        switch (n)
        {
        case 1:
            cout << "Enter a number to tell how many book data you want to store :" << endl;
            cin >> n;
            for(int i=1;i <=n;i++)
            {
                cin.ignore();
                cout << "Enter the title of book: " << endl;
                getline(cin, title);
                cout << "Enter the author name: " << endl;
                getline(cin, author);
                cout << "Enter Publisher name: " << endl;
                getline(cin, publisher);
                cout << "Enter book publish year: " << endl;
                getline(cin, publish_date);
                cout << "Enter the book code: " << endl;
                cin >> code;
                cout << "Enter the price of book: " << endl;
                cin >> price;
                // values passing to insert function
                b.insert(title, author, publisher, publish_date, code, price);
                 b.stor_data();
                cout << endl;
            }
            cout << "\t\t\t\t\t Updated List of Student:" << endl;

           
            cout << "-*--*--*--*--*--*--*--*--*-Thanks You-*--*--*--*--*--*--*--*--*--*--*--*-" << endl;
            cout << "if you to continue program , Press (Y) otherwise Press (N)" << endl;
            cin >> op;
            break;
        case 2:
            cout << "Enter code To Remove book from List:" << endl;
            int y;
            cout << "Select 1 to remove book by using title :" << endl;
            cout << "Select 2 to remove book by using author " << endl;
            cout << "select 3 to remove book by code " << endl;
            cin >> y;
            switch (y)
            {
            case 1:
                cout << "Enter the book Title :" << endl;
                getline(cin, x);
                b.del_title(x);
                break;
            case 2:
                cout << "Enter the author name :" << endl;
                getline(cin, x);
                b.del_author(x);
                break;
            default:
                cin >> code;
                b.del_data(code);
                cout << endl;
            }

            //cout << "if you to continue program , Press (Y) otherwise Press (N)" << endl;
            //cin >> op;
            break;
        case 3:
            cout << "Enter code To Remove book from List:" << endl;
            //  int y;
            cout << "Select 1 to remove book by using title :" << endl;
            cout << "Select 2 to remove book by using author " << endl;
            cout << "select 3 to remove book by code " << endl;
            cin >> y;
            switch (y)
            {
            case 1:
                cout << "Enter the book Title :" << endl;
                getline(cin, x);
                b.search_title(x);
                break;
            case 2:
                cout << "Enter the author name :" << endl;
                getline(cin, x);
                b.search_author(x);
                break;
            default:
                cout << " Enter the Code :" << endl;
                cin >> code;
                b.search(code);
                cout << endl;
            }
            cout << "if you to continue program , Press (Y) otherwise Press (N)" << endl;
            cin >> op;
            break;
        case 4:
            cout << "----------Data Store in Portal----------" << endl;
            cout << endl;
            cout << "Title\t\tAuthor\t\tPublisher\t\tPublish_date\t\tcode\t\tPrice" << endl;
            b.stor_data();
            b.display();

            
            cout << "-*--*--*--*--*--*--*--*--*-Thanks You-*--*--*--*--*--*--*--*--*--*--*--*-" << endl;
            cout << "if you to continue program , Press (Y) otherwise Press (N)" << endl;
            cin >> op;
            break;
        case 5:
        	b.stor_data();
        	b.print();
        	break;
        default:
            cout << "\t\t\t\t\tYour Program is Terminate." << endl;
            cout << "-*--*--*--*--*--*--*--*--*-Thanks You-*--*--*--*--*--*--*--*--*--*--*--*-" << endl;
           cout << "if you to continue program , Press (Y) otherwise Press (N)" << endl;
          cin >> op;
        }
    	}while(op=='Y');
}
