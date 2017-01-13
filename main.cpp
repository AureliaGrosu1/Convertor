#include <iostream>
#include <cstring>

using namespace std;

void menu() {
    cout << "\n";
    cout << " 0. Iesire\n";
    cout << " 1. Lungime\n";
    cout << " 2. Arie\n";
    cout << " 3. Volum\n";
    cout << " 4.xTimp\n";
    cout << " 5.xViteza (km /h in mph in m/s)\n";
    cout << " 6.xTemperatura\n";
    cout << " 7. Masa\n";
    cout << " 8.xEnergie\n";
    cout << " 9.xPresiune (bar to psi)\n";
    cout << "10.xDensitate\n";
    cout << "11.xConsum combustibil (din l/100km in mile la galon si km la litru)\n";
    cout << "\n";
    cout << "Alegeti o optiune: ";
}

double tabel[][3] = {{1, 1000, 1000000}, {1000, 1, 1000000}, {1000000, 1000, 1}};
double tabel2[][3] = {{1, 100, 1000000}, {100, 1, 1000000}, {1000000, 100, 1}};
double tabel3[][3] = {{1, 1000, 1000000000}, {1000, 1, 1000000000}, {1000000000, 1000, 1}};

char* umLungime[] = {"mm", "m", "km"};
char* umArie[] = {"mm2", "cm2", "m2"};
char* umVolum[] = {"mm3", "cm3", "m3"};
char* umMasa[] = {"mg", "g", "kg"};

double convertLungime(double val, char umFrom[], char umTo[]) {
    if (strcmp(umFrom, umTo) == 0) {
        return val;
    }
    int idxFrom = 0;
    int idxTo = 0;
    for (int i = 0; i <= 2; i++) {
        if (strcmp(umFrom, umLungime[i]) == 0) {
            idxFrom = i;
        }
        if (strcmp(umTo, umLungime[i]) == 0) {
            idxTo = i;
        }
    }
    if (idxFrom > idxTo) {
        return val * tabel[idxFrom][idxTo];
    } else {
        return val / tabel[idxFrom][idxTo];
    }
}

double convertArie(double val, char umFrom[], char umTo[]) {
    if (strcmp(umFrom, umTo) == 0) {
        return val;
    }
    int idxFrom = 0;
    int idxTo = 0;
    for (int i = 0; i <= 2; i++) {
        if (strcmp(umFrom, umArie[i]) == 0) {
            idxFrom = i;
        }
        if (strcmp(umTo, umArie[i]) == 0) {
            idxTo = i;
        }
    }
    if (idxFrom > idxTo) {
        return val * tabel2[idxFrom][idxTo];
    } else {
        return val / tabel2[idxFrom][idxTo];
    }
}

double convertVolum(double val, char umFrom[], char umTo[]) {
    if (strcmp(umFrom, umTo) == 0) {
        return val;
    }
    int idxFrom = 0;
    int idxTo = 0;
    for (int i = 0; i <= 2; i++) {
        if (strcmp(umFrom, umVolum[i]) == 0) {
            idxFrom = i;
        }
        if (strcmp(umTo, umVolum[i]) == 0) {
            idxTo = i;
        }
    }
    if (idxFrom > idxTo) {
        return val * tabel3[idxFrom][idxTo];
    } else {
        return val / tabel3[idxFrom][idxTo];
    }
}

double convertMasa(double val, char umFrom[], char umTo[]) {
    if (strcmp(umFrom, umTo) == 0) {
        return val;
    }
    int idxFrom = 0;
    int idxTo = 0;
    for (int i = 0; i <= 2; i++) {
        if (strcmp(umFrom, umMasa[i]) == 0) {
            idxFrom = i;
        }
        if (strcmp(umTo, umMasa[i]) == 0) {
            idxTo = i;
        }
    }
    if (idxFrom > idxTo) {
        return val * tabel[idxFrom][idxTo];
    } else {
        return val / tabel[idxFrom][idxTo];
    }
}

int main() {
    int option;

    double val[10];
    char umFrom[10], umTo[10];
    char dummy[10];

    cout.precision(2);

    while (true) {
        menu();
        cin >> option;

        if (option == 0) {
            break;
        }

        switch (option) {
        case 1:
            cout << "Unitati masura: ";
            for (int i = 0; i < 3; i++) {
                cout << umLungime[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 m = ? mm): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertLungime(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        case 2:
            cout << "Unitati masura: ";
            for (int i = 0; i < 3; i++) {
                cout << umArie[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 m2 = ? mm2): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertArie(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        case 3:
            cout << "Unitati masura: ";
            for (int i = 0; i < 3; i++) {
                cout << umVolum[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 m3 = ? mm3): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertVolum(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        case 7:
            cout << "Unitati masura: ";
            for (int i = 0; i < 3; i++) {
                cout << umMasa[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 mg = ? g): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertMasa(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        default:
            cout << "Optiune invalida!\n";
        }
    }

    return 0;
}
