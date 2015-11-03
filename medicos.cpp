#include <iostream>
#include <string>
#include <fstream>
using namepace std;


class medicine;
class manufacturer;
class computer;
class store;
class user;
class employee;
class customer;


class computer
{
    private:
        static user u[50];
        static int u_no;
        int pos;
    protected:
        static medicine med[1000];
        static manufacturer man[50];
        static store s[50];
        static int med_no; //no of medicines
        static int man_no; //no of manufacturers
        static int s_no;
    public:
        computer()
        {
            pos=0;
        }

        friend class medicine;
        friend class manufacturer;
        friend class store;
        friend class user;

        bool validID(string id1)
        {
            int i;
            for(i=0;i<u_no;i++)
            {
                if(u[i].id==id1)
                    return true;
            }
            return false;
        }

        int check_pass(string id1,string pass1)
        {
            for(i=0;i<u_no;i++)
            {
                if(u[i].id==id1)
                {
                    if(u[i].pass==pass1)
                        return i;
                    else
                        return -1;
                }
            }
            return -1;
        }

        void calculate() //to calculate med_no and man_no
        {

        }

        void load()
        {
            int i=0,j=0,id1;
            string name1,add1,no1;
            float price1;
            ifstream i1,i2;
            i1.open("manufacturer_db.txt",ios::in);
            i2.open("medicine_db.txt",ios::in);
            while(!i1.eof())
            {
                man[i]=new manufacturer;
                i1>>id1>>line;
                j=0;
                while(line[j]!='$')
                {
                    if(line[j])
                    name1[i++]=line[j];
                }

            }
        }

        void save()
        {

        }

        int login()
        {
            string id1,pass1;
            int ch;
            cout<<"Enter username: ";
            cin>>id1;
            if(!validID(id1))
            {
                cout<<"Invalid username.\n1.New user\n2.Login again\n3.Exit";
                cin>>ch;
                if(ch==1)
                    signup();
                else if(ch==2)
                    login();
                else
                    return -1;
            }
            else
            {
                pas:
                cout<<"Enter your password: ";
                cin>>pass1;
                pos=check_pass(id1,pass1);
                if(pos==-1)
                {
                    cout<<"Wrong password\n1.Enter password again\n2.Exit\n";
                    cin>>ch;
                    if(ch==1)
                        goto pas;
                    else
                        return -1;
                }
            }
            return 1;
        }

        int signup()
        {
            string name1,id1,pass1;
            char type1;
            int ch;
            cout<<"Enter a username: ";
            cin>>id1;
            if(usedID(id1))
            {
                cout<<"Username in use.\n1.Enter again\n2.Exit\n";
                cin>>ch;
                if(ch==1)
                    signup();
                else
                    return -1;
            }
            else
            {
                cout<<"Enter your name: "
                cin>>name1;
                cout<<"Enter your password: "
                cin>>pass1;
                cout<<"1.Customer\n2.Employee\n";
                cin>>ch2;
                if(ch2==1)
                {
                    type1='c';
                    u[u_no]=new customer;
                    u[u_no].new_user(id1,name1,pass1,type1);
                    u_no++;
                }
                else
                {
                    type1='e';
                    /*

                        employee verification
                        use file handling

                    */
                    u[u_no]=new employee;
                    u[u_no]=new_user(id1,name1,pass1,type1);
                    //add details to employee object from file correspondingly
                    u_no++;
                }
            }
            return 1;
        }

};

user computer::u[50]={};
int computer::u_no=0;
medicine computer::med[1000]={};
manufacturer computer::man[50]={};
store computer::s[50]={};
int computer::med_no=0;
int computer::man_no=0;
int computer::s_no=0;

class user
{
    protected:
        string id;
        string pass;
        char type;  //user or employee
        string name;
    public:
        user()
        {
            id=0;
            pass="";
            type='';
            name="";
        }

        void new_user(string id1,string name1,string pass1,char type1)
        {
            name=name1;
            pass=pass1;
            type=type1;
            id=id1;
        }

