# Problem 1
# An array of 99 elements contains integers from 1 to 100 with one missing element. Find the missing element.

numbers = [92, 71, 26, 74, 58, 69, 91, 55, 17, 88, 100, 54, 89, 15, 49, 11, 16, 14, 80, 24, 19, 63, 93, 44, 25, 33, 20,
           35, 73, 47, 39, 30, 41, 22, 77, 66, 60, 43, 13, 85, 78, 62, 95, 90, 68, 99, 32, 87, 53, 65, 79, 12, 83, 61,
           31, 50, 86, 81, 28, 10, 98, 5, 9, 59, 94, 52, 72, 96, 21, 42, 29, 97, 8, 40, 64, 56, 1, 51, 76, 2, 6, 67, 5,
           7, 70, 45, 37, 18, 23, 36, 4, 82, 3, 34, 46, 38, 48, 84, 27]


def findMissingNumber(number_list):
    """

    :param number_list:
    :return: an array of missing numbers or [-1] if nothing is found
    """
    missing_numbers = []
    for i in range(1, 100):
        if i not in number_list:
            missing_numbers.append(i)

    if not missing_numbers:
        missing_numbers.append(-1)

    return missing_numbers


print("The missing number is: {}".format(findMissingNumber(numbers)))


# Problem 2
# Write a function that determines if a number is prime
# A prime number is a positive integer greater than 1 that is only divisible by 1 and itself

def isPrime(n: int):
    """
    A prime number is a positive integer greater than 1 that is only divisible by 1 and itself.

    TODO: look up prime factorization for speed up.

    :param n: int greater than 1
    :return:
    """
    if n <= 1:
        return False

    for i in range(2, n-1):
        if n % i == 0:
            # print("{} is divisable by {}".format(n, i))
            return False

    return True


print("Is {} Prime? {}".format(-1, isPrime(-1)))
print("Is {} Prime? {}".format(0, isPrime(0)))
print("Is {} Prime? {}".format(1, isPrime(1)))
print("Is {} Prime? {}".format(2, isPrime(2)))
print("Is {} Prime? {}".format(3, isPrime(3)))
print("Is {} Prime? {}".format(11, isPrime(11)))
print("Is {} Prime? {}".format(23, isPrime(23)))
print("Is {} Prime? {}".format(67867979, isPrime(67867979)))
print("Is {} Prime? {}".format(15485869, isPrime(15485869)))

# Problem 3
# Given an array of numbers, replace each number with the product of all the numbers
# in the array except the number itself *WITHOUT* using division

# You may put the resulting values back into the original array or create a new array with the results.

numbers = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
# results = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0]

def array_replace(nums):
    """

    :param nums:
    :return:
    """
    results = []
    for i in range(0, len(nums)):
        results.append(1)
        for j in range(0, len(nums)):
            if i != j:
                results[i] = nums[j] * results[i]

    return results



print(array_replace(numbers))
print(numbers)


# Problem 4
# Write a function that return the column number for an excel column label
# Ex: A=1,  B=2,  AA=27, AB=28, ABC= . . .

def getExcelColumnNumber(excel_header: str):
    """

    [A-Z]* A ==1 Z==26
    AA==27 ~ Base 26number

    :param excel_header:
    :return:
    """
    col_number = 0
    for character in excel_header:
        if character == 'A':
            col_number += 1

    return 0


print("A = {}".format(getExcelColumnNumber("A")))
print("B = {}".format(getExcelColumnNumber("B")))
print("AA = {}".format(getExcelColumnNumber("AA")))
print("BA = {}".format(getExcelColumnNumber("BA")))
print("AAA = {}".format(getExcelColumnNumber("AAA")))
print("XFC = {}".format(getExcelColumnNumber("XFC")))
