#ifndef VERZEICHNIS_H
#define VERZEICHNIS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "passagier.h"
using namespace std;


class Verzeichnis {

private:
    vector<Passagier> datenIndex;

public:
   enum Kategorie{Sitzplatz=0, Nachname=1, Vorname=2, GepaeckStueckzahl=3, GepaeckGesamtgewicht=4, Nationalitaet=5};
   //Ausgabe-Funktion
   void auslesenXML();
   void auslesenTXT();
   Passagier * Suche(Kategorie kategorie, string suchBegriff);
   void neueXMLerstellen(string neuerDateiname);

};

#endif // VERZEICHNIS_H
