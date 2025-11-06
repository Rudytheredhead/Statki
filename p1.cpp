#include <iostream>
#include <string>
#include<vector>
#include<cmath>
using namespace std;

class Statek{
public:
    int dlugosc;
    int px;
    int kx;
    int py;
    int ky;
    bool zatopiony;
    bool poziomy;
    string pole;
    vector<bool> trafienia;
    vector<string> pola;
    Statek (int d, int px_, int kx_, int py_, int ky_ ):
        dlugosc(d),
        trafienia(d),
        pola(d),
        px(px_),
        kx(kx_),
        py(py_),
        ky(ky_),
        zatopiony(false),
        poziomy(true),
        pole("")

        {
            if (px==kx){
                poziomy = false;
            }   
            for (int i = 0; i<dlugosc;i++){
                trafienia[i] = false;
                
                if (poziomy){
                    pole = {char(px+i),char(py)};
                }
                else{
                    pole = {char(px),char(py+i)};
                }
                pola[i]= pole;




            }



        }

};


class Plansza{
public:
    std::vector<std::vector<int>> pole;


    Plansza(){
        pole.resize(10, std::vector<int>(10));
    }
};

Statek dodawanie_statku(int dlugosc, Plansza& plansza){
    int px;
    int py;
    int kx;
    int ky;
    string p;
    string k;
    while (true){
        cout<<"podaj kordynatu statku o dlugosci "<<dlugosc<<endl;
        cin>>p;
        cin>>k;

        px = p[0];
        py = p[1];
        kx = k[0];
        ky = k[1];
        if (px ==kx && abs(ky - py) ==dlugosc-1 ){
            Statek p(dlugosc,px, kx,py,ky);
            for (int i = 0; i<dlugosc;i++){
                plansza.pole[py+i-'1'][kx-'a'] =1;
            }



            return p;
        }else if (py==ky && abs(kx-px)==dlugosc-1)
        {   Statek p(dlugosc,px, kx,py,ky);

            for (int i = 0; i<dlugosc;i++){
                plansza.pole[px+i-'a'][ky-'1'] =1;
            }
            return p;
        }
        else
        {
            cout<<"zle kordynaty"<<endl;
        }
    }
}

int main(){
    Plansza p1;
    Statek p = dodawanie_statku(2,p1);
    for (int i=0; i<p.dlugosc; i++){
        cout<<p.pola[i];
    }
    cout<<p1.pole[0][0];
   
}
