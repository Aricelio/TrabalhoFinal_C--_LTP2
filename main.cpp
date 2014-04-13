#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

#include "classes.h"
#include "ListagemCliente.h"   //Função que lista todos os clientes
#include "CadastrarCliente.h"  //Função que faz um novo cadastro
#include "VerificaNumeroConta.h" //Função que verifica se o numero da conta existe

using namespace std;

//-------------------- Protótipos das Funções---------------------------------//
void MenuPrincipal();
void MenuCadastro();
void CadastrarCliente(cliente *&, int &, int &, int &);
void ListarClientes(cliente *&, int &);
bool VerificaNumeroConta(int, int &, cliente *&);
int  RetornaIndiceCliente(int, cliente *&, int &);
void MenuEditar();
void EditarCliente(cliente *&, int, int &,int &);

int main()
{    
//-------------------- Declaração de Variaveis--------------------------------//     
    cliente *Cliente;
    int TotalClientes = 0;
    int NumeroContaCorrente = 1111;
    int NumeroCartaoCredito = 333333;
    
    int respMenuPrincipal;   
    int respEditar;
    
    do
    {
         system("cls"); 
         MenuPrincipal();
         cout << "\nResp: "; 
         cin >> respMenuPrincipal;
         
         switch (respMenuPrincipal)
         {
              case 1:
                   int respCadastro;
                   MenuCadastro: //Usado pelo 'goto' pra voltar pro menu de Cadastros
                   system("cls");
                   MenuCadastro();
             //-----------------Valida a resposta do Usuario------------------//      
                   do
                   {
                       cout << "Resp: ";
                       cin >> respCadastro;
                   }while((respCadastro < 1) || (respCadastro > 4));
             //---------------------------------------------------------------//
                   switch(respCadastro)
                   {
                        case 1:
                             system("cls");
                             CadastrarCliente(Cliente, TotalClientes, NumeroContaCorrente, NumeroCartaoCredito);
                             system("PAUSE");
                             break;
                        case 2:
                             ListarClientes(Cliente, TotalClientes);
                             do
                             {
                                 cout << "Resp: ";
                                 cin >> respEditar;   
                                 
                                 if(!VerificaNumeroConta(respEditar,TotalClientes, Cliente))
                                         cout << "\nNumero de Conta INEXISTENTE!\n";                  
                             }while(!VerificaNumeroConta(respEditar,TotalClientes, Cliente));      
                             
                             EditarCliente(Cliente, respEditar, TotalClientes,NumeroCartaoCredito);
                                         
                             system("PAUSE");
                             break;
                        case 3:
                             cout << "\nExcluir\n";
                             ListarClientes(Cliente, TotalClientes);
                             system("PAUSE");
                             break;            
                        case 4:
                             cout << "\nVoltar\n";
                             system("PAUSE"); 
                             break;     
                   }
//----------------------------------------------------------------------------//                   
                   if((respCadastro >= 1) && (respCadastro <= 3))
                       goto MenuCadastro;
//----------------------------------------------------------------------------//
                   break;
              case 2:
                   cout << "\nTransacoes";
                   break;
              case 3: 
                   cout << "\nConsultas";
                   ListarClientes(Cliente, TotalClientes);
                   break;
              case 4:
                   cout << "\nSair";
                   break;                 
         } 
    }while(respMenuPrincipal != 4);      
    
    
    
    for(int i=0; i<TotalClientes; i++)
    {
            cout << "\nNome: " << Cliente[i].getNome();
            cout << "\nCPF: "         << Cliente[i].getCPF();
            cout << "\nEndereco: "    << Cliente[i].getEndereco();
            cout << "\nNC: "            << Cliente[i].ContaCorrente.getNumeroCC();
            cout << "\nNumero Cartao:  "   << Cliente[i].ContaCorrente.CartaoCredito.getNumero(); 
            cout << "\nBandeira: "         << Cliente[i].ContaCorrente.CartaoCredito.getBandeira(); 
            cout << "\n===========================================\n\n";
            
    }
    
    
    /*Cliente.setNome("Aricelio");
    cout << "nome: " << Cliente.getNome() << endl;
    Cliente.setCPF("111.111.111-00");
    cout << "CPF: " << Cliente.getCPF() << endl;
    Cliente.setEndereco("Rua B");
    cout << "Endereco: " << Cliente.getEndereco() << endl;    
    
    cartaoCredito cartao;
    int n;
    do
    {
        cin >> n;
        cartao.setBandeira(n);
    }while((n != 1) && (n != 2));
    cout << "\nDeu Certo! " << cartao.getBandeira();*/
    
    
//----------------------------------------------------------------------------//    
    cout << endl << endl;
    system("PAUSE");
    return 0;
}
//-------------------- MENU PRINCIPAL-----------------------------------------//
void MenuPrincipal()
{
     cout << " +--------------------------------------------------+" << endl
          << " +               MENU PRINCIPAL                     +" << endl
          << " + 1. Cadastros                                     +" << endl
          << " + 2. Transacoes                                    +" << endl
          << " + 3. Consultas                                     +" << endl
          << " + 4. Sair                                          +" << endl
          << " +--------------------------------------------------+" << endl;
     
}
//-------------------- MENU CADASTROS-----------------------------------------//
void MenuCadastro()
{   
     cout << " +--------------------------------------------------+" << endl
          << " +               MENU CADASTROS                     +" << endl
          << " + 1. Novo Cliente                                  +" << endl
          << " + 2. Editar Cliente                                +" << endl
          << " + 3. Exluir Cliente                                +" << endl
          << " + 4. Retornar ao Menu Principal                    +" << endl
          << " +--------------------------------------------------+" << endl;
}
int  RetornaIndiceCliente(int NumeroCC, cliente *&Cliente, int &TotalClientes)
{
     int Indice;
     
     for(int i=0; i<TotalClientes; i++)
     {
          if(Cliente[i].ContaCorrente.getNumeroCC() == NumeroCC)
          {
               Indice = i;
               break;                                     
          }               
     }
     return Indice;
}

