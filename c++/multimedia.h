/**
 * @file multimedia.h
 * @author YANG_Yining (yining.yang@telecom-paris.fr)
 * @brief The higest origin class for multimedias
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <iostream>
#include <string>
#include "multimedia.h"
//#include <memory>

using namespace std;


/**
 * @class <Multimedia>
 * @brief Multimedia could be inherited by Photo and Video
 * 
 */
class Multimedia
{
protected:

    string nom = ""; /**
     * @brief the name of the multimedia in our system
     * 
     */

    string nom_du_fichier = "";/**
     * @brief the path of the file in our system
     * 
     */
    

public:
    /**
     * @brief Construct a new Multimedia object
     * 
     */
    Multimedia();
    /**
     * @brief Construct a new Multimedia object
     * 
     * @param _nom input of name of the multimedia in our system
     * @param nom_du_fichier the path of the multimedia in our system
     */
    Multimedia(string,string);
    /**
     * @brief Construct a new Multimedia object with the reference of other
     * 
     */
    Multimedia(const Multimedia&);
    /**
     * @brief define the operator= for Multimedia
     * 
     * @return Multimedia& 
     */
    Multimedia& operator=(const Multimedia&);
    /**
     * @brief Destroy the Multimedia object (virtual defined)
     * 
     */
    virtual ~Multimedia();
    /**
     * @brief Get the Nom object
     * 
     * @return string 
     */
    string getNom() const;
    /**
     * @brief Get the Nom Du Fichier object
     * 
     * @return string 
     */
    string getNomDuFichier() const;
    /**
     * @brief Set the Nom object
     * 
     */
    void setNom(string);
    /**
     * @brief Set the Nom Du Fichier object
     * 
     */
    void setNomDuFichier(string);
    /**
     * @brief print the information for the Multimedia (nom,nom_du_ficher)
     * 
     */
    virtual void affichage(ostream&)const;
    /**
     * @brief play the multimedia
     * @note
     *  The attribute is purely virtual here.
     * 
     */
    virtual void jouer()const = 0;
};

#endif // MULTIMEDIA_H
