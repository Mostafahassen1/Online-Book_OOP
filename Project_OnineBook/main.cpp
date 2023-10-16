#include <iostream>
#include<bits/stdc++.h>
#include <ctime>
using namespace std;

class Print{

protected:

int choies_from_menu( const int & low, const int & hight)
{
    int number ;
    cout<<"\n\n";
    while( true)
    {

        cout<<"Enter the number in range ( "<<low<<" - "<< hight<<" ) : " ;
        cin >> number ;
        if( number <= 0 || number > hight )
            cout<<"\nThe number our your range . Try again \n" ;

        else
            break ;

    }

    return number ;
}
int ShowReadMenu( const vector<string> & choies )
{
    cout<<"\nMenu:\n";
    for( int line =0 ; line < (int)choies.size() ; line++  )
        cout<<"         "<<line+1<<" : "<<choies[line]<<"\n" ;
    int number = choies_from_menu( 1, (int)choies.size() ) ;
    return number ;
}

};

class Book
{


private :

    string  isdn ;    // International Standard Book Numbering System
    string author ;
    string title ;
    vector<string> pages ;


public :


    void Read()
    {
        string Str ;
        cout<<"\n Enter the ISDN of book : " ;
        cin>>Str ;
        SetIsdn(Str) ;

        cout<<"\nEnter the name of Author : " ;
        cin >> Str ;
        SetAuthor( Str ) ;

        cout<<"\nEnter title of book : ";
        cin>> Str ;
        SetTitle(Str) ;

        cout<<"\nEnter the number pages of book : " ;
        int number ;
        cin >> number ;


        string pag ;

        for( int line = 0 ; line < number ; line++ )
        {
            cout<<"\nEnter the page ( "<<line+1<<" )\n" ;
            cin>>pag ;
            pages.push_back( pag ) ;
        }

        cout<<"/n       You did add book\n\n";
    }


    void SetIsdn( const string & isdn)
    {
        this->isdn = isdn ;
    }

    void SetAuthor( const string & author )
    {
        this->author = author ;
    }

    void SetTitle( const string & title )
    {
        this->title = title ;
    }

    void SetPages( const vector<string> & pages )
    {
        this->pages = pages ;

    }



    const string & GetIsdn() const
    {
        return isdn ;
    }

    const string & GetAuthor() const
    {
        return author ;
    }

    const string & GetTitle() const
    {
        return title ;
    }

    const vector<string> & GetPages() const
    {
        return pages ;
    }

    string ToString()
    {
        return title ;
    }

};

class BookReadingSession
{

private :

     int curring_page ;
     Book* book ;

public :


    BookReadingSession() { }
    BookReadingSession(  Book *book ) : curring_page(0),book(book)
    {

    }

    int GetCurrentPage()
    {
        return curring_page ;
    }

    string ToString()
    {
        ostringstream oss ;
        oss<< book->GetTitle()<<" Pages "<< PageStr() ;
        return oss.str() ;
    }

    string PageStr()
    {
        ostringstream oss ;
        oss<< GetCurrentPage()+1<<" / "<<book->GetPages().size();
        return oss.str() ;
    }

    string GetCurrentPageContint()
    {
        return book->GetPages()[curring_page] ;
    }

    void NextPage()
    {
        if( (int)book->GetPages().size()-1 > curring_page )
            curring_page++ ;
    }

    void PreviousPage()
    {
        if( curring_page > 0 )
            curring_page-- ;
    }


} ;

class User
{
private :

    string user_name ;
    string password ;
    string name ;
    string email ;
    bool Case ;

    vector<BookReadingSession*> reading_session ;
public :

   // User(const User&) = delete;
   // void operator=(const User&) = delete;

    User()
    {
        //ctor
    }

    ~User()
    {
        cout<<"Destructor: User\n" ;
        for( auto Session : reading_session )
        {
            delete Session ;
        }
        reading_session.clear() ;

    }


