import Data.Maybe
import Data.List

main:: IO()
main = do
        (testCases:cases) <- lines `fmap` getContents -- IO
        --clean all the test cases by elimitating all blank spaces
        let sanitizedInput = map (filter (/= ' ')) . filter (/= "") $ (take (read testCases* 2) cases)
        mapM_ (putStrLn . show . (operate 0 '+')) $ sanitizedInput

firstOccurenceOf :: Eq a => [a] -> [a] -> Int -> Maybe Int
-- returns the index of the first ocurrence of any of the elmenets of the x list in the xs list
firstOccurenceOf x xs index
    |(index > ((length xs)-1)) = Nothing
    |(xs !! index) `elem` x = Just index
    |otherwise = firstOccurenceOf x xs (index+1)

operate :: (Integral a, Read a) => a -> Char -> [Char] -> a
-- returns the result of the provided mathemathical expresion
-- whithot taking in consideration operators precedence
operate acc _ [] = acc
operate acc operand expresion = operate (ope operand) (expresion !! opIndex) cutInput
    where opIndex = fromJust . firstOccurenceOf "+-*/=" expresion $ 0
          cutInput = tail . drop opIndex $ expresion
          ope oper
            |operand == '+' = (acc + (read . take opIndex $ expresion))
            |operand == '-' = (acc - (read . take opIndex $ expresion))
            |operand == '*' = (acc * (read . take  opIndex $ expresion))
            |operand == '/' = (acc `div` (read . take opIndex $ expresion))
            |otherwise = acc
