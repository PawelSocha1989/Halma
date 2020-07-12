#include "DwochGraczy.h"
#include "menu.h"
#include "kasa.h"

DwochGraczy::DwochGraczy(void)
{
	bufor_gra = NULL;
	bufor_gra2 = NULL;
	bufor_gra3 = NULL;
	kursor_gra1 = NULL;
	twoj_ruch = NULL;
	kwadracik = NULL;
	w_niebieski = NULL;
	w_pomaranczowy = NULL;
	menu_gra = NULL;
	menu_gra2 = NULL;
	kolejny_gracz = NULL;
	kolejny_gracz2 = NULL;
	zap = NULL;

	pozycja_x=0;
	pozycja_y=450;
	zajete_przez_gracz=0;
	kolejka=0;
	kolejka1=0;
	kolejka2=0;
}

DwochGraczy::~DwochGraczy(void)
{
	destroy_bitmap(bufor_gra);
	destroy_bitmap(bufor_gra2);
	destroy_bitmap(bufor_gra3);
	destroy_bitmap(twoj_ruch);
	destroy_bitmap(kwadracik);
	destroy_bitmap(w_niebieski);
	destroy_bitmap(w_pomaranczowy);
	destroy_bitmap(menu_gra);
	destroy_bitmap(menu_gra2);
	destroy_bitmap(kolejny_gracz);
	destroy_bitmap(kolejny_gracz2);
	destroy_bitmap(zap);
	destroy_bitmap(kursor_gra1);
}

void DwochGraczy::load_gra()
{
	bufor_gra = create_bitmap(640,480);
	bufor_gra2 = create_bitmap(640,480);
	bufor_gra3 = create_bitmap(640,480);
	twoj_ruch = load_bmp( "grafika/twoj_ruch.bmp", default_palette );
	kwadracik = load_bmp( "grafika/kwadracik.bmp", default_palette );
	w_niebieski = load_bmp( "grafika/wygral_niebieski.bmp", default_palette );
	w_pomaranczowy = load_bmp( "grafika/wygral_pomaranczowy.bmp", default_palette );
	menu_gra = load_bmp( "grafika/menu_gra.bmp", default_palette );
	menu_gra2 = load_bmp( "grafika/menu_gra2.bmp", default_palette );
	kolejny_gracz = load_bmp( "grafika/kolejny_gracz.bmp", default_palette );
	kolejny_gracz2 = load_bmp( "grafika/kolejny_gracz2.bmp", default_palette );
	zap = load_bmp( "grafika/zapisywanie.bmp", default_palette );
}
void DwochGraczy::szachownica_gra()
{
	rectfill(bufor_gra3, 80, 0, 560, 480, makecol(255, 255, 255));
	rectfill(bufor_gra3, 80, 0, 128, 48, makecol(0, 0, 0));
	rectfill(bufor_gra3, 176, 0, 224, 48, makecol(0, 0, 0));
	rectfill(bufor_gra3, 272, 0, 320, 48, makecol(0, 0, 0));
	rectfill(bufor_gra3, 368, 0, 416, 48, makecol(0, 0, 0));
	rectfill(bufor_gra3, 464, 0, 512, 48, makecol(0, 0, 0));
	rectfill(bufor_gra3, 128, 48, 176, 96, makecol(0, 0, 0));
	rectfill(bufor_gra3, 224, 48, 272, 96, makecol(0, 0, 0));
	rectfill(bufor_gra3, 320, 48, 368, 96, makecol(0, 0, 0));
	rectfill(bufor_gra3, 416, 48, 464, 96, makecol(0, 0, 0));
	rectfill(bufor_gra3, 512, 48, 560, 96, makecol(0, 0, 0));
	rectfill(bufor_gra3, 80, 96, 128, 144, makecol(0, 0, 0));
	rectfill(bufor_gra3, 176, 96, 224, 144, makecol(0, 0, 0));
	rectfill(bufor_gra3, 272, 96, 320, 144, makecol(0, 0, 0));
	rectfill(bufor_gra3, 368, 96, 416, 144, makecol(0, 0, 0));
	rectfill(bufor_gra3, 464, 96, 512, 144, makecol(0, 0, 0));
	rectfill(bufor_gra3, 128, 144, 176, 192, makecol(0, 0, 0));
	rectfill(bufor_gra3, 224, 144, 272, 192, makecol(0, 0, 0));
	rectfill(bufor_gra3, 320, 144, 368, 192, makecol(0, 0, 0));
	rectfill(bufor_gra3, 416, 144, 464, 192, makecol(0, 0, 0));
	rectfill(bufor_gra3, 512, 144, 560, 192, makecol(0, 0, 0));
	rectfill(bufor_gra3, 80, 192, 128, 240, makecol(0, 0, 0));
	rectfill(bufor_gra3, 176, 192, 224, 240, makecol(0, 0, 0));
	rectfill(bufor_gra3, 272, 192, 320, 240, makecol(0, 0, 0));
	rectfill(bufor_gra3, 368, 192, 416, 240, makecol(0, 0, 0));
	rectfill(bufor_gra3, 464, 192, 512, 240, makecol(0, 0, 0));
	rectfill(bufor_gra3, 128, 240, 176, 288, makecol(0, 0, 0));
	rectfill(bufor_gra3, 224, 240, 272, 288, makecol(0, 0, 0));
	rectfill(bufor_gra3, 320, 240, 368, 288, makecol(0, 0, 0));
	rectfill(bufor_gra3, 416, 240, 464, 288, makecol(0, 0, 0));
	rectfill(bufor_gra3, 512, 240, 560, 288, makecol(0, 0, 0));
	rectfill(bufor_gra3, 80, 288, 128, 336, makecol(0, 0, 0));
	rectfill(bufor_gra3, 176, 288, 224, 336, makecol(0, 0, 0));
	rectfill(bufor_gra3, 272, 288, 320, 336, makecol(0, 0, 0));
	rectfill(bufor_gra3, 368, 288, 416, 336, makecol(0, 0, 0));
	rectfill(bufor_gra3, 464, 288, 512, 336, makecol(0, 0, 0));
	rectfill(bufor_gra3, 128, 336, 176, 384, makecol(0, 0, 0));
	rectfill(bufor_gra3, 224, 336, 272, 384, makecol(0, 0, 0));
	rectfill(bufor_gra3, 320, 336, 368, 384, makecol(0, 0, 0));
	rectfill(bufor_gra3, 416, 336, 464, 384, makecol(0, 0, 0));
	rectfill(bufor_gra3, 512, 336, 560, 384, makecol(0, 0, 0));
	rectfill(bufor_gra3, 80, 384, 128, 432, makecol(0, 0, 0));
	rectfill(bufor_gra3, 176, 384, 224, 432, makecol(0, 0, 0));
	rectfill(bufor_gra3, 272, 384, 320, 432, makecol(0, 0, 0));
	rectfill(bufor_gra3, 368, 384, 416, 432, makecol(0, 0, 0));
	rectfill(bufor_gra3, 464, 384, 512, 432, makecol(0, 0, 0));
	rectfill(bufor_gra3, 128, 432, 176, 480, makecol(0, 0, 0));
	rectfill(bufor_gra3, 224, 432, 272, 480, makecol(0, 0, 0));
	rectfill(bufor_gra3, 320, 432, 368, 480, makecol(0, 0, 0));
	rectfill(bufor_gra3, 416, 432, 464, 480, makecol(0, 0, 0));
	rectfill(bufor_gra3, 512, 432, 560, 480, makecol(0, 0, 0));
}

void DwochGraczy::kursor_gra()
{
	kursor_gra1 = load_bmp("grafika/kursor.bmp", NULL);
	set_mouse_sprite(kursor_gra1);
	unscare_mouse();
}

void DwochGraczy::tlo()
{
	szachownica_gra();

	rect(bufor_gra3,0,0,79,30,makecol(255,0,0));
	rect(bufor_gra3,1,1,78,29,makecol(255,0,0));
	rect(bufor_gra3,2,2,77,28,makecol(255,0,0));
	rect(bufor_gra3,561,0,640,30,makecol(0,0,255));
	rect(bufor_gra3,562,1,639,29,makecol(0,0,255));
	rect(bufor_gra3,563,2,638,28,makecol(0,0,255));
	textout_ex(bufor_gra3,font,"GRACZ 1",13,10,makecol(255,0,0),-1);
	textout_ex(bufor_gra3,font,"WYNIK",20,40,makecol(255,0,0),-1);
	textout_ex(bufor_gra3,font,"GRACZ 2",573,10,makecol(0,0,255),-1);
	textout_ex(bufor_gra3,font,"WYNIK",580,40,makecol(0,0,255),-1);
	masked_blit( twoj_ruch, bufor_gra3, 0,0,0,450, twoj_ruch->w, twoj_ruch->h);
	textprintf_ex( bufor_gra3, font, 20, 100, makecol(0,0,0), - 1, "%d",kolejka2);
	textprintf_ex( bufor_gra3, font, 600, 100, makecol(0,0,0), - 1, "%d",kolejka1);
	menu_game();
	kolejny();
}

void DwochGraczy::tlo2()
{
	szachownica_gra();

	rect(bufor_gra3,0,0,79,30,makecol(0,0,255));
	rect(bufor_gra3,1,1,78,29,makecol(0,0,255));
	rect(bufor_gra3,2,2,77,28,makecol(0,0,255));
	rect(bufor_gra3,561,0,640,30,makecol(255,0,0));
	rect(bufor_gra3,562,1,639,29,makecol(255,0,0));
	rect(bufor_gra3,563,2,638,28,makecol(255,0,0));
	textout_ex(bufor_gra3,font,"GRACZ 1",13,10,makecol(0,0,255),-1);
	textout_ex(bufor_gra3,font,"WYNIK",20,40,makecol(0,0,255),-1);
	textout_ex(bufor_gra3,font,"GRACZ 2",573,10,makecol(255,0,0),-1);
	textout_ex(bufor_gra3,font,"WYNIK",580,40,makecol(255,0,0),-1);
	masked_blit( twoj_ruch, bufor_gra3, 0,0,560,450, twoj_ruch->w, twoj_ruch->h);
	textprintf_ex( bufor_gra3, font, 20, 100, makecol(0,0,0), - 1, "%d",kolejka2);
	textprintf_ex( bufor_gra3, font, 600, 100, makecol(0,0,0), - 1, "%d",kolejka1);
	menu_game();
	kolejny();
}

void DwochGraczy::kolejny()
{
	masked_blit(kolejny_gracz, bufor_gra3, 0,0, 582, 300, kolejny_gracz->w, kolejny_gracz->h);
	if((mouse_x>=582)&&(mouse_x<=612)&&(mouse_y>=300)&&(mouse_y<=329))
	{
		masked_blit(kolejny_gracz2, bufor_gra3, 0,0, 582, 300, kolejny_gracz2->w, kolejny_gracz2->h);
		if(mouse_b==1)
		{
			next_game++;
			
			if(next_game%2==0)
				kolejka1++;
			
			if(next_game%2==1)
				kolejka2++;
		}

	}
}

void DwochGraczy::menu_game()
{
	masked_blit( menu_gra, bufor_gra3, 0,0,561,350, menu_gra->w, menu_gra->h);
	if((mouse_x>=561)&&(mouse_x<=640)&&(mouse_y>=350)&&(mouse_y<=366))
	{
		masked_blit( menu_gra2, bufor_gra3, 0,0,561,350, menu_gra2->w, menu_gra2->h);
		if(mouse_b==1)
		{
			menu men;
			men.menu_glowne();
		}
	}
}

void DwochGraczy::zajetosc_pol_poczatek()
{
	//pola zajete przez niebieskie
	zajete_pole[0]=zajete_pole[1]=zajete_pole[2]=zajete_pole[3]=zajete_pole[4]=
	zajete_pole[10]=zajete_pole[11]=zajete_pole[12]=zajete_pole[13]=zajete_pole[20]=
	zajete_pole[21]=zajete_pole[22]=zajete_pole[30]=zajete_pole[31]=zajete_pole[40]=
	pola[0]=pola[1]=pola[2]=pola[3]=pola[4]=pola[10]=pola[11]=pola[12]=
	pola[13]=pola[20]=pola[21]=pola[22]=pola[30]=pola[31]=pola[40]=1;

	//pola zajete przez pomarañczowe
	zajete_pole[59]=zajete_pole[68]=zajete_pole[69]=zajete_pole[77]=
	zajete_pole[78]=zajete_pole[79]=zajete_pole[86]=zajete_pole[87]=
	zajete_pole[88]=zajete_pole[89]=zajete_pole[95]=zajete_pole[96]=
	zajete_pole[97]=zajete_pole[98]=zajete_pole[99]=
	pola[59]=pola[68]=pola[69]=pola[77]=pola[78]=pola[79]=pola[86]=
	pola[87]=pola[88]=pola[89]=pola[95]=pola[96]=pola[97]=pola[98]=pola[99]=2;
}

void DwochGraczy::pol()
{
	clear_to_color(bufor_gra,makecol(0,0,0));
	clear_to_color(bufor_gra3,makecol(0,255,0));
	if(zajete_przez_gracz==1)
		tlo();
	if(zajete_przez_gracz==2)
		tlo2();
	masked_blit(bufor_gra3,bufor_gra2, 0,0,0,0,640,480);
	rozstawienie_gracz1();
	rozstawienie_gracz2();
	masked_blit(bufor_gra2,bufor_gra, 0,0,0,0,640,480);
}

void DwochGraczy::pola1(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, 
						int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, 
						int p18, int p19, int p20, int p21, int p22, int p23, int p24, int p25, 
					    int p26, int p27, int p28, int p29, int p30, int p31, int p32, int p33, 
						int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41, int p42)
{
	if((mouse_x>=polex[p1])&&(mouse_x<=polex[p2]))
	{
		if((mouse_y>=poley[p1])&&(mouse_y<=poley[p3]))
		{
			koniec_gry();
			if((pola[p4]==zajete_przez_gracz)&&(mouse_b==1))
			{	
				mouse_b=0;
				while(mouse_b!=1)
				{
					pol();
					if(twoj_ruch1==0)
					{
						if(pola[p5]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p6],poley[p6],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p42]==pola[p4])))
					{
						if((pola[p5]!=0)&&(pola[p7]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p8],poley[p8],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p9]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p10],poley[p10],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p42]==pola[p4])))
					{
						if((pola[p9]!=0)&&(pola[p11]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p12],poley[p12],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p13]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p14],poley[p14],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p42]==pola[p4])))
					{
						if((pola[p13]!=0)&&(pola[p15]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p16],poley[p16],kwadracik->w,kwadracik->h);
						}
					}
					if((mouse_x>=polex[p17])&&(mouse_x<=polex[p18]))
					{
						if((mouse_y>=poley[p17])&&(mouse_y<=poley[p19]))
						{
							if((mouse_b==2)&&(pola[p20]==1)&&(pola[p21]==0))
							{
								pola[p20]=0;
								pola[p21]=1;
								zajete_pole[p20]=0;
								zajete_pole[p21]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p20]==2)&&(pola[p21]==0))
							{
								pola[p20]=0;
								pola[p21]=2;
								zajete_pole[p20]=0;
								zajete_pole[p21]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p22])&&(mouse_x<=polex[p23]))
					{
						if((mouse_y>=poley[p22])&&(mouse_y<=poley[p24]))
						{
							if((mouse_b==2)&&(pola[p20]==1)&&(pola[p25]==0)&&(pola[p21]!=0))
							{
								pola[p20]=0;
								pola[p25]=1;
								zajete_pole[p20]=0;
								zajete_pole[p25]=1;
								wykonales_skok=1;
								p25++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p25]=1;
								p25--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p20]==2)&&(pola[p25]==0)&&(pola[p21]!=0))
							{
								pola[p20]=0;
								pola[p25]=2;
								zajete_pole[p20]=0;
								zajete_pole[p25]=2;
								wykonales_skok=1;
								p25++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p25]=2;
								p25--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p26])&&(mouse_x<=polex[p27]))
					{
						if((mouse_y>=poley[p26])&&(mouse_y<=poley[p28]))
						{
							if((mouse_b==2)&&(pola[p20]==1)&&(pola[p29]==0))
							{
								pola[p20]=0;
								pola[p29]=1;
								zajete_pole[p20]=0;
								zajete_pole[p29]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p20]==2)&&(pola[p29]==0))
							{
								pola[p20]=0;
								pola[p29]=2;
								zajete_pole[p20]=0;
								zajete_pole[p29]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p30])&&(mouse_x<=polex[p31]))
					{
						if((mouse_y>=poley[p30])&&(mouse_y<=poley[p32]))
						{
							if((mouse_b==2)&&(pola[p20]==1)&&(pola[p33]==0)&&(pola[p29]!=0))
							{
								pola[p20]=0;
								pola[p33]=1;
								zajete_pole[p20]=0;
								zajete_pole[p33]=1;
								wykonales_skok=1;
								p33++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p33]=1;
								p33--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p20]==2)&&(pola[p33]==0)&&(pola[p29]!=0))
							{
								pola[p20]=0;
								pola[p33]=2;
								zajete_pole[p20]=0;
								zajete_pole[p33]=2;
								wykonales_skok=1;
								p33++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p33]=2;
								p33--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p34])&&(mouse_x<=polex[p35]))
					{
						if((mouse_y>=poley[p34])&&(mouse_y<=poley[p36]))
						{
							if((mouse_b==2)&&(pola[p20]==1)&&(pola[p37]==0))
							{
								pola[p20]=0;
								pola[p37]=1;
								zajete_pole[p20]=0;
								zajete_pole[p37]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p20]==2)&&(pola[p37]==0))
							{
								pola[p20]=0;
								pola[p37]=2;
								zajete_pole[p20]=0;
								zajete_pole[p37]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p38])&&(mouse_x<=polex[p39]))
					{
						if((mouse_y>=poley[p38])&&(mouse_y<=poley[p40]))
						{
							if((mouse_b==2)&&(pola[p20]==1)&&(pola[p41]==0)&&(pola[p37]!=0))
							{
								pola[p20]=0;
								pola[p41]=1;
								zajete_pole[p20]=0;
								zajete_pole[p41]=1;
								wykonales_skok=1;
								p41++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p41]=1;
								p41--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p20]==2)&&(pola[p41]==0)&&(pola[p37]!=0))
							{
								pola[p20]=0;
								pola[p41]=2;
								zajete_pole[p20]=0;
								zajete_pole[p41]=2;
								wykonales_skok=1;
								p41++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p41]=2;
								p41--;
								twoj_ruch1=1;
							}
						}
					}
				draw_sprite(bufor_gra,kursor_gra1,mouse_x,mouse_y);
				blit(bufor_gra, screen, 0,0,0,0, 640, 480);
				}
			}
		}
	}
}

