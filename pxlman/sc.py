# code to scrape the data from an api
# API structure: https://newton.now.sh/api/v2/factor/x^2-1

import requests
import json
def toExpr(arr):
    n = arr[0]
    i1 = 0
    expr1 = "".join([str(c)+"x^"+str(i1)+"+" for c in arr[1].split(" ")])
    i1+= 1
    expr1 = expr1[:len(expr1)-1]
    i2 = 0
    expr2 = "".join([str(c)+"x^"+str(i2) for c in arr[1].split(" ")])
    i2 += 1
    expr2 = expr2[:len(expr2)-1]
    return {deg:n, expression1:expr1, expression2:expr2}
def simplify(expression):
    url = "https://newton.now.sh/api/v2/simplify/" + expression
    data = requests.get(url).json().get('result')
    return data
# Summation of two expressions
def sum(expression1,expression2):
    url = "https://newton.now.sh/api/v2/simplify/" + expression1 + "+" + expression2
    data = requests.get(url).json().get('result')
    return data
# Subtraction of two expressions
def sub(expression1,expression2):
    url = "https://newton.now.sh/api/v2/simplify/(" + expression1 + ") - (" + expression2 + ')'
    data = equests.get(url).json().get('result')
    return data
# Product of two expressions
def product(expression1,expression2):
    url = "https://newton.now.sh/api/v2/simplify/(" + expression1 + " ) * ( " + expression2 + ' )'
    data = requests.get(url).json().get('result')
    return data
# Derivative of an expression
def derivative(expression):
    url = "https://newton.now.sh/api/v2/derive/" + expression
    data = requests.get(url).json().get('result')
    return data
# Integration of an expression
def interal(expression):
    url = "https://newton.now.sh/api/v2/integrate/" + expression
    data = requests.get(url).json().get('result')
    return data
# Definite integration of an expression from 0 to 1
def difinite_integration(expression):
    url = "https:/newton.now.sh/api/v2/integrate/" + expression
    data = requests.get(url).json().get('result')
    at0 = data.replace('x', 0)
    simplified_at0 = simplify(at0)
    at1 = data.replace('x', 1)
    simplified_at1 = simplify(at1)
    result = sub(simplifie_at1, simplified_at0)
    return data
# Evaluate an expression at x = 2
def at2(expression):
    expression = expression.replace('x', '2')
    url = "https://newton.now.sh/api/v2/simplify/" + expression
    data = requests.get(url).json().get('result')
    return data
def degree(expression):
    while len(expression) > 2:
        if expression[expression.rfind('x^') -1] != '0':
            return expression[expression.rfind('x^') +2]
        else:
            expression = expression[:expression.rfind('x^') - 1]
    return 0

def generateTestCases():
    testCases = []
    for i in range(30):
        pol1 = []
        pol2 = []
        for j in range(random.randint(0, 12)):
            pol1.append(random.randint(1, 30) - 15)
            pol2.append(random.randint(1, 30) - 15)
        testCases.append([len(pol1), " ".join([str(c) for c in pol1]), " ".join([str(c) for c in pol2])])
print(degree("1x^0 + 0x^1 + 2x^2 + 2x^3"))
