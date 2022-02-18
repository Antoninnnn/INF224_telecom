#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <iostream>
#include <string>
//#include <memory>

using namespace std;

class Multimedia
{
protected:
    string nom = "";
    string nom_du_fichier = "";

public:
    Multimedia();
    Multimedia(string _nom,string nom_du_fichier);
    virtual ~Multimedia() =0;
    string getNom() const;
    string getNomDuFichier() const;
    void setNom(string);
    void setNomDuFichier(string);
    virtual void affichage(ostream&)const;
    virtual void jouer()const = 0;
};

#endif // MULTIMEDIA_H
