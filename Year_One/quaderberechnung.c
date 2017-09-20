#include <stdio.h>

double berechne_rechteckflaeche(double s1, double s2)
{
   double a;
   a = s1*s2;
   return a;
}

double berechne_rechteckkantenlaenge(double s1,double s2)
{
   double sk;
   sk = 2*s1+2*s2;
   return sk;
}

double berechne_quadervolumen(double s1, double s2, double s3)
{
   double volumen, grundflaeche;
   grundflaeche = berechne_rechteckflaeche(s1,s2);
   volumen = grundflaeche * s3;
   return volumen;
}

double berechne_quaderoberflaeche(double s1, double s2, double s3)
{
   double ao;
   ao = 2*berechne_rechteckflaeche(s1,s2)
      + 2*berechne_rechteckflaeche(s1,s3)
      + 2*berechne_rechteckflaeche(s2,s3);
   return ao;
}

double berechne_quaderkantenlaenge(double s1,double s2,double s3)
{
   double sk;
   sk = berechne_rechteckkantenlaenge(s1,s2)
      + berechne_rechteckkantenlaenge(s1,s3)
      + berechne_rechteckkantenlaenge(s2,s3);
   return sk;
}

double berechne_masse(double v, double rho)
{
   double m;
   m = v * rho;
   return m;
}

int main(void)
{ 
#  define RHO_STEIN 2400 /* kg/m^3 */
   double laenge    = 6.0;
   double hoehe     = 2.5;
   double breite    = 2.5;
   double wanddicke = 0.1;
   double farbdicke = 0.5e-3;
   
   double volumen_baumaterial;
   double volumen_umbaut;
   double baumasse_in_kg;
   double volumen_wandfarbe;
   double kantenlaenge;
   
   volumen_umbaut = berechne_quadervolumen(laenge,breite,hoehe);
   volumen_baumaterial = berechne_quaderoberflaeche(laenge,breite,hoehe)
                       * wanddicke;
   baumasse_in_kg = berechne_masse(volumen_baumaterial,RHO_STEIN);
   volumen_wandfarbe = ( 2*berechne_rechteckflaeche(laenge,hoehe)
                        +2*berechne_rechteckflaeche(breite,hoehe))
                       * farbdicke;
   kantenlaenge = berechne_quaderkantenlaenge(laenge, breite, hoehe);
   
   printf("Umbautes Volumen  = %lf m^3\n", volumen_umbaut);
   printf("Baumaterial-Vol.  = %lf m^3\n", volumen_baumaterial);
   printf("Volumen Baumasse  = %lf kg\n",  baumasse_in_kg);
   printf("Volumen Wandfarbe = %lf l\n", volumen_wandfarbe*1000.0);
   printf("Kantenlaenge f. Blitzschutz = %lf m\n", kantenlaenge);
   return 0;
}

