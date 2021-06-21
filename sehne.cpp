#include "sehne.h" 


double BogenMass(double gradwinkel)
{
 return(( (gradwinkel * M_PI) / 180));
}

void ZeigeSehnenlaenge(double sehnenlnge)
{
 std::cout << std::endl << "Sehnenlaenge: " << sehnenlnge << std::endl;
}


double ShowWidif(struct bohrdat *boda)
{
 
 boda->widif = fabs(boda->gwi - boda->kwi);
 
 if (boda->widif > 180) boda->widif = 360 - boda->widif;
  std::cout << std::endl << "Winkel-Differenz:" << boda->widif;

return(boda->widif);
}

//void BOHPO (double winkel, double gr)
void BOHPO (struct bohrdat *boda)
{
 double xf, yf;

  boda->grboma = BogenMass(boda->gwi);
  boda->klboma = BogenMass(boda->kwi);
  boda->grcos = cos(boda->grboma);
  boda->grsin = sin(boda->grboma);
  boda->grtan = tan(boda->grboma);
  boda->klcos = cos(boda->klboma);
  boda->klsin = sin(boda->klboma);
  boda->kltan = tan(boda->klboma);

  xf = 1;
  yf = 1; //-1;
  boda->grx = (boda->grcos * boda->grradius * xf);
  boda->gry = (boda->grsin * boda->grradius * yf);
  boda->klx = (boda->klcos * boda->klradius * xf);
  boda->kly = (boda->klsin * boda->klradius * yf);
}

void GROZE (std::string titel, struct bohrdat boda)
{
  std::cout << std::endl << "                    " << titel << std::endl;
  std::cout << "                      grosser Teilkreis        kleiner Teilkreis" << std::endl;
  std::cout << "------------------------------------------------------------------" << std::endl;
  std::cout << "Durchmesser:    ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.grdmr << "     ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.kldmr << std::endl;
  std::cout << "Radius:         ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.grradius << "     ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.klradius << std::endl;
  std::cout << "Winkel          ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.gwi << "     ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.kwi << std::endl;
  std::cout << "Sinus           ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.grsin << "     ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.klsin << std::endl;
  std::cout << "Cosinus         ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.grcos << "     ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.klcos << std::endl;
  std::cout << "Tangens         ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.grtan << "     ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.kltan << std::endl;
  std::cout << "Pos X-Achse     ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.grx << "     ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.klx << std::endl;
  std::cout << "Pos Y-Achse     ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.gry << "     ";
  std::cout << std::setw(16) << std::setprecision(12) << boda.kly << std::endl;
  std::cout << "Sehnenlaenge: " << boda.s << std::endl;
}


// Achsen-Maße der Bohrunge   n vom Kreismittelpunkt aus gerechnet
double GetSehnenlaenge(struct bohrdat *boda)
{
 double widif, grpr,  krpr; 
 double ax, bx, rewer, dummy, nok, boms, abewi, a, b;
 
 boda->grradius = boda->grdmr / 2;
 boda->klradius = boda->kldmr / 2;
 
 
 widif = boda->widif;
 grpr = boda->grradius;
 krpr = boda->klradius; 

 if (widif < 90)
  {
   boms = BogenMass(widif);
   a = sin(boms) * grpr;
   b = (cos(boms) * grpr) - krpr;
   ax = a * a;
   bx = b * b;
   dummy = ax + bx;
   rewer = sqrt(dummy);
   std::cout << std::endl << "<90";
  }
 if ( widif == 90 )
     {
      ax    = krpr * krpr;
      bx    = grpr * grpr;
      dummy = ax + bx;
      rewer = sqrt(dummy);
     std::cout << std::endl << "=90";
     }

 if ((widif > 90) && (widif < 180))
     {
      abewi = widif - 90;       /* Zur Berechnung Anahme, das grosser Polarrarius auf X-Achse liegt */
      nok =  BogenMass(abewi);
      a = cos(nok) * krpr;
      b = sin(nok) * krpr;
      ax = a * a;                     /* kleine Kathete des virtuellen Dreiecks (auf Y-Achse) */
      bx = (b + grpr) * (b + grpr);   /* grosse Kathete des virtuellen Dreiecks (auf X-Achse) */
      dummy = ax + bx;
      rewer = sqrt(dummy);
     std::cout << std::endl << ">90  < 180";
     }
 if (widif == 180)
  {
  rewer = grpr + krpr;
  std::cout << std::endl << "=180";
  }
return(rewer);
}

