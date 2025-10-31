#include <iostream>
#include <limits>
#include <string>

using namespace std;

template <typename T>
T get_value(const string& error_message) {
    T value;
    while (!(cin >> value)) {
        cout << error_message << "\n";
        cout << "Введите значение снова: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << endl;

    int N, M;

    while (true) {
        cout << "Введите количество строк (N): ";
        N = get_value<int>("Ошибка: Ввод не является числом.");
        if (N > 0)
        {
            break;
        }

        cout << "Ошибка: Количество строк должно быть положительным.\n";
    }

    while (true) {
        cout << "Введите количество столбцов (M): ";
        M = get_value<int>("Ошибка: Ввод не является числом.");
        if (M > 0)
        {
            break;
        }
        cout << "Ошибка: Количество столбцов должно быть положительным.\n";
    }

    int** matrix = new int*[N];
    for (int i = 0; i < N; ++i) {
        matrix[i] = new int[M];
    }


    cout << "\nВведите " << N * M << " элементов матрицы (построчно):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << "Введите элемент " << i+1 << "-ой строки " << j+1 << "-ого столбца: ";
            matrix[i][j] = get_value<int>("Ошибка: Ввод не является числом.");
        }
    }


    if (N == 1)
    {
        cout << "Особых элементов не может существовать так как N = 1\n";

        for (int i = 0; i < N; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;

        return 0;
    }

    int specialCount = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int j = 0; j < M; ++j) {
        long long columnSum = 0;
        for (int i = 0; i < N; ++i) {
            columnSum += matrix[i][j];
        }

        for (int i = 0; i < N; ++i) {
            long long sumOfOthers = columnSum - matrix[i][j];

            if (matrix[i][j] > sumOfOthers) {
                cout << "  -> Найден 'особый' элемент в " << i+1 << "-ой строке " << j+1 << "-ом столбце: "
                     << matrix[i][j] << " (т.к. " << matrix[i][j] << " > " << sumOfOthers << ")\n";
                specialCount++;
            }
        }
    }

    cout << "________________________________________________________________________\n";
    cout << "Общее количество особых элементов: " << specialCount << endl;

    for (int i = 0; i < N; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}