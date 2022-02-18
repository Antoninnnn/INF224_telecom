#ifndef PHOTO_H
#define PHOTO_H


#include "multimedia.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory>
using namespace std;

class Photo: public Multimedia{
private:
    float latitude=0;
    float longetitude = 0;


public:
    Photo(){}
    Photo(string _nom,string _nom_du_fichier):Multimedia(_nom,_nom_du_fichier){}
    Photo(string _nom,string _nom_du_fichier,float lati, float longe):Multimedia(_nom,_nom_du_fichier),latitude(lati),longetitude(longe){}
    ~Photo()override{}
    void setLatitude(float f)
    {
        latitude = f;
    }
    void setLongetitude(float f)
    {
        longetitude = f;
    }
    float getLatitude(){
        return latitude;
    }
    float getLongetitude(){
        return longetitude;
    }
    void affichage(ostream& ostream) const override
    {
        Multimedia::affichage(ostream);
        ostream << "latitude:" << latitude << "longitude:" << longetitude << endl;
    }
    void jouer() const override{
        string cmd = "imagej "+nom_du_fichier + " &";
        system(cmd.c_str());
    }


};
using PhotoPtr = shared_ptr<Photo>;

#endif // PHOTO_H
