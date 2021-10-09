//Brendan Li | NUID:001386816
//EECE2560, HW6

//include necessary libraries/define/using
#include <iostream>
#include <fstream>
#include <limits.h>
#include <stdexcept>
using namespace std;

//define numbers for the graph's size sake
#define N 200
//#define maxints 200


//GLOBAL
int Adj[N][N];
//vertices is for the number of vertices total
int vertices;
//u is the start vertex
//v is end vertix
//w is distance/weight
int s, e, w;
//the building index corresponding to building number
int const buildN[]={0, 26, 27, 29, 4, 24, 30, 7, 39, 9, 35, 38, 12, 54, 59, 50, 49, 48, 43, 19, 53, 42, 22};

//opens and read data from text file
void readMatrix(){
    //for reading the text file
    ifstream inf;
    //open at file location
    inf.open("C:\\Users\\Brend\\OneDrive\\Desktop\\EECE2560\\Graph.txt");//ENTER SPECIFIC LOCATION
    //if this fails display error message
    if(inf.fail()){
        cerr << "Error: Could not open output file\n";
        exit(1);
    }
    //activate the exception handling of inf stream
    inf.exceptions(ifstream::failbit | ifstream::badbit);

    //for reading each number correctly
    int x;
    int count=0;
    while (count < N) { //keep reading until reading maxints or
        //until a reading failure is caught.
        //read inf, enter into x
        try {
            inf >> x;
        }
        //Check for reading failure due to end of file or
        // due to reading a non‐integer value from the file.
        catch (ifstream::failure e) {
            break;
        }
        //number of vertices
        if(count==0){vertices=x;}
        else if(count%3==0){w=x;}//if it is the distance
        else if(count%2==0){e=x;}//if it is the end vertex
        else{s=x;}//if it is the start vertex
        //if all are read, update the Graph value
        if(count%3==0){Adj[s][e]=Adj[e][s]=w;}
        count++;
    }
}


//This function is for printing the path
void path(int shortL[], int j){
    // Base case to end recursion
    if (shortL[j] == - 1)
        return;
    //recursive call
    path(shortL, shortL[j]);
    //print out the correct building number
    cout<<buildN[j]<<" ";
}

//function to print out the Travel Directions/Info
void printPath(int SD[], int shortL[], int start, int end){
    //print the building start and end infomation
    cout<<"Traveling from building "<<buildN[start]<<" to "<<buildN[end]<<endl;
    //call path function and print shortest path
    cout<<"Shortest Path:"<<endl;
    path(shortL, end); cout<<endl;
    //Display the total distance of travel
    cout<<"Shortest Path's Distance:"<<endl;
    cout<<SD[end]<<endl;
}

//function for finding the minimum distance
int minD(int SD[], bool shortFlag[]){

    // Initialize min value and index
    int min = INT_MAX;
    int mindex;
    //find that minimum index in dist
    for (int v = 0; v < N; v++) {
        if (shortFlag[v] == false && SD[v] <= min) {
            min = SD[v], mindex = v;
        }
    }
    //return index
    return mindex;
}


//actually finds/calculates the shortest path
void dijkstra(int Adj[N][N]){
    //get the start buiding
    int start;
    cout<<"Provide Start Index:"<<endl;
    cin>>start;
    bool check=false;
    //find the node's index
    for(int i=0; i<vertices+1; i++){
        if(start==buildN[i]) {
            start = i;
            //set flag to true
            check=true;
        }
    }
    //if flag is never made true, it isn't a building/node
    if(!check){
        cout<<"That is an Invalid Building Number...Sorry!"<<endl;
    }
    //hold shortest distance
    int SD[N];
    // keep track of what is in shortest route
    bool shortFlag[N];
    // Storing the shortest path
    int shortL[N];

    // set all the shortest paths and distances to nada
    //also all shortFlags to false
    for (int i = 0; i < N; i++)
    {
        shortL[start] = -1;
        SD[i] = INT_MAX;
        shortFlag[i] = false;
    }
    // always 0 at 0
    SD[start] = 0;


    // For loop to find the shortest path for vertices
    for (int count = 0; count < N - 1; count++)
    {
        // Pick the minimum distance vertex if not processed then mark as processed
        int u = minD(SD, shortFlag);
        shortFlag[u] = true;

        // Update distances of adjacent vertices in this embedded
        for (int v = 0; v < N; v++)
            // Update short List if the new path is shorter
            if (!shortFlag[v] && Adj[u][v] && SD[u] + Adj[u][v] < SD[v]){
                //set shortList and short distance
                shortL[v] = u;
                SD[v] = SD[u] + Adj[u][v];
            }
    }


    //Get end destination
    int end;
    bool check2=false;
    cout<<"Provide Destination Index: "<<endl;
    cin>>end;
    //find the entered building's index
    for(int i=0; i<vertices+1; i++){
        if(end==buildN[i]) {
            end = i;
            //set flag to true if so
            check2=true;
        }
    }
    //if flag is false, display error message
    if(!check2){
        cout<<"That is an Invalid Building Number...Sorry!"<<endl;
    }
    //if the entered indices are valid, print the solution
    if(check && check2){printPath(SD, shortL, start, end);}
}


//main function to test the algorithm
int main() {
    //read from text file
    readMatrix();
    //call dijkstra's algorithm
    dijkstra(Adj);
    return 0;
}
