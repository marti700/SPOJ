import System.Exit

main::IO()
main = do
        tc <- getLine
        if tc == "-1 -1"
        then exitSuccess
        else do
            let[a,b] = words tc
            putStrLn . show . anarc08e a $ b

        main



anarc08e "1" b = "1+"++b++"="++(show (1+read(b)))
anarc08e a "1" = a++"+1"++"="++(show (1+read(a)))
anarc08e a b = a++"+"++b++"!="++(show (read(a) + read(b)))
