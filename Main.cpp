#include <iostream>// für std::cout
#include <memory> // für smart pointer
#include <vector>// für vector
#include <cmath>  // für std::fabs-------------------------
#include "fahrzeug.h"// für die Fahrzeug-Klasse
#include "PKW.h"   // für die PKW-Klasse
#include "fahrrad.h"// für die Fahrrad-Klasse
//aufgabe 1 halt
double g_dGlobaleZeit = 0.0;//globale zeit variable initialisieren (Notiz eher wie ein Timer) Aufgabe 4.2.7

void vAufgabe1()
{
//Tabellen Test ausgabe Aufgabe 4.2.8
        /*Fahrzeug fFahrzeug1("Static1", 120.0);
        Fahrzeug fFahrzeug2("Static2", 150.0);

	Fahrzeug::vKopf();
	std::cout << std::endl;

	// Simulation 5 mal
	for(int i = 0; i < 5; i++)//ich hab jetzt mal angenommen das geschwindigkeit in km/h ist und zeit in stunden
	{
	    g_dGlobaleZeit += 1.0;   // Zeit erhöhen
            fFahrzeug1.vSimulieren();
            fFahrzeug2.vSimulieren();
        }

        fFahrzeug1.vAusgeben();
        std::cout << std::endl;
        fFahrzeug2.vAusgeben();
        std::cout << std::endl;
//test vollständig ausgbae macht sinn*/

	std::cout << "Start vAufgabe1()\n";//gibt aus das die aufgabe 1 startet


   /* std::cout << "Statische Fahrzeuge\n";//gibt aus das jetzt statische fahrzeuge kommen

    Fahrzeug f1("Static1");//erstellt ein statisches fahrzeug mit name static1
    Fahrzeug f2("Static2");//erstellt ein statisches fahrzeug mit name static2*/

    std::cout << "\nDynamische Fahrzeuge\n";//gibt aus das jetzt dynamische fahrzeuge kommen

    Fahrzeug* pF3 = new Fahrzeug("Dynamic1");//erstellt ein dynamisches fahrzeug mit name dynamic1
    Fahrzeug* pF4 = new Fahrzeug("Dynamic2");//erstellt ein dynamisches fahrzeug mit name dynamic2

    delete pF3;//löscht das dynamische fahrzeug dynamic1
    delete pF4;//löscht das dynamische fahrzeug dynamic2



    std::cout << "\nSmartpointer: unique_ptr\n";//gibt aus das jetzt unique_ptr kommen

    auto pUniqueFahrzeug1 = std::make_unique<Fahrzeug>("Unique1");//	erstellt ein unique_ptr fahrzeug mit name unique1
    auto pUniqueFahrzeug2 = std::make_unique<Fahrzeug>("Unique2");//	erstellt ein unique_ptr fahrzeug mit name unique2

    std::cout << "\nvector<unique_ptr<Fahrzeug>>\n";//gibt aus das jetzt vector<unique_ptr<Fahrzeug>> kommen

    std::vector<std::unique_ptr<Fahrzeug>> vecpUnique;//erstellt einen vector der unique_ptr<Fahrzeug> speichert

    vecpUnique.push_back(std::move(pUniqueFahrzeug1));//fügt unique ptr u1 in den vector ein am ende(owner ship wird transferiert)
    vecpUnique.push_back(std::move(pUniqueFahrzeug2));//fügt unique ptr u2 in den vector ein am ende(owner ship wird transferiert)

    vecpUnique.clear();//löscht alle elemente im vector

    std::cout << "\nSmartpointer: shared_ptr\n";//gibt aus das jetzt shared_ptr kommen

    auto pSharedFahrzeug1 = std::make_shared<Fahrzeug>("Shared1");//erstellt ein shared_ptr fahrzeug mit name shared1
    auto pSharedFahrzeug2 = std::make_shared<Fahrzeug>("Shared2");//erstellt ein shared_ptr fahrzeug mit name shared2

    std::cout << "pSharedFahrzeug1 use_count vor Kopie: " << pSharedFahrzeug1.use_count() << "\n";//gibt die anzahl der shared_ptr die auf das gleiche objekt besitzen aus

    std::shared_ptr<Fahrzeug> pSharedFahrzeug3 = pSharedFahrzeug1;//kopiert den shared_ptr pSharedFahrzeug1 in pSharedFahrzeug3, (kopieren geht nur bei shared_ptr nicht bei unique_ptr)

    std::cout << "pSharedFahrzeug1 use_count nach Kopie: " << pSharedFahrzeug1.use_count() << "\n";//gibt die anzahl der shared_ptr die auf das gleiche objekt zeigen aus

    std::cout << "\nvector<shared_ptr<Fahrzeug>>\n";//gibt aus das jetzt vector<shared_ptr<Fahrzeug>> kommen

    std::vector<std::shared_ptr<Fahrzeug>> vecSharedFahrzeuge;//erstellt einen vector der shared_ptr<Fahrzeug> speichert

    vecSharedFahrzeuge.push_back(pSharedFahrzeug1);//fügt shared ptr pSharedFahrzeug1 in den vector ein am ende
    vecSharedFahrzeuge.push_back(std::move(pSharedFahrzeug2));//schiebt shared ptr pSharedFahrzeug2 in den vector ein am ende also transfer den besitz

    std::cout << "pSharedFahrzeug1 use_count im vector: " << pSharedFahrzeug1.use_count() << "\n";//gibt die anzahl der shared_ptr die auf das gleiche objekt zeigen aus

    vecSharedFahrzeuge.clear();//löscht alle elemente im vector

    std::cout << "\nEnde vAufgabe1()\n\n";//gibt aus das die aufgabe 1 zu ende istx
}
void vAufgabe1a()//aufgabe 4.2.9
{
    std::vector<std::unique_ptr<Fahrzeug>> vecFahrzeuge;//neuer vector der unique_ptr<Fahrzeug> speichert(nicht einzeknd löschen da smart pointer)

    std::cout << "Bitte geben Sie 3 Fahrzeuge ein (Name + MaxGeschwindigkeit):\n";//aufforderung an den benutzer 3 fahrzeuge einzugeben

    for (int i = 0; i < 3; i++)//schleife für 3 fahrzeuge
    {
        std::string sName;
        double dGeschwindigkeit;//wir benutzen neue varauible für name und geschwindigkeit weil noch gar keine Fahrzeuge existieren weil wir vor dem Konstruktor sind

        std::cout << "Fahrzeug " << i + 1 << " Name: ";
        std::cin >> sName;

        std::cout << "Fahrzeug " << i + 1 << " MaxGeschwindigkeit: ";
        std::cin >> dGeschwindigkeit;

        // Fahrzeug erzeugen (ende vom vektor)und mit name und geschwindigkeit
        vecFahrzeuge.push_back(std::make_unique<Fahrzeug>(sName, dGeschwindigkeit));
    }

    std::cout << "\n Simulation startet \n";

    Fahrzeug::vKopf();//Kopf von alter aufgabe ausgeben weil nochmal wäre unnötig
    std::cout << std::endl;

    // Simulation in 30 minuten schritten und das 10 mal also insgesamt 5 stunden
    for (int i = 0; i < 10; i++)
    {
        g_dGlobaleZeit += 0.5;   // Globale Uhr erhöhen (0.5h pro Schritt)
        //notiz an selbst nicht das g vergesseb
        // die for schleife geht durch alle fahrzeuge im vektor durch
        for (std::unique_ptr<Fahrzeug>& fzg : vecFahrzeuge)//man könnte auch auto benutzen aber finde ich es so persönlich klarer : Fzg ist ein referenz auf unique_ptr<Fahrzeug>
        {							//& weil wir ändern wollen nicht kopieren //kopieren geht nicht bei unique_ptr
            fzg->vSimulieren();  //Nimmt das fahrzeug und simuliert es
            fzg->vAusgeben();    //Gibt fahrzeug daten aus
            std::cout << std::endl;
        }

        std::cout << std::string(140, '-') << "\n";
    }

    std::cout << "\nSimulation beendet\n";
}

