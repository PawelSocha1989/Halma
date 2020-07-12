#ifndef MENU_H
#define MENU_H

#define USE_CONSOLE //definiuje konsole

#include<fstream>
#include<string>
#include <allegro.h> //zaimplementowano potrzebn¹ bibliotekê graficzn¹

using namespace std;

class menu //stworzono klase menu
{
public:  //w czêœci publicznej
	menu(void); // zdefiniowano konstruktor
	~menu(void);  // zdefiniowano destruktor

	void menu_tlo();
	void szachownica();
	void menu_glowne();
	void menu_load();
	void menu_myszka();
	void menu_klawiatura();
	void menu_kursor();

	int frame;
	int gracz;

	BITMAP* menu1;
	BITMAP* bufor;
	BITMAP* bufor2;
	BITMAP* menu12;
	BITMAP* menu13;
	BITMAP* menu14;
	BITMAP* menu15;
	BITMAP* halma;
	BITMAP* kursor;
};
#endif