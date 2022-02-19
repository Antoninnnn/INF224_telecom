#ifndef FILM_H
#define FILM_H
#include "multimedia.h"
#include "video.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory>


class Film: public Video{
private:
    int* durees=new int[10];  //the duration for different chapters
    unsigned int n_chap = 0;  //the number of chapters

public:
    Film(){}
    Film(string _nom,string _nom_du_fichier):Video(_nom,_nom_du_fichier){}
    Film(string _nom,string _nom_du_fichier,int * d , unsigned int n){
        nom = _nom;
        nom_du_fichier = _nom_du_fichier;
        delete [] durees;
        n_chap = n;
        durees = new int[n_chap];
        copy(d, d+n,durees);
    }
    Film(const Film& f):Video(f){
        n_chap = f.n_chap;
        durees = f.durees? new int(*f.durees):nullptr;

    };
    Film& operator=(const Film& f){
        Video::operator=(f);
        n_chap = f.n_chap;
        if (durees&&f.durees) *durees = *f.durees;
        else{
            delete [] durees;
            durees = f.durees? new int(*f.durees):nullptr;

        }
        return *this;

    };

    ~Film() override{
        delete [] durees;
    }
    void setDuree(int* d, unsigned int n)
    {
        delete [] durees;
        n_chap = n;
        durees = new int[n];
        copy(d, d+n,durees);
    }

    void getDuree(int* d, unsigned int n){
        if (n<n_chap){
            cout << "length of the int table is not large enough to contain all info" << endl;
            return;
        }
        n = n_chap;
        copy(durees, durees+n,d);
    }
    void affichage(ostream& ostream) const override
    {
        Multimedia::affichage(ostream);
        ostream <<  " duree:" << duree << " nombre de chapitre: "<< n_chap <<" duree de chapitre:[" ;
        for (int i =0;i<n_chap;i++)
            ostream<<durees[i]<<"," ;
            
        ostream<< "]"<<endl;
    }
};

using FilmPtr = shared_ptr<Film>;


#endif // FILM_H
