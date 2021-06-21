#ifndef SEHNE_INC_
#define SEHNE_INC_

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#include <math.h>
#include "menuefrage.h"

#define ENDOFCASE  wouhi = 11; break;  


static struct bohrdat{
   double grdmr;
   double grradius;
   double kldmr;
   double klradius;
   double winkel;
   double gwi;
   double kwi;
   double grboma;
   double klboma;
   double grcos;
   double grsin;
   double grtan;
   double klcos;
   double klsin;
   double kltan;
   double grx;
   double gry; 
   double klx;
   double kly; 
   double widif; 
   double s;     //Nennmass Sehnenlaenge
   double s_go;
   double s_gu;
   double dmrbohrung_grtk; 
   double ei_dmrbohrung_grtk; 
   double es_dmrbohrung_grtk; 
   double go_dmrbohrung_grtk; 
   double gu_dmrbohrung_grtk; 
   double dmrbohrung_kltk;
   double ei_dmrbohrung_kltk;
   double es_dmrbohrung_kltk;
   double go_dmrbohrung_kltk;
   double gu_dmrbohrung_kltk;
   double s_mit_spitzen;
   double s_mit_schnaebel;
   double s_gu_mit_spitzen;
   double s_gu_mit_schnaebel;
   double s_go_mit_spitzen;
   double s_go_mit_schnaebel;
   double ei_kleinerTK;
   double es_kleinerTK;
   double ei_grosserTK;
   double es_grosserTK;
   double gu_kleinerTK;
   double go_kleinerTK;
   double gu_grosserTK;
   double go_grosserTK;
  
} boda;



double BogenMass(double gradwinkel);
void ZeigeSehnenlaenge(double sehnenlnge);
double ShowWidif(struct bohrdat *boda);
void BOHPO (struct bohrdat *boda);
void GROZE (std::string titel, struct bohrdat boda);
double GetSehnenlaenge(struct bohrdat *boda);
void GetBohrungswerte(struct bohrdat *boda);
void GetTK_Toleranzen(struct bohrdat *boda);
void ShowToleranzwerteTeilkreise(struct bohrdat boda);
void SetStructvalues(struct bohrdat *boda);
void ZeigeBohrungswerte(struct bohrdat boda);


#endif