#ifndef FELSOROLO_H_INCLUDED
#define FELSOROLO_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>

struct Nap
{
  std::string datum; //EEEE.HH.NN
  std::vector <int> udito;  //mindig 10 elemu

  std::vector <int> arak; //mindig 10

  bool sok;
  int forgalom;

};

class Felsorolo
{
    private:
        enum Status
        {
          norm, abnorm
        };

        Status sx;
        Nap dx;
        std::ifstream x;

        void Read(Status & sx, Nap & dx, std::ifstream & x);

    public:
        Felsorolo(std::string fname);
        ~Felsorolo();

        void First();
        void Next();
        Nap Current() const;
        bool End() const;




};




#endif // FELSOROLO_H_INCLUDED
