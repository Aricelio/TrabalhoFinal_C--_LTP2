#include <string>

using namespace std;


//--------------- Classe Transação -------------------------------------------//
class transacao 
{
      private:
        int Codigo;
        float Valor;   
      public:
        //--------Construtor--------------------------------------------------//
        transacao() {  
        }         
        //--------Métodos-----------------------------------------------------//
        //--------Código------------------------------------------------------//
        void setCodigo(int Codigo)
        {
             this->Codigo = Codigo;
        }
        int getCodigo()
        {
             return this->Codigo;            
        }
        //--------Valot-------------------------------------------------------//
        void setValor(float Valor)
        {
             this->Valor = Valor;    
        }
        float getValor()
        {
             return this->Valor;
        } 
        //--------------------------------------------------------------------//
};
//--------------- Classe TransaçãoConta---------------------------------------//
class transacaoConta: public transacao
{
      private:   
        int Tipo; //1-Saque; 2-Crédito      
      public:
        //Construtor
        transacaoConta() {        
        }  
        //-----------------Tipo-----------------------------------------------//
        void setTipo(int Tipo)
        {                            
             this->Tipo = Tipo;
        }      
        string getTipo()
        {
            string Saque = "Saque";
            string Deposito = "Deposito";
               
            if(this->Tipo == 1)
                return Saque;
            else if(this->Tipo == 2)
                return Deposito;
        }     
};
//--------------- Classe TransaçãoCartão--------------------------------------//
class transacaoCartao: public transacao 
{
      private:   
        string NomeEstabelecimento;
        string Cidade;      
      public:
        //Construtor
        transacaoCartao() {        
        }  
        //-----------------Métodos--------------------------------------------//
        //----------------NomeEstabelecimento---------------------------------//
        void setNomeEstabelecimento(string NomeEstabelecimento)
        {
              this->NomeEstabelecimento = NomeEstabelecimento; 
        }       
        string getNomeEstabelecimento()
        { 
              return this->NomeEstabelecimento;
        }
        //----------------Cidade----------------------------------------------//
        void setCidade(string Cidade)
        {
              this->Cidade = Cidade;    
        }
        string getCidade()
        {
              return this->Cidade;
        }
        //--------------------------------------------------------------------//           
};
//------------------------ Classe 'Cartão de Crédito' ------------------------//
class cartaoCredito 
{
      private:
        int Numero;      
        int Bandeira; //1-Visa; 2-MasterCard
        transacaoCartao *Transacao; //array de transações
      public:
       //-----------------Construtor------------------------------------------//
        cartaoCredito() 
        {  
          Transacao = NULL;
        }
       //-----------------Métodos---------------------------------------------//
       //-----------------Bandeira--------------------------------------------//
         void setBandeira(int Bandeira)
         {                            
              //if((Bandeira == 1) || (Bandeira == 2))
                   this->Bandeira = Bandeira;             
             // else
                   //cout << "\nNumero da Bandeira e INVALIDA!\n";
         }      
         string getBandeira()
         {
             string Visa = "Visa";
             string Master = "MasterCard";
                
             if(this->Bandeira == 1)
                 return Visa;
             else if(this->Bandeira == 2)
                 return Master;
         }
        //----------------Numero----------------------------------------------//
         void setNumero(int Numero)
         {
               this->Numero = Numero; 
         }       
         int getNumero()
         { 
               return this->Numero;
         }
       //---------------------------------------------------------------------//  
};
//------------------------ Classe 'Conta Corrente' ---------------------------//
class contaCorrente 
{
      private:    
        int NumeroCC;
        float Saldo;   
        bool CartaoCreditoAtivo;
        
        transacaoConta *Transacao; //array de transações
      public:
             
        cartaoCredito CartaoCredito;
       //--------------------Construtor---------------------------------------//
        contaCorrente() 
        {
              Transacao = NULL;  
              this->Saldo = 0;
        }
       //------------------- Métodos -----------------------------------------//
        void setNumeroCC(int NumeroCC)
        {
              this->NumeroCC = NumeroCC; 
        }       
        int getNumeroCC()
        { 
              return this->NumeroCC;
        }
       //------------------- Saldo -------------------------------------------//
        float getSaldo()
        { 
              return this->Saldo;
        }
       //-----------------------Cartão de Crédito-----------------------------//
        void setCartaoCreditoAtivo(bool CartaoCreditoAtivo)
        {
             this->CartaoCreditoAtivo = CartaoCreditoAtivo;
        } 
        bool getCartaoCreditoAtivo()
        {
             return this->CartaoCreditoAtivo;
        }
       //---------------------------------------------------------------------// 
};
//--------------------------- Classe 'Cliente' -------------------------------//
class cliente 
{
      private:
        string Nome; 
        string CPF;
        string Endereco;
         
      public:
        contaCorrente ContaCorrente;       
       //---------Construtor--------------------------------------------------//
        cliente() {  
        }   
       //--------- Métodos ---------------------------------------------------//
          
       
       //---------Nome--------------------------------------------------------// 
        void setNome(string Nome)
        {
             this->Nome = Nome;
        } 
        string getNome()
        {
             return this->Nome;  
        }
       //---------CPF--------------------------------------------------------//  
        void setCPF(string CPF)
        {
             this->CPF = CPF;
        } 
        string getCPF()
        {
             return this->CPF;  
        }
       //---------Endereço----------------------------------------------------//
        void setEndereco(string Endereco)
        {
             this->Endereco = Endereco;
        } 
        string getEndereco()
        {
             return this->Endereco;  
        }
       //---------------------------------------------------------------------//     
};
