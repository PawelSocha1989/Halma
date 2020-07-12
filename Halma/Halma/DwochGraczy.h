#ifndef DWOCHGRACZY_H
#define DWOCHGRACZY_H

#include "menu.h"

class DwochGraczy
{
public:
	DwochGraczy(void);
	~DwochGraczy(void);
	void tlo();
	void tlo2();
	void szachownica_gra();
	void gra();
	void load_gra();
	void kursor_gra();
	void rozstawienie_gracz1();
	void rozstawienie_gracz2();
	void sprawdzanie_pol();
	void koniec_gry();
	void pol();
	void pola1(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, 
			   int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, 
			   int p18, int p19, int p20, int p21, int p22, int p23, int p24, int p25, 
			   int p26, int p27, int p28, int p29, int p30, int p31, int p32, int p33, 
			   int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41, int p42);

	void pola2(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, 
			   int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, 
			   int p18, int p19, int p20, int p21, int p22, int p23, int p24, int p25, 
			   int p26, int p27, int p28, int p29, int p30, int p31, int p32, int p33, 
			   int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41, 
			   int p42, int p43, int p44, int p45, int p46, int p47, int p48, int p49,
			   int p50, int p51, int p52, int p53, int p54);

	void pola3(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, 
			   int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, 
			   int p18, int p19, int p20, int p21, int p22, int p23, int p24, int p25, 
			   int p26, int p27, int p28, int p29, int p30, int p31, int p32, int p33, 
			   int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41, 
			   int p42, int p43, int p44, int p45, int p46, int p47, int p48, int p49,
			   int p50, int p51, int p52, int p53, int p54, int p55, int p56, int p57,
			   int p58, int p59, int p60, int p61, int p62, int p63, int p64, int p65, int p66);

	void pola4(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, 
			   int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, 
			   int p18, int p19, int p20, int p21, int p22, int p23, int p24, int p25, 
			   int p26, int p27, int p28, int p29, int p30, int p31, int p32, int p33, 
			   int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41, 
			   int p42, int p43, int p44, int p45, int p46, int p47, int p48, int p49,
			   int p50, int p51, int p52, int p53, int p54, int p55, int p56, int p57,
			   int p58, int p59, int p60, int p61, int p62, int p63, int p64, int p65, 
			   int p66, int p67, int p68, int p69, int p70, int p71, int p72);
	
	void pola5(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, 
			   int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, 
			   int p18, int p19, int p20, int p21, int p22, int p23, int p24, int p25, 
			   int p26, int p27, int p28, int p29, int p30, int p31, int p32, int p33, 
			   int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41, 
			   int p42, int p43, int p44, int p45, int p46, int p47, int p48, int p49,
			   int p50, int p51, int p52, int p53, int p54, int p55, int p56, int p57,
			   int p58, int p59, int p60, int p61, int p62, int p63, int p64, int p65, 
			   int p66, int p67, int p68, int p69, int p70, int p71, int p72, int p73,
			   int p74, int p75, int p76, int p77, int p78, int p79, int p80, int p81,
			   int p82, int p83, int p84);

	void pola6(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, 
			   int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, 
			   int p18, int p19, int p20, int p21, int p22, int p23, int p24, int p25, 
			   int p26, int p27, int p28, int p29, int p30, int p31, int p32, int p33, 
			   int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41, 
			   int p42, int p43, int p44, int p45, int p46, int p47, int p48, int p49,
			   int p50, int p51, int p52, int p53, int p54, int p55, int p56, int p57,
			   int p58, int p59, int p60, int p61, int p62, int p63, int p64, int p65, 
			   int p66, int p67, int p68, int p69, int p70, int p71, int p72, int p73,
			   int p74, int p75, int p76, int p77, int p78, int p79, int p80, int p81,
			   int p82, int p83, int p84, int p85, int p86, int p87, int p88, int p89, 
			   int p90, int p91, int p92, int p93, int p94, int p95, int p96, int p97,
			   int p98, int p99, int p100, int p101, int p102);

