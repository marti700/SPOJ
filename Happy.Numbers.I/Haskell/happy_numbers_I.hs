--Happy Numbers How To
--there are crazy (not useful, but recreational) things in mathematics
--read this to understand the happy numbers properties:
--https://en.wikipedia.org/wiki/Happy_number

main::IO()
main = do
        tc <- getLine
        print (stespsToHappy (read tc) 0 0)

stespsToHappy:: Integer -> Integer -> Integer -> Integer
stespsToHappy 0 _ _ = -1
stespsToHappy 1 counter notHappy = counter
--when a number is happy applying the happyfication (<- what a word) will produce a infinite loop
--of which the numbers 4, 16, 37, 58, 89, 145, 42, 20 will always be part of in that exact same order
--fallowing line tracks the number 4 by adding 4 to the variable notHappy when this variable reach the
--value of 12 (after going through the loop(the process of happyfication (<- what a word)) 3 times )
--the function will return -1 indicating that the number is not happy.
stespsToHappy 4 counter notHappy = if notHappy == 12 then -1 else stespsToHappy 16 counter (notHappy + 4)
stespsToHappy aNumber counter notHappy = stespsToHappy (sum (map (^2) (decompose aNumber))) (counter + 1) notHappy

decompose::Integer -> [Integer]
--return the digits of a number in an array
--E.g 452 -> [4,2,5] #but not precisely in that order
--takes advantage of the fact that the modulo 10 of all the numbers
--is the last digit of the number E.g 23 % 10 = 3
decompose aNumber
    |aNumber == 0 = []
    |otherwise = (aNumber `mod` 10):decompose (aNumber `div` 10)
