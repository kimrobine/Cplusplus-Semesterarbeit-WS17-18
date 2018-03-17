#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "passagier.h"
#include "verzeichnis.h"

using namespace std;

int main()
{
    //Einbauen, dass Programm nach Ausführung einer Aktion für eine erneute Abfrage bereit steht

    // Objekt "passagierVerzeichnis" wird basierend auf Klasse "Verzeichnis" erzeugt
    Verzeichnis passagierVerzeichnis;

    // Die beiden Funktionen zum Auslesen der Ausgangsdateien werden zur Ausführung aufgerufen
    passagierVerzeichnis.auslesenXML();
    passagierVerzeichnis.auslesenTXT();


    // Eine Variable vom Typ string wird für die Nutzereingabe deklariert
    string input;

    // Ausgabe des Programms für Kommunikation mit Nutzer

    cout << endl;
    cout << "Um ein neues Verzeichnis zu erstellen, geben Sie 'konvertieren' ein." << endl;
    cout << "Um nach Informationen zu einzelnen Passagieren zu filtern, geben Sie 'suchen' ein." << endl;

    // Nutereingabe wird in input gespeichert
    cin >> input;

    // Wenn die Nutzereingabe mit dem Wort 'konvertieren' übereinstimmt,
    if(input.compare("konvertieren") == 0){

        cout << "Geben Sie einen Dateinamen inklusive Endung (.xml) für das neue Verzeichnis ein:" << endl;
        // kann der Nutzer einen beliebigen Namen für die neue Datei eingeben
        cin >> input;
        // und die Liste wird über die Funktion "neueXMLerstellen(); unter diesem neuen Namen im Build-Ordner erstellt.
        passagierVerzeichnis.neueXMLerstellen(input);
        cout << "Datei wurde konvertiert." << endl;
    }

    else if(input.compare("suchen") == 0){

        int suchWert;

        cout << "Nach welche Kategorie wollen Sie suchen? 0=Sitzplatz 1=Nachname 2=Vorname 5=Nationalität?" << endl;
        cin >> suchWert;

        if (suchWert <= 5) {
            cout << "Geben Sie einen Suchbegriff ein: " << endl;
            cin >> input;
            cout << endl;

            //Hier: Suche-Funktion aufrufen und vom User eingegebene Kategorie (suchWert) und Suchbegriff (input) übergeben

            //Außerdem hinzufügen: Ausgabe einer Meldung, wenn vom User eingegebener Suchbegriff nicht in Datenbasis gefunden wurde

        }

        if (suchWert > 5) {
            cout << "Nach dieser Kategorie kann nicht gesucht werden." << endl;
        }
    }

    else {
        cout << "Eingabe ungültig." << endl;
    }

    return 0;
}
