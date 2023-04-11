#include<iostream>
#include<vector>
#include<iomanip>
#include<cstdlib>
#include<stdio.h>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<string>
using namespace std;
struct T_data_dostawy{int dzien, miesiac, rok;};
struct T_dane_produktu
{
    char nazwa[256], producent[256], model[50], uwagi[1000];
    string kategoria;
    int liczba_sztuk;
    double cena;
    T_data_dostawy data_dostawy;
};
void wczytaj_date_dostawy(T_data_dostawy &data)
{
    cout<<"Podaj przewidywana date dostawy: "<<endl;
    cout<<"Dzien:";
    cin>>data.dzien;
    cout<<"Miesiac:";
    cin>>data.miesiac;
    cout<<"Rok:";
    cin>>data.rok;
}
void wyswietl_date_dostawy(const T_data_dostawy &data)
{
    cout<<data.dzien<<"."<<data.miesiac<<"."<<data.rok;
}
string wybor_kategorii()
{
    string typ_produktu;
    int wybor1;
    cout<<"Wybierz kategorie produktu:"<<endl;
    cout<<"1. Procesor"<<endl;
    cout<<"2. Karta graficzna"<<endl;
    cout<<"3. Plyta glowna"<<endl;
    cout<<"4. Pamiec RAM"<<endl;
    cout<<"5. Zasilacz"<<endl;
    cout<<"6. Obudowa"<<endl;
    cout<<"7. Chlodzenie"<<endl;
    cin>>wybor1;
    switch(wybor1)
    {
        case 1: typ_produktu="procesor";          break;
        case 2: typ_produktu="karta graficzna";   break;
        case 3: typ_produktu="plyta glowna";      break;
        case 4: typ_produktu="pamiec RAM";        break;
        case 5: typ_produktu="zasilacz";          break;
        case 6: typ_produktu="obudowa";           break;
        case 7: typ_produktu="chlodzenie";        break;
        default: cout<<"Nie ma takiej opcji!";    break;
    }
    system("cls");
    return typ_produktu;
}
void wczytaj_produkt(vector<T_dane_produktu> &produkt)
{
    int rozmiar=produkt.size();
    produkt.resize(rozmiar+1);
    rozmiar=produkt.size();
    produkt[rozmiar-1].kategoria=wybor_kategorii();
    cin.ignore();
    cout<<"---DANE PRODUKTU---"<<endl;
    cout<<"Podaj nazwe: ";
    cin.getline(produkt[rozmiar-1].nazwa, 256);
    cout<<"Podaj producenta: ";
    cin.getline(produkt[rozmiar-1].producent, 256);
    cout<<"Podaj model: ";
    cin.getline(produkt[rozmiar-1].model, 50);
    cout<<"Podaj ilosc sztuk w magazynie: ";
    cin>>produkt[rozmiar-1].liczba_sztuk;
    cout<<"Podaj cene: ";
    cin>>produkt[rozmiar-1].cena;
    wczytaj_date_dostawy(produkt[rozmiar-1].data_dostawy);
    cout<<"Podaj uwagi: ";
    cin.ignore();
    cin.getline(produkt[rozmiar-1].uwagi, 1000);
    system("cls");
    cout<<"Dodano produkt!";
}
void wyswietl_produkt(const T_dane_produktu &produkt)
{
    cout<<"---DANE PRODUKTU---"<<endl;
    cout<<"Nazwa:                     "<<produkt.nazwa<<endl;
    cout<<"Producent:                 "<<produkt.producent<<endl;
    cout<<"Model:                     "<<produkt.model<<endl;
    cout<<"Kategoria:                 "<<produkt.kategoria<<endl;
    cout<<"Liczba sztuk w magazynie:  "<<produkt.liczba_sztuk<<endl;
    cout<<"Cena:                      "<<produkt.cena<<endl;
    cout<<"Przewidywana data dostawy: ";wyswietl_date_dostawy(produkt.data_dostawy);cout<<endl;
    cout<<"Uwagi:                     "<<produkt.uwagi;
}
void usun_produkt(vector<T_dane_produktu> &produkty)
{
    int x;
    cout<<"Wybierz z listy produkt, ktory chcesz usunac"<<endl;
    for(size_t i=0; i<produkty.size(); i++)
    {
        cout<<"Produkt nr. "<<i+1<<": "<<produkty[i].nazwa<<endl;
    }
    cin>>x;
    x=x-1;
    produkty.erase(produkty.begin()+x);
    system("cls");
    cout<<"Produkt zostal usuniety!";
}
void zmiana_danych(vector<T_dane_produktu> &produkty)
{
    int x;
    cout<<"Wybierz z listy produkt, ktory chcesz edytowac"<<endl;
    for(size_t i=0; i<produkty.size(); i++)
    {
        cout<<"Produkt nr. "<<i+1<<": "<<produkty[i].nazwa<<endl;
    }
    cin>>x;
    system("cls");
    cout<<"Obecnie: "<<endl;
    wyswietl_produkt(produkty[x-1]);
    cout<<endl<<endl<<"Nowe: "<<endl;
    wczytaj_produkt(produkty);
    system("cls");
    cout<<"Zmieniono dane produktu!";
}
void zmiana_dostawy(vector<T_dane_produktu> &produkty)
{
    int x;
    cout<<"Wybierz z listy produkt, ktory chcesz edytowac"<<endl;
    for(size_t i=0; i<produkty.size(); i++)
    {
        cout<<"Produkt nr. "<<i+1<<": "<<produkty[i].nazwa<<endl;
    }
    cin>>x;
    system("cls");
    cout<<"Obecna data dostawy: ";wyswietl_date_dostawy(produkty[x-1].data_dostawy);
    cout<<endl;
    wczytaj_date_dostawy(produkty[x-1].data_dostawy);
    system("cls");
    cout<<"Zmieniono date dostawy!";
}
void spis_produktow(vector<T_dane_produktu> &produkty)
{
    int x;
    cout<<"Spis wszystkich produktow(wybierz, aby zobaczyc szegolowe dane):"<<endl;
    for(size_t i=0; i<produkty.size(); i++)
    {
        cout<<"Produkt nr. "<<i+1<<": "<<produkty[i].nazwa<<endl;
    }
    cin>>x;
    system("cls");
    wyswietl_produkt(produkty[x-1]);
}
void wyszukaj_produkt(vector<T_dane_produktu> &produkty)
{
    int y;
    string str;
    cout<<"Wybierz po jakich parametrach chcesz sszukac produktu:"<<endl;
    cout<<"1. Nazwa"<<endl;
    cout<<"2. Model"<<endl;
    cout<<"3. Producent"<<endl;
    cin>>y;
    if(y==1)
    {
        system("cls");
        char tab[256];
        cout<<"Podaj nazwe szukanego produktu: ";
        cin.ignore();
        cin.getline(tab, 256);
        int roz=produkty.size();
        system("cls");
        int x=1;
        cout<<"Wyszukane produkty(wybierz, aby zobaczyc szczegolowe dane)"<<endl;
        for(int i=0; i<roz; i++)
        {
            if(stricmp(tab, produkty[i].nazwa)==0)
                cout<<"Produkt nr. "<<x++<<": "<<produkty[i].nazwa<<endl;
            else
                cout<<"Nie ma takiego produktu!"; return;
        }
        cin>>x;
        system("cls");
        wyswietl_produkt(produkty[x-1]);
    }
    if(y==2)
    {
        system("cls");
        char tab[50];
        cout<<"Podaj model szukanego produktu: ";
        cin.ignore();
        cin.getline(tab, 50);
        int roz=produkty.size();
        system("cls");
        int x=1;
        cout<<"Wyszukane produkty(wybierz, aby zobaczyc szczegolowe dane)"<<endl;
        for(int i=0; i<roz; i++)
        {
            if(stricmp(tab, produkty[i].model)==0)
                cout<<"Produkt nr. "<<x++<<": "<<produkty[i].nazwa<<endl;
            else
                cout<<"Nie ma takiego produktu!"; return;
        }
        cin>>x;
        system("cls");
        wyswietl_produkt(produkty[x-1]);
    }
    if(y==3)
    {
        system("cls");
        char tab[256];
        cout<<"Podaj producenta szukanego produktu: ";
        cin.ignore();
        cin.getline(tab, 256);
        int roz=produkty.size();
        system("cls");
        int x=1;
        cout<<"Wyszukane produkty(wybierz, aby zobaczyc szczegolowe dane)"<<endl;
        for(int i=0; i<roz; i++)
        {
            if(stricmp(tab, produkty[i].producent)==0)
                cout<<"Produkt nr. "<<x++<<": "<<produkty[i].nazwa<<endl;
            else
                cout<<"Nie ma takiego produktu!"; return;
        }
        cin>>x;
        system("cls");
        wyswietl_produkt(produkty[x-1]);
    }
}
void zapisz_baze(vector<T_dane_produktu> &produkty)
{
    fstream baza_danych;
    baza_danych.open("bazadanych.txt",ios::out|ios::trunc);
    for(size_t i=0; i<produkty.size(); i++)
    {
        baza_danych<<produkty[i].nazwa<<endl;
        baza_danych<<produkty[i].producent<<endl;
        baza_danych<<produkty[i].model<<endl;
        baza_danych<<produkty[i].kategoria<<endl;
        baza_danych<<produkty[i].uwagi<<endl;
        baza_danych<<produkty[i].liczba_sztuk<<endl;
        baza_danych<<produkty[i].cena<<endl;
        baza_danych<<produkty[i].data_dostawy.dzien<<endl;
        baza_danych<<produkty[i].data_dostawy.miesiac<<endl;
        baza_danych<<produkty[i].data_dostawy.rok<<endl;
    }
    baza_danych.close();
    cout<<"Zapisano dane!";
}
void wczytaj_baze(vector<T_dane_produktu> &produkty)
{
    fstream baza_danych;
    baza_danych.open("bazadanych.txt",ios::in);
    if(baza_danych.good()==false)
    {
        cout<<"Plik nie istnieje!";
        system("pause");
        return;
    }
    else
    {
        int rozmiar=produkty.size();
        string str;

        while(!baza_danych.eof())
        {
            produkty.resize(rozmiar+1);
            rozmiar=produkty.size();
            //baza_danych.ignore();
            baza_danych.getline(produkty[rozmiar-1].nazwa, 256);
            baza_danych.getline(produkty[rozmiar-1].producent, 256);
            baza_danych.getline(produkty[rozmiar-1].model, 50);
            getline(baza_danych, produkty[rozmiar-1].kategoria);
            baza_danych.getline(produkty[rozmiar-1].uwagi, 1000);
            baza_danych>>str; produkty[rozmiar-1].liczba_sztuk=atoi(str.c_str());
            baza_danych>>str; produkty[rozmiar-1].cena=atof(str.c_str());
            baza_danych>>str; produkty[rozmiar-1].data_dostawy.dzien=atoi(str.c_str());
            baza_danych>>str; produkty[rozmiar-1].data_dostawy.miesiac=atoi(str.c_str());
            baza_danych>>str; produkty[rozmiar-1].data_dostawy.rok=atoi(str.c_str());
            baza_danych.ignore();
        }
        baza_danych.close();
        cout<<"Wczytano baze!";
    }
}
int main()
{
    vector<T_dane_produktu> produkty;
    int wybor;
    for(;;)
    {
        cout<<"  MENU BAZY DANYCH  "<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1. Dodaj produkt"<<endl;
        cout<<"2. Usun produkt"<<endl;
        cout<<"3. Zmien dane produktu"<<endl;
        cout<<"4. Dodaj/zmien date dostawy"<<endl;
        cout<<"5. Spis wszystkich produktow"<<endl;
        cout<<"6. Wyszukaj produkt"<<endl;
        cout<<"7. Zapisz zgromadzona baze danych do pliku"<<endl;
        cout<<"8. Wczytaj zapisana baze danych z pliku"<<endl;
        cout<<"9. Wyjscie"<<endl;
        cout<<endl;
        cin>>wybor;
        switch(wybor)
        {
            case 1: system("cls"); wczytaj_produkt(produkty);   break;
            case 2: system("cls"); usun_produkt(produkty);      break;
            case 3: system("cls"); zmiana_danych(produkty);     break;
            case 4: system("cls"); zmiana_dostawy(produkty);    break;
            case 5: system("cls"); spis_produktow(produkty);    break;
            case 6: system("cls"); wyszukaj_produkt(produkty);  break;
            case 7: system("cls"); zapisz_baze(produkty);       break;
            case 8: system("cls"); wczytaj_baze(produkty);      break;
            case 9: system("cls"); exit(0);                     break;
            default: cout<<"Nie ma takiej opcji w menu!";       break;
        }
        cout<<endl;
        system("pause");
        system("cls");
    }
    return 0;
}
