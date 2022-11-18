#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <time.h>

using namespace std;

int lvl=1;
int gold=0;
int monster_lvl;
if(lvl=1)
{
    monster_lvl=lvl;
}
else
{
    monster_lvl-lvl*0.9;
}
string Monster[10]={"Ork", "Troll","Pudzianowski","Pirat","aaaa","bbbbbb","ccccc","sssssssss","abcabsjaa","dsadssss"};

void loading()
{
    system("cls");
    cout<<"Witaj Gladiatorze!\n";
    Sleep(2000);
    system("cls");
    Sleep(1500);
    cout<<"Rada:\n";
    cout<<"Atak znajduje sie pod przyciskiem A!\n";
    cout<<"Obrona znajduje sie pod przyciskiem D!\n";
    cout<<"Aby wejsc do menu wcisinij przycisk '~'\n"<<endl;
    cout<<"Ladowanie gry";
    for(int i=0; i<4;i++)
    {
        cout<<".";
        Sleep(1000);
    }
}
void gra()
{
    system("cls");
    cout<<"lvl: "<<lvl<<"||| gold:"<<gold<<endl;
    cout<<"Znajdujesz sie przed brama miasta! Gdzie chcesz sie udac?\n";
    cout<<"1.KOLOSEUM\n";
    cout<<"2.SKLEP Z BRONIA BIALA\n";
    cout<<"3.SKLEP Z ALCHEMIA\n";
    cout<<"4.MIEJSCE KULTU MENELI\n";
    cout<<"Twoj wybor: ";
    char wybor=getch();
    switch(wybor)
    {
        case '1':
        {
            cout<<"Wchodzisz na arene";
            for(int j=0; j<4; j++)
            {
                cout<<".";
                Sleep(1000);
            }
            system("cls");
            srand(time(NULL));
            int n=rand()%10; //Zalezy od ilosci przeciwnikow w liscie
            cout<<"Walczysz z "<<Monster[n]<<" majacy lvl:"<<monster_lvl;
        }

    }
    getchar();getchar();
}
void menu()
{
    system("cls");
    char wybor;
    cout<<"----------------------------"<<endl;
    cout<<"------------MENU------------"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"---------1.NOWA GRA---------"<<endl;
    cout<<"--------2.WCZYTAJ GRE-------"<<endl;
    cout<<"-----------3.OPCJE----------"<<endl;
    cout<<"-----------4.WYJDZ----------"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"Twoj wybor: ";
    wybor=getch();
    switch(wybor)
    {
    case '1':
        loading();
        gra();
    case '2':
        {
            exit(0);
             //jeszcze do zrobienia, wczytuje z pliku zmienne z statami, itemami, lvlem itp. a pozniej normalnie sie gra wlacza (ja to zrobie )
        }
    case '3':
    {
        system("cls");
        cout<<"Atak znajduje sie pod przyciskiem A!\n";
        cout<<"Obrona znajduje sie pod przyciskiem D!\n";
        cout<<"Aby otworzyc ekwipunek wcisnij przycisk E!\n";
        cout<<"Aby zapisac gre wcisnij przycisk P!\n";
        cout<<endl<<"Wcisnij dowolny przycisk, aby wrocic do menu";
        char wejscie_do_menu=getch();
        if(wejscie_do_menu=' ')
        {
            menu();
        }
        getchar();getchar();
    }
    case '4':
    {
        exit(0);
    }
    default: cout<<"Nie ma takiej opcji w menu! "; Sleep(1800); menu();
    }
    getchar();getchar();
    system("cls");

}
int main()
{
    cout<<"Miecze i Sandaly"<<endl; //nazwa gry do wymyslenia
    Sleep(2500);
    system("cls");
    cout<<"Autorzy:"<<endl;
    cout<<"-Filip Kasperski"<<endl<<"-Patryk Przybyl";
    Sleep(2500);
    system("cls");
    menu();

    return 0;
}
