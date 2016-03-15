--Hbulullu HOW TO
--pas commentaire

main::IO()
main = do
        (testCases:cases) <- lines `fmap` getContents --IO in one go
        mapM_ (putStrLn . hubululu . words) $ (take (read testCases) cases)


hubululu [n,p] = if p == "0" then "Airborne wins." else "Pagfloyd wins."
