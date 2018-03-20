#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "passagier.h"
#include "verzeichnis.h"

using namespace std;

int main()
{
    /* Mit Hilfe der Variable int start sowie der while-Schleife wird das Weiterlaufen des Programms
     * gewährleistet, solange der User es nutzen möchte (siehe unten, Ende der main) */
    int start;
    start = 1;

    cout << endl << "+++++ Herzlich Willkommen +++++";

    while (start == 1) {

    /* Objekt "passagierVerzeichnis" wird basierend auf Klasse "Verzeichnis" erzeugt */
    Verzeichnis passagierVerzeichnis;

    /* Die beiden Funktionen zum Auslesen der Ausgangsdateien werden zur Ausführung aufgerufen */
    passagierVerzeichnis.auslesenXML();
    passagierVerzeichnis.auslesenTXT();

    /* Eine Variable vom Typ string wird für die Nutzereingabe deklariert */
    string input;

    /* Ausgabe des Programms für Kommunikation mit Nutzer */
    cout << endl;
    cout << "Um ein neues Verzeichnis zu erstellen, geben Sie 'konvertieren' ein." << endl;
    cout << "Um nach Informationen zu einzelnen Passagieren zu filtern, geben Sie 'suchen' ein." << endl;

    /* Die Nutereingabe wird in input gespeichert */
    cin >> input;

    /* Wenn die Nutzereingabe mit dem Wort 'konvertieren' übereinstimmt, */
    if(input.compare("konvertieren") == 0){

        /* kann der Nutzer einen beliebigen Namen für die neue Datei eingeben */
        cout << "Geben Sie einen Dateinamen inklusive Endung (.xml) für das neue Verzeichnis ein:" << endl;
        cin >> input;

        /* und die Liste wird über die Funktion "neueXMLerstellen(); unter diesem neuen Namen im Build-Ordner erstellt */
        passagierVerzeichnis.neueXMLerstellen(input);

        cout << "Datei wurde konvertiert." << endl;
    }

    /* Wenn die Nutzereingabe mit dem Wort 'suchen' übereinstimmt, */
    else if(input.compare("suchen") == 0){

        int suchWert;

        /* kann der Nutzer ein Wert von 0-5 eingeben, stellvertretend für die Kategorie, nach der er suchen möchte */
        cout << "Nach welcher Kategorie wollen Sie suchen? 0=Sitzplatz 1=Nachname 2=Vorname 5=Nationalität?" << endl;

        cin >> suchWert;

        /* Wenn sich die Eingabe des Users unter den möglichen wählbaren Kategorien befindet */
        if (suchWert <= 5) {

            /* soll dann ein Suchbegriff eingegeben werden */
            cout << "Geben Sie einen Suchbegriff ein: " << endl;

            cin >> input;
            cout << endl;

            /* Aufruf der Such-Funktion mit Übergabe der vom Nutzer eingegebenen Kategorie und des Suchbegriffes */
            passagierVerzeichnis.Suche(static_cast<Verzeichnis::Kategorie>(suchWert),input);

            /* Die Funktion ausgeben(); soll nur dann ausgeführt werden, wenn ein Suchbegriff gefunden wurde,
             * also der von der Suche-Funktion zurückgegebene Wert nicht NULL ist.
             * Ansonsten gibt es eine Fehlermeldung */

            if (passagierVerzeichnis.Suche(static_cast<Verzeichnis::Kategorie>(suchWert),input) == NULL) {
                cout << "Zu Ihrem Suchbegriff wurde leider keine Übereinstimmung gefunden." << endl;
            } else {
                passagierVerzeichnis.Suche(static_cast<Verzeichnis::Kategorie>(suchWert),input)->ausgeben();
            }

        }

        /* Fehlermeldung, wenn sich die Eingabe des Users nicht unter den möglichen wählbaren Kategorien befindet */
        if (suchWert > 5) {
            cout << "Nach dieser Kategorie kann nicht gesucht werden." << endl;
        }
    }

    else {
        /* Fehlermeldung, wenn sich die Eingabe des Users nicht mit 'konvertieren oder 'suchen' übereinstimmt */
        cout << "Eingabe ungültig." << endl;
    }

    cout << endl;

    /* Gibt der User 1 ein, bleibt start = 1, das Programm läuft also weiter und steht für eine erneute Abfrage bereit */
    cout << "Wenn Sie fortfahren möchten, geben Sie eine 1 ein." << endl;

    /* Gibt der User 0 ein, wird start = 0 gesetzt und die while-Bedingung ist nicht mehr zutreffend, sodass das Programm endet */
    cout << "Zum Beenden des Programms geben Sie 0 ein." << endl;

    cin >> start;

    }
}
