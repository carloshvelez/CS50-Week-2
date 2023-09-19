#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include<math.h>


int count_letters(string input);
int count_words(string input);
int count_sentences(string input);

int main(void)
{
    string input = get_string("Text:  ");
    int letras = count_letters(input);
    int palabras = count_words(input);
    int frases = count_sentences(input);


    float L = (float)letras / (float)palabras * 100;
    float S = (float)frases / (float)palabras * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }


}

int count_letters(string input)
//Función para contar letras
// Por cada caracter, verifica si es letra mayúscula o minúscula y si es así, suma 1 al sumador.
{
    int contador = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z'))
        {
            contador += 1;
        }
    }
    return contador;
}

int count_words(string input)
// para contar palabras: por cada espacio, suma 1 al contador. Empieza desde 1 considerando que la última palabra no tiene un espacio.
{
    int contador = 1;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (input[i] == ' ')
        {
            contador += 1;
        }
    }
    return contador;
}

int count_sentences(string input)
//contador de sentencias. Cuenta frases cada vez que aparece un punto, una exclamación o una interrogación, sumando +1 al contador. 
{
    int contador = 0;
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (input[i] == '!'  || input[i] == '.' || input[i] == '?')
        {
            contador += 1;
        }
    }
    return contador;
}
