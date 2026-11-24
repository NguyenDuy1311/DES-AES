#ifndef DES_HPP
#define DES_HPP

#include <array>
#include <cstdint>
#include <iostream>

class DES {
public:
    explicit DES(uint64_t key, bool verbose = false);

    uint64_t encrypt(uint64_t plaintext, bool verbose = false) const;
    uint64_t decrypt(uint64_t ciphertext, bool verbose = false) const;

private:
    std::array<uint64_t, 16> subkeys_{};

    static uint64_t permute(uint64_t src, const uint8_t* table, int in_bits, int out_bits);
    static uint32_t rotl28(uint32_t val, int shift);
    static uint32_t feistel(uint32_t right, uint64_t subkey, int round, bool verbose);
    uint64_t run_rounds(uint64_t block, bool is_decrypt, bool verbose) const;
};

#endif