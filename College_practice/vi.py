num=int(input("enter a number : "))
for i in range(2,num):
    div = num % i
    if div==0:
        print(" not prime")
        break
else:
    print("prime")
        
    