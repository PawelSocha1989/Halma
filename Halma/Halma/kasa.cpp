#include "kasa.h"

kasa::kasa(void)
{
	bufor_kasa = NULL;
	bufor_kasa2 = NULL;
	kursor_money = NULL;
	zaczynasz = NULL;
	zaczynasz2 = NULL;
	zaczynasz11 = NULL;
	zaczynasz22 = NULL;
	orzel = NULL;
	orzel2 = NULL;
	reszka = NULL;
	reszka2 = NULL;

	moneta=0;
	wybrales=0;
	moneta_x=200;
	moneta_y=100;
}

kasa::~kasa(void)
{
	destroy_bitmap(kursor_money);
	destroy_bitmap(bufor_kasa);
	destroy_bitmap(bufor_kasa2);
	destroy_bitmap(orzel);
	destroy_bitmap(reszka);
	destroy_bitmap(orzel2);
	destroy_bitmap(reszka2);
	destroy_bitmap(zaczynasz);
	destroy_bitmap(zaczynasz2);
	destroy_bitmap(zaczynasz11);
	destroy_bitmap(zaczynasz22);
}

void kasa::kursor_money1()
{
	kursor_money = load_bmp("grafika/kursor.bmp", NULL);
	set_mouse_sprite(kursor_money);
	unscare_mouse();
}

void kasa::load_kasa()
{
	bufor_kasa = create_bitmap(640,480);
	bufor_kasa2 = create_bitmap(640,480);
	orzel = load_bmp( "grafika/orzel.bmp", default_palette );
	reszka = load_bmp( "grafika/reszka.bmp", default_palette );
	orzel2 = load_bmp( "grafika/orzel2.bmp", default_palette );
	reszka2 = load_bmp( "grafika/reszka2.bmp", default_palette );
	zaczynasz = load_bmp( "grafika/zaczynasz.bmp", default_palette );
	zaczynasz2 = load_bmp( "grafika/zaczynasz2.bmp", default_palette );
	zaczynasz11 = load_bmp( "grafika/zaczynasz11.bmp", default_palette );
	zaczynasz22 = load_bmp( "grafika/zaczynasz22.bmp", default_palette );
}

void kasa::wybierz_monete()
{
		wybrales=0;
		if((mouse_x>=120)&&(mouse_x<=300)&&(mouse_y>=100)&&(mouse_y<=280))
		{
			masked_blit( reszka2, bufor_kasa, 0,0, 100,100, reszka2->w, reszka2->h);
			wybrales=1;
			if(mouse_b==1)
			{
				rest(100);
				losowanie_kto_zaczyna();
			}
		}
		if((mouse_x>=370)&&(mouse_x<=550)&&(mouse_y>=100)&&(mouse_y<=280))
		{
			masked_blit( orzel2, bufor_kasa, 0,0, 350,100, orzel2->w, orzel2->h);
			wybrales=2;
			if(mouse_b==1)
			{
				rest(100);
				losowanie_kto_zaczyna();
			}	
		}
}

void kasa::tlo_kasa()
{
		masked_blit( reszka, bufor_kasa2, 0,0, 100,100, reszka->w, reszka->h);
		masked_blit( orzel, bufor_kasa2, 0,0, 350,100, orzel->w, orzel->h);
}

void kasa::glowna_kasa()
{
	kursor_money1();
	load_kasa();
	clear_to_color(bufor_kasa2, makecol(255,255,255));
	while(!key[KEY_Q])
	{
		clear_to_color(bufor_kasa, makecol(255,255,255));
		tlo_kasa();
		masked_blit( bufor_kasa2, bufor_kasa, 0,0,0,0, 640,480);
		wybierz_monete();
		draw_sprite(bufor_kasa,kursor_money,mouse_x,mouse_y);
		blit(bufor_kasa, screen, 0,0,0,0, 640, 480);
	}
}

void kasa::losowanie_kto_zaczyna()
{
	int min=1;
	int max=2;
	srand(time(NULL));
	moneta=rand()%(max-min+1)+min;
	clear_to_color(screen, makecol(255,255,255));
	clear_to_color(bufor_kasa, makecol(255,255,255));
	clear_to_color(bufor_kasa2, makecol(255,255,255));
	while(!key[KEY_W])
	{
		if ((moneta==1)&&(wybrales==1))
		{ 
			masked_blit( bufor_kasa2, bufor_kasa, 0,0,0,0, 640,480);
			masked_blit( orzel, bufor_kasa2, 0,0, moneta_x,moneta_y, orzel->w, orzel->h);
			masked_blit(zaczynasz2, bufor_kasa2, 0,0, 120,300,zaczynasz2->w, zaczynasz2->h);
			masked_blit(zaczynasz22, bufor_kasa2, 0,0, 140,400,zaczynasz22->w, zaczynasz22->h);
			if(mouse_b==1)
			{
				DwochGraczy giera;
				giera.gra();
			}
		}

		if ((moneta==1)&&(wybrales==2))
		{ 
			masked_blit( bufor_kasa2, bufor_kasa, 0,0,0,0, 640,480);
			masked_blit( orzel, bufor_kasa2, 0,0, moneta_x,moneta_y, orzel->w, orzel->h);
			masked_blit(zaczynasz, bufor_kasa2, 0,0, 220,300,zaczynasz->w, zaczynasz->h);
			masked_blit(zaczynasz11, bufor_kasa2, 0,0, 140,400,zaczynasz11->w, zaczynasz11->h);
			if(mouse_b==1)
			{
				DwochGraczy giera;
				giera.gra();
			}
		}

		if ((moneta==2)&&(wybrales==2))
		{
			masked_blit( bufor_kasa2, bufor_kasa, 0,0,0,0, 640,480);
			masked_blit( reszka, bufor_kasa2, 0,0, moneta_x,moneta_y, reszka->w, reszka->h);
			masked_blit(zaczynasz2, bufor_kasa2, 0,0, 120,300,zaczynasz2->w, zaczynasz2->h);
			masked_blit(zaczynasz22, bufor_kasa2, 0,0, 140,400,zaczynasz22->w, zaczynasz22->h);
			if(mouse_b==1)
			{
				DwochGraczy giera;
				giera.gra();
			}
		}

		if ((moneta==2)&&(wybrales==1))
		{
			masked_blit( bufor_kasa2, bufor_kasa, 0,0,0,0, 640,480);
			masked_blit( reszka, bufor_kasa2, 0,0, moneta_x,moneta_y, reszka->w, reszka->h);
			masked_blit(zaczynasz, bufor_kasa2, 0,0, 220,300,zaczynasz->w, zaczynasz->h);
			masked_blit(zaczynasz11, bufor_kasa2, 0,0, 140,400,zaczynasz11->w, zaczynasz11->h);
			if(mouse_b==1)
			{
				DwochGraczy giera;
				giera.gra();
			}
		}
		draw_sprite(bufor_kasa,kursor_money,mouse_x,mouse_y);
		blit(bufor_kasa, screen, 0,0,0,0, 640, 480);
	}
		
}