void DwochGraczy::pola2(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, 
						int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, 
						int p18, int p19, int p20, int p21, int p22, int p23, int p24, int p25, 
						int p26, int p27, int p28, int p29, int p30, int p31, int p32, int p33, 
						int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41, 
						int p42, int p43, int p44, int p45, int p46, int p47, int p48, int p49,
						int p50, int p51, int p52, int p53, int p54)
{
	if((mouse_x>=polex[p1])&&(mouse_x<=polex[p2]))
	{
		if((mouse_y>=poley[p1])&&(mouse_y<=poley[p3]))
		{
			koniec_gry();
			if((pola[p4]==zajete_przez_gracz)&&(mouse_b==1))
			{	
				mouse_b=0;
				while(mouse_b!=1)
				{
					pol();
					if(twoj_ruch1==0)
					{
						if(pola[p5]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p6],poley[p6],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p7]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p8],poley[p8],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p54]==pola[p4])))
					{
						if((pola[p7]!=0)&&(pola[p9]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p10],poley[p10],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p11]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p12],poley[p12],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p54]==pola[p4])))
					{
						if((pola[p11]!=0)&&(pola[p13]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p14],poley[p14],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p15]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p16],poley[p16],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p17]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p18],poley[p18],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p54]==pola[p4])))
					{
						if((pola[p17]!=0)&&(pola[p19]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p20],poley[p20],kwadracik->w,kwadracik->h);
						}
					}
					if((mouse_x>=polex[p21])&&(mouse_x<=polex[p22]))
					{
						if((mouse_y>=poley[p21])&&(mouse_y<=poley[p23]))
						{
							if((mouse_b==2)&&(pola[p24]==1)&&(pola[p25]==0))
							{
								pola[p24]=0;
								pola[p25]=1;
								zajete_pole[p24]=0;
								zajete_pole[p25]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p24]==2)&&(pola[p25]==0))
							{
								pola[p24]=0;
								pola[p25]=2;
								zajete_pole[p24]=0;
								zajete_pole[p25]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p26])&&(mouse_x<=polex[p27]))
					{
						if((mouse_y>=poley[p26])&&(mouse_y<=poley[p28]))
						{
							if((mouse_b==2)&&(pola[p24]==1)&&(pola[p29]==0))
							{
								pola[p24]=0;
								pola[p29]=1;
								zajete_pole[p24]=0;
								zajete_pole[p29]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p24]==2)&&(pola[p29]==0))
							{
								pola[p24]=0;
								pola[p29]=2;
								zajete_pole[p24]=0;
								zajete_pole[p29]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p30])&&(mouse_x<=polex[p31]))
					{
						if((mouse_y>=poley[p30])&&(mouse_y<=poley[p32]))
						{
							if((mouse_b==2)&&(pola[p24]==1)&&(pola[p33]==0)&&(pola[p29]!=0))
							{
								pola[p24]=0;
								pola[p33]=1;
								zajete_pole[p24]=0;
								zajete_pole[p33]=1;
								wykonales_skok=1;
								p33++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p33]=1;
								p33--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p24]==2)&&(pola[p33]==0)&&(pola[p29]!=0))
							{
								pola[p24]=0;
								pola[p33]=2;
								zajete_pole[p24]=0;
								zajete_pole[p33]=2;
								wykonales_skok=1;
								p33++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p33]=2;
								p33--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p34])&&(mouse_x<=polex[p35]))
					{
						if((mouse_y>=poley[p34])&&(mouse_y<=poley[p36]))
						{
							if((mouse_b==2)&&(pola[p24]==1)&&(pola[p37]==0))
							{
								pola[p24]=0;
								pola[p37]=1;
								zajete_pole[p24]=0;
								zajete_pole[p37]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p24]==2)&&(pola[p37]==0))
							{
								pola[p24]=0;
								pola[p37]=2;
								zajete_pole[p24]=0;
								zajete_pole[p37]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p38])&&(mouse_x<=polex[p39]))
					{
						if((mouse_y>=poley[p38])&&(mouse_y<=poley[p40]))
						{
							if((mouse_b==2)&&(pola[p24]==1)&&(pola[p41]==0)&&(pola[p37]!=0))
							{
								pola[p24]=0;
								pola[p41]=1;
								zajete_pole[p24]=0;
								zajete_pole[p41]=1;
								wykonales_skok=1;
								p41++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p41]=1;
								p41--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p24]==2)&&(pola[p41]==0)&&(pola[p37]!=0))
							{
								pola[p24]=0;
								pola[p41]=2;
								zajete_pole[p24]=0;
								zajete_pole[p41]=2;
								wykonales_skok=1;
								p41++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p41]=2;
								p41--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p42])&&(mouse_x<=polex[p43]))
					{
						if((mouse_y>=poley[p42])&&(mouse_y<=poley[p44]))
						{
							if((mouse_b==2)&&(pola[p24]==1)&&(pola[p45]==0))
							{
								pola[p24]=0;
								pola[p45]=1;
								zajete_pole[p24]=0;
								zajete_pole[p45]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p24]==2)&&(pola[p45]==0))
							{
								pola[p24]=0;
								pola[p45]=2;
								zajete_pole[p24]=0;
								zajete_pole[p45]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p46])&&(mouse_x<=polex[p47]))
					{
						if((mouse_y>=poley[p46])&&(mouse_y<=poley[p48]))
						{
							if((mouse_b==2)&&(pola[p24]==1)&&(pola[p49]==0))
							{
								pola[p24]=0;
								pola[p49]=1;
								zajete_pole[p24]=0;
								zajete_pole[p49]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p24]==2)&&(pola[p49]==0))
							{
								pola[p24]=0;
								pola[p49]=2;
								zajete_pole[p24]=0;
								zajete_pole[p49]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p50])&&(mouse_x<=polex[p51]))
					{
						if((mouse_y>=poley[p50])&&(mouse_y<=poley[p52]))
						{
							if((mouse_b==2)&&(pola[p24]==1)&&(pola[p53]==0)&&(pola[p49]!=0))
							{
								pola[p24]=0;
								pola[p53]=1;
								zajete_pole[p24]=0;
								zajete_pole[p53]=1;
								wykonales_skok=1;
								p53++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p53]=1;
								p53--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p24]==2)&&(pola[p53]==0)&&(pola[p49]!=0))
							{
								pola[p24]=0;
								pola[p53]=2;
								zajete_pole[p24]=0;
								zajete_pole[p53]=2;
								wykonales_skok=1;
								p53++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p53]=2;
								p53--;
								twoj_ruch1=1;
							}
						}
					}
				draw_sprite(bufor_gra,kursor_gra1,mouse_x,mouse_y);
				blit(bufor_gra, screen, 0,0,0,0, 640, 480);
				}
			}
		}
	}
}

void DwochGraczy::pola4(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, 
						int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, 
						int p18, int p19, int p20, int p21, int p22, int p23, int p24, int p25, 
						int p26, int p27, int p28, int p29, int p30, int p31, int p32, int p33, 
						int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41, 
						int p42, int p43, int p44, int p45, int p46, int p47, int p48, int p49,
						int p50, int p51, int p52, int p53, int p54, int p55, int p56, int p57,
						int p58, int p59, int p60, int p61, int p62, int p63, int p64, int p65, 
						int p66, int p67, int p68, int p69, int p70, int p71, int p72)
{
	if((mouse_x>=polex[p1])&&(mouse_x<=polex[p2]))
	{
		if((mouse_y>=poley[p1])&&(mouse_y<=poley[p3]))
		{
			koniec_gry();
			if((pola[p4]==zajete_przez_gracz)&&(mouse_b==1))
			{	
				mouse_b=0;
				while(mouse_b!=1)
				{
					pol();
					if(twoj_ruch1==0)
					{
						if(pola[p5]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p6],poley[p6],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p7]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p8],poley[p8],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p72]==pola[p4])))
					{
						if((pola[p7]!=0)&&(pola[p9]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p10],poley[p10],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p11]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p12],poley[p12],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p13]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p14],poley[p14],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p72]==pola[p4])))
					{
						if((pola[p13]!=0)&&(pola[p15]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p16],poley[p16],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p17]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p18],poley[p18],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p19]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p20],poley[p20],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p21]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p22],poley[p22],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p23]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p24],poley[p24],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p72]==pola[p4])))
					{
						if((pola[p23]!=0)&&(pola[p25]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p26],poley[p26],kwadracik->w,kwadracik->h);
						}
					}
					if((mouse_x>=polex[p27])&&(mouse_x<=polex[p28]))
					{
						if((mouse_y>=poley[p27])&&(mouse_y<=poley[p29]))
						{
							if((mouse_b==2)&&(pola[p30]==1)&&(pola[p31]==0))
							{
								pola[p30]=0;
								pola[p31]=1;
								zajete_pole[p30]=0;
								zajete_pole[p31]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p30]==2)&&(pola[p31]==0))
							{
								pola[p30]=0;
								pola[p31]=2;
								zajete_pole[p30]=0;
								zajete_pole[p31]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p32])&&(mouse_x<=polex[p33]))
					{
						if((mouse_y>=poley[p32])&&(mouse_y<=poley[p34]))
						{
							if((mouse_b==2)&&(pola[p30]==1)&&(pola[p35]==0))
							{
								pola[p30]=0;
								pola[p35]=1;
								zajete_pole[p30]=0;
								zajete_pole[p35]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p30]==2)&&(pola[p35]==0))
							{
								pola[p30]=0;
								pola[p35]=2;
								zajete_pole[p30]=0;
								zajete_pole[p35]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p36])&&(mouse_x<=polex[p37]))
					{
						if((mouse_y>=poley[p36])&&(mouse_y<=poley[p38]))
						{
							if((mouse_b==2)&&(pola[p30]==1)&&(pola[p39]==0))
							{
								pola[p30]=0;
								pola[p39]=1;
								zajete_pole[p30]=0;
								zajete_pole[p39]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p30]==2)&&(pola[p39]==0))
							{
								pola[p30]=0;
								pola[p39]=2;
								zajete_pole[p30]=0;
								zajete_pole[p39]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p40])&&(mouse_x<=polex[p41]))
					{
						if((mouse_y>=poley[p40])&&(mouse_y<=poley[p42]))
						{
							if((mouse_b==2)&&(pola[p30]==1)&&(pola[p43]==0)&&(pola[p39]!=0))
							{
								pola[p30]=0;
								pola[p43]=1;
								zajete_pole[p30]=0;
								zajete_pole[p43]=1;
								wykonales_skok=1;
								p43++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p43]=1;
								p43--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p30]==2)&&(pola[p43]==0)&&(pola[p39]!=0))
							{
								pola[p30]=0;
								pola[p43]=2;
								zajete_pole[p30]=0;
								zajete_pole[p43]=2;
								wykonales_skok=1;
								p43++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p43]=2;
								p43--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p44])&&(mouse_x<=polex[p45]))
					{
						if((mouse_y>=poley[p44])&&(mouse_y<=poley[p46]))
						{
							if((mouse_b==2)&&(pola[p30]==1)&&(pola[p47]==0))
							{
								pola[p30]=0;
								pola[p47]=1;
								zajete_pole[p30]=0;
								zajete_pole[p47]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p30]==2)&&(pola[p47]==0))
							{
								pola[p30]=0;
								pola[p47]=2;
								zajete_pole[p30]=0;
								zajete_pole[p47]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p48])&&(mouse_x<=polex[p49]))
					{
						if((mouse_y>=poley[p48])&&(mouse_y<=poley[p50]))
						{
							if((mouse_b==2)&&(pola[p30]==1)&&(pola[p51]==0)&&(pola[p47]!=0))
							{
								pola[p30]=0;
								pola[p51]=1;
								zajete_pole[p30]=0;
								zajete_pole[p51]=1;
								wykonales_skok=1;
								p51++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p51]=1;
								p51--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p30]==2)&&(pola[p51]==0)&&(pola[p47]!=0))
							{
								pola[p30]=0;
								pola[p51]=2;
								zajete_pole[p30]=0;
								zajete_pole[p51]=2;
								wykonales_skok=1;
								p51++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p51]=2;
								p51--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p52])&&(mouse_x<=polex[p53]))
					{
						if((mouse_y>=poley[p52])&&(mouse_y<=poley[p54]))
						{
							if((mouse_b==2)&&(pola[p30]==1)&&(pola[p55]==0))
							{
								pola[p30]=0;
								pola[p55]=1;
								zajete_pole[p30]=0;
								zajete_pole[p55]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p30]==2)&&(pola[p55]==0))
							{
								pola[p30]=0;
								pola[p55]=2;
								zajete_pole[p30]=0;
								zajete_pole[p55]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p56])&&(mouse_x<=polex[p57]))
					{
						if((mouse_y>=poley[p56])&&(mouse_y<=poley[p58]))
						{
							if((mouse_b==2)&&(pola[p30]==1)&&(pola[p59]==0))
							{
								pola[p30]=0;
								pola[p59]=1;
								zajete_pole[p30]=0;
								zajete_pole[p59]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p30]==2)&&(pola[p59]==0))
							{
								pola[p30]=0;
								pola[p59]=2;
								zajete_pole[p30]=0;
								zajete_pole[p59]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p60])&&(mouse_x<=polex[p61]))
					{
						if((mouse_y>=poley[p60])&&(mouse_y<=poley[p62]))
						{
							if((mouse_b==2)&&(pola[p30]==1)&&(pola[p63]==0))
							{
								pola[p30]=0;
								pola[p63]=1;
								zajete_pole[p30]=0;
								zajete_pole[p63]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p30]==2)&&(pola[p63]==0))
							{
								pola[p30]=0;
								pola[p63]=2;
								zajete_pole[p30]=0;
								zajete_pole[p63]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p64])&&(mouse_x<=polex[p65]))
					{
						if((mouse_y>=poley[p64])&&(mouse_y<=poley[p66]))
						{
							if((mouse_b==2)&&(pola[p30]==1)&&(pola[p67]==0))
							{
								pola[p30]=0;
								pola[p67]=1;
								zajete_pole[p30]=0;
								zajete_pole[p67]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p30]==2)&&(pola[p67]==0))
							{
								pola[p30]=0;
								pola[p67]=2;
								zajete_pole[p30]=0;
								zajete_pole[p67]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p68])&&(mouse_x<=polex[p69]))
					{
						if((mouse_y>=poley[p68])&&(mouse_y<=poley[p70]))
						{
							if((mouse_b==2)&&(pola[p30]==1)&&(pola[p71]==0)&&(pola[p67]!=0))
							{
								pola[p30]=0;
								pola[p71]=1;
								zajete_pole[p30]=0;
								zajete_pole[p71]=1;
								wykonales_skok=1;
								p71++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p71]=1;
								p71--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p30]==2)&&(pola[p71]==0)&&(pola[p67]!=0))
							{
								pola[p30]=0;
								pola[p71]=2;
								zajete_pole[p30]=0;
								zajete_pole[p71]=2;
								wykonales_skok=1;
								p71++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p71]=2;
								p71--;
								twoj_ruch1=1;
							}
						}
					}
				draw_sprite(bufor_gra,kursor_gra1,mouse_x,mouse_y);
				blit(bufor_gra, screen, 0,0,0,0, 640, 480);
				}
			}
		}
	}
}