	void gra_open();
	void ruch_gracza_niebieskiego();
	void ruch_gracza_pomaranczowego();
	void zajetosc_pol();
	void zajetosc_pol_poczatek();
	void zapis();
	void zapisywanie();
	void menu_game();
	void kolejny();

	BITMAP* bufor_gra;
	BITMAP* bufor_gra2;
	BITMAP* bufor_gra3;
	BITMAP* kursor_gra1;
	BITMAP* twoj_ruch;
	BITMAP* kwadracik;
	BITMAP* w_niebieski;
	BITMAP* w_pomaranczowy;
	BITMAP* menu_gra;
	BITMAP* menu_gra2;
	BITMAP* kolejny_gracz;
	BITMAP* kolejny_gracz2;
	BITMAP* zap;

	int next_game;
	int twoj_ruch1;
	int pola[99];
	char osoba[200];
	int numer_polaxx;
	int numer_polaxxx;
	int numer_polayy;
	int numer_polayyy;
	int numer_pola;
	int numer_pola2;
	int zajete_przez_gracz;
	int pozycja_x;
	int pozycja_y;
	int wykonales_skok;
	int zajete_pole[99];
	int pojawilo_sie[100];
	int kolejka;
	int kolejka2;
	int kolejka1;
	int w_pom;
	int w_nieb;

private:
	struct tablica_polex {
            int polex[121];
			int numer_polaxx;
            tablica_polex() 
            {
              	for(numer_polaxx=1;numer_polaxx<=111;numer_polaxx=numer_polaxx+11)
					polex[numer_polaxx]=80;
	
				for(numer_polaxx=2;numer_polaxx<=112;numer_polaxx=numer_polaxx+11)
					polex[numer_polaxx]=128;

				for(numer_polaxx=3;numer_polaxx<=113;numer_polaxx=numer_polaxx+11)
					polex[numer_polaxx]=176;

				for(numer_polaxx=4;numer_polaxx<=114;numer_polaxx=numer_polaxx+11)
					polex[numer_polaxx]=224;

				for(numer_polaxx=5;numer_polaxx<=115;numer_polaxx=numer_polaxx+11)
					polex[numer_polaxx]=272;
	
				for(numer_polaxx=6;numer_polaxx<=116;numer_polaxx=numer_polaxx+11)
					polex[numer_polaxx]=320;
	
				for(numer_polaxx=7;numer_polaxx<=117;numer_polaxx=numer_polaxx+11)
					polex[numer_polaxx]=368;

				for(numer_polaxx=8;numer_polaxx<=118;numer_polaxx=numer_polaxx+11)
					polex[numer_polaxx]=416;

				for(numer_polaxx=9;numer_polaxx<=119;numer_polaxx=numer_polaxx+11)
					polex[numer_polaxx]=464;

				for(numer_polaxx=10;numer_polaxx<=120;numer_polaxx=numer_polaxx+11)
					polex[numer_polaxx]=512;

				for(numer_polaxx=11;numer_polaxx<=121;numer_polaxx=numer_polaxx+11)
					polex[numer_polaxx]=560;
            }
            const int & operator[](int x) const { return polex[x]; }
        };

		   
		struct tablica_poley {
            int poley[121];
			int numer_polayy;
            tablica_poley() 
            {
				for(numer_polayy=1;numer_polayy<=11;numer_polayy++)
					poley[numer_polayy]=0;

				for(numer_polayy=12;numer_polayy<=22;numer_polayy++)
					poley[numer_polayy]=48;

				for(numer_polayy=23;numer_polayy<=33;numer_polayy++)
					poley[numer_polayy]=96;

				for(numer_polayy=34;numer_polayy<=44;numer_polayy++)
					poley[numer_polayy]=144;

				for(numer_polayy=45;numer_polayy<=55;numer_polayy++)
					poley[numer_polayy]=192;

				for(numer_polayy=56;numer_polayy<=66;numer_polayy++)
					poley[numer_polayy]=240;

				for(numer_polayy=67;numer_polayy<=77;numer_polayy++)
					poley[numer_polayy]=288;

				for(numer_polayy=78;numer_polayy<=88;numer_polayy++)
					poley[numer_polayy]=336;

				for(numer_polayy=89;numer_polayy<=99;numer_polayy++)
					poley[numer_polayy]=384;

				for(numer_polayy=100;numer_polayy<=110;numer_polayy++)
					poley[numer_polayy]=432;

				for(numer_polayy=111;numer_polayy<=121;numer_polayy++)
					poley[numer_polayy]=480;
            }
            const int & operator[](int y) const { return poley[y]; }
        };

