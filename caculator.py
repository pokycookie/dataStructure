# Stack class
class Stack:
    def __init__(self):
        self.__elements = [];

    def push(self, value):
        self.__elements.append(value)
    def pop(self):
        return self.__elements.pop()
    def peak(self):
        return self.__elements[-1]
    def isEmpty(self):
        return True if len(self.__elements) == 0 else False
    def length(self):
        return len(self.__elements)

# Symbol list
leftBracket = ["(", "{", "["]
rightBracket = [")", "}", "]"]
symbolList = ["+", "-", "*", "/", "^", "%"]
symbolList.extend(leftBracket)
symbolList.extend(rightBracket)

# Priority
priority = {"^": 3, "*": 2, "/": 2, "%": 2, "+": 1, "-": 1, "(": 0, "{": 0, "[": 0}

# 괄호 짝 확인
def checkPair(exp: str):
    pairStack = Stack()
    for i in range(len(exp)):
        char = exp[i]
        if char in leftBracket: pairStack.push(char)
        if char in rightBracket:
            if pairStack.isEmpty(): return False
            result = pairStack.pop()
            if result == "(" and char != ")" or result == "{" and char != "}" or result == "[" and char != "]": return False

    if pairStack.isEmpty(): return True
    else: return False

# 후위표기법으로 변환
def conversion(exp: str):
    # 괄호의 짝이 맞지 않는 경우 바로 retrun
    if not checkPair(exp):
        print("괄호의 짝이 맞지 않습니다.")
        return []
    
    # Stack과 List선언
    expStack = Stack()
    expList = []
    
    # 2자리 이상의 수를 위한 temp공간
    temp = ""

    # 문자열의 문자 하나씩 반복문 실행
    for i in range(len(exp)):
        # 문자열의 한 문자
        char = exp[i]
        
        # 공백 제거용(trim)
        if char == " ": continue

        # char가 symbolist중 하나인 경우
        if char in symbolList:
            # temp에 기록되어 있던 숫자를 실수로 변환하여 expList에 추가
            if len(temp) > 0:
                expList.append(float(temp))
                temp = ""

            # char가 왼쪽 괄호인 경우
            if char in leftBracket:
                expStack.push(char)

            # char가 오른쪽 괄호인 경우
            elif char in rightBracket:
                while True:
                    element = expStack.pop()
                    if element in leftBracket or expStack.isEmpty():
                        break
                    else:
                        expList.append(element)
            
            # char가 괄호가 아닌 기본 연산자인 경우
            else:
                # 스택에 다른 연산자가 쌓여있는 경우
                if not expStack.isEmpty():
                    # 현재 연산자가 쌓인 연산자보다 우선순위가 높을 경우
                    if priority[char] > priority[expStack.peak()]:
                        expStack.push(char)

                    # 현재 연산자가 쌓인 연산자보다 우선순위가 같거나 낮을 경우
                    else:
                        expList.append(expStack.pop())
                        expStack.push(char)

                # 스택에 아무런 연산자도 쌓여있지 않을 경우
                else:
                    expStack.push(char)

        # char가 symbolist에 없는 경우 (숫자, 소숫점 또는 잘못된기호)
        else:
            # char가 소숫점인 경우
            if char == ".":
                temp = temp + char
            else:
                # char가 숫자인 경우
                try:
                    int(char)
                    temp = temp + char
                
                # char가 잘못된 기호인 경우
                except:
                    print("잘못된 수식입니다.")
                    return []
    
    # 남은 temp와 stack값 모두 expList에 순서대로 추가
    try:
        expList.append(float(temp))
    except:
        pass
    for i in range(expStack.length()):
        expList.append(expStack.pop())

    return expList

def caculator(exp: str):
    expList = conversion(exp)
    expStack = Stack()

    if len(expList) == 0: return ""

    for i in range(len(expList)):
        element = expList[i]

        # 숫자인 경우
        if element not in symbolList:
            expStack.push(element)

        # 연산자인 경우
        else:
            value2 = expStack.pop()
            value1 = expStack.pop()

            if element == "+": expStack.push(value1 + value2)
            elif element == "-": expStack.push(value1 - value2)
            elif element == "*": expStack.push(value1 * value2)
            elif element == "/": expStack.push(value1 / value2)
            elif element == "^": expStack.push(pow(value1, value2))
            elif element == "%": expStack.push(value1 % value2)
    
    # Stack에 쌓인 마지막 결과물을 꺼냄
    result = expStack.pop()

    # 마지막 결과물 외에 값이 더 있는 경우
    if not expStack.isEmpty():
        print("잘못된 수식입니다.")
        return ""
    
    print(result)
    return result

def main():
    while True:
        caculator(input("식을 입력하세요: "))
        print()

main()
