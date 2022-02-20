/**
 * @file gestionnaire.h
 * @author YANG_Yining (yining.yang@telecom-paris.fr)
 * @brief The Overral Manager of the Multimedia System
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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

/**
 * @class <Gestionnaire>
 * @brief The 
 * 
 */
class Gestionnaire{
private:

    MultimediaDict mtable;/**<The map dictionary that contains Multimedia pointers*/
    GroupDict gtable;/**<The map dictionary that contains the Group pointers.*/

public:

    /**
     * @brief Construct a new Gestionnaire object
     * 
     */
    Gestionnaire(){}
    /**
     * @brief Destroy the Gestionnaire object
     * 
     */
    ~Gestionnaire(){}
    /**
     * @brief Create a Photo object in mtable and return it
     * 
     * @param _nom 
     * @param _nom_du_fichier 
     * @return Photo 
     */
    Photo createPhoto(string _nom, string _nom_du_fichier){
        PhotoPtr p(new Photo(_nom,_nom_du_fichier));
        mtable[_nom] = p;
        return *p;
    }
    /**
     * @brief Create a Video object in mtable and return it
     * 
     * @param _nom 
     * @param _nom_du_fichier 
     * @return Video 
     */
    Video createVideo(string _nom, string _nom_du_fichier){
        VideoPtr v(new Video(_nom,_nom_du_fichier));
        mtable[_nom] = v;
        return *v;
    }
    /**
     * @brief Create a Video object in mtable and return it
     * 
     * @param _nom 
     * @param _nom_du_fichier 
     * @param d 
     * @return Video 
     */
    Video createVideo(string _nom, string _nom_du_fichier,float d){
        VideoPtr v(new Video(_nom,_nom_du_fichier,d));
        mtable[_nom] = v;
        return *v;
    }
    /**
     * @brief Create a Film object in mtable and return it
     * 
     * @param _nom 
     * @param _nom_du_fichier 
     * @return Film 
     */
    Film createFilm(string _nom, string _nom_du_fichier){
        FilmPtr f(new Film(_nom,_nom_du_fichier));
        mtable[_nom] = f;
        return *f;
    }
    /**
     * @brief Create a Film object in mtable and return it
     * 
     * @param _nom 
     * @param _nom_du_fichier 
     * @param d 
     * @param n 
     * @return Film 
     */
    Film createFilm(string _nom, string _nom_du_fichier,int * d , unsigned int n){
        FilmPtr f(new Film(_nom,_nom_du_fichier,d,n));
        mtable[_nom] = f;
        return *f;
    }
    /**
     * @brief Create a Group object in the gtable and return it
     * 
     * @param _nom 
     * @return Group 
     */
    Group createGroup(string _nom){
        GroupPtr g(new Group(_nom));
        gtable[_nom] = g;
        return *g;
    }
    /**
     * @brief Find the multimedia pointer in mtable by its name and return it
     * 
     * @param m Name of multimedia we want
     * @return MultimediaPtr 
     */
    MultimediaPtr findMultiP(string m){
        auto mul = mtable.find(m)->second;
        return mul;
    }
    /**
     * @brief Find the Group pointer in mtable by its name and return it
     * 
     * @param m Name of multimedia we want
     * @return GroupPtr 
     */
    GroupPtr findGroupP(string m){
        auto pp = gtable.find(m)->second;
        return pp;
    }
    /**
     * @brief Supprome the Multimedia pointer in mtable
     * 
     * @param m Name of the Multimedia we want to delete
     */
    void suprimerMultiP(string m){
        mtable.erase(m);
    }
    /**
     * @brief Supprome the Group pointer in gtable
     * 
     * @param m Name of the Group we want to delete
     */
    void suprimerGroupP(string m){
        gtable.erase(m);
    }
    /**
     * @brief Print the Multimedia information to a outputstream
     * 
     * @param m The name of the Multimedia we want to print
     * @param ost The outputstream to contains the information
     */
    void afficherMulti(string m, ostream & ost){
        findMultiP(m)->affichage(ost);
    }
    /**
     * @brief Print the Multimedia information to a outputstream
     * 
     * @param m The name of the Multimedia we want to print
     * @param ost The outputstream to contains the information
     */
    void afficherGroup(string m, ostream & ost){
        findGroupP(m)->affichage(ost);
    }
    /**
     * @brief Play the multimedia by its name
     * 
     * @param m The name of the multimedia we want to play
     */
    void jouerMulti(string m){
        findMultiP(m)->jouer();
    }



};





#endif // TABLES_H