        void display()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"ID: "<<id<<endl;
        }

        string getid()
        {
            return id;
        }

        void update()
        {
            int ch,ch1;
            string pass1;
            cout<<"1.Name\n2.Password\n";
            cin>>ch;
            switch(ch)
            {
                case 1:cout<<"Enter your new name: ";
                    cin>>name;
                    break;
                case 2:pas:
                    cout<<"Enter your old password: ";
                    cin>>pass1;
                    if(pass=pass1)
                    {
                        cout<<"Enter your new password: ";
                        cin>>pass;
                    }
                    else
                    {
                        cout<<"Password incorrect\nDo you want to enter again?<Y=1,N=0>\n";
                        cin>>ch1;
                        if(ch1==1)
                            goto pas;
                        else
                            return;
                    }
                    break;
            }
            cout<<"Do you want to update again?<Y=1,N=0>\n";
            cin>>ch;
            if(ch==1)
                update();
        }

        medicine *get_med_by_id(int id1)
        {
            int i;
            for(i=0;i<med_no;i++)
            {
                if(med[i].id==id1)
                    return &med[i];
            }
            return null;
        }

        bool validID(int id1,int t)
        {
            if(t==1)
            {
                for(i=0;i<med_no;i++)
                {
                    if(med[i]==id1)
                        return true;
                }
            }
            else if(t==2)
            {
                for(i=0;i<man_no;i++)
                {
                    if(man[i]==id1)
                        return true;
                }
            }
            else
            {
                for(i=0;i<s_no;i++)
                {
                    if(s[i]==id1)
                        return true;
                }
            }
            return false;
        }

        int search_med_by_man(string man1)
        {
            int i,ctr=0,ch;
            for(i=0;i<man_no;i++)
            {
                if(man[i].name==name1)
                {
                    man[i].display();
                    cout<<endl;
                    ctr++;
                }
            }
            if(ctr==0)
                return -1;
            else
            {
                check:
                cout<<"Enter the manufacturer id\n";
                cin>>id1;
                if(!valid_id(id1))
                {
                    cout<<"Invalid ID. Do you want to enter again? <Y=1,N=0>\n";
                    cin>>ch;
                    if(ch==1)
                        goto check;
                    else
                        return -1;
                }
                return id1;
            }
        }

        int search_med_by_name(string name1)
        {
            int i,ctr=0,ch;
            for(i=0;i<med_no;i++)
            {
                if(med[i].name==name1)
                {
                    med[i].display(0);
                    cout<<endl;
                    ctr++;
                }
            }
            if(ctr==0)
                return -1;
            else
            {
                check:
                cout<<"Enter the medicine id\n";
                cin>>id1;
                if(!valid_id(id1))
                {
                    cout<<"Invalid ID. Do you want to enter again? <Y=1,N=0>\n";
                    cin>>ch;
                    if(ch==1)
                        goto check;
                    else
                        return -1;
                }
                return id1;
            }
        }

        int get_med_id()
        {
            int ch,ch1,id1;
            string man1,name1;
            cout<<"1.Add by name\n2.Add by ID\n3.Add by manufacturer\n"
            cin>>ch;
            switch(ch)
            {
                case 1:medloop1:
                    cout<<"\nEnter the name of the medicine: ";
                    cin>>name1;
                    id1=search_med_by_name(name1);
                    if(id1==-1)
                    {
                        cout<<"\nEnter a valid name\n1.Enter name again\n2.Search by another criteria\n";
                        cin>>ch1;
                        if(ch1==1)
                            goto medloop1;
                        else
                            return get_med_id();
                    }
                    break;
                case 2:medloop2:
                    cout<<"\nEnter the medicine id: ";
                    cin>>id1;
                    if(!valid_id())
                    {
                        cout<<"\nEnter a valid ID\n1.Enter ID again\n2.Search by another criteria\n";
                        cin>>ch1;
                        if(ch1==1)
                            goto medloop2;
                        else
                            return get_med_id();
                    }
                    break;
                case 3:medloop3:
                    cout<<"\n1.Enter the name of manufacturer\n";
                    cin>>man1;
                    id1=search_med_by_man(man1);
                    if(id1==-1)
                    {
                        cout<<"\nEnter a valid manufacturer name\n1.Enter manufacturer name again\n2.Search by another criteria\n";
                        cin>>ch1;
                        if(ch1==1)
                            goto medloop3;
                        else
                            return get_med_id();
                    }
                    break;
                default:cout<<"Wrong input\n1.Search medicines again\n2.Do other operation\n";
                    cin>>ch1;
                    if(ch1==1)
                        goto choiceloop;
                    else
                        return -1;
            }
            return id1;

        }

        friend class computer;

};


