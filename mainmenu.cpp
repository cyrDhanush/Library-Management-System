#include<iostream>


#include "bookmodel.cpp"

using namespace std;

int mainscreen(){
    cout<<"1. Login as Student"<<endl;
    cout<<"2. Login as Admin"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Enter the Option: ";
    int option;
    cin>>option;
    return option;
}

int studentmenu(){
    cout<<"1. Take Book"<<endl;
    cout<<"2. Deposit Book"<<endl;
    cout<<"3. Taken Books"<<endl;
    cout<<"Enter the Option: ";
    int option;
    cin>>option;
    return option;
}

int adminmenu(){
    cout<<"1. All Books"<<endl;
    cout<<"2. See History"<<endl;
    cout<<"Enter the Option: ";
    int option;
    cin>>option;
    return option;
}

void mainmenu(){
    cout<<endl<<endl;
    cout<<"*******************************************"<<endl;
    cout<<"         LIBRARY MANAGEMENT SYSTEM"<<endl;
    cout<<"*******************************************"<<endl;
    cout<<endl<<endl;
}

int main(){
    Student s;
    Book b;
    Admin a;
    mainmenu();
    system("pause");

    while(1){
        system("cls");
        int res=mainscreen();
        if(res==3) break;
        switch (res)
        {
        case 1:
        int loginres;
            loginres=s.login();
            if(loginres==401){
                cout<<"Login Failed"<<endl;
                system("pause");
            }
            else{
                system("cls");
                s.printdetails(loginres);
                int stures=studentmenu();
                switch (stures)
                {
                case 1:
                    int in;
                    in=b.getbookid();
                    s.takebook(loginres,in);
                    break;
                case 2:
                s.depositbook(loginres,b);
                system("pause");
                break;
                case 3:
                s.takenbooks(loginres,b);
                system("pause");
                break;
                default:
                    break;
                }
            }
            break;
        
        case 2:
        bool adlogin;
            adlogin=a.login();
            if(adlogin==false){
                cout<<"Login Failed"<<endl;
                system("pause");
            }
            else{
                system("cls");
                int adres=adminmenu();
                switch (adres)
                {
                case 1:
                    //to see all books
                    b.printallbooks();
                    system("pause");
                    break;
                case 2:
                s.adminhistory(b);
                system("pause");
                default:
                    break;
                }
            }
            break;
        
        default:
            cout<<"Enter a valid option"<<endl;
            continue;
            break;
        }
    }

}