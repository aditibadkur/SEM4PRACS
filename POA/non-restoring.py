def twoesComplement(num):
    onesComp = ""
    for i in num:
        if i == "0":
            onesComp += "1"
        else:
            onesComp += "0"

    return bin(int(onesComp, 2) + int("1", 2)).replace('0b', '')

dividend = int(input("Enter dividend(Q): "))
divisor = int(input("Enter divisor(M): "))

binNum1 = bin(abs(divisor)).replace('0b', '')
binNum2 = bin(abs(dividend)).replace('0b', '')

maxlen = len(binNum1) if len(binNum1) > len(binNum2) else len(binNum2)
maxlen += 1 

binNum1 = binNum1.zfill(maxlen)
binNum2 = binNum2.zfill(maxlen)

if divisor<0:
    binNum1 = twoesComplement(binNum1)

if dividend<0:
    binNum2 = twoesComplement(binNum2)

binCompNum2 = twoesComplement(binNum2)
binCompNum2 = binCompNum2.zfill(maxlen)

print("M: ", binNum1)
print("Q: ", binNum2)
print("-M: ", binCompNum2)

count = maxlen
m = binNum2
minusm = binCompNum2
q = binNum1
q1 = "0"
a = "0"
a = a.zfill(maxlen)
leftshift = ""

while count>0:
    merged = a+q

    leftshift = merged[1:]
    a = leftshift[:maxlen + 1] # WHY +1?

    if a[0] == "1": # a is -ve
        a = bin(int(a, 2) + int(m, 2)).replace('0b', '') 
        if len(a)>maxlen+1:
            a = a[1:]
        a = a.zfill(maxlen+1)

        leftshift = a + q[1:] #q0 = 0
        leftshift += "0"

    else: # a is +ve
        a = bin(int(a, 2) + int(minusm, 2)).replace('0b', '') 
        if len(a)>maxlen+1:
            a = a[1:]
        a = a.zfill(maxlen+1)

    leftshift = a + q[1:] #q0 = 1
    if a[0] == "1":
        leftshift += "0"
    else:
        leftshift += "1"

    a = leftshift[:maxlen + 1]
    q = leftshift[maxlen + 1:]
    count -=1
    print(maxlen - count, a, q)

if a[0] == "1":
    a = bin(int(a, 2) + int(m, 2)).replace("0b", "")
    if len(a) > maxlen + 1:
        a = a[1:]

print(int(a, 2))
print(int(q, 2))