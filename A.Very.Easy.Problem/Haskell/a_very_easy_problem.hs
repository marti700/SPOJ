main::IO()
main = mapM_ (putStrLn . decompose) $ [137, 1315, 73, 136, 255, 1384, 16385]

--decomposes a number into a sequence of powers of two using the logarithm base 2 function.
--It statars by finding a logarithm base 2 of a number(it takes just the integer part)
--then it substract 2^ logbase 2 (the number obtained in the previous step)
--as you sure have noticed this is a recursive function.
--Now is your turn decuce the formatting part because I don't want to, besides,
--you have to do some work or you are going to get fat
--(and in case you are fat you have to do some work to lose some weight).
decompose::Int -> String
decompose 0 = ""
decompose 1 = "2(0)"
decompose 2 = "2"
decompose 3 = "2+2(0)"
decompose aNumber = "2("++ decompose(floor . logBase 2 $ (fromIntegral aNumber)) ++ ")" ++ if n == 0 then op1 else op2
    where
        n = aNumber - 2^(floor . logBase 2 $ (fromIntegral aNumber))
        op1 = decompose(n)
        op2 = "+" ++ decompose(n)

--decompose aNumber = "2("++decompose(floor(logBase 2 (fromIntegral aNumber))) ++ ")" ++ "+" ++ decompose(aNumber - (2^(floor(logBase 2 (fromIntegral aNumber)))))
--test str = str == decompose(read f)