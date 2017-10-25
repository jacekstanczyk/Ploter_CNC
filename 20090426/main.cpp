#include "demo.h"
#include "grafika.h"
#include "silnikkrokowy.h"
#include "konwerter.h"

float dystans;
int ktora;

int main()
{
zerujWyjsciaLPT1();



for (;;)
{
	
	cout << "1) X Axis" << endl;
	cout << "2) Y Axis" << endl;
	cout << "3) Z Axis" << endl;
	cout << "4) Predkosc" << endl << endl << endl;

	cout << "5) Planowanie 165x105" << endl;


	cout << "6) Proba plytki" << endl;
	cout << "7) Ornament 3" << endl;
	cout << "8) Plytka drukowana " << endl <<endl;
	cout << "15) Przelicz wymiary" << endl;
	cout << "21) Demo 1" << endl;
	cout << "22) Demo 2" << endl;
	cout << "23) Demo 3" << endl;

	cout << "16) Wyjscie z programu " << endl << endl;
	cout << "Wybierz opcje" << endl;
	cin >> ktora;


	switch (ktora)
	{

		case 1:
			{
				cout << "Podaj wymiar w mm" << endl;
				cin >> dystans;
				if (dystans > 0)
					{
					ploter25D zlom;
					zlom.wlaczSilniki();
					zlom.rLiniaB(0, 0,dystans*266.6666666666, 0);
					zlom.wylaczSilniki();
					}
				else
					{
					ploter25D zlom;
					zlom.wlaczSilniki();
					zlom.rLiniaB(-dystans*266.6666666666, 0,0, 0);
					zlom.wylaczSilniki();
					}
			}
			break;

		case 2:
			{
				cout << "Podaj wymiar w mm" << endl;
				cin >> dystans;
				if (dystans > 0)
					{
					ploter25D zlom;
					zlom.wlaczSilniki();
					zlom.rLiniaB(0, 0,0,dystans*266.6666666666);
					zlom.wylaczSilniki();
					}
				else
					{
					ploter25D zlom;
					zlom.wlaczSilniki();
					zlom.rLiniaB(0, -dystans*266.6666666666,0,0);
					zlom.wylaczSilniki();
					}
			}
			break;

		case 3:
			{
				cout << "Podaj wymiar w mm" << endl;
				cin >> dystans;
				if (dystans > 0)
					{
					ploter25D zlom;
					zlom.wlaczSilniki();
					silnikKrokowy678H378 (1, dystans*400, 200000, 200000);
					zlom.wylaczSilniki();
					}
				else
					{
					ploter25D zlom;
					zlom.wlaczSilniki();
					silnikKrokowy678H378 (0, -dystans*400, 200000, 200000);
					zlom.wylaczSilniki();
					}

			}
			break;

		case 4:
			{
				cout << "Podaj prêdkosc w mm m" << endl;
			}
			break;
//************************************************************************************************
		
		case 5:
			{
				ploter25D zlom;
				zlom.wlaczSilniki();

				for (int i=0;i<32;i++)
					{
						silnikKrokowy012H378 (1, 69333, 200000, 200000);
						silnikKrokowy345H378 (1, 666, 200000, 200000);
						silnikKrokowy012H378 (0, 69333, 200000, 200000);
						silnikKrokowy345H378 (1, 666, 200000, 200000);
					}
					silnikKrokowy345H378 (1, 42624, 200000, 200000);
				
				zlom.wylaczSilniki();	
			}
			break;

		case 15:
			{
			przeliczWymiary("godlo.plt");
			}
			break;
		
		case 8:
			{
				przeliczPlikPLT("plytkaO.plt");
				rysujPlikPLT("plytkaO.plt");
			}
			break;
		case 7:
			{
				przeliczPlikPLT("orn3.plt");
				rysujPlikPLT("orn3.plt");
			}
			break;
		case 6:
			{
				przeliczPlikPLT("proba.plt");
				rysujPlikPLT("proba.plt");
			}
			break;
	

		
		
		
		
	

		
		case 21:
			{
				demo();
			}
			break;
		case 22:
			{
				demo1();
			}
			break;
		case 23:
			{
				demo2();
			}
			break;
	}

	if (ktora==16) break;
}



				
			

return 0;
}


