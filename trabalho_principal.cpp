#include <iostream>
#include <cstring>

#define M 10
#define MAX 100

using namespace std;

bool verificaHorizontal(char palavra[], char grade[M][M], int m, int p)
{
    int tamanhoPalavra = strlen(palavra);
    for (int i = 0; i < m; i++)
    {
        // Checa normalmente
        for (int j = 0; j <= p - tamanhoPalavra; j++)
        {
            bool encontrou = true;
            for (int k = 0; k < tamanhoPalavra; k++)
            {
                if (grade[i][j + k] != palavra[k] && grade[i][j + k] != palavra[k] - 'a' + 'A' && grade[i][j + k] != palavra[k] - 'A' + 'a')
                {
                    encontrou = false;
                    break;
                }
            }
            if (encontrou)
            {
                cout << "A palavra " << palavra << " foi localizada horizontalmente a partir da posição (" << i << "," << j << ").\n";
                return encontrou;
            }
        }
        // Checa ao contrário
        for (int j = p - 1; j >= tamanhoPalavra - 1; j--)
        {
            bool encontrou = true;
            for (int k = 0; k < tamanhoPalavra; k++)
            {
                if (grade[i][j - k] != palavra[k] && grade[i][j - k] != palavra[k] - 'a' + 'A' && grade[i][j - k] != palavra[k] - 'A' + 'a')
                {
                    encontrou = false;
                    break;
                }
            }
            if (encontrou)
            {
                cout << "A palavra " << palavra << " foi localizada horizontalmente a partir da posição (" << i << "," << j << ").\n";
                return encontrou;
            }
        }
    }
    return false;
}

bool verificaVertical(char palavra[], char grade[M][M], int m, int p)
{   
    int tamanhoPalavra = strlen(palavra);
    for (int j = 0; j < p; j++)
    {
        // Checa de cima para baixo
        for (int i = 0; i <= m - tamanhoPalavra; i++)
        {
            bool encontrou = true;
            for (int k = 0; k < tamanhoPalavra; k++)
            {
                if (grade[i + k][j] != palavra[k] && grade[i + k][j] != palavra[k] - 'a' + 'A' && grade[i + k][j] != palavra[k] - 'A' + 'a')
                {
                    encontrou = false;
                    break;
                }
            }
            if (encontrou)
            {
                cout << "A palavra " << palavra << " foi localizada verticalmente a partir da posição (" << i << "," << j << ").\n";
                return encontrou;
            }
        }
        // Checa de baixo para cima
        for (int i = m - 1; i >= tamanhoPalavra - 1; i--)
        {
            bool encontrou = true;
            for (int k = 0; k < tamanhoPalavra; k++)
            {
                if (grade[i - k][j] != palavra[k] && grade[i - k][j] != palavra[k] - 'a' + 'A' && grade[i - k][j] != palavra[k] - 'A' + 'a')
                {
                    encontrou = false;
                    break;
                }
            }
            if (encontrou)
            {
                cout << "A palavra " << palavra << " foi localizada verticalmente a partir da posição (" << i << "," << j << ").\n";
                return encontrou;
            }
        }
    }
    return false;
}

bool verificaDiagonal(char palavra[], char grade[M][M], int m, int p)
{
    int tamanhoPalavra = strlen(palavra);
    // Diagonal para baixo e para a direita
    for (int i = 0; i <= m - tamanhoPalavra; i++)
    {
        for (int j = 0; j <= p - tamanhoPalavra; j++)
        {
            bool encontrou = true;
            for (int k = 0; k < tamanhoPalavra; k++)
            {
                if (grade[i + k][j + k] != palavra[k] && grade[i + k][j + k] != palavra[k] - 'a' + 'A' && grade[i + k][j + k] != palavra[k] - 'A' + 'a')
                {
                    encontrou = false;
                    break;
                }
            }
            if (encontrou)
            {
                cout << "A palavra " << palavra << " foi localizada diagonalmente a partir da posição (" << i << "," << j << ").\n";
                return true;
            }
        }
    }
    // Diagonal para cima e para a direita
    for (int i = tamanhoPalavra - 1; i < m; i++)
    {
        for (int j = 0; j <= p - tamanhoPalavra; j++)
        {
            bool encontrou = true;
            for (int k = 0; k < tamanhoPalavra; k++)
            {
                if (grade[i - k][j + k] != palavra[k] && grade[i - k][j + k] != palavra[k] - 'a' + 'A' && grade[i - k][j + k] != palavra[k] - 'A' + 'a')
                {
                    encontrou = false;
                    break;
                }
            }
            if (encontrou)
            {
                cout << "A palavra " << palavra << " foi localizada diagonalmente a partir da posição (" << i << "," << j << ").\n";
                return true;
            }
        }
    }
    // Diagonal para baixo e para a esquerda
    for (int i = 0; i <= m - tamanhoPalavra; i++)
    {
        for (int j = tamanhoPalavra - 1; j < p; j++)
        {
            bool encontrou = true;
            for (int k = 0; k < tamanhoPalavra; k++)
            {
                if (grade[i + k][j - k] != palavra[k] && grade[i + k][j - k] != palavra[k] - 'a' + 'A' && grade[i + k][j - k] != palavra[k] - 'A' + 'a')
                {
                    encontrou = false;
                    break;
                }
            }
            if (encontrou)
            {
                cout << "A palavra " << palavra << " foi localizada diagonalmente a partir da posição (" << i << "," << j << ").\n";
                return true;
            }
        }
    }
    // Diagonal para cima e para a esquerda
    for (int i = tamanhoPalavra - 1; i < m; i++)
    {
        for (int j = tamanhoPalavra - 1; j < p; j++)
        {
            bool encontrou = true;
            for (int k = 0; k < tamanhoPalavra; k++)
            {
                if (grade[i - k][j - k] != palavra[k] && grade[i - k][j - k] != palavra[k] - 'a' + 'A' && grade[i - k][j - k] != palavra[k] - 'A' + 'a')
                {
                    encontrou = false;
                    break;
                }
            }
            if (encontrou)
            {
                cout << "A palavra " << palavra << " foi localizada diagonalmente a partir da posição (" << i << "," << j << ").\n";
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int qtdPalavras, qtdLinhas, qtdColunas;
    cin >> qtdPalavras >> qtdLinhas >> qtdColunas;

    char palavras[qtdPalavras][MAX];
    cin.ignore();
    for (int i = 0; i < qtdPalavras; i++){
        cin.getline(palavras[i], MAX);
    }
    char grade[qtdLinhas][M];
    for (int i = 0; i < qtdLinhas; i++)
    {
        for (int j = 0; j < qtdColunas; j++)
        {
            cin >> grade[i][j];
        }
    }

    for (int i = 0; i < qtdPalavras; i++)
    {
        bool encontrou = false;
        if(verificaHorizontal(palavras[i], grade, qtdLinhas, qtdColunas))
            encontrou = true;
        else if(verificaVertical(palavras[i], grade, qtdLinhas, qtdColunas))
            encontrou = true;
        else if (verificaDiagonal(palavras[i], grade, qtdLinhas, qtdColunas))
            encontrou = true;
        if(!encontrou)
        {
            cout << "A palavra " << palavras[i] << " não foi localizada.\n";
        }
    }

    return 0;
}