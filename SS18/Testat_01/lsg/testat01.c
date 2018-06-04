/**
 * Technische Mechanik II (MW SoSe 2018)
 *
 * Testat 1
 *
 * Compile:  gcc -Wall -std=gnu99 -pedantic <datei.c> -lm -o <datei>
 *
 * Option -lm wird verwendet, um Bibliothek <math.h> einzubinden.
 */
#include <stdio.h>
#include <math.h>

#define PI ((double)3.14159265359)

int main () {
  
  //Variablendeklaration
  double d, x, L1, L2, L3, E, F1, F2;
  double FC = 0, // Lagerreaktion, obere vertikale Einspannung, in [N]
         FD = 0; // Lagerreaktion, untere vertikale Einspannung, in [N]
  double A = 0; // Kreisfoermige Flaeche
  double Ux = 0; // Vertikale Verschiebung an der Stelle x
  
  //Einlesen der Werte
  printf("\nDurchmesser d in [m]: ");
  scanf("%lf", &d);
  
  printf("\nVertikale Stelle x in [m]: ");
  scanf("%lf", &x);
  
  printf("\nAbstand L1 in [m]: ");
  scanf("%lf", &L1);
  
  printf("\nAbstand L2 in [m]: ");
  scanf("%lf", &L2);
  
  printf("\nAbstand L3 in [m]: ");
  scanf("%lf", &L3);
  
  printf("\nModul E in [GPa]: ");
  scanf("%lf", &E);
  
  printf("\nKraft F1 in [kN]: ");
  scanf("%lf", &F1);
  
  printf("\nKraft F2 in [kN]: ");
  scanf("%lf", &F2);
  
  //Umrechnen der Einheiten: [m]->[mm], [GPa]->[MPa], [kN]->[N]
  d *= 1000; // [mm]
  x *= 1000; // [mm]
  L1 *= 1000; // [mm] 
  L2 *= 1000; // [mm]
  L3 *= 1000; // [mm]
  E *= 1000; // [MPa] = [N/mm^2]
  F1 *= 1000; // [N]
  F2 *= 1000; // [N]  
  
  //Berechnen der Lagerreaktionen
  FC = (F1*(L3-L1)-F2*(L3-L2))/L3;
  FD = F1-F2-FC;
  
  //Berechnen der Flaeche
  A = pow(d/2.0,2)*PI;
  
  //Berechnen der vertikalen Verschiebung an der Stelle x
  if ( 0 <= x && x <= L1 ) {
    Ux = FC*x/(E*A);
  } else if ( L1 < x && x <= L2 ) {
    Ux = (FC*x-F1*(x-L1))/(E*A);
  } else if ( L2 < x && x <= L3 ) {
    Ux = (FC*x-F1*(x-L1)+F2*(x-L2))/(E*A);
  }
  
  printf("\nLagerreaktion (vertikale obere Einspannung):  FC = %lf [N]", FC);
  printf("\nLagerreaktion (vertikale untere Einspannung): FD = %lf [N]", FD);
  printf("\n\nVertikale Verschiebung:  U(x=%.2lf [m]) = %.2lf [mm]\n\n", x/1000, Ux);
  
  return 0;
}
