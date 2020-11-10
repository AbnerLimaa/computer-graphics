class Matriz
{
    private:
        int n_linhas;
        int n_colunas;
        int** matriz;
    
    public:
        Matriz(int linhas, int colunas);
        int getLinhas();
        int getColunas();
        int** getMatriz();
        void inserir(int linha, int coluna, int valor);
        void somar(Matriz matriz);
        void subtrair(Matriz matriz);
        void multiplicar(int escalar);
        Matriz multiplicar(Matriz matriz);
        void transposta();
};