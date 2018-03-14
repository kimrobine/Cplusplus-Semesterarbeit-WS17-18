#include "passagier.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

string bringeAttributWert (string attributName, string& zeile);
string bringeTagWert (string tagName, string& zeile);

Passagier::Passagier (string *PassagierDatenXML) {
   Sitzplatz = bringeAttributWert("reihe:sitz", PassagierDatenXML[0]);
   Nachname = bringeTagWert("nachname", PassagierDatenXML[2]);
   Vorname = bringeTagWert("vorname", PassagierDatenXML[3]);
   GepaeckStueckzahl = bringeTagWert("stueckzahl", PassagierDatenXML[6]);
   GepaeckGesamtgewicht = bringeTagWert("gesamtgewicht", PassagierDatenXML[7]);
}

vector<string> Passagier::neueXMLerstellen() {
   // Vektor für Erstellung der Auflistung deklarieren
    vector<string> zeile;

   /* string-Variablen aus Klasse "Passagier" werden eingesetzt */
   zeile.push_back("<passagier reihe:sitz= "+Sitzplatz+">");
   zeile.push_back("<passagierName>");
   zeile.push_back("<nachname>" + Nachname + "</nachname>");
   zeile.push_back("<vorname>" + Vorname + "</vorname>");
   zeile.push_back("</passagierName>");
   zeile.push_back("<passagierGepaeck>");
   zeile.push_back("<stueckzahl>" + GepaeckStueckzahl + "</stueckzahl>");
   zeile.push_back("<gesamtgewicht>" + GepaeckGesamtgewicht + "</gesamtgewicht>");
   zeile.push_back("</passagierGepaeck>");
   zeile.push_back("<nationalitaet>" + Nationalitaet + "</nationalitaet>");
   zeile.push_back("</passagier>");

   // Anschließend wird der so zusammengesetzte Datenblock eines Passagiers (als string) zurückgegben
   return zeile;
}


//Ausgeben-Funktion für Suchergebnisse


string bringeAttributWert(string attributName, string &zeile) {
   int zeiger = zeile.find(attributName)+attributName.length();
   char puffer = '\0';

   while(puffer != 34){              //34 --> ASCII-Code für das Anführungszeichen
       puffer = zeile.at(zeiger);
       zeiger++;
   }

   puffer = 0;
   string attributWert;

   while(puffer != 34){
       puffer = zeile.at(zeiger);
       if(puffer != 34){
       attributWert += puffer;
       zeiger++;
   }
   }
return attributWert;
}


string bringeTagWert(string tagName, string &zeile){
   int zeiger = zeile.find("<"+tagName+"")+tagName.length();
   char puffer = 0;
   string tagWert;

   while(puffer != '>') {
       puffer = zeile.at(zeiger);
       zeiger++;
   }

   puffer = 0;

   while(puffer != '<') {
       puffer = zeile.at(zeiger);
       if(puffer != '<'){
           tagWert += puffer;
           zeiger++;
       }
   }
   return tagWert;
}

