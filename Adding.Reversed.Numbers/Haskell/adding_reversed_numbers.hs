main::IO()
main = do
    (testCases:cases) <- lines `fmap` getContents -- IO in one go
    mapM_ (putStrLn . show . addrev . words) $ (take (read testCases) cases)

addrev::Read a => Integral a => [String] -> a
-- first reverse a and b then convert them to integers then convert the
-- result to an integer reverse it and finally convert the reversed result
-- to an integer (this last step deletes the zeros in front of the number)
addrev [a,b] = read . reverse . show $ ((read . reverse $ a) + (read . reverse $ b))
