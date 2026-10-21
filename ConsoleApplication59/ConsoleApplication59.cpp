#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Array {
private:
    long* arr;
    int size;

public:
    Array() {
        this->size = 0;
        this->arr = nullptr;
    }

    Array(int size) {
        if (size < 0) size = 0;

        this->size = size;
        this->arr = size > 0 ? new long[size]() : nullptr;
    }

    Array(const Array& other) {
        this->size = other.size;
        this->arr = size > 0 ? new long[size] : nullptr;

        for (int i = 0; i < size; i++) {
            this->arr[i] = other.arr[i];
        }
    }

    ~Array() {
        delete[] arr;
    }

    void FillDefault() {
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    void FillRandom() {
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 201 - 100;
        }
    }

    void FillKeyboard() {
        for (int i = 0; i < size; i++) {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
    }

    void Show() const {
        if (size == 0) {
            cout << "Масив порожній!" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    void Add(long value) {
        long* temp = new long[size + 1];

        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        temp[size] = value;

        delete[] arr;
        arr = temp;
        size++;
    }

    void RemoveByIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Неправильний індекс!" << endl;
            return;
        }

        long* temp = size > 1 ? new long[size - 1] : nullptr;

        for (int i = 0, j = 0; i < size; i++) {
            if (i != index) {
                temp[j++] = arr[i];
            }
        }

        delete[] arr;
        arr = temp;
        size--;
    }

    void RemoveByValue(long value) {
        int index = -1;

        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Елемент не знайдено!" << endl;
            return;
        }

        RemoveByIndex(index);
    }

    void SortAscending() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    long temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void SortDescending() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    long temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void MinMax() const {
        if (size == 0) {
            cout << "Масив порожній!" << endl;
            return;
        }

        long min = arr[0];
        long max = arr[0];

        for (int i = 1; i < size; i++) {
            if (arr[i] < min) min = arr[i];
            if (arr[i] > max) max = arr[i];
        }

        cout << "Мінімум: " << min << endl;
        cout << "Максимум: " << max << endl;
    }

    void Average() const {
        if (size == 0) {
            cout << "Масив порожній!" << endl;
            return;
        }

        double sum = 0;

        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }

        cout << "Середнє арифметичне: "
            << sum / size << endl;
    }

    int GetSize() const {
        return this->size;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    Array a(5);

    a.FillRandom();

    cout << "Початковий масив: ";
    a.Show();

    a.Add(50);
    cout << "Після додавання: ";
    a.Show();

    a.RemoveByIndex(0);
    cout << "Після видалення за індексом: ";
    a.Show();

    a.RemoveByValue(50);
    cout << "Після видалення за значенням: ";
    a.Show();

    a.SortAscending();
    cout << "Сортування за зростанням: ";
    a.Show();

    a.SortDescending();
    cout << "Сортування за спаданням: ";
    a.Show();

    a.MinMax();
    a.Average();

    Array b(a);

    cout << "Копія масиву: ";
    b.Show();

    return 0;
}