void DwochGraczy::pola3(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, 
						int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, 
						int p18, int p19, int p20, int p21, int p22, int p23, int p24, int p25, 
						int p26, int p27, int p28, int p29, int p30, int p31, int p32, int p33, 
						int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41, 
						int p42, int p43, int p44, int p45, int p46, int p47, int p48, int p49,
						int p50, int p51, int p52, int p53, int p54, int p55, int p56, int p57,
						int p58, int p59, int p60, int p61, int p62, int p63, int p64, int p65, int p66)
{
	if((mouse_x>=polex[p1])&&(mouse_x<=polex[p2]))
	{
		if((mouse_y>=poley[p1])&&(mouse_y<=poley[p3]))
		{
			koniec_gry();
			if((pola[p4]==zajete_przez_gracz)&&(mouse_b==1))
			{	
				mouse_b=0;
				while(mouse_b!=1)
				{
					pol();
					if(twoj_ruch1==0)
					{
						if(pola[p5]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p6],poley[p6],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p66]==pola[p4])))
					{
						if((pola[p5]!=0)&&(pola[p7]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p8],poley[p8],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p9]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p10],poley[p10],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p66]==pola[p4])))
					{
						if((pola[p9]!=0)&&(pola[p11]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p12],poley[p12],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p13]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p14],poley[p14],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p66]==pola[p4])))
					{
						if((pola[p13]!=0)&&(pola[p15]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p16],poley[p16],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p17]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p18],poley[p18],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p66]==pola[p4])))
					{
						if((pola[p17]!=0)&&(pola[p19]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p20],poley[p20],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p21]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p22],poley[p22],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p66]==pola[p4])))
					{
						if((pola[p21]!=0)&&(pola[p23]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p24],poley[p24],kwadracik->w,kwadracik->h);
						}
					}
					if((mouse_x>=polex[p25])&&(mouse_x<=polex[p26]))
					{
						if((mouse_y>=poley[p25])&&(mouse_y<=poley[p27]))
						{
							if((mouse_b==2)&&(pola[p28]==1)&&(pola[p29]==0))
							{
								pola[p28]=0;
								pola[p29]=1;
								zajete_pole[p28]=0;
								zajete_pole[p29]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p28]==2)&&(pola[p29]==0))
							{
								pola[p28]=0;
								pola[p29]=2;
								zajete_pole[p28]=0;
								zajete_pole[p29]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p30])&&(mouse_x<=polex[p31]))
					{
						if((mouse_y>=poley[p30])&&(mouse_y<=poley[p32]))
						{
							if((mouse_b==2)&&(pola[p28]==1)&&(pola[p33]==0)&&(pola[p29]!=0))
							{
								pola[p28]=0;
								pola[p33]=1;
								zajete_pole[p28]=0;
								zajete_pole[p33]=1;
								wykonales_skok=1;
								p33++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p33]=1;
								p33--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p28]==2)&&(pola[p33]==0)&&(pola[p29]!=0))
							{
								pola[p28]=0;
								pola[p33]=2;
								zajete_pole[p28]=0;
								zajete_pole[p33]=2;
								wykonales_skok=1;
								p33++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p33]=2;
								p33--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p34])&&(mouse_x<=polex[p35]))
					{
						if((mouse_y>=poley[p34])&&(mouse_y<=poley[p36]))
						{
							if((mouse_b==2)&&(pola[p28]==1)&&(pola[p37]==0))
							{
								pola[p28]=0;
								pola[p37]=1;
								zajete_pole[p28]=0;
								zajete_pole[p37]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p28]==2)&&(pola[p37]==0))
							{
								pola[p28]=0;
								pola[p37]=2;
								zajete_pole[p28]=0;
								zajete_pole[p37]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p38])&&(mouse_x<=polex[p39]))
					{
						if((mouse_y>=poley[p38])&&(mouse_y<=poley[p40]))
						{
							if((mouse_b==2)&&(pola[p28]==1)&&(pola[p41]==0)&&(pola[p37]!=0))
							{
								pola[p28]=0;
								pola[p41]=1;
								zajete_pole[p28]=0;
								zajete_pole[p41]=1;
								wykonales_skok=1;
								p41++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p41]=1;
								p41--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p28]==2)&&(pola[p41]==0)&&(pola[p37]!=0))
							{
								pola[p28]=0;
								pola[p41]=2;
								zajete_pole[p28]=0;
								zajete_pole[p41]=2;
								wykonales_skok=1;
								p41++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p41]=2;
								p41--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p42])&&(mouse_x<=polex[p43]))
					{
						if((mouse_y>=poley[p42])&&(mouse_y<=poley[p44]))
						{
							if((mouse_b==2)&&(pola[p28]==1)&&(pola[p45]==0))
							{
								pola[p28]=0;
								pola[p45]=1;
								zajete_pole[p28]=0;
								zajete_pole[p45]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p28]==2)&&(pola[p45]==0))
							{
								pola[p28]=0;
								pola[p45]=2;
								zajete_pole[p28]=0;
								zajete_pole[p45]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p46])&&(mouse_x<=polex[p47]))
					{
						if((mouse_y>=poley[p46])&&(mouse_y<=poley[p48]))
						{
							if((mouse_b==2)&&(pola[p28]==1)&&(pola[p49]==0)&&(pola[p45]!=0))
							{
								pola[p28]=0;
								pola[p49]=1;
								zajete_pole[p28]=0;
								zajete_pole[p49]=1;
								wykonales_skok=1;
								p49++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p49]=1;
								p49--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p28]==2)&&(pola[p49]==0)&&(pola[p45]!=0))
							{
								pola[p28]=0;
								pola[p49]=2;
								zajete_pole[p28]=0;
								zajete_pole[p49]=2;
								wykonales_skok=1;
								p49++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p49]=2;
								p49--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p50])&&(mouse_x<=polex[p51]))
					{
						if((mouse_y>=poley[p50])&&(mouse_y<=poley[p52]))
						{
							if((mouse_b==2)&&(pola[p28]==1)&&(pola[p53]==0))
							{
								pola[p28]=0;
								pola[p53]=1;
								zajete_pole[p28]=0;
								zajete_pole[p53]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p28]==2)&&(pola[p53]==0))
							{
								pola[p28]=0;
								pola[p53]=2;
								zajete_pole[p28]=0;
								zajete_pole[p53]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p54])&&(mouse_x<=polex[p55]))
					{
						if((mouse_y>=poley[p54])&&(mouse_y<=poley[p56]))
						{
							if((mouse_b==2)&&(pola[p28]==1)&&(pola[p57]==0)&&(pola[p53]!=0))
							{
								pola[p28]=0;
								pola[p57]=1;
								zajete_pole[p28]=0;
								zajete_pole[p57]=1;
								wykonales_skok=1;
								p57++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p57]=1;
								p57--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p28]==2)&&(pola[p57]==0)&&(pola[p53]!=0))
							{
								pola[p28]=0;
								pola[p57]=2;
								zajete_pole[p28]=0;
								zajete_pole[p57]=2;
								wykonales_skok=1;
								p57++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p57]=2;
								p57--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p58])&&(mouse_x<=polex[p59]))
					{
						if((mouse_y>=poley[p58])&&(mouse_y<=poley[p60]))
						{
							if((mouse_b==2)&&(pola[p28]==1)&&(pola[p61]==0))
							{
								pola[p28]=0;
								pola[p61]=1;
								zajete_pole[p28]=0;
								zajete_pole[p61]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p28]==2)&&(pola[p61]==0))
							{
								pola[p28]=0;
								pola[p61]=2;
								zajete_pole[p28]=0;
								zajete_pole[p61]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p62])&&(mouse_x<=polex[p63]))
					{
						if((mouse_y>=poley[p62])&&(mouse_y<=poley[p64]))
						{
							if((mouse_b==2)&&(pola[p28]==1)&&(pola[p65]==0)&&(pola[p61]!=0))
							{
								pola[p28]=0;
								pola[p65]=1;
								zajete_pole[p28]=0;
								zajete_pole[p65]=1;
								wykonales_skok=1;
								p65++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p65]=1;
								p65--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p28]==2)&&(pola[p65]==0)&&(pola[p61]!=0))
							{
								pola[p28]=0;
								pola[p65]=2;
								zajete_pole[p28]=0;
								zajete_pole[p65]=2;
								wykonales_skok=1;
								p65++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p65]=2;
								p65--;
								twoj_ruch1=1;
							}
						}
					}
				draw_sprite(bufor_gra,kursor_gra1,mouse_x,mouse_y);
				blit(bufor_gra, screen, 0,0,0,0, 640, 480);
				}
			}
		}
	}
}

void DwochGraczy::pola5(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, 
						int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, 
						int p18, int p19, int p20, int p21, int p22, int p23, int p24, int p25, 
						int p26, int p27, int p28, int p29, int p30, int p31, int p32, int p33, 
						int p34, int p35, int p36, int p37, int p38, int p39, int p40, int p41, 
						int p42, int p43, int p44, int p45, int p46, int p47, int p48, int p49,
						int p50, int p51, int p52, int p53, int p54, int p55, int p56, int p57,
						int p58, int p59, int p60, int p61, int p62, int p63, int p64, int p65, 
						int p66, int p67, int p68, int p69, int p70, int p71, int p72, int p73,
						int p74, int p75, int p76, int p77, int p78, int p79, int p80, int p81,
						int p82, int p83, int p84)
{
	if((mouse_x>=polex[p1])&&(mouse_x<=polex[p2]))
	{
		if((mouse_y>=poley[p1])&&(mouse_y<=poley[p3]))
		{
			koniec_gry();
			if((pola[p4]==zajete_przez_gracz)&&(mouse_b==1))
			{	
				mouse_b=0;
				while(mouse_b!=1)
				{
					pol();
					if(twoj_ruch1==0)
					{
						if(pola[p5]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p6],poley[p6],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p84]==pola[p4])))
					{
						if((pola[p5]!=0)&&(pola[p7]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p8],poley[p8],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p9]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p10],poley[p10],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p11]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p12],poley[p12],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p84]==pola[p4])))
					{
						if((pola[p11]!=0)&&(pola[p13]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p14],poley[p14],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p15]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p16],poley[p16],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p84]==pola[p4])))
					{
						if((pola[p15]!=0)&&(pola[p17]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p18],poley[p18],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p19]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p20],poley[p20],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p21]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p22],poley[p22],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p23]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p24],poley[p24],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p84]==pola[p4])))
					{
						if((pola[p23]!=0)&&(pola[p25]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p26],poley[p26],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p27]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p28],poley[p28],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p84]==pola[p4])))
					{
						if((pola[p27]!=0)&&(pola[p29]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p30],poley[p30],kwadracik->w,kwadracik->h);
						}
					}
					if((mouse_x>=polex[p31])&&(mouse_x<=polex[p32]))
					{
						if((mouse_y>=poley[p31])&&(mouse_y<=poley[p33]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p35]==0))
							{
								pola[p34]=0;
								pola[p35]=1;
								zajete_pole[p34]=0;
								zajete_pole[p35]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p35]==0))
							{
								pola[p34]=0;
								pola[p35]=2;
								zajete_pole[p34]=0;
								zajete_pole[p35]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p36])&&(mouse_x<=polex[p37]))
					{
						if((mouse_y>=poley[p36])&&(mouse_y<=poley[p38]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p39]==0)&&(pola[p35]!=0))
							{
								pola[p34]=0;
								pola[p39]=1;
								zajete_pole[p34]=0;
								zajete_pole[p39]=1;
								wykonales_skok=1;
								p39++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p39]=1;
								p39--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p39]==0)&&(pola[p35]!=0))
							{
								pola[p34]=0;
								pola[p39]=2;
								zajete_pole[p34]=0;
								zajete_pole[p39]=2;
								wykonales_skok=1;
								p39++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p39]=2;
								p39--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p40])&&(mouse_x<=polex[p41]))
					{
						if((mouse_y>=poley[p40])&&(mouse_y<=poley[p42]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p43]==0))
							{
								pola[p34]=0;
								pola[p43]=1;
								zajete_pole[p34]=0;
								zajete_pole[p43]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p43]==0))
							{
								pola[p34]=0;
								pola[p43]=2;
								zajete_pole[p34]=0;
								zajete_pole[p43]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p44])&&(mouse_x<=polex[p45]))
					{
						if((mouse_y>=poley[p44])&&(mouse_y<=poley[p46]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p47]==0))
							{
								pola[p34]=0;
								pola[p47]=1;
								zajete_pole[p34]=0;
								zajete_pole[p47]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p47]==0))
							{
								pola[p34]=0;
								pola[p47]=2;
								zajete_pole[p34]=0;
								zajete_pole[p47]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p48])&&(mouse_x<=polex[p49]))
					{
						if((mouse_y>=poley[p48])&&(mouse_y<=poley[p50]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p51]==0)&&(pola[p47]!=0))
							{
								pola[p34]=0;
								pola[p51]=1;
								zajete_pole[p34]=0;
								zajete_pole[p51]=1;
								wykonales_skok=1;
								p51++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p51]=1;
								p51--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p51]==0)&&(pola[p47]!=0))
							{
								pola[p34]=0;
								pola[p51]=2;
								zajete_pole[p34]=0;
								zajete_pole[p51]=2;
								p51++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p51]=2;
								p51--;
								wykonales_skok=1;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p52])&&(mouse_x<=polex[p53]))
					{
						if((mouse_y>=poley[p52])&&(mouse_y<=poley[p54]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p55]==0))
							{
								pola[p34]=0;
								pola[p55]=1;
								zajete_pole[p34]=0;
								zajete_pole[p55]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p55]==0))
							{
								pola[p34]=0;
								pola[p55]=2;
								zajete_pole[p34]=0;
								zajete_pole[p55]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p56])&&(mouse_x<=polex[p57]))
					{
						if((mouse_y>=poley[p56])&&(mouse_y<=poley[p58]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p59]==0)&&(pola[p55]!=0))
							{
								pola[p34]=0;
								pola[p59]=1;
								zajete_pole[p34]=0;
								zajete_pole[p59]=1;
								p59++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p59]=1;
								p59--;
								wykonales_skok=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p59]==0)&&(pola[p55]!=0))
							{
								pola[p34]=0;
								pola[p59]=2;
								zajete_pole[p34]=0;
								zajete_pole[p59]=2;
								p59++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p59]=2;
								p59--;
								wykonales_skok=1;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p60])&&(mouse_x<=polex[p61]))
					{
						if((mouse_y>=poley[p60])&&(mouse_y<=poley[p62]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p63]==0))
							{
								pola[p34]=0;
								pola[p63]=1;
								zajete_pole[p34]=0;
								zajete_pole[p63]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p63]==0))
							{
								pola[p34]=0;
								pola[p63]=2;
								zajete_pole[p34]=0;
								zajete_pole[p63]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p64])&&(mouse_x<=polex[p65]))
					{
						if((mouse_y>=poley[p64])&&(mouse_y<=poley[p66]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p67]==0))
							{
								pola[p34]=0;
								pola[p67]=1;
								zajete_pole[p34]=0;
								zajete_pole[p67]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p67]==0))
							{
								pola[p34]=0;
								pola[p67]=2;
								zajete_pole[p34]=0;
								zajete_pole[p67]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p68])&&(mouse_x<=polex[p69]))
					{
						if((mouse_y>=poley[p68])&&(mouse_y<=poley[p70]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p71]==0))
							{
								pola[p34]=0;
								pola[p71]=1;
								zajete_pole[p34]=0;
								zajete_pole[p71]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p71]==0))
							{
								pola[p34]=0;
								pola[p71]=2;
								zajete_pole[p34]=0;
								zajete_pole[p71]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p72])&&(mouse_x<=polex[p73]))
					{
						if((mouse_y>=poley[p72])&&(mouse_y<=poley[p74]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p75]==0)&&(pola[p71]!=0))
							{
								pola[p34]=0;
								pola[p75]=1;
								zajete_pole[p34]=0;
								zajete_pole[p75]=1;
								p75++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p75]=1;
								wykonales_skok=1;
								p75--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p75]==0)&&(pola[p71]!=0))
							{
								pola[p34]=0;
								pola[p75]=2;
								zajete_pole[p34]=0;
								zajete_pole[p75]=2;
								wykonales_skok=1;
								p75++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p75]=2;
								p75--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p76])&&(mouse_x<=polex[p77]))
					{
						if((mouse_y>=poley[p76])&&(mouse_y<=poley[p78]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p79]==0))
							{
								pola[p34]=0;
								pola[p79]=1;
								zajete_pole[p34]=0;
								zajete_pole[p79]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p79]==0))
							{
								pola[p34]=0;
								pola[p79]=2;
								zajete_pole[p34]=0;
								zajete_pole[p79]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p80])&&(mouse_x<=polex[p81]))
					{
						if((mouse_y>=poley[p80])&&(mouse_y<=poley[p82]))
						{
							if((mouse_b==2)&&(pola[p34]==1)&&(pola[p83]==0)&&(pola[p79]!=0))
							{
								pola[p34]=0;
								pola[p83]=1;
								zajete_pole[p34]=0;
								zajete_pole[p83]=1;
								wykonales_skok=1;
								p83++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p83]=1;
								p83--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p34]==2)&&(pola[p83]==0)&&(pola[p79]!=0))
							{
								pola[p34]=0;
								pola[p83]=2;
								zajete_pole[p34]=0;
								zajete_pole[p83]=2;
								wykonales_skok=1;
								p83++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p83]=2;
								p83--;
								twoj_ruch1=1;
							}
						}
					}
				draw_sprite(bufor_gra,kursor_gra1,mouse_x,mouse_y);
				blit(bufor_gra, screen, 0,0,0,0, 640, 480);
				}
			}
		}
	}
}