    void Read( const string & user_name )
    {

        SetUserName(user_name );

        string str;

        cout << "Enter password ( No space ) : ";
        cin >> str;
        SetPassword(str);

        cout << "Enter name( No space ) : ";
        cin >> str;
        SetName(str);

        cout << "Enter email( No space ) : ";
        cin >> str;
        SetEmail(str);
        SetLiprary_admin(false) ;
    }


    void SetUserName(const string& userName)
    {
        user_name = userName;
    }

    void SetPassword(const string& password)
    {
        this->password = password;
    }

    void SetName(const string& name)
    {
        this->name = name;
    }
    void SetEmail(const string& email)
    {
        this->email = email;
    }
    void SetLiprary_admin( const bool & Case )
    {
        this->Case = Case ;
    }


    const string &GetUserName() const
    {
        return  user_name ;
    }

    const string &GetPassword() const
    {
        return    password;
    }

    const string &GetName() const
    {
        return  name ;
    }

    const string &GetEmail() const
    {
        return  email ;
    }

    bool GetLiprary_admin( ) const
    {
        return Case ;
    }

    vector<BookReadingSession*> GetReadingSession()
    {

        return reading_session ;

    }

    BookReadingSession* AddReadingSession( Book* book)
    {

        BookReadingSession* Session = new BookReadingSession(book) ;

        reading_session.push_back( Session ) ;

        return  Session ;

    }

};

class UserManger : public Print
{

private :

    User *current_user = new User() ;
    map<string,User*> userame_userobject_map ;

    void FreeLoadData()
    {

        for( auto Pair : userame_userobject_map )
        {
            delete  Pair.second ;
        }
        userame_userobject_map.clear();
        //current_user = nullptr ;
    }


public :




    UserManger()
    {
        //current_user = new User() ;

    }

    ~UserManger()
    {
        cout << "Destuctor: UsersManager\n";
        FreeLoadData();
    }

   // UserManger(const UserManger&) = delete;
   // void operator=(const UserManger&) = delete;

    void LoadDatabase()
    {

        cout<<"UsersManager: LoadDatabase\n";
        FreeLoadData();

        User* user1= new User();
        user1->SetUserName("Mostafa");
        user1->SetPassword("123");
        user1->SetName("mostafa") ;
        user1->SetEmail("Mostafa@gmail.com") ;
        user1->SetLiprary_admin(true) ;

        userame_userobject_map[ user1->GetUserName() ] = user1 ;

        User* user2 = new User();

        user2->SetUserName("J");
        user2->SetPassword("345");
        user2->SetName("JACK") ;
        user2->SetEmail("jack@gmail.com") ;
        user2->SetLiprary_admin(false) ;

        userame_userobject_map[ user2->GetUserName() ] = user2 ;
    }


    void AccessSystem()
    {
        vector<string>menu ;
        menu.push_back(" Login");
        menu.push_back(" SignUp");
        int choie = ShowReadMenu(menu) ;
        if( choie == 1)
            DoLog_In();
        else
            DoSign_Up();

    }

    void DoSign_Up()
    {

        string  user_name ;

        cout<<"\n Enter user name ( No space ) : " ;
        cin >> user_name ;
        if( userame_userobject_map.count(user_name) )
        {
            cout<<"This user name already active : Try again \n " ;
            DoSign_Up() ;

        }
        current_user->Read(user_name);

        userame_userobject_map[ current_user->GetUserName() ] = current_user ;
    }

    void  DoLog_In()
    {
        cout<<"\n";
        LoadDatabase();
        string user_name ;
        string password ;

        while( true )
        {

            cout<<"\nEnter the user name : " ;
            cin >> user_name ;

            cout<< "\nEnter the password :  " ;
            cin >>  password ;

            if( ! userame_userobject_map.count( user_name ) )
            {
                cout << "\nInvalid user user_name or password. Try again\n\n" ;
                continue ;
            }

            User* user_line = userame_userobject_map.find(user_name)->second ;


            if( user_line->GetPassword() != password )
            {
                cout << "\nInvalid user user_name or password. Try again\n\n" ;
                continue ;
            }
            current_user = user_line ;

            break ;
        }

    }

