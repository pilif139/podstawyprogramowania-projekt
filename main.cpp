#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <time.h>

using namespace std;

string nickname;
int sekret = 0;
int maks1=0;
int maks2=0;
int HavelArmorOnOrNot=0;
long long lvl = 1;
long long gold = 0;
long long actual_hp;
int dmg = 100;
long long hp;
int blokDmg;
int isFirstTimePlaying=0;
string consumableItems[]={"Hp Potion","Throwing Dagger","Poison Bomb","Fire Bomb","Lighting powder"};
const int consumableItemsSize= sizeof(consumableItems) / sizeof(consumableItems[0]);
int consumableItemsAmount[consumableItemsSize]={1,1,1,1,1}; //ilosc itemow mozliwych do posiadania i uzycia
string Monster[10] = {"Ork", "Troll", "Pudzianowski", "Pirat", "Dres", "Brajanek", "Karen", "Dudy Rick", "Kanye East", "Informatyk"};

void loading()
{
    system("cls");
    cout << "Witaj Gladiatorze "<<nickname<<"!\n"
         << endl;
    Sleep(2000);
    cout << "Rada:\n";
    cout << "Atak znajduje sie pod przyciskiem A!\n";
    cout << "Obrona znajduje sie pod przyciskiem D!\n";
    cout << endl;
    cout << "Ladowanie gry";
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        Sleep(1000);
    }
}
int save()
{
    ofstream myfile;
    myfile.open("save.txt");
    myfile << lvl << endl;
    myfile << gold << endl;
    myfile << dmg << endl;
    myfile << sekret << endl;
    myfile << maks1 <<endl;
    myfile << maks2 <<endl;
    myfile << nickname <<endl;
    myfile <<HavelArmorOnOrNot <<endl;
    myfile <<isFirstTimePlaying<<endl;
    myfile << consumableItemsAmount[0]<<endl;
    myfile << consumableItemsAmount[1]<<endl;
    myfile << consumableItemsAmount[2]<<endl;
    myfile << consumableItemsAmount[3]<<endl;
    myfile << consumableItemsAmount[4]<<endl;
    myfile.close();

    return 0;
}
int load_save()
{
    string linia;
    int nr_linii = 1;

    fstream plik;
    plik.open("save.txt", ios::in);

    if (!plik.good())
        cout << "Brak save'u!";
    while (getline(plik, linia))
    {
        switch (nr_linii)
        {
            case 1:
                lvl = atoi(linia.c_str());
                break;
            case 2:
                gold = atoi(linia.c_str());
                break;
            case 3:
                dmg = atoi(linia.c_str());
                break;
            case 4:
                sekret = atoi(linia.c_str());
                break;
            case 5:
                maks1=atoi(linia.c_str());
                break;
            case 6:
                maks2=atoi(linia.c_str());
                break;
            case 7:
                nickname = linia;
                break;
            case 8:
                HavelArmorOnOrNot=atoi(linia.c_str());
                break;
            case 9:
                isFirstTimePlaying=atoi(linia.c_str());
                break;
            case 10:
                consumableItemsAmount[0]=atoi(linia.c_str());
                break;
            case 11:
                consumableItemsAmount[1]=atoi(linia.c_str());
                break;
            case 12:
                consumableItemsAmount[2]=atoi(linia.c_str());
                break;
            case 13:
                consumableItemsAmount[3]=atoi(linia.c_str());
                break;
            case 14:
                consumableItemsAmount[4]=atoi(linia.c_str());
                break;
        }

        nr_linii++;
    }

    plik.close();
    return 0;
}
int alchemic_shop()
{
    int consumableItemsPrice[consumableItemsSize]={25,11,37,52,78};
    int Choice=0;
    while(Choice!=6)
    {
        system("cls");
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "	Witaj w Sklepie Alchemicznym" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout <<"Ilosc golda: "<<gold<<endl;
        cout << "Nazwa:\t\t\t Cena:" << endl;
        cout << "1.Health Potion \t 25 golda" << endl;
        cout << "2.Throwing Dagger \t 11 golda" << endl;
        cout << "3.Poison Bomb \t\t 37 golda" << endl;
        cout << "4.Fire Bomb \t\t 52 golda" << endl;
        cout << "5.Lighting Powder \t 78 golda\n"<<endl;
        cout << "6.Wyjdz ze sklepu";
        cout<<endl<<"Twoj wybor: ";
        cin>>Choice;
        system("cls");
        if(Choice==1||Choice==2||Choice==3||Choice==4||Choice==5)
        {
            if(gold>=consumableItemsPrice[Choice-1])
            {
                consumableItemsAmount[Choice-1]+=1;
                gold-=consumableItemsPrice[Choice-1];
                cout<<"Zakupiles "<<consumableItems[Choice-1];
                Sleep(1500);
            }
            else {
                cout << "Nie stac cie na to!";
                Sleep(1500);
            }
        }
        else if(Choice==6) {
            cout<<"Wychodzisz ze Sklepu Alchemicznego!";
            Sleep(1000);
            return 0;
        }
        else
        {
            cout<<"Wynocha z naszego sklepu!"; //nie bedzie bezkarnego bugowania gierki
            Sleep(1500);
            return 0;
        }
        system("cls");
    }

    return 0;
} //zbalansowac ceny do dmg'u
int cult()
{
    char numerek2;
    while(numerek2!=3){
        system("cls");
        if (sekret == 0)
        {
            cout << "Menel: Kim ty jestes?" << endl;
            cout << "Menel: Zimno nam, nie potrzebujemy cie w naszym skladzie" << endl;
            Sleep(2000);
            return 0;
        }
        else if(sekret==1)
        {
            system("cls");
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "    	   Masz Klapki, Ufamy Tobie" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Nazwa:\t\t\t\t\t Cena:" << endl;
            cout << "1.Mlot Legendarnego Hog Ridera(1,5x dmg) \t 150 golda" << endl;
            cout << "2.Magiczny Poison Mirka(2x dmg) \t\t 200 golda\n"
                 << endl;
            cout << "3.Wyjdz ze sklepu" << endl;
            cout << "" << endl;
            cout << "Co chcesz kupic?" << endl;
            numerek2 = getch();
            system("cls");

            switch (numerek2)
            {
                case '1':
                {
                    if(maks1==0)
                    {
                        if(gold <= 150)
                        {
                            cout << "Ale ze ty chcesz zebrac od zebraka?!?!" << endl;
                            Sleep(2000);
                            break;
                        }
                        else if(gold >= 150)
                        {
                            cout << "kupiles Mlot Legendarnego Hog Ridera, masz potrzebe by krzyczec, kosztowalo cie to 150 golda" << endl;
                            gold = gold - 150;
                            dmg = dmg * 1.5;
                            maks1=1;
                            Sleep(2000);
                            break;
                        }
                    }
                    else if(maks1==1){
                        cout<<"HOG RIDER MA TYLKO JEDEN MLOT!!!";
                        Sleep(1500);
                        break;
                    }
                }
                case '2':
                {
                    if(maks2==0)
                    {
                        if (gold <= 200) {
                            cout << "Ale ze ty chcesz zebrac od zebraka?!?!" << endl;
                            Sleep(2000);
                            break;
                        } else if (gold >= 200) {
                            cout
                                    << "kupiles Magiczny Poison Mirka, wykonany jest po harnasu, kosztowalo cie to 200 golda"
                                    << endl;
                            gold = gold - 200;
                            dmg = dmg * 2;
                            maks2 = 1;
                            Sleep(2000);
                            break;
                        }
                    }
                    else if(maks2==1){
                            cout<<"Nasz mirek juz nie produkuje takich ustrojstw! ";
                            Sleep(1500);
                            break;
                        }
                    }
                case '3':
                {
                    cout << "Wychodzisz z kultu!";
                    Sleep(1000);
                    return 0;
                }
                default:
                {
                    cout << "Jeremiaszu, to nie u nas";
                    Sleep(2000);
                    break;
                }
            }
        }
    }
}