void DwochGraczy::pola6(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, 
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
						int p98, int p99, int p100, int p101, int p102)
{
	if((mouse_x>=polex[p1])&&(mouse_x<=polex[p2]))
	{
		if((mouse_y>=poley[p1])&&(mouse_y<=poley[p3]))
		{
			koniec_gry();
			if((pola[p4]==zajete_przez_gracz)&&(mouse_b==1))
			{	
				mouse_b=0;
				while(mouse_b!=1)
				{
					pol();
					if(twoj_ruch1==0)
					{
						if(pola[p5]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p6],poley[p6],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p102]==pola[p4])))
					{
						if((pola[p5]!=0)&&(pola[p7]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p8],poley[p8],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p9]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p10],poley[p10],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p102]==pola[p4])))
					{
						if((pola[p9]!=0)&&(pola[p11]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p12],poley[p12],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p13]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p14],poley[p14],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p102]==pola[p4])))
					{
						if((pola[p13]!=0)&&(pola[p15]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p16],poley[p16],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p17]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p18],poley[p18],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p102]==pola[p4])))
					{
						if((pola[p17]!=0)&&(pola[p19]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p20],poley[p20],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p21]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p22],poley[p22],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p102]==pola[p4])))
					{
						if((pola[p21]!=0)&&(pola[p23]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p24],poley[p24],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p25]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p26],poley[p26],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p102]==pola[p4])))
					{
						if((pola[p25]!=0)&&(pola[p27]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p28],poley[p28],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p29]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p30],poley[p30],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p102]==pola[p4])))
					{
						if((pola[p29]!=0)&&(pola[p31]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p32],poley[p32],kwadracik->w,kwadracik->h);
						}
					}
					if(twoj_ruch1==0)
					{
						if(pola[p33]==0)
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p34],poley[p34],kwadracik->w,kwadracik->h);
						}
					}
					if((twoj_ruch1==0)||((wykonales_skok==1)&&(pojawilo_sie[p102]==pola[p4])))
					{
						if((pola[p33]!=0)&&(pola[p35]==0))
						{
							masked_blit(kwadracik,bufor_gra, 0,0,polex[p36],poley[p36],kwadracik->w,kwadracik->h);
						}
					}
					if((mouse_x>=polex[p37])&&(mouse_x<=polex[p38]))
					{
						if((mouse_y>=poley[p37])&&(mouse_y<=poley[p39]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p41]==0))
							{
								pola[p40]=0;
								pola[p41]=1;
								zajete_pole[p40]=0;
								zajete_pole[p41]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p41]==0))
							{
								pola[p40]=0;
								pola[p41]=2;
								zajete_pole[p40]=0;
								zajete_pole[p41]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p42])&&(mouse_x<=polex[p43]))
					{
						if((mouse_y>=poley[p42])&&(mouse_y<=poley[p44]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p45]==0)&&(pola[p41]!=0))
							{
								pola[p40]=0;
								pola[p45]=1;
								zajete_pole[p40]=0;
								zajete_pole[p45]=1;
								wykonales_skok=1;
								p45++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p45]=1;
								p45--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p45]==0)&&(pola[p41]!=0))
							{
								pola[p40]=0;
								pola[p45]=2;
								zajete_pole[p40]=0;
								zajete_pole[p45]=2;
								wykonales_skok=1;
								p45++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p45]=2;
								p45--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p46])&&(mouse_x<=polex[p47]))
					{
						if((mouse_y>=poley[p46])&&(mouse_y<=poley[p48]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p49]==0))
							{
								pola[p40]=0;
								pola[p49]=1;
								zajete_pole[p40]=0;
								zajete_pole[p49]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p49]==0))
							{
								pola[p40]=0;
								pola[p49]=2;
								zajete_pole[p40]=0;
								zajete_pole[p49]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p50])&&(mouse_x<=polex[p51]))
					{
						if((mouse_y>=poley[p50])&&(mouse_y<=poley[p52]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p53]==0)&&(pola[p49]!=0))
							{
								pola[p40]=0;
								pola[p53]=1;
								zajete_pole[p40]=0;
								zajete_pole[p53]=1;
								wykonales_skok=1;
								p53++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p53]=1;
								p53--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p53]==0)&&(pola[p49]!=0))
							{
								pola[p40]=0;
								pola[p53]=2;
								zajete_pole[p40]=0;
								zajete_pole[p53]=2;
								wykonales_skok=1;
								p53++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p53]=2;
								p53--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p54])&&(mouse_x<=polex[p55]))
					{
						if((mouse_y>=poley[p54])&&(mouse_y<=poley[p56]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p57]==0))
							{
								pola[p40]=0;
								pola[p57]=1;
								zajete_pole[p40]=0;
								zajete_pole[p57]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p57]==0))
							{
								pola[p40]=0;
								pola[p57]=2;
								zajete_pole[p40]=0;
								zajete_pole[p57]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p58])&&(mouse_x<=polex[p59]))
					{
						if((mouse_y>=poley[p58])&&(mouse_y<=poley[p60]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p61]==0)&&(pola[p57]!=0))
							{
								pola[p40]=0;
								pola[p61]=1;
								zajete_pole[p40]=0;
								zajete_pole[p61]=1;
								wykonales_skok=1;
								p61++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p61]=1;
								p61--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p61]==0)&&(pola[p57]!=0))
							{
								pola[p40]=0;
								pola[p61]=2;
								zajete_pole[p40]=0;
								zajete_pole[p61]=2;
								wykonales_skok=1;
								p61++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p61]=2;
								p61--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p62])&&(mouse_x<=polex[p63]))
					{
						if((mouse_y>=poley[p62])&&(mouse_y<=poley[p64]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p65]==0))
							{
								pola[p40]=0;
								pola[p65]=1;
								zajete_pole[p40]=0;
								zajete_pole[p65]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p65]==0))
							{
								pola[p40]=0;
								pola[p65]=2;
								zajete_pole[p40]=0;
								zajete_pole[p65]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p66])&&(mouse_x<=polex[p67]))
					{
						if((mouse_y>=poley[p66])&&(mouse_y<=poley[p68]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p69]==0)&&(pola[p65]!=0))
							{
								pola[p40]=0;
								pola[p69]=1;
								zajete_pole[p40]=0;
								zajete_pole[p69]=1;
								wykonales_skok=1;
								p69++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p69]=1;
								p69--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p69]==0)&&(pola[p65]!=0))
							{
								pola[p40]=0;
								pola[p69]=2;
								zajete_pole[p40]=0;
								zajete_pole[p69]=2;
								wykonales_skok=1;
								p69++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p69]=2;
								p69--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p70])&&(mouse_x<=polex[p71]))
					{
						if((mouse_y>=poley[p70])&&(mouse_y<=poley[p72]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p73]==0))
							{
								pola[p40]=0;
								pola[p73]=1;
								zajete_pole[p40]=0;
								zajete_pole[p73]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p73]==0))
							{
								pola[p40]=0;
								pola[p73]=2;
								zajete_pole[p40]=0;
								zajete_pole[p73]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p74])&&(mouse_x<=polex[p75]))
					{
						if((mouse_y>=poley[p74])&&(mouse_y<=poley[p76]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p77]==0)&&(pola[p73]!=0))
							{
								pola[p40]=0;
								pola[p77]=1;
								zajete_pole[p40]=0;
								zajete_pole[p77]=1;
								wykonales_skok=1;
								p77++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p77]=1;
								p77--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p77]==0)&&(pola[p73]!=0))
							{
								pola[p40]=0;
								pola[p77]=2;
								zajete_pole[p40]=0;
								zajete_pole[p77]=2;
								wykonales_skok=1;
								p77++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p77]=2;
								p77--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p78])&&(mouse_x<=polex[p79]))
					{
						if((mouse_y>=poley[p78])&&(mouse_y<=poley[p80]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p81]==0))
							{
								pola[p40]=0;
								pola[p81]=1;
								zajete_pole[p40]=0;
								zajete_pole[p81]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p81]==0))
							{
								pola[p40]=0;
								pola[p81]=2;
								zajete_pole[p40]=0;
								zajete_pole[p81]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p82])&&(mouse_x<=polex[p83]))
					{
						if((mouse_y>=poley[p82])&&(mouse_y<=poley[p84]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p85]==0)&&(pola[p81]!=0))
							{
								pola[p40]=0;
								pola[p85]=1;
								zajete_pole[p40]=0;
								zajete_pole[p85]=1;
								wykonales_skok=1;
								p85++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p85]=1;
								p85--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p85]==0)&&(pola[p81]!=0))
							{
								pola[p40]=0;
								pola[p85]=2;
								zajete_pole[p40]=0;
								zajete_pole[p85]=2;
								wykonales_skok=1;
								p85++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p85]=2;
								p85--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p86])&&(mouse_x<=polex[p87]))
					{
						if((mouse_y>=poley[p86])&&(mouse_y<=poley[p88]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p89]==0))
							{
								pola[p40]=0;
								pola[p89]=1;
								zajete_pole[p40]=0;
								zajete_pole[p89]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p89]==0))
							{
								pola[p40]=0;
								pola[p89]=2;
								zajete_pole[p40]=0;
								zajete_pole[p89]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p90])&&(mouse_x<=polex[p91]))
					{
						if((mouse_y>=poley[p90])&&(mouse_y<=poley[p92]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p93]==0)&&(pola[p89]!=0))
							{
								pola[p40]=0;
								pola[p93]=1;
								zajete_pole[p40]=0;
								zajete_pole[p93]=1;
								wykonales_skok=1;
								p93++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p93]=1;
								p93--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p93]==0)&&(pola[p89]!=0))
							{
								pola[p40]=0;
								pola[p93]=2;
								zajete_pole[p40]=0;
								zajete_pole[p93]=2;
								wykonales_skok=1;
								p93++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p93]=2;
								p93--;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p94])&&(mouse_x<=polex[p95]))
					{
						if((mouse_y>=poley[p94])&&(mouse_y<=poley[p96]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p97]==0))
							{
								pola[p40]=0;
								pola[p97]=1;
								zajete_pole[p40]=0;
								zajete_pole[p97]=1;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p97]==0))
							{
								pola[p40]=0;
								pola[p97]=2;
								zajete_pole[p40]=0;
								zajete_pole[p97]=2;
								twoj_ruch1=1;
							}
						}
					}
					if((mouse_x>=polex[p98])&&(mouse_x<=polex[p99]))
					{
						if((mouse_y>=poley[p98])&&(mouse_y<=poley[p100]))
						{
							if((mouse_b==2)&&(pola[p40]==1)&&(pola[p101]==0)&&(pola[p97]!=0))
							{
								pola[p40]=0;
								pola[p101]=1;
								zajete_pole[p40]=0;
								zajete_pole[p101]=1;
								wykonales_skok=1;
								p101++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p101]=1;
								p101--;
								twoj_ruch1=1;
							}
							else if((mouse_b==2)&&(pola[p40]==2)&&(pola[p101]==0)&&(pola[p97]!=0))
							{
								pola[p40]=0;
								pola[p101]=2;
								zajete_pole[p40]=0;
								zajete_pole[p101]=2;
								wykonales_skok=1;
								p101++;
								for(int t=1;t<=100;t++)
								pojawilo_sie[t]=0;
								pojawilo_sie[p101]=2;
								p101--;
								twoj_ruch1=1;
							}
						}
					}
				draw_sprite(bufor_gra,kursor_gra1,mouse_x,mouse_y);
				blit(bufor_gra, screen, 0,0,0,0, 640, 480);
				}
			}
		}
	}
}

void DwochGraczy::zajetosc_pol()
{
	for(int g=0; g<=99; g++)
		if(zajete_pole[g]==1)
			pola[g]=1;
		else if(zajete_pole[g]==2)
			pola[g]=2;
		else
			pola[g]=0;	
}

void DwochGraczy::koniec_gry()
{
	while((zajete_pole[0]==2)&&(zajete_pole[1]==2)&&(zajete_pole[2]==2)&&(zajete_pole[3]==2)&&
	   (zajete_pole[4]==2)&&(zajete_pole[10]==2)&&(zajete_pole[11]==2)&&(zajete_pole[12]==2)&&
	   (zajete_pole[13]==2)&&(zajete_pole[20]==2)&&(zajete_pole[21]==2)&&(zajete_pole[22]==2)&&
	   (zajete_pole[30]==2)&&(zajete_pole[31]==2)&&(zajete_pole[40]==2))
	{
	   masked_blit(w_pomaranczowy,bufor_gra, 0,0,0,200,w_pomaranczowy->w,w_pomaranczowy->h);
	   draw_sprite(bufor_gra,kursor_gra1,mouse_x,mouse_y);
	   blit(bufor_gra, screen, 0,0,0,0, 640, 480);
	   rest(3000);
	   w_pom=1;
	   zapis();
	   menu men;
	   men.menu_glowne();
	}
	
	while((zajete_pole[59]==1)&&(zajete_pole[68]==1)&&(zajete_pole[69]==1)&&(zajete_pole[77]==1)&&
	   (zajete_pole[78]==1)&&(zajete_pole[79]==1)&&(zajete_pole[86]==1)&&(zajete_pole[87]==1)&&
	   (zajete_pole[88]==1)&&(zajete_pole[89]==1)&&(zajete_pole[95]==1)&&(zajete_pole[96]==1)&&
	   (zajete_pole[97]==1)&&(zajete_pole[98]==1)&&(zajete_pole[99]==1))
	{
		masked_blit(w_niebieski,bufor_gra, 0,0,0,200,w_niebieski->w,w_niebieski->h);
		draw_sprite(bufor_gra,kursor_gra1,mouse_x,mouse_y);
		blit(bufor_gra, screen, 0,0,0,0, 640, 480);
		rest(3000);
		w_nieb=1;
		zapis();
		menu men;
		men.menu_glowne();
	}
}

