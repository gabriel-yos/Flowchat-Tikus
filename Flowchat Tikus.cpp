#include <iostream>
#include <thread>
#include <chrono>
#include <sstream>
#include <locale>
using namespace std;

string getAnswer(string action, string animal = "Tikus") {
    return "\nSTATUS: " + animal + " memutuskan untuk " + action + "\n\n";
}
int main() {
    int choice, tik;

    cout << "--- PROGRAM KEPUTUSAN ---\n\n";

    cout << "Apakah tikus ingin mengambil keju? (1 [Yes] / 0 [No]): ";
    cin >> choice;
    cout << getAnswer(choice == 1 ? "ingin mengambil keju" : "tidak ingin mengambil keju");

    if (choice == 1) {
        cout << "\nSTATUS: Tikus mencari keju. est 3 sec.\n\n";
        this_thread::sleep_for(chrono::seconds(3));
        
        cout << "\nSTATUS: Tikus menemukan keju\n\n";
        this_thread::sleep_for(chrono::seconds(1));

        cout << "Kemana tikus akan membawa keju? (1 [Ke anaknya] / 0 [Tidak membawa kemana mana]): ";
        cin >> choice;
        cout << getAnswer(choice == 1 ? "membawa keju ke anaknya" : "tidak membawa keju");

        if (choice == 1) {
            cout << "\nSTATUS: Tikus berjalan menuju tempat anak anaknya. est 4 sec.\n\n";
            this_thread::sleep_for(chrono::seconds(4));

            cout << "Apakah tikus akan menjaga di depan takut ada kucing? (1 [Menjaga] / 0 [Tidak]): ";
            cin >> tik;
            cout << getAnswer(tik == 1 ? "menjaga di depan agar aman" : "tidak menjaga di depan");

            if (tik == 1) cout << "\nSTATUS: Tikus berjaga jaga didepan agar tidak ada sesuatu yang membahayakan. est 2 sec.\n\n";

            this_thread::sleep_for(chrono::seconds(3));

            cout << "Apakah kucing akan mengawasi tikus? (1 [Mengawasi] / 0 [Tidak]): ";
            cin >> choice;
            cout << getAnswer((choice == 1 ? "mengawasi tikus dari kejauhan" : "tidak mengawasi tikus"), "Kucing");
            if (choice == 1 && tik == 0) {
                cout << "\nSTATUS: Kucing akhirnya mendapatkan moment yang tepat. est 3 sec.\n\n";
                this_thread::sleep_for(chrono::seconds(3));

                cout << "\nSTATUS: Kucing akhirnya menerkan tikus dan anaknya.\n\n";
                this_thread::sleep_for(chrono::seconds(1));
            }
            else cout << "\nSTATUS: Tikus merasa tidak ada yang membahayakan ia lanjut makan bersama anaknya.\n\n";
        }
        else cout << "\nSTATUS: Tikus diam dan memakan keju di tempat\n\n";
    }
    cout << "--- PROGRAM SELESAI ---" << endl;
    return 0;
}
