#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <time.h>
#include <cmath>

using namespace std;

string nickname;
int sekret = 0;
int walter_white=0;
int maks1=0;
int maks2=0;
int maks3=0;
int armor=5;
int lvl = 1;
long gold = 0;
long actual_hp;
int dmg = 100;
long long hp;
int hpBarConvert;
int MonsterHpBarConvert;
int monster_lvl;
int monster_hp_value;
string ArenaName[]={"Rzym","Sosnowiec","Radom","ZSK","Sala Nr 62", "Ziemia Niczyja lidl", "Poznan w remoncie","Spot Rybacki o 4 rano"};
string consumableItems[]={"Hp Potion","Throwing Dagger","Poison Bomb","Fire Bomb","Lighting powder"};
const int consumableItemsSize = sizeof(consumableItems) / sizeof(consumableItems[0]);
int consumableItemsAmount[consumableItemsSize]={1,1,0,0,0}; //ilosc itemow mozliwych do posiadania i uzycia
string Monster[] = {"Ork", "Troll", "Pudzianowski", "Pirat", "Dres", "Brajanek", "Karen", "Dudy Rick", "Kanye East", "Informatyk",
                    "Evil Menel", "Kangurek Kao", "Dwayne the Pebble Jonson", "Technik Pszczelarstwa", "Budowlaniec", "Tomasz"};
