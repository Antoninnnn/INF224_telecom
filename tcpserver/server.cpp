//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "../gestionnaire.h"


#include "../multimedia.h"
#include "../photo.h"
#include "../video.h"
#include "../film.h"
#include "../group.h"
#include <list>

const int PORT = 3331;


int main(int argc, char* argv[])
{
    MultimediaPtr v1(new Video("video1","/cal/exterieurs/yang-21/INF224/medias/videos/video1"));  //shared_ptr did not to be manually deleted
    MultimediaPtr p1(new Photo("photo1","/cal/exterieurs/yang-21/INF224/medias/photos/photo1"));

    //Group *grp1 = new Group("group1");


    //grp1->affichage(cout);
    Gestionnaire * geste = new Gestionnaire();
    Photo p2= geste->createPhoto("photo2","/cal/exterieurs/yang-21/INF224/media/photos/photo2");
    Photo p3= geste->createPhoto("photo3","/cal/exterieurs/yang-21/INF224/media/photos/photo3");
    Photo p4= geste->createPhoto("photo4","/cal/exterieurs/yang-21/INF224/media/photos/photo4");
    Photo p5= geste->createPhoto("photo5","/cal/exterieurs/yang-21/INF224/media/photos/photo5");

    Video v2= geste->createVideo("video2","/cal/exterieurs/yang-21/INF224/media/videos/video2");
    Video v3= geste->createVideo("video3","/cal/exterieurs/yang-21/INF224/media/videos/video3");
    Group grp1 = geste->createGroup("group1");
    grp1.push_back(v1);
    grp1.push_back(p1);
    //geste->afficherGroup("group1",cout);
    //geste->afficherMulti("photo3",cout);
    //geste->findMultiP()
    //geste->findGroupP()
    //geste->jouerMulti("video3");








    
  
  // cree le TCPServer
  
  
  auto* server =
  new TCPServer( [&](std::string const& request, std::string& response) {

    // the request sent by the client to the server
    std::cout << "request: " << request << std::endl;

    std::stringstream ss;
    ss<<request;

    std::string cm,nom;

    ss>>cm>>nom;

    if (cm=="RechercherMultimedia"){
      MultimediaPtr m = geste->findMultiP(nom);
      response = nom+"found in server";
    }
    else if (cm=="RechercherGroup"){
      GroupPtr g = geste->findGroupP(nom);
      response = nom+"found in server";
    }
    else if(cm =="AfficherMultimedia"){
      std::stringstream s;
      geste->afficherMulti(nom,s);
      response = "The Multimedia is: "+s.str();
     
 
    }
    else if(cm =="AfficherGroup"){
      std::stringstream s;
      geste->afficherMulti(nom,s);
      response = "The Multimedia is: "+s.str();
     

    }
    else if(cm=="JouerMultimedia"){
      geste->jouerMulti(nom);
      response = nom+"played in the server";
    }



    // the response that the server sends back to the client
    

    // return false would close the connecytion with the client
    return true;
  });


  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }
  delete geste;

  return 0;
}