		struct tablica_pozycja_pionka {
            int pozycja_pionka[199];
			int numer_polaxxx;
			int numer_polayyy;
			tablica_pozycja_pionka() 
            {
				for(numer_polaxxx=0;numer_polaxxx<=90;numer_polaxxx=numer_polaxxx+10)
					pozycja_pionka[numer_polaxxx]=104;

				for(numer_polaxxx=1;numer_polaxxx<=91;numer_polaxxx=numer_polaxxx+10)
					pozycja_pionka[numer_polaxxx]=152;

				for(numer_polaxxx=2;numer_polaxxx<=92;numer_polaxxx=numer_polaxxx+10)
					pozycja_pionka[numer_polaxxx]=200;
	
				for(numer_polaxxx=3;numer_polaxxx<=93;numer_polaxxx=numer_polaxxx+10)
					pozycja_pionka[numer_polaxxx]=248;

				for(numer_polaxxx=4;numer_polaxxx<=94;numer_polaxxx=numer_polaxxx+10)
					pozycja_pionka[numer_polaxxx]=296;

				for(numer_polaxxx=5;numer_polaxxx<=95;numer_polaxxx=numer_polaxxx+10)
					pozycja_pionka[numer_polaxxx]=344;

				for(numer_polaxxx=6;numer_polaxxx<=96;numer_polaxxx=numer_polaxxx+10)
					pozycja_pionka[numer_polaxxx]=392;

				for(numer_polaxxx=7;numer_polaxxx<=97;numer_polaxxx=numer_polaxxx+10)
					pozycja_pionka[numer_polaxxx]=440;

				for(numer_polaxxx=8;numer_polaxxx<=98;numer_polaxxx=numer_polaxxx+10)
					pozycja_pionka[numer_polaxxx]=488;

				for(numer_polaxxx=9;numer_polaxxx<=99;numer_polaxxx=numer_polaxxx+10)
					pozycja_pionka[numer_polaxxx]=536;

				for(numer_polayyy=100;numer_polayyy<=109;numer_polayyy++)
					pozycja_pionka[numer_polayyy]=24;

				for(numer_polayyy=110;numer_polayyy<=119;numer_polayyy++)
					pozycja_pionka[numer_polayyy]=72;

				for(numer_polayyy=120;numer_polayyy<=129;numer_polayyy++)
					pozycja_pionka[numer_polayyy]=120;

				for(numer_polayyy=130;numer_polayyy<=139;numer_polayyy++)
					pozycja_pionka[numer_polayyy]=168;

				for(numer_polayyy=140;numer_polayyy<=149;numer_polayyy++)
					pozycja_pionka[numer_polayyy]=216;

				for(numer_polayyy=150;numer_polayyy<=159;numer_polayyy++)
					pozycja_pionka[numer_polayyy]=264;

				for(numer_polayyy=160;numer_polayyy<=169;numer_polayyy++)
					pozycja_pionka[numer_polayyy]=312;

				for(numer_polayyy=170;numer_polayyy<=179;numer_polayyy++)
					pozycja_pionka[numer_polayyy]=360;

				for(numer_polayyy=180;numer_polayyy<=189;numer_polayyy++)
					pozycja_pionka[numer_polayyy]=408;

				for(numer_polayyy=190;numer_polayyy<=199;numer_polayyy++)
					pozycja_pionka[numer_polayyy]=456;
            }
            const int & operator[](int z) const { return pozycja_pionka[z]; }
        };
 
    public:
        const tablica_polex polex;
		const tablica_poley poley;
		const tablica_pozycja_pionka pozycja_pionka;
};
#endif