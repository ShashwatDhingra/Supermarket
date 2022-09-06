// JGJ7
/* 
    SuperMarket Billing System
*/ 

#include<iostream>
#include<fstream>
using namespace std;
class shopping 
{
    private:
        int pcode;  // Product Code
        float pprice;  // Product Price
        float pdis; // Discount on Product
        string pname; // Product Name

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void rem(); // Remove
        void edit();
        void list();
        void receipt();
        
};

void shopping :: menu()
{
    int choice;
    string email;
    string password;

repeat_1:
    cout<<"\t\t\t\t _________________________________\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t       SuperMarket Main Menu      \n";
    cout<<"\t\t\t\t _________________________________\n";
    cout<<"\t\t\t\t                                  \n";

    cout<<"\t\t\t\t  1) Administrator\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t  2) Buyer\n";
    cout<<"\t\t\t\t                                  \n";
    cout<<"\t\t\t\t  3) Exit\n";

    cout<<"\t\t\t\t Please Select!";
    cin>>choice;

    switch (choice)
    {
    case(1):
    {
        cout<<"\t\t\t\t Please Login\n";
        cout<<"\t\t\t\t Enter Email :: ";
        cin>>email;
        cout<<"\n\t\t\t\t Enter Password ::";
        cin>>password;

        if(email == "xyz@gmail.com" && password == "xyz")
        {
            administrator();
        }
        else
        {
            cout<<" Invalid Email/Password \n";
        }
    }
        break;

    case(2):
    {
        buyer();
    }
        break;

    case(3):
    {
        exit(0);
    }
        break;
    
    default:
    {
        cout<<"Please Select Correct Option!";
    }
        break;
    }

    goto repeat_1;

}

void shopping :: administrator()
{

repeat_2:
    int choice;
    cout<<"\n\t\t\t\t|_____Administrator Menu___|";
    cout<<"\n\t\t\t\t|____1)Add the Product_____|";
    cout<<"\n\t\t\t\t|                          |";
    cout<<"\n\t\t\t\t|____2)Modify the Product__|";
    cout<<"\n\t\t\t\t|                          |";
    cout<<"\n\t\t\t\t|____3)Delete the Product__|";
    cout<<"\n\t\t\t\t|                          |";
    cout<<"\n\t\t\t\t|____4)Back to Main Menu___|";

    cout<<"\n\n\t Please Enter Your Choice :: ";
    cin>>choice;

    switch(choice)
    {
        case(1):
        {
            add();
        }
        break;

        case(2):
        {
            edit();
        }   
        break;

        case(3):
        {
            rem();
        }
        break;

        case(4):
        {
            menu();
        }
        break;

        default:
        {
        cout<<"Please Select Correct Option!";
        }
        break;
    }

    goto repeat_2;
}

void shopping :: buyer()
{

repeat_3:
    int choice;

    cout<<"\t\t\t\t     Buyer \n";
    cout<<"\t\t\t\t _____________ \n";
    cout<<"\t\t\t\t                 \n";
    cout<<"\t\t\t\t 1) Buy Product   \n";
    cout<<"\t\t\t\t                 \n";
    cout<<"\t\t\t\t 2) Go Back      \n";
    cout<<"\t\t\t\t                 \n";
    cout<<"\t\t\t\t Enter your Choice :: ";
    cin>>choice;

    switch (choice)
    {
    case(1):
    {
        receipt();
    }
        break;

    case(2):
    {
        menu();
    }
        break;
    
    default:
        {
        cout<<"Please Select Correct Option!";
        }
        break;
    }

goto repeat_3;

}

void shopping :: add()
{
    fstream data;
    int c;  // Product Code
    int token = 0;
    int d;  // Discount
    int p;  // Price
    string n;  // Name

repeat_4:
    cout<<"\t\t\t\t Add New Product :: ";
    cout<<"\n\n\t Product Code of Product :: ";
    cin>>pcode;
    cout<<"\n\n\t Name of Product :: ";
    cin>>pname;
    cout<<"\n\n\t Price of Product :: ";
    cin>>pprice;
    cout<<"\n\n\t Discount on Product Price :: ";
    cin>>pdis;

    data.open("database.txt", ios::in);

    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<pprice<<" "<<pdis<<"\n";
        data.close();
    }

    else
    {
        data>>c>>d>>n>>p;

        while(!data.eof())
        {
            if(c == pcode)
            {
                token++;
            }
            data>>c>>d>>n>>p;
        }


    data.close();

        if(token == 1)
        {
            goto repeat_4;
        }
        else
        {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<pprice<<" "<<pdis<<"\n";
        data.close();
        }   

        cout<<"\n\n\t\t\t\t RECORD INSERTED!";  

    }

}

