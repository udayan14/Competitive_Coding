gcd m n = 
        if n == 0
            then m
            else Main.gcd n (mod m n)

main = print (Main.gcd 100 49)
