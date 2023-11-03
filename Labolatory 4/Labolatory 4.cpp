#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void taskTwo(int** matrix, int rows, int colons); 

struct TIMETABLE
{
     string NAZV;
     int NUM;
     string DATE;
     string TIME;
};

void addTrain(TIMETABLE* TRAIN, int N) {

    for (int i = 0; i < N; i++)
    {
        cout << "TIMETABLE " << i + 1 << ":" << endl;
        cout << "Enter destination name: " << endl;
        cin.ignore();
        getline(cin, TRAIN[i].NAZV);

        cout << "Enter the number of train: " << endl;
        cin >> TRAIN[i].NUM;

        string d;
        while (true)
        {
            cout << "Enter the date of departure in the right order(dd.mm.yyyy): " << endl;
            cin >> d;
            
            if (d.length() > 10)
            {
                cout << "Wrong order in date" << endl;
            }
            else
            {
                TRAIN[i].DATE = d;
                break;
            }
        }
    
        string t;
        while (true)
        {
            cout << "Enter the time of departure in right order(hh:mm)" << endl;
            cin >> t;
            
            if (t.length() > 5)
            {
                cout << "Wrong order in time" << endl;
            }
            else
            {
                TRAIN[i].TIME = t;
                break;
            }
        }
    }
}

void sortTrain(TIMETABLE* TRAIN, int N) {
    sort(TRAIN, TRAIN + N, [](const TIMETABLE& a, const TIMETABLE& b) {
        return a.NUM < b.NUM;
    });
}

void coutTrain(TIMETABLE* TRAIN, int N) {
    for (int i = 0; i < N; i++)
    {
        cout << endl;
        cout << "TIMETABLE " << i + 1 << ":" << endl;
        cout << "Destination name: " << TRAIN[i].NAZV << endl;
        cout << "Number of train: " << TRAIN[i].NUM << endl;
        if (!TRAIN[i].DATE._Equal("\0"))
        {
            cout << "Date of departure: " << TRAIN[i].DATE << endl;
        }
        else {
            cout << "Date of departure: " << "null" << endl;
        }
        cout << "Time of departure: " << TRAIN[i].TIME << endl;
    }
}

int main()
{
    int N;
    cout << "Enter the TIMETABLE numbers" << endl;
    cin >> N;

    TIMETABLE* TRAIN = new TIMETABLE[N];
    addTrain(TRAIN, N);
    sortTrain(TRAIN, N);
    coutTrain(TRAIN, N);

    int rows, colons;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> colons;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[colons];
    }
    
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colons; j++) {
            cin >> matrix[i][j];
        }
    }


    cout << "Your matrix: " << endl<< endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colons; j++)
        {
            cout << "\t" << matrix[i][j];
        }
        cout << endl;
    }
    
    taskTwo(matrix, rows, colons);
}

void taskTwo(int** matrix, int rows, int colons) {
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colons; j++)
        {
            if (matrix[i][j] == 0)
            {
                count++;
            }
        }
    }

    int resultRow = -1;
    int longestSeriesLength = 0;

    for (int i = 0; i < rows; i++) {
        int currentSeriesLength = 1;
        int maxSeriesLength = 1;

        for (int j = 1; j < colons; j++) {
            if (matrix[i][j] == matrix[i][j - 1]) {
                currentSeriesLength++;
            }
            else {
                currentSeriesLength = 1;
            }

            if (currentSeriesLength > maxSeriesLength) {
                maxSeriesLength = currentSeriesLength;
            }
        }

        if (maxSeriesLength > longestSeriesLength) {
            longestSeriesLength = maxSeriesLength;
            resultRow = i;
        }
    }


    cout << "Colons with zeros: " << count << endl;
    if (resultRow != -1)
    {
        cout << "Row with the most dublicates: " << resultRow << endl;
    }
    else {
        cout << "No rows with dublicaets." << endl;
    }
}