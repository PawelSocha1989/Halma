#ifndef ZAPISANEWYNIKI_H
#define ZAPISANEWYNIKI_H

#include "kasa.h"

class ZapisaneWyniki
{
public:
	ZapisaneWyniki(void);
	~ZapisaneWyniki(void);
	void kursor_wyniki();
	void wyniki();
	void load_wyniki();
	void wczytaj();

	BITMAP* kursorek;
	BITMAP* bufor_wyniki;
	BITMAP* zapisane_wyniki;
};
#endif