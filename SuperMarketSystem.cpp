#include<iostream>
#include <stdlib.h>
#include<fstream>
#include<string.h>
#include<string>
void insert();
void display();
void search();
void update();
void del();
using namespace std;
int main()
{
    int c;
    bool flag=true;
    while(flag)
    {
        cout<<"\t \t \t      welcome in super market \n";
        cout<<"\t\t\t\t*******************\n";
        cout<<"\t\t\t\tto insert enter  1 : \n";
        cout<<"\t\t\t\tto display enter 2 : \n";
        cout<<"\t\t\t\tto search enter  3 : \n";
        cout<<"\t\t\t\tto update update 4 : \n";
        cout<<"\t\t\t\tto delete update 5 : \n";
        cout<<"\t\t\t\t*******************\n";
        cin>>c;
        //system("cls");
        switch(c)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            update();
            break;
        case 5:
            del();
            break;
        default :
            cout<<"\tchoose the right number \n";
        }
        char x;
        cout<<"\n\tto continue enter y "<<"\tto exit enter f \n";
        cin>>x;
        if(x=='y')
            flag=true;
        else
            flag=false;
        cout<<"\n\n";
        system("cls");
    }
}
///////////////////////// 	function to insert    ****    function  number 1		 
void insert()
{
    ofstream file;
    file.open("super market.txt", ios::app);
    char name[1000], Price[100], quantity[100], id[100] ;
    cin.ignore();
    cout<<"\nenter the name of food   : ";
    cin.getline( name, 1000);
    cout<<"enter the Price  : ";
    cin.getline( Price, 100);
    cout<<"enter quantity  : ";
    cin.getline( quantity, 100);
    cout<<"enter the id  : ";
    cin.getline( id, 100);
    cout<<"\n";
    file<<name<<"*"<<Price<<"*"<<quantity<<"*"<<id<<"\n";
    file.close();
    system("cls");
}
///////////////////////// 	function to display   ****   function     number 2		 
void display()
{
    cout<<"\n\n";
    ifstream file;
    file.open("super market.txt" );
    char name[1000] ;
    char Price[10];
    char  quantity[100];
    char  id[10] ;
    if (file . fail() )
        cout<<"\n\tERROR";
    while( !file.eof() )
    {
        file.getline( name, 1000, '*' );
        file.getline( Price, 10, '*');
        file.getline( quantity, 10, '*');
        file.getline( id, 10 );
        if(name[0] != '\0')
            cout<<"name : "<<name<<"\t\t"<<"Price : "<<Price<<"\t\t"<<"quantity : "<<quantity<<"\t\t "<<"id : "<<id<<"\n\n";
    }
    file.close();
}
///////////////////////// 	function to search    *****  function  number 3		 
void search()
{
    ifstream file;
    file.open("super market.txt" );
    if (file . fail() )
        cout<<"\n\tERROR";
    char name[1000], Price[10], quantity[100], id[10], search[100];
    cin.ignore();
    cout<<"\n\nenter the id you want to search about it :  ";
    cin.getline( search, 100);
    bool flag=false;
    while( !file.eof() )
    {
        file.getline( name, 1000, '*' );
        file.getline( Price, 10, '*');
        file.getline( quantity, 100, '*');
        file.getline( id, 10 );
        if(strcmp ( id, search )== 0)
            cout<<"\nname      : "<<name<<endl<<"Price    : "<<Price<<endl<<"quantity  : "<<quantity<<endl<<"id        : "<<id<<endl;
        else
            flag=true	;
    }
    if(flag==false)
        cout<<"\n\tnot found\n\n";
    file.close();
}
/////////////  to update        function number  4    ////////////////////
void update()
{
    ifstream file;
    file.open("super market.txt");
    ofstream data;
    data.open("new data.txt");
    if (file . fail() )
        cout<<"\n\tERROR";
    char name [1000], Price [10], quantity[100], id [10] ;  ;
    bool flag=false;
    char x [7];
    cout<<"\n\n\nenter the id you want to update it ??  ";
    cin.ignore();
    cin.getline( x, 7);
    if (file . fail() )
        cout<<"\n\tERROR";
    while( !file.eof() )
    {
        file.getline( name, 1000, '*' );
        file.getline( Price, 10, '*');
        file.getline( quantity, 100, '*');
        file.getline( id, 10 );
        if( name[0] != '\0')
        {
            if( strcmp ( id, x) == 0 )
            {
                cout<<"\nenter new name &&  new sales  &&  new quantity   &&  new id \n";
                cin.getline( name, 1000 );
                cin.getline( Price, 10);
                cin.getline( quantity, 100);
                cin.getline( id, 10);
                data<<name<<"*"<<Price<<"*"<<quantity<<"*"<<id<<endl;
                flag=true;
            }
            else
            {
                data<<name<<"*"<<Price<<"*"<<quantity<<"*"<<id<<endl;
            }
        }
    }
    if ( flag == false )
        cout<<"\n\tTHID ID NOT EXIT \n";
    file.close();
    data.close();
    remove ("super market.txt");
    rename ( "new data.txt", "super market.txt" );
}
/////////////// FUNCTION TO DELETE      NUMBER   5   //////////
void del()
{
    ifstream file;
    file.open("super market.txt");
    ofstream data;
    data.open("new data.txt");
    if (file . fail() )
        cout<<"\n\tERROR";
    char name [1000], Price [10], quantity[100], id [10] ;
    bool flag=false;
    char x [7];
    cout<<"\n\n\nenter the id you want to delet it ??  ";
    cin.ignore();
    cin.getline( x, 7);
    if (file . fail() )
        cout<<"\n\tERROR";
    while( !file.eof() )
    {
        file.getline( name, 1000, '*' );
        file.getline( Price, 10, '*');
        file.getline( quantity, 100, '*');
        file.getline( id, 10 );
        if( name[0] != '\0')
        {
            if( strcmp ( id, x) == 0 )
            {
                flag=true;
                continue;
            }
            else
                data<<name<<"*"<<Price<<"*"<<quantity<<"*"<<id<<endl;
        }
    }
    if ( flag == true )
        cout<<"\n\tDONE\n";
    else
        cout<<"\n\tTHID ID NOT EXIT \n";
    file.close();
    data.close();
    remove ("super market.txt");
    rename ( "new data.txt", "super market.txt" );}
