#ifndef PASSAGIER_H
#define PASSAGIER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Passagier {

public:
    string Sitzplatz;
    string Nachname;
    string Vorname;
    string GepaeckStueckzahl;
    string GepaeckGesamtgewicht;
    string Nationalitaet;
    Passagier (string PassagierDatenXML[10]);
    vector<string> neueXMLerstellen();

};

#endif // PASSAGIER_H

