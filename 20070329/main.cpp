#include "demo.h"
#include "grafika.h"
#include "silnikkrokowy.h"
#include "konwerter.h"


int ktora;

int main()
{




for (;;)
{
	cout << "21) Demo 1" << endl;
	cout << "22) Demo 2" << endl;
	cout << "1) Chlopiec" << endl;
	cout << "2) Coldchill" << endl;
	cout << "3) Kon" << endl;
	cout << "4) Loga" << endl;
	cout << "5) Ornament 1" << endl;
	cout << "6) Ornament 2" << endl;
	cout << "7) Ornament 3" << endl;
	cout << "8) Robot " << endl <<endl;

	cout << "9) x+10000" << endl;
	cout << "10) x-10000" << endl;
	cout << "11) y+10000" << endl;
	cout << "12) y-10000" << endl;
	cout << "13) z+500" << endl;
	cout << "14) z-500" << endl;

	cout << "15) Wyjscie z programu " << endl << endl;
	cout << "Wybierz opcje" << endl;
	cin >> ktora;


	switch (ktora)
	{
		
		case 14:
			{
			ploter2D zlom;
			zlom.wlaczSilniki();
			silnikKrokowy678H378 (0, 500, 4000, 4000);
			zlom.wylaczSilniki();
			}
			break;
		case 13:
			{
			ploter2D zlom;
			zlom.wlaczSilniki();
			silnikKrokowy678H378 (1, 500, 4000, 4000);
			zlom.wylaczSilniki();
			}
			break;
		case 12:
			{
			ploter2D zlom;
			zlom.wlaczSilniki();
			zlom.rLiniaB(0, 10000,0, 0);
			zlom.wylaczSilniki();
			}
			break;
		case 11:
			{
			ploter2D zlom;
			zlom.wlaczSilniki();
			zlom.rLiniaB(0, 0,0, 10000);
			zlom.wylaczSilniki();
			}
			break;
		case 10:
			{
			ploter2D zlom;
			zlom.wlaczSilniki();
			zlom.rLiniaB(10000, 0,0, 0);
			zlom.wylaczSilniki();
			}
			break;
		case 9:
			{
			ploter2D zlom;
			zlom.wlaczSilniki();
			zlom.rLiniaB(0, 0,10000, 0);
			zlom.wylaczSilniki();
			}
			break;
		case 8:
			{
				przeliczPlikPLT("robot.plt");
				rysujPlikPLT("robot.plt");
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
				przeliczPlikPLT("orn2.plt");
				rysujPlikPLT("orn2.plt");
			}
			break;
		case 5:
			{
				przeliczPlikPLT("orn1.plt");
				rysujPlikPLT("orn1.plt");
			}
			break;
		case 4:
			{
				przeliczPlikPLT("loga.plt");
				rysujPlikPLT("loga.plt");
			}
			break;
		case 3:
			{
				przeliczPlikPLT("kon.plt");
				rysujPlikPLT("kon.plt");
			}
			break;
		case 2:
			{
				przeliczPlikPLT("coldchill.plt");
				rysujPlikPLT("coldchill.plt");
			}
			break;
		case 1:
			{
				przeliczPlikPLT("chlopiec.plt");
				rysujPlikPLT("chlopiec.plt");
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
	}

	if (ktora==15) break;
}



				
			

return 0;
}


