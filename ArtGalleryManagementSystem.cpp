#include <iostream>
#include <fstream>
using namespace std;
class Arts
{
private:
    int art_id;
    string art_title;
    int art_year;
    float art_price;
    string art_artist;

public:
    Arts()
    {
        art_id = 0;
        art_title = "NULL";
        art_year = 0;
        art_price = 0.0;
        art_artist = "NULL";
    }
    Arts(int art_id, string art_title, int art_year, float art_price, string art_artist)
    {
        this->art_id = art_id;
        this->art_title = art_title;
        this->art_year = art_year;
        this->art_price = art_price;
        this->art_artist = art_artist;
    }
    void set_id(int art_id)
    {
        this->art_id = art_id;
    }
    void set_title(string art_title)
    {
        this->art_title = art_title;
    }
    void set_year(int art_year)
    {
        this->art_year = art_year;
    }
    void set_price(float art_price)
    {
        this->art_price = art_price;
    }
    void set_artist(string art_artist)
    {
        this->art_artist = art_artist;
    }
    int get_id()
    {
        return art_id;
    }
    string get_title()
    {
        return art_title;
    }
    int get_year()
    {
        return art_year;
    }
    float get_price()
    {
        return art_price;
    }
    string get_artist()
    {
        return art_artist;
    }
};

class Paintings : public Arts
{
private:
    string paint_type;
    float painting_height;
    float painting_width;

public:
    Paintings(int id = 0, string title = "NULL", int year = 0, float price = 0.0, string artist = "NULL", string paint_type = "NULL", float painting_height = 0.0, float painting_width = 0.0)
        : Arts(id, title, year, price, artist)
    {
        this->paint_type = paint_type;
        this->painting_height = painting_height;
        this->painting_width = painting_width;
    }
    void set_type(string paint_type)
    {
        this->paint_type = paint_type;
    }
    void set_height(float painting_height)
    {
        this->painting_height = painting_height;
    }
    void set_width(float painting_width)
    {
        this->painting_width = painting_width;
    }
    string get_type()
    {
        return paint_type;
    }
    float get_height()
    {
        return painting_height;
    }
    float get_width()
    {
        return painting_width;
    }
    friend ostream &operator<<(ostream &output, Paintings &obj);
    friend istream &operator>>(ostream &input, Paintings &obj);
};
ostream &operator<<(ostream &output, Paintings &obj)
{
    output << "\n**********";
    output << "\n ID: " << obj.get_id();
    output << "\n TITLE: " << obj.get_title();
    output << "\n YEAR: " << obj.get_year();
    output << "\n PRICE: " << obj.get_price();
    output << "\n ARTIST: " << obj.get_artist();
    output << "\n PAINT TYPE: " << obj.get_type();
    output << "\n PAINT HEIGHT: " << obj.get_height() << " inch";
    output << "\n PAINT WIDTH: " << obj.get_width() << " inch";
    output << "\n**********";
    return output;
}

class Sculptures : public Arts
{
private:
    string Material;
    float Height;
    float Weight;

public:
    Sculptures(int id = 0, string title = "NULL", int year = 0, float price = 0.0, string artist = "NULL", string Material = "NULL", float Height = 0.0, float Weight = 0.0)
        : Arts(id, title, year, price, artist)
    {
        this->Material = Material;
        this->Height = Height;
        this->Weight = Weight;
    }
    void set_material(string Material)
    {
        this->Material = Material;
    }
    void set_Height(float Height)
    {
        this->Height = Height;
    }
    void set_Weight(float Weight)
    {
        this->Weight = Weight;
    }
    string get_material()
    {
        return Material;
    }
    float get_Height()
    {
        return Height;
    }
    float get_Weight()
    {
        return Weight;
    }
    friend ostream &operator<<(ostream &output, Sculptures &obj);
    friend istream &operator>>(ostream &input, Sculptures &obj);
};
ostream &operator<<(ostream &output, Sculptures &obj)
{
    output << "\n**********";
    output << "\n ID: " << obj.get_id();
    output << "\n TITLE: " << obj.get_title();
    output << "\n YEAR: " << obj.get_year();
    output << "\n PRICE: " << obj.get_price();
    output << "\n ARTIST: " << obj.get_artist();
    output << "\n MATERIAL: " << obj.get_material();
    output << "\n SCULPTURE HEIGHT: " << obj.get_Height() << " inch";
    output << "\n SCULPTURE WEIGHT: " << obj.get_Weight() << " pounds";
    output << "\n**********";
    return output;
}

