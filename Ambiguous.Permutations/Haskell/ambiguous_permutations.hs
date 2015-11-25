import Data.List
import Data.Maybe
import System.Exit
--import Control.Monad
--import qualified Data.Map as Map
import Data.ByteString.Char8 as BS


-- I HAVE TRIED MANY THINGS TO MAKE THIS PASS BUT LOOKS LIKE THAT HASKELL
-- IS NOT FAST ENOUGH OR I STILL TO GREEN IN HASKELL TO CAME UP WITH A FAST
-- ENOUGH SOLUTION TO THIS BELOW ARE LISTED THE DIFERENT APPROACHES I TOOK
-- TO SOLVE THIS ALL OF THEM WORKS BUT ARE NOT FAST ENOUGH TO PASS SPOJ


--FORTH APPROACH USE BYTESTRING TO REDUCE THE AMAUNT OF TIME THE PROGRAM
--USES TO READ INPUT ------------------> TIME LIMIT EXCEEDED
main::IO()
main = do
        --Read the current case exit when zero
        t <- BS.getLine
        if (fst (fromJust (BS.readInt t))) == 0
            then  exitSuccess
            else do
                    per <- BS.getLine
                    --let m  = Map.fromList (indexPer 0 (read t) (map read (words per)))
                    Prelude.putStrLn $ permut2 0 (fst (fromJust (BS.readInt t))) (Prelude.map (fst . fromJust . BS.readInt) $ (BS.words per))

        main



--THIRD APPROACH WHITHOUT A MAP (NO NEED TO BUILD AN INDEX)ITERATE OVER THE LIST OF
--PERMUTATIONS AND FIND OUT IF THE PERMUTATION IS AMBIGUOUS ------> TIME LIMIT EXCEEDED
permut2::Int -> Int -> [Int] -> String
--says if a permutation is ambiguous or not
permut2 i n xs
    |(i+1) > n = "ambiguous"
    |xs !! i == (fromJust (Data.List.elemIndex (i+1) xs) +1 ) = permut2 (i+1) n xs
    |otherwise = "not ambiguous"



-- SECOND APPROACH INDEX THE POSITION OF ALL ELEMENTS IN THE PERMUTATION
-- THIS WAY I DON'T HAVE TO GO THROUGH ALL THE PERMUTATION LIST TO KNOW IF
-- IS AMBIGUOUS --------------------------------------------> TIME LIMIT EXCEEDED

--permut2::Int -> [Int] -> String
---- says if a permutation is ambiguous or not
--permut2 i n xs
--    |dectInversion 0 n xs (Map.fromList $ indexPer 0 n xs) == True = "ambiguous"
--    |otherwise = "not ambiguous"
--
--indexPer::Int -> Int -> [Int] ->[(Int,Int)]
----index in a map all the positions of the given permutation
----E.X: in [1,4,3,2] the generated map will be [(1,1)(2,4)(3,3)(2,4)]
--indexPer i n xs
--    |(i+1) > n = []
--    |otherwise = ((i+1),(fromJust (elemIndex (i+1) xs) + 1)):indexPer (i+1) n xs
--
--dectInversion::Eq a => Int -> Int -> [a] -> Map.Map Int a ->  Bool
----Recurcively iterates over the provided map and list to determinate
----if a list is ambiguous or not
--dectInversion i n xs m
--    |(i+1) > n = True
--    |fromJust (Map.lookup (i+1) m) /= xs !! (i) = False
--    |otherwise = dectInversion (i+1) n xs m
--
--  FIRST APPROACH INVERT THE GIVEN PERMUTATION ---> TIME LIMIT EXCEEDED
----inversePermut :: Int -> Int -> [Int] -> [Int]
----inverse a permutation
----fromJust -> returns the value of a maybe type E.X fromJust Just 4 #-> 4
----elemIndex -> returns the index of element in the list
----inversePermut i n xs
----    |(i+1) > n = []
----    |otherwise = (fromJust (elemIndex (i+1) xs)+1):inversePermut (i+1) n xs
