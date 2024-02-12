# python program to find factorial of any number (n)

def factorial(n):
    if n == 0 or n==1:
        return 1

    else:
        return (n * factorial(n-1))


number = int(input("Enter any number: "))
print(factorial(number))
print(hex(number))