class Gallery
{
public:
    virtual void Add() = 0;
    virtual void View() = 0;
    virtual void Update() = 0;
    virtual void Search() = 0;
};

class Customer : public Gallery
{
private:
    string c_name;
    string c_address;
    double c_phone;

public:
    Customer()
    {
        c_name = "NULL";
        c_phone = 0;
        c_address = "NULL";
    }
    Customer(string c_name, string c_address, double c_phone)
    {
        this->c_name = c_name;
        this->c_address = c_address;
        this->c_phone = c_phone;
    }
    void set_name(string c_name)
    {
        this->c_name = c_name;
    }
    void set_address(string c_address)
    {
        this->c_address = c_address;
    }
    void set_phone(double c_phone)
    {
        this->c_phone = c_phone;
    }
    string get_name()
    {
        return c_name;
    }
    string get_address()
    {
        return c_address;
    }
    double get_phone()
    {
        return c_phone;
    }
    float BuyArt(){
        float temp_price=0.0;
        int id, year;
        string title, artist, t;
        float price, h, w;
        int choice;
        cout<<"\nWhat do you want to Buy? \n1) Painting  \n2) Sculpture";
        cin>>choice;
        if(choice==1)
        {
        int check;
        cout<<"\nEnter the ID of Painting you want to buy: ";
        cin>>check;
        ifstream inPaint("paintingDetails.txt");
        while(inPaint >> id >> title >> year >> price >> artist >> t >> h >> w){
            if(id==check){
            cout<<"\nID Found :)";
            temp_price=price;
            }
        }
        }
        if(choice==2)
        {
        int check;
        cout<<"\nEnter the ID of Sculpture you want to buy: ";
        cin>>check;
        ifstream inSculpture("sculptureDetails.txt");
        while(inSculpture >> id >> title >> year >> price >> artist >> t >> h >> w){
            if(id==check){
            cout<<"\nID Found :)";
            temp_price=price;
            }
        }
        }
        cout<<"\nYou have to Pay Rs: ";
  return temp_price;
       
    }
};

class Artist : public Gallery
{
private:
    string artist_name;
    string artist_country;
    double artist_contact;

public:
    Artist()
    {
        artist_name = "NULL";
        artist_contact = 0;
        artist_country = "NULL";
    }
    Artist(string artist_name, string artist_country, double artist_contact)
    {
        this->artist_name = artist_name;
        this->artist_country = artist_country;
        this->artist_contact = artist_contact;
    }
    void set_name(string artist_name)
    {
        this->artist_name = artist_name;
    }
    void set_country(string artist_country)
    {
        this->artist_country = artist_country;
    }
    void set_contact(double artist_contact)
    {
        this->artist_contact = artist_contact;
    }
    string get_name()
    {
        return artist_name;
    }
    string get_country()
    {
        return artist_country;
    }
    double get_contact()
    {
        return artist_contact;
    }
    int SellArt()
    {
        int year;
        string title, artist, t;
        float h, w , price;
        int choice;
        cout<<"\nWhat do you want to Sell? \n1) Painting \n2) Sculpture  \nPress Any key to Exit";
        cin>>choice;

        if (choice == 1)
        {
            ofstream out("SellsPaintings.txt");
            cout << "\n| Adding Painting Details |" << endl;
            cout << "Enter Title: " << endl;
            cin >> title;
            cout << "Enter Year: " << endl;
            cin >> year;
            cout << "Enter Price: " << endl;
            cin >> price;
            cout << "Enter Artist Name: " << endl;
            cin >> artist;
            cout << "Enter Paint type: " << endl;
            cin >> t;
            cout << "Enter Height: " << endl;
            cin >> h;
            cout << "Enter Width: " << endl;
            cin >> w;

            out << title << " " << year << " " << price << " " << artist << " " << t
                << " " << h << " " << w << " " <<endl;
            out.close();
        }
        if (choice == 2)
        {
            ofstream out("SellsSculptures.txt");
            cout << "\n| Adding Sculpture Details |" << endl;
             cout << "Enter Title: " << endl;
            cin >> title;
            cout << "Enter Year: " << endl;
            cin >> year;
            cout << "Enter Price: " << endl;
            cin >> price;
            cout << "Enter Artist Name: " << endl;
            cin >> artist;
            cout << "Enter material: " << endl;
            cin >> t;
            cout << "Enter Height: " << endl;
            cin >> h;
            cout << "Enter Weight: " << endl;
            cin >> w;

            out << title << " " << year << " " << price << " " << artist << " " << t
                << " " << h << " " << w << " " <<endl;
            out.close();
        }
        return choice;
    }
};

