#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#include "multimedia.h"
#include "photo.h"
#include "film.h"
#include "video.h"
#include "group.h"
#include <iostream>
#include <map>
#include <string>
#include <memory>

using namespace std;
//using FilmPtr = shared_ptr<Film>;  //deja definit dans film
//using VideoPtr = shared_ptr<Video>;
//using PhotoPtr = shared_ptr<Photo>;
using GroupPtr = shared_ptr<Group>;

using MultimediaDict = map<string,MultimediaPtr>;
//using VideoDict = map<string,VideoPtr>;
using PhotoDict = map<string,PhotoPtr>;
//using FilmDict = map<string,FilmPtr>;
using GroupDict = map<string,GroupPtr>;

class Gestionnaire{
private:
    MultimediaDict mtable;
    GroupDict gtable;



public:
    Gestionnaire(){}
    ~Gestionnaire(){}

    Photo createPhoto(string _nom, string _nom_du_fichier){
        PhotoPtr p(new Photo(_nom,_nom_du_fichier));
        mtable[_nom] = p;
        return *p;
    }
    Video createVideo(string _nom, string _nom_du_fichier){
        VideoPtr v(new Video(_nom,_nom_du_fichier));
        mtable[_nom] = v;
        return *v;
    }
    Film createFilm(string _nom, string _nom_du_fichier){
        FilmPtr f(new Film(_nom,_nom_du_fichier));
        mtable[_nom] = f;
        return *f;
    }
    Group createGroup(string _nom){
        GroupPtr g(new Group(_nom));
        gtable[_nom] = g;
        return *g;
    }

    MultimediaPtr findMultiP(string m){
        auto mul = mtable.find(m)->second;
        return mul;
    }
    GroupPtr findGroupP(string m){
        auto pp = gtable.find(m)->second;
        return pp;
    }
    void suprimerMultiP(string m){
        mtable.erase(m);
    }
    void suprimerGroupP(string m){
        gtable.erase(m);
    }
    void afficherMulti(string m, ostream & ost){
        findMultiP(m)->affichage(ost);

    }
    void afficherGroup(string m, ostream & ost){
        findGroupP(m)->affichage(ost);
    }

    void jouerMulti(string m){
        findMultiP(m)->jouer();
    }



};





#endif // TABLES_H
