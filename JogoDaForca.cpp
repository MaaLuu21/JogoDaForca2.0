#include <iostream>
#include <locale.h>

using namespace std;

void ExibeForca ()
{
            cout << "\n _ ";
            cout << "\n| | ";
            cout << "\n|   ";
            cout << "\n|   ";
            cout << "\n| ";
}

void Insere (char palavra[])
{
        cout << "Insira uma palavra: ";
        cin >> palavra;

}
void InsereLetra (char letra [])
{
    cout << "\n\nInsira uma letra: ";
    cin >> letra[0];
}

int main ()
{
    setlocale(LC_ALL,"portuguese");
    char palavra[20], letra[1], secreta[20], res;
    int i, tam, acertos, chances;
    bool resposta;

    do
    {
        system("cls");
        chances=5;
        i=0;
        tam=0;
        acertos=0;
        resposta=false;
        res='s';

        Insere(palavra);

        system("cls");

        //soma quantidade de letras
        while(palavra[i] != NULL){
            tam++;
            i++;
        }
        //exibe quantidade de letras
        for(i=0; i<tam; i++)
        {
            secreta[i]='_';
        }


        while((chances>0) && (acertos<tam) && (res=='s'))
        {

            cout << "Chances restantes: " << chances << "\n";

            ExibeForca();

            for(i=0; i<tam; i++)
            {
                cout << secreta[i] << " ";
            }

            InsereLetra(letra);

            //substitui a a letra na palavra
            for(i=0; i<tam; i++)
            {
                if(palavra[i]==letra[0])
                {
                    resposta=true;
                    secreta[i]=palavra[i];
                    acertos++;
                }
            }

            if(!resposta)
            {
                chances--;
            }
            resposta=false;
            system("cls"); 
        
        }

        if (acertos==tam)
        {
            cout << "Isso mesmo a palavra era ---> ";
            
            for(i=0; i<tam; i++)
            {
                cout << secreta[i];
            }
            cout << "\n\n!!!VOCE VENCEU!!!\n\n";
            
            cout << "Deseja jogar novamente? [S] [N] ";
            cin >> res;

        }
        else
        {
                        for(i=0; i<tam; i++)
            {
                cout << secreta[i];
            }
            cout << "VOCE PERDEU :(\n\n";
            cout << "Deseja jogar novamente? [S] [N] ";
            cin >> res;
        }


    }while(toupper(res)!='N');

    return 0;
}