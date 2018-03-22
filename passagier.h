#ifndef PASSAGIER_H
#define PASSAGIER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/* Die Klasse "Passagier" wird genutzt, um für die Suche alle hinterlegten Daten eines Passagiers kategoriespezifisch speichern
 * und dadurch später zusammenführen und ausgeben zu können. Außerdem werden die so geparsedten Daten für das Konvertieren und
 * Erstellen der neuen XML-Datei benötigt. */

class Passagier {

public:
    string Sitzplatz;
    string Nachname;
    string Vorname;
    string GepaeckStueckzahl;
    string GepaeckGesamtgewicht;
    string Nationalitaet;
    string BuchungsNR;
    string BonusMeilen;
    Passagier (string PassagierDatenXML[10]);
    vector<string> neueXMLerstellen();
    void ausgeben();

};

#endif // PASSAGIER_H