    vector<BookReadingSession*> GetReadingSession()
    {

        return current_user->GetReadingSession();  // have the same number in class User and UserManger ( overLoad)

    }

    BookReadingSession* AddReadingSession(Book* book )
    {
        return current_user->AddReadingSession(book) ;
    }

    User* GetCurrentUser() const
    {

        return current_user ;

    }

};

class BookManger  : public Print
{

private:

    map< string, Book*> isbn_to_book_map ;

    void FreeLoadData()
    {
        for(  auto  Pair : isbn_to_book_map )
        {
            delete Pair.second ;
        }
        isbn_to_book_map.clear();
    }

public :

    BookManger()
    {
    }

    ~BookManger()
    {
        cout << "Destuctor: BookManger\n";
        FreeLoadData();
    }

    //BookManger(const BookManger&) = delete;
    //void operator=(const BookManger&) = delete;

    void LoadDatabase()
    {
        cout<<"BookManger: LoadDatabase\n";
        FreeLoadData();


        Book *book1 = new Book() ;

        book1->SetIsdn("0001");
        book1->SetAuthor("PaulS.Wang");
        book1->SetTitle("Object-Oriented Program");
        vector<string> pagesBook1 = { "One Basics", "Two Object-Based", "Tree Array , pointer" } ;
        book1->SetPages(pagesBook1 );

        AddBook( book1 ) ;


        Book* book2 = new Book() ;

        book2->SetIsdn("0002");
        book2->SetAuthor("Mark Allen Weiss");
        book2->SetTitle("Data Structures and Algorithm");
        vector<string> pagesBook2 = { "One : Algorithm Analysis ", "Two : List , Stacks , Queues ", "Tree : Trees ", "four : Hashing" } ;
        book2->SetPages(pagesBook2 );

        AddBook( book2 ) ;

        Book* book3 = new Book() ;

        book3->SetIsdn("0003");
        book3->SetAuthor("Mark Allen ");
        book3->SetTitle("Analysis Algorithm");
        vector<string> pagesBook3 = { "One: Sort ", "Two : Disjoint Set ", "Tree: Graph Algorithm ", "four : Amortized Analysis " } ;
        book3->SetPages(pagesBook3 );

        AddBook( book3 ) ;

    }



    void AddBook(Book* book_add )
    {

        isbn_to_book_map[ book_add->GetIsdn() ] = book_add ;

    }

    const map<string, Book*> & GetIsbnToBookMap() const
    {

        return isbn_to_book_map ;
    }


};



class User_View  : public Print
{

private :
    UserManger &users_manager ;
    BookManger &book_manager ;
public :

    User_View (UserManger & users_manager, BookManger & book_manager  ) :
        users_manager(users_manager),  book_manager(book_manager)
    {

    }

    ~User_View()
    {
        //Doc
    }



    void Display()
    {

        User *user = users_manager.GetCurrentUser();

        cout << "\n\nHello " << user->GetName()<< " | User View\n";

        vector<string> Menu ;
        Menu.push_back("View Profile");
        Menu.push_back("List & Select from History Books ") ;
        Menu.push_back("List & Select from Available Books");
        Menu.push_back("Logout");



        while( true )
        {

            int num = ShowReadMenu( Menu );

            if( num == 1 )
                ViewProfile();
            else if( num == 2 )
                HistoryReading();
            else if( num == 3)
                Available_Books();
            else
                break ;
        }

    }

    void ViewProfile()
    {

        User *user = users_manager.GetCurrentUser();

        cout<<"Name: "<<user->GetName() <<"\n" ;
        cout<<"Email: "<<user->GetEmail()<<"\n" ;
        cout<<"User name : "<<user->GetUserName()<<"\n";
        cout<<"\n\n";

    }

