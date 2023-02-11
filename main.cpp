// Mateo Estrada Jorge
// Feb 09, 2023
// This program implements the RSA cryptosystem to encrypt and decrypt messages.
// Resource: https://www.sanfoundry.com/cpp-program-implement-rsa-algorithm/
// Resource: https://www.geeksforgeeks.org/rsa-algorithm-cryptography/
// wiki: https://en.wikipedia.org/wiki/RSA_(cryptosystem)

// Preprocessor directives
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>
#include <fstream>



using namespace std;

// Function prototypes
// using the following steps:
// 1. Generate two large prime numbers
// 2. Compute n = p * q
// 3. Compute phi(n) = (p - 1) * (q - 1)
// 4. Choose an integer e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
// 5. Compute d such that d * e = 1 mod phi(n)
// 6. Store the public key (n, e) and the private key (n, d) in a text file
long int p, q, n, t, flag, temp[100], j, m[100], en[100], i;
long int e[100]; // public key
long int d[100]; // private key
char msg[100];
int prime(long int);
void calculatePublicKey(); //
long int calculatePrivateKey(long int); // 
void encrypt();
void decrypt();
int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

int makeRandomPrime(){
    int num = rand() % 1000;
    while(!prime(num)){
        num = rand() % 1000;
    }
    return num;
}

int main()
{
    cout << "RSA Cryptosystem" << endl;
    p = makeRandomPrime();
    q = makeRandomPrime();

    cout << "\nEnter message\n";
fflush(stdin);
cin.getline(msg, sizeof(msg));
for(i = 0; msg[i] != '\0'; i++){
    m[i] = msg[i];
}
    n = p * q;
    t = (p-1)*(q-1);
    calculatePublicKey();
    cout << "\n possible values of e and d are:\n";
    for(i = 0; i < j - 1; i++){
        cout<< e[i] << "\t" << d[i] << "\n";
    }
    encrypt();
    decrypt();
    return 0;
}


// Function declarations
// calculate public key e with private key d
void calculatePublicKey(){
    int k;
    k = 0;
    for(i = 2; i < t; i++){
        if(t%i ==0){
            continue;
        }
        flag = prime(i);
        if(flag == 1 && i != p && i != q){
            e[k] = i;
            flag = calculatePrivateKey(e[k]);
            if (flag > 0){
                d[k] = flag;
                k++;
            }
            if(k == 99){
                break;
            }
        }
    }
}
// calculate private key d with private key e
long int calculatePrivateKey(long int x){
    long int k = 1;
    while(1){
        k = k + t;
        if(k % x ==0){
            return (k / x);
        }
    }
}
void encrypt(){
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = strlen(msg);
    while(i != len){
        pt = m[i];
        pt = pt -96;
        k = 1;
        for(j = 0; j < key; j++){
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "\nThe encrypted message: \n";
    for(i = 0; en[i] != -1; i++){
        printf("%c", (char)en[i]);
    }
    // put the encrypted message in a file called encrypted.txt in text format

    ofstream myfile;
    myfile.open("encrypted.txt");
    for(i = 0; en[i] != -1; i++){
        myfile << en[i];
    }
    myfile.close();
    
}


void decrypt(){
    long int pt, ct, key = d[0], k;
    i = 0;
    while(en[i] != -1){
        ct = temp[i];
        k = 1;
        for(j = 0; j < key; j++)
        {
            k = k*ct;
            k = k%n;

        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }

    m[i] = -1;
    cout << "\n The decrypted message: \n";
    for(i = 0; m[i] != -1; i++){
        // check if the character is a space in the message and print it
        printf("%c", (char)m[i]); // format specifies type int but the argument has type long, so we need to cast it
       
    }
    // put the decrypted message in text format like so: msg: messageContent, a file called decrypted.txt
    ofstream myfile;
    myfile.open("decrypted.txt");
    myfile << "msg: ";
    for(i = 0; m[i] != -1; i++){
        
        myfile << (char)m[i];
    }
    myfile.close();
}
