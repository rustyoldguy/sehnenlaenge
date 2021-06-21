#include "sehne.h" 

int main(int argc, char **argv)
{

int wouhi = 11, bohrungstoleranzengesetzt = 0;
struct bohrdat boda;
struct bohrdat bodamin;
struct bohrdat bodamax;

SetStructvalues(&boda);

do
switch(wouhi)
{
 default:   std::cout << std::endl << "Sehnenlaenge V0.05" << std::endl;
            std::cout << std::endl << "Berechnung der Sehnenlaenge" << std::endl;
            std::cout << "Programmende...........................0" << std::endl;
            std::cout << "Dmr & Winkel grosser Tk................1" << std::endl;  
            std::cout << "Dmr & Winkel kleiner Tk................2" << std::endl;  
            std::cout << "Sehnenlaenge...........................3" << std::endl;
            std::cout << "Dmr und Toleranzen der Bohrungen.......4" << std::endl;
            std::cout << "Sehnenlaenge mit Teilkreistoleranzen...5" << std::endl;
            std::cout << "Bohrungswerte zeigen...................6" << std::endl;
            wouhi = MenueFrage();
         break;  

 case 0:
      std::cout << "Programm beendet" << std::endl;
      return 0;
    break;  

 case 1:
        std::cout << "grosser TK-Winkel......: ";
        std::cin >> boda.gwi;
        std::cout << "grosser TK-Durchmesser.: ";
        std::cin >> boda.grdmr;
       ENDOFCASE 
    
 case 2:
       std::cout << "kleiner TK-Winkel......: ";
       std::cin  >>  boda.kwi;
       std::cout << "kleiner TK-Durchmesser.: ";
       std::cin >> boda.kldmr;
       ENDOFCASE

 case 3:
       boda.widif = ShowWidif(&boda);
       boda.s = GetSehnenlaenge(&boda);
       BOHPO(&boda);
       GROZE("Werte der Teilkreise bei Nennmass", boda);
       ENDOFCASE  
     
 case 4:
       bohrungstoleranzengesetzt = 1;
       GetBohrungswerte(&boda);
       ZeigeBohrungswerte(boda);
           
       // Sehnenlaenge Wert bei Nennmass
       std::cout << "\nSehnenlaenge bei Nennmass: " << std::endl;
       std::cout << "Mit Messspitzen..: " << boda.s_mit_spitzen << std::endl;
       std::cout << "Mit Messschnaebel: " << boda.s_mit_schnaebel << std::endl;
       
       std::cout << "Sehnenlaenge bei Nennmass kleinsten Werten Bohrungsdurchmesser: " << std::endl;
       std::cout << "Mit Messspitzen..: " << boda.s_gu_mit_spitzen << std::endl;
       std::cout << "Mit Messschnaebel: " << boda.s_gu_mit_schnaebel << std::endl;
       
       std::cout << "Sehnenlaenge bei Nennmass groessten Werten Bohrungsdurchmesser: " << std::endl;
       std::cout << "Mit Messspitzen..: " << boda.s_go_mit_spitzen << std::endl;
       std::cout << "Mit Messschnaebel: " << boda.s_go_mit_schnaebel << std::endl;
       ENDOFCASE     

 case 5:
       GetTK_Toleranzen(&boda);
       ShowToleranzwerteTeilkreise(boda);

       bodamin = boda;
       bodamin = boda;
       
       bodamin.grdmr = boda.gu_grosserTK; 
       bodamin.kldmr = boda.go_kleinerTK;        
       bodamin.grradius = bodamin.grdmr / 2;   
       bodamin.klradius = bodamin.kldmr / 2;
       
       bodamax.grdmr = boda.go_grosserTK; 
       bodamax.kldmr = boda.gu_kleinerTK;        
       bodamax.grradius = bodamin.grdmr / 2;   
       bodamax.klradius = bodamin.kldmr / 2;
            
       bodamin.s = GetSehnenlaenge(&bodamin);
       bodamax.s = GetSehnenlaenge(&bodamax);

       BOHPO(&bodamin);
       GROZE("\nTeilkreiswerte bei Gu kleinerTK und Go grosserTk", bodamin);
      
       std::cout << "\nSehnenlaenge bei Nennmass " << std::endl;
       std::cout << "Mit Messspitzen..: " << boda.s_mit_spitzen << std::endl;
       std::cout << "Mit Messschnaebel: " << boda.s_mit_schnaebel << std::endl;
       if (bohrungstoleranzengesetzt == 1)
       {
       std::cout << "\nSehnenlaenge bei Kleinstmass der Bohrungen: " << std::endl;
       std::cout << "Mit Messspitzen: " << bodamin.s_gu_mit_spitzen << std::endl;
       std::cout << "Mit Messschnaebel: " << bodamin.s_gu_mit_schnaebel << std::endl; 
       
       std::cout << "Sehnenlaenge bei Groesstmass der Bohrungen: " << std::endl;
       std::cout << "Mit Messspitzen..: " << bodamin.s_go_mit_spitzen << std::endl;
       std::cout << "Mit Messschnaebel: " << bodamin.s_go_mit_schnaebel << std::endl;      
       }
       
       
       BOHPO(&bodamax);
       GROZE("\nTeilkreiswerte bei Go kleinerTK und Gu grosserTk", bodamax);
        
       std::cout << "\nSehnenlaenge bei Nennmass " << std::endl;
       std::cout << "Nennmass Sehnenlaenge mit Messspitzen: " << bodamax.s_mit_spitzen << std::endl;
       std::cout << "Nennmass Sehnenlaenge mit Messschnaebel: " << bodamax.s_mit_schnaebel << std::endl;       
 
       if (bohrungstoleranzengesetzt == 1)
       {  
       std::cout << "Sehnenlaenge bei Kleinstmass der Bohrungen: " << std::endl;
       std::cout << "Mit Messspitzen: " << bodamax.s_gu_mit_spitzen << std::endl;
       std::cout << "Mit Messschnaebel: " << bodamax.s_gu_mit_schnaebel << std::endl; 
       
       std::cout << "Sehnenlaenge bei Groesstmass der Bohrungen: " << std::endl;
       std::cout << "Mit Messspitzen: " << bodamax.s_go_mit_spitzen << std::endl;
       std::cout << "Mit Messschnaebel: " << bodamax.s_go_mit_schnaebel << std::endl;      
       }
      ENDOFCASE  
      
      
  case 6:
       ZeigeBohrungswerte(boda);
       ENDOFCASE  
   


}while(wouhi != 0);

return EXIT_SUCCESS;
}