void GetBohrungswerte(struct bohrdat *boda)
{
 double miwert, minwert_schnabel, minwert_spitze, maxwert_schnabel, maxwert_spitze;   


    // Eingabe D und Toleranzen Bohrung kleiner TK
       std::cout << "Durchmesser Bohrung kleiner Tk: ";
       std::cin >> boda->dmrbohrung_kltk;
       std::cout << "EI Durchmesser Bohrung kleiner Tk: ";
       std::cin >> boda->ei_dmrbohrung_kltk; 
       std::cout << "ES Durchmesser Bohrung kleiner Tk: ";
       std::cin >> boda->es_dmrbohrung_kltk; 
       // Eingabe D und Toleranzen Bohrung grosser TK
       std::cout << "Durchmesser Bohrung grosser Tk: ";
       std::cin >> boda->dmrbohrung_grtk;
       std::cout << "EI Durchmesser Bohrung grosser Tk: ";
       std::cin >> boda->ei_dmrbohrung_grtk; 
       std::cout << "ES Durchmesser Bohrung grosser Tk: ";
       std::cin >> boda->es_dmrbohrung_grtk; 
     
             
       // Errechne GU und GO Bohrung grosser TK
       boda->gu_dmrbohrung_grtk = boda->dmrbohrung_grtk + boda->ei_dmrbohrung_grtk; 
       boda->go_dmrbohrung_grtk = boda->dmrbohrung_grtk + boda->es_dmrbohrung_grtk;
       // Errechne GU und GO Bohrung kleiner TK
       boda->gu_dmrbohrung_kltk = boda->dmrbohrung_kltk + boda->ei_dmrbohrung_kltk; 
       boda->go_dmrbohrung_kltk = boda->dmrbohrung_kltk + boda->es_dmrbohrung_kltk;
       
       miwert = (boda->dmrbohrung_kltk + boda->dmrbohrung_grtk) / 2;
       minwert_schnabel = (boda->go_dmrbohrung_kltk + boda->go_dmrbohrung_grtk) / 2;
       minwert_spitze = (boda->gu_dmrbohrung_kltk + boda->gu_dmrbohrung_grtk) / 2;
       maxwert_schnabel = (boda->gu_dmrbohrung_kltk + boda->gu_dmrbohrung_grtk) / 2;
       maxwert_spitze = (boda->go_dmrbohrung_kltk + boda->go_dmrbohrung_grtk) / 2;
       /*
       std::cout << "-------------------------------------"<< std::endl; 
       
       std::cout << "Durchmesser Bohrung kleiner Tk...: " << boda->dmrbohrung_kltk << std::endl;
       std::cout << "EI Durchmesser Bohrung kleiner Tk: " << boda->ei_dmrbohrung_kltk << std::endl; 
       std::cout << "ES Durchmesser Bohrung kleiner Tk: " << boda->es_dmrbohrung_kltk << std::endl; 
       std::cout << "GU Bohrung kleiner Tk............: " << boda->gu_dmrbohrung_kltk << std::endl; 
       std::cout << "GO Bohrung kleiner Tk............: " << boda->go_dmrbohrung_kltk << std::endl; 
       // Eingabe D und Toleranzen Bohrung grosser TK
       std::cout << "Durchmesser Bohrung grosser Tk...: " << boda->dmrbohrung_grtk  << std::endl;
       std::cout << "EI Durchmesser Bohrung grosser Tk: " << boda->ei_dmrbohrung_grtk << std::endl; 
       std::cout << "ES Durchmesser Bohrung grosser Tk: " << boda->es_dmrbohrung_grtk << std::endl;
       std::cout << "GU Bohrung grosser Tk............: " << boda->gu_dmrbohrung_grtk << std::endl; 
       std::cout << "GO Bohrung grosser Tk............: " << boda->go_dmrbohrung_grtk << std::endl;  
         
       std::cout << "-------------------------------------"<< std::endl;  
       
       std::cout << "miwert..........: " << miwert << std::endl;
       std::cout << "minwert_schnabel: " << minwert_schnabel << std::endl;
       std::cout << "minwert_spitze..: " << minwert_spitze << std::endl;
       std::cout << "maxwert_schnabel: " << maxwert_schnabel << std::endl;
       std::cout << "maxwert_spitze..: " << maxwert_spitze << std::endl;
       */

       // Sehnenlaenge Wert bei Nennmass
       boda->s_mit_spitzen = boda->s + miwert;
       boda->s_mit_schnaebel = boda->s - miwert; 
       
       // Sehnenlaenge kleinster Wert
       boda->s_gu_mit_spitzen = boda->s + minwert_spitze;
       boda->s_gu_mit_schnaebel = boda->s - minwert_schnabel;
       
       // Sehnenlaenge groesster Wert
       boda->s_go_mit_spitzen = boda->s + maxwert_spitze;
       boda->s_go_mit_schnaebel = boda->s - maxwert_schnabel;
       
       
}    

