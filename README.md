# TinyRSA

Toy implementation of the RSA cryptography algorithm.

Compile with `make`.

Executable files:

- `new_key.out` - Generates a new pair of RSA keys.
- `encrypt.out` - Requests a public key and a message and prints the same message encrypted using the given key.
- `decrypt.out` - Requests a private key and an encrypted message and prints the message decrypted using the given key.
- `hack.out`- Requests a public key and a message encrypted with it and, by brute force, deducts the prime numbers used to generate the pair of keys. Then, the message is decrypted and the result printed. 


Usage examples:

```
$ ./new_key.out 
P: 8641,   Q: 5227
New private key:  <45166507 5250307>
New public key:   <45166507 43>
```
```
$ ./encrypt.out 
Public key > 45166507 43
Message: 
> Hello World!

Encrypted message:
41649630 35971862 29019764 29019764 18963172 18209884 32387372 18963172 11949822 29019764 7630578 11614059 0
```

```
$ ./decrypt.out
Private key > 45166507 5250307
Encrypted message:
> 41649630 35971862 29019764 29019764 18963172 18209884 32387372 18963172 11949822 29019764 7630578 11614059 0 

Decrypted message:
	'Hello World!'
```
```
$ ./hack.out 
Shame on you, Eve!!

Public key > 45166507 43
Prime numbers: 5227 & 8641

Encrypted message:
 > 41649630 35971862 29019764 29019764 18963172 18209884 32387372 18963172 11949822 29019764 7630578 11614059 0 

Decrypted message:
	'Hello World!'
```
---

April 2016
