import System.Exit

main::IO()
main = do
        tc <-getLine
        if tc == "0"
        then exitSuccess
        else do
            putStrLn . show . samer08f $ read tc

        main

samer08f:: Int -> Int
-- Returns how many different squares are there in a grid of N x N squares
-- In a grid of 8X8 square are (8*8)+(7*7)+(6*6)+(5*5)+(4*4)+(3*3)+(2*2)+(1*1) = 204
-- Is not posible to submit a solution for this problem implemented in
-- Haskell but I realize after I wrote the code.
samer08f n = sum [x*x | x <- [1..n]]

