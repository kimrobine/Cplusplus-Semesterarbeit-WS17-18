#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "passagier.h"

using namespace std;

int main()
{
    //Objekt für andere Klasse (für Verzeichnis)

    //Funktion zum Auslesen der XML
    //Funktion zum Auslesen der TXT

    // Nutzereingabe
    string input;

    // Ausgabe des Programms
    cout << "Um ein neues Verzeichnis zu erstellen, geben sie 'konvertieren' ein." << endl;

    //Nutzereingabe = input
    cin >> input;

    if(input.compare("konvertieren") == 0){

        cout << "Geben Sie einen Dateinamen inklusive Endung für das neue Verzeichnis ein:" << endl;

        cin >> input;

        //hier: Objekt.Funktion(Übergabe des User-inputs), um die neue Liste zu erstellen

        cout << "Datei wurde konvertiert." << endl;
    }

    else {
        cout << "Eingabe ungültig." << endl;

        //hier: später mal anderer Case für die Eingabe "suchen"
    }

    return 0;
}
