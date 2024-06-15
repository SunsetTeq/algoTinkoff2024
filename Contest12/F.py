def mod_exp(base, exp, modulus) :
    result = 1
    while exp > 0:
if exp % 2 == 1 :
    result = (result * base) % modulus
    base = (base * base) % modulus
    exp //= 2
    return result


    def mod_inverse(a, mod) :
    return pow(a, mod - 2, mod)


    def main() :
    N, M, K, MOD = map(int, input().split())

    totalCount = mod_exp(M, N, MOD)
    operationsPerSecondInverse = mod_inverse(K, MOD)
    finalResult = (totalCount * operationsPerSecondInverse) % MOD

    print(finalResult)


    main()