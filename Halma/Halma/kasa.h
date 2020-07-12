#ifndef KASA_H
#define KASA_H

#include "DwochGraczy.h"

class kasa
{
public:
	kasa(void);
	~kasa(void);
	void kursor_money1();
	void load_kasa();
	void losowanie_kto_zaczyna();
	void wybierz_monete();
	void glowna_kasa();
	void tlo_kasa();

	BITMAP* bufor_kasa;
	BITMAP* bufor_kasa2;
	BITMAP* kursor_money;
	BITMAP* orzel;
	BITMAP* orzel2;
	BITMAP* reszka;
	BITMAP* reszka2;
	BITMAP* zaczynasz;
	BITMAP* zaczynasz2;
	BITMAP* zaczynasz11;
	BITMAP* zaczynasz22;

	int wybrales;
	int moneta;
	int moneta_x;
	int moneta_y;
};
#endif