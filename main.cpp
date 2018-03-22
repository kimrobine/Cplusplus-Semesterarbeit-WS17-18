#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "passagier.h"
#include "verzeichnis.h"

using namespace std;

int main()
{
    /* Hauptfunktion des Programms */

    /* Mit Hilfe der Variable int start sowie der while-Schleife wird das Weiterlaufen des Programms
     * gewährleistet, solange der User es nutzen möchte (siehe unten, Ende der main) */
    int start;
    start = 1;

    cout << endl << "Herzlich Willkommen!" << endl;

    while (start == 1) {

    /* Objekt "passagierVerzeichnis" wird basierend auf Klasse "Verzeichnis" erzeugt */
    Verzeichnis passagierVerzeichnis;

    /* Die beiden Funktionen zum Auslesen der Ausgangsdateien werden zur Ausführung aufgerufen */
    passagierVerzeichnis.auslesenXML();
    passagierVerzeichnis.auslesenTXT();

    /* Eine Variable vom Typ string wird für die Nutzereingabe deklariert */
    string input;

    /* Ausgabe des Programms für Kommunikation mit Nutzer, nennt wählbare Operationen */
    cout << endl;
    cout << "+++++ Hauptmenü +++++" << endl;
    cout << "Um ein neues Verzeichnis zu erstellen, geben Sie 'konvertieren' ein." << endl;
    cout << "Um nach Informationen zu einzelnen Passagieren zu filtern, geben Sie 'suchen' ein." << endl;
    cout << "Wenn Sie Hinweise zu der Benutzung dieses Programms benötigen, geben Sie 'hilfe' ein." << endl;
    cout << endl;

    /* Die Nutereingabe wird in input gespeichert */
    cin >> input;

    /* Wenn die Nutzereingabe mit dem Wort 'konvertieren' übereinstimmt, */
    if(input.compare("konvertieren") == 0){

        /* kann der Nutzer einen beliebigen Namen für die neue Datei eingeben */
        cout << endl << "Geben Sie einen Dateinamen inklusive Endung (.xml) für das neue Verzeichnis ein:" << endl;
        cin >> input;

        string xml (".xml");

        /* Entspricht die Usereingabe dem genannten Format, enthält also die Dateiendung ".xml" */
        if (input.find(xml) != string::npos) {

            /* wird die neue XML-Datei über die Funktion "neueXMLerstellen();" unter diesem Namen im Build-Ordner erstellt */
            passagierVerzeichnis.neueXMLerstellen(input);

            cout << endl << "Datei wurde konvertiert." << endl;

         }

        /* Enthält die Usereingabe nicht die Dateiendung ".xml" */
        else {
            /* wird eine Fehlermeldung ausgegeben und die Datei nicht konvertiert */
             cout << endl << "Eingabe nicht korrekt. Bitte versuchen Sie es erneut." << endl;
        }

    }

    /* Wenn die Nutzereingabe mit dem Wort 'suchen' übereinstimmt, */
    else if(input.compare("suchen") == 0){

        int kategorie;

        /* kann der Nutzer ein Wert von 0-5 eingeben, stellvertretend für die Kategorie, nach der er suchen möchte */
        cout << endl << "Nach welche Kategorie möchten Sie suchen?" << endl;
        cout << "0=Sitzplatz 1=Nachname 2=Vorname 3=Gepäckgewicht 4=Nationalität 5=Buchungsnummer 6=Bonusmeilen?" << endl;

        cin >> kategorie;

        /* Wenn sich die Eingabe des Users unter den möglichen wählbaren Kategorien befindet */
        if (kategorie <= 6) {

            /* soll dann ein Suchbegriff eingegeben werden */
            cout << "Geben Sie einen Suchbegriff ein: " << endl;

            cin >> input;
            cout << endl;

            /* Aufruf der Such-Funktion mit Übergabe der vom Nutzer eingegebenen Kategorie und des Suchbegriffes */
            passagierVerzeichnis.Suche(static_cast<Verzeichnis::Kategorie>(kategorie),input);

            /* Die Funktion ausgeben(); soll nur dann ausgeführt werden, wenn ein Suchbegriff gefunden wurde,
             * also der von der Suche-Funktion zurückgegebene Wert nicht NULL ist.
             * Ansonsten gibt es eine Fehlermeldung */

            if (passagierVerzeichnis.Suche(static_cast<Verzeichnis::Kategorie>(kategorie),input) == NULL) {
                cout << "Zu Ihrem Suchbegriff wurde leider keine Übereinstimmung gefunden." << endl;
            } else {
                passagierVerzeichnis.Suche(static_cast<Verzeichnis::Kategorie>(kategorie),input)->ausgeben();
            }

        }

        /* Fehlermeldung, wenn sich die Eingabe des Users nicht unter den möglichen wählbaren Kategorien befindet */
        if (kategorie > 6) {
            cout << "Nach dieser Kategorie kann nicht gesucht werden." << endl;
        }
    }

    /* Wenn die Nutzereingabe mit dem Wort 'hilfe' übereinstimmt, werden Hinweise zur Programmnutzung ausgegeben */
    else if (input.compare("hilfe") == 0) {
        cout << endl;
        cout << "+++++ Hilfe +++++" << endl;
        cout << "Mit diesem Programm können Sie die gespeicherten Daten zu unseren Fluggästen verwalten." << endl;
        cout << "Ihre Eingaben bestätigen Sie bitte immer durch Drücken der ENTER-Taste." << endl << endl;
        cout << "+ Funktionen +" << endl;
        cout << "1. Durch Eingabe des Wortes 'konvertieren' wird ein neues XML-Verzeichnis erstellt, dass die zwei verschiedenen Datensätze zusammenfügt." << endl;
        cout << "Sie erhalten eine universale XML-Datei, in der alle hinterlegten Informationen pro Passagier gebündelt aufgelistet sind." << endl << endl;
        cout << "2. Durch Eingabe des Wortes 'suchen' können Sie in den zwei vorhandenen Datensätzen nach Informationen zu einzelnen Passagieren suchen." << endl;
        cout << "Dazu geben Sie zunächst die Kennzahl der Kategorie ein, nach der Sie suchen möchten (Die Kennzahlen werden Ihnen vor der Suche angezeigt)." << endl;
        cout << "Danach geben Sie den Suchbegriff ein, nach dem Sie suchen möchten." << endl ;
        cout << "Wenn das Programm eine Übereinstimmung in den Passagierdaten findet, erhalten Sie eine Auflistung." << endl;

    }

    /* Bei jeder anderen Nutzereingabe */
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
