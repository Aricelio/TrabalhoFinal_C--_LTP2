bool VerificaNumeroConta(int NumeroCC, int &TotalClientes, cliente *&Cliente)
{
     bool existe = false;
     
     for(int i=0; i<TotalClientes; i++)
     {
          if(Cliente[i].ContaCorrente.getNumeroCC() == NumeroCC)
          {
               existe = true;
               break;                                     
          }               
     }
     
     return existe;
}