template<class T>
class Admin : public Customer, public Artist
{
private:
    int admin_id;
    string admin_name;
    T admin_password;
    Customer *c;
    Artist *a;

public:
    Admin()
    {
        admin_name = "NULL";
        admin_password = 0;
    }
    Admin(string admin_name, T admin_password = 0)
    {
        this->admin_name = admin_name;
        this->admin_password = admin_password;
    }
    void set_name(string admin_name)
    {
        this->admin_name = admin_name;
    }
    void set_password(T admin_password)
    {
        this->admin_password = admin_password;
    }
    string get_name()
    {
        return admin_name;
    }
    T get_password()
    {
        return admin_password;
    }
    bool Authentication(T check)
    {
        if (check == admin_password)
            return true;
        else
            return false;
    }

    void Add()
    {
        int id, year;
        string title, artist, t;
        float price, h, w;
        int choice;
        cout << "1) Painting. \n 2) Sculpture";
        cin >> choice;
        if (choice == 1)
        {
            cout << "\n| Adding Painting Details |" << endl;
            cout << "Enter Id: " << endl;
            cin >> id;
            cout << "Enter Title: " << endl;
            cin >> title;
            cout << "Enter Year: " << endl;
            cin >> year;
            cout << "Enter Price: " << endl;
            cin >> price;
            cout << "Enter Artist Name: " << endl;
            cin >> artist;
            cout << "Enter Paint type: " << endl;
            cin >> t;
            cout << "Enter Height: " << endl;
            cin >> h;
            cout << "Enter Width: " << endl;
            cin >> w;

            ofstream out("paintingDetails.txt", ios::app);
            Paintings p(id, title, year, price, artist, t, h, w);
            out << p.get_id() << " " << p.get_title() << " " << p.get_year() << " " << p.get_price() << " " << p.get_artist()
                << " " << p.get_type() << " " << p.get_height() << " " << p.get_width() << endl;
            out.close();
        }
        if (choice == 2)
        {
            cout << "\n| Adding Sculpture Details |" << endl;
            cout << "Enter Id: " << endl;
            cin >> id;
            cout << "Enter Title: " << endl;
            cin >> title;
            cout << "Enter Year: " << endl;
            cin >> year;
            cout << "Enter Price: " << endl;
            cin >> price;
            cout << "Enter Artist Name: " << endl;
            cin >> artist;
            cout << "Enter Sculpture Material: " << endl;
            cin >> t;
            cout << "Enter Height: " << endl;
            cin >> h;
            cout << "Enter Weight: " << endl;
            cin >> w;
            ofstream out("sculptureDetails.txt", ios::app);
            Sculptures s(id, title, year, price, artist, t, h, w);
            out << s.get_id() << " " << s.get_title() << " " << s.get_year() << " " << s.get_price() << " " << s.get_artist()
                << " " << s.get_material() << " " << s.get_Height() << " " << s.get_Weight();
            out.close();
            cout << s;
        }
    }
    void View()
    {
        int id, year;
        string title, artist, t;
        float price, h, w;
        cout << "\nWhich Details You Want To View: \n1)Painting \n2)Sculpture";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "\n| AVAILABLE PAINTINGS |";
            ifstream inPaint("paintingDetails.txt");
            while (inPaint >> id >> title >> year >> price >> artist >> t >> h >> w)
            {
                Paintings p(id, title, year, price, artist, t, h, w);
                cout << p;
            }
        }
        if (choice == 2)
        {
            cout << "\n| AVAILABLE SCULPTURES |";
            ifstream inSculpture("sculptureDetails.txt");
            while (inSculpture >> id >> title >> year >> price >> artist >> t >> h >> w)
            {
                Sculptures s(id, title, year, price, artist, t, h, w);
                cout << s;
            }
        }
    }

    void Search()
    {
        int id, year;
        float price, h, w;
        string title, artist, t;
        cout << "\nWhich Details You Want To Search: \n1)Painting \n2)Sculpture";
        int choice;
        cin >> choice;
        int check;
        if (choice == 1)
        {
            int check, index, i = 0;
            cout << "\nEnter ID to search:";
            cin >> check;
            ifstream getData("paintingDetails.txt");
            if (!getData)
            {
                cout << "File not exists";
                return;
            }
            else
            {
                while (getData >> id >> title >> year >> price >> artist >> t >> h >> w)
                {
                    if (id == check)
                    {
                        index = i;
                        cout << "\nID found at index: " << index << endl;
                        Paintings obj(id, title, year,price,artist,t,w,h );
                        cout<<obj;
                        break;
                    }
                    i++;
                }
            }
            getData.close();
        }
        if (choice == 2)
        {
            int check, index, i = 0;
            cout << "\nEnter ID to search:";
            cin >> check;
            ifstream getData("sculptureDetails.txt");
            if (!getData)
            {
                cout << "File not exists";
                return;
            }
            else
            {
                while (getData >> id >> title >> year >> price >> artist >> t >> h >> w)
                {
                    if (id == check)
                    {
                        index = i;
                        cout << "\nID found at index: " << index << endl;
                        Sculptures obj(id, title, year,price,artist,t,w,h );
                        cout<<obj;
                       break;
                    }
                    i++;
                }
            }
            getData.close();
        }
    }

    void Update()
    {
        int id, year;
        float price, h, w;
        string title, artist, t;
        cout << "\nWhich Details You Want To Update: \n1)Painting \n2)Sculpture";
        int choice;
        cin >> choice;
        int check;
        if (choice == 1)
        {
            cout << "\nEnter ID to Update: ";
            cin >> check;

            int i = 0, index, size = 0;
            ifstream getData1("paintingDetails.txt");

            while (getData1 >> id >> title >> year >> price >> artist >> t >> h >> w)
            {
                size++;
            }
            // cout << size;
            getData1.close();
            ifstream getData2("paintingDetails.txt");
            string titleArray[size], artistArray[size], tArray[size];
            int idArray[size], yearArray[size];
            float wArray[size], hArray[size], priceArray[size];

            while (getData2 >> idArray[i] >> titleArray[i] >> yearArray[i] >> priceArray[i] >> artistArray[i] >> tArray[i] >> hArray[i] >> wArray[i])
            {
                if (idArray[i] == check)
                {
                    index = i;
                }
                i++;
            }
            getData2.close();
            idArray[index] = check;
            cout << "\n| UPDATING |" << endl;
            cout << "\nEnter TITLE: ";
            cin >> titleArray[index];
            cout << "\nEnter YEAR: ";
            cin >> yearArray[index];
            cout << "\nEnter PRICE: ";
            cin >> priceArray[index];
            cout << "\nEnter ARTIST: ";
            cin >> artistArray[index];
            cout << "\nEnter PAINT TYPE: ";
            cin >> tArray[index];
            cout << "\nEnter WIDTH: ";
            cin >> wArray[index];
            cout << "\nEnter HEIGHT: ";
            cin >> hArray[index];

            ofstream dataChange("paintingDetails.txt");
            for (int j = 0; j < i; j++)
                if (j == index)
                {
                    dataChange << idArray[index] << "  " << titleArray[index] << "  " << yearArray[index] << "  " << priceArray[index] << "  " << artistArray[index] << "  " << tArray[index] << "  " << hArray[index] << "  " << wArray[index] << endl;
                }
                else
                {
                    dataChange << idArray[j] << "  " << titleArray[j] << "  " << yearArray[j] << "  " << priceArray[j] << "  " << artistArray[j] << "  " << tArray[j] << "  " << hArray[j] << "  " << wArray[index] << endl;
                }
            dataChange.close();
        }

        if (choice == 2)
        {
            cout << "\nEnter ID to Update: ";
            cin >> check;
            int i = 0, index, size = 0;
            ifstream getData1("sculptureDetails.txt");

            while (getData1 >> id >> title >> year >> price >> artist >> t >> h >> w)
            {
                size++;
            }
            // cout << size;
            getData1.close();
            ifstream getData2("sculptureDetails.txt");
            string titleArray[size], artistArray[size], tArray[size];
            int idArray[size], yearArray[size];
            float wArray[size], hArray[size], priceArray[size];

            while (getData2 >> idArray[i] >> titleArray[i] >> yearArray[i] >> priceArray[i] >> artistArray[i] >> tArray[i] >> hArray[i] >> wArray[i])
            {
                if (idArray[i] == check)
                {
                    index = i;
                }
                i++;
            }
            getData2.close();
            idArray[index] = check;
            cout << "\n| UPDATING |" << endl;
            cout << "\nEnter TITLE: ";
            cin >> titleArray[index];
            cout << "\nEnter YEAR: ";
            cin >> yearArray[index];
            cout << "\nEnter PRICE: ";
            cin >> priceArray[index];
            cout << "\nEnter ARTIST: ";
            cin >> artistArray[index];
            cout << "\nEnter MATERIAL: ";
            cin >> tArray[index];
            cout << "\nEnter HEIGHT: ";
            cin >> hArray[index];
            cout << "\nEnter WEIGHT: ";
            cin >> wArray[index];

            ofstream dataChange("sculptureDetails.txt");
            for (int j = 0; j < i; j++)
                if (j == index)
                {
                    dataChange << idArray[index] << "  " << titleArray[index] << "  " << yearArray[index] << "  " << priceArray[index] << "  " << artistArray[index] << "  " << tArray[index] << "  " << hArray[index] << "  " << wArray[index] << endl;
                }
                else
                {
                    dataChange << idArray[j] << "  " << titleArray[j] << "  " << yearArray[j] << "  " << priceArray[j] << "  " << artistArray[j] << "  " << tArray[j] << "  " << hArray[j] << "  " << wArray[index] << endl;
                }
            dataChange.close();
        }
    }

      void artistPaintsManage(){
        int year, id;
        float price, h,w;
        string title, artist, t;
        int i=0;
        ifstream in("SellsPaintings.txt");
        while(in>>title>>year>>price>>artist>>t>>w>>h){
            cout<<"Enter ID for Painting: ";
            cin >>id;
            ofstream out("paintingDetails.txt", ios::app);
            Paintings p(id, title, year, price, artist, t, h, w);
            out << p.get_id() << " " << p.get_title() << " " << p.get_year() << " " << p.get_price() << " " << p.get_artist()
                << " " << p.get_type() << " " << p.get_height() << " " << p.get_width() << endl;
            out.close();
            i++;
        }
        cout<<"\n"<<i<<" Records have been Saved!";

    }
    void artistSculptureManage(){
        int year, id;
        float price, h,w;
        string title, artist, t;
        int i=0;
        ifstream in("SellsSculptures.txt");
        while(in>>title>>year>>price>>artist>>t>>w>>h){
            cout<<"Enter ID for Sculpture: ";
            cin >>id;
            ofstream out("sculptureDetails.txt", ios::app);
            out<<"\n";
            Sculptures p(id, title, year, price, artist, t, h, w);
            out << p.get_id() << " " << p.get_title() << " " << p.get_year() << " " << p.get_price() << " " << p.get_artist()
                << " " << p.get_material() << " " << p.get_Height() << " " << p.get_Weight();
            out.close();
            i++;
        }
        cout<<"\n"<<i<<" Records have been Saved!";

    }
    void customerManage(){
        c=new Admin;
         cout<<c->BuyArt();
    }
};
class Visitors_of_exhibition
{
    private:
    string v_name;
    string v_country;
    double v_phone;
    public:
    Visitors_of_exhibition(string v_name="NULL", string v_country="NULL", double v_phone=0)
    {
        this->v_name=v_name;
        this->v_country=v_country;
        this->v_phone=v_phone;
    }
    void set_name(string name){
        v_name=name;
    }
    void set_country(string country){
        v_country=country;
    }
    void set_phone(double phone){
        v_phone=phone;
    }
       string get_name(){
        return v_name;
    }
    string get_country(){
        return v_country;
    }
    double get_phone(){
        return v_phone;
    }
    void save_visitors(){
        ofstream out("Visitors.txt",ios::app);
            out<<v_name<<" "<<v_country<<" "<<v_phone<<endl;
        
    }

};
class Exhibition
{ 
    private:
    string e_location;
    string start_date;
    string end_date;
    Visitors_of_exhibition visitor;
    public:
    Exhibition(string l="NULL", string sd="NULL", string ed="NULL"){
        e_location=l;
        start_date=sd;
        end_date=ed;
    }
    void set_visitor(){
        string name, country;
        double phone;
        cout<<"Enter Name of Visitor: ";
        cin>>name;
        visitor.set_name(name);
        cout<<"Enter Country of Visitor: ";
        cin>>country;
        visitor.set_country(country);
        cout<<"Enter phone number of visitor: ";
        cin>>phone;
        visitor.set_phone(phone);
        visitor.save_visitors();
    }
    void Display(){
        string name, country;
        double phone;
        cout<<"\n| EXHIBITION DETAILS |"<<endl;
        cout<<"\nLOCATION: "<<e_location;
        cout<<"\nSTART DATE: "<<start_date;
        cout<<"\nEND DATE: "<<end_date;
        cout<<"\n*****************************";
        cout<<"\n| VISTITORS |";
        ifstream in("Visitors.txt");
            while(in>>name>>country>>phone){
                cout<<"\nVisitor Name: "<<name;
                cout<<"\nVisitor Country: "<<country;
                cout<<"\nVisitor Phone: "<<phone;
                cout<<"\n*****************************";
            }
        
    }
    void exhibition_enter(){
        ofstream exhibit("exhibition_details.txt",ios::app);
        cout<<"Enter the start Date for exhibition: ";
        cin>>start_date;
        cout<<"Enter the End Date for exhibition: ";
        cin>>end_date;
        cout<<"Enter the Location of Exhibition: ";
        cin>>e_location;
        exhibit<<start_date<<"  "<<end_date<<"  "<<e_location<<endl;
        int num_of_visitors;
        cout<<"How many visitors you want to Enter? ";
        cin>>num_of_visitors;
        Exhibition visitor[num_of_visitors];
        for(int i=0;i<num_of_visitors;i++){
            visitor[i].set_visitor();
           
    }
    } 
    void exhibition_record(){
        ifstream input("exhibition_details.txt");
        while(input>>start_date>>end_date>>e_location){
        cout<<"\nSTART DATE: "<<start_date;
        cout<<"\nEND DATE: "<<end_date;
        cout<<"\nLOCATION: "<<e_location;
        cout<<"\n*****************************";
        }
    }

};

