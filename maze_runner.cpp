#include <iostream>
#include <fstream>
#include <vector
#include <string>
#include <stack>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>

// Representação do labirinto
using namespace std;
mutex labirinto_mutex;  // Mutex para sincronizar o acesso ao labirinto
atomic<bool> encontrou_saida(false);  // Flag para indicar se a saída foi encontrada

bool carregar_labirinto(const string& caminho_arquivo, vector<vector<char>>& labirinto, int& linhas, int& colunas, pair<int, int>& inicio) {
    ifstream arquivo(caminho_arquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return false;
    }
    arquivo >> linhas >> colunas;
    labirinto.resize(linhas);
    string linha;
    getline(arquivo, linha);
    for (int i = 0; i < linhas; i++) {
        getline(arquivo, linha);
        labirinto[i] = vector<char>(linha.begin(), linha.end());
        size_t pos = linha.find('e');
        if (pos != string::npos) {
            inicio = {i, static_cast<int>(pos)};
        }
    }
    arquivo.close();
    return true;

void imprimir_labirinto(const vector<vector<char>>& labirinto) {
    this_thread::sleep_for(chrono::milliseconds(200));
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    for (const auto& linha : labirinto) {
        for (const auto& celula : linha) {
            cout << celula;
        }
        cout << endl;
    }

// Função principal para navegar pelo labirinto
bool walk(Position pos) {
    // TODO: Implemente a lógica de navegação aqui
    // 1. Marque a posição atual como visitada (maze[pos.row][pos.col] = '.')
    // 2. Chame print_maze() para mostrar o estado atual do labirinto
    // 3. Adicione um pequeno atraso para visualização:
    //    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    // 4. Verifique se a posição atual é a saída (maze[pos.row][pos.col] == 's')
    //    Se for, retorne true
    // 5. Verifique as posições adjacentes (cima, baixo, esquerda, direita)
    //    Para cada posição adjacente:
    //    a. Se for uma posição válida (use is_valid_position()), adicione-a à pilha valid_positions
    // 6. Enquanto houver posições válidas na pilha (!valid_positions.empty()):
    //    a. Remova a próxima posição da pilha (valid_positions.top() e valid_positions.pop())
    //    b. Chame walk recursivamente para esta posição
    //    c. Se walk retornar true, propague o retorno (retorne true)
    // 7. Se todas as posições foram exploradas sem encontrar a saída, retorne false
    
    return false; // Placeholder - substitua pela lógica correta
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_labirinto>" << std::endl;
        return 1;
    }

    Position initial_pos = load_maze(argv[1]);
    if (initial_pos.row == -1 || initial_pos.col == -1) {
        std::cerr << "Posição inicial não encontrada no labirinto." << std::endl;
        return 1;
    }

    bool exit_found = walk(initial_pos);

    if (exit_found) {
        std::cout << "Saída encontrada!" << std::endl;
    } else {
        std::cout << "Não foi possível encontrar a saída." << std::endl;
    }

    return 0;
}

// Nota sobre o uso de std::this_thread::sleep_for:
// 
// A função std::this_thread::sleep_for é parte da biblioteca <thread> do C++11 e posteriores.
// Ela permite que você pause a execução do thread atual por um período especificado.
// 
// Para usar std::this_thread::sleep_for, você precisa:
// 1. Incluir as bibliotecas <thread> e <chrono>
// 2. Usar o namespace std::chrono para as unidades de tempo
// 
// Exemplo de uso:
// std::this_thread::sleep_for(std::chrono::milliseconds(50));
// 
// Isso pausará a execução por 50 milissegundos.
// 
// Você pode ajustar o tempo de pausa conforme necessário para uma melhor visualização
// do processo de exploração do labirinto.
