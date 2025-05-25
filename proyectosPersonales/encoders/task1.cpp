#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // para std::hex
#include <locale>
#include <codecvt>
#include <cstdint>

using namespace std;

// Convierte string UTF-8 en vector de bytes
vector<uint8_t> utf8ToBytes(const string& utf8) {
    return vector<uint8_t>(utf8.begin(), utf8.end());
}

// Convierte bytes a string UTF-8
string bytesToUtf8(const vector<uint8_t>& bytes) {
    return string(bytes.begin(), bytes.end());
}

// XOR entre dos vectores de bytes
vector<uint8_t> xorData(const vector<uint8_t>& a, const vector<uint8_t>& b) {
    vector<uint8_t> result;
    for (size_t i = 0; i < a.size(); ++i) {
        result.push_back(a[i] ^ b[i]);
    }
    return result;
}

// Imprime bytes en hexadecimal
void printBytes(const vector<uint8_t>& data, const string& label) {
    cout << label << ": ";
    for (uint8_t byte : data) {
        cout << hex << setw(2) << setfill('0') << (int)byte << " ";
    }
    cout << dec << endl;
}

int main() {
    // Establecer salida en UTF-8 si la terminal lo permite
    //setlocale(LC_ALL, "");

    // Textos planos en cirílico
    string P1 = "Привет";  // "Hola" en ruso
    string P2 = "войная";  // "Mundo123"

    // Convertir a bytes
    vector<uint8_t> p1 = utf8ToBytes(P1);
    vector<uint8_t> p2 = utf8ToBytes(P2);

    // Validar tamaños iguales
    if (p1.size() != p2.size()) {
        cerr << "Error: los textos deben tener la misma longitud en bytes." << endl;
        return 1;
    }

    // Clave del mismo tamaño (puede ser aleatoria o fija
    string key_str = "ключ123";
    vector<uint8_t> key = utf8ToBytes(key_str); 
    key.resize(p1.size());


    // Cifrar ambos textos
    vector<uint8_t> c1 = xorData(p1, key);
    vector<uint8_t> c2 = xorData(p2, key);

    // Imprimir resultados
    printBytes(p1, "P1 (Привет)");
    printBytes(p2, "P2 (Мир123)");
    printBytes(key, "Key");
    printBytes(c1, "C1");
    printBytes(c2, "C2");

    // Simular ataque: C1 ⊕ C2 = P1 ⊕ P2
    vector<uint8_t> p1_xor_p2 = xorData(c1, c2);
    printBytes(p1_xor_p2, "P1 ⊕ P2");

    // Descifrado: volver a texto
    vector<uint8_t> p1_decrypted = xorData(c1, key);
    vector<uint8_t> p2_decrypted = xorData(c2, key);

    cout << "\nP1 descifrado: " << bytesToUtf8(p1_decrypted) << endl;
    cout << "P2 descifrado: " << bytesToUtf8(p2_decrypted) << endl;

    cout<< "hóla"<<endl;

    return 0;
}
