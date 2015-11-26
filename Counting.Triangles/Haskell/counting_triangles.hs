main::IO()
main = do
        (tc:cases) <- lines `fmap` getContents
        mapM_ (putStrLn . show . tricount . read) $ take (read tc) cases

tricount :: Integral a => a -> a
--To understand the math behind this problem read this:
--http://www.billthelizard.com/2009/08/how-many-triangles.html
tricount n = (n * (n + 2) * (2 * n + 1)) `div` 8