template <class T>
class employee:public user,public computer
{
    public:
/*
        medicine *shift(medicine m[1000],int pos)
        {
            int i;
            for(i=pos;i<med_no-1;i++)
                m[i]=m[i+1];
            med_no--;
            return m;
        }

        store *shift(store m[1000],int pos)
        {
            int i;
            for(i=pos;i<s_no-1;i++)
                m[i]=m[i+1];
            s_no--;
            return m;
        }

        manufacturer *shift(manufacturer m[50],int pos)
        {
            int i;
            for(i=pos;i<man_no-1;i++)
                m[i]=m[i+1];
            man_no--;
            return m;
        }
*/
        T *shift(T m[1000],int pos,char ch)
        {
            int i,x;
            switch(ch)
            {
                case 'm':x=med_no;
                    break;
                case 'M':x=man_no;
                    break;
                case 's':x=s_no;
                    break;
            }
            for(i=pos;i<x;i++)
                m[i]=m[i+1];
            switch(ch)
            {
                case 'm':med_no--;
                    break;
                case 'M':man_no--;
                    break;
                case 's':s_no--;
                    break;
            }
            return m;
        }

        void del_man()
        {
            int id1,ch,i;
            cout<<"Enter the manufacturer ID: ";
            if(!validID(id1,2))
            {
                cout<<"Enter a valid id.\n1.Enter id again\n2.Exit\n";
                cin>>ch;
                if(ch==1)
                    del_man();
                else
                    return;
            }
            else
            {
                for(i=0;i<man_no;i++)
                {
                    if(man[i].id==id1)
                    {
                        man=shift(man,i);
                        break;
                    }
                }
            }
        }

        void del_med()
        {
            int id1,ch,i;
            cout<<"Enter the medicine ID: ";
            if(!validID(id1,1))
            {
                cout<<"Enter a valid id.\n1.Enter id again\n2.Exit\n";
                cin>>ch;
                if(ch==1)
                    del_med();
                else
                    return;
            }
            else
            {
                for(i=0;i<med_no;i++)
                {
                    if(med[i].id==id1)
                    {
                        med=shift(med,i);
                        break;
                    }
                }
            }
        }

        void del_s()
        {
            int id1,ch,i;
            cout<<"Enter the store ID: ";
            if(!validID(id1,3))
            {
                cout<<"Enter a valid id.\n1.Enter id again\n2.Exit\n";
                cin>>ch;
                if(ch==1)
                    del_s();
                else
                    return;
            }
            else
            {
                for(i=0;i<s_no;i++)
                {
                    if(s[i].id==id1)
                    {
                        s=shift(s,i);
                        break;
                    }
                }
            }
        }

