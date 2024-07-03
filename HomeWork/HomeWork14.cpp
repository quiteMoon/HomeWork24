#include <iostream>
#include <cstring>

using namespace std;

class People {
private:
    char* Fullname;

public:
    People(const char* name) {
        Fullname = new char[strlen(name) + 1];
        strcpy_s(Fullname, strlen(name) + 1, name);
    }

    People(const People& other) {
        Fullname = new char[strlen(other.Fullname) + 1];
        strcpy_s(Fullname, strlen(other.Fullname) + 1, other.Fullname);
    }

    People& operator=(const People& other) {
        if (this == &other) {
            return *this;
        }
        delete[] Fullname;
        Fullname = new char[strlen(other.Fullname) + 1];
        strcpy_s(Fullname, strlen(other.Fullname) + 1, other.Fullname);
        return *this;
    }

    ~People() {
        delete[] Fullname;
    }

    void print() {
        cout << "People: " << Fullname << endl;
    }
};

class Apart {
private:
    People** res;
    int resCount;

public:
    Apart() : res(nullptr), resCount(0) {}

    void addResident(const People& person) {
        People** newRes = new People * [resCount + 1];
        for (int i = 0; i < resCount; ++i) {
            newRes[i] = res[i];
        }
        newRes[resCount] = new People(person);
        delete[] res;
        res = newRes;
        ++resCount;
    }

    Apart(const Apart& other) : res(nullptr), resCount(0) {
        for (int i = 0; i < other.resCount; ++i) {
            addResident(*other.res[i]);
        }
    }

    Apart& operator=(const Apart& other) {
        if (this == &other) {
            return *this;
        }
        for (int i = 0; i < resCount; ++i) {
            delete res[i];
        }
        delete[] res;
        res = nullptr;
        resCount = 0;
        for (int i = 0; i < other.resCount; ++i) {
            addResident(*other.res[i]);
        }
        return *this;
    }

    ~Apart() {
        for (int i = 0; i < resCount; ++i) {
            delete res[i];
        }
        delete[] res;
    }

    void print()  {
        cout << "Apartment with " << resCount << " residents:" << endl;
        for (int i = 0; i < resCount; ++i) {
            res[i]->print();
        }
    }
};

class House {
private:
    Apart* apartments;
    int apartCount;

public:
    House() : apartments(nullptr), apartCount(0) {}

    void addApartment(const Apart& apartment) {
        Apart* newApart = new Apart[apartCount + 1];
        for (int i = 0; i < apartCount; ++i) {
            newApart[i] = apartments[i];
        }
        newApart[apartCount] = apartment;
        delete[] apartments;
        apartments = newApart;
        ++apartCount;
    }

    House(const House& other) : apartments(nullptr), apartCount(0) {
        for (int i = 0; i < other.apartCount; ++i) {
            addApartment(other.apartments[i]);
        }
    }

    House& operator=(const House& other) {
        if (this == &other) {
            return *this;
        }
        delete[] apartments;
        apartments = nullptr;
        apartCount = 0;
        for (int i = 0; i < other.apartCount; ++i) {
            addApartment(other.apartments[i]);
        }
        return *this;
    }

    ~House() {
        delete[] apartments;
    }

    void print()  {
        cout << "House with " << apartCount << " apartments:" << endl;
        for (int i = 0; i < apartCount; ++i) {
            apartments[i].print();
        }
    }
};

int main() {
    People p1("John Van");
    People p2("Tom Doe");
    People p3("Jone Lon");

    Apart a1;
    a1.addResident(p1);
    Apart a2;
    a2.addResident(p2);
    a2.addResident(p3);

    House h;
    h.addApartment(a1);
    h.addApartment(a2);

    h.print();

}
