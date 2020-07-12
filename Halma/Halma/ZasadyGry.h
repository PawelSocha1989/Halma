#ifndef ZASADYGRY_H
#define ZASADYGRY_H

#include "ZapisaneWyniki.h"

class ZasadyGry//stworzono klase ZasadyGry
{
public://w czêœci publicznej
	ZasadyGry(void);// zdefiniowano konstruktor
	~ZasadyGry(void); // zdefiniowano destruktor

	void load_zasady();
	void kursor_zasady();
	void zasady_gry();

	BITMAP* zasady;
	BITMAP* zasady1;
	BITMAP* bufor_zasady;
	BITMAP* kursor_zas;

};
#endif