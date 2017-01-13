#include <iostream>
#include <cstring>

#define C 2.3521458

using namespace std;

void menu() {
    cout << "\n";
    cout << " 0. Iesire\n";
    cout << " 1. Lungime\n";
    cout << " 2. Arie\n";
    cout << " 3. Volum\n";
    cout << " 4. Timp\n";
    cout << " 5. Viteza\n";
    cout << " 6. Temperatura\n";
    cout << " 7. Masa\n";
    cout << " 8. Energie\n";
    cout << " 9. Presiune (bar to psi)\n";
    cout << "10.xDensitate\n";
    cout << "11.xConsum combustibil (din l/100km in mile la galon si km la litru)\n";
    cout << "Alegeti o optiune: ";
}

double tabel[][3] = {{1, 1000, 1000000}, {1000, 1, 1000000}, {1000000, 1000, 1}};
double tabel2[][3] = {{1, 100, 1000000}, {100, 1, 1000000}, {1000000, 100, 1}};
double tabel3[][3] = {{1, 1000, 1000000000}, {1000, 1, 1000000000}, {1000000000, 1000, 1}};
double tabelTimp[][3] = {{1, 60, 3600}, {60, 1, 3600}, {3600, 60, 1}};
double tabelViteza[][3] = {{1, 60, 0.277777778}, {60, 1, 1000}, {0.277777778, 1000, 1}};
double tabelConsumBkp[][2] = {{2.3521458, 235.21458}, {0.023521458, 2.3521458}};
double tabelConsum[][4] = {{1, 100, C, C*100}, {1/100, 1, C/100, C}, {1/C, 1/(C*100), 1, 100}, {100/C, 1/C, 1/100, 1}};

char* umLungime[] = {"mm", "m", "km"};
char* umArie[] = {"mm2", "cm2", "m2"};
char* umVolum[] = {"mm3", "cm3", "m3"};
char* umTimp[] = {"s", "m", "h"};
char* umViteza[] = {"mps", "mph", "kmph"};
char* umTemp[] = {"C", "F"};
char* umMasa[] = {"mg", "g", "kg"};
char* umEnergie[] = {"J", "kJ", "mJ"};
char* umPresiune[] = {"bar", "psi"};
char* umConsum[] = {"gpmi", "gp100mi", "lpkm", "lp100km"};

