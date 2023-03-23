#include <iostream>
using namespace std;


struct DateTime {
    double year;
    int month;
    int day;
    int hour;
    int minute;
};

struct Sheep
{
    int weight = 40;
    int weightWool = 400;
    DateTime birthday = { 1998,4,25,6,30 };

    void print() {
        cout<< weight << " " << weightWool << " " <<
            birthday.year << " " << birthday.month << endl;
    }
};

void addSheep(Sheep*& sheeps, int& size, Sheep sheep) {
    Sheep* temp = new Sheep[size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = sheeps[i];
    }
    temp[size] = sheep;
    delete[] sheeps;
    sheeps = temp;
    size++;
}

void deliteSheep(Sheep*& sheeps, int& size, int index) {
    Sheep* temp = new Sheep[size - 1];
    if (index <= size) {
    for (int i = 0; i < size; i++) {
        temp[i] = sheeps[i];
    }
    for (int i = index + 1; i < size; i++) {
        temp[i - 1] = sheeps[i];
    }
    delete[] sheeps;
    sheeps = temp;
    size--;
}
    else {
        cout << "u are bed human" << endl;
    }
}


Sheep createSheep(int size = 10) {
    Sheep sheep;
    sheep.weight = rand() % 100 + 20;
    sheep.weightWool = rand() % 100 + 200;
    return sheep;
}

int main()
{
    srand(time(0));
    int size = 10;
    Sheep* arrSheeps = new Sheep[size];

    for (int i = 0; i < size; i++) {
        arrSheeps[i].print();
        cout << endl;
    }
    cout << endl << endl;

    Sheep NewSheep = createSheep(size);
    addSheep(arrSheeps, size,NewSheep);
    for (int i = 0; i < size; i++) {
        arrSheeps[i].print();
        cout << endl;
    }  


    int index;
    cin >> index;
    deliteSheep(arrSheeps,size,index);
    for (int i = 0; i < size; i++) {
        arrSheeps[i].print();
    }

    for (int i = 0; i < size; i++) {
        arrSheeps[i].weight += 1;
        arrSheeps[i].weightWool += 100;
        for (int i = 0; i < size; i++) {
            arrSheeps[i].print();
            cout << endl;
        }

    }

}