    void DisplaySession( BookReadingSession * Session )
    {

        vector<string> menu ;
        menu.push_back("Next Page");
        menu.push_back("Previous Page");
        menu.push_back("Stop Reading");

        while(true)
        {

            cout<<"\nCurrent Page : " <<Session->PageStr()<<"\n";
            cout<<Session->GetCurrentPageContint();
            int num = ShowReadMenu(menu) ;

            if(num == 1)
            {
                Session->NextPage();
            }
            else if(num == 2 )
            {
                Session->PreviousPage();
            }
            else
                break ;
        }

    }


    void HistoryReading()
    {
        vector<BookReadingSession*> Session = users_manager.GetReadingSession();
        int index = 0 ;

        for( auto & session : Session )
            cout<< ++index <<" - " << session->ToString() <<"\n" ;

        if( index == 0 )
            cout<< "\nNo history. List books and start having fun\n" ;
        else
        {
            int chioes = choies_from_menu( 1,  index+1  ) ;
            DisplaySession(  Session[chioes-1] ) ;
        }

    }

    void Available_Books()
    {


        const map<string, Book*> & mp = book_manager.GetIsbnToBookMap();
        int index = 0 ;

        cout <<"\nOur current book collection:\n";

        for(const auto & line : mp  )
        {
            cout<<"          "<<++index<<" - "<<line.second->GetTitle() <<"\n";
        }

        cout<<"\nWhich book Do you read?:" ;
        int chioes = choies_from_menu(1, index ) ;

        index = 0 ;

        for( auto & line : mp )
        {

            if( ++index == chioes )
            {

                BookReadingSession * Session = users_manager.AddReadingSession( line.second) ;
                DisplaySession(Session ) ;
                break ;
            }
        }

    }
};

class AdminView  : public Print
{

private :

    UserManger &users_manager ;
    BookManger & book_manager ;

public :

    AdminView( UserManger &users_manager, BookManger & book_manager ) :
        users_manager(users_manager), book_manager(book_manager)
    {

    }



    void Display()
    {

        vector<string> Menu ;

        Menu.push_back("View Profile");
        Menu.push_back("Add Book");
        Menu.push_back("Logout");

        while(true )
        {

            int num = ShowReadMenu(Menu) ;
            cout<<"\n";

            if( num == 1 )
                ViewProfile();
            else if( num == 2 )
                Add_Book();
            else
                break ;

        }

    }

    void  ViewProfile()
    {

        User *user = users_manager.GetCurrentUser();

        cout<<"Name: "<<user->GetName() <<"\n" ;
        cout<<"Email: "<<user->GetEmail()<<"\n" ;
        cout<<"User name : "<<user->GetUserName()<<"\n";
        cout<<"\n\n";
    }

    void Add_Book()
    {

        Book* book = new Book();
        book->Read();
        book_manager.AddBook(book) ;
    }


};

class Online_book
{

private :
    UserManger* usermanger = nullptr  ;
    BookManger* bookmanger = nullptr ;

    void LoadDatabase()
    {

        usermanger->LoadDatabase();
        bookmanger->LoadDatabase();
    }

public :

    Online_book():
        bookmanger(new BookManger()), usermanger(new UserManger())
    {

    }

    ~Online_book()
    {
        cout << "Destuctor: OnlineReaderSystem\n";

        if (bookmanger != nullptr)
        {
            delete bookmanger;
            bookmanger = nullptr;
        }
        if (usermanger != nullptr)
        {
            delete usermanger;
            usermanger = nullptr;
        }
    }




    void  run()
    {

        LoadDatabase();


        while( true )
        {

            usermanger->AccessSystem();

            if (usermanger->GetCurrentUser()->GetLiprary_admin( ))
            {
                AdminView view(*usermanger, *bookmanger);
                view.Display();
            }
            else
            {
                User_View view(*usermanger, *bookmanger);
                view.Display();
            }
        }
    }
};

int main()
{
    Online_book ss ;
    ss.run();

    return 0;
}
