#include<iostream>
#include<string>
using namespace std;

class BookModel{
    public:
    int bookid;
    string bookname;
    BookModel(int bookid, string bookname){
        this->bookid=bookid;
        this->bookname=bookname;
    }
    BookModel(){}
};

class Book{
    public:
    int booklength=5;
    BookModel object[5];
    Book(){
        int bookids[booklength]={100,101,102,103,104};
        string booknames[booklength]={"THE GENE: AN INTIMATE HISTORY BY SIDDHARTHA MUKHERJEE", "BEING MORTAL: MEDICINE AND WHAT MATTERS IN THE END BY ATUL GAWANDE", "THE IMMORTAL LIFE OF HENRIETTA LACKS BY REBECCA SKLOOT", "A BRIEF HISTORY OF TIME BY STEPHEN HAWKING", "SILENT SPRING BY RACHEL CARSON"};
        
        for(int i=0;i<booklength;i++){
            object[i].bookid=bookids[i];
            object[i].bookname=booknames[i];
        }
    }
    int getbookid(){
        for(int i=0;i<booklength;i++){
            cout<<i+1<<". "<<object[i].bookname<<endl;
        }
        int res;
        cout<<"Enter the Book Option: ";
        cin>>res;
        return (res-1);
    }
    void printbook(int id){
        cout<<"Book ID: "<<object[id].bookid<<endl;
        cout<<"Book Name: "<<object[id].bookname<<endl;
    }
    void printallbooks(){
       for(int i=0;i<5;i++){
        cout<<endl;
         cout<<"Book ID: "<<object[i].bookid<<endl;
        cout<<"Book Name: "<<object[i].bookname<<endl<<endl;
       }
    }
};

// int main(){
//     Book o;
//     o.printbooks();
// }

class StudentModel{
    
    int studentpassword;
    public:
    int studentid;
    string name;
    int history[10];
    int historysize=0;
    void getinput(int studentid, int studentpassword, string name){
        this->studentid=studentid;
        this->studentpassword=studentpassword;
        this->name=name;
    }
    StudentModel(){}
    void printer(){
        cout<<"Student Id: "<<studentid<<endl;
        cout<<"Student password: "<<studentpassword<<endl;
        cout<<"Student Name: "<<name<<endl;
    }
    int checkpass(int id, int pass){
        if(studentid==id && studentpassword==pass){
            return studentid;
        }
        return 401;
    } 

};





class Student{
    public:
    StudentModel array[10];
    Student(){
        int studentids[10]={1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
        int passwords[10]={1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
        string names[10]={"AA","BB","CC","DD","EE","FF","GG","HH","II","JJ"};
        
        for(int i=0;i<10;i++){
            // array[i].studentid=studentids[i];
            // array[i].studentpassword=passwords[i];
            // array[i].name=names[i];
            array[i].getinput(studentids[i], passwords[i], names[i]);
        }
    }

    void adminhistory(Book b){
        for(int i=0;i<10;i++){
            
            if(array[i].historysize!=0){
                cout<<endl;
                cout<<"Student ID: "<<array[i].studentid<<endl;
                cout<<"Student Name: "<<array[i].name<<endl;
                cout<<"Total No. of Books taken: "<<array[i].historysize<<endl;
                for (int j = 0; j < array[i].historysize; j++){
                    cout<<endl;
                    
                    b.printbook(array[i].history[j]);
                    cout<<endl;
                }
            }
            cout<<endl;
           
            
        }
    }

    int login(){
        int userid,password;
        cout<<"Enter Student ID: ";
        cin>>userid;
        cout<<"Enter Student Password: ";
        cin>>password;
        for(int i=0;i<10;i++){
            int returncode;
            returncode=array[i].checkpass(userid,password);
            if(returncode==userid){
                return i;
            }
            else if(returncode==401 && i==9)
                {
                    return returncode;
                }
            
        }
    }
    void printdetails(int id){
        array[id].printer();
    }
    void takebook(int id, int bookid){  
        array[id].history[array[id].historysize]=bookid;
        array[id].historysize+=1; 
        cout<<"Succesfully Taken";  // storing book id into student history
    }
    void depositbook(int id, Book b){
        for(int i=0;i<array[id].historysize;i++){
            cout<<i+1<<". ";
            b.printbook(array[id].history[i]);
            cout<<endl;
        }
        int option;
        cin>>option;
        option-=1;
        
        for(int i=option;i<(array[id].historysize-1);i++){
            array[id].history[i]=array[id].history[i+1];
            array[id].historysize-=1;
        }
        cout<<"Successfully Deposited"<<endl;
    }
    void takenbooks(int id,Book b){
        system("cls");
        for(int i=0;i<array[id].historysize;i++){
            cout<<i+1<<". ";
            b.printbook(array[id].history[i]);
            cout<<endl;
        }
    }

};


/////////////////admin

class Admin{
    int password=248;
    int userid=248;
    public:
    bool login(){
        int pass,id;
        cout<<"Enter Admin Id: "; cin>>id;
        cout<<"Enter Admin Password: "; cin>>pass;
        if(password==pass && userid==id){
            return true;
        }
        return false;
    }
};