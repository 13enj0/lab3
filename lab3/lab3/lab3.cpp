#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// функція для створення префікс-таблиці для алгоритму КМП
vector<int> computePrefixFunction(vector<int> pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);

    int k = 0;
    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            k++;
        }
        pi[i] = k;
    }

    return pi;
}

// функція для знаходження підстроки в масиві цілих чисел
void findSubarray(vector<int> array, vector<int> pattern) {
    int n = array.size();
    int m = pattern.size();

    // створення префікс-таблиці для підстроки
    vector<int> pi = computePrefixFunction(pattern);
    int g = 0;
    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != array[i]) {
            q = pi[q - 1];
        }
        if (pattern[q] == array[i]) {
            q++;
        }
        if (q == m) {
            cout << "Пiдстрока знайдена починаючи з iндексу " << i - m + 1 << endl;
            q = pi[q - 1];
            g++;
        }
    }

    if (g == 0) {
        cout << "Пiдстрока не знайдена" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ukr");
    srand(time(NULL));
    vector<int> array(400);
    int n;

    vector<int> pattern; // оголошуємо масив розміром 10
    ifstream input("F:\\Алгоритми та структури даних\\lab3\\lab3\\x64\\Debug\\pattern.txt"); // відкриваємо файл для зчитування
    if (input.is_open()) { // перевіряємо, чи файл було відкрито успішно
        for (int i = 0; i < 2; i++) {
            input >> n;
             pattern.push_back(n); // зчитуємо елемент масиву з файлу
        }
        input.close(); // закриваємо файл
    }
    else {
        cout << "Unable to open file"; // повідомляємо про помилку, якщо файл не було відкрито
    }

    // виводимо зчитані елементи масиву на екран
    for (int i = 0; i < 2; i++) {
        cout << pattern[i] << " ";
    }
    cout << endl;




    // заповнення масиву з 400 елементів в межах від 1 до 10
    for (int i = 0; i < 400; i++) {
        array[i] =1+ rand() % 11;
    }

    findSubarray(array, pattern);

    return 0;
}