void GetTK_Toleranzen(struct bohrdat *boda)
 {       
       std::cout << "Eingabe der Toleranzen der Teilkreise" << std::endl;
       std::cout << "Durchmesser kleiner Teilkreis unteres Abmass: ";
       std::cin >> boda->ei_kleinerTK;
       std::cout << "Durchmesser kleiner Teilkreis oberes Abmass: ";
       std::cin >> boda->es_kleinerTK;
       std::cout << "Durchmesser grosser Teilkreis unteres Abmass: ";
       std::cin >> boda->ei_grosserTK;
       std::cout << "Durchmesser grosser Teilkreis oberes Abmass: ";
       std::cin >> boda->es_grosserTK;
       
       boda->gu_kleinerTK = boda->kldmr + boda->ei_kleinerTK;
       boda->go_kleinerTK = boda->kldmr + boda->es_kleinerTK;
       boda->gu_grosserTK = boda->grdmr + boda->ei_grosserTK;
       boda->go_grosserTK = boda->grdmr + boda->es_grosserTK;
       
 }
 

void ShowToleranzwerteTeilkreise(struct bohrdat boda)
{       
       std::cout << std::endl << "                  Toleranzwerte der Teilkreise" << std::endl;
       std::cout << "                        grosser Teilkreis        kleiner Teilkreis" << std::endl;
       std::cout << "--------------------------------------------------------------------" << std::endl;
       std::cout << "Nenndurchmesser:    ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.grdmr << "     ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.kldmr << std::endl;
       std::cout << "unteres Abmass:     ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.ei_grosserTK << "     ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.ei_kleinerTK << std::endl;
       std::cout << "oberes Abmass       ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.es_grosserTK << "     ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.ei_kleinerTK << std::endl;
       std::cout << "Mindestmass         ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.gu_grosserTK << "     ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.gu_kleinerTK << std::endl;
       std::cout << "Höchstmass          ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.go_grosserTK << "     ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.go_kleinerTK << std::endl;
 
 
}       


void SetStructvalues(struct bohrdat *boda)
{
   boda->grdmr = 200;
   boda->kldmr = 100;
   boda->gwi = 0;
   boda->kwi = 60;
   boda->grradius = 0;
   boda->klradius = 0;
   boda->winkel = 0;
   boda->grboma = 0;
   boda->klboma = 0;
   boda->grcos = 0;
   boda->grsin = 0;
   boda->grtan = 0;
   boda->klcos = 0;
   boda->klsin = 0;
   boda->kltan = 0;
   boda->grx = 0;
   boda->gry = 0; 
   boda->klx = 0;
   boda->kly = 0; 
   boda->widif = 0; 
   boda->s = 0;     //Nennmass Sehnenlaenge
   boda->s_go = 0;
   boda->s_gu = 0;
   boda->dmrbohrung_grtk = 20; 
   boda->ei_dmrbohrung_grtk = -0.1; 
   boda->es_dmrbohrung_grtk = 0.1; 
   boda->go_dmrbohrung_grtk = 20.1; 
   boda->gu_dmrbohrung_grtk = 19.9; 
   boda->dmrbohrung_kltk = 10;
   boda->ei_dmrbohrung_kltk = -0.1;
   boda->es_dmrbohrung_kltk = 0.1;
   boda->go_dmrbohrung_kltk = 10.1;
   boda->gu_dmrbohrung_kltk = 9.9;
   boda->s_mit_spitzen = 0;
   boda->s_mit_schnaebel = 0;
   boda->s_gu_mit_spitzen = 0;
   boda->s_gu_mit_schnaebel = 0;
   boda->s_go_mit_spitzen = 0;
   boda->s_go_mit_schnaebel = 0;
   boda->ei_kleinerTK = 0;
   boda->es_kleinerTK = 0;
   boda->ei_grosserTK = 0;
   boda->es_grosserTK = 0;
   boda->gu_kleinerTK = 0;
   boda->go_kleinerTK = 0;
   boda->gu_grosserTK = 0;
   boda->go_grosserTK = 0;
    
}

void ZeigeBohrungswerte(struct bohrdat boda)
{
       std::cout << "Bohrungswerte zeigen: " << std::endl;
       std::cout << std::endl << "                  Toleranzwerte der Bohrungen" << std::endl;
       std::cout << "                        grosser Teilkreis        kleiner Teilkreis" << std::endl;
       std::cout << "--------------------------------------------------------------------" << std::endl;
       std::cout << "Bohrungsdurchmesser ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.dmrbohrung_grtk << "     ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.dmrbohrung_kltk << std::endl;
       std::cout << "unteres Abmass:     ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.ei_dmrbohrung_grtk << "     ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.ei_dmrbohrung_kltk << std::endl;
       std::cout << "oberes Abmass       ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.es_dmrbohrung_grtk << "     ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.es_dmrbohrung_kltk << std::endl;
       std::cout << "Mindestmass         ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.gu_dmrbohrung_grtk << "     ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.gu_dmrbohrung_kltk << std::endl;
       std::cout << "Höchstmass          ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.go_dmrbohrung_grtk << "     ";
       std::cout << std::setw(16) << std::setprecision(12) << boda.go_dmrbohrung_kltk << "     ";
       
}