int main()
{
   Admin<double> a;
   a.set_password(221437);
  int loop=0;
  cout<<"\n*****ART GALLERY MANAGEMENT SYSTEM***"<<endl;
  while(loop==0){
    int choice;
    cout<<"\n| MENU |  \n1) Admin  \n2) Customer  \n3) Artist \n4) Exhibition Setting \n5) Exit";
    cin>>choice;
    if(choice==1){
        int  menu=-1;
        while(menu!=0){
        cout<<"\n1) Save Arts \n2) View Arts \n3) Update Arts \n4) Search Arts \n5) Exit";
        cin>>menu;
        if(menu==1){
            a.Add();
        }
        else if(menu==2){
            a.View();
        }
        else if(menu==3){
            a.Update();
        }
        else if(menu==4){
            a.Search();
        }
        else if(menu==5){
            menu=0;
        }
        else
        cout<<"Enter Valid Input.";
    }
    }
    else if(choice==2){
        a.View();
        a.customerManage();
    }
    else if(choice==3){
        double password;
        if(a.SellArt()==1){cout<<"\n| Hello Admin |";
        cout<<"\n Enter your password: ";
        cin>>password;
        if(a.Authentication(password)){
        a.artistPaintsManage();}
        }
        if(a.SellArt()==2){cout<<"\n| Hello Admin |";
        cout<<"\n Enter your password: ";
        cin>>password;
        if(a.Authentication(password)){
        a.artistSculptureManage();}
        }
        
    }
    else if(choice==4){
        double password;
        cout<<"\n Enter your password: ";
        cin>>password;
         if(a.Authentication(password)){
            Exhibition exhibition;
            exhibition.exhibition_enter();
            exhibition.Display();
         }
    }
    else{
        cout<<"\nBye :)";
        loop=1;
    }
  }
  
}