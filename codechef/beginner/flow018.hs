factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)

solve :: IO ()
solve = do
	putStrLn "Enter value of n"
	input1 <- getLine
	let n = (read input1 :: Int)
	print (factorial n)

iterate1 :: Int -> IO ()
iterate1 t = 
	if t > 0
		then do 
			solve
			iterate1 (t-1)
		else 
			putChar ' '

main :: IO ()
main = do
	putStrLn "enter value for t"
	input1 <- getLine
	let t = (read input1 :: Int)
	iterate1 t
