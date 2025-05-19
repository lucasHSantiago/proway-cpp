### O que são?

DLL (Dynamic Link Library) é um tipo de biblioteca que contém código e dados que podem ser usados por múltiplos programas ao mesmo tempo. 

### Por que usar?

- **Reutilização de código**: Vários programas podem compartilhar a mesma DLL, evitando duplicação de código.
- **Atualizações fáceis**: Você pode corrigir bugs ou adicionar funcionalidades apenas substituindo a DLL, sem recompilar todo o programa.
- **Redução do tamanho do executável**: O código da DLL não é incluído diretamente no .exe, o que diminui o tamanho do arquivo principal.
- **Modularidade**: Permite separar responsabilidades em diferentes arquivos, facilitando manutenção e organização.
- **Carregamento dinâmico**: Pode carregar DLLs sob demanda com LoadLibrary, útil para plugins e sistemas extensíveis.

### Diferença entre compilação estática e dinâmica

- **Dinâmica**:
    - gera um arquivo `.dll` que pode ser linkado com multiplos `.exe` ou `.dll`
- **Estático**:
    - linka o binário da dll com o binário do `.exe`

### Conceito de interface de comunicação: cabeçalhos (.h) compartilhados

Para que um programa cliente consiga usar as funções de uma DLL, ele precisa conhecer a interface pública da DLL. Isso é feito por meio de arquivos de cabeçalho (.h) compartilhados.

Esses cabeçalhos contêm:

- Declarações de funções exportadas,
- Tipos, structs, enums, constantes,
- Macros de exportação/importação (ex: __declspec(dllexport) e __declspec(dllimport)).
- O cliente inclui o .h e linka o .lib gerado junto com a DLL para poder chamar as funções exportadas. (ClassExport.h)
