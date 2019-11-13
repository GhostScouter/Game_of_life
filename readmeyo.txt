###############Anleitung zum Programm je nach Teilaufgabe######################

Aufgabe 1)
Aktuell ist keine Funktion auskommentiert und alles wird durch Benutzereingaben geregelt.
Die Eingabeaufforderungen werden im Konsolenprogramm grundsätzlich hinreichend erklärt.
Es handelt sich um Zahlen die eingeklammert hinter der jeweiligen Eingabe stehen.

Es wird zu Anfang unterschieden, ob die ersten Teilaufgaben (1a,1b) oder (1c,1d,1e) präsentiert werden sollen.

Zu 1ab)
Mit den Eingaben 1,2,3,4,5 kann leicht navigiert werden.
Die Reihenfolge der Eingabe ist vollkommen beliebig und jede Kombination erzielt Ergebnisse.

Erklärungsbedürftige sind die folgenden:

Wenn man 4 vor 3 eingibt:
Der dynamische Array wird mit seinen Standardwerten ausgegeben.
Fast alle sind hier 0.

Wenn man 2 vor 1 eingibt:
Der statische Array wird mit seinen Standardwerten ausgegeben.
Diese sind scheinbar zufällig, aber immer die Selben.

Bei 1:
Wir nutzen einen "guten" Zufallsgenerator, zu finden in der static_array.cpp line 9 und 15.


Zu 1cde)
1.	Zuerst wird erfragt, ob ein Automat eingelesen werden soll.
	Dieser muss im Format der Beispieldatei aus der Aufgabenstellung entsprechen.
	Die txt, die importiert werden soll, muss im Build Ordner abgelegt werden.
	Falls dies getan wird, wird zu Schritt 4 übersprungen!

2.	Als nächstes kann die Feldgröße verändert werden, die Standardmäßig 30x30 ist.
	Hierbei wird zuerst die neue Höhe und dann die neue Breite erwartet.

3.	Nun werden vom Benutzer Eingaben erwartet, um das Feld manuell zu füllen.
	Hierbei ist es möglich, mit Absätzen versehene Eingaben einzugeben, um sich viel Tipparbeit zu sparen!

Beispiel für einen 3x3 Feld:
1
0
0
1
1
1
0
0
0

4.	Nun gibt es die Möglichkeit nachträglich einzelne Felder zu ändern. Um das erste Feld zu ändern muss 0 0 eingegeben werden, für das Letzte also (höhe-1) (breite-1).
	Der Wert des Feldes wird mit (+1%2) versehen.
	Sobald man kein weiteres Feld mehr ändern möchte wird das veränderte Feld einmal ausgegeben. Und direkt die Evolution darauf angewandt.
	Nach jeder Evolution wird man gefragt, ob man wieder Felder ändern will.

5.	Des Weiteren gibt es die Möglichkleit das aktuelle Feld in eine txt zu exportieren. Diese findet man dann in dem Build Ordner wieder.
	Daraufhin kann man weiter "evoluionieren".
	Um die Aufgabenstellung 1cde zu verlassen muss die "noch einmal?" Frage mit 0 beantwortet werden.



Aufgabe 2)
!!!
Das Konsolenprogramm für aufgabe 2 befindet sich auskommentiert in der Mainfunktion.
Einfach den Part für die GUI auskommentieren und das Konsolenprogramm entkommentieren.
Damit dies funktioniert, ist die Konsole aktiviert, startet also auch wenn die GUI startet.
!!!

2c auskommentiert in der Main-function.
2d und 2e in 2g
2f ist dadurch realisiert,dass die overlayfunction ein Objekt der Klasse 
Bild zurückgibt und man somit Zugriff auf die exp-Methode der Klasse hat und 
so das Bild speichern kann.

2g): mögliche eingaben:

visualcrypt encode <ort bild> <ort key> <speicherort>
visualcrypt decode <ort bild verschlüsselt> <ort key> <speicherort>
visualcrypt overlay <ort bild1> <ort bild2> <speicherort>

Mit den Beispieldatein aus dem Ordner der c++ Datein:

visualcrypt encode data.txt key.txt bildencoded.txt 
visualcrypt decode bildencoded.txt key.txt bilddecoded.txt
visualcrypt overlay bildencoded.txt keyAB.txt bildoverlay.txt 


#Zu beachten ist, dass bei encode und overlay die Bilder
 gleich groß sein müssen.
#bei decode wird über den originalen(nicht in AB-darstellung) 
 Schlüssel decodiert. Das erste Bild muss also doppelt so groß
 sein, wie der Schlüssel)



#######################Wer hat was gemacht#####################################
Kai Stock:
Erstellung der 1a und 1b
Zusammenarbeit bei der gesamten 1c mit Samuel Hahne
Menüführung der Aufgabe 1 und Aufräumen des Codes

Samuel Hahne:
Zusammenarbeit bei der gesamten 1c mit Kai Stock
Erstellung der Import und Export Funktion (1d, 1e)
Kommentierung des Codes der 1 & die Readme für Aufgabe 1
~30 Stunden inklusive allem

Max Krawietz:
Aufgabe 2:
Klasse NBild/Bild mit Methoden, 
Konsolenprogramm
Funktionen
alles eig yo
Aufgabe3:
alles für cryptographie
~25 Stunden inkl. C++-tutorials
Tolun Cihan Cakal: createPic

#######################Bekannte Probleme#######################################
#Aufgabe 1:
	-keine

#Aufgabe 2:
	-Wenn die Bilder unterschiedlich groß sind kommt es zu Fehlern
	-im Konsolenprogramm ist der Befehl zum beenden unschön aber funktioniert
	-bei zu kurzen eingaben in der Konsole kommt es zu Problemen, da das Programm 
	 noch weitere Argumente erwartet

#Aufgabe3: 
	-Es werden keine falschen Benutzereingaben, wie zum Beispiel falsche Größe, falscher Dateientyp etc. abgefangen