void hp_bar(int monster_hp, int act_hp, int b)
{
    system("cls");
    cout <<nickname<<" HP: [";
    for (int i = 0; i < act_hp / 10; i++)
    {
        cout << "|";
    }
    cout << "]" << act_hp <<"/"<<hp<< endl;
    cout << Monster[b] << " HP: [";
    for (int i = 0; i < monster_hp / 10; i++)
    {
        cout << "|";
    }
    cout << "]" << monster_hp<<"/"<< hp*1.2 << endl
         << endl;
}
void monsterAttack(int mdmg, char ruch, int a,int monster_actual_hp)
{
    cout << ruch;
    if (ruch == 'd' || ruch == 'D')
    {
        if(HavelArmorOnOrNot==0)
        {
            blokDmg=mdmg*0.6;
            actual_hp = actual_hp - blokDmg;
        }
        else if(HavelArmorOnOrNot==1)
        {
            blokDmg=mdmg*0.1;
            actual_hp = actual_hp - blokDmg;
        }
        hp_bar(monster_actual_hp, actual_hp, a);
        cout << "BLOK!";
        Sleep(2000);
        system("cls");
        hp_bar(monster_actual_hp, actual_hp, a);
    }
    else
    {
        actual_hp = actual_hp - mdmg;
        hp_bar(monster_actual_hp, actual_hp, a);
        system("color CF");
        cout << Monster[a] << " cie atakuje!";
        Sleep(1000);
        system("color fc");

        system("cls");
        hp_bar(monster_actual_hp, actual_hp, a);
    }
}
void fight(int c,int monster_actual_hp,int monster_lvl)
{
    srand(time(NULL));
    int monster_dmg;
    hp_bar(monster_actual_hp, actual_hp, c);
    do
    {
        monster_dmg=rand()%dmg+dmg/4;
        cout<<endl<<"---POLE SZYBKIEGO RUCHU---\n \n";
        for(int i=0;i<consumableItemsSize;i++)
        {
            cout<<i+1<<". "<<consumableItems[i]<<" - "<<consumableItemsAmount[i]<<endl;
        }
        cout <<endl<< "Twoj ruch: ";

        char ruch = getch();
        switch(tolower(ruch))
        {
            case 'a':
            {
                monster_actual_hp = monster_actual_hp - dmg;
                hp_bar(monster_actual_hp, actual_hp, c);
                cout<<"Zaatakowano przeciwnika za "<<dmg<<" hp!";
                Sleep(1500);
                break;
            }
            case '1':
            {
                if(consumableItemsAmount[0]>0) {
                    actual_hp += rand() % monster_dmg + monster_dmg / 2;
                    if (actual_hp > hp) {
                        actual_hp = hp;
                    }
                    consumableItemsAmount[0]-=1;
                    hp_bar(monster_actual_hp, actual_hp, c);
                    cout<<"Wyleczono HP!";
                    Sleep(1500);
                    break;
                }
                else {
                    cout << "Nie masz zadnych Health Potionow!";
                    Sleep(1500);
                    break;
                }
            }
            case '2':
            {
                if(consumableItemsAmount[1]>0)
                {
                    monster_actual_hp-=dmg*1.25;
                    consumableItemsAmount[1]-=1;
                    hp_bar(monster_actual_hp, actual_hp, c);
                    cout<<"Rzuciles daggerem w przeciwnika i zadales "<<dmg*1.25<<" hp!";
                    Sleep(1800);
                    break;
                }
                else {
                    cout << "Nie masz zadnych Throwing Daggerow";
                    Sleep(1800);
                    break;
                }
            }
            case '3':
            {
                if(consumableItemsAmount[2]>0) {
                    monster_actual_hp -= dmg * 1.5;
                    consumableItemsAmount[2]-=1;
                    hp_bar(monster_actual_hp, actual_hp, c);
                    cout<<"Rzuciles Poison Bombom w przeciwnika i zadales "<< dmg*1.5<<" hp!";
                    Sleep(1800);
                    break;
                }
                else {
                    cout << "Nie masz zadnych Poison Bomb!";
                    Sleep(1800);
                    break;
                }
            }
            case '4':
            {
                if(consumableItemsAmount[3]>0) {
                    monster_actual_hp -= dmg * 1.75;
                    consumableItemsAmount[3]-=1;
                    hp_bar(monster_actual_hp, actual_hp, c);
                    cout<<"Rzuciles Fire Bombom w przeciwnika i zadales "<< dmg*1.75<<" hp!";
                    Sleep(1800);
                    break;
                }
                else {
                    cout << "Nie masz zadnych Fire Bomb!";
                    Sleep(1800);
                    break;
                }
            }
            case '5':
            {
                if(consumableItemsAmount[4]>0) {
                    monster_actual_hp -= dmg * 2.5;
                    consumableItemsAmount[4]-=1;
                    hp_bar(monster_actual_hp, actual_hp, c);
                    cout<<"Twoj miecz jest naelektryzowany piorunami i zadaje "<< dmg*2.5<<" hp przeciwnikowi!";
                    Sleep(1800);
                    break;
                }
                else {
                    cout << "Nie masz zadnego Lightning Powdera!";
                    Sleep(1800);
                    break;
                }
            }
        }
        if (monster_actual_hp > 0)
        {
            monsterAttack(monster_dmg, ruch, c,monster_actual_hp);
        }
    } while (monster_actual_hp > 0 && actual_hp > 0);

    //zakonczenie pojedynku
    if (monster_actual_hp <= 0)
    {
        system("cls");
        cout << "Gratulacje!" << endl
             << "Wygrales z " << Monster[c] << endl;
        cout << "Twoja nagroda to 1 lvl i "<<monster_lvl*10<< "golda!\n";
        Sleep(2500);
        lvl++;
        gold = gold + monster_lvl*10;
    }
    else if (actual_hp <= 0)
    {
        system("cls");
        cout << "YOU DIED\n";
        cout << endl
             << "Straciles caly swoj majatek!\n";
        Sleep(2500);
        gold = 0;
    }
    save();
}
int sword_shop()
{
    int numerek;
    while (numerek != 6)
    {
        system("cls");
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "	Witaj w Sklepie" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Nazwa:\t\t\t Cena:" << endl;
        cout << "1.Klapek(+12 dmg) \t 15 golda" << endl;
        cout << "2.Dlugopis(+18 dmg) \t 25 golda" << endl;
        cout << "3.Kabelek(+24 dmg) \t 40 golda" << endl;
        cout << "4.Rekawiczki(+35 dmg) \t 69 golda" << endl;
        cout << "5.Pasek(+100 dmg) \t 90 golda\n"
             << endl;
        cout << "6.Wyjdz ze sklepu" << endl;
        cout << "" << endl;
        cout << "Co chcesz kupic?" << endl;
        numerek = getch();
        system("cls");

        switch (numerek)
        {
            case '1':
            {
                if (gold < 15)
                {
                    cout << "za biedny jestes" << endl;
                    Sleep(2000);
                    break;
                }
                else if (gold > 15)
                {
                    cout << "kupiles klapek, czujesz sie duzo silniejszy, kosztowalo cie to 15 golda" << endl;
                    sekret = 1;
                    gold = gold - 15;
                    dmg = dmg + 12;
                    Sleep(2000);
                    break;
                }
            }
            case '2':
            {
                if (gold < 25)
                {
                    cout << "za biedny jestes" << endl;
                    Sleep(2000);
                    break;
                }
                else if (gold > 24)
                {
                    cout << "kupiles dlugopis, bedziesz uzywac go jako sztylet, kosztowalo cie to 25 golda" << endl;
                    gold = gold - 25;
                    dmg = dmg + 18;
                    Sleep(2000);
                    break;
                }
            }
            case '3':
            {
                if (gold < 40)
                {
                    cout << "za biedny jestes" << endl;
                    Sleep(2000);
                    break;
                }
                else if (gold > 39)
                {
                    cout << "kupiles klapek, masz swiadomosc ze kable>przewody, kosztowalo cie to 40 golda" << endl;
                    gold = gold - 40;
                    dmg = dmg + 24;
                    Sleep(2000);
                    break;
                }
            }
            case '4':
            {
                if (gold < 69)
                {
                    cout << "za biedny jestes" << endl;
                    Sleep(2000);
                    break;
                }
                else if (gold > 69)
                {
                    cout << "kupiles rekawiczki, nagle czujesz sie cieplo, kosztowalo cie to 69 golda" << endl;
                    gold = gold - 69;
                    dmg = dmg + 35;
                    Sleep(2000);
                    break;
                }
            }
            case '5':
            {
                if (gold < 90)
                {
                    cout << "za biedny jestes" << endl;
                    Sleep(2000);
                    break;
                }
                else if (gold > 89)
                {
                    cout << "kupiles pasek, wypelnia cie determinacja, kosztowalo cie to 90 golda" << endl;
                    gold = gold - 90;
                    dmg = dmg + 100;
                    Sleep(2000);
                    break;
                }
            }
            case '6':
            {
                cout << "Wychodzisz ze sklepu!";
                Sleep(1000);
                return 0;
            }
            default:
            {
                cout << "Nie ma takiej opji w naszym sklepie!";
                Sleep(2000);
                break;
            }
        }
    }
}
int gra()
{
    char wybor;
    while (wybor != 5)
    {
        save();
        system("cls");
        cout <<"Gladiator: "<<nickname<< " \t lvl: " << lvl << "\t gold: " << gold << "\t"
             << "dmg: " << dmg << endl;
        cout << "Znajdujesz sie przed brama miasta! Gdzie chcesz sie udac?\n";
        cout << "1.KOLOSEUM\n";
        cout << "2.SKLEP Z BRONIA BIALA\n";
        cout << "3.SKLEP Z ALCHEMIA\n";
        cout << "4.MIEJSCE KULTU MENELI\n";
        cout << "5.UCIEKNIJ (wyjscie z gry)\n";
        cout << "Twoj wybor: ";
        wybor = getch();
        switch (wybor)
        {
            case '1':
            {
                cout << "Wchodzisz na arene";
                for (int j = 0; j < 3; j++)
                {
                    cout << ".";
                    Sleep(1000);
                }
                system("cls");
                srand(time(NULL));
                int n = rand() % 10; // Zalezy od ilosci przeciwnikow w liscie
                int monster_lvl = rand()%lvl+1+lvl/4;
                cout << "Walczysz z " << Monster[n] << " majacy lvl: " << monster_lvl << endl;
                Sleep(2000);
                // deklaracja stat niezdefiniowanych przedtem
                hp = lvl * 100;
                system("color fc");
                actual_hp=hp;
                fight(n,hp*1.2,monster_lvl);
                system("color 70");
                break;
            }
            case '2':
            {
                system("color 8e");
                sword_shop();
                system("color 70");
                break;
            }
            case '3':
            {
                alchemic_shop();
                break;
            }
            case '4':
            {
                system("color 08");
                cult();
                system("color 70");
                break;
            }
            case '5':
            {
                return 0;
            }

            default:
            {
                break;
            }
        }
    }
}
void CharacterCreate()
{
    system("cls");
    cout<<endl<<"Jakie chcesz otrzymac atrybuty poczatkowe?\n";
    cout<<"\t 1. 150 golda\n";
    cout<<"\t 2. Topor Miasta Poczatkow \n";
    cout<<"\t 3. Mityczny Denaturat Mirka Pierwszego \n";
    cout<<"\t 4. Legendarna Zbroja Havela \n";
    char wybor;
    wybor=getch();
    system("cls");
    switch(wybor)
    {
        case '1':
        {
            cout<<"Jestes dzieckiem bogatych rodzicow tzw. bananem!";
            gold=gold+150;
            Sleep(1800);
            break;
        }
        case '2':
        {
            cout<<"Otrzymujesz Topor Miasta Poczatkow";
            dmg=dmg+20;
            Sleep(1800);
            break;
        }
        case '3':
        {
            cout<<"Otrzymujesz szacunek ludzi ulicy!";
            sekret=1; //moze dodatkowy item w kulcie
            Sleep(1800);
            break;
        }
        case '4':
        {
            cout<<"Mityczna Zbroja Havla Przyodziewa twoje cialo!";
            HavelArmorOnOrNot=1;
            Sleep(1800);
            break;
        }
        default:{
            cout<<"Nie ma takiego atrybutu pocztkowego!";
            Sleep(1800);
            break;
        }
    }
}
int menu()
{
    char wybor;
    while (wybor != 4)
    {
        system("cls");
        system("color 70");
        cout << "----------------------------" << endl;
        cout << "------------MENU------------" << endl;
        cout << "----------------------------" << endl;
        cout << "---------1.NOWA GRA---------" << endl;
        cout << "--------2.WCZYTAJ GRE-------" << endl;
        cout << "-----------3.OPCJE----------" << endl;
        cout << "-----------4.WYJDZ----------" << endl;
        cout << "----------------------------" << endl;
        cout << "Twoj wybor: ";
        wybor = getch();
        switch (wybor)
        {
            case '1':
                system("cls");
                isFirstTimePlaying=1;
                cout<<"---MENU TWORZENIA POSTACI---\n";
                cout<<"Nazwij swoja postac: ";
                cin>>nickname;
                CharacterCreate();
                save();
                loading();
                gra();
                return 0;
            case '2':
            {
                load_save();
                if(isFirstTimePlaying==1)
                {
                    load_save();
                    gra();
                }
                else if(isFirstTimePlaying==0) {
                    cout << "Nie masz jeszcze zadnego save'u!";
                    Sleep(1500);
                }
                return 0;
            }
            case '3':
            {
                system("cls");
                cout << "Atak znajduje sie pod przyciskiem A!\n";
                cout << "Obrona znajduje sie pod przyciskiem D!\n";
                cout << "-------------------------------------------";
                cout << "\n ----------USTAWIENIA GRAFICZNE----------\n";
                cout << "JAKOSC TEKSTUR: ULTRA MAX\n";
                cout << "MODELOWANIE POSTACI: ULTRA MAX\n";
                cout << "CIENIE: ULTRA MAX\n";
                cout << "SPRAWDZANIE STANU KOMPUTERA: ";
                Sleep(2000);
                system("ipconfig");
                system("dir /s");
                Sleep(3000);
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Nie ma takiej opcji w menu! ";
                Sleep(1800);
                break;
            }
        }
        system("cls");
    }
}
int main()
{
    system("title Wlocznie i Buty");
    cout << "Wlocznie i Buty" << endl; // nazwa gry do wymyslenia
    Sleep(2500);
    system("cls");
    cout << "Autorzy:" << endl;
    cout << "-Filip Kasperski" << endl
         << "-Patryk Przybyl";
    Sleep(2500);
    system("cls");
    menu();

    return 0;
}