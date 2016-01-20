import System.Exit
import System.IO(isEOF)

main::IO()
main = do
        eof <- isEOF
        if eof
        then exitSuccess
        else do
            tc <- getLine
            putStrLn . show . bishops . read $ tc

        main


--returns the maximun number of bishops that can be placed in a N X N chess
--board
bishops::(Eq a, Num a) => a -> a
bishops tableSize
    |tableSize == 1 = 1
    |otherwise = tableSize + (tableSize - 2)
