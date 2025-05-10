namespace Enums
{
    namespace Normal
    {
        enum TipoUsuario
        {
            Padrao = 1,
            Admin = 2,
        };

        enum TipoCliente
        {
            Padrao = 1,
        };

        int main()
        {
            TipoUsuario tipoUsuario = TipoUsuario::Padrao;
            //tipoUsuario = Padrao; // Erro de compila��o por que tem dois enums iguals
            tipoUsuario = Admin; // Funciona por que s� tem um tipo "Admin"

            return 0;
        }
    }

    namespace Class
    {
        enum class TipoUsuario
        {
            Padra = 1,
            Admin = 2,
        };
        
        int main()
        {
            TipoUsuario tipoUsuario = TipoUsuario::Padra;
            // tipoUsuario = Admin; // Erro de compila��o, precisa do prefixo

            return 0;
        }
    }
}