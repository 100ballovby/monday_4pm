#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Структура для представления вершины
struct Vertex {
    int id;
    vector<int> adjacentVertices;
};

// Структура для представления ребра
struct Edge {
    int sourceVertex;
    int destinationVertex;
};

// Структура для представления графа
struct Graph {
    vector<Vertex> vertices;
    vector<Edge> edges;
};

// Функция для печати данных графа в текстовый файл
void printGraphToFile(const Graph &graph, const string &filename) {
    ofstream outfile(filename);

    // Вывести количество вершин
    outfile << graph.vertices.size() << endl;

    // Вывести вершины
    for (int i = 0; i < graph.vertices.size(); i++) {
        outfile << graph.vertices[i].id << " ";
        for (int j = 0; j < graph.vertices[i].adjacentVertices.size(); j++) {
            outfile << graph.vertices[i].adjacentVertices[j] << " ";
        }
        outfile << endl;
    }

    // Вывести края
    for (int i = 0; i < graph.edges.size(); i++) {
        outfile << graph.edges[i].sourceVertex << " " << graph.edges[i].destinationVertex << endl;
    }

    outfile.close();
}

// Функция для чтения данных графа из текстового файла
Graph readGraphFromFile(const string &filename) {
    Graph graph;

    ifstream infile(filename);

    // Прочитать количество вершин
    int numVertices;
    infile >> numVertices;

    // Чтение вершин
    for (int i = 0; i < numVertices; i++) {
        Vertex vertex;
        infile >> vertex.id;
        graph.vertices.push_back(vertex);
    }

    // Чтение краев
    for (int i = 0; i < numVertices; i++) {
        Edge edge;
        infile >> edge.sourceVertex >> edge.destinationVertex;
        graph.edges.push_back(edge);
    }

    infile.close();

    return graph;
}

// Функция для случайного заполнения графа, запрашивая у пользователя количество вершин и ребер.
void fillGraphRandomly(Graph &graph) {
    int numVertices, numEdges;

    // Запросить у пользователя количество вершин
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    // Запросить у пользователя количество ребер
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    // Создать вершины
    for (int i = 0; i < numVertices; i++) {
        Vertex vertex;
        vertex.id = i;
        graph.vertices.push_back(vertex);
    }

    // Создать края
    for (int i = 0; i < numEdges; i++) {
        Edge edge;
        edge.sourceVertex = rand() % numVertices;
        edge.destinationVertex = rand() % numVertices;
        graph.edges.push_back(edge);
    }
}

// Функция, позволяющая по заданной матрице смежности (набору данных из консоли) построить матрицу инцидентности
void buildIncidenceMatrix(const Graph &graph, vector<vector<int>> &incidenceMatrix) {
    int numVertices = graph.vertices.size();
    int numEdges = graph.edges.size();

    // Создать матрицу заболеваемости
    incidenceMatrix.resize(numVertices);

    for (int i = 0; i < numEdges; i++) {
        // Получить исходную и конечную вершины
        int sourceVertex = graph.edges[i].sourceVertex;
        int destinationVertex = graph.edges[i].destinationVertex;

        // Установить соответствующие записи в матрице инцидентности
        incidenceMatrix[sourceVertex].push_back(i);
        incidenceMatrix[destinationVertex].push_back(i);
    }
}

// Функция добавления вершины. Данные об инцидентных ребрах задаются из консоли.
void addVertex(Graph &graph) {
    int vertexId;

    // Запрашиваем у пользователя идентификатор вершины
    cout << "Enter the vertex id: ";
    cin >> vertexId;

    // Создаем вершину
    Vertex vertex;
    vertex.id = vertexId;
    graph.vertices.push_back(vertex);

    // Запросите у пользователя количество инцидентных ребер
    int numIncidentEdges;
    cout << "Enter the number of incident edges: ";
    cin >> numIncidentEdges;

    // Создаем инцидентные ребра
    for (int i = 0; i < numIncidentEdges; i++) {
        Edge edge;
        edge.sourceVertex = vertexId;
        edge.destinationVertex = rand() % graph.vertices.size();
        graph.edges.push_back(edge);
    }
}

void menu() {
    cout << " 1. Fill a graph randomly.\n2. Print a graph to a file.\n3. Read a graph from a file.\n4. Build an incidence matrix.\n5. Add a vertex.\n6. Exit." << endl;
}

int main() {
    int choice;

    do {
        // Создаем граф
        Graph graph;
        Graph graph2;

        menu();
        cout << "Make a choice: ";
        cin >> choice;

        if (choice == 1) {
            // Наполняем его случайными числами
            fillGraphRandomly(graph);
            cout << "Done!" << endl;
        } else if (choice == 2) {
            // Выводим граф в файл
            printGraphToFile(graph, "../graph.txt");
            cout << "Done!" << endl;
        } else if (choice == 3) {
            // Читаем граф из файла
             graph2 = readGraphFromFile("../graph.txt");
        } else if (choice == 4) {
            // строим матрицу инцидентности
            vector<vector<int>> incidenceMatrix;
            buildIncidenceMatrix(graph2, incidenceMatrix);

            // Выводим матрицу инцидентности
            cout << "Incident matrix" << endl;
            for (int i = 0; i < incidenceMatrix.size(); i++) {
                for (int j = 0; j < incidenceMatrix[i].size(); j++) {
                    cout << incidenceMatrix[i][j] << " ";
                }
                cout << endl;
            }
        } else if (choice == 5) {
            // Add a vertex
            addVertex(graph2);
        }

    } while (choice > 0 && choice <= 6);



    return 0;
}