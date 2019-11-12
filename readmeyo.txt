

###############Anleitung zum Programm je nach Teilaufgabe######################
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
#Aufgabe 2:
	-Wenn die Bilder unterschiedlich groß sind kommt es zu Fehlern
	-im Konsolenprogramm ist der Befehl zum beenden unschön aber funktioniert
	-bei zu kurzen eingaben in der Konsole kommt es zu Problemen, da das Programm 
	 noch weitere Argumente erwartet

#Aufgabe3: 
	-Es werden keine falschen Benutzereingaben, wie zum Beispiel falsche Größe, falscher Dateientyp etc. abgefangen