void EditarCliente(cliente *&Cliente, int NumeroCC, int &TotalClientes, int &NumeroCartaoCredito)
{
     int Indice = RetornaIndiceCliente(NumeroCC, Cliente, TotalClientes);
     int resp, limite, tempInt;
     string tempStr;
     
     
     system("cls");
     cout << "Nome: " << Cliente[Indice].getNome() << endl
          << "Conta: " << Cliente[Indice].ContaCorrente.getNumeroCC() << endl;
     
     cout << "\n +--------------------------------------------------+" << endl
          << " +            QUAL CAMPO DESEJA EDITAR?             +" << endl
          << " + 1. Nome                                          +" << endl
          << " + 2. CPF                                           +" << endl
          << " + 3. Endereco                                      +" << endl;
     
     if(Cliente[Indice].ContaCorrente.getCartaoCreditoAtivo() == true)
     {
         limite = 5;
         cout << " + 4. Desativar Cartao de Credito                   +" << endl 
              << " + 5. Alterar Bandeira                              +" << endl;                                                    
     }
     else
     {
         limite = 4;
         cout << " + 4. Ativar Cartao de Credito                      +" << endl;
     }

     do
     {
         cout << "Resp: ";
         cin >> resp;
     }while ((resp < 1) || (resp > limite));
     
     
     
     switch (resp)
     {
           case 1:
                fflush(stdin);
                cout << "\nNome: ";
                getline(cin, tempStr);
                Cliente[Indice].setNome(tempStr);
                cout << "Nome Alterado com Sucesso!\n\n";
                //goto inicioEditar;
                break;
           case 2:
                fflush(stdin);
                cout << "\nCPF: ";
                getline(cin, tempStr);
                Cliente[Indice].setCPF(tempStr);
                cout << "CPF Alterado com Sucesso!\n\n";
                //goto inicioEditar;
                break;
           case 3:
                fflush(stdin);
                cout << "\nEndereco: ";
                getline(cin, tempStr);
                Cliente[Indice].setEndereco(tempStr);
                cout << "Endereco Alterado com Sucesso!\n\n";
                //goto inicioEditar;
                break;
     }     
     
     if(limite == 4)
     {
           if(resp == 4)
           {
                cout << "\nDeseja Realmente ativar seu Cartão de Credito? (1-Sim/ 2-Nao)" << endl; 
                do
                {
                    cout << "Resp: ";
                    cin >> tempInt;
                }while ((tempInt < 1) || (tempInt > 2));
                
                if(tempInt == 1)
                {
                    Cliente[Indice].ContaCorrente.setCartaoCreditoAtivo(true);    
                    
                    cout << "\nInforme a bandeira do Cartao." << endl
                         << "    1 - Visa" << endl
                         << "    2 - MasterCard" << endl;                
                    do
                    {
                         cout << "Resp: ";
                         cin >> tempInt;
                    }while ((tempInt < 1) || (tempInt > 2));   
                    
                    if(tempInt == 1)
                        Cliente[Indice].ContaCorrente.CartaoCredito.setBandeira(tempInt);
                    else
                        Cliente[Indice].ContaCorrente.CartaoCredito.setBandeira(tempInt);
                        
                    Cliente[Indice].ContaCorrente.CartaoCredito.setNumero(NumeroCartaoCredito);    
                }
           }    
     }
     else if (limite = 5)
     {
          if(resp == 4)
          {
                cout << "\nDeseja Realmente Desativar seu Cartão de Credito? (1-Sim/ 2-Nao)" << endl; 
                do
                {
                    cout << "Resp: ";
                    cin >> tempInt;
                }while ((tempInt < 1) || (tempInt > 2));
                
                if(tempInt == 1)
                    Cliente[Indice].ContaCorrente.setCartaoCreditoAtivo(false);                      
          }
          else if(resp == 5)
          {
                cout << "\nDeseja Realmente alterar a bandeira de seu Cartão de Credito? (1-Sim/ 2-Nao)" << endl; 
                do
                {
                    cout << "Resp: ";
                    cin >> tempInt;
                }while ((tempInt < 1) || (tempInt > 2));
                
                if(tempInt == 1)               
                {
                    cout << "\nInforme a bandeira do Cartao." << endl
                         << "    1 - Visa" << endl
                         << "    2 - MasterCard" << endl;                
                    do
                    {
                         cout << "Resp: ";
                         cin >> tempInt;
                    }while ((tempInt < 1) || (tempInt > 2));   
                    
                    if(tempInt == 1)
                        Cliente[Indice].ContaCorrente.CartaoCredito.setBandeira(tempInt);
                    else
                        Cliente[Indice].ContaCorrente.CartaoCredito.setBandeira(tempInt);
                }
          }
     }
}
