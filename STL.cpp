#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

class Order 
{
protected:
    int order_id;
    double tax;
    double total;
public:
    Order()
    {
        order_id = 10000;
        tax = 0;
        total = 0;
    }
    Order(int oi, double ta, double to)
    {
        order_id = oi;
        tax = ta;
        total = to;
    }
    //getter
    virtual int getOrderID() = 0;

    virtual double getTax() = 0;

    virtual double getTotal() = 0;

    //setter
    virtual void setOrderID() = 0;

    virtual void setOrderID(int id) = 0;

    virtual void setTax(int ta) = 0;

    virtual void setTotal(int to) = 0;

    virtual void print() = 0;
};

class OrderByPhone : public Order
{
private:
    string clerk_name;
    string phone_number;
public:
    OrderByPhone()
    {
        clerk_name = " ";
        phone_number = " ";
    }
    OrderByPhone(string cn, string pn)
    {
        clerk_name = cn;
        phone_number = pn;
    }
    //getter
    int getOrderID()
    {
        return order_id;
    }

    double getTax()
    {
        return tax;
    }

    double getTotal()
    {
        return total;
    }

    string getClerkName()
    {
        return clerk_name;
    }
    string getPhoneNumber()
    {
        return phone_number;
    }
    //setter
    void setOrderID()
    {
        srand(time(0));
		order_id = rand();
    }

    void setOrderID(int id)
    {
        order_id += id;
    }

    void setTax(int ta)
    {
        tax = ta;
    }

    void setTotal(int to)
    {
        total = to;
    }

    void setClerkName(string cn)
    {
        clerk_name = cn;        
    }
    void setPhoneNumber(string pn)
    {
        phone_number = pn;
    }
    void print()
    {
        cout << "Order ID: "<<getOrderID()<<"\tTax: "<<getTax()<<"\t\tTotal: "<<getTotal()<<'\n';
        cout << "Clerk Name: " << getClerkName() << "\tPhone Number: " << getPhoneNumber() << endl;
    }
};

class OrderByInternet : public Order
{
private:
    string url_address;
public:
    OrderByInternet()
    {
        url_address = " ";
    }
    OrderByInternet(string ua)
    {
        url_address = ua;
    }
    //getter
    int getOrderID()
    {
        return order_id;
    }

    double getTax()
    {
        return tax;
    }

    double getTotal()
    {
        return total;
    }
    string getUrlAddress()
    {
        return url_address;
    }
    //setter
    void setOrderID()
    {
        srand(time(0));
		order_id = rand();
    }

    void setOrderID(int id)
    {
        order_id += id;
    }

    void setTax(int ta)
    {
        tax = ta;
    }

    void setTotal(int to)
    {
        total = to;
    }
    void setUrlAddress(string ua)
    {
        url_address = ua;        
    }
    void print()
    {
        cout << "Order ID: "<<getOrderID()<<"\tTax: "<<getTax()<<"\t\tTotal: "<<getTotal()<<'\n';
        cout << "URL Address: " << getUrlAddress() <<endl;
    }
};

class Customer 
{
private:
    int account_no;
    string account_name;
    string shipping_add;
    vector<OrderByPhone>phone_list;
    vector<OrderByInternet>internet_list;

