/**
 * @file group.h
 * @author YANG_Yining (yining.yang@telecom-paris.fr)
 * @brief 
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
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

/**
 * @class <Group>
 * @brief The class of list of Multimedia pointers
 * 
 */
class Group: public list<MultimediaPtr>{

private:
    /**
     * @brief nom is the name of the group
     * 
     */
    string nom;  // Il est un objet qui possède un constructeur!!! pas besoin de l'initialiser

public:

    /**
     * @brief Construct a new Group object
     * 
     */
    Group(){}
    
    /**
     * @brief Destroy the Group object
     * 
     */
    ~Group(){}
    /**
     * @brief Get the Nom object
     * 
     * @return string 
     */
    string getNom(){
        return nom;
    }
    /**
     * @brief Print the information of multimedias in the group to the outputstream
     * 
     * @param ostream The outputstream to register the informations
     */
    void affichage(ostream & ostream){
        for (auto &it : *this) it->affichage(ostream);
    }



//    mlist.push_back(Multimedia());
//



};



#endif // GROUP_H
