#include "verzeichnis.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


/* Funktion zum Auslesen der Ausgangs-XML-Datei */
void Verzeichnis::auslesenXML(){

    /* Öffnen der XML-Datei */
    ifstream datei("flugdatenListe.xml");

    /* Deklaration des Vektoren (vom Datentyp String) für Nutzung als Puffer */
    vector<string> puffer;

    /* Schleife, die jede Zeile sichern soll */
    for(string zeile; getline(datei,zeile);){
        puffer.push_back(zeile);
    }

   puffer.erase(puffer.begin());
   puffer.pop_back();

   /* Einteilung der Passagierdaten in 10er-Blöcke, um die Informationen spezifisch jedem
    * Passagier zuordnen und unterscheiden zu können */
    for(auto i = 0u; i < puffer.size(); i += 10) {
        string zeilenProPassagier[10];
        for (int j = 0; j < 10; ++j) {
            zeilenProPassagier[j] = puffer.at(i+j);
        }
        Passagier x (zeilenProPassagier);
        datenIndex.push_back(x);
    }
}


/* Funktion zum Auslesen der TXT-Datei */
void Verzeichnis::auslesenTXT() {

    /* Öffnen der TXT-Datei */
    ifstream datei("zolldatenListe.txt");

    for(string zeile; getline(datei, zeile);) {

        /* mit Hilfe des strings passagierSitz soll jede Zeile bis zum Semikolon
         * durchsucht werden, um so die Angabe zur Nationalität finden und zuordnen zu können */

        string passagierSitz = zeile.substr(0,zeile.find(';'));

        /* Aufruf der Suche-Funktion, um Daten aus TXT rauszusuchen & zu speichern */
        Passagier *ergebnis = Suche(Sitzplatz,passagierSitz);

            if (ergebnis != NULL) {

                /* finde erstes Semikolon */
                int indexErsterBegriff = zeile.find(';') + 1;
                /* finde zweites Semikolon durch Suche ab der Position des ersten Semikolons + 1 */
                int indexZweiterBegriff = zeile.find(';', indexErsterBegriff) + 1;
                /* finde drittes Semikolon durch Suche ab der Position des zweiten Semikolons */
                int indexDritterBegriff = zeile.find(';', indexZweiterBegriff);

                /* Nationalität = substring ab erstes Semikolon */
                string tempNation = zeile.substr(indexErsterBegriff,indexZweiterBegriff-indexErsterBegriff - 1);
                ergebnis->Nationalitaet = tempNation;

                /* Buchungsnummer = substring ab zweites Semikolon */
                string tempBuchungsNr = zeile.substr(indexZweiterBegriff, indexDritterBegriff - indexZweiterBegriff);
                ergebnis->BuchungsNR = tempBuchungsNr;

                /* Bonusmeilen = substring ab drittes Semikolon */
                string tempBonusMeilen = zeile.substr(indexDritterBegriff + 1);
                ergebnis->BonusMeilen = tempBonusMeilen;

                }
            else {
                     cout << "Fehler" << endl;
                }
    }
}



/* Funktion, um Datenbasis kategoriespezifisch nach Passagierinformationen zu durchsuchen */
Passagier * Verzeichnis::Suche(Kategorie kategorie, string suchBegriff) {
    /* For-Schleife, um Verzeichnis durchgehen zu können */
    for(auto i = 0u; i < datenIndex.size(); i++) {
        Passagier uebergangsPassagier = datenIndex.at(i);

        /* Switch-Case, um die im Menü auswählbaren Kategorien mit der Suche zu verknüpfen,
         * das Vorhandensein des vom User eingegebenen Suchbegriffes in der Datenbasis
         * kategoriespezifisch zu überprüfen und gefundene Daten zurückzugeben */

        switch(kategorie) {

        case Sitzplatz:
            if (uebergangsPassagier.Sitzplatz.compare(suchBegriff) == 0) {
                return &datenIndex.at(i);
            }

            break;

        case Nachname:
            if (uebergangsPassagier.Nachname.compare(suchBegriff) == 0) {
                return &datenIndex.at(i);
            }
            break;

        case Vorname:
            if (uebergangsPassagier.Vorname.compare(suchBegriff) == 0) {
                return &datenIndex.at(i);
            }
            break;

        case GepaeckStueckzahl:
            if (uebergangsPassagier.GepaeckStueckzahl.compare(suchBegriff) == 0) {
                return &datenIndex.at(i);
            }
            break;

        case GepaeckGesamtgewicht:
            if (uebergangsPassagier.GepaeckGesamtgewicht.compare(suchBegriff) == 0) {
                return &datenIndex.at(i);
            }
            break;

        case Nationalitaet:
            if (uebergangsPassagier.Nationalitaet.compare(suchBegriff) == 0) {
                return &datenIndex.at(i);
            }
            break;

        case BuchungsNR:
            if (uebergangsPassagier.BuchungsNR.compare(suchBegriff) == 0) {
                return &datenIndex.at(i);
            }
            break;

        case BonusMeilen:
           if (uebergangsPassagier.BonusMeilen.compare(suchBegriff) == 0) {
               return &datenIndex.at(i);
           }
           break;

         }
    }
    return NULL;
}

/* Funktion, um neue XML-Datei unter gewünschtem Namen zu erstellen */
void Verzeichnis::neueXMLerstellen(string neuerDateiname) {
    /* Mit ofstream soll die Ausgabedatei (konvertierte XML) erzeugt werden */
    ofstream XMLdatei;
    XMLdatei.open(neuerDateiname);
    /* konvertiertes Verzeichnis soll mit gleichem Tag wie in ursprünglicher XML starten */
    XMLdatei << "<flugdaten> \n";

    for(auto i = 0u; i < datenIndex.size(); ++i) {
        vector<string> uebergangsPassagierStrings = datenIndex.at(i).neueXMLerstellen();
        for(auto j = 0u; j < uebergangsPassagierStrings.size(); ++j) {
            XMLdatei << uebergangsPassagierStrings.at(j) << "\n";
        }
    }

    /* neues Verzeichnis soll auch mit ursprünglich schließendem Tag enden */
    XMLdatei << "</flugdaten>";
    /* neue Datei wird geschlossen */
    XMLdatei.close();
}



/* Funktion zum Ausgeben der Ergebnisse der Suche();
 * For-Loop, der schrittweise die Inhalte des "datenIndex" an die ausgeben();-Funktion weitergibt */
void Verzeichnis::Ausgabe(){
    for(auto i = 0u;  i < datenIndex.size(); i++) {
          Passagier uebergangsPerson = datenIndex.at(i);
          uebergangsPerson.ausgeben();
        }
}


