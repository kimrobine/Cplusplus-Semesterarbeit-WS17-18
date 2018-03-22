#ifndef VERZEICHNIS_H
#define VERZEICHNIS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "passagier.h"
using namespace std;

/* Die Klasse "Verzeichnis" wird benötigt, um eine konvertierte neue XML-Datei zu erstellen, die die Daten aus beiden Datenquellen
 * (flugdatenListe.xml & zolldatenListe.xml) zusammenführt. Mit einem vector wird ein "datenIndex" erzeugt, der alle vorhandenen
 * Informationen beinhaltet und aus dem bestimmte Daten zu einzelnen Personen herausgesucht oder die gesamte Liste ausgegeben werden kann */

class Verzeichnis {

private:
    vector<Passagier> datenIndex;

public:
   enum Kategorie{Sitzplatz=0, Nachname=1, Vorname=2, GepaeckGesamtgewicht=3, Nationalitaet=4, BuchungsNR=5, BonusMeilen=6, GepaeckStueckzahl=7};
   void Ausgabe();
   void auslesenXML();
   void auslesenTXT();
   Passagier * Suche(Kategorie kategorie, string suchBegriff);
   void neueXMLerstellen(string neuerDateiname);

};

#endif // VERZEICHNIS_H
