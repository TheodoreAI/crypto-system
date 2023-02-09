# C++ RSA Library

#### Mateo Estrada Jorge
#### Feb 08, 2023
#### Crypto system

### The system is written for RSA:
- It is a public-key cryptosystem that is widely used for secure data transmission.
- The security of RSA is based on the mathematical problem of factorization, i.e., it is hard to factorize a large composite number into its prime factors.
- Key Generation: Select two large prime numbers, p and q, and compute n = p * q. Compute φ(n) = (p - 1) * (q - 1) and select a public key exponent, e, such that 1 < e < φ(n) and e is coprime to φ(n). Compute a private key exponent, d, such that d * e ≡ 1 (mod φ(n)).
- Encryption: Given a message m and a public key (n, e), the encryption is computed as c ≡ m^e (mod n).
- Decryption: Given a ciphertext c and a private key d, the decryption is computed as m ≡ c^d (mod n).
- Complexity: The encryption and decryption operations in RSA are both exponential in the number of bits in the key size, making it relatively slow for larger key sizes.

# Requirements:
1. Key Generation: The library should have a function for generating RSA key pairs, including both public and private keys.
2. Key Storage: The library should have the ability to securely store the generated keys, either on disk or in memory.
3. Key Encryption: The library should have the ability to encrypt messages using the public key.
4. Key Decryption: The library should have the ability to decrypt messages using the private key.
5. Key Size: The library should support key sizes ranging from 512 to 4096 bits.
6. Modulus Generation: The library should have a function for generating a modulus that meets the required security standards.
7. Prime Number Generation: The library should have a function for generating large prime numbers to be used in the key generation process.
8. Random Number Generation: The library should have a function for generating random numbers for use in key generation and encryption/decryption operations.
9. Error Handling: The library should have robust error handling mechanisms to catch and report any exceptions or errors that may occur during encryption/decryption operations.
10. Security: The library should implement best practices for security, such as using secure random number generators and proper key storage mechanisms, to ensure the confidentiality and integrity of the data being encrypted/decrypted.
