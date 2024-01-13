#include <iostream>
#include <vector>
#include <cmath>

const long long int a = 1366;
const long long int c = 150889;
const long long int m = 714025;
long long int zarodek;


void wczytaj_zarodek(){
    std::cout << "Podaj zarodek: ";
    std::cin >> zarodek;
}

double generuj_ui(long long int xi){
    return double(xi) / m;
}

long long int generuj_xi(long long int x)
{
    return (a * x + c) % m;
}

std::vector<double> generuj_tablice_ui(const int rozmiar){
    std::vector<double> tab(rozmiar);

    long long int xi = generuj_xi(zarodek);

    for(int i(0); i < rozmiar; i++){
        xi = generuj_xi(xi);        
        tab[i] = generuj_ui(xi);       
    }

    return tab; 
}

void wypisz(const std::vector<double> t){
    for(auto it: t)
        std::cout << it << std::endl;
}

double srednia(const std::vector<double> t){
    if(t.size() == 0)
        throw std::runtime_error(std::string(__func__) + ": tablica jest pusta.");
    
    double suma = 0;
    
    for(auto it: t)
        suma += it;

    return suma / t.size();   
}

double odchylenie(const std::vector<double> t){
    if(t.size() == 0)
        throw std::runtime_error(std::string(__func__) + ": tablica jest pusta.");
    
    // Oczekujemy odchylenia 1/sqrt(12) ~ 0.288...

    double sred = srednia(t);

    double suma = 0;

    for(auto it: t)
        suma += (it - sred) * (it - sred);

    return std::sqrt(suma / t.size());
}


int main() {
    wczytaj_zarodek();

    std::vector<double> loski(generuj_tablice_ui(10000));
    
    // wypisz(loski);      

    std::cout << srednia(loski) << "\t" << odchylenie(loski) << std::endl;

    main();
    return 0;
}


/*
    2, 11, 13 - wybieramy 3 liczby
    

    Konstuujemy swoj wlasny generator i obliczamy moc 

    Warunki na 500 000 < m < 10 000 000
    a - 4 lub 5 cyfr

    PDF - parametry
*/