#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// A struct to represent a vertex
struct Vertex {
    int id;
    vector<int> adjacentVertices;
};

// A struct to represent an edge
struct Edge {
    int sourceVertex;
    int destinationVertex;
};

// A struct to represent a graph
struct Graph {
    vector<Vertex> vertices;
    vector<Edge> edges;
};

// A function to print the graph data to a text file
void printGraphToFile(const Graph &graph, const string &filename) {
    ofstream outfile(filename);

    // Print the number of vertices
    outfile << graph.vertices.size() << endl;

    // Print the vertices
    for (int i = 0; i < graph.vertices.size(); i++) {
        outfile << graph.vertices[i].id << " ";
        for (int j = 0; j < graph.vertices[i].adjacentVertices.size(); j++) {
            outfile << graph.vertices[i].adjacentVertices[j] << " ";
        }
        outfile << endl;
    }

    // Print the edges
    for (int i = 0; i < graph.edges.size(); i++) {
        outfile << graph.edges[i].sourceVertex << " " << graph.edges[i].destinationVertex << endl;
    }

    outfile.close();
}

// A function to read the graph data from a text file
Graph readGraphFromFile(const string &filename) {
    Graph graph;

    ifstream infile(filename);

    // Read the number of vertices
    int numVertices;
    infile >> numVertices;

    // Read the vertices
    for (int i = 0; i < numVertices; i++) {
        Vertex vertex;
        infile >> vertex.id;
        graph.vertices.push_back(vertex);
    }

    // Read the edges
    for (int i = 0; i < numVertices; i++) {
        Edge edge;
        infile >> edge.sourceVertex >> edge.destinationVertex;
        graph.edges.push_back(edge);
    }

    infile.close();

    return graph;
}

// A function to fill the graph randomly by asking the user for the number of vertices and edges
void fillGraphRandomly(Graph &graph) {
    int numVertices, numEdges;

    // Ask the user for the number of vertices
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    // Ask the user for the number of edges
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    // Create the vertices
    for (int i = 0; i < numVertices; i++) {
        Vertex vertex;
        vertex.id = i;
        graph.vertices.push_back(vertex);
    }

    // Create the edges
    for (int i = 0; i < numEdges; i++) {
        Edge edge;
        edge.sourceVertex = rand() % numVertices;
        edge.destinationVertex = rand() % numVertices;
        graph.edges.push_back(edge);
    }
}

// A function that allows using the given adjacency matrix (data set from the console) to build an incidence matrix
void buildIncidenceMatrix(const Graph &graph, vector<vector<int>> &incidenceMatrix) {
    int numVertices = graph.vertices.size();
    int numEdges = graph.edges.size();

    // Create the incidence matrix
    incidenceMatrix.resize(numVertices);
    // Iterate over the edges
    for (int i = 0; i < numEdges; i++) {
        // Get the source and destination vertices
        int sourceVertex = graph.edges[i].sourceVertex;
        int destinationVertex = graph.edges[i].destinationVertex;

        // Set the corresponding entries in the incidence matrix
        incidenceMatrix[sourceVertex].push_back(i);
        incidenceMatrix[destinationVertex].push_back(i);
    }
}

// The function of adding a vertex. Data about incident edges is set from the console.
void addVertex(Graph &graph) {
    int vertexId;

    // Ask the user for the vertex id
    cout << "Enter the vertex id: ";
    cin >> vertexId;

    // Create the vertex
    Vertex vertex;
    vertex.id = vertexId;
    graph.vertices.push_back(vertex);

    // Ask the user for the number of incident edges
    int numIncidentEdges;
    cout << "Enter the number of incident edges: ";
    cin >> numIncidentEdges;

    // Create the incident edges
    for (int i = 0; i < numIncidentEdges; i++) {
        Edge edge;
        edge.sourceVertex = vertexId;
        edge.destinationVertex = rand() % graph.vertices.size();
        graph.edges.push_back(edge);
    }
}

int main() {
    // Create a graph
    Graph graph;

    // Fill the graph randomly
    fillGraphRandomly(graph);

    // Print the graph data to a text file
    printGraphToFile(graph, "../graph.txt");

    // Read the graph data from a text file
    Graph graph2 = readGraphFromFile("../graph.txt");

    // Build the incidence matrix
    vector<vector<int>> incidenceMatrix;
    buildIncidenceMatrix(graph2, incidenceMatrix);

    // Print the incidence matrix
    for (int i = 0; i < incidenceMatrix.size(); i++) {
        for (int j = 0; j < incidenceMatrix[i].size(); j++) {
            cout << incidenceMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Add a vertex
    addVertex(graph2);

    return 0;
}