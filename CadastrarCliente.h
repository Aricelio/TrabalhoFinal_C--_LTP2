//------------------------ CADASTRAR UM CLIENTE ------------------------------//
void CadastrarCliente(cliente *&Cliente, int &TotalClientes, int &NumeroContaCorrente, int &NumeroCartaoCredito)
{
     int tempInt;   // Variavel tempor�ria usada para entrada de dados
     string tempStr;// Variavel string temporaria
     
    //---------------Aloca��o de Mem�ria--------------------------------------// 
     cliente *tempCliente = NULL;
     tempCliente = new cliente[TotalClientes +1];
     
    //--------------- Se possuir mais de um registro ir� realocar ------------//                        
     if(TotalClientes > 0)
     {
           for(int i=0; i< TotalClientes; i++)
           {
                 tempCliente[i] = Cliente[i];       
           }                     
     }
     
     Cliente = tempCliente;
     
     
     cout << "||---------------------- CADASTRO DE CLIENTES ------------------------------||\n";
   //---------- Atribui o Nome -----------------------------------------------//  
     fflush(stdin);
     cout << "\nDigite o Nome: ";
     getline(cin, tempStr);
     Cliente[TotalClientes].setNome(tempStr);
     
   //---------- Atribui o CPF  -----------------------------------------------//     
     fflush(stdin);
     cout << "\nDigite o CPF: ";
     getline(cin, tempStr);
     Cliente[TotalClientes].setCPF(tempStr);
     
   //---------- Atribui o Endereco -------------------------------------------//  
     fflush(stdin);
     cout << "\nDigite o Endereco: ";
     getline(cin, tempStr);
     Cliente[TotalClientes].setEndereco(tempStr);
     
   //---------- Conta Corrente------------------------------------------------//
     Cliente[TotalClientes].ContaCorrente.setNumeroCC(NumeroContaCorrente);
   //-------------------------------------------------------------------------//
     
     cout << "\nDeseja Ativar seu Cart�o de Credito? (1-Sim/ 2-Nao)" << endl; 
     do
     {
         cout << "Resp: ";
         cin >> tempInt;
     }while ((tempInt < 1) || (tempInt > 2));
     
     if(tempInt == 1)
     {
         //------------------ Ativa o cart�o de cr�dito ----------------------//       
           Cliente[TotalClientes].ContaCorrente.setCartaoCreditoAtivo(true); 
         
         //------------------Informa qual bandeira do cart�o -----------------//  
           cout << "\nInforme a bandeira do Cartao." << endl
                << "    1 - Visa" << endl
                << "    2 - MasterCard" << endl;                
           do
           {
                cout << "Resp: ";
                cin >> tempInt;
           }while ((tempInt < 1) || (tempInt > 2));   
           
           if(tempInt == 1)
                Cliente[TotalClientes].ContaCorrente.CartaoCredito.setBandeira(tempInt);
           else
                Cliente[TotalClientes].ContaCorrente.CartaoCredito.setBandeira(tempInt);
         //----------------- Setar o numero do cart�o ------------------------//
           Cliente[TotalClientes].ContaCorrente.CartaoCredito.setNumero(NumeroCartaoCredito);
           
           
         //-----Incrementar a variavel que controla o total de cart�es -------//
         NumeroCartaoCredito++;           
     }
     cout << "\n||---------------------- CADASTRO CONCLUIDO ------------------------------||\n";
      
    TotalClientes++;//Incrementa o numero de cliente
    NumeroContaCorrente++; //Incrementa o numero de Contas
}
