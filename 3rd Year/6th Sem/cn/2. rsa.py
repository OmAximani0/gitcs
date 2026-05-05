import math
import random


def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(math.sqrt(num)+1)):
        if num % i == 0:
            return False
    return True


def gen_prime(bits):
    while True:
        num = random.getrandbits(bits)
        if is_prime(num):
            return num


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def mod_inverse(a, m):
    m0, x0, x1 = m, 0, 1
    while a > 1:
        q = a // m
        m, a = a % m, m
        x0, x1 = x1 - q * x0, x0
    return x1 + m0 if x1 < 0 else x1


def gen_keys(bits):
    p = gen_prime(bits)
    q = gen_prime(bits)
    n = p * q
    phi = (p-1) * (q-1)

    while True:
        e = random.randint(2, phi-1)
        if gcd(e, phi) == 1:
            break

    d = mod_inverse(e, phi)

    pub = (n, e)
    pri = (n, d)

    return pub, pri


def enc(pub, msg):
    n, e = pub
    cipher = [pow(ord(char), e, n) for char in msg]
    return cipher


def dec(pri, cip):
    n, d = pri
    msg = "".join([chr(pow(char, d, n)) for char in cip])
    return msg


if __name__ == "__main__":
    bits = 8  # Adjust the number of bits for your desired security level
    public_key, private_key = gen_keys(bits)
    print(f" Generated Public Key : {
          public_key} \n Generated Private Key : {private_key}")

    message = (input(" Enter the Message to be Encrypted : "))
    print(" Original message:", message)

    encrypted_message = enc(public_key, message)
    print(" Encrypted message:", encrypted_message)

    dec = dec(private_key, encrypted_message)  # type:ignore
    print(" Encrypted message:", dec)
