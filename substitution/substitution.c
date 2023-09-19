#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int sumador(string x);
int repetidos(string cadena);


int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Debes agregar un argumento; ni más ni menos/n");
        return 1;
    }

    if (sumador(argv[1]) != ('a' + 'z') * 13 || strlen(argv[1]) != 26 || repetidos(argv[1]) != 26)
    {
        printf("Debes agregar todas las letras del alfabeto, sin repetir/n");
        return 1;
    }






    string plain_text = get_string("Plain text:  ");


    printf("ciphertext: ");

    for (int j = 0; j < strlen(plain_text); j++)
    {
        if ((plain_text[j] >= 'a' && plain_text[j] <= 'z') || (plain_text[j] >= 'A' && plain_text[j] <= 'Z'))
        {
            for (int i = 0; i < 26; i++)
            {
                if (plain_text[j] == 'a' + i)
                {
                    printf("%c", tolower(argv[1][i]));
                }
                else if (plain_text[j] == 'A' + i)
                {
                    printf("%c", toupper(argv[1][i]));
                }

            }
        }

        else
        {
            printf("%c", plain_text[j]);
        }

    }



    printf("\n");

}

int sumador(string x)
{

    int sumando = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if ((x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z'))
        {
            x[i] = tolower(x[i]);
            sumando += x[i];
        }

        else
        {
            return 0;
        }
    }
    return sumando;


}

int repetidos(string cadena)
{
    int contador = 0;
    for (int i = 0; i < strlen(cadena); i++)
    {
        for (int j = 0; j < strlen(cadena); j++)
        {
            if (cadena[i] == cadena[j])
            {
                contador++;
            }
        }
    }
    return contador;
}