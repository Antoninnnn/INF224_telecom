/**
 * @file multimedia.cpp
 * @author YANG_Yining (yining.yang@telecom-paris.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "multimedia.h"
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Construct a new Multimedia:: Multimedia object
 * 
 */
Multimedia::Multimedia(){}

/**
 * @brief Construct a new Multimedia:: Multimedia object
 * 
 * @param _nom name of the multimedia in our system
 * @param _nom_du_fichier path of the multimedia
 */

Multimedia::Multimedia(string _nom, string _nom_du_fichier):nom(_nom),nom_du_fichier(_nom_du_fichier){}
/**
 * @brief Construct a new Multimedia:: Multimedia object
 * 
 * @param m the multimidia object (passage par reference)
 */
Multimedia::Multimedia(const Multimedia& m){
        nom = m.nom;
        nom_du_fichier = m.nom_du_fichier;
}
/**
 * @brief Define the operator= for the Multimedia class
 * 
 * @param m const multimedia object (passage par reference)
 * @return Multimedia& 
 */
Multimedia& Multimedia::operator=(const Multimedia& m){
        nom = m.nom;
        nom_du_fichier = m.nom_du_fichier;
        return *this;
    }

/**
 * @brief Destroy the Multimedia:: Multimedia object
 * 
 */
Multimedia::~Multimedia()
{}



/**
 * @brief Get the name of the multimedia
 * 
 * @return string 
 */
string Multimedia::getNom() const
{
    return nom;
}

/**
 * @brief Get the path of the multimedia
 * 
 * @return string 
 */
string Multimedia::getNomDuFichier() const
{
    return nom_du_fichier;
}

/**
 * @brief set the name of Multimedia
 * 
 * @param N String: name of multimedia
 */
void Multimedia::setNom(string N)
{
    nom = N;
}
/**
 * @brief set the path of Multimedia
 * 
 * @param N String: path of the multimedia
 */
void Multimedia::setNomDuFichier(string N)
{
    nom_du_fichier = N;
}
/**
 * @brief Print the information of multimedia
 * 
 * @param ostream 
 *  the outputstream that contains the 
 *  information we want to print
 */
void Multimedia::affichage(ostream & ostream) const
{
    ostream << "name:" << nom << "path:" << nom_du_fichier ;
}
