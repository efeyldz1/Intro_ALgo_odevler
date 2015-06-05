#include <stdio.h>
#include <stdlib.h>
#define ACCEPTABLE 1
#define NOTMATCH 0
#define MAX_BOYUT 20 + 2

// Fonksiyon prototipi
int matrisKontrol(int matris[][MAX_BOYUT], int satir, int sutun);
void matirisiYazdir(int matris[][MAX_BOYUT], int satir, int sutun);

// argc : argument counter, 
// argv : argument vector
int main(int argc, char * argv[])
{
	int matris[MAX_BOYUT][MAX_BOYUT];
	int satir, sutun;
	int sayac = 3;


	if (argc == 1)
	{
		// yalnýzca
		// > programAdi.exe yazýlmýþsa if'in içine girer

		printf("Parametre girmediniz!!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		// > programAdi.exe satir sutun yazýlmýþsa
		// içine girer.

		// char * tipindeki komut satýrý argümanlarýný 
		// int tipine çevir int atoi(const char *) fonksiyonuyla
		satir = atoi(argv[1]);
		sutun = atoi(argv[2]);

		// Boyut 20 x 20 nin üstündeyse programý sonlandýr.
		if (satir >= 20 || sutun >= 20)
			exit(EXIT_FAILURE);

		// matris oluþturuluyor.
		for (int i = 1; i <= satir; i++)
		{
			for (int j = 1; j <= sutun; j++)
			{
				matris[i][j] = atoi(argv[sayac++]);
			}
		}

		matirisiYazdir(matris, satir, sutun);
		if (matrisKontrol(matris, satir, sutun) == ACCEPTABLE)
		{
			printf("\n+++ ACCEPTABLE +++\n");
		}
		else
		{
			printf("\n--- NOT MATCH ---\n");
		}

	}

	getchar();
	getchar();
	return 0;
}

int matrisKontrol(int matris[][MAX_BOYUT], int satir, int sutun)
{
	int kontrol = ACCEPTABLE;

	// Toplama için 
	// Dýþ kabuðu 0 ile doldur.
	for (int i = 0; i < satir + 2; i++)
	{
		for (int j = 0; j < sutun + 2; j++)
		{
			if (i == 0 || j == 0 || i == satir + 1 || j == sutun + 1)
				matris[i][j] = 0;
		}
	}

	for (int i = 1; i <= satir; i++)
	{
		for (int j = 1; j <= sutun; j++)
		{

			if ((sutun * (i - 1) + j) % 4 == 2)
			{
				if (matris[i][j] != matris[i][j + 1] + matris[i][j - 1] + matris[i - 1][j] + matris[i + 1][j])
				{
					kontrol = NOTMATCH;
					return kontrol;
				}

			}


		}
	}



	// Toplama için 
	// Dýþ kabuðu 1 ile doldur.
	for (int i = 0; i < satir + 2; i++)
	{
		for (int j = 0; j < sutun + 2; j++)
		{
			if (i == 0 || j == 0 || i == satir + 1 || j == sutun + 1)
				matris[i][j] = 1;
		}
	}

	for (int i = 1; i <= satir; i++)
	{
		for (int j = 1; j <= sutun; j++)
		{
			if ((sutun * (i - 1) + j) % 4 == 0)
			{
				if (matris[i][j] != matris[i][j + 1] * matris[i][j - 1] * matris[i - 1][j] * matris[i + 1][j])
				{
					kontrol = NOTMATCH;
					return kontrol;
				}

			}

		}
	}

	return kontrol;

}

void matirisiYazdir(int matris[][MAX_BOYUT], int satir, int sutun)
{
	printf("Matris : \n");
	for (int i = 1; i <= satir; i++)
	{
		for (int j = 1; j <= sutun; j++)
		{
			printf("%d\t", matris[i][j]);
		}
		printf("\n");
	}
}