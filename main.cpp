#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <random>
using namespace std;


struct Graph {
    vector<vector<int>> adj_matrix;
    int num_vertices;
    int num_edges;
};


// функция записи графа в файл
void writeGraphToFile(const Graph &graph, const string &filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << graph.num_vertices << " " << graph.num_edges << endl;
    for (int i = 0; i < graph.num_vertices; i++) {
        for (int j = 0; j < graph.num_edges; j++) {
            file << graph.adj_matrix[i][j] << " ";
        }
        file << endl;
    }
    file.close();
}

// чтение графа из файла
Graph readGraphFromFile(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return {{}, 0, 0};
    }
    int num_vertices, num_edges;
    file >> num_vertices >> num_edges;
    vector<vector<int>> adj_matrix(num_vertices, vector<int>(num_vertices));

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            file >> adj_matrix[i][j];
        }
    }
    file.close();
    return { adj_matrix, num_vertices, num_edges};
}


// функция заполнения графа случайными числами
void generateRandomGraph(Graph &graph) {
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, 1);
    cout << "Num of vertices: ";
    cin >> graph.num_vertices;
    graph.adj_matrix.resize(graph.num_vertices);
    for (int i = 0; i < graph.num_vertices; i++) {
        graph.adj_matrix[i].resize(graph.num_vertices);
        for (int j = 0; j < i; j++) {
            int val = distribution(generator);
            graph.adj_matrix[i][j] = graph.adj_matrix[j][i] = val;
            if (val == 1) {
                graph.num_edges++;
            }
        }
    }
}


// функция для построения матрицы инцидентности на основе матрицы смежности
vector<vector<int>> getIncidentMatrix(const vector<vector<int>> &adj_matrix) {
    int num_vertices = adj_matrix.size();
    int num_edges = 0;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            if (adj_matrix[i][j] == 1) {
                num_edges++;
            }
        }
    }

    vector<vector<int>> incidentMatrix (num_vertices, vector<int>(num_edges));
    int edge_index = 0;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            if (adj_matrix[i][j] == 1) {
                incidentMatrix[i][edge_index] = incidentMatrix[j][edge_index] = 1;
                edge_index++;
            }
        }
    }
    return incidentMatrix;
}


void addVertex(Graph &graph) {
    int new_vertex = graph.num_vertices;
    graph.num_vertices++;
    graph.adj_matrix.push_back(vector<int>(graph.num_vertices));
    for (int i = 0; i < graph.num_vertices; i++) {
        graph.adj_matrix[i].push_back(0);
    }
    cout << "Enter nums of vertices connected with new vertex (from 0 to " << new_vertex - 1 << "): " << endl;
    for (int i = 0; i < graph.num_vertices; i++) {
        int connected;
        cout << "Vertex " << i << ": ";
        cin >> connected;

        if (connected >= 0 && connected < new_vertex) {
            graph.adj_matrix[new_vertex][connected] = graph.adj_matrix[connected][new_vertex] = 1;
            graph.num_edges++;
        } else {
            cout << "Incorrect number of vertex!" << endl;
            i--;
        }
    }
}

// функция для получения всех цепей, исходящих из заданной вершины
void getPathsFromVertex(const Graph &graph, int vertex, vector<int> &path, vector<vector<int>> &paths) {
    path.push_back(vertex);
    if (path.size() == graph.num_vertices) {
        paths.push_back(path);
    } else {
        for (int i = 0; i < graph.num_vertices; i++) {
            if (graph.adj_matrix[vertex][i] == 1 && find(path.begin(), path.end(), i) == path.end()) {
                getPathsFromVertex(graph, i, path, paths);
            }
        }
    }
    path.pop_back();
}


int main() {
    Graph graph = { {}, 0, 0 };

    while (true) {
        cout << "Choose action: " << endl;
        cout << "1. Записать граф в файл." << endl;
        cout << "2. Прочитать граф из файла." << endl;
        cout << "3. Заполнить граф случайными числами." << endl;
        cout << "4. Построить матрицу инцидентности." << endl;
        cout << "5. Добавить вершину." << endl;
        cout << "6. Выйти.";
        int action;
        cin >> action;

        if (action == 1) {
            writeGraphToFile(graph, "../graph.txt");
        } else if (action == 2) {
            Graph graph2;
            graph2 = readGraphFromFile("../graph.txt");
        } else if (action == 3) {
            generateRandomGraph(graph);
        } else if (action == 4) {
            vector<vector<int>> incident = getIncidentMatrix(graph.adj_matrix);
            for (int i = 0; i < incident.size(); i++) {
                for (int j = 0; i < incident[i].size(); j++) {
                    cout << incident[i][j] << " ";
                }
                cout << endl;
            }
        } else if (action == 5) {
            addVertex(graph);
        } else if (action == 6) {
            break;
        }
    }
    return 0;
}
