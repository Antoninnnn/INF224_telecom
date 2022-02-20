/**
 * @file video.h
 * @author YANG_Yining (yining.yang@telecom-paris.fr)
 * @brief Header file implement all attributes of the Video class which extends from Multimedia
 * 
 * @version 0.1
 * @date 2022-02-20
 * @note 
 *  There are 3 constructors overloading for the class.
 *  The constructor from the reference and operator= is implemented.
 *  Same level as the Photo class
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"
#include <memory>
#include <string>
#include <stdlib.h>


using namespace std;

/**
 * @class <Video>
 * @brief Video class extend the Multimedia clas
 * @note 
 *  it contains all the protected attributes of Multimedia(nom,nom_du_fichier)
 * 
 */
class Video: public Multimedia{
protected:

    float duree=0.0;/**<length of the Video in minutes*/


public:
/**
 * @brief Construct a new Video object
 * 
 */
    Video(){}
    /**
     * @brief Construct a new Video object as Multimedia
     * 
     * @param _nom input of name of the multimedia in our system
     * @param nom_du_fichier the path of the multimedia in our system
     */
    Video(string _nom,string _nom_du_fichier):Multimedia(_nom,_nom_du_fichier){}
    
    /**
     * @brief Construct a new Video object
     * 
     * @param _nom input of name of the multimedia in our system
     * @param nom_du_fichier the path of the multimedia in our system
     * @param d length of the Video in minutes
     */
    Video(string _nom,string _nom_du_fichier,float d):Multimedia(_nom,_nom_du_fichier),duree(d){}
    
    /**
     * @brief Construct a new Video object from an Video object (passage par reference)
     * 
     * @param v a Video object
     */
    Video(const Video& v):Multimedia(v){
        duree = v.duree;
    }

    /**
     * @brief Define the operator=
     * 
     * @param v a Video object
     * @return Video& 
     */
    Video& operator=(const Video& v){
        Multimedia::operator=(v);
        duree = v.duree;
        return *this;
    }
    

/**
 * @brief Destroy the Video object (override the destroy of Multimedia)
 * 
 */
    ~Video()override{}
    /**
     * @brief Set the Duree object
     * 
     * @param d The duration we are going to set
     */
    void setDuree(float d)
    {
        duree = d;
    }
    /**
     * @brief Get the Duree object
     * 
     * @return float 
     */
    float getDuree(){
        return duree;
    }
    /**
     * @brief 
     *  print the information for 
     *  the Multimedia (nom,nom_du_ficher)
     * 
     * @param ostream 
     */
    void affichage(ostream& ostream) const override
    {
        Multimedia::affichage(ostream);
        //ostream << "name:" << nom << "path:" << nom_du_fichier << "duree:" << duree << endl;
        ostream <<  " duree:" << duree << endl;
    }
    /**
     * @brief play the video
     * 
     */
    void jouer() const override{
        string cmd = "mpv "+nom_du_fichier + " &";
        system(cmd.c_str());
    }
};
using VideoPtr = shared_ptr<Video>;

#endif // VIDEO_H

