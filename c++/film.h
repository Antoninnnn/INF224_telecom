/**
 * @file film.h
 * @author YANG_Yining (yining.yang@telecom-paris.fr)
 * @brief The Film class extending the Video class which includes more information than videos
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef FILM_H
#define FILM_H
#include "multimedia.h"
#include "video.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory>

/**
 * @class <Film>
 * @brief The Film class inherited from Video
 * 
 */
class Film: public Video{
private:
    /**
     * @brief the duration of different chapiter
     * 
     */
    int* durees=new int[10];  //the duration for different chapters
    /**
     * @brief the number of chapiter
     * 
     */
    unsigned int n_chap = 0;  //the number of chapters

public:

    /**
     * @brief Construct a new Film object
     * 
     */
    Film(){}
    /**
     * @brief Construct a new Film object
     * 
     * @param _nom Same as multimedia
     * @param _nom_du_fichier Same as multimedia
     */
    Film(string _nom,string _nom_du_fichier):Video(_nom,_nom_du_fichier){}
    /**
     * @brief Construct a new Film object
     * 
     * @param _nom 
     * @param _nom_du_fichier 
     * @param d The int arrays representing different durations of chapiters
     * @param n The number of chapiters
     * @note 
     *  For the durees as a type of int array, we firstly 
     *  delete its default one and set it as a new one. 
     *  Then we copy() the input to the new int array
     */
    Film(string _nom,string _nom_du_fichier,int * d , unsigned int n){
        nom = _nom;
        nom_du_fichier = _nom_du_fichier;
        delete [] durees;
        n_chap = n;
        durees = new int[n_chap];
        copy(d, d+n,durees);
    }
    /**
     * @brief Construct a new Film object from a Film object
     * 
     * @param f a Film object passed by reference
     */
    Film(const Film& f):Video(f){
        n_chap = f.n_chap;
        durees = f.durees? new int(*f.durees):nullptr;

    };
    /**
     * @brief Define the operator=
     * 
     * @param f 
     * @return Film& 
     */
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
    /**
     * @brief Destroy the Film object
     * 
     */
    ~Film() override{
        delete [] durees;
    }
    /**
     * @brief Set the Duree object
     * 
     * @param d The int arrays representing different durations of chapiters
     * @param n The number of chapiters
     */
    void setDuree(int* d, unsigned int n)
    {
        delete [] durees;
        n_chap = n;
        durees = new int[n];
        copy(d, d+n,durees);
    }

    /**
     * @brief Get the Duree object
     * 
     * @param d 
     * @param n 
     */
    void getDuree(int* d, unsigned int n){
        if (n<n_chap){
            cout << "length of the int table is not large enough to contain all info" << endl;
            return;
        }
        n = n_chap;
        copy(durees, durees+n,d);
    }
    /**
     * @brief send the information of Film to outputstream
     * 
     * @param ostream the outputstream to store info.
     */
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
