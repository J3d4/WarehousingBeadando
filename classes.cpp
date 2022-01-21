#include "classes.h"
#include <iostream>
#include <list>
#include <iterator>
#include <fstream>

using namespace std;

class Goods {
    protected:
        string name;
        string manufacturer;
        int code;
        int quantity;
        int price;
    public:
        Goods() : Goods("Unidentified"){
        }

        Goods(string name) : Goods(name, "Unidentified"){
        }

        Goods(string name, string manufacturer) : Goods(name, manufacturer, 9999){
        }

        Goods(string name, string manufacturer, int code) : Goods(name, manufacturer, code, -1){
        }

        Goods(string name, string manufacturer, int code, int quantity) : Goods(name, manufacturer, code, quantity, -1){
        }

        Goods(string name, string manufacturer, int code, int quantity, int price){
            setname(name);
            this->manufacturer = manufacturer;
            this->code = code;
            this->quantity = quantity;
            this->price = price;
        }

        //Getter, Setter
        string getname(){
            return name;
        }

        void setname(string value){
            if(value.length() == 8){
                name = value;
            } else throw "Nem megfelelő a megadott EAN kód hossza!";

        }

        string getManufacturer(){
            return manufacturer;
        }

        int getCode(){
            return code;
        }

        int getQuantity(){
            return quantity;
        }

        int getPrice(){
            return price;
        }

        virtual string getTypeOfPrice(){
            return "None";
        }



        // Metódusok
        virtual void printInformation(){
            cout << "\nJármű adatai:" << endl;
            cout << "\n  Rendszám:\t " << name << endl;
            cout << "  Típus:\t " << manufacturer << endl;
            cout << "  Gyártás éve:\t " << code << endl;
            cout << "  Kapacitás:\t " << quantity << endl;
            cout << "  Igénybevétel:\t " << price << endl;
        }

        virtual Goods generate(){
            cout << "  Kérem a jármű rendszámát (NNN-NNN): ";
            string name;
            cin >> name;

            cout << "  Kérem a jármű típusát: ";
            string manufacturer;
            cin >> manufacturer;

            cout << "  Kérem a jármű gyártási évét: ";
            int code;
            cin >> code;

            cout << "  Kérem a jármű kapacitását: ";
            int quantity;
            cin >> quantity;

            cout << "  Kérem a jármű igénybevételét: ";
            int price;
            cin >> price;
            Goods vh(name, manufacturer, code, quantity, price);
            return vh;
        }
};

class QuantityGoods : public Goods {
    using Goods::Goods;
    public:

        void printInformation(){
            cout << "\nMunkagép adatai:" << endl;
            cout << "\n  Rendszám:\t " << name << endl;
            cout << "  Típus:\t " << manufacturer << endl;
            cout << "  Gyártás éve:\t " << code << endl;
            cout << "  Teljesítmény:\t " << quantity << " kW"<< endl;
            cout << "  Igénybevétel:\t " << price << " munkaóra"<< endl;
        }

        Goods generate(){
            cout << "  Kérem a munkagép rendszámát (NNN-NNN): ";
            string name;
            cin >> name;

            cout << "  Kérem a munkagép típusát: ";
            string manufacturer;
            cin >> manufacturer;

            cout << "  Kérem a munkagép gyártási évét: ";
            int code;
            cin >> code;

            cout << "  Kérem a munkagép teljesítményét (kW): ";
            int quantity;
            cin >> quantity;

            cout << "  Kérem a munkagép igénybevételét (munkaóra): ";
            int price;
            cin >> price;
            QuantityGoods wm(name, manufacturer, code, quantity, price);
            return wm;
        }

        string getManufacturerOfprice(){
            return "munkaóra";
        }
};

class LedigGoods : public Goods {
    using Goods::Goods;
    public:

        void printInformation(){
            cout << "\nTeheautó adatai:" << endl;
            cout << "\n  Rendszám:\t " << name << endl;
            cout << "  Típus:\t " << manufacturer << endl;
            cout << "  Gyártás éve:\t " << code << endl;
            cout << "  Teherbírás:\t " << quantity << " tonna"<< endl;
            cout << "  Igénybevétel:\t " << price << " km"<< endl;
        }

        Goods generate(){
            cout << "  Kérem a teherautó rendszámát (NNN-NNN): ";
            string name;
            cin >> name;

            cout << "  Kérem a teherautó típusát: ";
            string manufacturer;
            cin >> manufacturer;

            cout << "  Kérem a teherautó gyártási évét: ";
            int code;
            cin >> code;

            cout << "  Kérem a teherautó teherbírását (tonna): ";
            int quantity;
            cin >> quantity;

            cout << "  Kérem a teherautó igénybevételét (km): ";
            int price;
            cin >> price;
            LedigGoods t(name, manufacturer, code, quantity, price);
            return t;
        }

        string getManufacturerOfprice(){
            return "km";
        }
};