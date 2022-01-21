#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include "classes.h"

using namespace std;

// Osztályok

// Menü kirajzolásához segéd függvények
void clear(){
    cout << "\x1B[2J\x1B[H";
}

int drawMenu(string array[], int size){
    int answer = 0;

    int i;
    for (i = 0; i < size; ++i){
      cout << " [" << i << "] " << array[i] << endl;
    }

    //cout << " [" << i << "] " << "Kilépés" << endl;


    cout << "\n  >> ";
    cin >> answer;


    if(array[answer] == "Kilépés"){
        return -2;
    }
    else if(answer >= 0 && answer < size){
        return answer;
    }
    else{
        return -1;
    }
}


// Menüpontok
void first(Goods array[], int index, int maxSize){

    if(index < maxSize){
        array[index] = array[index].generate();
    }else{
        cout << "  >> Elérte a maximálisan tárolható járművek számát, ebben a kategóriában! <<" << endl;
        cout << "  >> Kérem szerkessze a beállítások file tartalmát, a maximális méret növeléséért. <<" << endl;
    }

    //cout << index;
}


void second(Goods array[], int index){
    for(int i = 0; i < index; i++){
        array[i].printInformation();
    }
}

void third(Goods array[], int index){
    cout << " Adja meg a keresendő rendszámot: ";
    string name;
    cin >> name;

    bool found = false;

    for(int i = 0; i < index; i++){
        if(array[i].getname() == name){
            cout << "  Megtalált jármű:" << endl;
            array[i].printInformation();
            found = true;
        }
    }

    if(found == false){
        cout << "  >> Nincs ilyen rendszámmal jármű az adatbázisban! <<";
    }
}

void fourth(Goods array[], int index){
    int sum = 0;
    string madafak = array[0].getTypeOfPrice();
    for(int i = 0; i < index; i++){
        sum += array[i].getPrice();
    }

    cout << "  Az összesített Igénybevétel ebben a kategóriában: " << sum << " " << madafak  << endl;
}

int fifth(Goods array[], int index){
    cout << "  Kérem adja meg az új szervízhatár értékét (" << array[0].getTypeOfPrice() << "): ";


    int serviceBoundry;

    cin >> serviceBoundry;

    cout << "  >> Az új szervízhatár értéke felfrissítve! <<" << endl;
    return serviceBoundry;
}

void sixth(Goods array[], int index, int serviceBoundry){
    for(int i = 0; i < index; i++){
        if(array[i].getPrice() >= serviceBoundry){
            array[i].printInformation();
        }
    }
}

// Főprogram
int main()
{
    char quit = 'n'; // 'y' || 'n'

    //Maximum jármű darabszám betöltése a settings fájlból
    ifstream readFile("settings");
    string data;
    int number = 0;
    while(getline(readFile, data)){
        number = stoi(data);
    }
    readFile.close();


    // Gondoskodni kéne arról, hogy ne lehessenek ugyan olyan rendszámok
    WorkMachine wmList[number];
    int wmIndex = 0;
    Truck truckList[number];
    int truckIndex = 0;
    Bus busList[number];
    int busIndex = 0;

    int serviceBoundary[3] = {999,999,999};

    string Goodsmanufacturers[] = {"Munkagép", "Teherautó", "Autóbusz"};


    // Menu ciklusa
    while(quit != 'y' && quit != 'Y'){
        clear();
        cout << "Gépnyilvántartó program\n" << endl;

        string mainMenu[7] = {"Jármű hozzáadása", "Járművek adatainak megtekintése", "Rendszám alapján azonosítás", "Igénybevétel összesítése", "Szervízhatár beállítása" , "Szervíz köteles járművek","Kilépés"};
        int answer = drawMenu(mainMenu, 7);

        if(answer == 0){
            cout << "  >> " << mainMenu[answer] << " <<\n" << endl;
            cout << "  Melyik járműtípushoz akarsz hozzáadni?\n\n";
            int result = drawMenu(Goodsmanufacturers,3);
            if(result == 0){
                first(wmList, wmIndex, number);
                if(wmIndex < number){
                    wmIndex += 1;
                }

            }
            else if(result == 1){
                first(truckList, truckIndex, number);
                if(truckIndex < number){
                    truckIndex += 1;
                }

            }
            else if(result == 2){
                first(busList, busIndex, number);
                if(busIndex < number){
                    busIndex += 1;
                }

            }
        }
        else if(answer == 1){
            cout << "  >> " << mainMenu[answer] << " <<\n" << endl;

            cout << "  Melyik járműtípus csoportosítását kívánja megtekinteni?\n\n";
            int result = drawMenu(Goodsmanufacturers,3);

            if(result == 0){
                second(wmList, wmIndex);
            }
            else if(result == 1){
                second(truckList, truckIndex);
            }
            else if(result == 2){
                second(busList, busIndex);
            }

        }
        else if(answer == 2){
            cout << "  >> " << mainMenu[answer] << " <<\n" << endl;

            cout << "  Melyik járműtípusban kíván keresni rendszám alapján?\n\n";
            int result = drawMenu(Goodsmanufacturers,3);
            if(result == 0){
                third(wmList, wmIndex);
            }
            else if(result == 1){
                third(truckList, truckIndex);
            }
            else if(result == 2){
                third(busList, busIndex);
            }
        }
        else if(answer == 3){
            cout << "  >> " << mainMenu[answer] << " <<\n" << endl;
            cout << "  Melyik kategóriában kívánja összesíteni az adatokat?\n\n";
            int result = drawMenu(Goodsmanufacturers,3);
            if(result == 0){
                fourth(wmList, wmIndex);
            }
            else if(result == 1){
                fourth(truckList, truckIndex);
            }
            else if(result == 2){
                fourth(busList, busIndex);
            }


        }
        else if(answer == 4){
            cout << "  >> " << mainMenu[answer] << " <<\n" << endl;
            cout << "  Melyik kategóriában kívánja beállítani a szervízhatárt?\n\n";
            int result = drawMenu(Goodsmanufacturers,3);
            if(result == 0){
                serviceBoundary[result] = fifth(wmList, wmIndex);
            }
            else if(result == 1){
                serviceBoundary[result] = fifth(truckList, truckIndex);
            }
            else if(result == 2){
                serviceBoundary[result] = fifth(busList, busIndex);
            }

        }
        else if(answer == 5){
            cout << "  >> " << mainMenu[answer] << " <<\n" << endl;
            cout << "  Melyik kategóriában kívánja megtekinteni a szervízköteles járműveket?\n\n";
            int result = drawMenu(Goodsmanufacturers,3);
            if(result == 0){
                sixth(wmList, wmIndex, serviceBoundary[result]);
            }
            else if(result == 1){
                sixth(truckList, truckIndex, serviceBoundary[result]);
            }
            else if(result == 2){
                sixth(busList, busIndex, serviceBoundary[result]);
            }


        }

        else if(answer == -2){
            cout << "  >> Biztos benne hogy ki akar lépni? [y/n]: ";
            cin >> quit;
            if(quit == 'y' || quit == 'Y'){
                cout << "  >> Kilépés megerősítve! <<" << endl;
            }
            else{
                cout << "  >> Kilépés megszakítva! <<" << endl;
            }
        }
        else{
            cout << "  >> Sajnos nincs ilyen menüpont! <<";
        }

        cout << "\n  >> Kész! << ";

        cin.get();
        getchar();
    }
    return 0;
}