void DwochGraczy::sprawdzanie_pol()
{
	zajetosc_pol();
	//pole 0
	pola1(1, 2, 12, 0, 1, 2, 2, 3, 10, 12, 20, 22, 11, 13, 22, 25, 2, 3, 13, 0, 1, 3, 4, 14, 
		  2, 12, 13, 23, 10, 23, 24, 34, 20, 13, 14, 24, 11, 25, 26, 36, 22, 1);
	//pole 1
	pola2(2, 3, 13, 1, 0, 1, 2, 3, 3, 4, 11, 13, 21, 24, 10, 12, 12, 14, 23, 26,
		  1, 2, 12, 1, 0, 3, 4, 14, 2, 4, 5, 15, 3, 13, 14, 24, 11, 24, 25, 35, 
		  21, 12, 13, 23, 10, 14, 15, 25, 12, 26, 27, 37, 23, 2);
	//pole 2
	pola3(3, 4, 14, 2, 1, 2, 0, 1, 3, 4, 4, 5, 12, 14, 22, 25, 11, 13, 20, 23, 13, 15, 24, 27, 2, 3, 
		  13, 2, 1, 1, 2, 12, 0, 4, 5, 15, 3, 5, 6, 16, 4, 14, 15, 25, 12, 25, 26, 36, 22, 13, 14, 24, 
		  11, 23, 24, 34, 20, 15, 16, 26, 13, 27, 28, 38, 24, 3);
	//pole 3
	pola3(4, 5, 15, 3, 2, 3, 1, 2, 4, 5, 5, 6, 13, 15, 23, 26, 12, 14, 21, 24, 14, 16, 25, 28, 3, 4, 14, 
		  3, 2, 2, 3, 13, 1, 5, 6, 16, 4, 6, 7, 17, 5, 15, 16, 26, 13, 26, 27, 37, 23, 14, 15, 25, 12, 
		  24, 25, 35, 21, 16, 17, 27, 14, 28, 29, 39, 25, 4);
	//pole 4
	pola3(5, 6, 16, 4, 3, 4, 2, 3, 5, 6, 6, 7, 14, 16, 24, 27, 13, 15, 22, 25, 15, 17, 26, 29, 4, 5, 15,
		  4, 3, 3, 4, 14, 2, 6, 7, 17, 5, 7, 8, 18, 6, 16, 17, 27, 14, 27, 28, 38, 24, 15, 16, 26, 13, 
		  25, 26, 36, 22, 17, 18, 28, 15, 29, 30, 40, 26, 5);
	//pole 5
	pola3(6, 7, 17, 5, 4, 5, 3, 4, 6, 7, 7, 8, 15, 17, 25, 28, 14, 16, 23, 26, 16, 18, 27, 30, 5, 6, 16, 
		  5, 4, 4, 5, 15, 3, 7, 8, 18, 6, 8, 9, 19, 7, 17, 18, 28, 15, 28, 29, 39, 25, 16, 17, 27, 14, 
		  26, 27, 37, 23, 18, 19, 29, 16, 30, 31, 41, 27, 6);
	//pole 6
	pola3(7, 8, 18, 6, 5, 6, 4, 5, 7, 8, 8, 9, 16, 18, 26, 29, 15, 17, 24, 27, 17, 19, 28, 31, 6, 7, 
		  17, 6, 5, 5, 6, 16, 4, 8, 9, 19, 7, 9, 10, 20, 8, 18, 19, 29, 16, 29, 30, 40, 26, 17, 18, 
		  28, 15, 27, 28, 38, 24, 19, 20, 30, 17, 31, 32, 42, 28, 7);
	//pole 7
	pola3(8, 9, 19, 7, 6, 7, 5, 6, 8, 9, 9, 10, 17, 19, 27, 30, 16, 18, 26, 28, 18, 20, 29, 32, 7, 8, 
		18, 7, 6, 6, 7, 17, 5, 9, 10, 20, 8, 10, 11, 21, 9, 19, 20, 30, 17, 30, 31, 41, 27, 18, 19, 29, 
		16, 28, 29, 39, 25, 20, 21, 31, 18, 32, 33, 43, 29, 8);
	//pole 8
	pola2(9, 10, 20, 8, 9, 10, 7, 8, 6, 7, 18, 20, 28, 31, 19, 21, 17, 19, 26, 29,
		  10, 11, 21, 8, 9, 8, 9, 19, 7, 7, 8, 18, 6, 20, 21, 31, 18, 31, 32, 42, 
		  28, 21, 22, 33, 19, 19, 20, 30, 17, 29, 30, 40, 26, 9);
	//pole 9
	pola1(10, 11, 21, 9, 8, 9, 7, 8, 19, 21, 29, 32, 18, 20, 27, 30, 9, 10, 20, 9, 
		  8, 8, 9, 19, 7, 21, 22, 32, 19, 32, 33, 43, 29, 20, 21, 31, 18, 30, 31, 41, 27, 10);
	//pole10
	pola2(12, 13, 23, 10, 0, 1, 11, 13, 12, 14, 20, 23, 30, 34, 1, 2, 21, 24, 32, 36,
		  1, 2, 12, 10, 0, 13, 14, 24, 11, 14, 15, 25, 12, 23, 24, 34, 20, 34, 35, 45, 
		  30, 2, 3, 13, 1, 24, 25, 35, 21, 36, 37, 47, 32, 11);
	//pole 11
	pola4(13, 14, 24, 11, 10, 12, 12, 14, 13, 15, 1, 2, 21, 24, 31, 35, 0, 1, 2, 3, 20, 23, 22, 25, 
		  33, 37, 12, 13, 23, 11, 10, 2, 3, 13, 1, 14, 15, 25, 12, 15, 16, 26, 13, 24, 25, 35, 21, 35, 
		  36, 46, 31, 1, 2, 12, 0, 3, 4, 14, 2, 23, 24, 34, 20, 25, 26, 36, 22, 37, 38, 48, 33, 12);
	//pole 12
	pola5(14, 15, 25, 12, 11, 13, 10, 12, 2, 3, 13, 15, 14, 16, 22, 25, 32, 36, 1, 2, 3, 4, 21, 24, 
		  30, 34, 23, 26, 34, 38, 13, 14, 24, 12, 11, 12, 13, 23, 10, 3, 4, 14, 2, 15, 16, 26, 13, 16, 
		  17, 27, 14, 25, 26, 36, 22, 36, 37, 47, 32, 2, 3, 13, 1, 4, 5, 15, 3, 24, 25, 35, 21, 34, 35, 
		  45, 30, 26, 27, 37, 23, 38, 39, 49, 34, 13);
	//pole 13
	pola5(15, 16, 26, 13, 12, 14, 11, 13, 3, 4, 14, 16, 15, 17, 23, 26, 33, 37, 2, 3, 4, 5, 22, 25, 31, 
		  35, 24, 27, 35, 39, 14, 15, 25, 13, 12, 13, 14, 24, 11, 4, 5, 15, 3, 16, 17, 27, 14, 17, 18, 
		  28, 15, 26, 27, 37, 23, 37, 38, 48, 33, 3, 4, 14, 2, 5, 6, 16, 4, 25, 26, 36, 22, 35, 36, 46, 
		  31, 27, 28, 38, 24, 39, 40, 50, 35, 14);
	//pole 14
	pola5(16, 17, 27, 14, 13, 15, 12, 14, 4, 5, 15, 17, 16, 18, 24, 27, 34, 38, 3, 4, 5, 6, 23, 26, 32, 
		  36, 25, 28, 36, 40, 15, 16, 26, 14, 13, 14, 15, 25, 12, 5, 6, 16, 4, 17, 18, 28, 15, 18, 19, 
		  29, 16, 27, 28, 38, 24, 38, 39, 49, 34, 4, 5, 15, 3, 6, 7, 17, 5, 26, 27, 37, 23, 36, 37, 47, 
		  32, 28, 29, 39, 25, 40, 41, 51, 36, 15);
	//pole 15
	pola5(17, 18, 28, 15, 14, 16, 13, 15, 5, 6, 16, 18, 17, 19, 25, 28, 35, 39, 4, 5, 6, 7, 24, 27, 33, 
		  37, 26, 29, 37, 41, 16, 17, 27, 15, 14, 15, 16, 26, 13, 6, 7, 17, 5, 18, 19, 29, 16, 19, 20, 
		  30, 17, 28, 29, 39, 25, 39, 40, 50, 35, 5, 6, 16, 4, 7, 8, 18, 6, 27, 28, 38, 24, 37, 38, 48,
		  33, 29, 30, 40, 26, 41, 42, 52, 37, 16);
	//pole 16
	pola5(18, 19, 29, 16, 15, 17, 14, 16, 6, 7, 17, 19, 18, 20, 26, 29, 36, 40, 5, 6, 7, 8, 25, 28, 34, 
		  38, 27, 30, 38, 42, 17, 18, 28, 16, 15, 16, 17, 27, 14, 7, 8, 18, 6, 19, 20, 30, 17, 20, 21, 
		  31, 18, 29, 30, 40, 26, 40, 41, 51, 36, 6, 7, 17, 5, 8, 9, 19, 7, 28, 29, 39, 25, 38, 39, 49, 
		  34, 30, 31, 41, 27, 42, 43, 53, 38, 17);
	//pole 17
	pola5(19, 20, 30, 17, 16, 18, 15, 17, 7, 8, 18, 20, 19, 21, 27, 30, 37, 41, 6, 7, 8, 9, 26, 29, 35, 
		  39, 28, 31, 40, 43, 18, 19, 29, 17, 16, 17, 18, 28, 15, 8, 9, 19, 7, 20, 21, 31, 18, 21, 22, 
		  32, 19, 30, 31, 41, 27, 41, 42, 52, 37, 7, 8, 18, 6, 9, 10, 20, 8, 29, 30, 40, 26, 39, 40, 50,
		  35, 31, 32, 42, 28, 43, 44, 54, 39, 18);
	//pole 18
	pola4(20, 21, 31, 18, 19, 21, 17, 19, 16, 18, 8, 9, 28, 31, 38, 42, 7, 8, 9, 10, 29, 32, 27, 30, 36, 
		  40, 9, 10, 20, 18, 8, 21, 22, 32, 19, 31, 32, 42, 28, 42, 43, 53, 38, 19, 20, 30, 17, 18, 19, 
		  29, 16, 8, 9, 19, 7, 10, 11, 21, 9, 32, 33, 43, 29, 30, 31, 41, 27, 40, 41, 51, 36, 19);
	//pole 19
	pola2(21, 22, 32, 19, 9, 10, 18, 20, 17, 19, 29, 32, 39, 43, 8, 9, 28, 31, 37, 41,
		  10, 11, 21, 19, 9, 20, 21, 31, 18, 19, 20, 30, 17, 32, 33, 43, 29, 43, 44, 54, 
		  39, 9, 10, 20, 8, 31, 32, 42, 28, 41, 42, 52, 37, 20);
	//pole 20
	pola3(23, 24, 34, 20, 11, 13, 1, 2, 21, 24, 22, 25, 30, 34, 40, 45, 11, 13, 2, 3, 31, 
		  35, 42, 47, 12, 13, 23, 20, 10, 1, 2, 12, 0, 24, 25, 35, 21, 25, 26, 36, 22, 34, 
		  35, 45, 30, 45, 46, 56, 40, 13, 14, 24, 11, 3, 4, 14, 2, 35, 36, 46, 31, 47, 48, 58, 42, 21);
	//pole 21
	pola5(24, 25, 35, 21, 11, 13, 1, 2, 20, 23, 22, 25, 23, 26, 31, 35, 41, 46, 10, 12, 30, 34, 12, 14, 
		  3, 4, 32, 36, 43, 48, 13, 14, 24, 21, 11, 2, 3, 13, 1, 23, 24, 34, 20, 25, 26, 36, 22, 26, 
		  27, 37, 23, 35, 36, 46, 31, 46, 47, 57, 41, 12, 13, 23, 10, 34, 35, 45, 30, 14, 15, 25, 12, 
		  4, 5, 15, 3, 36, 37, 47, 32, 48, 49, 59, 43, 22);
	//pole 22
	pola6(25, 26, 36, 22, 21, 24, 20, 23, 12, 14, 2, 3, 23, 26, 24, 27, 32, 36, 42, 47, 11, 13, 0, 1, 
		  13, 15, 4, 5, 31, 35, 40, 45, 33, 37, 44, 49, 24, 25, 35, 22, 21, 23, 24, 34, 20, 14, 15, 25, 
		  12, 3, 4, 14, 2, 26, 27, 37, 23, 27, 28, 38, 24, 36, 37, 47, 32, 47, 48, 58, 42, 13, 14, 24, 
		  11, 1, 2, 12, 0, 15, 16, 26, 13, 5, 6, 16, 4, 35, 36, 46, 31, 45, 46, 56, 40, 37, 38, 48, 33, 
		  49, 50, 60, 44, 23);
	//pole 23
	pola6(26, 27, 37, 23, 22, 25, 21, 24, 13, 15, 3, 4, 24, 27, 25, 28, 33, 37, 43, 48, 12, 14, 1, 2, 
		  14, 16, 5, 6, 32, 36, 41, 46, 34, 38, 45, 50, 25, 26, 36, 23, 22, 24, 25, 35, 21, 15, 16, 26, 
		  13, 4, 5, 15, 3, 27, 28, 38, 24, 28, 29, 39, 25, 37, 38, 48, 33, 48, 49, 59, 43, 14, 15, 25, 
		  12, 2, 3, 13, 1, 16, 17, 27, 14, 6, 7, 17, 5, 36, 37, 47, 32, 46, 47, 57, 41, 38, 39, 49, 34, 
		  50, 51, 61, 45, 24);
	//pole 24
	pola6(27, 28, 38, 24, 23, 26, 22, 25, 14, 16, 4, 5, 25, 28, 26, 29, 34, 38, 44, 49, 13, 15, 2, 3, 
		  15, 17, 6, 7, 33, 37, 42, 47, 35, 39, 46, 51, 26, 27, 37, 24, 23, 25, 26, 36, 22, 16, 17, 27, 
		  14, 5, 6, 16, 4, 28, 29, 39, 25, 29, 30, 40, 26, 38, 39, 49, 34, 49, 50, 60, 44, 15, 16, 26, 
		  13, 3, 4, 14, 2, 17, 18, 28, 15, 7, 8, 18, 6, 37, 38, 47, 33, 47, 48, 58, 42, 39, 40, 50, 35, 
		  51, 52, 62, 46, 25);
	//pole 25
	pola6(28, 29, 39, 25, 24, 27, 23, 26, 15, 17, 5, 6, 26, 29, 27, 30, 35, 39, 45, 50, 14, 16, 3, 4, 
		  16, 18, 7, 8, 34, 38, 43, 48, 36, 40, 47, 52, 27, 28, 38, 25, 24, 26, 27, 37, 23, 17, 18, 28,
		  15, 6, 7, 17, 5, 29, 30, 40, 26, 30, 31, 41, 27, 39, 40, 50, 35, 50, 51, 61, 45, 16, 17, 27, 
		  14, 4, 5, 15, 3, 18, 19, 29, 16, 8, 9, 19, 7, 38, 39, 48, 34, 48, 49, 59, 43, 40, 41, 51, 36, 
		  52, 53, 63, 47, 26);
	//pole 26
	pola6(29, 30, 40, 26, 25, 28, 24, 27, 16, 18, 6, 7, 27, 30, 28, 31, 36, 40, 46, 51, 15, 17, 4, 5, 
		  17, 19, 8, 9, 35, 39, 44, 49, 37, 41, 48, 53, 28, 29, 39, 26, 25, 27, 28, 38, 24, 18, 19, 29, 
		  16, 7, 8, 18, 6, 30, 31, 41, 27, 31, 32, 42, 28, 40, 41, 51, 36, 51, 52, 62, 46, 17, 18, 28, 
		  15, 5, 6, 16, 4, 19, 20, 30, 17, 9, 10, 20, 8, 39, 40, 49, 35, 49, 50, 60, 44, 41, 42, 52, 37, 
		  53, 54, 64, 48, 27);
	//pole 27
	pola6(30, 31, 41, 27, 26, 29, 25, 28, 17, 19, 7, 8, 28, 31, 29, 32, 37, 41, 47, 52, 16, 18, 5, 6, 
		  18, 20, 9, 10, 36, 40, 45, 50, 38, 42, 49, 54, 29, 30, 40, 27, 26, 28, 29, 39, 25, 19, 20, 
		  30, 17, 8, 9, 19, 7, 31, 32, 42, 28, 32, 33, 43, 29, 41, 42, 52, 37, 52, 53, 63, 47, 18, 19, 
		  29, 17, 6, 7, 17, 5, 20, 21, 31, 18, 10, 11, 21, 9, 40, 41, 50, 36, 50, 51, 61, 45, 42, 43, 
		  53, 38, 54, 55, 65, 49, 28);
	//pole 28
	pola5(31, 32, 42, 28, 27, 30, 26, 29, 29, 32, 18, 20, 8, 9, 38, 42, 48, 53, 19, 21, 39, 43, 17, 19, 
		  6, 7, 37, 41, 46, 51, 20, 21, 31, 28, 18, 9, 10, 20, 8, 32, 33, 43, 29, 30, 31, 41, 27, 29, 30, 
		  40, 26, 42, 43, 53, 38, 53, 54, 64, 48, 21, 22, 32, 19, 43, 44, 54, 39, 19, 20, 30, 17, 7, 8, 
		  18, 6, 41, 42, 52, 37, 51, 52, 62, 46, 29);
	//pole 29
	pola3(32, 33, 43, 29, 28, 31, 27, 30, 19, 21, 9, 10, 39, 43, 49, 54, 18, 20, 7, 8, 38, 42, 47, 
		  52, 21, 22, 32, 29, 19, 10, 11, 21, 9, 31, 32, 42, 28, 30, 31, 41, 27, 43, 44, 54, 39, 
		  54, 55, 65, 49, 20, 21, 31, 18, 8, 9, 19, 7, 42, 43, 53, 38, 52, 53, 63, 47, 30);
	//pole 30
	pola3(34, 35, 45, 30, 20, 23, 10, 12, 31, 35, 32, 36, 40, 45, 50, 56, 21, 24, 12, 14, 41, 46, 
		  52, 58, 23, 24, 34, 30, 20, 12, 13, 23, 10, 35, 36, 46, 31, 36, 37, 47, 32, 45, 46, 56, 
		  40, 56, 57, 67, 50, 24, 25, 35, 21, 14, 15, 25, 12, 46, 47, 57, 41, 58, 59, 69, 52, 31);
	//pole 31
	pola5(35, 36, 46, 31, 21, 24, 11, 13, 30, 34, 32, 36, 33, 37, 41, 46, 51, 57, 20, 23, 40, 45, 22, 
		  25, 13, 15, 42, 47, 53, 59, 24, 25, 35, 31, 21, 13, 14, 24, 11, 34, 35, 45, 30, 36, 37, 47, 
		  32, 37, 38, 48, 33, 46, 47, 57, 41, 57, 58, 68, 51, 23, 24, 34, 20, 45, 46, 56, 40, 25, 26, 
		  36, 22, 15, 16, 26, 13, 47, 48, 58, 42, 59, 60, 70, 53, 32);
	//pole 32
	pola6(36, 37, 47, 32, 31, 35, 30, 34, 22, 25, 12, 14, 33, 37, 34, 38, 42, 47, 52, 58, 21, 24, 10, 
		  12, 23, 26, 14, 16, 41, 46, 50, 56, 43, 48, 54, 60, 35, 36, 46, 32, 31, 34, 35, 45, 30, 25, 
		  26, 36, 22, 14, 15, 25, 12, 37, 38, 48, 33, 38, 39, 49, 34, 47, 48, 58, 42, 58, 59, 69, 52, 
		  24, 25, 35, 21, 12, 13, 23, 10, 26, 27, 37, 23, 16, 17, 27, 14, 46, 47, 57, 41, 56, 57, 67, 
		  50, 48, 49, 59, 43, 60, 61, 71, 54, 33);
	//pole 33
	pola6(37, 38, 48, 33, 32, 36, 31, 35, 23, 26, 13, 15, 34, 38, 35, 39, 43, 48, 53, 59, 22, 25, 11, 
		  13, 24, 27, 15, 17, 42, 47, 51, 57, 44, 49, 55, 61, 36, 37, 47, 33, 32, 35, 36, 46, 31, 26, 
		  27, 37, 23, 15, 16, 26, 13, 38, 39, 49, 34, 39, 40, 50, 35, 48, 49, 59, 43, 59, 60, 70, 53, 
		  25, 26, 36, 22, 13, 14, 24, 11, 27, 28, 38, 24, 17, 18, 28, 15, 47, 48, 58, 42, 57, 58, 68, 
		  51, 49, 50, 60, 44, 61, 62, 72, 55, 34);
	//pole 34
	pola6(38, 39, 49, 34, 33, 37, 32, 36, 24, 27, 14, 16, 35, 39, 36, 40, 44, 49, 54, 60, 23, 26, 12, 
		  14, 25, 28, 16, 18, 43, 48, 52, 58, 45, 50, 56, 62, 37, 38, 48, 34, 33, 36, 37, 47, 32, 27, 
		  28, 38, 24, 16, 17, 27, 14, 39, 40, 50, 35, 40, 41, 51, 36, 49, 50, 60, 44, 60, 61, 71, 54, 
		  26, 27, 37, 23, 14, 15, 25, 12, 28, 29, 39, 25, 18, 19, 29, 16, 48, 49, 59, 43, 58, 59, 69, 
		  52, 50, 51, 61, 45, 62, 63, 73, 56, 35);
	//pole 35
	pola6(39, 40, 50, 35, 34, 38, 33, 37, 25, 28, 15, 17, 36, 40, 37, 41, 45, 50, 55, 61, 24, 27, 13, 
          15, 26, 29, 17, 19, 44, 49, 53, 59, 46, 51, 57, 63, 38, 39, 49, 35, 34, 37, 38, 48, 33, 28, 
		  29, 39, 25, 17, 18, 28, 15, 40, 41, 51, 36, 41, 42, 52, 37, 50, 51, 61, 45, 61, 62, 72, 55, 
		  27, 28, 38, 24, 15, 16, 26, 13, 29, 30, 40, 26, 19, 20, 30, 17, 49, 50, 60, 44, 59, 60, 70, 
		  53, 51, 52, 62, 46, 63, 64, 74, 57, 36);
	//pole 36
	pola6(40, 41, 51, 36, 35, 39, 34, 38, 26, 29, 16, 18, 37, 41, 38, 42, 46, 51, 56, 62, 25, 28, 14, 
		  16, 27, 30, 18, 20, 45, 50, 54, 60, 47, 52, 58, 64, 39, 40, 50, 36, 35, 38, 39, 49, 34, 29, 
		  30, 40, 26, 18, 19, 29, 16, 41, 42, 52, 37, 42, 43, 53, 38, 51, 52, 62, 46, 62, 63, 73, 56, 
		  28, 29, 39, 25, 16, 17, 27, 14, 30, 31, 41, 27, 20, 21, 31, 18, 50, 51, 61, 45, 60, 61, 71, 
		  54, 52, 53, 63, 47, 64, 65, 75, 58, 37);
	//pole 37
	pola6(41, 42, 52, 37, 36, 40, 35, 39, 27, 30, 17, 19, 38, 42, 39, 43, 47, 52, 57, 63, 26, 29, 15, 
		  17, 28, 31, 19, 21, 46, 51, 55, 61, 48, 53, 59, 65, 40, 41, 51, 37, 36, 39, 40, 50, 35, 30, 
		  31, 41, 27, 19, 20, 30, 17, 42, 43, 53, 38, 43, 44, 54, 39, 52, 53, 63, 47, 63, 64, 74, 57, 
		  29, 30, 40, 26, 17, 18, 28, 15, 31, 32, 42, 28, 21, 22, 32, 19, 51, 52, 62, 46, 61, 62, 72, 
		  55, 53, 54, 64, 48, 65, 66, 76, 59, 38);
	//pole 38
	pola5(42, 43, 53, 38, 37, 41, 36, 40, 39, 43, 28, 31, 18, 20, 48, 53, 58, 64, 29, 32, 49, 54, 27, 
		  30, 16, 18, 47, 52, 56, 62, 31, 32, 42, 38, 28, 20, 21, 31, 18, 43, 44, 54, 39, 41, 42, 52, 
		  37, 40, 41, 51, 36, 53, 54, 64, 48, 64, 65, 75, 58, 32, 33, 43, 29, 54, 55, 65, 49, 30, 31, 
		  41, 27, 18, 19, 29, 16, 52, 53, 63, 47, 62, 63, 73, 56, 39);
	//pole 39
	pola3(43, 44, 54, 39, 38, 42, 37, 41, 29, 32, 19, 21, 39, 54, 49, 54, 28, 31, 17, 19, 48, 53, 
		  57, 63, 32, 33, 43, 39, 29, 21, 22, 32, 19, 42, 43, 53, 38, 41, 42, 52, 37, 54, 55, 65, 
		  49, 65, 66, 76, 59, 31, 32, 42, 28, 19, 20, 30, 17, 53, 54, 64, 48, 63, 64, 74, 57, 40);
	//pole 40
	pola3(45, 46, 56, 40, 30, 34, 20, 23, 41, 46, 42, 47, 50, 56, 60, 67, 31, 35, 22, 25, 51, 57, 
		  62, 69, 34, 35, 45, 40, 30, 23, 24, 34, 20, 46, 47, 57, 41, 47, 48, 58, 42, 56, 57, 67, 
		  50, 67, 68, 78, 60, 35, 36, 46, 31, 25, 26, 36, 22, 57, 58, 68, 51, 69, 70, 80, 62, 41);
	//pole 41
	pola5(46, 47, 57, 41, 31, 35, 21, 24, 40, 45, 42, 47, 43, 48, 51, 57, 61, 68, 30, 34, 50, 56, 32,   
		  36, 23, 26, 52, 58, 63, 70, 35, 36, 46, 41, 31, 24, 25, 35, 21, 45, 46, 56, 40, 47, 48, 58, 
		  42, 48, 49, 59, 43, 57, 58, 68, 51, 68, 69, 79, 61, 34, 35, 45, 30, 56, 57, 67, 50, 36, 37, 
		  47, 32, 26, 27, 37, 23, 58, 59, 69, 52, 70, 71, 81, 63, 42);
	//pole 42
	pola6(47, 48, 58, 42, 41, 46, 40, 45, 32, 36, 22, 25, 43, 48, 44, 49, 52, 58, 62, 69, 31, 35, 20, 
		  23, 33, 37, 24, 27, 51, 57, 60, 67, 53, 59, 64, 71, 46, 47, 57, 42, 41, 45, 46, 56, 40, 36, 
		  37, 47, 32, 25, 26, 36, 22, 48, 49, 59, 43, 49, 50, 60, 44, 58, 59, 69, 52, 69, 70, 80, 62, 
		  35, 36, 46, 31, 23, 24, 34, 20, 37, 38, 48, 33, 27, 28, 38, 24, 57, 58, 68, 51, 67, 68, 78, 
		  60, 59, 60, 70, 53, 71, 72, 82, 64, 43);
	//pole 43
	pola6(48, 49, 59, 43, 42, 47, 41, 46, 33, 37, 23, 26, 44, 49, 45, 50, 53, 59, 63, 70, 32, 36, 21,
		  24, 34, 38, 25, 28, 52, 58, 61, 68, 54, 60, 65, 72, 47, 48, 58, 43, 42, 46, 47, 57, 41, 37, 
		  38, 48, 33, 26, 27, 37, 23, 49, 50, 60, 44, 50, 51, 61, 45, 59, 60, 70, 53, 70, 71, 81, 63, 
		  36, 37, 47, 32, 24, 25, 35, 21, 38, 39, 49, 34, 28, 29, 39, 25, 58, 59, 69, 52, 68, 69, 79, 
		  61, 60, 61, 71, 54, 72, 73, 83, 65, 44);
	//pole 44
	pola6(49, 50, 60, 44, 43, 48, 42, 47, 34, 38, 24, 27, 45, 50, 46, 51, 54, 60, 64, 71, 33, 37, 22, 
		  25, 35, 39, 26, 29, 53, 59, 62, 69, 55, 61, 66, 73, 48, 49, 59, 44, 43, 47, 48, 58, 42, 38, 
		  39, 49, 34, 27, 28, 38, 24, 50, 51, 61, 45, 51, 52, 62, 46, 60, 61, 71, 54, 71, 72, 82, 64, 
		  37, 38, 48, 33, 25, 26, 36, 22, 39, 40, 50, 35, 29, 30, 40, 26, 59, 60, 70, 53, 69, 70, 80, 
		  62, 61, 62, 72, 55, 73, 74, 84, 66, 45);
	//pole 45
	pola6(50, 51, 61, 45, 44, 49, 43, 48, 35, 39, 25, 28, 46, 51, 47, 52, 55, 61, 65, 72, 34, 38, 23, 
		  26, 36, 40, 27, 30, 54, 60, 63, 70, 56, 62, 67, 74, 49, 50, 60, 45, 44, 48, 49, 59, 43, 39, 
		  40, 50, 35, 28, 29, 39, 25, 51, 52, 62, 46, 52, 53, 63, 47, 61, 62, 72, 55, 72, 73, 83, 65, 
		  38, 39, 49, 34, 26, 27, 37, 23, 40, 41, 51, 36, 30, 31, 41, 27, 60, 61, 71, 54, 70, 71, 81, 
		  63, 62, 63, 73, 56, 74, 75, 85, 67, 46);
	//pole 46
	pola6(51, 52, 62, 46, 45, 50, 44, 49, 36, 40, 26, 29, 47, 52, 48, 53, 56, 62, 66, 73, 35, 39, 24, 
		  27, 37, 41, 28, 31, 55, 61, 64, 71, 57, 63, 68, 75, 50, 51, 61, 46, 45, 49, 50, 60, 44, 40, 
		  41, 51, 36, 29, 30, 40, 26, 52, 53, 63, 47, 53, 54, 64, 48, 62, 63, 73, 56, 73, 74, 84, 66, 
		  39, 40, 50, 35, 27, 28, 38, 24, 41, 41, 52, 37, 31, 32, 42, 38, 61, 62, 72, 55, 71, 72, 82, 
		  64, 63, 64, 74, 57, 75, 76, 86, 68, 47);
	//pole 47
	pola6(52, 53, 63, 47, 46, 51, 45, 50, 37, 41, 27, 30, 48, 53, 49, 54, 57, 63, 67, 74, 36, 40, 25, 
		  28, 38, 42, 29, 32, 56, 62, 65, 72, 58, 64, 69, 76, 51, 52, 62, 47, 46, 50, 51, 61, 45, 41, 
		  42, 52, 37, 30, 31, 41, 27, 53, 54, 64, 48, 54, 55, 65, 49, 63, 64, 74, 57, 74, 75, 85, 67, 
		  40, 41, 51, 36, 28, 29, 39, 25, 42, 42, 53, 38, 32, 33, 43, 39, 62, 63, 73, 56, 72, 73, 83, 
		  65, 64, 65, 75, 58, 76, 77, 87, 69, 48);
	//pole 48
	pola5(53, 54, 64, 48, 47, 52, 46, 51, 49, 54, 38, 42, 28, 31, 58, 64, 68, 75, 39, 43, 59, 65, 37, 
		  41, 26, 29, 57, 63, 66, 73, 42, 43, 53, 48, 38, 31, 32, 42, 28, 54, 55, 65, 49, 52, 53, 63, 
		  47, 51, 52, 62, 46, 64, 65, 75, 58, 75, 76, 86, 68, 43, 44, 54, 39, 65, 66, 76, 59, 41, 42, 
		  52, 37, 29, 30, 40, 26, 63, 64, 74, 57, 73, 74, 84, 66, 49);
	//pole 49
	pola3(54, 55, 65, 49, 48, 53, 47, 52, 39, 43, 29, 32, 59, 65, 69, 76, 38, 42, 27, 30, 58, 64, 67, 
		  74, 43, 44, 54, 49, 39, 32, 33, 43, 29, 53, 54, 64, 48, 52, 53, 63, 47, 65, 66, 76, 59, 76, 
		  77, 87, 69, 42, 43, 53, 38, 30, 31, 41, 27, 64, 65, 75, 58, 74, 75, 85, 67, 50);
	//pole 50
	pola3(56, 57, 67, 50, 40, 45, 30, 34, 51, 57, 52, 58, 60, 67, 70, 78, 41, 46, 32, 36, 61, 68, 72, 
		  78, 45, 46, 56, 50, 40, 34, 35, 45, 30, 57, 58, 68, 51, 58, 59, 69, 52, 67, 68, 78, 60, 78, 
		  79, 89, 70, 46, 47, 57, 41, 36, 37, 47, 32, 68, 69, 79, 61, 80, 81, 91, 72, 51);
	//pole 51
	pola5(57, 58, 68, 51, 41, 46, 31, 35, 50, 56, 52, 58, 53, 59, 61, 68, 71, 79, 40, 45, 60, 67, 42, 
		  47, 33, 37, 62, 69, 73, 81, 46, 47, 57, 51, 41, 35, 36, 46, 31, 56, 57, 67, 50, 58, 59, 69, 
		  52, 59, 60, 70, 53, 68, 69, 79, 61, 79, 80, 90, 71, 45, 46, 56, 40, 67, 68, 78, 60, 47, 48, 
          58, 42, 37, 38, 48, 33, 69, 70, 80, 62, 81, 82, 92, 73, 52);
	//pole 52
	pola6(58, 59, 69, 52, 51, 57, 50, 56, 42, 47, 32, 36, 53, 59, 54, 60, 62, 69, 72, 80, 41, 46, 30, 
		  34, 43, 48, 34, 38, 61, 68, 70, 78, 63, 70, 74, 82, 57, 58, 68, 52, 51, 56, 57, 67, 50, 47, 
		  48, 58, 42, 36, 37, 47, 32, 59, 60, 70, 53, 60, 61, 71, 54, 69, 70, 80, 62, 80, 81, 91, 72, 
		  46, 47, 57, 41, 34, 35, 45, 30, 48, 49, 59, 43, 38, 39, 49, 34, 68, 69, 79, 61, 78, 79, 89, 
		  70, 70, 71, 81, 63, 82, 83, 93, 74, 53);
	//pole 53
	pola6(59, 60, 70, 53, 52, 58, 51, 57, 43, 48, 33, 37, 54, 60, 55, 61, 63, 70, 73, 81, 42, 47, 31, 
		  35, 44, 49, 35, 39, 62, 69, 71, 79, 64, 71, 75, 83, 58, 59, 69, 53, 52, 57, 58, 68, 51, 48, 
		  49, 59, 43, 37, 38, 48, 33, 60, 61, 71, 54, 61, 62, 72, 55, 70, 71, 81, 63, 81, 82, 92, 73, 
		  47, 48, 58, 42, 35, 36, 46, 31, 49, 50, 60, 44, 39, 40, 50, 35, 69, 70, 80, 62, 79, 80, 90, 
		  71, 71, 72, 82, 64, 83, 84, 94, 75, 54);
	//pole 54
	pola6(60, 61, 71, 54, 53, 59, 52, 58, 44, 49, 34, 38, 55, 61, 56, 62, 64, 71, 74, 82, 43, 48, 32, 
		  36, 45, 50, 36, 40, 63, 70, 72, 80, 65, 72, 76, 84, 59, 60, 70, 54, 53, 58, 59, 69, 52, 49, 
		  50, 60, 44, 38, 39, 49, 34, 61, 62, 72, 55, 62, 63, 73, 56, 71, 72, 82, 64, 82, 83, 93, 74, 
		  48, 49, 59, 43, 36, 37, 47, 32, 50, 51, 61, 45, 40, 41, 51, 36, 70, 71, 81, 63, 80, 81, 91, 
		  72, 72, 73, 83, 65, 84, 85, 95, 76, 55);
	//pole 55
	pola6(61, 62, 72, 55, 54, 60, 53, 59, 45, 50, 35, 39, 56, 62, 57, 63, 65, 72, 75, 83, 44, 49, 33, 
		  37, 46, 51, 37, 41, 64, 71, 73, 81, 66, 73, 77, 85, 60, 61, 71, 55, 54, 59, 60, 70, 53, 50, 
		  51, 61, 45, 39, 40, 50, 35, 62, 63, 73, 56, 63, 64, 74, 57, 72, 73, 83, 65, 83, 84, 94, 75, 
		  49, 50, 60, 44, 37, 38, 48, 33, 51, 52, 62, 46, 41, 42, 52, 37, 71, 72, 82, 64, 81, 82, 92, 
		  73, 73, 74, 84, 66, 85, 86, 96, 77, 56);
	//pole 56
	pola6(62, 63, 73, 56, 55, 61, 54, 60, 46, 51, 36, 40, 57, 63, 58, 64, 66, 73, 76, 84, 45, 50, 34, 
		  38, 47, 52, 38, 42, 65, 72, 74, 82, 67, 74, 78, 86, 61, 62, 72, 56, 55, 60, 61, 71, 54, 51, 
		  52, 62, 46, 40, 41, 51, 36, 63, 64, 74, 57, 64, 65, 75, 58, 73, 74, 84, 66, 84, 85, 95, 76, 
		  50, 51, 61, 45, 38, 39, 49, 34, 52, 53, 63, 47, 42, 43, 53, 38, 72, 73, 83, 65, 82, 83, 93, 
		  74, 74, 75, 85, 67, 86, 87, 97, 78, 57);
	//pole 57
	pola6(63, 64, 74, 57, 56, 62, 55, 61, 47, 52, 37, 41, 58, 64, 59, 65, 67, 74, 77, 85, 46, 51, 35, 
		  39, 48, 53, 39, 43, 66, 73, 75, 83, 68, 75, 79, 87, 62, 63, 73, 57, 56, 61, 62, 72, 55, 52, 
		  53, 63, 47, 41, 42, 52, 37, 64, 65, 75, 58, 65, 66, 76, 59, 74, 75, 85, 67, 85, 86, 96, 77, 
		  51, 52, 62, 46, 39, 40, 50, 35, 53, 54, 64, 48, 43, 44, 54, 39, 73, 74, 84, 66, 83, 84, 94, 
		  75, 75, 76, 86, 68, 87, 88, 98, 79, 58);
	//pole 58
	pola5(64, 65, 75, 58, 57, 63, 56, 62, 59, 65, 48, 53, 38, 42, 68, 75, 78, 86, 49, 54, 69, 76, 47, 
		  52, 36, 40, 67, 74, 76, 84, 53, 54, 64, 58, 48, 42, 43, 53, 38, 65, 66, 76, 59, 63, 64, 74, 
		  57, 62, 63, 73, 56, 75, 76, 86, 68, 86, 87, 97, 78, 54, 55, 65, 49, 76, 77, 87, 69, 52, 53, 
		  63, 47, 40, 41, 51, 36, 74, 75, 85, 67, 84, 85, 95, 76, 59);
	//pole 59
	pola3(65, 66, 76, 59, 58, 64, 57, 63, 49, 54, 39, 43, 69, 76, 79, 87, 48, 53, 37, 41, 68, 75, 77, 
		  85, 54, 55, 65, 59, 49, 43, 44, 54, 39, 64, 65, 75, 58, 63, 64, 74, 57, 76, 77, 87, 69, 87, 
		  88, 98, 79, 53, 54, 64, 48, 41, 42, 52, 37, 75, 76, 86, 68, 85, 86, 96, 77, 60);
	//pole 60
	pola3(67, 68, 78, 60, 50, 56, 40, 45, 61, 68, 62, 69, 70, 78, 80, 89, 51, 57, 42, 47, 71, 79, 82, 
		  91, 56, 57, 67, 60, 50, 45, 46, 56, 40, 68, 69, 79, 61, 69, 70, 80, 62, 78, 79, 89, 70, 89, 
		  90, 100, 80, 57, 58, 68, 51, 47, 48, 58, 42, 79, 80, 90, 71, 91, 92, 102, 82, 61);
	//pole 61
	pola5(68, 69, 79, 61, 51, 57, 41, 46, 60, 67, 62, 69, 63, 70, 71, 79, 81, 90, 50, 56, 70, 78, 52, 
		  58, 43, 48, 72, 80, 83, 92, 57, 58, 68, 61, 51, 46, 47, 57, 41, 67, 68, 78, 60, 69, 70, 80, 
		  62, 70, 71, 81, 63, 79, 80, 90, 71, 90, 91, 101, 81, 56, 57, 67, 50, 78, 79, 89, 70, 58, 59, 
		  69, 52, 48, 49, 59, 43, 80, 81, 91, 72, 92, 93, 103, 83, 62);
	//pole 62
	pola6(69, 70, 80, 62, 61, 68, 60, 67, 52, 58, 42, 47, 63, 70, 64, 71, 72, 80, 82, 91, 51, 57, 40, 
		  45, 53, 59, 44, 49, 71, 79, 80, 89, 73, 81, 84, 93, 68, 69, 79, 62, 61, 67, 68, 78, 60, 58, 
		  59, 69, 52, 47, 48, 58, 42, 70, 71, 81, 63, 71, 72, 82, 64, 80, 81, 91, 72, 91, 92, 102, 82, 
		  57, 58, 68, 51, 45, 46, 56, 40, 59, 60, 70, 53, 49, 50, 60, 44, 79, 80, 90, 71, 89, 90, 100, 
		  80, 81, 82, 92, 73, 93, 94, 104, 84, 63);
	//pole 63
	pola6(70, 71, 81, 63, 62, 69, 61, 68, 53, 59, 43, 48, 64, 71, 65, 72, 73, 81, 83, 92, 52, 58, 41, 
		  46, 54, 60, 45, 50, 72, 80, 81, 90, 74, 82, 85, 94, 69, 70, 80, 63, 62, 68, 69, 79, 61, 59, 
		  60, 70, 53, 48, 49, 59, 43, 71, 72, 82, 64, 72, 73, 83, 65, 81, 82, 92, 73, 92, 93, 103, 83, 
		  58, 59, 69, 52, 46, 47, 57, 41, 60, 61, 71, 54, 50, 51, 61, 45, 80, 81, 91, 72, 90, 91, 101, 
		  81, 82, 83, 93, 74, 94, 95, 105, 85, 64);
	//pole 64
	pola6(71, 72, 82, 64, 63, 70, 62, 69, 54, 60, 44, 49, 65, 72, 66, 73, 74, 82, 84, 93, 53, 59, 42, 
		  47, 55, 61, 46, 51, 73, 81, 82, 91, 75, 83, 86, 95, 70, 71, 81, 64, 63, 69, 70, 80, 62, 60, 
		  61, 71, 54, 49, 50, 60, 44, 72, 73, 83, 65, 73, 74, 84, 66, 82, 83, 93, 74, 93, 94, 104, 84, 
		  59, 60, 70, 53, 47, 48, 58, 42, 61, 62, 72, 55, 51, 52, 62, 46, 81, 82, 92, 73, 91, 92, 102, 
		  82, 83, 84, 94, 75, 95, 96, 106, 86, 65);
	//pole 65
	pola6(72, 73, 83, 65, 64, 71, 63, 70, 55, 61, 45, 50, 66, 73, 67, 74, 75, 83, 85, 94, 54, 60, 43, 
		  48, 56, 62, 47, 52, 74, 82, 83, 92, 76, 84, 87, 96, 71, 72, 82, 65, 64, 70, 71, 81, 63, 61, 
		  62, 72, 55, 50, 51, 61, 45, 73, 74, 84, 66, 74, 75, 85, 67, 83, 84, 94, 75, 94, 95, 105, 85,
		  60, 61, 71, 54, 48, 49, 59, 43, 62, 63, 73, 56, 52, 53, 63, 47, 82, 83, 93, 74, 92, 93, 103,
		  83, 84, 85, 95, 76, 96, 97, 107, 87, 66);
	//pole 66
	pola6(73, 74, 84, 66, 65, 72, 64, 71, 56, 62, 46, 51, 67, 74, 68, 75, 76, 84, 86, 95, 55, 61, 44, 
		  49, 57, 63, 48, 53, 75, 83, 84, 93, 77, 85, 88, 97, 72, 73, 83, 66, 65, 71, 72, 82, 64, 62, 
		  63, 73, 56, 51, 52, 62, 46, 74, 75, 85, 67, 75, 76, 86, 68, 84, 85, 95, 76, 95, 96, 106, 86,
		  61, 62, 72, 55, 49, 50, 60, 44, 63, 64, 74, 57, 53, 54, 64, 48, 83, 84, 94, 75, 93, 94, 104,
		  84, 85, 86, 96, 77, 97, 98, 108, 88, 67);
	//pole 67
	pola6(74, 75, 85, 67, 66, 73, 65, 72, 57, 63, 47, 52, 68, 75, 69, 76, 77, 85, 87, 96, 56, 62, 45, 
		  50, 58, 64, 49, 54, 76, 84, 85, 94, 78, 86, 89, 98, 73, 74, 84, 67, 66, 72, 73, 83, 65, 63, 
		  64, 74, 57, 52, 53, 63, 47, 75, 76, 86, 68, 76, 77, 87, 69, 85, 86, 96, 77, 96, 97, 107, 87, 
		  62, 63, 73, 56, 50, 51, 61, 45, 64, 65, 75, 58, 54, 55, 65, 49, 84, 85, 95, 76, 94, 95, 105, 
		  85, 86, 87, 97, 78, 98, 99, 109, 89, 68);
	//pole 68
	pola5(75, 76, 86, 68, 67, 74, 66, 73, 69, 76, 58, 64, 48, 53, 78, 86, 88, 97, 59, 65, 79, 87, 57, 
		  63, 46, 51, 77, 85, 86, 95, 64, 65, 75, 68, 58, 53, 54, 64, 48, 76, 77, 87, 69, 74, 75, 85, 
		  67, 73, 74, 84, 66, 86, 87, 97, 78, 97, 98, 108, 88, 65, 66, 76, 59, 87, 88, 98, 79, 63, 64, 
		  74, 57, 51, 52, 62, 46, 85, 86, 96, 77, 95, 96, 106, 86, 69);
	//pole 69
	pola3(76, 77, 87, 69, 68, 75, 67, 74, 59, 65, 49, 54, 79, 87, 89, 98, 58, 64, 47, 52, 78, 86, 87, 
		  96, 65, 66, 76, 69, 59, 54, 55, 65, 49, 75, 76, 86, 68, 74, 75, 85, 67, 87, 88, 98, 79, 98, 
		  99, 109, 89, 64, 65, 75, 58, 52, 53, 63, 47, 86, 87, 97, 78, 96, 97, 107, 87, 70);
	//pole 70
	pola3(78, 79, 89, 70, 60, 67, 50, 56, 71, 79, 72, 80, 80, 89, 90, 100, 61, 68, 52, 58, 81, 90, 92, 
		  102, 67, 68, 78, 70, 60, 56, 57, 67, 50, 79, 80, 90, 71, 80, 81, 91, 72, 89, 90, 100, 80, 100, 
		  101, 111, 90, 68, 69, 79, 61, 58, 59, 69, 52, 90, 91, 101, 81, 102, 103, 113, 92, 71);
	//pole 71
	pola5(79, 80, 90, 71, 61, 68, 51, 57, 70, 78, 72, 80, 73, 81, 81, 90, 91, 101, 60, 67, 80, 89, 62, 
		  69, 53, 59, 82, 91, 93, 103, 68, 69, 79, 71, 61, 57, 58, 68, 51, 78, 79, 89, 70, 80, 81, 91, 
		  72, 81, 82, 92, 73, 90, 91, 101, 81, 101, 102, 112, 91, 67, 68, 78, 60, 89, 90, 100, 80, 69, 
		  70, 80, 62, 59, 60, 70, 53, 91, 92, 102, 82, 103, 104, 114, 93, 72);
	//pole 72
	pola6(80, 81, 91, 72, 71, 79, 70, 78, 62, 69, 52, 58, 73, 81, 74, 82, 82, 91, 92, 102, 61, 68, 50, 
		  56, 63, 70, 54, 60, 81, 90, 90, 100, 83, 92, 94, 104, 79, 80, 90, 72, 71, 78, 79, 89, 70, 69, 
		  70, 80, 62, 58, 59, 69, 52, 81, 82, 92, 73, 82, 83, 93, 74, 91, 92, 102, 82, 102, 103, 113, 
		  92, 68, 69, 79, 61, 56, 57, 67, 50, 70, 71, 81, 63, 60, 61, 71, 54, 90, 91, 101, 81, 100, 
		  101, 111, 90, 92, 93, 103, 83, 104, 105, 115, 94, 73);
	//pole 73
	pola6(81, 82, 92, 73, 72, 80, 71, 79, 63, 70, 53, 59, 74, 82, 75, 83, 83, 92, 93, 103, 62, 69, 51, 
		  57, 64, 71, 55, 61, 82, 91, 91, 101, 84, 93, 95, 105, 80, 81, 91, 73, 72, 79, 80, 90, 71, 70, 
		  71, 81, 63, 59, 60, 70, 53, 82, 83, 93, 74, 83, 84, 94, 75, 92, 93, 103, 83, 103, 104, 114, 
		  93, 69, 70, 80, 62, 57, 58, 68, 51, 71, 72, 82, 64, 61, 62, 72, 55, 91, 92, 102, 82, 101, 
		  102, 112, 91, 93, 94, 104, 84, 105, 106, 116, 95, 74);
	//pole 74
	pola6(82, 83, 93, 74, 73, 81, 72, 80, 64, 71, 54, 60, 75, 83, 76, 84, 84, 93, 94, 104, 63, 70, 52, 
		  58, 65, 72, 56, 62, 83, 92, 92, 102, 85, 94, 96, 106, 81, 82, 92, 74, 73, 80, 81, 91, 72, 71, 
		  72, 82, 64, 60, 61, 71, 54, 83, 84, 94, 75, 84, 85, 95, 76, 93, 94, 104, 84, 104, 105, 115, 
		  94, 70, 71, 81, 63, 58, 59, 69, 52, 72, 73, 83, 65, 62, 63, 73, 56, 92, 93, 103, 83, 102, 103, 
		  113, 92, 94, 95, 105, 85, 106, 107, 117, 96, 75);
	//pole 75
	pola6(83, 84, 94, 75, 74, 82, 73, 81, 65, 72, 55, 61, 76, 84, 77, 85, 85, 94, 95, 105, 64, 71, 53, 
		  59, 66, 73, 57, 63, 84, 93, 93, 103, 86, 95, 97, 107, 82, 83, 93, 75, 74, 81, 82, 92, 73, 72, 
		  73, 83, 65, 61, 62, 72, 55, 84, 85, 95, 76, 85, 86, 96, 77, 94, 95, 105, 85, 105, 106, 116, 
		  95, 71, 72, 82, 64, 59, 60, 70, 53, 73, 74, 84, 66, 63, 64, 74, 57, 93, 94, 104, 84, 103, 104, 
		  114, 93, 95, 96, 106, 86, 107, 108, 118, 97, 76);
	//pole 76
	pola6(84, 85, 95, 76, 75, 83, 74, 82, 66, 73, 56, 62, 77, 85, 78, 86, 86, 95, 96, 106, 65, 72, 54, 
		  60, 67, 74, 58, 64, 85, 94, 94, 104, 87, 96, 98, 108, 83, 84, 94, 76, 75, 82, 83, 93, 74, 73, 
		  74, 84, 66, 62, 63, 73, 56, 85, 86, 96, 77, 86, 87, 97, 78, 95, 96, 106, 86, 106, 107, 117, 
		  96, 72, 73, 83, 65, 60, 61, 71, 54, 74, 75, 85, 67, 64, 65, 75, 58, 94, 95, 105, 85, 104, 105, 
		  115, 94, 96, 97, 107, 87, 108, 109, 119, 98, 77);
	//pole 77
	pola6(85, 86, 96, 77, 76, 84, 75, 83, 67, 74, 57, 63, 78, 86, 79, 87, 87, 96, 97, 107, 66, 73, 55, 
		  61, 68, 75, 59, 65, 86, 95, 95, 105, 88, 97, 99, 109, 84, 85, 95, 77, 76, 83, 84, 94, 75, 74, 
		  75, 85, 67, 63, 64, 74, 57, 86, 87, 97, 78, 87, 88, 98, 79, 96, 97, 107, 87, 107, 108, 118, 
		  97, 73, 74, 84, 66, 61, 62, 72, 55, 75, 76, 86, 68, 65, 66, 76, 59, 95, 96, 106, 86, 105, 106,
		  116, 95, 97, 98, 108, 88, 109, 110, 120, 99, 78);
	//pole 78
	pola5(86, 87, 97, 78, 77, 85, 76, 84, 79, 87, 68, 75, 58, 64, 88, 97, 98, 108, 69, 76, 89, 98, 67, 
		  74, 56, 62, 87, 96, 96, 106, 75, 76, 86, 78, 68, 64, 65, 75, 58, 87, 88, 98, 79, 97, 98, 108, 
		  88, 108, 109, 119, 98, 85, 86, 96, 77, 84, 85, 95, 76, 76, 77, 87, 69, 98, 99, 109, 89, 74, 
		  75, 85, 67, 62, 63, 73, 56, 96, 97, 107, 87, 106, 107, 117, 96, 79);
	//pole 79
	pola3(87, 88, 98, 79, 78, 86, 77, 85, 69, 76, 59, 65, 89, 98, 99, 109, 68, 75, 57, 63, 88, 97, 97, 
		  107, 76, 77, 87, 79, 69, 65, 66, 76, 59, 86, 87, 97, 78, 85, 86, 96, 77, 98, 99, 109, 89, 
		  109, 110, 120, 99, 75, 76, 86, 68, 63, 64, 74, 57, 97, 98, 1088, 88, 107, 108, 118, 97, 80);
	//pole 80
	pola2(89, 90, 100, 80, 90, 100, 70, 78, 60, 67, 81, 90, 82, 91, 91, 101, 71, 79, 62, 69,
		  100, 101, 111, 80, 90, 90, 91, 101, 81, 91, 92, 102, 82, 78, 79, 89, 70, 67, 68, 78, 
		  60, 101, 102, 112, 91, 79, 80, 90, 71, 69, 70, 80, 62, 81);
	//pole 81
	pola4(90, 91, 101, 81, 80, 89, 71, 79, 61, 68, 91, 101, 82, 91, 83, 92, 70, 78, 90, 100, 92, 102,
		  72, 80, 63, 70, 89, 90, 100, 81, 80, 101, 102, 112, 91, 79, 80, 90, 71, 68, 69, 79, 61, 91, 92, 
		  102, 82, 92, 93, 103, 83, 78, 79, 89, 70, 100, 101, 111, 90, 102, 103, 113, 92, 80, 81, 91, 72,
		  70, 71, 81, 63, 82);
	//pole 82
	pola5(91, 92, 102, 82, 81, 90, 80, 89, 92, 102, 72, 80, 62, 69, 83, 92, 84, 93, 91, 101, 93, 103, 
		  71, 79, 60, 67, 73, 81, 64, 71, 90, 91, 101, 82, 81, 89, 90, 100, 80, 102, 103, 113, 92, 92, 
		  93, 103, 83, 93, 94, 104, 84, 80, 81, 91, 72, 69, 70, 80, 62, 101, 102, 112, 91, 103, 104, 
		  114, 93, 79, 80, 90, 71, 67, 68, 78, 60, 81, 82, 92, 73, 71, 72, 82, 64, 83);
	//pole 83
	pola5(92, 93, 103, 83, 82, 91, 81, 90, 93, 103, 73, 81, 63, 70, 84, 93, 85, 94, 92, 102, 94, 104, 
		  72, 80, 61, 68, 74, 82, 65, 72, 91, 92, 102, 83, 82, 90, 91, 101, 81, 103, 104, 114, 93, 93, 
		  94, 104, 84, 94, 95, 105, 85, 81, 82, 92, 73, 70, 71, 81, 63, 102, 103, 113, 92, 104, 105, 
		  115, 94, 80, 81, 91, 72, 68, 69, 79, 61, 82, 83, 93, 74, 72, 73, 83, 65, 84);
	//pole 84
	pola5(93, 94, 104, 84, 83, 92, 82, 91, 94, 104, 74, 82, 64, 71, 85, 94, 86, 95, 93, 103, 95, 105, 
		  73, 81, 62, 69, 75, 83, 66, 73, 92, 93, 103, 84, 83, 91, 92, 102, 82, 104, 105, 115, 94, 94, 
		  95, 105, 85, 95, 96, 106, 86, 82, 83, 93, 74, 71, 72, 82, 64, 103, 104, 114, 93, 105, 106, 
		  116, 95, 81, 82, 92, 73, 69, 70, 80, 62, 83, 84, 94, 75, 73, 74, 84, 66, 85);
	//pole 85
	pola5(94, 95, 105, 85, 84, 93, 83, 92, 95, 105, 75, 83, 65, 72, 86, 95, 87, 96, 94, 104, 96, 106,
		  74, 82, 63, 70, 76, 84, 67, 74, 93, 94, 104, 85, 84, 92, 93, 103, 83, 105, 106, 116, 95, 94,
		  96, 106, 86, 96, 97, 107, 87, 83, 84, 94, 75, 72, 73, 83, 65, 104, 105, 115, 94, 106, 107, 
		  117, 96, 82, 83, 93, 74, 70, 71, 81, 63, 84, 85, 95, 76, 74, 75, 85, 67, 86);
	//pole 86
	pola5(95, 96, 106, 86, 85, 94, 84, 93, 96, 106, 76, 84, 66, 73, 87, 96, 88, 97, 95, 105, 97, 107,
		  75, 83, 64, 71, 77, 85, 68, 75, 94, 95, 105, 86, 85, 93, 94, 104, 84, 106, 107, 117, 96, 95,
		  97, 107, 87, 97, 98, 108, 88, 84, 85, 95, 76, 73, 74, 84, 66, 105, 106, 116, 95, 107, 108, 
		  118, 97, 83, 84, 94, 75, 71, 72, 82, 64, 85, 86, 96, 77, 75, 76, 86, 68, 87);
	//pole 87
	pola5(96, 97, 107, 87, 86, 95, 85, 94, 97, 107, 77, 85, 67, 74, 88, 97, 89, 98, 96, 106, 98, 108,
		  76, 84, 65, 72, 78, 86, 69, 76, 95, 96, 106, 87, 86, 94, 95, 105, 85, 107, 108, 118, 97, 96,
		  98, 108, 88, 98, 99, 109, 89, 85, 86, 96, 77, 74, 75, 85, 67, 106, 107, 117, 96, 108, 109,
		  119, 98, 84, 85, 95, 76, 72, 73, 83, 65, 86, 87, 97, 78, 76, 77, 87, 69, 88);
	//pole 88
	pola4(97, 98, 108, 88, 89, 98, 87, 96, 86, 95, 98, 108, 78, 86, 68, 75, 79, 87, 99, 109, 97, 107, 
		  77, 85, 66, 73, 98, 99, 109, 88, 89, 108, 109, 119, 98, 86, 87, 97, 78, 75, 76, 86, 68, 96, 
		  97, 107, 87, 95, 96, 106, 86, 87, 88, 98, 79, 107, 108, 118, 97, 109, 110, 120, 99, 85, 86, 
		  96, 77, 73, 74, 84, 66, 89);
	//pole 89
	pola2(98, 99, 109, 89, 99, 109, 88, 97, 87, 96, 79, 87, 69, 76, 98, 108, 78, 86, 67, 74,
		  109, 110, 120, 89, 99, 97, 98, 108, 88, 96, 97, 107, 87, 87, 88, 98, 79, 76, 77, 87, 
		  69, 108, 109, 119, 98, 86, 87, 97, 78, 74, 75, 85, 67, 90); 
	//pole 90
	pola1(100, 101, 111, 90, 80, 89, 70, 78, 91, 101, 92, 102, 81, 90, 72, 80, 89, 90, 100, 90,
		  80, 78, 79, 89, 70, 101, 102, 112, 91, 102, 103, 113, 92, 90, 91, 101, 81, 80, 81, 91, 72, 91);
		//pole 91
	pola2(101, 102, 112, 91, 90, 100, 81, 90, 71, 79, 92, 102, 93, 103, 80, 89, 82, 91, 73, 81,
		  100, 101, 111, 91, 90, 102, 103, 113, 92, 103, 104, 114, 93, 90, 91, 101, 81, 79, 80, 
		  90, 71, 89, 90, 100, 80, 91, 92, 102, 82, 81, 82, 92, 73, 92);
	//pole 92
	pola3(102, 103, 113, 92, 91, 101, 90, 100, 82, 91, 72, 80, 93, 103, 94, 104, 81, 90, 70, 78, 83, 
		  92, 74, 82, 101, 102, 112, 92, 91, 100, 101, 111, 90, 91, 92, 102, 82, 80, 81, 91, 72, 103, 
		  104, 114, 93, 104, 105, 115, 94, 90, 91, 101, 81, 78, 79, 89, 70, 92, 93, 103, 83, 82, 83, 
		  93, 74, 93);
	//pole 93
	pola3(103, 104, 114, 93, 92, 102, 91, 101, 83, 92, 73, 81, 94, 104, 95, 105, 82, 91, 71, 79, 84, 
		  93, 75, 83, 102, 103, 113, 93, 92, 101, 102, 112, 91, 92, 93, 103, 83, 81, 82, 92, 73, 104, 
		  105, 115, 94, 105, 106, 116, 95, 91, 92, 102, 82, 79, 80, 90, 71, 93, 94, 104, 84, 83, 84, 
		  94, 75, 94);
	//pole 94
	pola3(104, 105, 115, 94, 93, 103, 92, 102, 84, 93, 74, 82, 95, 105, 96, 106, 83, 92, 72, 80, 85, 
		  94, 76, 84, 103, 104, 114, 94, 93, 102, 103, 113, 92, 93, 94, 104, 84, 82, 83, 93, 74, 105, 
		  106, 116, 95, 106, 107, 117, 96, 92, 93, 103, 83, 80, 81, 91, 72, 94, 95, 105, 85, 84, 85, 
		  95, 76, 95);
	//pole 95
	pola3(105, 106, 116, 95, 94, 104, 93, 103, 85, 94, 75, 83, 96, 106, 97, 107, 84, 93, 73, 81, 86, 
		  95, 77, 85, 104, 105, 115, 95, 94, 103, 104, 114, 93, 94, 95, 105, 85, 83, 84, 94, 75, 106, 
		  107, 117, 96, 107, 108, 118, 97, 93, 94, 104, 84, 81, 82, 92, 73, 95, 96, 106, 86, 85, 86, 
		  96, 77, 96);
	//pole 96
	pola3(106, 107, 117, 96, 95, 105, 94, 104, 86, 95, 76, 84, 97, 107, 98, 108, 85, 94, 74, 82, 87, 
		  96, 78, 86, 105, 106, 116, 96, 95, 104, 105, 115, 94, 95, 96, 106, 86, 84, 85, 95, 76, 107,
		  108, 118, 97, 108, 109, 119, 98, 94, 95, 105, 85, 82, 83, 93, 74, 96, 97, 107, 87, 86, 87, 
		  97, 78, 97);
	//pole 97
	pola3(107, 108, 118, 97, 96, 106, 95, 105, 87, 96, 77, 85, 98, 108, 99, 109, 86, 95, 75, 83, 88, 
		  97, 79, 87, 106, 107, 117, 97, 96, 105, 106, 116, 95, 96, 97, 107, 87, 85, 86, 96, 77, 108, 
		  109, 119, 98, 109, 110, 120, 99, 95, 96, 106, 86, 83, 84, 94, 75, 97, 98, 108, 88, 87, 88, 
		  98, 79, 98);
	//pole 98
	pola2(108, 109, 119, 98, 99, 109, 97, 107, 96, 106, 88, 97, 78, 86, 89, 98, 87, 96, 76, 84,
		  109, 110, 120, 98, 99, 107, 108, 118, 97, 106, 107, 117, 96, 97, 98, 108, 88, 86, 87, 97,
		  78, 98, 99, 109, 89, 96, 97, 107, 87, 84, 85, 95, 76, 99);
	//pole 99
	pola1(109, 110, 120, 99, 98, 108, 97, 107, 89, 98, 79, 87, 88, 97, 77, 85, 108, 109, 119, 99, 
		  98, 107, 108, 118, 97, 98, 99, 109, 89, 87, 88, 98, 79, 97, 98, 108, 88, 85, 86, 96, 77, 100);
}