void shopping :: edit()
{
    fstream data1, data2;
    int pkey;  
    int c;  // Product Code
    int token = 0;
    int d;  // Discount
    int p;  // Price
    string n;  // Name
    cout<<"\n\t\t\t\t\t\t\t--Modify the Record--";
    cout<<"\n\t\t\t\t Enter the Product Code :: ";
    cin>>pkey;

    data1.open("database.txt", ios::in);

    if(!data1)
    {
        cout<<"File Not Exist!";
    }

    else
    {
        data2.open("database1.txt", ios::app | ios::out);
        data1>>pcode>>pname>>pdis>>pprice;

        while(!data1.eof())
        {
            if(pkey == pcode)
            {
                cout<<"\n\n\t Product New Code :: ";
                cin>>c;
                cout<<"\n\n\t Name of Product :: ";
                cin>>n;
                cout<<"\n\n\t Price of Product :: ";
                cin>>p;
                cout<<"\n\n\t Discount on Product Price :: ";
                cin>>d; 
                data2<<" "<<c<<" "<<n<<" "<<" "<<p<<" "<<d<<"\n";    
                cout<<"Record Edited!";
                token++;
            }

            else
            {
                data2<<" "<<pcode<<" "<<pname<<" "<<pprice<<" "<<pdis<<"\n";
            }

            data1>>pcode>>pname>>pprice>>pdis;
        }

        data1.close();
        data2.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");
    }

    if(token == 0)
    {   
        cout<<"Sorry can't Update Record!";
    }

    else
    {
        cout<<"Record Updated Successfully";
    }

}

void shopping :: rem()
{
    fstream data1, data2;
    int token=0;
    int pkey;

    cout<<"\n\n\t\t\t\t\t\t --Delete Product--";
    cout<<"\n\t\t\t\t Enter the Product Code :: ";
    cin>>pkey;
    data1.open("database.txt", ios::in);

    if(!data1)
    {
        cout<<"File not Exist!";
    }

    else
    {
        data2.open("database1.txt", ios::app | ios::out);
        data1>>pcode>>pname>>pdis>>pprice;

        while(!data1.eof())
        {
            if(pkey == pcode)
            {
                cout<<"File Deleted Successfully";
            }

            else
            {
               data2<<" "<<pcode<<" "<<pname<<" "<<pprice<<" "<<pdis<<"\n";
            }
            
            data1>>pcode>>pname>>pprice>>pdis;

        }

        data1.close();
        data2.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token == 0)
        {
            cout<<"\n\n\t\t\t\tRecord Not Found!\n\n";
        }
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n __________________________________________\n";
    cout<<"Product Code\t Product Name\t Product Price\n";
    cout<<"\n\n __________________________________________\n";
    data>>pcode>>pname>>pprice>>pdis;

    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<pprice<<"\n";
        data>>pcode>>pname>>pprice>>pdis;
    }

    data.close();
} 

void shopping :: receipt()
{
    fstream data;

    int arr_code[100];
    int arr_quantity[100];
    char choice;
    int count = 0;
    int amount = 0;
    int dis = 0;
    int total = 0;

    cout<<"\n\n\t\t\t\t RECEIPT";
    
    // Opening File in Reading Mode

    data.open("database.txt", ios::in);

    // Check for File Existance
    if(!data)
    {
        cout<<"\n\n Empty DataBase";
    }

    else
    {
        data.close();

        list();

        cout<<"\n\n\t\t\t\t _______________________________\n";
        cout<<"\t\t\t\t|    PLEASE PLACE THE ORDER     |\n";
        cout<<"\t\t\t\t|_______________________________|\n";

        do
        {
        repeat_5:
        
            if(choice == 'n' || choice == 'N')
            {
                break;
            }
            cout<<"\n\n Enter the Product Code :: ";
            cin>>arr_code[count];
            cout<<"\n\n Enter the Quantity :: ";
            cin>>arr_quantity[count];

            for(int i=0; i<count; i++)
            {
                if(arr_code[count] == arr_code[i])
                {
                    cout<<"\n\n Duplicate Product Code! Please Try Again.";
                    goto repeat_5;
                }
            }

            count++;
            cout<<"\n\n Do you want to buy any Another Product? if Yes [Y] else [N]";
            cin>>choice;
        }
        while(choice == 'y');

        cout<<"\n\n\n\t\t\t_________________________RECEIPT___________________________";
        cout<<"\nProduct Code\tProduct Name\tProduct Quantity\tPrice\tAmount\tDiscount";

        for(int i=0; i<count; i++)
        {
            data.open("database.txt", ios::in);
            data>>pcode>>pdis>>pname>>pprice;

            while(!data.eof())
            {
                if(pcode == arr_code[i])
                {
                   amount = pprice*arr_quantity[i];
                   dis = (amount - (amount * dis/100));
                   total = total + dis;
                   cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arr_quantity[i]<<"\t"<<pprice<<"\t"<<amount<<"\t"<<dis;
                }

                data>>pcode>>pname>>pprice>>pdis;
            }
        }

        data.close();
    }

    cout<<"\n\n\n_________________________________________________________\n";
    cout<<"Total Payble Amount : "<<total;

}
int main()
{
    
    shopping obj;
    obj.menu();

    return(0);
}