    //for making orders
    int order_id;
    int n_order;
    double tax;
    double total;
    string clerk_name;
    string phone_number;
    string url_address;

public:
    Customer()
    {
        account_no = 10000;
        account_name = " ";
        shipping_add = " ";
        n_order = 0;
    }
    Customer(int ano, string ana, string sad)
    {
        account_no = ano;
        account_name = ana;
        shipping_add = sad;
    }
    //getter
    int getAccountNo()
    {
        return account_no;
    }
    string getAccountName()
    {
        return account_name;
    }
    string getShippingAdd()
    {
        return shipping_add;
    }
    //setter
    void setAccountNo(int ano)
    {
        account_no += ano;
    }
    void setAccountName(string ana)
    {
        account_name = ana;
    }
    void setShippingAdd(string sad)
    {
        shipping_add = sad;
    }
    void addOrder(int choose)
    {
        if(choose == 1)
        {
            OrderByPhone* new_phone = new OrderByPhone();
            cout<<"Enter Clerk Name: ";
            cin.ignore();
            getline(cin, clerk_name);
            new_phone->setClerkName(clerk_name);

            cout<<"Enter Phone Number: ";
            cin>>phone_number;
            new_phone->setPhoneNumber(phone_number);

            cout<<"Enter Tax: RM";
            cin>>tax;
            new_phone->setTax(tax);

            cout<<"Enter Total: RM";
            cin>>total;
            new_phone->setTotal(total);

            new_phone->setOrderID(n_order);

            n_order++;
            phone_list.push_back(*new_phone);
        }
        else if(choose == 2)
        {
            OrderByInternet* new_internet = new OrderByInternet();
            cout<<"Enter URL: ";
            cin.ignore();
            getline(cin, url_address);
            new_internet->setUrlAddress(url_address);

            cout<<"Enter Tax: RM";
            cin>>tax;
            new_internet->setTax(tax);

            cout<<"Enter Total: RM";
            cin>>total;
            new_internet->setTotal(total);

            new_internet->setOrderID(n_order);

            n_order++;
            internet_list.push_back(*new_internet);
        }
        else
        {
            cout<<"Invalid input!\n";
        }
    }
    void printStatement()
    {
        tax = 0;
        total = 0;
        cout << "Account no: " << account_no << endl;
        cout << "Account name: " << account_name << endl;
        cout << "Shipping address: " << shipping_add << endl;

        for(vector<OrderByPhone>::iterator it = phone_list.begin(); it != phone_list.end(); it++)
        {
            it->print();
            tax += it->getTax();
            total += it->getTotal();
        }
        for(vector<OrderByInternet>::iterator it = internet_list.begin(); it != internet_list.end(); it++)
        {
            it->print();
            tax += it->getTax();
            total += it->getTotal();
        }

        cout<<"Total tax: RM"<<tax<<'\n';
        cout<<"Total payment: RM"<<total<<'\n';
    }
};

int main()
{
    // Variables for customer
    int acc_num;
    int n_account;
    string name;
    string shipp_addr;
    int index;
    bool login = false;

    // Variables for phone
    string clerk_nm;
    string phone_num;

    // Variables for order
    double tax;
    double total;
    int choose_ord;
    char pick;
    
    // Vectors to store the class
    vector<Customer*>customer_list;

    int choose = 100;
    while (choose != 4)
    {
        cout << "Welcome to HELP Inventory System" << endl;
        cout << "1.Create Customer" << endl;
        cout << "2.Add Order" << endl;
        cout << "3.Print Statement" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your option: ";
        cin >> choose;

        if(choose == 1)
        {
            Customer *new_customer = new Customer();
            cout<<"Enter Account Name: ";
            cin.ignore();
            getline(cin, name);

            cout<<"Enter Shipping Address: ";
            cin.ignore();
            getline(cin, shipp_addr);

            new_customer->setAccountName(name);
            new_customer->setAccountNo(n_account);
            new_customer->setShippingAdd(shipp_addr);

            customer_list.push_back(new_customer);
            n_account++;
            cout<<"Costumer "<<new_customer->getAccountName()<<" with account No "<<new_customer->getAccountNo()<<" has been successfully created\n";
        }
            
        else if(choose == 2)
        {
            if(customer_list.empty())
            {
                cout<<"Please create customer account first!\n";
                continue;
            }
            cout<<"Enter Customer Account No: ";
            cin>>acc_num;

            for(int i=0;i<customer_list.size();i++)
            {
                if(acc_num == customer_list[i]->getAccountNo())
                {
                    login = true;
                    index = i;
                }
            }
            if(login)
            {
                while(true)
                {
                    cout << "1. Order By Phone" << endl;
                    cout << "2. Order By Internet" << endl;
                    cout << "Enter your option: ";
                    cin >> choose_ord;

                    customer_list[index]->addOrder(choose_ord);

                    cout<<"Do you wish to continue? (y/n): ";
                    cin>>pick;

                    if(pick == 'n')
                    {
                        login = false;
                        break;
                    }
                }
            }
            else
            {
                cout<<"Invalid Account No!\n";
            }
            
        }
        else if(choose == 3)
        {
            if(customer_list.empty())
            {
                cout<<"Please create customer account first!\n";
                continue;
            }
            cout<<"Enter Customer Account No: ";
            cin>>acc_num;

            for(int i=0;i<customer_list.size();i++)
            {
                if(acc_num == customer_list[i]->getAccountNo())
                {
                    login = true;
                    index = i;
                }
            }
    
            if(login)
            {
                customer_list[index]->printStatement();
                login = false;
            }
            else
            {
                cout<<"Invalid Account No!\n";
            }
            
        }
        else if(choose == 4)
        {
            break;
        }
        else
        {
            cout<<"Invalid input\n";
        }
        cout<<"==================================================\n\n";
    }
}