def twoesComplement(num):
    onesComp = ""
    for i in num:
        if i == "0":
            onesComp += "1"
        else:
            onesComp += "0"

    return bin(int(onesComp, 2) + int("1", 2)).replace('0b', '')

M = int(input("Enter multiplicand(M): "))
Q = int(input("Enter multiplier(Q): "))

binNum1 = bin(abs(M)).replace('0b', '')
binNum2 = bin(abs(Q)).replace('0b', '')

maxlen = len(binNum1) if len(binNum1) > len(binNum2) else len(binNum2)
maxlen += 1 

binNum1 = binNum1.zfill(maxlen)
binNum2 = binNum2.zfill(maxlen)

if M<0:
    binNum1 = twoesComplement(binNum1)

if Q<0:
    binNum2 = twoesComplement(binNum2)

binCompNum1 = twoesComplement(binNum1)
binCompNum1 = binCompNum1.zfill(maxlen)

print("M: ", binNum1)
print("Q: ", binNum2)
print("-M: ", binCompNum1)

count = maxlen
m = binNum1
minusm = binCompNum1
q = binNum2
q1 = "0"
a = "0"
a = a.zfill(maxlen)
rightshift = ""

while count>0:
    if q1 == "0" and q[maxlen-1] == "1": # 10
        a = bin(int(a, 2) + int(minusm, 2)).replace('0b', '')
        if len(a)>maxlen:
            a = a[1:]
        a = a.zfill(maxlen)

    elif q1 == "1" and q[maxlen-1] == "0": #01
        a = bin(int(a, 2) + int(m, 2)).replace('0b', '')
        if len(a)>maxlen:
            a = a[1:]
        a = a.zfill(maxlen)

    merged = a+q+q1
    rightshift = merged[0]

    for i in range(len(merged)-1):
        rightshift += merged[i]

    a = rightshift[:maxlen]
    q = rightshift[maxlen:maxlen*2]
    q1 = rightshift[-1]
    count -=1

ans = a+q
miss = False

if ans[0] == 1: # ans is -ve
    ans = twoesComplement(ans)
    miss = True
print(ans)

if miss:
    print(int(ans, 2)*-1)
else:
    print(int(ans, 2))