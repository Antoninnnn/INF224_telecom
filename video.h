#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"
#include <memory>
#include <string>
#include <stdlib.h>


using namespace std;


class Video: public Multimedia{
private:
    float duree=0.0;


public:
    Video(){}
    Video(string _nom,string _nom_du_fichier):Multimedia(_nom,_nom_du_fichier){}
    Video(string _nom,string _nom_du_fichier,float d):Multimedia(_nom,_nom_du_fichier),duree(d){}

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
        ostream <<  "duree:" << duree << endl;
    }
    void jouer() const override{
        string cmd = "mpv "+nom_du_fichier + " &";
        system(cmd.c_str());
    }
};
using VideoPtr = shared_ptr<Video>;

#endif // VIDEO_H

