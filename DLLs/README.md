### O que s�o?

DLL (Dynamic Link Library) � um tipo de biblioteca que cont�m c�digo e dados que podem ser usados por m�ltiplos programas ao mesmo tempo. 

### Por que usar?

- **Reutiliza��o de c�digo**: V�rios programas podem compartilhar a mesma DLL, evitando duplica��o de c�digo.
- **Atualiza��es f�ceis**: Voc� pode corrigir bugs ou adicionar funcionalidades apenas substituindo a DLL, sem recompilar todo o programa.
- **Redu��o do tamanho do execut�vel**: O c�digo da DLL n�o � inclu�do diretamente no .exe, o que diminui o tamanho do arquivo principal.
- **Modularidade**: Permite separar responsabilidades em diferentes arquivos, facilitando manuten��o e organiza��o.
- **Carregamento din�mico**: Pode carregar DLLs sob demanda com LoadLibrary, �til para plugins e sistemas extens�veis.

### Diferen�a entre compila��o est�tica e din�mica

- **Din�mica**:
    - gera um arquivo `.dll` que pode ser linkado com multiplos `.exe` ou `.dll`
- **Est�tico**:
    - linka o bin�rio da dll com o bin�rio do `.exe`

### Conceito de interface de comunica��o: cabe�alhos (.h) compartilhados

Para que um programa cliente consiga usar as fun��es de uma DLL, ele precisa conhecer a interface p�blica da DLL. Isso � feito por meio de arquivos de cabe�alho (.h) compartilhados.

Esses cabe�alhos cont�m:

- Declara��es de fun��es exportadas,
- Tipos, structs, enums, constantes,
- Macros de exporta��o/importa��o (ex: __declspec(dllexport) e __declspec(dllimport)).
- O cliente inclui o .h e linka o .lib gerado junto com a DLL para poder chamar as fun��es exportadas. (ClassExport.h)