string swordShopItems[]={"Klapek","Dlugopis","Kabelek","Rekawiczki","Mlot pneumatyczny","Dragon Blade"};
int swordShopItemAmount[]={0,0,0,0,0,0};
int armorShopItemAmount[]={0,0,0,0,0,0};
string armorShopItems[]={"Sandaly","Pancerniki Januszowe","Cevlar z Fortnite","ChugJug","Zbroja Cebuli","Ciezka Zbroja Havela"};
BOOL WINAPI SetConsoleOutputCP(
        UINT wCodePageID
);
BOOL WINAPI SetCurrentConsoleFontEx(
        _In_ HANDLE               hConsoleOutput,
        _In_ BOOL                 bMaximumWindow,
        _In_ PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx
);
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
    myfile <<armor <<endl;
    myfile << consumableItemsAmount[0]<<endl;
    myfile << consumableItemsAmount[1]<<endl;
    myfile << consumableItemsAmount[2]<<endl;
    myfile << consumableItemsAmount[3]<<endl;
    myfile << consumableItemsAmount[4]<<endl;
    myfile << maks3<<endl;
    myfile << swordShopItemAmount[0]<<endl;
    myfile << swordShopItemAmount[1]<<endl;
    myfile << swordShopItemAmount[2]<<endl;
    myfile << swordShopItemAmount[3]<<endl;
    myfile << swordShopItemAmount[4]<<endl;
    myfile << swordShopItemAmount[5]<<endl;
    myfile << armorShopItemAmount[0]<<endl;
    myfile << armorShopItemAmount[1]<<endl;
    myfile << armorShopItemAmount[2]<<endl;
    myfile << armorShopItemAmount[3]<<endl;
    myfile << armorShopItemAmount[4]<<endl;
    myfile << armorShopItemAmount[5]<<endl;
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
    {
        cout << "Brak dostepnego save'u!";
        Sleep(2000);
        return -1;
    }

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
                armor=atoi(linia.c_str());
                break;
            case 9:
                consumableItemsAmount[0]=atoi(linia.c_str());
                break;
            case 10:
                consumableItemsAmount[1]=atoi(linia.c_str());
                break;
            case 11:
                consumableItemsAmount[2]=atoi(linia.c_str());
                break;
            case 12:
                consumableItemsAmount[3]=atoi(linia.c_str());
                break;
            case 13:
                consumableItemsAmount[4]=atoi(linia.c_str());
                break;
            case 14:
                maks3=atoi(linia.c_str());
                break;
            case 15:
                swordShopItemAmount[0]=atoi(linia.c_str());
                break;
            case 16:
                swordShopItemAmount[1]=atoi(linia.c_str());
                break;
            case 17:
                swordShopItemAmount[2]=atoi(linia.c_str());
                break;
            case 18:
                swordShopItemAmount[3]=atoi(linia.c_str());
                break;
            case 19:
                swordShopItemAmount[4]=atoi(linia.c_str());
                break;
            case 20:
                swordShopItemAmount[5]=atoi(linia.c_str());
                break;
            case 21:
                armorShopItemAmount[0]=atoi(linia.c_str());
                break;
            case 22:
                armorShopItemAmount[1]=atoi(linia.c_str());
                break;
            case 23:
                armorShopItemAmount[2]=atoi(linia.c_str());
                break;
            case 24:
                armorShopItemAmount[3]=atoi(linia.c_str());
                break;
            case 25:
                armorShopItemAmount[4]=atoi(linia.c_str());
                break;
            case 26:
                armorShopItemAmount[5]=atoi(linia.c_str());
                break;
        }

        nr_linii++;
    }

    plik.close();
    return 0;
}
void casino()
{

    system("cls");
    char numerek3;
    while (numerek3 != 2) {
        system("cls");
        cout << "Witaj w kasynie, gotowy *zainwestować* swoje pieniądze?" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout <<"Twoje żetony: "<<gold<<endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1.Oczywiście(150 golda)" << endl;
        cout << "2.Wolę wyjść\n" << endl;
        cout << "Co powiesz?: " <<endl;
        numerek3 = getch();
        system("cls");

        srand(time(0));
        switch (numerek3)
        {
            case '1':
            {
                if(gold>=150)
                {
                    gold=gold-150;
                    int r=(rand()%500-200);
                    cout << "Zakręciłeś machiną";
                    for (int j = 0; j < 3; j++)
                    {
                        cout << ".";
                        Sleep(1000);
                    }
                    system("cls");
                    cout << "Wylosowaleś  " << r << " golda!" << endl;
                    gold=gold+r;
                    if(gold<0)
                        gold=0;
                    Sleep(2000);
                    break;
                }
                else
                {
                    cout<<"Maszyna losująca nie przyjmuje takich biedackich monet!";
                    Sleep(1500);
                    break;
                }
            }

            case '2':
            {
                cout << "Wychodzisz z kasyna!" << endl;
                Sleep(400);
                return;
            }
            default:
            {
                cout << "Takich rzeczy w naszym kasynie nie ma";
                Sleep(1100);
                break;
            }
        }
    }
}
void alchemic_shop()
{
    int consumableItemsPrice[consumableItemsSize]={30,50,85,150,200};
    int Choice;
    while(Choice!=6)
    {
        system("cls");
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "  Witaj w Sklepie Alchemicznym" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout <<endl<<"Ilosc golda: "<<gold<<endl<<endl;
        cout << "Nazwa:\t\t\t Cena:" << endl;
        cout << "1.Health Potion \t 30 golda" << endl;
        cout << "2.Throwing Dagger \t 50 golda" << endl;
        cout << "3.Poison Bomb \t\t 85 golda" << endl;
        cout << "4.Fire Bomb \t\t 150 golda" << endl;
        cout << "5.Lighting Powder \t 200 golda\n"<<endl;
        cout << "6.Wyjdz ze sklepu";
        cout<<endl<<"Twoj wybor: ";
        unsigned char x=getch();
        Choice = x - '0';
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
            return;
        }
        else
        {
            cout<<"Nie ma takiego przedmiotu w naszym sklepie!";
            Sleep(1500);
        }
        system("cls");
    }
} //zbalansowac ceny do dmg'u
void cult() {
    system("cls");
    if (swordShopItemAmount[5]<1) {
        cout << "Menel: Kim ty jestes?" << endl;
        cout << "Menel: Zimno nam, nie potrzebujemy cie w naszym skladzie" << endl;
        Sleep(2000);
        return;
    } else if (swordShopItemAmount[5]==1)
    {
        unsigned char numerek2;
        while (numerek2 != 3) {
            system("cls");
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "   Kierowniku! Co możemy dla ciebie zrobić?" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Nazwa:\t\t\t\t\t Cena:" << endl;
            cout << "1.Młot Legendarnego Hog Ridera(1,5x dmg) \t 150 golda" << endl;
            cout << "2.Magiczny Poison Mirka(2x dmg) \t\t 200 golda\n"
                 << endl;
            cout << "3.Wyjdź ze sklepu" << endl<<endl;
            if(sekret==2)
            {
                cout<<"4. Legendarny Trójząb Boga Denaturatosa \t 300 golda\n \n";
            }
            cout << "Co chcesz kupić?" << endl;
            numerek2 = getch();
            system("cls");

            switch (numerek2) {
                case '1': {
                    if (maks1 == 0) {
                        if (gold < 150) {
                            cout << "Ale że ty chcesz żebrać od żebraka?!?!" << endl;
                            Sleep(2000);
                            break;
                        } else if (gold >= 150) {
                            cout
                                    << "kupiłeś Młot Legendarnego Hog Ridera, masz potrzebę by krzyczeć, kosztowalo cię to 150 golda"
                                    << endl;
                            gold = gold - 150;
                            dmg = dmg * 1.5;
                            maks1 = 1;
                            Sleep(2000);
                            break;
                        }
                    } else if (maks1 == 1) {
                        cout << "HOG RIDER MA TYLKO JEDEN MLOT!!!";
                        Sleep(1500);
                        break;
                    }
                }
                case '2': {
                    if (maks2 == 0) {
                        if (gold < 200) {
                            cout << "Ale że ty chcesz żebrać od żebraka?!?!" << endl;
                            Sleep(2000);
                            break;
                        } else if (gold >= 200) {
                            cout
                                    << "kupileś Magiczny Poison Mirka, wykonany jest po harnasiu, kosztowalo cię to 200 golda"
                                    << endl;
                            gold = gold - 200;
                            dmg = dmg * 2;
                            maks2 = 1;
                            Sleep(2000);
                            break;
                        }
                    } else if (maks2 == 1) {
                        cout << "Nasz mirek już nie produkuje takich ustrojstw! ";
                        Sleep(1500);
                        break;
                    }
                }
                case '3': {
                    cout << "Wychodzisz z kultu!";
                    Sleep(1000);
                    return;
                }
                case '4':
                {
                    if(sekret==2)
                    {
                        if(maks3==0)
                        {
                            if(gold < 300)
                            {
                                cout<<"Nie masz tyle kasy, aby kupić broń samego boga!";
                                Sleep(2000);
                                break;
                            }
                            else if(gold>=300)
                            {
                                cout<<"Stales sie Bogiem Denaturatosem!!!\n";
                                cout<<"Twoje ataki są od teraz wspierane przez efekt nietrzeźwości sprawiający, że twój styl walki jest nieprzewidywalny!";
                                gold=gold-300;
                                dmg=dmg*3;
                                maks3=1;
                                Sleep(2000);
                                break;
                            }
                        }
                        else
                        {
                            cout<<"Już jesteś Bogiem Denaturatosem!";
                            Sleep(1500);
                            break;
                        }
                    }
                    else
                        break;
                }
                default: {
                    cout << "Jeremiaszu, to nie u nas";
                    Sleep(2000);
                    break;
                }
            }
        }
    }
}
void pomnik(){

    system("cls");
    cout << "Idąc po drodze, napotkaleś starszego łysego pana w okularach przy wanie\n" << endl;
    cout << "Chcesz podejść do niego?\n" <<endl;
    cout<<"1.Tak"<<endl;
    cout<<"2.Nie"<<endl;
    char wybor;
    wybor = getch();
    system("cls");

    switch(wybor)
    {
        case '1':
            if(walter_white==1){
                cout << "Dostaleś już swoje, odejdź" << endl;
                Sleep(1600);
                return;
            }
            else if(walter_white ==0){
                cout << "Chcesz Kupić ??? za jedyne 5 golda?\n" << endl;
                cout<<"1.Oczywiście"<<endl;
                cout<<"2.Nie Chcę"<<endl;
                char dragi;
                dragi = getch();

                switch(dragi)
                {
                    case '1':
                        system("cls");
                        gold=gold-5;
                        cout<<"Smakowalo jak truskawki, czujesz sie słabszy"<<endl;
                        walter_white=1;
                        dmg=dmg*0.75;
                        Sleep(1000);
                        return;
                    default: cout<<"Jesteś zamyslony i odchodzisz w dal...";Sleep(1000); return;
                }
            }

        case '2':
            system("cls");
            cout<<"     III     "<<endl;
            cout<<"    IIIII    "<<endl;
            cout<<"   IIIIIII   "<<endl;
            cout<<"  IIIIIIIII  "<<endl;
            cout<<" IIIIIIIIIII "<<endl;
            cout<<"IIIIIIIIIIIII\n"<<endl;
            cout<<"Chcesz dać SMS o treści pomoc pod numer 600 100 100?\n"<<endl;
            cout<<"1.Jak najbardziej"<<endl;
            cout<<"2.Nie..."<<endl;
            char sms;
            sms = getch();
            system("cls");

            switch(sms) {
                case '1':
                    cout << "dałeś im 2 golda, a oni cie wygonili od pomnika" << endl;
                    Sleep(1000);
                    gold = gold - 2;
                    return;
                default:
                    cout<<"Jesteś zamyslony i odchodzisz w dal..."; Sleep(1000); return;
                }
                    default: cout<<"Jesteś zamyslony i odchodzisz w dal...";Sleep(1000); return;
    }
}
void sword_shop()
{
    int swordShopItemsPrice[]={20,40,60,100,200,350};
    int swordShopItemVar[]={12,18,24,35,50,100};
    string swordShopItemQuote[]={"Od teraz będziesz używać go jako sztylet","Masz swiadomosc ze kable>przewody?","Nagle poczules sie cieply",
                                 "Twoje cialo wypelnia determinacja","Twoje ortograficzne i geograficzne zdolnosci wzrosly!","Stales sie furasem przebranym za smoka!"};
    //daloby sie tabele z nazwami wypisac w forze zamiast tego ale wtedy ceny golda sa nierowno
    int numerek;
    while (numerek != 7)
    {
        system("cls");
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "  Witaj w Sklepie z bronia biala" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout <<endl<<"Ilosc golda: "<<gold<<endl<<endl;
        cout << "Nazwa:\t\t\t\t Cena:" << endl;
        cout << "1.Klapek (12 dmg) +"<<swordShopItemAmount[0]<<" \t\t 20 golda" << endl;
        cout << "2.Dlugopis (18 dmg) +"<<swordShopItemAmount[1]<<" \t\t 40 golda" << endl;
        cout << "3.Kabelek (24 dmg) +"<<swordShopItemAmount[2]<<" \t\t 60 golda" << endl;
        cout << "4.Rekawiczki (35 dmg) +"<<swordShopItemAmount[3]<<" \t 100 golda" << endl;
        cout << "5.Mlot pneumatyczny (50dmg) +"<<swordShopItemAmount[4]<<" \t 200 golda\n";
        cout << "6.Dragon Blade (100dmg) +"<<swordShopItemAmount[5]<<" \t 350 golda \n";
        cout << endl << "7.Wyjdz ze sklepu" << endl;
        cout << "" << endl;
        cout << "Co chcesz kupic?" << endl;
        unsigned char x=getch();
        numerek = x-'0';
        system("cls");
        if(numerek==1||numerek==2||numerek==3||numerek==4||numerek==5||numerek==6)
        {
            if(swordShopItemAmount[numerek-1]<10)
            {
                if(gold>=swordShopItemsPrice[numerek-1])
                {
                    swordShopItemAmount[numerek-1]+=1;
                    gold-=swordShopItemsPrice[numerek-1];
                    dmg+=swordShopItemVar[numerek-1];
                    cout<<"Kupiles "<<swordShopItems[numerek-1]<<" +"<<swordShopItemAmount[numerek-1]<<", kosztowalo cie to "<<swordShopItemsPrice[numerek-1]<<" golda."<<endl;
                    cout<<swordShopItemQuote[numerek-1];
                    Sleep(1750);
                }
                else {
                    cout << "Nie stac cie na to!";
                    Sleep(1500);
                }
            }
            else{
                cout<<swordShopItems[numerek-1]<<" jest juz maksymalnie ulepszony!";
                Sleep(1500);
            }
        }
        else if(numerek==7) {
            cout<<"Wychodzisz ze Sklepu!";
            Sleep(1000);
            return;
        }
        else
        {
            cout<<"Nie ma takiego przedmiotu w naszym sklepie!";
            Sleep(1500);
        }
    }
}
void armorShop()
{
    int armorShopPrice[]={25,50,100,150,250,350};
    int armorShopVar[]={5,10,25,40,60,80};
    string armorShopQuote[]={"Do tych sandalow brakuje ci jeszcze skarpetek.","Zbroja Janusza dla prawdziwych Januszy biznesu.","To chyba nie te uniwersum.","take me to your xbox to play fortnite today \n you can take me to the moisty mire but not loot lake \n i would really love to, chug jug with you \n we can be pro fortnite gamers ",
                             "Od teraz wygladasz i czujesz sie jak cebula","Ta zbroja jest tak ciezka ze jedyne co mozesz robic to stac i machac mieczem."};
    int numerek;
    while (numerek != 7)
    {
        system("cls");
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "       Witaj w Zbrojowni!" << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout <<endl<<"Ilosc golda: "<<gold<<endl<<endl;
        cout << "Nazwa:\t\t\t\t\t Cena:" << endl;
        cout << "1.Sandaly (+5 armora ) +"<<armorShopItemAmount[0]<<" \t\t 25 golda" << endl;
        cout << "2.Pancerniki Januszowe (+10 armora) +"<<armorShopItemAmount[1]<<" \t 50 golda" << endl;
        cout << "3.Cevlar z Fortnite (+25 armora) +"<<armorShopItemAmount[2]<<" \t 100 golda" << endl;
        cout << "4.ChugJug (+40 armora) +"<<armorShopItemAmount[3]<<" \t\t 150 golda" << endl;
        cout << "5.Zbroja Cebuli (+60 armora) +"<<armorShopItemAmount[4]<<" \t 250 golda\n";
        cout << "6.Ciezka Zbroja Havela(+80 armora) +"<<armorShopItemAmount[5]<<" \t 350 golda \n";
        cout << endl << "7.Wyjdz ze sklepu" << endl;
        cout << "" << endl;
        cout << "Co chcesz kupic?" << endl;
        unsigned char x=getch();
        numerek = x-'0';
        system("cls");
        if(numerek==1||numerek==2||numerek==3||numerek==4||numerek==5||numerek==6)
        {
            if(armorShopItemAmount[numerek-1]<10)
            {
                if(gold>=armorShopPrice[numerek-1])
                {
                    armorShopItemAmount[numerek-1]+=1;
                    gold-=armorShopPrice[numerek-1];
                    armor+=armorShopVar[numerek-1];
                    cout<<"Kupiles "<<armorShopItems[numerek-1]<<" +"<<armorShopItemAmount[numerek-1]<<", kosztowalo cie to "<<armorShopPrice[numerek-1]<<" golda."<<endl;
                    cout<<armorShopQuote[numerek-1];
                    Sleep(1750);
                }
                else {
                    cout << "Nie stac cie na to!";
                    Sleep(1500);
                }
            }
            else
            {
                cout<<armorShopItems[numerek-1]<<" jest juz maksymalnie ulepszony!";
                Sleep(1500);
            }
        }
        else if(numerek==7) {
            cout<<"Wychodzisz ze Sklepu!";
            Sleep(1000);
            return;
        }
        else
        {
            cout<<"Nie ma takiego przedmiotu w naszym sklepie!";
            Sleep(1500);
        }
    }
}
void hp_bar(int monster_hp, int act_hp, int b)
{
    system("cls");
    hpBarConvert=pow(10,(log10(hp))-1);
    cout <<nickname<<" HP: [";
    for (int i = 0; i <= act_hp / hpBarConvert; i++)
    {
        cout << "|";
    }
    cout << "]" << act_hp <<"/"<<hp<< endl;
    cout << Monster[b] << " HP: [";
    for (int i = 0; i <= monster_hp / hpBarConvert; i++)
    {
        cout << "|";
    }
    cout << "]" << monster_hp<<"/"<< monster_hp_value << endl
         << endl;
}
void monsterAttack(int mdmg, int a,int monster_actual_hp)
{
    actual_hp=actual_hp-(mdmg-armor/5);
    hp_bar(monster_actual_hp, actual_hp, a);
    system("color CF");
    cout << Monster[a] << " cie atakuje!";
    Sleep(1000);
    system("color fc");
    system("cls");
    hp_bar(monster_actual_hp, actual_hp, a);
}
void fight(int n,int monster_actual_hp)
{
    srand(time(NULL));
    int monster_dmg;
    hp_bar(monster_actual_hp, actual_hp, n);
    do
    {
        monster_dmg=rand()%dmg+dmg/3;
        cout<<endl<<"---POLE SZYBKIEGO RUCHU---\n \n";
        for(int i=0;i<consumableItemsSize;i++)
        {
            cout<<i+1<<". "<<consumableItems[i]<<" - "<<consumableItemsAmount[i]<<endl;
        }
        cout <<endl<< "Twoj ruch: ";

        unsigned char ruch = getch();
        ruch=tolower(ruch);
        switch(ruch)
        {
            case 'a':
            {
                monster_actual_hp = monster_actual_hp - dmg;
                hp_bar(monster_actual_hp, actual_hp, n);
                cout<<"Zaatakowano przeciwnika za "<<dmg<<" hp!";
                Sleep(1500);
                break;
            }
            case 'd':
                {
                    actual_hp=actual_hp-(monster_dmg-armor*1.2);
                    hp_bar(monster_actual_hp, actual_hp, n);
                    cout << "BLOK!";
                    Sleep(2000);
                    system("cls");
                    hp_bar(monster_actual_hp, actual_hp, n);
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
                    hp_bar(monster_actual_hp, actual_hp, n);
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
                    hp_bar(monster_actual_hp, actual_hp, n);
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
                    hp_bar(monster_actual_hp, actual_hp, n);
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
                    hp_bar(monster_actual_hp, actual_hp, n);
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
                    hp_bar(monster_actual_hp, actual_hp, n);
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
            default: cout<<"Stracono ruch!"; Sleep(1000); monster_dmg=monster_dmg-monster_dmg/3; break;
        }
        if (monster_actual_hp > 0&&ruch!='d')
        {
            monsterAttack(monster_dmg, n,monster_actual_hp);
        }
    } while (monster_actual_hp > 0 && actual_hp > 0);

    //zakonczenie pojedynku
    if (monster_actual_hp <= 0)
    {
        system("cls");
        cout << "Gratulacje!" << endl
             << "Wygrales z " << Monster[n] << endl;
        int droppedGoldFromMonster=rand()%(monster_lvl*10)+10;
        cout << "Twoja nagroda to 1 lvl i "<<droppedGoldFromMonster<< "golda!\n";
        Sleep(2500);
        lvl++;
        gold = gold + droppedGoldFromMonster;
        if(lvl%10==0)
        {
            system("cls");
            system("color e1");
            cout<<"Brawo! Odblokowales nowa arene!\n Od teraz Bedziesz walczyl w "<<ArenaName[lvl/10];
            Sleep(3000);
        }
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
void Inventory()
{
    char wybor;
    while(wybor!=27)
    {
        system("cls");
        cout<<"~~EKWIPUNEK~~"<<endl;
        cout<<" BRON BIALA:"<<endl;
        const int swordShopSize = sizeof(swordShopItems) / sizeof(swordShopItems[0]);
        for(int i=0;i<swordShopSize;i++)
        {
            cout<<"     - "<<swordShopItems[i]<<" +"<<swordShopItemAmount[i]<<endl;
        }
        cout<<" ARMOR:"<<endl;
        const int armorShopSize = sizeof(armorShopItems) / sizeof(armorShopItems[0]);
        for(int i=0;i<armorShopSize;i++)
        {
            cout<<"     - "<<armorShopItems[i]<<" +"<<armorShopItemAmount[i]<<endl;
        }
        cout<<" CONSUMABLE ITEMY:"<<endl;
        for(int i=0;i<consumableItemsSize;i++)
        {
            cout<<"     - "<<consumableItems[i]<<" - "<<consumableItemsAmount[i]<<endl;
        }
        cout<<"Aby wyjsc z ekwipunku wcisnij klawisz ESC";
        wybor=getch();
    }
}
void gra()
{
    char wybor;
    while (wybor != 27)
    {
        save();
        system("color 70");
        system("cls");
        cout <<"Gladiator: "<<nickname<< " \t lvl: " << lvl << " gold: " << gold
             << "  dmg: " << dmg <<"  armor: "<<armor<<"\t KLIKNIJ E, ABY WEJSC DO EKWIPUNKU" << endl<<endl;
        cout << "ARENA "<<ArenaName[lvl/10]<<endl<<endl;
        cout << "1.KOLOSEUM\n";
        cout << "2.SKLEP Z BRONIĄ BIALĄ\n";
        cout << "3.SKLEP Z ALCHEMIĄ\n";
        cout << "4.MIEJSCE KULTU MENELI\n";
        cout << "5.ZBROJOWNIA\n";
        if(lvl>=10)
        {
            cout<<"6.KASYNO LAS VEGAS SPONSORED \n";
            cout<<"7.POMNIK LEGENDARNEGO WOJOWNIKA\n";
        }
        cout << "ESC. UCIEKNIJ (wyjście z gry)\n";
        cout << "Twoj wybor: ";
        wybor = getch();
        switch (tolower(wybor))
        {
            case 'e':
            {
                system("color 3f");
                Inventory();
                break;
            }
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
                const int MonsterListSize = sizeof(Monster) / sizeof(Monster[0]);
                int n = rand() % MonsterListSize;
                monster_lvl = rand()%lvl+lvl/2;
                if(monster_lvl==0)
                    monster_lvl=1;
                cout << "Walczysz z " << Monster[n] << " majacy lvl: " << monster_lvl << endl;
                Sleep(2000);
                // deklaracja stat niezdefiniowanych przedtem
                hp = lvl * 100;
                system("color fc");
                actual_hp=hp;
                monster_hp_value=rand()%(monster_lvl*20)+monster_lvl*90;
                system("color fc");
                fight(n,monster_hp_value);
                break;
            }
            case '2':
            {
                system("color 8e");
                sword_shop();
                break;
            }
            case '3':
            {
                system("color 5f");
                alchemic_shop();
                break;
            }
            case '4':
            {
                system("color 08");
                cult();
                break;
            }
            case '5':
            {
                system("color 4f");
                armorShop();
                break;
            }
            case '6':
            {
                if(lvl>=10)
                {
                    system("color 1f");
                    casino();
                    break;
                }
                else
                    break;
            }
            case '7':
            {
                if(lvl>=10)
                {
                    system("color 05");
                    pomnik();
                    break;}
                else
                    break;
            }
            case 27:
            {
                return;
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
            cout<<"Otrzymujesz szacunek ludzi ulicy";
            sekret=2;
            Sleep(1800);
            break;
        }
        case '4':
        {
            cout<<"Mityczna Zbroja Havla Przyodziewa twoje cialo!";
            armor+=20;
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
void menu()
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
                cout<<"---MENU TWORZENIA POSTACI---\n";
                cout<<"Nazwij swoją postać: ";
                cin>>nickname;
                CharacterCreate();
                save();
                loading();
                gra();
                break;
            case '2':
            {
                int firstTime=load_save();
                if(firstTime==-1)
                    break;
                else
                    gra();
                break;
            }
            case '3':
            {
                system("cls");
                cout << "Atak znajduje się pod przyciskiem A!\n";
                cout << "Obrona znajduje się pod przyciskiem D!\n";
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
                return;
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
    //ustawianie czcionki
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 24;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_HEAVY;
    std::wcscpy(cfi.FaceName, L"Lucida Sans Typewritter"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    //ustawianie enkodowania w konsoli
    SetConsoleOutputCP(65001);

    system("title W\243\323CZNIE I BUTY"); //https://www.ic.unicamp.br/~stolfi/EXPORT/www/ISO-8859-1-Encoding.html Ł to £ przez co nie ma ł XD chociaż £ wypisuje jako Ł
    cout << "Włócznie i Buty" << endl; // nazwa gry do wymyslenia
    Sleep(2500);
    system("cls");
    cout << "Autorzy:" << endl;
    cout << "-Filip Kasperski" << endl
         << "-Patryk Przybył";
    Sleep(2500);
    system("cls");
    menu();

    return 0;
}
