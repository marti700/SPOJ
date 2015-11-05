--import Data.ByteString.Lazy.Char8 as BS

main::IO()
main = do
        (testCases:cases) <- Prelude.lines `fmap` Prelude.getContents
        --Prelude.putStrLn testCases
        --mapM_ Prelude.putStrLn cases
        mapM_ (Prelude.putStrLn . (`transformExpresion` [])) $ Prelude.take (read testCases) cases

transformExpresion :: String -> String -> String
transformExpresion [] [] = []
transformExpresion (e:exp) stack
    |e `Prelude.elem` "+-*/^" = transformExpresion exp (push e stack)
    |e == ')' = (fst (pop stack)):transformExpresion exp (snd (pop stack))
    |e == '(' = transformExpresion exp stack
    |otherwise = e:transformExpresion exp stack

push :: a -> [a] -> [a]
push a [] = [a]
push a st = a:st

pop :: [a] -> (a,[a])
pop [] = error "Empty List"
pop (s:st) = (s,st)

isEmpty :: [a] -> Bool
isEmpty st
    |Prelude.length st == 0 = True
    |otherwise      = False