        void add_med()
        {
            int i,id1,flag=0;
            //med[med_no]=new medicine;
            med[med_no].set();
            cout<<"Enter manufacturer details: \n";
            cout<<"ID: ";
            cin>>id1;
            //checking if the manufacturer is an existing manufacturer by searching manufacturer list by its id
            for(i=0;i<man_no;i++)
            {
                if(man[i].id==id1)
                {
                    cout<<"\nManufacturer found\n\n";
                    man[i].display();
                    //med[med_no].mset(man[i].id,man[i].name,man[i].add,man[i].no);
                    //man[i].add_med(med[med_no].id,med[med_no].name,med[med_no].price,med[med_no].dd,med[med_no].mm,med[med_no].yy);
                    med[med_no].mset(&man[i]);
                    man[i].add_med(&med[med_no]);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<"\nManufacturer not found\nEnter the details of the manufacturer\n\n";
                //man[man_no]=new manufacturer;
                cout<<"Name: ";
                cin>>name1;
                cout<<"Address: ";
                cin>>add1;
                cout<<"Phone no: ";
                cin>>no1;
                man[man_no].set(id1,name1,add1,no1);
                //man[man_no].add_med(med[med_no].id,med[med_no].name,med[med_no].price,med[med_no].dd,med[med_no].mm,med[med_no].yy);
                man[man_no].add_med(&med[med_no]);
                med[med_no].mset(&man[man_no]);
                man_no++;
            }
            med_no++;
        }

        void add_man()
        {
            int id1;
            string name1,add1,no1;
            cout<<"Enter the details of the manufaturer: \n\n";
            //man[man_no]=new manufacturer;
            cout<<"ID: ";
            cin>>id1;
            cout<<"Name: ";
            cin>>name1;
            cout<<"Address: ";
            cin>>add1;
            cout<<"Phone no: ";
            cin>>no1;
            man[man_no].set(id1,name1,add1,no1);
            man_no++;
        }

        bool valid_store_id(int id1)
        {
            int i
            for(i=0;i<s_no;i++)
            {
                if(s[i].id==id1)
                    return true;
            }
            return false;
        }

        bool valid_id(int id1)
        {
            int i;
            for(i=0;i<med_no;i++)
            {
                if(med[i].id==id1)
                    return true;
            }
            return false;
        }

        void add_med_to_store()
        {
            int id1,ch,ch1,id2;
            string name1,man1;
            medicine *m;
            cout<<"\nEnter your store ID\n";
            cin>>id2;
            if(!valid_store_id(id2))
            {
                cout<<"Store not found, do you want to add a new store? <Y=1,N=0>\n";
                cin>>ch1;
                if(ch1==1)
                    add_store();
                else
                    return;
            }
            id1=get_med_id();
            m=get_med_by_id(id1);
            for(i=0;i<s_no;i++)
            {
                if(s[i].id==id2)
                {
                    store[i].addmed(m);
                    break;
                }
            }
        }

        void add_store()
        {
            int ch;
            s[s_no++].addstore();
            cout<<"\n\nDo you want to add medicines? <Y=1, N=0>\n"
            cin>>ch;
            if(ch==1)
                add_med_to_store();
        }

        void update(char c)
        {
            int i,id1,flag=0;
            switch(c)
            {
                case 'm':loop1:
                    cout<<"\nEnter the medicine id: "
                    cin>>id1;
                    for(i=0;i<med_no;i++)
                    {
                        if(med[i].id==id1)
                        {
                            med[i].update();
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        cout<<"\nMedicine not found. Do you want to enter id again?<Y=1,N=0>\n"
                        cin>>ch;
                        if(ch==1)
                            goto loop1;
                        else
                            return;
                    }
                    break;
                case 'M':loop2:
                    cout<<"\nEnter manufacturer id: ";
                    cin>>id1;
                    for(i=0;i<man_no;i++)
                    {
                        if(man[i].id==id1)
                        {
                            man[i].update();
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        cout<<"\nManufacturer not found. Do you want to enter id again?<Y=1,N=0>\n"
                        cin>>ch;
                        if(ch==1)
                            goto loop2;
                        else
                            return;
                    }
                    break;
                case 's':loop3:
                    cout<<"\nEnter store id: ";
                    cin>>id1;
                    for(i=0;i<s_no;i++)
                    {
                        if(s[i].id==id1)
                        {
                            s[i].update();
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        cout<<"\nStore not found. Do you want to enter id again?<Y=1,N=0>\n"
                        cin>>ch;
                        if(ch==1)
                            goto loop3;
                        else
                            return;
                    }
                    break;
            }
        }

};


class customer:public user,public computer
{
    medicine *cart;
    int *quant
    int c_no;
    public:
        customer()
        {
            cart=new medicine[100];
            quant=new int[100];
            c_no=0;
        }

        void add_med_to_cart(medicine m,int q)
        {
            cart[c_no]=m;
            quant[c_no]=q;
            c_no++;
        }

        void getMed()
        {
            int id1,q;
            medicine *m;
            id1=get_med_id();
            m=get_med_by_id(id1);
            cout<<"Enter quantity: ";
            cin>>q;
            if(checkQuantity(m,q))
                add_med_to_cart(*m,q);
            else
            {
                cout<<"Not enough medicines left"
            }

            //get stores with this med with quant and discount, hence net price
            //show total quant (opqrator overloading)
            //ask quantity

        }
}


class medicine
{
    int id;
    string name;
    float price;
    int dd,mm,yy;
    manufacturer *m;
    public:
        medicine()
        {
            id=0;
            name="";
            price=0.0;
            dd=0;mm=0;yy=0;
        }

        void display(int x)
        {
            int ch,ch1;
            cout<<"Details of the medicine = \n\n";
            cout<<"Medicine id= "<<id<<endl;
            cout<<"Name= "<<name<<endl;
            cout<<"Price= "<<price<<endl;
            cout<<"Expiry date= "<<dd<<"-"<<mm<<"-"<<yy<<endl;
            cout<<"For more details enter 1 else enter 0\n";
            cin>>ch;
            if(ch==1)
            {
                if(x==1)
                    cout<<"Details already shown\n";
                else
                {
                    cout<<"1.Manufacturer details\n2.Composition\n3.Diseases it can cure\n"
                    cin>>ch1;
                    if(ch1==1)
                        m->display();
                }
            }
        }

        bool checkDate(int d,int m,int y)
        {
            if (! (1<= m && m<=12) )
                return false;
            if (! (1<= d && d<=31) )
                return false;
            if ( (d==31) && (m==2 || m==4 || m==6 || m==9 || m==11) )
                return false;
            if ( (d==30) && (m==2) )
                return false;
            if ( (m==2) && (d==29) && (y%4!=0) )
                return false;
            if ( (m==2) && (d==29) && (y%400==0) )
                return true;
            if ( (m==2) && (d==29) && (y%100==0) )
                return false;
            if ( (m==2) && (d==29) && (y%4==0)  )
                return true;

            return true;
        }

        void set()
        {
            cout<<"Enter details of the medicine: \n";
            cout<<"ID: ";
            cin>>id;
            cout<<"Name: ";
            cin>>name;
            cout<<"price: ";
            cin>>price;
            date:
            cout>>"Expiry date (dd mm yyyy): ";
            cin>>dd>>mm>>yy;
            if(!checkDate(dd,mm,yy))
            {
                cout<<"Invalid date\n";
                goto date;
            }
        }

        void set(int id1,string name1,float price1,int dd1, int mm1, int yy1)
        {
            id=id1;
            name=name1;
            price=price1;
            dd=dd1;
            mm=mm1;
            yy=yy1;
        }

        /*void mset(int id1,string name1,string add1,string no1)
        {
            m.set(id1,name1,add1,no1);
        }*/

        void mset(manufacturer *m1)
        {
            m=m1;
        }

        int getid()
        {
            return id;
        }

        void update()
        {
            int ch;
            cout<<"\n1.Name\n2.Price\n3.Expiry Date\n";
            cin>>ch;
            switch(ch)
            {
                case 1:cout<<"\nEnter new name: ";
                    cin>>name;
                    break;
                case 2:cout<<"\nEnter new price: ";
                    cin>>price;
                    break;
                case 1:cout<<"\nEnter new expiry date(dd mm yyyy): ";
                    cin>>dd>>mm>>yy;
                    break;
            }
        }

        friend class user;
};


class manufacturer
{
    int id;
    string name;
    string add;
    string no;
    medinice *m[10];
    int med_no;
    public:
        manufacturer()
        {
            id=0;
            name="";
            add="";
            no="";
            med_no=0;
        }

        void display()
        {
            int i,ch;
            cout<<"Manufacturer details: \n\n";
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Address: "<<add<<endl;
            cout<<"Ph No.: "<<no<<endl;
            cout<<"For details of medicines press 1\n";
            cin>>ch;
            if(ch==1)
            {
                for(i=0;i<med_no;i++)
                    med[i].display(1);
            }
        }

        /*void addmed(int id1,string name1,float price1,int dd,int mm,int yy)
        {
            m[med_no]=new medicine;
            m[med_no].set(id1,name1,price1,dd,mm,yy);
            m[med_no].mset(id,name,add,no);
        }*/

        void addmed(medicine *m1)
        {
            m[med_no]=m1;
            med_no++;
        }

        void set(int id1,string name1,string add1,string no1)
        {
            id=id1;
            name=name1;
            add=add1;
            no=no1;
        }

         void update()
        {
            int ch;
            cout<<"\n1.Name\n2.Address\n3.Phone number\n";
            cin>>ch;
            switch(ch)
            {
                case 1:cout<<"\nEnter new name: ";
                    cin>>name;
                    break;
                case 2:cout<<"\nEnter new address: ";
                    cin>>add;
                    break;
                case 1:cout<<"\nEnter new phone no: ";
                    cin>>no;
                    break;
            }
        }

        friend class user;
};


class store
{
    int id;
    string name;
    string location;
    string address;
    string no;
    medicines **m;
    int med_no;
    int quantity[1000][2];
    public:
        store()
        {
            id=0;
            name="";
            location="";
            address="";
            no="";
            *m=new medicine[1000];
            med_no=0;
        }

        string getLocation()
        {
            return location;
        }

        void addstore()
        {
            int ch;
            cout<<"Enter details of the store: \n\n";
            cout<<"ID: ";
            cin>>id;
            cout<<"Name: ";
            cin>>name;
            cout<<"Location: ";
            cin>>location;
            cout<<"Address: ";
            cin>>address;
            cout<<"Phone no.: ";
            cin>>no;
            //cout<<"Do you want to add medicines?<Y=1,N=0>\n";
            //cin>>ch;
            //if(ch==1)
              //  addmed(id);
        }

        void addmed(medicine *m1)
        {
            m[med_no]=m1;
            quantity[med_no][0]=m1->id;
            cout<<"Enter quantity of the medicine\n";
            cin>>quantity[med_no][1];
        }

        int getQuantity(int id)
        {
            for(int i=0;i<med_no;i++)
            {
                if(quantity[i][0]==id)
                    return quantity[i][1];
            }
            return -1;
        }

        void display()
        {
            cout<<"Details of the store are: \n\n";
            cout<<"ID: "<<id<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Location: "<<location<<endl;
            cout<<"Address: "<<address<<endl;
            cout<<"Phone no.: "<<no<<endl;
            cout<<"Do you want to view the mdecines available in the store?<Y=1,N=0>\n";
            int ch;
            cin>>ch;
            if(ch==1)
                showmed();
        }

        void showmed()
        {
            int j;
            for(int i=0;i<med_no;i++)
            {
                cout<<i+1<<")\n";
                m[i]->display(0);
                cout<<"\nQuantity left: "
                for(j=0;j<med_no;j++)
                {
                    if(quantity[j][0]==m[i]->id)
                        cout<<quantity[j][1];

                }
                cout<<endl<<endl;
            }
        }

        void update()
        {
            int ch;
            cout<<"\n1.Name\n2.Location and Address\n3.Phone number\n4.Medicine quantity\n";
            cin>>ch;
            switch(ch)
            {
                case 1:cout<<"\nEnter new name: ";
                    cin>>name;
                    break;
                case 2:cout<<"\nEnter new location: ";
                    cin>>location;
                    cout<<"\nEnter new address: ";
                    cin>>address;
                    break;
                case 3:cout<<"\nEnter new Phone number: ";
                    cin>>no;
                    break;
                case 4:medloop:
                    cout<<"\nEnter the ID of the medicine: ";
                    cin>>med_id;
                    for(i=0;i<med_no;i++)
                    {
                        if(m[i]->getid()==med_id)
                        {
                            cout<<"Enter the new quantity of "<<m[i]->getname()<<": ";
                            for(j=0;j<med_no;j++)
                            {
                                if(quantity[j][0]==m[i]->id)
                                {
                                    cin>>quantity[j][1];
                                    break;
                                }
                            }
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0)
                    {
                        cout<<"\nMedicine not found. Do you want to enter id again?<Y=1,N=0>\n";
                        cin>>ch1;
                        if(ch1==1)
                            goto medloop;
                        else
                            return;
                    }
                    break;
            }
        }

        friend class user;
};

