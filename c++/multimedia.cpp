#include "multimedia.h"
#include <iostream>
#include <string>
using namespace std;

Multimedia::Multimedia(){}

Multimedia::Multimedia(string _nom, string _nom_du_fichier):nom(_nom),nom_du_fichier(_nom_du_fichier){}

Multimedia::Multimedia(const Multimedia& m){
        nom = m.nom;
        nom_du_fichier = m.nom_du_fichier;
}
Multimedia& Multimedia::operator=(const Multimedia& m){
        nom = m.nom;
        nom_du_fichier = m.nom_du_fichier;
        return *this;
    }

Multimedia::~Multimedia()
{}




string Multimedia::getNom() const
{
    return nom;
}

string Multimedia::getNomDuFichier() const
{
    return nom_du_fichier;
}


void Multimedia::setNom(string N)
{
    nom = N;
}

void Multimedia::setNomDuFichier(string N)
{
    nom_du_fichier = N;
}

void Multimedia::affichage(ostream & ostream) const
{
    ostream << "name:" << nom << "path:" << nom_du_fichier ;
}
