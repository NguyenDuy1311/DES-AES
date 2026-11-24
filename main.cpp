#include "des.hpp"
#include "aes128.hpp"
#include <iomanip>
#include <iostream>

int main() {
    uint64_t des_pt  = 0x0123456789ABCDEFULL;
    uint64_t des_key = 0x133457799BBCDFF1ULL;

    DES des(des_key, true);
    uint64_t des_ct  = des.encrypt(des_pt, true);
    uint64_t des_dec = des.decrypt(des_ct, false);

    std::cout << "\n[DES VERIFY] Ciphertext = " << std::uppercase << std::hex
              << std::setw(16) << std::setfill('0') << des_ct
              << " | Decrypted = " << std::setw(16) << des_dec
              << " | Match: " << (des_dec == des_pt ? "OK" : "FAIL") << "\n\n";


    return 0;
}