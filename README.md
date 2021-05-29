# Algorithmic_Toolbox
EDU. Set of small programs implementing various algorithms.

## Greedy Algorithms

### Greatest Common Divisor
* gcd.cpp

#### Euclid's algorithm
    gcd(a, b) = gcd (b, a mod b)

where

    a mod b = a − b ⌊ a b ⌋

If the arguments are both greater than zero, then the algorithm can be written in more elementary terms as follows:

    gcd(a, b) = gcd(a − b, b), if a >= b
    gcd(a, b) = gcd(a, b − a), else

### Least Common Multiple
* lcm.cpp

    lcm(a, b) = |a*b| / gcd(a,b)


### Largest number
* largest_number.cpp

Example of lexicographic sorting of integers in C++

## Divide-and-Conquer

### Quick sort
* quicksort3.cpp

### Polynomial Multiplication
* not yet

#### Karatsuba approach

A(x) = a_1 x + a_0

B(x) = b_1 x + b_0

A(x)B(x) = a1b1*x2 + ((a1+a0)(b1+b0) − a1b1 − a0b0)x + a0b0

## Dynamic Programming

### Edit distance

### Knapsack 

## Other

### Euler's totient function

[Wiki Euler's totient function](https://ru.wikipedia.org/wiki/%D0%A4%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D1%8F_%D0%AD%D0%B9%D0%BB%D0%B5%D1%80%D0%B0#%D0%A4%D1%83%D0%BD%D0%BA%D1%86%D0%B8%D1%8F_%D0%AD%D0%B9%D0%BB%D0%B5%D1%80%D0%B0_%D0%BE%D1%82_%D0%BD%D0%B0%D1%82%D1%83%D1%80%D0%B0%D0%BB%D1%8C%D0%BD%D0%BE%D0%B3%D0%BE_%D1%87%D0%B8%D1%81%D0%BB%D0%B0)
[Binomial coefficient](https://ru.wikipedia.org/wiki/%D0%91%D0%B8%D0%BD%D0%BE%D0%BC%D0%B8%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D0%B9_%D0%BA%D0%BE%D1%8D%D1%84%D1%84%D0%B8%D1%86%D0%B8%D0%B5%D0%BD%D1%82)

Вычислить значение функции Эйлера от некоторого биномиального коэффициента («выбрать k элементов из n»).

