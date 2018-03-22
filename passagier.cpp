#include "passagier.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/* Für die Verarbeitung von Attributnamen und Tagnamen werden Funktionen und Parameter vom Datentyp string deklariert */
string bringeAttributWert (string attributName, string& zeile);
string bringeTagWert (string tagName, string& zeile);

/* Definition der Funktionen, um auf den jeweiligen AttributWert bzw. TagWert aus der XML zugreifen zu können:
 * Es werden die Werte aus den Anführungszeichen (" ") und den spitzen Klammern (<>) geparsed und anschließend
 * im vorgesehenen string gespeichert und zurückgegeben, damit sie zu einem späteren Zeitpunkt in die Datei
 * eingefügt werden können */
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


/* Die Parameter werden bei Aufruf der Parser-Funktionen definiert: Der Name des Attributes/Tags
 * und die Zeile, in der sich die Information befindet, werden übergeben. Die Daten der Passagiere
 * werden einzeln geparsed, im dafür vorgesehenen string gespeichert und mit dem Sitzplatz zusammengeführt,
 * um an der richtigen Stelle des Verzeichnisses eingesetzt werden zu können ([0][2][3][6][7]) */
Passagier::Passagier (string *PassagierDatenXML) {
   Sitzplatz = bringeAttributWert("reihe:sitz", PassagierDatenXML[0]);
   Nachname = bringeTagWert("nachname", PassagierDatenXML[2]);
   Vorname = bringeTagWert("vorname", PassagierDatenXML[3]);
   GepaeckStueckzahl = bringeTagWert("stueckzahl", PassagierDatenXML[6]);
   GepaeckGesamtgewicht = bringeTagWert("gesamtgewicht", PassagierDatenXML[7]);
}


/* Funktion, um die Daten zu kombinieren und in einer neuen XML-Datei zu speichern.
 * Die Passagierdaten sollen jedes Mal um eine Zeile erweitert werden, um das Verzeichnis
 * so zu schrittweise zu vervollständigen, bis die gesamte Datenmenge bearbeitet wurde.
 * Dies wird ermöglicht, indem der Vektor zeile mit dem Befehl ".push_back" kombiniert wird */
vector<string> Passagier::neueXMLerstellen() {
   /* Vektor für Erstellung der Auflistung */
    vector<string> zeile;

   /* string-Variablen aus Klasse "Passagier", die bereits die aus XML und TXT ausgelesenen Werte enthalten,
    * werden nach und nach eingesetzt, um das Verzeichnis zu erweitern; inklusive auch der leeren bzw. schließenden Tags */
   zeile.push_back(" <passagier reihe:sitz=\"" + Sitzplatz + "\">");
   zeile.push_back("  <passagierName>");
   zeile.push_back("   <nachname>" + Nachname + "</nachname>");
   zeile.push_back("   <vorname>" + Vorname + "</vorname>");
   zeile.push_back("  </passagierName>");
   zeile.push_back("  <passagierGepaeck>");
   zeile.push_back("   <stueckzahl>" + GepaeckStueckzahl + "</stueckzahl>");
   zeile.push_back("   <gesamtgewicht>" + GepaeckGesamtgewicht + "</gesamtgewicht>");
   zeile.push_back("  </passagierGepaeck>");
   zeile.push_back("  <passagierInfo>");
   zeile.push_back("  <nationalitaet>" + Nationalitaet + "</nationalitaet>");
   zeile.push_back("  <buchungsnummer nr=\"" + BuchungsNR + "\"></buchungsnummer>");
   zeile.push_back("  <bonusmeilen>" + BonusMeilen + "</bonusmeilen>");
   zeile.push_back("  </passagierInfo>");
   zeile.push_back(" </passagier>");

   /* Anschließend wird der so zusammengesetzte Datenblock eines Passagiers zurückgegeben */
   return zeile;
}


/* Funktion für die Ausgabe der Passagierinformationen, wenn Such-Anfrage des Users erfolgreich war.
 * Die mit Werten gefüllten strings werden hier in die Ausgabe eingesetzt */
void Passagier::ausgeben(){
   cout << "Übereinstimmung für folgende(n) Reisende(n) gefunden: " << endl << endl;
   cout << "Sitzplatz: " << Sitzplatz << endl;
   cout << "Nachname: " << Nachname << endl;
   cout << "Vorname: " << Vorname << endl;
   cout << "Anzahl der aufgegebenen Gepäckstücke: " << GepaeckStueckzahl << endl;
   cout << "Gesamtgewicht der aufgegebenen Gepäckstücke: " << GepaeckGesamtgewicht << endl;
   cout << "Nationalität: " << Nationalitaet << endl;
   cout << "Buchungsnummer: " << BuchungsNR << endl;
   cout << "Bonusmeilen: " << BonusMeilen << endl;
}