void DwochGraczy::rozstawienie_gracz1()
{
	int o=0;
	int j=100;
	while((o<=99)&&(j<=199))
	{
	if(pola[o]==1)
	circlefill(bufor_gra2, pozycja_pionka[o], pozycja_pionka[j], 20, makecol(0,255,255));
	j++;
	o++;
	}
}

void DwochGraczy::rozstawienie_gracz2()
{
	int o=0;
	int j=100;
	while((o<=99)&&(j<=199))
	{
	if(pola[o]==2)
	circlefill(bufor_gra2, pozycja_pionka[o], pozycja_pionka[j], 20, makecol(255,128,0));
	j++;
	o++;
	}
}

void DwochGraczy::zapisywanie()
{
	int i=0;
	FILE* plik;
	plik=fopen( "zapisywanie.txt", "a");
	clear_to_color(bufor_gra, makecol(255,255,255));
	clear_to_color(bufor_gra2,makecol(255,255,255));
	int x=200;
	fprintf(plik, "\n");
	while(!key[KEY_ENTER])
	{
		masked_blit(zap,bufor_gra2, 0,0,180,20,zap->w,zap->h);
		textprintf_ex(bufor_gra2, font, 20, 100, makecol(0,0,0), - 1, "Wpisz swoje imie:");
		osoba[i]= readkey();
		if(osoba[i]>=key[KEY_A] && osoba[i]<=key[KEY_Z])
		{
			osoba[i];
		}
		textprintf_ex( bufor_gra2, font, x, 100, makecol(0,0,0), - 1, "%c",osoba[i]);
		fprintf(plik, "%c", osoba[i]);
		x=x+7;
		i++;
		masked_blit(bufor_gra2,bufor_gra, 0,0,0,0,640,480);
		draw_sprite(bufor_gra,kursor_gra1,mouse_x,mouse_y);
		blit(bufor_gra, screen, 0,0,0,0, 640, 480);
	}
	fprintf(plik,"                                  ");
	if(w_nieb==1)
		fprintf(plik, "%d", kolejka1);
	if(w_pom==1)
		fprintf(plik, "%d", kolejka2);
	fclose(plik);
}

