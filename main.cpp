#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <time.h>

#include "fight_functions.h"

using namespace std;

int sekret = 0;
int maks1=0;
int maks2=0;
long long lvl = 1;
long long gold = 0;
long long hp;
long long monster_lvl;
long long monster_hp;
long long monster_actual_hp;
long long actual_hp;
long long dmg = 100;
long long monster_dmg;
string Monster[10] = {"Ork", "Troll", "Pudzianowski", "Pirat", "Dres", "Brajanek", "Karen", "Dudy Rick", "Kanye East", "Informatyk"};

void loading()
{
    system("cls");
    cout << "Witaj Gladiatorze!\n"
         << endl;
    Sleep(2000);
    cout << "Rada:\n";
    cout << "Atak znajduje sie pod przyciskiem A!\n";
    cout << "Obrona znajduje sie pod przyciskiem D!\n";
    cout << endl;
    cout << "Ladowanie gry";
    for (int i = 0; i < 4; i++)
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
    myfile.close();

    return 0;
}
int load_save()
{
    string linia;
    int nr_linii = 1;

    fstream plik;
    plik.open("save.txt", ios::in);

    if (plik.good() == false)
        cout << "nie mozna otworzyc pliku!";
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
        }

        nr_linii++;
    }

    plik.close();
    return 0;
}
int alchemic_shop() // do zrobienia
{
    return 0;
}
int cult() // do zrobienia, ten kult to jaki� black market rozumiem
{
    char numerek2;
    while(numerek2!=3){
        system("cls");
        if (sekret != 1)
        {
            cout << "Menel: Kim ty jestes?" << endl;
            cout << "Menel: Zimno nam, nie potrzebujemy cie w naszym skladzie" << endl;
            Sleep(2000);
            return 0;
        }
        else
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
                    if(maks1!=1)
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
                    else{
                        cout<<"HOG RIDER MA TYLKO JEDEN MLOT!!!";
                        Sleep(1500);
                        break;
                    }
                }
                case '2':
                {
                    if(maks2!=1)
                    {
                        if (gold <= 200)
                        {
                            cout << "Ale ze ty chcesz zebrac od zebraka?!?!" << endl;
                            Sleep(2000);
                            break;
                        }
                        else if (gold >= 200)
                        {
                            cout << "kupiles Magiczny Poison Mirka, wykonany jest po harnasu, kosztowalo cie to 200 golda" << endl;
                            gold = gold - 200;
                            dmg = dmg * 2;
                            maks2=1;
                            Sleep(2000);
                            break;
                        }
                        else{
                            cout<<"Nasz mirek juz nie produkuje takich ustrojstw! ";
                            Sleep(1500);
                            break;
                        }
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
                    cult();
                }
            }
        }
    }
}
void hp_bar(int monster_hp, int act_hp, int b)
{
    system("cls");
    cout << "HP: [";
    for (int i = 0; i < act_hp / 10; i++)
    {
        cout << "|";
    }
    cout << "]" << act_hp << endl;
    cout << Monster[b] << " HP: [";
    for (int i = 0; i < monster_hp / 10; i++)
    {
        cout << "|";
    }
    cout << "]" << monster_hp << endl
         << endl;
}
void atak_potwora(int mdmg, char ruch, int a)
{
    cout << ruch;
    if (ruch == 'd' || ruch == 'D')
    {
        actual_hp = actual_hp - mdmg * 0.6;
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
void fight(int c)
{
    hp_bar(monster_actual_hp, actual_hp, c);
    do
    {
        cout << "Twoj ruch: ";
        char ruch = getch();

        if (ruch == 'a' || ruch == 'A')
        {
            monster_actual_hp = monster_actual_hp - dmg;
            hp_bar(monster_actual_hp, actual_hp, c);
            Sleep(2000);
        }
        if (monster_actual_hp > 0)
        {
            atak_potwora(monster_dmg, ruch, c);
        }
    } while (monster_actual_hp >= 0 && actual_hp >= 0);

    if (monster_actual_hp <= 0)
    {
        system("cls");
        cout << "Gratulacje!" << endl
             << "Wygrales z " << Monster[c] << endl;
        cout << "Twoja nagroda to 1 lvl i 10 golda!\n";
        Sleep(3500);
        lvl++;
        gold = gold + 10;
    }
    else if (hp <= 0)
    {
        system("cls");
        cout << "YOU DIED\n";
        cout << endl
             << "Straciles caly swoj majatek!\n";
        Sleep(3500);
        gold = 0;
    }
    save();
}
int sword_shop()
{
    char numerek;
    while (numerek != '6')
    {
        system("cls");
        welcome_menu();
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
                sword_shop();
            }
        }
    }
}
int gra()
{
    char wybor;
    while (wybor != 5)
    {
        system("cls");
        cout << "lvl: " << lvl << "\t gold: " << gold << "\t"
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
                monster_lvl = lvl * 1.4;
                cout << "Walczysz z " << Monster[n] << " majacy lvl: " << monster_lvl << endl;
                Sleep(2000);
                // deklaracja stat niezdefiniowanych przedtem
                hp = lvl * 100;
                actual_hp = hp;
                monster_hp = hp * 1.2;
                monster_actual_hp = monster_hp;
                monster_dmg = hp * 0.17;
                system("color fc");
                fight(n);
                system("color 70");
                break;
            }
            case '2':
            {
                system("color 8e");
                sword_shop();
                save();
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
                gra();
            }
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
                loading();
                gra();
                return 0;
            case '2':
            {
                load_save();
                gra();
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
                menu();
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
