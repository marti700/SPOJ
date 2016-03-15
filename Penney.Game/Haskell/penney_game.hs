import Data.Map
--import Data.List.Split

--Haskell provides this function as parot of the Data.List.Split package
--but SPOJ's compiler don't use such package so I had to reinvent the wheel
--and do a chunksOf function of my own
chunksOf::Int -> [a] -> [[a]]
chunksOf _ [] = []
chunksOf n xs = (take n xs):chunksOf n (drop n xs)

--Initialize a map with all the possible outcomes
outcomes = Data.Map.fromList[("TTT",0), ("TTH",0), ("THT",0), ("THH",0), ("HTT",0), ("HTH",0), ("HHT",0), ("HHH",0)]

main::IO()
main = do
        (tc:cases) <-lines `fmap` getContents --end of  IO
        --chunksOf function takes an int and a function and returns a list
        --of lists grouped by chunks (e.x chunksOf 2 [1234] will return [[1,2],[3,4]]
        mapM_ (putStrLn . theMessage) (chunksOf 2 (take (2*(read tc)) cases))

--This function acts as a coordinator between theReply and theFormater functions
theMessage::[String] -> String
-- it says take the head of xs (which is a list) and then append it to the
-- result of the formater
theMessage xs = (head xs) ++ theFormater (head xs) (reverse (Data.Map.toList  (theReply (last xs) outcomes)))

--Formats the results to be displayed to the user
theFormater::Show a => t -> [(a1, a)] -> [Char]
-- this function iterates over the provided list of tuples and create
-- a string out of it
theFormater a [] = ""
theFormater a (x:xs) = " " ++ show (snd x) ++ theFormater a xs


--counts the number of occurrences of the different outcomes of the coin toss
--by modifying the above defined outcomes map
theReply::(Num a, Ord a1) => [a1] -> Map [a1] a -> Map [a1] a
-- This function iterates over the provided list (which is a String)
-- since the results of the tosses can overlap this function recurses the
-- string by ...., ok An example abced this function will take abc and will
-- detect if abc is a key in the map then increment the value of this key
-- by 1 and in the next recursive call the string abcd will become bcd and
-- the process will be repeated.
theReply [] aMap = aMap
-- the below line says call the reply by making the tail of xs it first
-- argument (this will delete the first element of the list) and adjust aMap
-- to the new value (see: https://downloads.haskell.org/~ghc/6.12.2/docs/html/libraries/containers-0.3.0.0/Data-Map.html#v%3Aadjust)
theReply xs aMap = theReply (tail xs) (Data.Map.adjust (+1) (take 3 xs) aMap)