void DwochGraczy::zapis()
{	
	if(w_nieb==1||w_pom==1)
		 zapisywanie();
}

void DwochGraczy::gra_open()
{
	zajetosc_pol();
	twoj_ruch1=0;
	wykonales_skok=0;
	for(int t=1;t<=100;t++)
		pojawilo_sie[t]=0;
	mouse_b=0;
	while(next_game%2==0)
	{
		zajete_przez_gracz=1;
		clear_to_color(bufor_gra3, makecol(0,255,0));
		tlo();
		masked_blit(bufor_gra3,bufor_gra2, 0,0,0,0,640,480);
		rozstawienie_gracz1();
		rozstawienie_gracz2();
		masked_blit(bufor_gra2,bufor_gra, 0,0,0,0,640,480);
		sprawdzanie_pol();
		draw_sprite(bufor_gra,kursor_gra1,mouse_x,mouse_y);
		blit(bufor_gra, screen, 0,0,0,0, 640, 480);		
	}
	rest(200);
	twoj_ruch1=0;
	mouse_b=0;
	wykonales_skok=0;
	for(int t=1;t<=100;t++)
		pojawilo_sie[t]=0;
	while(next_game%2==1)
	{
		zajete_przez_gracz=2;	
		clear_to_color(bufor_gra3, makecol(0,255,0));
		tlo2();
		masked_blit(bufor_gra3,bufor_gra2, 0,0,0,0,640,480);
		rozstawienie_gracz1();
		rozstawienie_gracz2();
		masked_blit(bufor_gra2,bufor_gra, 0,0,0,0,640,480);
		sprawdzanie_pol();	
		draw_sprite(bufor_gra,kursor_gra1,mouse_x,mouse_y);
		blit(bufor_gra, screen, 0,0,0,0, 640, 480);
	}
}
void DwochGraczy::gra()
{
	load_gra();
	kursor_gra();
	zajetosc_pol_poczatek();
	next_game=0;
	w_pom=0;
	w_nieb=0;
	while(!key[KEY_ESC])
	{
		gra_open();
	}
}