double convertLungime(double val, char umFrom[], char umTo[]) {
    if (strcmp(umFrom, umTo) == 0) {
        return val;
    }
    int idxFrom = -1;
    int idxTo = -1;
    for (int i = 0; i < 3; i++) {
        if (strcmp(umFrom, umLungime[i]) == 0) {
            idxFrom = i;
        }
        if (strcmp(umTo, umLungime[i]) == 0) {
            idxTo = i;
        }
    }
    if ((idxFrom == -1) || (idxTo == -1)) {
        cout << "Unitate de masura invalida!";
        return -1;
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
    int idxFrom = -1;
    int idxTo = -1;
    for (int i = 0; i < 3; i++) {
        if (strcmp(umFrom, umArie[i]) == 0) {
            idxFrom = i;
        }
        if (strcmp(umTo, umArie[i]) == 0) {
            idxTo = i;
        }
    }
    if ((idxFrom == -1) || (idxTo == -1)) {
        cout << "Unitate de masura invalida!";
        return -1;
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
    int idxFrom = -1;
    int idxTo = -1;
    for (int i = 0; i < 3; i++) {
        if (strcmp(umFrom, umVolum[i]) == 0) {
            idxFrom = i;
        }
        if (strcmp(umTo, umVolum[i]) == 0) {
            idxTo = i;
        }
    }
    if ((idxFrom == -1) || (idxTo == -1)) {
        cout << "Unitate de masura invalida!";
        return -1;
    }
    if (idxFrom > idxTo) {
        return val * tabel3[idxFrom][idxTo];
    } else {
        return val / tabel3[idxFrom][idxTo];
    }
}

double convertTimp(double val, char umFrom[], char umTo[]) {
    if (strcmp(umFrom, umTo) == 0) {
        return val;
    }
    int idxFrom = -1;
    int idxTo = -1;
    for (int i = 0; i < 3; i++) {
        if (strcmp(umFrom, umTimp[i]) == 0) {
            idxFrom = i;
        }
        if (strcmp(umTo, umTimp[i]) == 0) {
            idxTo = i;
        }
    }
    if ((idxFrom == -1) || (idxTo == -1)) {
        cout << "Unitate de masura invalida!";
        return -1;
    }
    if (idxFrom > idxTo) {
        return val * tabelTimp[idxFrom][idxTo];
    } else {
        return val / tabelTimp[idxFrom][idxTo];
    }
}

double convertViteza(double val, char umFrom[], char umTo[]) {
    if (strcmp(umFrom, umTo) == 0) {
        return val;
    }
    int idxFrom = -1;
    int idxTo = -1;
    for (int i = 0; i < 3; i++) {
        if (strcmp(umFrom, umViteza[i]) == 0) {
            idxFrom = i;
        }
        if (strcmp(umTo, umViteza[i]) == 0) {
            idxTo = i;
        }
    }
    if ((idxFrom == -1) || (idxTo == -1)) {
        cout << "Unitate de masura invalida!";
        return -1;
    }
    if (idxFrom > idxTo) {
        return val * tabelViteza[idxFrom][idxTo];
    } else {
        return val / tabelViteza[idxFrom][idxTo];
    }
}

double convertTemp(double val, char umFrom[], char umTo[]) {
    if (strcmp(umFrom, umTo) == 0) {
        return val;
    }
    if (strcmp(umFrom, "C") == 0) {
        return val * 9 / 5 + 32;
    } else if (strcmp(umFrom, "F") == 0) {
        return (val - 32) * 5 / 9;
    } else {
        cout << "Unitate de masura invalida!";
    }
    return -1;
}

double convertMasa(double val, char umFrom[], char umTo[]) {
    if (strcmp(umFrom, umTo) == 0) {
        return val;
    }
    int idxFrom = -1;
    int idxTo = -1;
    for (int i = 0; i < 3; i++) {
        if (strcmp(umFrom, umMasa[i]) == 0) {
            idxFrom = i;
        }
        if (strcmp(umTo, umMasa[i]) == 0) {
            idxTo = i;
        }
    }
    if ((idxFrom == -1) || (idxTo == -1)) {
        cout << "Unitate de masura invalida!";
        return -1;
    }
    if (idxFrom > idxTo) {
        return val * tabel[idxFrom][idxTo];
    } else {
        return val / tabel[idxFrom][idxTo];
    }
}

double convertEnergie(double val, char umFrom[], char umTo[]) {
    if (strcmp(umFrom, umTo) == 0) {
        return val;
    }
    int idxFrom = -1;
    int idxTo = -1;
    for (int i = 0; i < 3; i++) {
        if (strcmp(umFrom, umEnergie[i]) == 0) {
            idxFrom = i;
        }
        if (strcmp(umTo, umEnergie[i]) == 0) {
            idxTo = i;
        }
    }
    if ((idxFrom == -1) || (idxTo == -1)) {
        cout << "Unitate de masura invalida!";
        return -1;
    }
    if (idxFrom > idxTo) {
        return val * tabel[idxFrom][idxTo];
    } else {
        return val / tabel[idxFrom][idxTo];
    }
}

double convertPresiune(double val, char umFrom[], char umTo[]) {
    if (strcmp(umFrom, umTo) == 0) {
        return val;
    }
    if (strcmp(umFrom, "bar") == 0) {
        return val * 14.5037738;
    } else if (strcmp(umFrom, "psi") == 0) {
        return val / 14.5037738;
    } else {
        cout << "Unitate de masura invalida!";
    }
    return -1;
}

double convertConsum(double val, char umFrom[], char umTo[]) {
    if (strcmp(umFrom, umTo) == 0) {
        return val;
    }
    int idxFrom = -1;
    int idxTo = -1;
    for (int i = 0; i < 4; i++) {
        if (strcmp(umFrom, umConsum[i]) == 0) {
            idxFrom = i;
        }
        if (strcmp(umTo, umConsum[i]) == 0) {
            idxTo = i;
        }
    }
    if ((idxFrom == -1) || (idxTo == -1)) {
        cout << "Unitate de masura invalida!";
        return -1;
    }
    return val * tabelConsum[idxFrom][idxTo];
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
            cout << "\nUnitati masura: ";
            for (int i = 0; i < 3; i++) {
                cout << umLungime[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 m = ? mm): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertLungime(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        case 2:
            cout << "\nUnitati masura: ";
            for (int i = 0; i <= 3; i++) {
                cout << umArie[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 m2 = ? mm2): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertArie(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        case 3:
            cout << "\nUnitati masura: ";
            for (int i = 0; i < 3; i++) {
                cout << umVolum[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 m3 = ? mm3): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertVolum(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        case 4:
            cout << "\nUnitati masura: ";
            for (int i = 0; i < 3; i++) {
                cout << umTimp[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 m = ? s): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertTimp(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        case 5:
            cout << "\nUnitati masura: ";
            for (int i = 0; i < 3; i++) {
                cout << umViteza[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 mph = ? mps): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertViteza(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        case 6:
            cout << "\nUnitati masura: ";
            for (int i = 0; i < 2; i++) {
                cout << umTemp[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 C = ? F): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertTemp(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        case 7:
            cout << "\nUnitati masura: ";
            for (int i = 0; i < 3; i++) {
                cout << umMasa[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 mg = ? g): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertMasa(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        case 8:
            cout << "\nUnitati masura: ";
            for (int i = 0; i < 3; i++) {
                cout << umEnergie[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 kJ = ? J): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertEnergie(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        case 9:
            cout << "\nUnitati masura: ";
            for (int i = 0; i < 2; i++) {
                cout << umPresiune[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 bar = ? psi): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertPresiune(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        case 11:
            cout << "\nUnitati masura: ";
            for (int i = 0; i < 4; i++) {
                cout << umConsum[i] << " ";
            }
            cout << "\nIntroduceti expresia pentru convertit (ex: 5 gp100mi = ? lp100km): ";
            cin >> val[0] >> umFrom >> dummy >> dummy >> umTo;
            cout  << std::fixed << convertConsum(val[0], umFrom, umTo) << " " << umTo << "\n";
            break;
        default:
            cout << "Optiune invalida!\n";
        }
    }

    return 0;
}
