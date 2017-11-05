/* PrimeSort 
 * Deny Stanley de Oliveira Barbosa		RA:145851
 */

#include <stdio.h>
#include <math.h>

int testa_numero(int num); /*Se numero e primo retorna 1, senao retorna 0 */


int main() {

	int n = 1, teste, i = 0, j;
	int naoprimos[200000];
	FILE *out, *arquivo;
	char ch;
	arquivo = fopen("ra145851.txt", "w");
	fclose(arquivo);

	while (n != (-1)) {
		scanf(" %d", &n);
		teste = testa_numero(n);
		if (!teste) { /* Se não primo*/
			//arquivo = fopen("ra145851.txt", "a"); /*abre o arquivo e escreve ao final do arquivo*/
			//fprintf(arquivo,"%d\n", n); /*escreve o numero nao primo no arquivo*/
			//fclose(arquivo); /*fecha o arquivo*/
			//printf("%d\n", n);
			//out = popen("cat ra145851.txt | sort --g -r > ra145851_1.txt", "r");   /*consome (ordenando) oss valores produzidos acima*/
			//pclose(out);
			naoprimos[i] = n;
			i++;
		}
	}	
	arquivo = fopen("ra145851.txt", "a");
	for (j = i - 1; j >= 0; j--) {
		fprintf(arquivo,"%d\n", naoprimos[j]);	
	}
	fclose(arquivo);

	out = popen("cat ra145851.txt | sort --g -r > ra145851_1.txt", "r");
	pclose(out);
	/*imprimindo na tela*/
	out = popen("cat ra145851_1.txt", "r");
	while( (ch=fgetc(out))!= EOF )
		putchar(ch);
	pclose(out);
	return 0;
}

int testa_numero(int num){
	int i, counter = 1; 
	if (num == 1) {
		return 0; /*numero 1 nao e primo*/
	} else {
		if (num == 2) {
			return 1;
		} else {
			for (i = 1; i <= ceil(sqrt(num)); i++) {
				if (num % i == 0) {
					counter++;
				}
			}

			if (counter > 2) {  /*Se tiver mais de 2 divisores é não primo*/
				return 0;
			} else {
				return 1; /*é primo*/
			}
		}
	}
}