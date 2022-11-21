#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <time.h>

using namespace std;

int lvl = 1;
int gold = 0; // staty/ trzeba jeszcze pomyslec o jakims zbalansowaniu
int hp = lvl * 100;
int monster_lvl = lvl * 1.4;
int monster_hp = hp * 1.4;
int monster_actual_hp;
int actual_hp;
int dmg = 10;
int monster_dmg = 8;
string Monster[10] = {"Ork", "Troll", "Pudzianowski", "Pirat", "aaaa", "bbbbbb", "ccccc", "sssssssss", "abcabsjaa", "dsadssss"};

void loading()
{
    system("cls");
    cout << "Witaj Gladiatorze!\n"
         << endl;
    Sleep(2000);
    cout << "Rada:\n";
    cout << "Atak znajduje sie pod przyciskiem A!\n";
    cout << "Obrona znajduje sie pod przyciskiem D!\n";
    cout << "Aby wejsc do menu wcisinij przycisk '~'\n"
         << endl;
    cout << "Ladowanie gry";
    for (int i = 0; i < 4; i++)
    {
        cout << ".";
        Sleep(1000);
    }
}
int sklep1() // do zrobienia
{
    return 0;
}
int sklep2() // do zrobienia
{
    return 0;
}
int kult() // do zrobienia
{
    return 0;
}
void hp_bar(int monster_hp, int act_hp)
{
    system("cls");
    cout << "HP: [";
    for (int i = 0; i < act_hp / 10; i++)
    {
        cout << "|";
    }
    cout << "]" << act_hp << endl;
    cout << "MONSTER HP: [";
    for (int i = 0; i < monster_hp / 10; i++)
    {
        cout << "|";
    }
    cout << "]" << monster_hp << endl
         << endl;
}
void atak_potwora(int dmg, char ruch)
{
    if (ruch = 'd' || ruch == 'D')
    {
        hp_bar(monster_actual_hp, actual_hp);
        cout << "BLOK!";
        Sleep(2000);
        system("cls");
        hp_bar(monster_actual_hp, actual_hp);
    }
    else
    {
        actual_hp = actual_hp - monster_dmg;
        hp_bar(monster_actual_hp, actual_hp);
        cout << "Potwor cie atakuje!";
        Sleep(2000);
        system("cls");
        hp_bar(monster_actual_hp, actual_hp);
    }
}
void fight()
{
    hp_bar(monster_actual_hp, actual_hp);
    do
    {
        cout << "Twoj ruch: ";
        char ruch = getch();

        if (ruch == 'a' || ruch == 'A')
        {
            monster_actual_hp = monster_actual_hp - dmg;
            hp_bar(monster_actual_hp, actual_hp);
            Sleep(2000);
        }
        atak_potwora(monster_dmg, ruch);
    } while (monster_actual_hp >= 0 && actual_hp >= 0);
    if (monster_actual_hp <= 0)
    {
        system("cls");
        cout << "Gratulacje!" << endl
             << "Wygrales z potworem!" << endl;
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
             << "Straciles cały swój majątek!\n";
        Sleep(3500);
        gold = 0;
    }
}
int gra()
{
    system("cls");
    cout << "lvl: " << lvl << "||| gold:" << gold << endl;
    cout << "Znajdujesz sie przed brama miasta! Gdzie chcesz sie udac?\n";
    cout << "1.KOLOSEUM\n";
    cout << "2.SKLEP Z BRONIA BIALA\n";
    cout << "3.SKLEP Z ALCHEMIA\n";
    cout << "4.MIEJSCE KULTU MENELI\n";
    cout << "5.UCIEKNIJ (wyjscie z gry)\n";
    cout << "Twoj wybor: ";
    char wybor = getch();
    switch (wybor)
    {
    case '1':
    {
        cout << "Wchodzisz na arene";
        for (int j = 0; j < 4; j++)
        {
            cout << ".";
            Sleep(1000);
        }
        system("cls");
        srand(time(NULL));
        int n = rand() % 10; // Zalezy od ilosci przeciwnikow w liscie
        cout << "Walczysz z " << Monster[n] << " majacy lvl:" << monster_lvl << endl;
        Sleep(2000);
        actual_hp = hp;
        monster_actual_hp = monster_hp;
        fight();
        gra();
    }
    case '2':
    {
        sklep1();
    }
    case '3':
    {
        sklep2();
    }
    case '4':
    {
        kult();
    }
    case '5':
    {
        exit(0);
    }

    default:
        gra();
    }
    getchar();
    getchar();
}
void menu()
{
    system("cls");
    char wybor;
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
    case '2':
    {
        exit(0);
        // jeszcze do zrobienia, wczytuje z pliku zmienne z statami, itemami, lvlem itp. a pozniej normalnie sie gra wlacza (ja to zrobie )
    }
    case '3':
    {
        system("cls");
        cout << "Atak znajduje sie pod przyciskiem A!\n";
        cout << "Obrona znajduje sie pod przyciskiem D!\n";
        cout << "Aby otworzyc ekwipunek wcisnij przycisk E!\n";
        cout << "Aby zapisac gre wcisnij przycisk P!\n";
        cout << endl
             << "Wcisnij dowolny przycisk, aby wrocic do menu";
        char wejscie_do_menu = getch();
        if (wejscie_do_menu == ' ')
        {
            menu();
        }
    }
    case '4':
    {
        exit(0);
    }
    default:
        cout << "Nie ma takiej opcji w menu! ";
        Sleep(1800);
        menu();
    }
    system("cls");
}
int main()
{
    cout << "Miecze i Sandaly" << endl; // nazwa gry do wymyslenia
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
