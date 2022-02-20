/**
 * @file photo.h
 * @author YANG_Yining (yining.yang@telecom-paris.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PHOTO_H
#define PHOTO_H


#include "multimedia.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory>
using namespace std;


/**
 * @class <Photo>
 * @brief Photo class extend the Multimedia
 * @note it contains all the protected attributes of Multimedia
 * 
 */
class Photo: public Multimedia{
protected:

    float latitude=0;/**< @brief The latitude of the photo*/

    float longetitude = 0;/**<@brief The longetitude of the photo
     * 
     */


public:
/**
 * @brief Construct a new Photo object
 * 
 */
    Photo(){}
    /**
     * @brief Construct a new Photo object
     * 
     * @param _nom 
     * @param _nom_du_fichier 
     */
    Photo(string _nom,string _nom_du_fichier):Multimedia(_nom,_nom_du_fichier){}
    /**
     * @brief Construct a new Photo object
     * 
     * @param _nom 
     * @param _nom_du_fichier 
     * @param lati 
     * @param longe 
     */
    Photo(string _nom,string _nom_du_fichier,float lati, float longe):Multimedia(_nom,_nom_du_fichier),latitude(lati),longetitude(longe){}
    /**
     * @brief Destroy the Photo object
     * 
     */
    ~Photo()override{}
    /**
     * @brief Set the Latitude object
     * 
     * @param f 
     */
    void setLatitude(float f)
    {
        latitude = f;
    }
    /**
     * @brief Set the Longetitude object
     * 
     * @param f 
     */
    void setLongetitude(float f)
    {
        longetitude = f;
    }
    /**
     * @brief Get the Latitude object
     * 
     * @return float 
     */
    float getLatitude(){
        return latitude;
    }
    /**
     * @brief Get the Longetitude object
     * 
     * @return float 
     */
    float getLongetitude(){
        return longetitude;
    }
    /**
     * @brief send information of the multimedia to the outputstream
     * 
     * @param ostream 
     */
    void affichage(ostream& ostream) const override
    {
        Multimedia::affichage(ostream);
        ostream <<  " latitude: " << latitude << " longitude: " << longetitude << endl;
    }
    /**
     * @brief show the image
     * 
     */
    void jouer() const override{
        string cmd = "imagej "+nom_du_fichier + " &";
        system(cmd.c_str());
    }


};
using PhotoPtr = shared_ptr<Photo>;

#endif // PHOTO_H
