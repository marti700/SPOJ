main::IO()
main = do
        (tc:cases) <- lines `fmap` getContents  -- IO
        mapM_ (putStrLn . show . crds . read) $ take (read tc) (cases)

crds :: Integral a => a -> a
-- (N*2 + N-1) is the number of cards at the level N (N is the level number)
-- N * (N*2 + N-1) this will give the number of cards needed to build a tower
-- of N levels (not a pyramind, but a tower with the same number of cards in
-- each level)
--
-- The difference of cards in each level of the pyramind is 3, so, the
-- difference of cards in each level of the piramid can be seen as
-- an arithmetic progression, by substracting the sum of the number of
-- cards of the arithmetic progression from the number of cards in the
-- tower and applying modulo 1000007 to the previous substraction we get
-- the answer to the question.
crds n = ((n*((n*2) + (n-1))) - (n*(0+(n-1)*3)) `div` 2) `mod` 1000007