void vAufgabeTest()//aufgabe 4.3.4 test simulation für mich persönlich
{
    std::vector<std::unique_ptr<Fahrzeug>> vec;

    vec.push_back(std::make_unique<Fahrzeug>("Fahrzeug", 80.0)); // normales Fahrzeug
    vec.push_back(std::make_unique<PKW>("Auto", 140.0, 7.5, 60.0)); // PKW
    vec.push_back(std::make_unique<Fahrrad>("Fahrrad", 25.0)); // Fahrrad

    std::cout << "\nTESTSIMULATION START\n\n";

    Fahrzeug::vKopf();
    std::cout << std::endl;

    // --- 10 Schritte à 0.5 h ---
    for (int i = 0; i < 10; i++)
    {
        g_dGlobaleZeit += 0.5;

        for (auto &fz : vec)
        {
            fz->vSimulieren();
            fz->vAusgeben();
            std::cout << "\n";
        }

        std::cout << "---------------------------------------------------------------\n";
    }

    std::cout << "\nTESTSIMULATION ENDE\n";
}
void vAufgabe2() // aufgabe 4.3.4
{
        g_dGlobaleZeit = 0.0; // globale Zeit zurücksetzen
    std::vector<std::unique_ptr<Fahrzeug>> vecpFahrzeuge; // vector der unique_ptr<Fahrzeug> speichert

    int iAnzahlPKW = 0;//anzahl der pkw die erzeugt werden sollen
    int iAnzahlFahrrad = 0;//anzahl der fahrräder die erzeugt werden sollen

    std::cout << "Wie viele PKWs sollen erzeugt werden? ";
    std::cin >> iAnzahlPKW;

    std::cout << "Wie viele Fahrraeder sollen erzeugt werden? ";
    std::cin >> iAnzahlFahrrad;

    // ---- PKW Erzeugung ----
    for (int i = 0; i < iAnzahlPKW; i++)//alle user eingaben für pkw abfragen
    {
        std::string sName;
        double dVMax;
        double dVerbrauch;
        double dTank = 55.0; // Default

        std::cout << "\nPKW " << i+1 << " Name: ";
        std::cin >> sName;

        std::cout << "MaxGeschwindigkeit: ";
        std::cin >> dVMax;

        std::cout << "Verbrauch (L/100km): ";
        std::cin >> dVerbrauch;

        std::cout << "Tankvolumen (Default 55): ";
        std::cin >> dTank;

        vecpFahrzeuge.push_back(std::make_unique<PKW>(sName, dVMax, dVerbrauch, dTank));
    }

    // ---- Fahrrad Erzeugung ----
    for (int i = 0; i < iAnzahlFahrrad; i++)//alle user eingaben für fahrräder abfragen
    {
        std::string sName;
        double dVMax;

        std::cout << "\nFahrrad " << i+1 << " Name: ";
        std::cin >> sName;

        std::cout << "MaxGeschwindigkeit: ";
        std::cin >> dVMax;

        vecpFahrzeuge.push_back(std::make_unique<Fahrrad>(sName, dVMax));
    }

    // ---- Simulation ----
    std::cout << "\nSimulation startet...\n\n";

    double dZeitschritt = 0.5; // 30 Minuten pro Schritt
    double dToleranz = 0.000001;   // für Double-Vergleich weil Gleitkomma

    Fahrzeug::vKopf();
    std::cout << "\n";

    while (g_dGlobaleZeit < 6.0) // z.B. bis 6 Stunden laufen lassen
    {
        g_dGlobaleZeit += dZeitschritt;

        // ------------- PKW tanken nach GENAU 3 Stunden ---------------
        if (std::fabs(g_dGlobaleZeit - 3.0) < dToleranz)
        {
            std::cout << "\n=== ALLE PKWs WERDEN NACH 3h VOLLGETANKT ===\n";

            for (auto &fz : vecpFahrzeuge)//alle fahrzeuge im vektor durchgehen
            {
                PKW* pPKW = dynamic_cast<PKW*>(fz.get());//versucht das fahrzeug in einen pkw zu casten
                if (pPKW != nullptr)//wenn der cast erfolgreich war also pkw ist
                {
                    pPKW->dTanken(); // default = voll
                }
            }
            std::cout << std::string(140, '=') << "\n\n";
        }

        for (auto &fz : vecpFahrzeuge)//alle fahrzeuge im vektor durchgehen
        {
            fz->vSimulieren();//fahrzeug simulieren
            fz->vAusgeben();//fahrzeug daten ausgeben
            std::cout << "\n";
        }

        std::cout << std::string(140, '-') << "\n";
    }

    std::cout << "\nSimulation beendet.\n";
}
void vAufgabe3() // Aufgabe 4.4 testen
{
    std::cout << "\nStarte vAufgabe3 (Operator-Tests)\n";
    g_dGlobaleZeit = 0.0;

    // zwei Fahrzeuge, damit wir Vergleiche und Ausgabe testen können
    auto pPKWTest = std::make_unique<PKW>("OperatorAuto", 120.0, 7.0, 50.0);
    auto pBikeTest = std::make_unique<Fahrrad>("OperatorRad", 25.0);
    Fahrzeug fCopyZiel("CopyZiel", 80.0); // wird per Zuweisungsoperator gefüttert

    // kleine Simulation, damit Strecken ungleich werden
    g_dGlobaleZeit += 1.0; // eine Stunde fahren lassen
    pPKWTest->vSimulieren();
    pBikeTest->vSimulieren();

    g_dGlobaleZeit += 0.5; // noch eine halbe Stunde oben drauf
    pPKWTest->vSimulieren();
    pBikeTest->vSimulieren();

    // Ausgabe ausschließlich mit dem neuen Operator<<
    Fahrzeug::vKopf();
    std::cout << std::endl;
    std::cout << *pPKWTest << std::endl;
    std::cout << *pBikeTest << std::endl;

    // Vergleichsoperator testen
    if (*pBikeTest < *pPKWTest)
    {
        std::cout << "Das Fahrrad hat weniger Strecke als der PKW (so soll es sein).\n";
    }
    else
    {
        std::cout << "Unerwartet: Fahrrad ist weiter gefahren als der PKW.\n";
    }

    // Zuweisungsoperator ausprobieren (nur Stammdaten)
    fCopyZiel = *pBikeTest; // kopiert Name + MaxGeschwindigkeit, behält eigene ID und Historie
    std::cout << "\nAusgabe vom zugewiesenen Fahrzeug (Basisobjekt behält eigene ID):\n";
    Fahrzeug::vKopf();
    std::cout << std::endl;
    std::cout << fCopyZiel << std::endl;
}


int main()
{
	//vAufgabe3();
	//vAufgabe2();
    //vAufgabe1();
    vAufgabe1a();
	//vAufgabeTest();
    return 0;
}
