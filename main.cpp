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

    // Nutzereingabe
    string input;

    // Ausgabe des Programms
    cout << "Um ein neues Verzeichnis zu erstellen, geben sie 'konvertieren' ein." << endl;

    //Nutzereingabe = input
    cin >> input;

    // Wenn die Nutzereingabe mit dem Wort 'konvertieren' übereinstimmt,
    if(input.compare("konvertieren") == 0){

        cout << "Ausgabedateiname?" << endl;
        // kann der Nutzer einen beliebigen Namen für die neue Datei eingeben
        cin >> input;
        // und die Liste wird über die Funktion "neueXMLerstellen(); unter diesem neuen Namen im Build-Ordner erstellt.
        passagierVerzeichnis.neueXMLerstellen(input);
        cout << "Datei wurde konvertiert." << endl;
    }

    else {
        cout << "Eingabe ungültig." << endl;

        //hier: später mal anderer Case für die Eingabe "suchen"
    }

    return 0;
}
