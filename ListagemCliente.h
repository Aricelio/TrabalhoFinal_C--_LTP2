//----------------------- LISTAGEM DE CLIENTES -------------------------------//
void ListarClientes(cliente *&Cliente, int &TotalClientes)
{
     system ("cls");
     cout << "\n||---------------------- LISTAGEM DE CLIENTES ---------------------------||\n"; 
     cliente Aux;
     if (TotalClientes > 0)
     {
         for(int i=0; i < TotalClientes; i++)
         {
               for(int j=i+1; j < TotalClientes; j++)
               {
                     if(Cliente[i].getNome() > Cliente[j].getNome())
                     {
                           Aux = Cliente[i];
                           Cliente[i] = Cliente[j];
                           Cliente[j] = Aux;                
                     }// Fim do 'if'        
               } // Fim do 'for' que usa 'j'
         }// Fim do 'for' que usa 'i'
         
       //---Cabeçalho da Listagem ------------------------------------------------//
        cout << "Codigo" << setw(20)
             << "Nome" << endl;
             
        for(int i=0; i < TotalClientes; i++)
        {
             cout << setw(6) <<  Cliente[i].ContaCorrente.getNumeroCC()
                  << setw(20) << Cliente[i].getNome() << endl;
        } 
     }
     else
             cout << "\nNao Ha Clientes Cadastrados!\n\n";
}
