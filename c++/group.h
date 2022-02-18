#ifndef GROUP_H
#define GROUP_H
#include "multimedia.h"
//#include "video.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory>
#include <list>

using namespace std;

using MultimediaPtr = shared_ptr<Multimedia>;
//typedef std::shared_ptr<Truc> TrucPtr;

class Group: public list<MultimediaPtr>{
private:
    string nom;  // Il est un objet qui possède un constructeur!!! pas besoin de l'initialiser

public:
    Group(){}
    Group(string name_){nom = name_;}
    ~Group(){}

    string getNom(){
        return nom;
    }

    void affichage(ostream & ostream){
        for (auto &it : *this) it->affichage(ostream);
    }



//    mlist.push_back(Multimedia());
//



};



#endif // GROUP_H
