//
// main.cpp
// Created on 01/01/2022
//

#include <iostream>
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include <list>
#include "gestionnaire.h"

using namespace std;


// to compile the code, use make to compile
// to run the code use make run


int main(int argc, const char* argv[] )
{
//    Multimedia * base_multimedia = new Multimedia("first_class","/cal/exterieurs/yang-21/INF224/base_multimedia");

/*
    Multimedia ** multimedias = new Multimedia *[10];
    unsigned int count  = 0;
    multimedias[count++]  = new Video("video1","/cal/exterieurs/yang-21/INF224/medias/videos/video1");
    multimedias[count++]  = new Video("video2","/cal/exterieurs/yang-21/INF224/medias/videos/video2");
    multimedias[count++]  = new Video("video3","/cal/exterieurs/yang-21/INF224/medias/videos/video3");
    multimedias[count++]  = new Photo("photo1","/cal/exterieurs/yang-21/INF224/medias/photos/photo1");
    multimedias[count++]  = new Photo("photo2","/cal/exterieurs/yang-21/INF224/medias/photos/photo2");
    multimedias[count++]  = new Photo("photo3","/cal/exterieurs/yang-21/INF224/medias/photos/photo3");
    multimedias[count++]  = new Photo("photo4","/cal/exterieurs/yang-21/INF224/medias/photos/photo4");
    multimedias[count++]  = new Photo("photo5","/cal/exterieurs/yang-21/INF224/medias/photos/photo5");
    cout<< count<<endl;*/

//    std::cout << "Hello brave new world" << std::endl;


    //delete [] multimedias;
    //    delete base_multimedia;
    MultimediaPtr v1(new Video("video1","/cal/exterieurs/yang-21/INF224/medias/videos/video1"));  //shared_ptr did not to be manually deleted
    MultimediaPtr p1(new Photo("photo1","/cal/exterieurs/yang-21/INF224/medias/photos/photo1"));

    //Group *grp1 = new Group("group1");


    //grp1->affichage(cout);
    Gestionnaire * geste = new Gestionnaire();
    Photo p2= geste->createPhoto("photo2","/cal/exterieurs/yang-21/INF224/media/photos/photo2");
    Photo p3= geste->createPhoto("photo3","/cal/exterieurs/yang-21/INF224/media/photos/photo3");
    Video v2= geste->createVideo("video2","/cal/exterieurs/yang-21/INF224/media/videos/video2");
    Video v3= geste->createVideo("video3","/cal/exterieurs/yang-21/INF224/media/videos/video3");
    Group grp1 = geste->createGroup("group1");
    grp1.push_back(v1);
    grp1.push_back(p1);
    geste->afficherGroup("group1",cout);
    geste->afficherMulti("photo3",cout);
    geste->jouerMulti("video3");








    delete geste;



    return 0;
}
