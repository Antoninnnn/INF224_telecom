#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"
#include <memory>
#include <string>
#include <stdlib.h>


using namespace std;


class Video: public Multimedia{
protected:
    float duree=0.0;


public:
    Video(){}
    Video(string _nom,string _nom_du_fichier):Multimedia(_nom,_nom_du_fichier){}
    Video(string _nom,string _nom_du_fichier,float d):Multimedia(_nom,_nom_du_fichier),duree(d){}
    Video(const Video& v):Multimedia(v){
        duree = v.duree;
    }
    Video& operator=(const Video& v){
        Multimedia::operator=(v);
        duree = v.duree;
        return *this;
    }


    ~Video()override{}
    void setDuree(float d)
    {
        duree = d;
    }
    float getDuree(){
        return duree;
    }
    void affichage(ostream& ostream) const override
    {
        Multimedia::affichage(ostream);
        //ostream << "name:" << nom << "path:" << nom_du_fichier << "duree:" << duree << endl;
        ostream <<  " duree:" << duree << endl;
    }
    void jouer() const override{
        string cmd = "mpv "+nom_du_fichier + " &";
        system(cmd.c_str());
    }
};
using VideoPtr = shared_ptr<Video>;

#endif // VIDEO_H

